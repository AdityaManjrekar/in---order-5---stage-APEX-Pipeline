//#include<string.h>
#include "InstructionHandler.hpp"
#include "ExecuteInstructions.hpp"
class InstSimulator
{
public:
	InstSimulator() {}
/*
 * Function declarations
 */
	void initialize();
	int cycle();
	int display();
	class Stage
	{
	public:
		int fetchStageExecution();
		int decodeStageExecution();
		int executeStageExecution();
		int memoryStageExecution();
		int wrtieBackStageExecution();
	};
	Stage stage;
};
InstSimulator ins;
instructionHandler insHand;
executeInstructions exeInst;
/*
	Function Name: initialize
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Initializes all the variables used in the program adn the Data memory location to 0
*/

void InstSimulator::initialize()
{
	int i;
	fetchStageProgramCounter=20000,decodeStageProgramCounter=0,executeStageProgramCounter=0,memoryStageProgramCounter=0,writeBackStageProgramCounter=0,haltInstructionProgramCounter=0,haltInstruction=0;
	jumpInstructionProgramCounter =0;
	jumpInstruction=0;
	bal=0;
	jumpFlag =0;
	R0=0,R1=0,R2=0,R3=0,R4=0,R5=0,R6=0;R7=0;
	BNZ=0;
	BZ=0;
	branchInstructionBNZ =0;
	branchInstructionBZ =0;
	branchInstructionProgramCounterBNZ=0;
	branchInstructionProgramCounterBZ =0;
	branchInstructionBNZADD=0;
	branchInstructionBZADD=0;
	zeroFlag=5;
	cycleNumber =0;
	cy=0;
	flag=0;
	fNext=0;
	fetchStage =0;
	decodeStage = 0;
	writeBackStage =0;
	executeStage =0;
	memoryStage =0;
	jumpAddressLcation=0;
	for(i=0;i<=9999;i++)
	{
		memoryAddress.insert(make_pair(i,0));
	}
	for(i=0;i<=31;i++)
	{
		registers.insert(make_pair(string("R").append(to_string(i)),0));
	}
}
/*
	Function Name: initialize
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Creates the cycle
*/
int InstSimulator::cycle()
{
	int a=0,i,choice;
	a=a*0;
//	int tempFetchStageProgramCounter,tempDecodeStageProgramCounter,tempExecuteStageProgramCounter,tempMemoryStageProgramCounter,tempWriteBackStageProgramCounter;
	cycleNumber=cycleNumber+1;

	if(flag==1)
	{
		if(cycleNumber==cy+1)
		{
			//q=FETCH_PC;w=DECODE_PC;e=EXE_PC;r=MEM_PC;t=WB_PC;
	/*		tempFetchStageProgramCounter = fetchStageProgramCounter;
			tempDecodeStageProgramCounter = decodeStageProgramCounter;
			tempExecuteStageProgramCounter = executeStageProgramCounter;
			tempMemoryStageProgramCounter = memoryStageProgramCounter;
			tempWriteBackStageProgramCounter = writeBackStageProgramCounter;*/
			LOOP:
				std::cout<<"Please enter your choice: "<<std::endl<<"1.RESUME: "<<std::endl<<"2.DISPLAY:"<<std::endl<<"3.STOP:"<<std::endl;
				std::cin>>choice;
			switch(choice)
			{
				case 1:
				{
					for(i=0;i<number;i++)
					{
					}
					break;
				}

				case 2:
				{
					a=display();
					goto LOOP;
					break;
				}

				case 3:
				{
					exit(0);
				}
			}
			}
	}
if(EXIT!=1)
{
	std::cout<<"\n\n Processing cycle  # ############################# "<<cycleNumber<<std::endl;

	a=stage.fetchStageExecution();
	a=stage.decodeStageExecution();
	a=stage.executeStageExecution();
	a=stage.memoryStageExecution();
	a=stage.wrtieBackStageExecution();
}
else
{
	exit(0);
}
if(dependency1==1||dependency2==1)
{
	writeBackStageProgramCounter=memoryStageProgramCounter;
	memoryStageProgramCounter=executeStageProgramCounter;
	executeStageProgramCounter =0;
	decodeStageProgramCounter =decodeStageProgramCounter;
	fetchStageProgramCounter = fetchStageProgramCounter;
}
else if(branchInstructionBNZ==1)
{
	writeBackStageProgramCounter=memoryStageProgramCounter;
	memoryStageProgramCounter=executeStageProgramCounter;
	executeStageProgramCounter=0;
	decodeStageProgramCounter=0;
	fetchStageProgramCounter = branchInstructionBNZADD;
	branchInstructionBNZ =0;
}
else if(branchInstructionBZ==1)
{
	writeBackStageProgramCounter=memoryStageProgramCounter;
	memoryStageProgramCounter=executeStageProgramCounter;
	executeStageProgramCounter=0;
	decodeStageProgramCounter=0;
	fetchStageProgramCounter = branchInstructionBZADD;
	branchInstructionBZ =0;
}
else if (jumpInstruction==1)
{
	if(executeStageProgramCounter==jumpInstructionProgramCounter)
	{
		writeBackStageProgramCounter=memoryStageProgramCounter;
		memoryStageProgramCounter=executeStageProgramCounter;
		executeStageProgramCounter =0;
		decodeStageProgramCounter =0;
		fetchStageProgramCounter = jumpAddressLcation;
		jumpInstruction =0;
		jumpAddressLcation =0;
	}
	else
	{
		writeBackStageProgramCounter=memoryStageProgramCounter;
		memoryStageProgramCounter=executeStageProgramCounter;
		executeStageProgramCounter =decodeStageProgramCounter;
		decodeStageProgramCounter =0;
		fetchStageProgramCounter = 0;
	}
}
else if (bal==1 && executeStageProgramCounter==balProgramCounter)
{
	writeBackStageProgramCounter=memoryStageProgramCounter;
	memoryStageProgramCounter=executeStageProgramCounter;
	executeStageProgramCounter =0;
	decodeStageProgramCounter =0;
	fetchStageProgramCounter = balAdd;
	bal=0;
	balAdd=0;
}
else if(fNext==1)
{
	writeBackStageProgramCounter=memoryStageProgramCounter;
	memoryStageProgramCounter=executeStageProgramCounter;
	executeStageProgramCounter =decodeStageProgramCounter;
	decodeStageProgramCounter =fetchStageProgramCounter;
	fetchStageProgramCounter = X;
	fNext=0;

}
else if(haltInstruction==1)
{
	if(writeBackStageProgramCounter!=haltInstructionProgramCounter)
	{
		writeBackStageProgramCounter=memoryStageProgramCounter;
		memoryStageProgramCounter=executeStageProgramCounter;
		executeStageProgramCounter=decodeStageProgramCounter;
		fetchStageProgramCounter=0;
		decodeStageProgramCounter=0;
	}
	else
	{
		display();
		exit(0);
	}
}
else if(dependency1==0 && dependency2==0)
{
	writeBackStageProgramCounter=memoryStageProgramCounter;
	memoryStageProgramCounter=executeStageProgramCounter;
	executeStageProgramCounter =decodeStageProgramCounter;
	decodeStageProgramCounter =fetchStageProgramCounter;
	if(fNext==1)
	{
		fetchStageProgramCounter=X;
		fNext=0;
	}
	else
	{
		fetchStageProgramCounter=fetchStageProgramCounter+1;
	}
}
std::cout<<"REGISTER CONTENTS\n";
std::cout<<"\n";
int tempCounter=0;
for(int i=0;i<32;i++)
{
		std::cout<<"[R"<<i<<" -> "<<registers.at(string("R").append(to_string(i)))<<"] ";
		if(tempCounter==7)
		{
			std::cout<<"\n";
			tempCounter=0;
		}		
		tempCounter++;
}
	std::cout<<"\n";
/*
std::cout<<"R1 -> "<<registers.at("R1")<<std::endl;
std::cout<<"R2 -> "<<registers.at("R2")<<std::endl;
std::cout<<"R3 -> "<<registers.at("R3")<<std::endl;
std::cout<<"R4 -> "<<registers.at("R4")<<std::endl;
std::cout<<"R5 -> "<<registers.at("R5")<<std::endl;
std::cout<<"R6 -> "<<registers.at("R6")<<std::endl;
std::cout<<"R7 -> "<<registers.at("R7")<<std::endl;
std::cout<<"R8 -> "<<registers.at("R8")<<std::endl;
std::cout<<"R31 -> "<<registers.at("R31")<<std::endl;
*/
//EXIT_HALT:
	return 0;
}
/*
	Function Name: display
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: displays the content of the registers and the data Memory locations
*/

