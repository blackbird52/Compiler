#pragma once

#include <fstream>
#include <string>
#include "symbol.h"

using namespace std;

enum JUDGE {
	BEQ,
	BNE,
	BGE,
	BLT,
	BGT,
	BLE
};

const string INT_TYPE = "int";
const string CHAR_TYPE = "char";

class MidcodeGenerator {
private:
	ofstream midcode;

	void PrintBez(int label, string expression);
	void PrintBnz(int label, string expression);

	void PrintBeq(int label, string expression1, string expression2);
	void PrintBne(int label, string expression1, string expression2);
	void PrintBge(int label, string expression1, string expression2);
	void PrintBgt(int label, string expression1, string expression2);
	void PrintBle(int label, string expression1, string expression2);
	void PrintBlt(int label, string expression1, string expression2);
public:
	MidcodeGenerator();
	void OpenMidcodeFile(string fileName);
	void FileClose();

	void PrintFuncDeclare(Symbol* function);
	void PrintVoidFuncDeclare(Symbol* function);
	void PrintReturn(bool isVoid, string value);

	void PrintElseLabel(int label);
	void PrintEndifLabel(int label);
	void PrintGotoEndifLabel(int label);

	void PrintBezOrBnz(int label, string expression, bool isFalseBranch);
	void PrintBeqOrBne(int label, string expression, string expression2, JUDGE judge, bool isFalseBranch);
	void PrintBgeOrBlt(int label, string expression, string expression2, JUDGE judge, bool isFalseBranch);
	void PrintBgtOrBle(int label, string expression, string expression2, JUDGE judge, bool isFalseBranch);
	
	void PrintString(int stringNumber);
	void PrintInteger(string number);
	void PrintChar(string c);
	void PrintNewline();

	void PrintScanf(string type, string identifier);
};
