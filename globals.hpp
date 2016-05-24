
#ifndef MAP_HPP
#define MAP_HPP
#include<map>
using namespace std;
#endif
/*
	Global Variables
*/

#define MAX_LENGTH 1024
map<int,instructionSet> mapInstruction;
map<int,int> memoryAddress;
map<string,int> registers;

int maxProgramCounter=0,number=0,cycleNumber=0;
int fetchStage,decodeStage,executeStage,memoryStage,writeBackStage;
int jumpAddressLcation;
int fetchStageProgramCounter,decodeStageProgramCounter,executeStageProgramCounter,memoryStageProgramCounter,writeBackStageProgramCounter;
int haltInstruction=0 ,haltInstructionProgramCounter;
int R0,R1,R2,R3,R4,R5,R6,R7;
int jumpInstructionProgramCounter,jumpInstruction,jumpFlag;
int X=0,fNext=0;
int BNZ,BZ,branchInstructionBNZ,branchInstructionBZ,branchInstructionProgramCounterBNZ,branchInstructionBNZADD,branchInstructionProgramCounterBZ,branchInstructionBZADD,zeroFlag;
int cy=0,flag=0;
int decodeStop=0;
int totalNumberOfInstructions=0;
int balProgramCounter,bal=0,balFlag,balAdd;
int insturctionID=0;
int dependency1=0;
int dependencyInstrutionID1 =0;
int dependency2=0;
int	dependencyInstrutionID2=0;
int EXIT=0,EXIT_HALT=0;