int InstSimulator::display(){
int i;
int tempCounter=0;
std::cout<<"REGISTER CONTENTS\n";
std::cout<<"\n";
for(i=0;i<32;i++)
{
		std::cout<<"[R"<<i<<" -> "<<registers.at(string("R").append(to_string(i)))<<"] ";
		if(tempCounter==7)
				{
					std::cout<<"\n";
					tempCounter=0;
				}
		tempCounter++;
}
std::cout<<"\n";
std::cout<<"\n";
	if(fetchStage==0||fetchStage>=maxProgramCounter)
	{
		std::cout<<"FETCH --->>> Empty\n";
	}
	else
	{
		if(mapInstruction.find(fetchStage)!=mapInstruction.end())
		{
			if(mapInstruction.at(fetchStage).instruction!="")
				std::cout<<"FETCH --->>> "<<mapInstruction.at(fetchStage).instruction<<std::endl;
			else
				std::cout<<"FETCH --->>> Empty\n";
		}

	}
if(decodeStage==0||decodeStage>=maxProgramCounter)
	{
		std::cout<<"DECODE --->>> Empty\n";
	}
else
	{
		if(mapInstruction.find(decodeStage)!=mapInstruction.end())
		{
			if(mapInstruction.at(decodeStage).instruction!="")
				std::cout<<"Decode --->>> "<<mapInstruction.at(decodeStage).instruction<<std::endl;
			else
				std::cout<<"DECODE --->>> Empty\n";
		}

	}
if(executeStage==0||executeStage>=maxProgramCounter)
	{
		std::cout<<"EXE --->>> Empty\n";
	}
else
	{
		if(mapInstruction.find(executeStage)!=mapInstruction.end())
		{
			if(mapInstruction.at(executeStage).instruction!="")
				std::cout<<"EXE --->>> "<<mapInstruction.at(executeStage).instruction<<std::endl;
			else
				std::cout<<"EXE --->>> Empty\n";
		}

	}
if(memoryStage==0||memoryStage>=maxProgramCounter)
	{
		std::cout<<"MEM --->>> Empty\n";
	}
else
	{
	if(mapInstruction.find(memoryStage)!=mapInstruction.end())
		{
			if(mapInstruction.at(memoryStage).instruction!="")
				std::cout<<"Memory --->>> "<<mapInstruction.at(memoryStage).instruction<<std::endl;
			else
						std::cout<<"MEM --->>> Empty\n";
		}

	}
	
if(writeBackStage==0||writeBackStageProgramCounter>=maxProgramCounter)
		std::cout<<"WB --->>> Empty\n";
else
	{
	if(mapInstruction.find(writeBackStage)!=mapInstruction.end())
		{
			if(mapInstruction.at(writeBackStage).instruction!="")
				std::cout<<"WB --->>> "<<mapInstruction.at(writeBackStage).instruction<<std::endl;
			else
						std::cout<<"WB --->>> Empty\n";
		}
	}
std::cout<<"\nMEMORY LOCATION CONTENTS: \n";
std::cout<<"\n";
tempCounter=0;
for(i=0;i<=99;i++)
{
		std::cout<<"Mem["<<i<<"] = "<<memoryAddress.at(i)<<" ";
		if(tempCounter==9)
		{
			std::cout<<"\n";
			tempCounter=0;
		}
		tempCounter++;
}
std::cout<<"\n";
return 0;
}
/*
		Function Name: fetchStageExecution
		Author: Aditya Manjrekar
		Date: 24th FEb 2016
		Description: Handles the code for fetch Stage
	*/
