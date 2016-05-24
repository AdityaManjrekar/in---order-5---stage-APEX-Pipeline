/*
 * struct: instructionSet
 * Author: Aditya Manjrekar
 * Date: 24th FEb 2016
 * Description: this struct will hold the details of input Instruction
 */
#ifndef IS_HPP
#define IS_HPP
#include<string>
using namespace std;
#endif

 struct instructionSet
{
public:
	string opcode;
	string instruction;
	string src1;
	int src1Value;
	string src2;
	int src2Value;
	string dest;
	int destValue;
	string literal;
	int litValue;
	int done;
	instructionSet()
	{
		opcode="";
		instruction = "";
		src1 = "";
		src2 = "";
		dest = "";
		literal ="";
		src1Value=0;
		src2Value=0;
		destValue =0;
		litValue =0;
		done =0;
	}
};
