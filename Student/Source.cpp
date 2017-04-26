#include <iostream>

#include <string>
#include <vector>
#include <map>

#include <algorithm>
#include <numeric>

enum Grade
{
	F = 1,
	D,
	C,
	B,
	A
};

struct Student
{
	std::string FIO;
	std::string Group;
	std::map<std::string, Grade> Grades;
};

std::vector<Student> LoadStudents()
{
	return{
		{
			"Anna", "G7",
			{
				{ "math", Grade::A },
				{ "cs", Grade::A },
				{ "english", Grade::A },
				{ "dutch", Grade::B },
			}
		},
		{
			"Petr", "G7",
			{
				{ "math", Grade::A },
				{ "cs", Grade::B },
				{ "dutch", Grade::C },
			}
		},
		{
			"Vova", "G1",
			{
				{ "math", Grade::F },
				{ "english", Grade::F },
			}
		},
		{
			"Vasya", "G3",
			{
				{ "math", Grade::F },
				{ "english", Grade::F },
				{ "cs", Grade::B },
				{ "dutch", Grade::C },
			}
		},
		{
			"Anton", "G4",
			{
				{ "math", Grade::F },
				{ "english", Grade::F },
				{ "dutch", Grade::C },
				{ "cs", Grade::C },
			}
		},
		{
			"Masha", "G2",
			{
				{ "math", Grade::A },
			}
		},
		{
			"Sasha", "G6",
			{
				{ "english", Grade::F },
				{ "russian", Grade::F },
				{ "dutch", Grade::F },
			}
		},
		{
			"Jeka", "G2",
			{
				{ "english", Grade::A },
			}
		},
		{
			"Sveta", "G3",
			{
			}
		}
	};
}


struct FindStudentGroup
{
	std::string neededGroup;
	bool operator()(const Student& s) const
	{
		return s.Group == neededGroup;
	}
};

struct PrinterStudent
{
	void operator()(const Student& s) const
	{
		std::cout << s.FIO << " studies in " << s.Group << std::endl;
	}
};


struct GradeEqual
{
	Grade grade = Grade::A;

	bool operator()(const std::pair<std::string, Grade> & el) const
	{
		return el.second == grade;
	}
};

struct BestÒMaths
{
	std::string name;
	size_t mark = 0;
	void operator()(Student& rhs)
	{
		auto it = rhs.Grades.find("math");
		if (it != rhs.Grades.end())
		{
			if (it->second>mark)
			{
				name = rhs.FIO;
				mark = rhs.Grades["math"];
			}
		}
	}
};

struct WorstSrBall
{
	std::string name;
	double srBall=0;
	void operator()(Student& rhs)
	{
		double sum = 0;
		size_t n = 0;
		for (auto i = rhs.Grades.begin(); i != rhs.Grades.end(); ++i)
		{
			sum += i->second;
			++n;
		}
		if (n != 0 && srBall > sum / n)
		{
			name = rhs.FIO;
			srBall = sum / n;
		}
	}
};

struct ManySubject
{
	std::string name;
	size_t number = 0;
	void operator()(Student& rhs)
	{
		if (rhs.Grades.size() > number)
		{
			name = rhs.FIO;
			number = rhs.Grades.size();
		}
	}
};

struct PeopleInGroup
{
	std::multimap<std::string, Student> groups;
	void operator()(Student& rhs)
	{
		groups.insert(std::make_pair(rhs.Group, rhs));
	}
};

struct MathAndCS {
	std::vector<Student> allStudents;
	void operator()(Student &rhs) {
		auto it1 = rhs.Grades.find("math");
		auto it2 = rhs.Grades.find("cs");
		if (it1 != rhs.Grades.end() && it2 != rhs.Grades.end())
			if (it1->second == Grade::B && it2->second == Grade::A)
				allStudents.push_back(rhs);
	}
};

struct AddSubject
{
	std::string subject = "Russian literature";
	void operator()(Student &rhs) {
		double sum = 0;
		int rez = 0;
		size_t n = 0;
		Grade mark;
		for (auto it = rhs.Grades.begin(); it != rhs.Grades.end(); ++it) 
		{
			sum += it->second;
			++n;
		}
		if (n != 0) 
		{
			rez = sum / n;
			rez = ceil(rez);
		}
		else
		{
			rez = 1 + rand() % 5;
		}
		mark = static_cast<Grade>(rez);
		rhs.Grades.insert(std::pair<std::string, Grade>(subject, mark));
	}
};

struct MarkDutch
{
	std::string subject = "dutch";
	void operator()(Student& rhs)
	{
		auto it = rhs.Grades.find(subject);
		if (it != rhs.Grades.end())
			std::cout << "Student " << rhs.FIO << ". Mark of dutch" << it->second << std::endl;
		else
			std::cout << "Student " << rhs.FIO << "hasn`t this subject"  << std::endl;
	}
};

int main()
{
	std::vector<Student> students = LoadStudents();

	// find students from G1
	FindStudentGroup finderObj;
	finderObj.neededGroup = "G1";
	auto it = std::find_if(students.begin(), students.end(), finderObj);
	if (it != students.end())
		std::cout << it->FIO << std::endl;


	// find students from G7
	it = std::find_if(students.begin(), students.end(), FindStudentGroup{ "G7" });
	if (it != students.end())
		std::cout << it->FIO << std::endl;


	// print info about all students
	std::for_each(students.begin(), students.end(), PrinterStudent());


	// count of grades eq 'A' of the student from G7
	auto cnt = std::count_if(it->Grades.begin(), it->Grades.end(), GradeEqual{});
	std::cout << cnt << std::endl;

	// count of grades eq 'B' of the student from G7
	auto cnt2 = std::count_if(it->Grades.begin(), it->Grades.end(),
		// lambda
		[](const std::pair<std::string, Grade> & el)
	{
		return el.second == Grade::B;
	}
	);
	std::cout << cnt2 << std::endl;


	auto bestMark = std::for_each(students.begin(), students.end(), BestÒMaths());

	auto worstSrBall = std::for_each(students.begin(), students.end(), WorstSrBall());

	auto manySubject = std::for_each(students.begin(), students.end(), ManySubject());

	auto group = std::for_each(students.begin(), students.end(), PeopleInGroup());

	auto mathAndCS = std::for_each(students.begin(), students.end(), MathAndCS());

	auto newSubject = std::for_each(students.begin(), students.end(), AddSubject());

	auto markDutch = std::for_each(students.begin(), students.end(), MarkDutch());
}