int InstSimulator::Stage::fetchStageExecution()
{
	if(fetchStageProgramCounter==0||fetchStageProgramCounter>=maxProgramCounter)
	{
		std::cout<<"FETCH--->>>: EMPTY "<<std::endl;
		fetchStage=0;
	}
	else
	{
		if(mapInstruction.find(fetchStageProgramCounter)!=mapInstruction.end())
		{
			fetchStage=fetchStageProgramCounter;
			std::cout<<"FETCH--->>>: "<<mapInstruction.at(fetchStageProgramCounter).instruction<<std::endl;
		}
	}
	return 0;
}
/*
	Function Name: decodeStageExecution
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: decode the input instruction and categorizes it based on the opcode
*/

int InstSimulator::Stage::decodeStageExecution()
{
	int a=0;
	a=a*0;
	string decodedInstruction;
	if(decodeStop!=1)
	{
		if(decodeStageProgramCounter==0||decodeStageProgramCounter>=maxProgramCounter)
			{
				std::cout<<"Decode--->>>:  Empty "<<std::endl;
				decodeStage=0;
			}
		else
		{
		   if(mapInstruction.find(decodeStageProgramCounter)!=mapInstruction.end())
			{
				decodeStage=decodeStageProgramCounter;
				std::cout<<"Decode--->>>: "<<mapInstruction.at(decodeStageProgramCounter).instruction<<std::endl;
				decodedInstruction = mapInstruction.at(decodeStageProgramCounter).instruction;
				if (decodedInstruction.find("ADD")!=std::string::npos)
				{
					a= insHand.addInsturctionHandler(decodeStageProgramCounter);
					mapInstruction.at(decodeStageProgramCounter).opcode="ADD";
				}
				if (decodedInstruction.find("SUB")!=std::string::npos)
				{
					a=insHand.addInsturctionHandler(decodeStageProgramCounter);
					mapInstruction.at(decodeStageProgramCounter).opcode="SUB";
				}
				if (decodedInstruction.find("MUL")!=std::string::npos)
				{
					a=insHand.addInsturctionHandler(decodeStageProgramCounter);
					mapInstruction.at(decodeStageProgramCounter).opcode="MUL";
				}
				if (decodedInstruction.find("AND")!=std::string::npos)
				{
					a=insHand.addInsturctionHandler(decodeStageProgramCounter);
					mapInstruction.at(decodeStageProgramCounter).opcode="AND";
				}
				if (decodedInstruction.find("NOP")!=std::string::npos)
				{
					mapInstruction.at(decodeStageProgramCounter).opcode="NOP";
				}
				if (decodedInstruction.find("STORE")!=std::string::npos)
				{
					a=insHand.storeInsturctionHandler(decodeStageProgramCounter);
					mapInstruction.at(decodeStageProgramCounter).opcode="STORE";
				}
				else if (decodedInstruction.find("XOR")!=std::string::npos)
				{
					a=insHand.addInsturctionHandler(decodeStageProgramCounter);
					mapInstruction.at(decodeStageProgramCounter).opcode="XOR";
				}
				else if (decodedInstruction.find("OR")!=std::string::npos)
				{
					a=insHand.orInsturctionHandler(decodeStageProgramCounter);
					mapInstruction.at(decodeStageProgramCounter).opcode="OR";
				}
				if (decodedInstruction.find("MOVC")!=std::string::npos)
				{
					a=insHand.movcInsturctionHandler(decodeStageProgramCounter);
					mapInstruction.at(decodeStageProgramCounter).opcode="MOVC";
				}
				else if (decodedInstruction.find("MOV")!=std::string::npos)
				{
					a=insHand.movInsturctionHandler(decodeStageProgramCounter);
					mapInstruction.at(decodeStageProgramCounter).opcode="MOV";
				}
				if (decodedInstruction.find("HALT")!=std::string::npos)
				{
					a=insHand.haltInsturctionHandler(decodeStageProgramCounter);
					mapInstruction.at(decodeStageProgramCounter).opcode="HALT";
					haltInstruction =1;
					haltInstructionProgramCounter = decodeStageProgramCounter;
				}
				if (decodedInstruction.find("LOAD")!=std::string::npos)
				{
					a=insHand.loadInsturctionHandler(decodeStageProgramCounter);
					mapInstruction.at(decodeStageProgramCounter).opcode="LOAD";
				}
				if (decodedInstruction.find("BA")!=std::string::npos)
				{
					a=insHand.balInsturctionHandler(decodeStageProgramCounter);
					mapInstruction.at(decodeStageProgramCounter).opcode="BAL";
					bal =1;
					balProgramCounter =  decodeStageProgramCounter;
				}
				if (decodedInstruction.find("JUMP")!=std::string::npos)
				{
					a=insHand.jumpInsturctionHandler(decodeStageProgramCounter);
					mapInstruction.at(decodeStageProgramCounter).opcode="JUMP";
					jumpInstruction = 1;
					jumpInstructionProgramCounter =  decodeStageProgramCounter;
				}
				if (decodedInstruction.find("BNZ")!=std::string::npos)
				{
					a=insHand.bnzInsturctionHandler(decodeStageProgramCounter);
					mapInstruction.at(decodeStageProgramCounter).opcode="BNZ";
					BNZ = 1;
					branchInstructionProgramCounterBNZ =  decodeStageProgramCounter;
				}
				if (decodedInstruction.find("BZ")!=std::string::npos)
				{
					a= insHand.bzInsturctionHandler(decodeStageProgramCounter);
					mapInstruction.at(decodeStageProgramCounter).opcode="BZ";
					BZ = 1;
					branchInstructionProgramCounterBZ =  decodeStageProgramCounter;
				}

				insturctionID=decodeStageProgramCounter;
			}


//dependency on consecutive inst
			if(insturctionID>0)
			{
				if(mapInstruction.at(insturctionID).opcode.compare("NOP")!=0)
				{
					if(mapInstruction.at(insturctionID).opcode.compare("MOVC")!=0)
					{
						if( writeBackStageProgramCounter>0 || memoryStageProgramCounter > 0 || executeStageProgramCounter > 0 )
						{
							if(mapInstruction.at(insturctionID).src1 != "")
							{
								if(mapInstruction.at(insturctionID).src1.compare(mapInstruction.at(insturctionID-1).dest)==0)
								{
									dependency1=1;
									dependencyInstrutionID1 = decodeStageProgramCounter-1;
								}
							}
							 if( mapInstruction.at(insturctionID).src2 != "")
							{
								if(mapInstruction.at(insturctionID).src2.compare(mapInstruction.at(insturctionID-1).dest)==0)
								{
									dependency1=1;
									dependencyInstrutionID1 = decodeStageProgramCounter-1;
								}
							}
							if(mapInstruction.at(insturctionID).opcode.compare("STORE")==0)
							{
								if(mapInstruction.at(insturctionID).src1 != "")
								{
									if(mapInstruction.at(insturctionID).src1.compare(mapInstruction.at(insturctionID-1).dest)==0)
									{
										dependency1=1;
										dependencyInstrutionID1 = decodeStageProgramCounter-1;
									}
								}
							 if( mapInstruction.at(insturctionID).src2 != "")
								{
									if(mapInstruction.at(insturctionID).src2.compare(mapInstruction.at(insturctionID-1).dest)==0)
									{
										dependency1=1;
										dependencyInstrutionID1 = decodeStageProgramCounter-1;
									}
								}
							}
							if(mapInstruction.at(insturctionID).src1 != "")
							{
								if(mapInstruction.at(insturctionID).src1.compare(mapInstruction.at(insturctionID-2).dest)==0)
									{
										if(mapInstruction.at(insturctionID-2).done!=1)
										{
											dependency2=1;
											dependencyInstrutionID2=decodeStageProgramCounter-2;
										}
									}
							}
							if(mapInstruction.at(insturctionID).src2 != "")
							{
								if(mapInstruction.at(insturctionID).src2.compare(mapInstruction.at(insturctionID-2).dest)==0)
								{
									if(mapInstruction.at(insturctionID-2).done!=1)
									{
										dependency2=1;
										dependencyInstrutionID2=decodeStageProgramCounter-2;
									}
								}
							}
					}//to handle jump instructions
					else
					{//Since no instruction in the pipeine nullifying the dependency
						dependency1 = 0;
						dependency2 =0;
					}

			}//MOV
			}//NOP
			}//Instruction ID > 0
		}//decode address found
		}//decode stop

return 0;

}
/*
	Function Name: executeStageExecution
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Execute the instruction based on the decode information
*/

