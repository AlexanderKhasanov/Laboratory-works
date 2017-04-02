#pragma once
#pragma once
#include <exception>

class CastException
	: public std::exception
{};

class IncorrectSymbol
	: public CastException
{};

class ArithmeticOverflow
	: public CastException
{};

class EmptyLine
	: public CastException
{};