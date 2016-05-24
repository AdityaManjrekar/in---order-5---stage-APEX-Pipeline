/*
	File Name: Instruction Simulator
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Implementation:
*/
/*
	Header files
*/

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "instructionStruct.hpp"
#include "globals.hpp"
#include "InstSimulator.hpp"
/*
 * Class Global
 */
InstSimulator sim;

/*
	Function Name: main()
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: main function execution begins from this function
*/

int main()
{
int choice,i=0,numberOfInstructions=0,a;
int initialisedFlag = 0;
a=a*0;
string fileName="";
//	HERE:
	bool continueFlag = true;
	while(continueFlag)
	{
		std::cout<<"\n";
		std::cout<<"1.Load:\n";
		std::cout<<"2.Initialize:\n";
		std::cout<<"3.Simulate all:\n";
		std::cout<<"4.simulate(n):\n";
		std::cout<<"5.Display:\n";
		std::cout<<"6.EXIT\n";
		std::cout<<"Please Enter choice:\n";
		std::cin>>choice;
		switch(choice)
		{
			case 1:
				{
						char instruction_read[20];
						std::cout<<"Enter the File Name:"<<std::endl;
						cin>>fileName;
						FILE *ptr;
						if((ptr=fopen(fileName.c_str(),"r"))==NULL)
						{
							std::cout<<"File Not Found\n";
							break;
						}

						while(fgets(instruction_read,70,ptr)!=NULL)                             //read line by line
						{
							instructionSet inst;
							string temp = "";
							temp = instruction_read;
							if(instruction_read[strlen(instruction_read)-1] != '\n')
								instruction_read[strlen(instruction_read)] = '\n';
							inst.instruction = instruction_read;
							int j=0;
							while(j<20)
							{
								instruction_read[j] = '\0';
								j++;
							}
							mapInstruction.insert(make_pair(20000+i,inst));
							i++;
							numberOfInstructions++;
						}
						number=numberOfInstructions;
						maxProgramCounter=20000+numberOfInstructions;
						std::cout<<"File Loaded\n";
					break;
				}
			case 2:
				{
					sim.initialize();
					initialisedFlag=1;
					std::cout<<"\ninitialised!!!!\n";
					break;
				}
			case 3:
				{
					if(initialisedFlag==1)
						{
							cycleNumber=0;
							while(writeBackStageProgramCounter<maxProgramCounter)
							{
								sim.cycle();
							}
						}
					else
						std::cout<<"Values Not Initialised!!!!\n";
					break;
				}
			case 4:
				{
					if(initialisedFlag==1)
						{
							std::cout<<"Enter  number of cycles to be processed:\n";
							std::cin>>cy;
							flag=1;
							int j=0;
							while(j<cy)
							{
								sim.cycle();
								j++;
							}
						}
						else
							std::cout<<"Values Not Initialised!!!!\n";
					break;
				}
			case 5:
				{
					a=sim.display();
					break;
				}
			case 6:
			{
				continueFlag = false;
				std::cout<<"Program Exited Normally\n";
				break;
			}
		}
	}
return 0;

}