int InstSimulator::Stage::executeStageExecution()
{
			if(executeStageProgramCounter==0||executeStageProgramCounter>=maxProgramCounter)
			{
				std::cout<<"EXE --->>>  Empty \n  ";
				executeStage=0;
			}
			else
			{

					if(mapInstruction.find(executeStageProgramCounter)!=mapInstruction.end())
						{
							executeStage=executeStageProgramCounter;
							std::cout<<"EXE --->>> "<<mapInstruction.at(executeStage).instruction<<std::endl;
							instructionSet inst = mapInstruction.at(executeStage);
							if(inst.opcode.compare("ADD")==0)
								exeInst.executeAddInstruction(executeStage);
							if(inst.opcode.compare("SUB")==0)
								exeInst.executeSubInstruction(executeStage);
							if(inst.opcode.compare("MUL")==0)
								exeInst.executeMulInstruction(executeStage);
							if(inst.opcode.compare("AND")==0)
								exeInst.executeAndInstruction(executeStage);
							if(inst.opcode.compare("OR")==0)
								exeInst.executeOrInstruction(executeStage);
							if(inst.opcode.compare("MOVC")==0)
								exeInst.executeMovcInstruction(executeStage);
							if(inst.opcode.compare("MOV")==0)
								exeInst.executeMovcInstruction(executeStage);
							if(inst.opcode.compare("XOR")==0)
								exeInst.executeXorInstruction(executeStage);
							if(inst.opcode.compare("HALT")==0)
								exeInst.executeHaltInstruction(executeStage);
							if(inst.opcode.compare("LOAD")==0)
								exeInst.executeAddInstruction(executeStage);
							if(inst.opcode.compare("STORE")==0)
								exeInst.executeStoreInstruction(executeStage);
							if(inst.opcode.compare("BAL")==0)
								exeInst.executeBalInstruction(executeStage);
							if(inst.opcode.compare("JUMP")==0)
								exeInst.executeJumpInstruction(executeStage);
							if(inst.opcode.compare("BZ")==0)
								exeInst.executeBZInstruction(executeStage);
							if(inst.opcode.compare("BNZ")==0)
								exeInst.executeBNZInstruction(executeStage);
	                        }
	                     }
	return 0;
}
/*
	Function Name: memoryStageExecution
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: copies  and stores the data to the memory location for load and store insturctions
*/

