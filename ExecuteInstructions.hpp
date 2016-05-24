class executeInstructions
{
public:
	int executeAddInstruction(int);
	int executeSubInstruction(int);
	int executeMulInstruction(int);
	int executeAndInstruction(int);
	int executeOrInstruction(int);
	int executeMovcInstruction(int);
	int executeXorInstruction(int);
	int executeStoreInstruction(int);
	int executeHaltInstruction(int);
	int executeBalInstruction(int);
	int executeJumpInstruction(int);
	int executeBZInstruction(int);
	int executeBNZInstruction(int);
	int memoryStageLoadExecution(int);
	int memoryStageStoreExecution(int);

};
/*
 * Function Name: executeAddInstruction
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to execute Add instruction
 */

int executeInstructions::executeAddInstruction(int location)
{
	if(mapInstruction.at(location).src2.compare("")!=0)
		mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value + mapInstruction.at(location).src2Value;
	else
		mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value + mapInstruction.at(location).litValue;
	if(mapInstruction.at(location).destValue==0)
		zeroFlag=1;
	else
		zeroFlag=5;
	return 0;
}
/*
 * Function Name: executeSubInstruction
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to execute SUB instruction
 */

int executeInstructions::executeSubInstruction(int location)
{
	if(mapInstruction.at(location).src2.compare("")!=0)
			mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value - mapInstruction.at(location).src2Value;
		else
			mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value - mapInstruction.at(location).litValue;
	if(mapInstruction.at(location).destValue==0)
		zeroFlag=1;
	else
		zeroFlag=5;
	return 0;
}
/*
 * Function Name: executeMulInstruction
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to execute MUL instruction
 */

int executeInstructions::executeMulInstruction(int location)
{
	if(mapInstruction.at(location).src2.compare("")!=0)
			mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value * mapInstruction.at(location).src2Value;
		else
			mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value * mapInstruction.at(location).litValue;
	if(mapInstruction.at(location).destValue==0)
		zeroFlag=1;
	else
		zeroFlag=5;
	return 0;
}
/*
 * Function Name: executeANDInstruction
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to execute AND instruction
 */

int executeInstructions::executeAndInstruction(int location)
{
	if(mapInstruction.at(location).src2.compare("")!=0)
			mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value & mapInstruction.at(location).src2Value;
		else
			mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value & mapInstruction.at(location).litValue;
	if(mapInstruction.at(location).destValue==0)
		zeroFlag=1;
	else
		zeroFlag=5;
	return 0;
}
/*
 * Function Name: executeORInstruction
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to execute OR instruction
 */

int executeInstructions::executeOrInstruction(int location)
{
	if(mapInstruction.at(location).src2.compare("")!=0)
		mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value | mapInstruction.at(location).src2Value;
	else
		mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value | mapInstruction.at(location).litValue;
	if(mapInstruction.at(location).destValue==0)
		zeroFlag=1;
	else
		zeroFlag=5;
	return 0;
}
/*
 * Function Name: executeMovcInstruction
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to execute MOVC instruction
 */

int executeInstructions::executeMovcInstruction(int location)
{
	mapInstruction.at(location).destValue=mapInstruction.at(location).src2Value;
	if(mapInstruction.at(location).destValue==0)
		zeroFlag=1;
	else
		zeroFlag=5;
	return 0;
}
/*
 * Function Name: executeXorInstruction
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to execute XOR instruction
 */

int executeInstructions::executeXorInstruction(int location)
{
	if(mapInstruction.at(location).src2.compare("")!=0)
		mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value ^ mapInstruction.at(location).src2Value;
	else
		mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value ^ mapInstruction.at(location).litValue;
	if(mapInstruction.at(location).destValue==0)
		zeroFlag=1;
	else
		zeroFlag=5;
	return 0;
}
/*
 * Function Name: executeStoreInstruction
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to execute Store instruction
 */

int executeInstructions::executeStoreInstruction(int location)
{
	mapInstruction.at(location).destValue=mapInstruction.at(location).src2Value + mapInstruction.at(location).litValue;
	return 0;
}
/*
 * Function Name: executeHaltInstruction
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to execute Halt instruction
 */

int executeInstructions::executeHaltInstruction(int location)
{
	location =location*0;
	return 0;
}
/*
 * Function Name: executeBalInstruction
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to execute BAL instruction
 */

int executeInstructions::executeBalInstruction(int location)
{
	if(mapInstruction.at(location).src2 !="")
		mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value + mapInstruction.at(location).src2Value;
	else if(mapInstruction.at(location).literal !="")
		mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value + mapInstruction.at(location).litValue;
	else
		mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value;

//	mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value + mapInstruction.at(location).src2Value;
	X = location+1;
	balAdd = mapInstruction.at(location).destValue;
	return 0;
}
/*
 * Function Name: executeJumpInstruction
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to execute Jump instruction
 */

int executeInstructions::executeJumpInstruction(int location)
{
	if(mapInstruction.at(location).src2 !="")
		mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value + mapInstruction.at(location).src2Value;
	else if(mapInstruction.at(location).literal !="")
		mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value + mapInstruction.at(location).litValue;
	else
		mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value;
	jumpAddressLcation =mapInstruction.at(location).destValue;
	return 0;
}
/*
 * Function Name: executeBZInstruction
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to execute BZ instruction
 */

int executeInstructions::executeBZInstruction(int location)
{
	mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value;
	branchInstructionBZADD = mapInstruction.at(location).destValue+location;
	if(zeroFlag==1)
	{
		haltInstruction=0;
		branchInstructionBZ = 1;
		zeroFlag=5;
	}
	return 0;
}
/*
 * Function Name: executeBNZInstruction
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to execute BNZ instruction
 */

int executeInstructions::executeBNZInstruction(int location)
{
	mapInstruction.at(location).destValue=mapInstruction.at(location).src1Value;
	branchInstructionBNZADD = mapInstruction.at(location).destValue+location;
	if(zeroFlag==5)
	{
		haltInstruction=0;
		branchInstructionBNZ = 1;
		zeroFlag=5;
	}
	return 0;
}
/*
 * Function Name: memoryStageLoadExecution
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to load the meory value into register
 */

int executeInstructions::memoryStageLoadExecution(int location)
{
	int data;
	data = memoryAddress.at(mapInstruction.at(location).destValue);
	mapInstruction.at(location).destValue=data;
	return 0;
}
/*
 * Function Name: memoryStageStoreExecution
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to store the register value into memory
 */

int executeInstructions::memoryStageStoreExecution(int location)
{
	memoryAddress.at(mapInstruction.at(location).destValue) = mapInstruction.at(location).src1Value;
	return 0;
}
