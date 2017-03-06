#include<iostream>
#include<string> 
#include<fstream>

void OpenFile(std::fstream & file) {
	std::string fileName;
	std::cout << "Enter the file name: ";
	std::cin >> fileName;
	file.open(fileName, std::ios_base::in);
	while (!file.is_open()) {
		std::cout << "Error! Enter the file name again: ";
		fileName = "";
		std::cin >> fileName;
		file.open(fileName, std::ios_base::in);
	}
}

bool GetWord(std::fstream &in, std::string &str) {
	if (in.eof()) return false;
	char symbol = '\0';
	in.get(symbol);
	while (!in.eof() && !isalnum(symbol)) {
		in.get(symbol);
	}
	str = "";
	while (!in.eof() && isalnum(symbol)) {
		str += symbol;
		in.get(symbol);
	}
	if (str!="") 
		return true;
	else 
		return false;
}

//функция печати, где wordFromPrint - указатель на массив слов, которые необходимо вывести, n - количество слов, которое необходимо вывести с каждой стороны
//pos - индекс слова, которое необходмо было найти
void PrintWord(std::string* wordFromPrint, int n, int pos) {
	int firstIndex = (pos + n + 1) % (2 * n + 1);//находим индекс слова, которое необходимо вывести первым
	int currntIndex = firstIndex;
	for (int i = 0; i < 2*n+1; ++i) {
 		if (wordFromPrint[currntIndex] != "")
			std::cout << wordFromPrint[currntIndex] << " ";
		currntIndex = (currntIndex + 1) % (2 * n + 1);//контролируем то, чтобы не выйти за рамки массива
	}
	std::cout << std::endl;
}

int main() {
	std::fstream file;
	std::string *wordForPrint;	
	std::string searchWord;
	size_t n = 0;		
	std::string buf;
	int i = 0;
	int indexFindWork = 0;
	OpenFile(file);
	std::cout << "Enter word for find: ";
	std::cin >> searchWord;
	std::cout << "Enter the number of words you want to show on both sides: ";
	std::cin >> n;
	std::cout << "\nSearching results:" << std::endl;
	bool flag = true;//true - если в файлу слов больше, чем n, false - если меньше
	bool enter = false;//для проверки было ли найдено хоть одно слово
	int indexWord = 0;
	size_t numberWords = 2 * n + 1;
	wordForPrint = new std::string[numberWords];
	
	//"Рамка" входит в массив слов
	for (i = 0; i < n; ++i) {
		if (!file.eof()&&GetWord(file, buf))
			wordForPrint[i] = buf;
		else {
			flag = false;
			break;
		}
	}
	
	if (!flag) {//если слов в файле меньше чем n
		for (i = 0; i < n; ++i) {
			if (wordForPrint[i] == searchWord) {
				PrintWord(wordForPrint, n, i);
				enter = true;
			}
		}
	}
	else {
		for (i = n; i  <= numberWords; ++i) {
			i = i % numberWords;			
			if (file.eof()) 
				break;
			else {
				if (GetWord(file, buf)) {
					wordForPrint[i] = buf;
				}
				else{
					wordForPrint[i] = "";
				}
				if (wordForPrint[indexWord] == searchWord) {
					PrintWord(wordForPrint, n, indexWord);
					enter = true;
				}
				indexWord = (indexWord + 1) % numberWords;
			}
		}
		for (i = indexWord; i < numberWords; ++i) {
			wordForPrint[(i + n) % numberWords] = "";
			if (wordForPrint[i] == searchWord) {
				PrintWord(wordForPrint, n, i);
				enter = true;
			}
		}
	}
	if (!enter)
		std::cout << "This word is not found" << std::endl;
	delete[] wordForPrint;
	file.close();
	system("pause");
	return 0;
}