int InstSimulator::Stage::memoryStageExecution()
{
	 int a=0;
	 a=a*0;
		if(memoryStageProgramCounter==0||memoryStageProgramCounter>=maxProgramCounter)
		{
			std::cout<<"MEM--->>>  Empty \n";
			memoryStage=0;
		}
	    else
	    {
			if(mapInstruction.find(memoryStageProgramCounter)!=mapInstruction.end())
			{
				memoryStage=memoryStageProgramCounter;
				std::cout<<"MEM--->>> "<<mapInstruction.at(memoryStage).instruction<<std::endl;
				instructionSet inst = mapInstruction.at(memoryStage);
				if(inst.opcode.compare("LOAD")==0)
				{
					a= exeInst.memoryStageLoadExecution(memoryStage);
				}
				if(inst.opcode.compare("STORE")==0)
				{
					a= exeInst.memoryStageStoreExecution(memoryStage);
				}

			}
		}
	return 0;
}
/*
	Function Name: wrtieBackStageExecution
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: writes the contents to the register file
*/

int InstSimulator::Stage::wrtieBackStageExecution()
{
	string destRegister;
	int p=0;
	p=p*0;
		if(writeBackStageProgramCounter==dependencyInstrutionID1)
		{
			dependency1=0;
		}

	if(writeBackStageProgramCounter==dependencyInstrutionID2)
	{
		dependency2=0;
	}

		if(writeBackStageProgramCounter==0||writeBackStageProgramCounter>=maxProgramCounter)
		{
			std::cout<<"WB--->>> EMPTY \n";
			writeBackStage=0;
		}
		else
		{
			if(mapInstruction.find(writeBackStageProgramCounter)!= mapInstruction.end())
				{
					instructionSet inst = mapInstruction.at(writeBackStageProgramCounter);
					if(inst.opcode.compare("STORE")==0)
					{
						std::cout<<"WB--->>>   "<< inst.instruction<<std::endl;
						writeBackStage = writeBackStageProgramCounter;
					}
					else if(inst.opcode.compare("NOP")==0)
					{
						std::cout<<"WB--->>>   "<< inst.instruction<<std::endl;
						writeBackStage = writeBackStageProgramCounter;
					}
					else if(inst.opcode.compare("BA")==0)
					{
						std::cout<<"WB--->>>   "<< inst.instruction<<std::endl;
					}
					else if(inst.opcode.compare("JUMP")==0)
					{
						std::cout<<"WB--->>>   "<< inst.instruction<<std::endl;
						writeBackStage = writeBackStageProgramCounter;
						jumpInstruction =0;
						jumpFlag=1;
					}
					else if(inst.opcode.compare("BNZ")==0)
					{
						std::cout<<"WB--->>>   "<< inst.instruction<<std::endl;
						writeBackStage = writeBackStageProgramCounter;
					}
					else if(inst.opcode.compare("BZ")==0)
					{
						std::cout<<"WB--->>>   "<< inst.instruction<<std::endl;
						writeBackStage = writeBackStageProgramCounter;
					}
					else
					{
						writeBackStage = writeBackStageProgramCounter;
						std::cout<<"WB--->>>   "<< inst.instruction<<std::endl;
						if(mapInstruction.at(writeBackStage).dest.compare("")!=0)
						{
							destRegister =mapInstruction.at(writeBackStage).dest;
							registers.at(destRegister) = mapInstruction.at(writeBackStage).destValue;
							for(map<int,instructionSet>::iterator it = mapInstruction.begin();it!=mapInstruction.end();++it)
							{
								if(it->second.src1.compare(destRegister)==0)
								{
									it->second.src1Value = registers.at(destRegister);
								}
								if(it->second.src2.compare(destRegister)==0)
								{
									it->second.src2Value = registers.at(destRegister);
								}

							}
						}
						mapInstruction.at(writeBackStage).done=1;
					}

				}
		}
	return 0;
}
