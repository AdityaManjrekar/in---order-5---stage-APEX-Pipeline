class instructionHandler
{
public:
	/*
	 * Function Declarations
	 */
	int addInsturctionHandler(int);
	int orInsturctionHandler(int);
	int movcInsturctionHandler(int);
	int movInsturctionHandler(int);
	int exorInsturctionHandler(int);
	int loadInsturctionHandler(int);
	int storeInsturctionHandler(int);
	int balInsturctionHandler(int);
	int jumpInsturctionHandler(int);
	int bnzInsturctionHandler(int);
	int bzInsturctionHandler(int);
	int haltInsturctionHandler(int);

};
/*
	Function Name: addInsturctionHandler
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to update the surce and destinaltion registers for the Add,Sub,MUL,And Insturction
*/

int instructionHandler::addInsturctionHandler(int location)
	{
		string decodedInstruction,src1,src2;
		int i=0;
		decodedInstruction = mapInstruction.at(location).instruction;
		if (decodedInstruction.find("\n")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\n"),1,"");
		if (decodedInstruction.find("\r")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\r"),1,"");
		char temp[1024];//[decodedInstruction.length()+1];
	 	char * pch;
	 	strcpy(temp,decodedInstruction.c_str());
		pch = strtok (temp," ,");
		while (pch != NULL)
		{
			if(i==1)
			{
				//Destination Register details
				mapInstruction.at(location).dest = string(pch); //decodedInstruction.substr(4,2);
				mapInstruction.at(location).destValue=registers.at(mapInstruction.at(location).dest);		
			}
			else if(i==2)
			{
				//Source 1  Register details
				src1 =  string(pch); //decodedInstruction.substr(7,2);
				mapInstruction.at(location).src1 = src1;
				mapInstruction.at(location).src1Value=registers.at(src1);
			}
			else if(i==3)
			{
				//Source 2  Register details
				if(pch[0]=='R')
				{
					src2 =  string(pch); // decodedInstruction.substr(10,2);
					mapInstruction.at(location).src2 = src2;
					mapInstruction.at(location).src2Value=registers.at(src2);
				}
				else if(pch[0]=='#')
				{
					mapInstruction.at(location).literal =  string(pch);  //decodedInstruction.substr(10,decodedInstruction.length()-10-1);
					char *temp1 = &(pch[1]);
					mapInstruction.at(location).litValue= stoi(string(temp1));//stoi(decodedInstruction.substr(11,decodedInstruction.length()-11-1));
				}
				else
				{
					mapInstruction.at(location).literal = string(pch);//decodedInstruction.substr(10,decodedInstruction.length()-10-1);
					mapInstruction.at(location).litValue=	stoi(string(pch));//stoi(decodedInstruction.substr(10,decodedInstruction.length()-10-1));
				}
			}
		  pch = strtok (NULL, " ,");
		  i++;
		}
		return 0;
		}
/*
	Function Name: orInsturctionHandler
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to update the surce and destinaltion registers for the OR Insturction
*/
int instructionHandler::orInsturctionHandler(int location)
	{
		string decodedInstruction,src1,src2;
		int i=0;
		decodedInstruction = mapInstruction.at(location).instruction;
		if (decodedInstruction.find("\n")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\n"),1,"");
		if (decodedInstruction.find("\r")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\r"),1,"");
		char temp[1024];//[decodedInstruction.length()+1];
	 	char * pch;
	 	strcpy(temp,decodedInstruction.c_str());
		pch = strtok (temp," ,");
		while (pch != NULL)
		{
			if(i==1)
			{
				//Destination Register details
				mapInstruction.at(location).dest = string(pch); //decodedInstruction.substr(4,2);
				mapInstruction.at(location).destValue=registers.at(mapInstruction.at(location).dest);		
			}
			else if(i==2)
			{
				//Source 1  Register details
				src1 =  string(pch); //decodedInstruction.substr(7,2);
				mapInstruction.at(location).src1 = src1;
				mapInstruction.at(location).src1Value=registers.at(src1);
			}
			else if(i==3)
			{
				//Source 2  Register details
				if(pch[0]=='R')
				{
					src2 =  string(pch); // decodedInstruction.substr(10,2);
					mapInstruction.at(location).src2 = src2;
					mapInstruction.at(location).src2Value=registers.at(src2);
				}
				else if(pch[0]=='#')
				{
					mapInstruction.at(location).literal =  string(pch);  //decodedInstruction.substr(10,decodedInstruction.length()-10-1);
					char *temp1 = &(pch[1]);
					mapInstruction.at(location).litValue= stoi(string(temp1));//stoi(decodedInstruction.substr(11,decodedInstruction.length()-11-1));
				}
				else
				{
					mapInstruction.at(location).literal = string(pch);//decodedInstruction.substr(10,decodedInstruction.length()-10-1);
					mapInstruction.at(location).litValue=	stoi(string(pch));//stoi(decodedInstruction.substr(10,decodedInstruction.length()-10-1));
				}
			}
		  pch = strtok (NULL, " ,");
		  i++;
		}

		return 0;
	}
/*
	Function Name: movcInsturctionHandler
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to update the surce and destinaltion registers for the MOVC Insturction
*/

int instructionHandler::movcInsturctionHandler(int location)
{
		string decodedInstruction,src1,src2;
		int i=0;
		decodedInstruction = mapInstruction.at(location).instruction;
		if (decodedInstruction.find("\n")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\n"),1,"");
		if (decodedInstruction.find("\r")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\r"),1,"");
		char temp[1024];//[decodedInstruction.length()+1];
	 	char * pch;
	 	strcpy(temp,decodedInstruction.c_str());
		pch = strtok (temp," ,");
		while (pch != NULL)
		{
			if(i==1)
			{
				//Destination Register details
				mapInstruction.at(location).dest = string(pch); //decodedInstruction.substr(4,2);
				mapInstruction.at(location).destValue=registers.at(mapInstruction.at(location).dest);		
			}
			else if(i==2)
			{
				//Source 2  Register details
				if(pch[0]=='R')
				{
					src2 =  string(pch); // decodedInstruction.substr(10,2);
					mapInstruction.at(location).src2 = src2;
					mapInstruction.at(location).src2Value=registers.at(src2);
				}
				else if(pch[0]=='#')
				{
					mapInstruction.at(location).src2 =  string(pch);  //decodedInstruction.substr(10,decodedInstruction.length()-10-1);
					char *temp1 = &(pch[1]);
					mapInstruction.at(location).src2Value= stoi(string(temp1));//stoi(decodedInstruction.substr(11,decodedInstruction.length()-11-1));
				}
				else
				{
					mapInstruction.at(location).src2 = string(pch);//decodedInstruction.substr(10,decodedInstruction.length()-10-1);
					mapInstruction.at(location).src2Value=	stoi(string(pch));//stoi(decodedInstruction.substr(10,decodedInstruction.length()-10-1));
				}
			}
		  pch = strtok (NULL, " ,");
		  i++;
		}
	return 0;
}

/*
	Function Name: movInsturctionHandler
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to update the surce and destinaltion registers for the MOV Insturction
*/
int instructionHandler::movInsturctionHandler(int location)
{
/*
	string decodedInstruction,src2;
	decodedInstruction = mapInstruction.at(location).instruction;
	if(decodedInstruction.find("R",7)!=string::npos)
	{
		src2 = decodedInstruction.substr(7,2);
		mapInstruction.at(location).src2 = src2;
		mapInstruction.at(location).src2Value=registers.at(src2);
	}
	else if(decodedInstruction.find("X",7)!=string::npos) //Literal with # found
	{
		mapInstruction.at(location).src2 = decodedInstruction.substr(7,decodedInstruction.length()-7-1);
		mapInstruction.at(location).src2Value = X;
	}

	mapInstruction.at(location).dest = decodedInstruction.substr(4,2);
	mapInstruction.at(location).destValue=registers.at(mapInstruction.at(location).dest);
	*/
	
		string decodedInstruction,src1,src2;
		int i=0;
		decodedInstruction = mapInstruction.at(location).instruction;
		if (decodedInstruction.find("\n")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\n"),1,"");
		if (decodedInstruction.find("\r")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\r"),1,"");
		char temp[1024];//[decodedInstruction.length()+1];
	 	char * pch;
	 	strcpy(temp,decodedInstruction.c_str());
		pch = strtok (temp," ,");
		while (pch != NULL)
		{
			if(i==1)
			{
				//Destination Register details
				mapInstruction.at(location).dest = string(pch); //decodedInstruction.substr(4,2);
				mapInstruction.at(location).destValue=registers.at(mapInstruction.at(location).dest);		
			}
			else if(i==2)
			{
				//Source 2  Register details
				if(pch[0]=='R')
				{
					src2 =  string(pch); // decodedInstruction.substr(10,2);
					mapInstruction.at(location).src2 = src2;
					mapInstruction.at(location).src2Value=registers.at(src2);
				}
				else if(pch[0]=='X')
				{
					mapInstruction.at(location).src2 =  string(pch);  //decodedInstruction.substr(10,decodedInstruction.length()-10-1);
					mapInstruction.at(location).src2Value= X;//stoi(string(temp1));//stoi(decodedInstruction.substr(11,decodedInstruction.length()-11-1));
				}
			}
		  pch = strtok (NULL, " ,");
		  i++;
		}

	return 0;

}
/*
	Function Name: exorInsturctionHandler
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to update the surce and destinaltion registers for the EXOR Insturction
*/

int instructionHandler::exorInsturctionHandler(int location)
{
/*
	string decodedInstruction,src1,src2;
	decodedInstruction = mapInstruction.at(location).instruction;
	src1 = decodedInstruction.substr(9,2);
	mapInstruction.at(location).src1 = src1;
	mapInstruction.at(location).src1Value=registers.at(src1);

	if(decodedInstruction.find("R",12)!=string::npos)
	{
		src2 = decodedInstruction.substr(12,2);
		mapInstruction.at(location).src2 = src2;
		mapInstruction.at(location).src2Value=registers.at(src2);
	}
	else if(decodedInstruction.find("#",12)!=string::npos) //Literal found
	{
		mapInstruction.at(location).literal = decodedInstruction.substr(12,decodedInstruction.length()-12-1);
		mapInstruction.at(location).litValue=stoi(decodedInstruction.substr(13,decodedInstruction.length()-13-1));
	}
	else
	{
		mapInstruction.at(location).literal = decodedInstruction.substr(12,decodedInstruction.length()-12-1);
		mapInstruction.at(location).litValue=stoi(decodedInstruction.substr(12,decodedInstruction.length()-12-1));
	}
	mapInstruction.at(location).dest = decodedInstruction.substr(6,2);
	mapInstruction.at(location).destValue=registers.at(mapInstruction.at(location).dest);
*/
		string decodedInstruction,src1,src2;
		int i=0;
		decodedInstruction = mapInstruction.at(location).instruction;
		if (decodedInstruction.find("\n")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\n"),1,"");
		if (decodedInstruction.find("\r")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\r"),1,"");
		char temp[1024];//[decodedInstruction.length()+1];
	 	char * pch;
	 	strcpy(temp,decodedInstruction.c_str());
		pch = strtok (temp," ,");
		while (pch != NULL)
		{
			if(i==1)
			{
				//Destination Register details
				mapInstruction.at(location).dest = string(pch); //decodedInstruction.substr(4,2);
				mapInstruction.at(location).destValue=registers.at(mapInstruction.at(location).dest);		
			}
			else if(i==2)
			{
				//Source 1  Register details
				src1 =  string(pch); //decodedInstruction.substr(7,2);
				mapInstruction.at(location).src1 = src1;
				mapInstruction.at(location).src1Value=registers.at(src1);
			}
			else if(i==3)
			{
				//Source 2  Register details
				if(pch[0]=='R')
				{
					src2 =  string(pch); // decodedInstruction.substr(10,2);
					mapInstruction.at(location).src2 = src2;
					mapInstruction.at(location).src2Value=registers.at(src2);
				}
				else if(pch[0]=='#')
				{
					mapInstruction.at(location).literal =  string(pch);  //decodedInstruction.substr(10,decodedInstruction.length()-10-1);
					char *temp1 = &(pch[1]);
					mapInstruction.at(location).litValue= stoi(string(temp1));//stoi(decodedInstruction.substr(11,decodedInstruction.length()-11-1));
				}
				else
				{
					mapInstruction.at(location).literal = string(pch);//decodedInstruction.substr(10,decodedInstruction.length()-10-1);
					mapInstruction.at(location).litValue=	stoi(string(pch));//stoi(decodedInstruction.substr(10,decodedInstruction.length()-10-1));
				}
			}
		  pch = strtok (NULL, " ,");
		  i++;
		}

	return 0;
}
/*
 * Function Name: loadInsturctionHandler
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to update the surce and destinaltion registers for the LOAD Insturction
 */
int instructionHandler::loadInsturctionHandler(int location)
{
/*
	string decodedInstruction,src1,src2;
	decodedInstruction = mapInstruction.at(location).instruction;
	src1 = decodedInstruction.substr(8,2);
	mapInstruction.at(location).src1 = src1;
	mapInstruction.at(location).src1Value=registers.at(src1);

	if(decodedInstruction.find("R",11)!=string::npos)
	{
		src2 = decodedInstruction.substr(11,2);
		mapInstruction.at(location).src2 = src2;
		mapInstruction.at(location).src2Value=registers.at(src2);
	}
	else if(decodedInstruction.find("#",11)!=string::npos) //Literal found
	{
		mapInstruction.at(location).literal = decodedInstruction.substr(11,decodedInstruction.length()-11-1);
		mapInstruction.at(location).litValue=stoi(decodedInstruction.substr(12,decodedInstruction.length()-12-1));
	}
	else
	{
		mapInstruction.at(location).literal = decodedInstruction.substr(11,decodedInstruction.length()-11-1);
		mapInstruction.at(location).litValue=stoi(decodedInstruction.substr(11,decodedInstruction.length()-11-1));
	}
	mapInstruction.at(location).dest = decodedInstruction.substr(5,2);
	mapInstruction.at(location).destValue=registers.at(mapInstruction.at(location).dest);
*/
		string decodedInstruction,src1,src2;
		int i=0;
		decodedInstruction = mapInstruction.at(location).instruction;
		if (decodedInstruction.find("\n")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\n"),1,"");
		if (decodedInstruction.find("\r")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\r"),1,"");
		char temp[1024];//[decodedInstruction.length()+1];
	 	char * pch;
	 	strcpy(temp,decodedInstruction.c_str());
		pch = strtok (temp," ,");
		while (pch != NULL)
		{
			if(i==1)
			{
				//Destination Register details
				mapInstruction.at(location).dest = string(pch); //decodedInstruction.substr(4,2);
				mapInstruction.at(location).destValue=registers.at(mapInstruction.at(location).dest);		
			}
			else if(i==2)
			{
				//Source 1  Register details
				src1 =  string(pch); //decodedInstruction.substr(7,2);
				mapInstruction.at(location).src1 = src1;
				mapInstruction.at(location).src1Value=registers.at(src1);
			}
			else if(i==3)
			{
				//Source 2  Register details
				if(pch[0]=='R')
				{
					src2 =  string(pch); // decodedInstruction.substr(10,2);
					mapInstruction.at(location).src2 = src2;
					mapInstruction.at(location).src2Value=registers.at(src2);
				}
				else if(pch[0]=='#')
				{
					mapInstruction.at(location).literal =  string(pch);  //decodedInstruction.substr(10,decodedInstruction.length()-10-1);
					char *temp1 = &(pch[1]);
					mapInstruction.at(location).litValue= stoi(string(temp1));//stoi(decodedInstruction.substr(11,decodedInstruction.length()-11-1));
				}
				else
				{
					mapInstruction.at(location).literal = string(pch);//decodedInstruction.substr(10,decodedInstruction.length()-10-1);
					mapInstruction.at(location).litValue=	stoi(string(pch));//stoi(decodedInstruction.substr(10,decodedInstruction.length()-10-1));
				}
			}
		  pch = strtok (NULL, " ,");
		  i++;
		}

	return 0;
}
/*
 * Function Name: storeInsturctionHandler
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to update the surce and destinaltion registers for the STORE Insturction
 */
int instructionHandler::storeInsturctionHandler(int location)
{
/*
	string decodedInstruction,src1,src2;
	decodedInstruction = mapInstruction.at(location).instruction;
	src1 = decodedInstruction.substr(6,2);
	mapInstruction.at(location).src1 = src1;
	mapInstruction.at(location).src1Value=registers.at(src1);

	src2 = decodedInstruction.substr(9,2);
	mapInstruction.at(location).src2 = src2;
	mapInstruction.at(location).src2Value=registers.at(src2);

	if(decodedInstruction.find("R",12)!=string::npos)
		{
			src2 = decodedInstruction.substr(12,2);
			mapInstruction.at(location).literal = src2;
			mapInstruction.at(location).litValue=registers.at(src2);
		}
	else if(decodedInstruction.find("#",12)!=string::npos) //Literal found
	{
		mapInstruction.at(location).literal = decodedInstruction.substr(12,decodedInstruction.length()-12-1);
		mapInstruction.at(location).litValue=stoi(decodedInstruction.substr(13,decodedInstruction.length()-13-1));
	}
	else
	{
		mapInstruction.at(location).literal = decodedInstruction.substr(12,decodedInstruction.length()-12-1);
		mapInstruction.at(location).litValue=stoi(decodedInstruction.substr(12,decodedInstruction.length()-12-1));
	}
*/
		string decodedInstruction,src1,src2;
		int i=0;
		decodedInstruction = mapInstruction.at(location).instruction;
		if (decodedInstruction.find("\n")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\n"),1,"");
		if (decodedInstruction.find("\r")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\r"),1,"");
		char temp[1024];//[decodedInstruction.length()+1];
	 	char * pch;
	 	strcpy(temp,decodedInstruction.c_str());
		pch = strtok (temp," ,");
		while (pch != NULL)
		{
			if(i==1)
			{
				//Source 1  Register details
				src1 =  string(pch); //decodedInstruction.substr(7,2);
				mapInstruction.at(location).src1 = src1;
				mapInstruction.at(location).src1Value=registers.at(src1);
			}
			else if(i==2)
			{
				//Source 2  Register details
				src2 =  string(pch); // decodedInstruction.substr(10,2);
				mapInstruction.at(location).src2 = src2;
				mapInstruction.at(location).src2Value=registers.at(src2);
			}
			else if(i==3)
			{
				if(pch[0]=='#')
				{
					mapInstruction.at(location).literal =  string(pch);  //decodedInstruction.substr(10,decodedInstruction.length()-10-1);
					char *temp1 = &(pch[1]);
					mapInstruction.at(location).litValue= stoi(string(temp1));//stoi(decodedInstruction.substr(11,decodedInstruction.length()-11-1));
				}
				else
				{
					mapInstruction.at(location).literal = string(pch);//decodedInstruction.substr(10,decodedInstruction.length()-10-1);
					mapInstruction.at(location).litValue=	stoi(string(pch));//stoi(decodedInstruction.substr(10,decodedInstruction.length()-10-1));
				}
			}
		  pch = strtok (NULL, " ,");
		  i++;
		}

	return 0;
}
/*
 * Function Name: balInsturctionHandler
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to update the surce and destinaltion registers for the BAL Insturction
 */
int instructionHandler::balInsturctionHandler(int location)
{
/*
		string decodedInstruction,src2,src1;
		decodedInstruction = mapInstruction.at(location).instruction;
		src1 = decodedInstruction.substr(4,2);
		mapInstruction.at(location).src1 = src1;
		mapInstruction.at(location).src1Value=registers.at(src1);

		if(decodedInstruction.find("R",7)!=string::npos)
		{
			src2 = decodedInstruction.substr(7,2);
			mapInstruction.at(location).src2 = src2;
			mapInstruction.at(location).src2Value=registers.at(src2);
		}
		else if(decodedInstruction.find("#",7)!=string::npos) //Literal with # found
		{
			mapInstruction.at(location).src2 = decodedInstruction.substr(7,decodedInstruction.length()-7-1);
			mapInstruction.at(location).src2Value = stoi(decodedInstruction.substr(8,decodedInstruction.length()-8-1));
		}
		else
		{
			mapInstruction.at(location).src2 = decodedInstruction.substr(7,decodedInstruction.length()-7-1);
			mapInstruction.at(location).src2Value = stoi(decodedInstruction.substr(7,decodedInstruction.length()-7-1));
		}
*/
		string decodedInstruction,src1,src2;
		int i=0;
		decodedInstruction = mapInstruction.at(location).instruction;
		if (decodedInstruction.find("\n")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\n"),1,"");
		if (decodedInstruction.find("\r")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\r"),1,"");
		char temp[1024];//[decodedInstruction.length()+1];
	 	char * pch;
	 	strcpy(temp,decodedInstruction.c_str());
		pch = strtok (temp," ,");
		while (pch != NULL)
		{
			if(i==1)
			{
				//Source 1  Register details
				src1 =  string(pch); //decodedInstruction.substr(7,2);
				mapInstruction.at(location).src1 = src1;
				mapInstruction.at(location).src1Value=registers.at(src1);
			}
			else if(i==2)
			{
				//Source 2  Register details
				if(pch[0]=='R')
				{
					src2 =  string(pch); // decodedInstruction.substr(10,2);
					mapInstruction.at(location).src2 = src2;
					mapInstruction.at(location).src2Value=registers.at(src2);
				}
				else if(pch[0]=='#')
				{
					mapInstruction.at(location).src2 =  string(pch);  //decodedInstruction.substr(10,decodedInstruction.length()-10-1);
					char *temp1 = &(pch[1]);
					mapInstruction.at(location).src2Value= stoi(string(temp1));//stoi(decodedInstruction.substr(11,decodedInstruction.length()-11-1));
				}
				else
				{
					mapInstruction.at(location).src2 = string(pch);//decodedInstruction.substr(10,decodedInstruction.length()-10-1);
					mapInstruction.at(location).src2Value=	stoi(string(pch));//stoi(decodedInstruction.substr(10,decodedInstruction.length()-10-1));
				}
			}
		  pch = strtok (NULL, " ,");
		  i++;
		}

	return 0;
}
/*
 * Function Name: jumpInsturctionHandler
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to update the surce and destinaltion registers for the JUMP Insturction
 */
int instructionHandler::jumpInsturctionHandler(int location)
{
/*
	string decodedInstruction,src1,src2;
	decodedInstruction = mapInstruction.at(location).instruction;
	if(decodedInstruction.find("R",5)!=string::npos)
	{
		src1 = decodedInstruction.substr(5,2);
		mapInstruction.at(location).src1 = src1;
		mapInstruction.at(location).src1Value=registers.at(src1);

		if(decodedInstruction.find("R",8)!=string::npos)
			{
				src2 = decodedInstruction.substr(8,2);
				mapInstruction.at(location).src2 = src2;
				mapInstruction.at(location).src2Value=registers.at(src2);
			}
		else if(decodedInstruction.find("#",8)!=string::npos) //Literal found
		{
			mapInstruction.at(location).literal = decodedInstruction.substr(9,decodedInstruction.length()-8-1);
			mapInstruction.at(location).litValue=stoi(decodedInstruction.substr(9,decodedInstruction.length()-9-1));
		}
		else
		{
			mapInstruction.at(location).literal = decodedInstruction.substr(8,decodedInstruction.length()-8-1);
			mapInstruction.at(location).litValue=stoi(decodedInstruction.substr(8,decodedInstruction.length()-8-1));
		}
	}
	else if(decodedInstruction.find("X",5)!=string::npos)
	{
		src1 = decodedInstruction.substr(5,1);
		mapInstruction.at(location).src1 = src1;
		mapInstruction.at(location).src1Value=X;
		if(decodedInstruction.find("R",7)!=string::npos) //Literal found
		{
			mapInstruction.at(location).src2 = decodedInstruction.substr(7,decodedInstruction.length()-7-1);
			mapInstruction.at(location).src2Value=stoi(decodedInstruction.substr(7,decodedInstruction.length()-7-1));
		}
	}
*/
		string decodedInstruction,src1,src2;
		int i=0;
		decodedInstruction = mapInstruction.at(location).instruction;
	if(decodedInstruction.find("R",5)!=string::npos)
	{
		if (decodedInstruction.find("\n")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\n"),1,"");
		if (decodedInstruction.find("\r")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\r"),1,"");
		char temp[1024];//[decodedInstruction.length()+1];
	 	char * pch;
	 	strcpy(temp,decodedInstruction.c_str());
		pch = strtok (temp," ,");
		while (pch != NULL)
		{
			if(i==1)
			{
				//Source 1  Register details
				src1 =  string(pch); //decodedInstruction.substr(7,2);
				mapInstruction.at(location).src1 = src1;
				mapInstruction.at(location).src1Value=registers.at(src1);
			}
			else if(i==2)
			{
				//Source 2  Register details
				if(pch[0]=='R')
				{
					src2 =  string(pch); // decodedInstruction.substr(10,2);
					mapInstruction.at(location).src2 = src2;
					mapInstruction.at(location).src2Value=registers.at(src2);
				}
				else if(pch[0]=='#')
				{
					mapInstruction.at(location).src2 =  string(pch);  //decodedInstruction.substr(10,decodedInstruction.length()-10-1);
					char *temp1 = &(pch[1]);
					mapInstruction.at(location).src2Value= stoi(string(temp1));//stoi(decodedInstruction.substr(11,decodedInstruction.length()-11-1));
				}
				else
				{
					mapInstruction.at(location).src2 = string(pch);//decodedInstruction.substr(10,decodedInstruction.length()-10-1);
					mapInstruction.at(location).src2Value=	stoi(string(pch));//stoi(decodedInstruction.substr(10,decodedInstruction.length()-10-1));
				}
			}
		  pch = strtok (NULL, " ,");
		  i++;
		}

	}
	else if(decodedInstruction.find("X",5)!=string::npos)
	{
	/*
		src1 = decodedInstruction.substr(5,1);
		mapInstruction.at(location).src1 = src1;
		mapInstruction.at(location).src1Value=X;
		if(decodedInstruction.find("R",7)!=string::npos) //Literal found
		{
			mapInstruction.at(location).src2 = decodedInstruction.substr(7,decodedInstruction.length()-7-1);
			mapInstruction.at(location).src2Value=stoi(decodedInstruction.substr(7,decodedInstruction.length()-7-1));
		}
		*/
		if (decodedInstruction.find("\n")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\n"),1,"");
		if (decodedInstruction.find("\r")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\r"),1,"");
		char temp[1024];//[decodedInstruction.length()+1];
	 	char * pch;
	 	strcpy(temp,decodedInstruction.c_str());
		pch = strtok (temp," ,");
		while (pch != NULL)
		{
			if(i==1)
			{
				//Source 1  Register details
				src1 =  string(pch); //decodedInstruction.substr(7,2);
				mapInstruction.at(location).src1 = src1;
				mapInstruction.at(location).src1Value=X;
			}
			else if(i==2)
			{
				//Source 2  Register details
				src2 =  string(pch); // decodedInstruction.substr(10,2);
				mapInstruction.at(location).src2 = src2;
				mapInstruction.at(location).src2Value=stoi(src2);//registers.at(src2);
			}
		  pch = strtok (NULL, " ,");
		  i++;
		}

	}

	return 0;
}
/*
 * Function Name: bnzInsturctionHandler
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to update the surce and destinaltion registers for the BNZ Insturction
 */

int instructionHandler::bnzInsturctionHandler(int location)
{
	string decodedInstruction,src1;
	decodedInstruction = mapInstruction.at(location).instruction;
/*
	src1 = decodedInstruction.substr(4,decodedInstruction.length()-4-1);
	mapInstruction.at(location).src1 = src1;
	std::cout<<"---------> "<<stoi(src1)<<std::endl;
	mapInstruction.at(location).src1Value=stoi(src1);
	mapInstruction.at(location).src2 = "R9";
	mapInstruction.at(location).src2Value=0;
*/
		if (decodedInstruction.find("\n")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\n"),1,"");
		if (decodedInstruction.find("\r")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\r"),1,"");

		int i=0;
		char temp[1024];//[decodedInstruction.length()+1];
	 	char * pch;
	 	strcpy(temp,decodedInstruction.c_str());
		pch = strtok (temp," ,");
		while (pch != NULL)
		{
			if(i==1)
			{
				//Source 1  Register details
				src1 =  string(pch); //decodedInstruction.substr(7,2);
				mapInstruction.at(location).src1 = src1;
				mapInstruction.at(location).src1Value=stoi(src1);//registers.at(src1);
			}
			else if(i==2)
			{
				//Source 2  Register details
					mapInstruction.at(location).src2 = "R32";
					mapInstruction.at(location).src2Value=0;
			}
		  pch = strtok (NULL, " ,");
		  i++;
		}


	return 0;
}
/*
 * Function Name: bzInsturctionHandler
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to update the surce and destinaltion registers for the BZ Insturction
 */

int instructionHandler::bzInsturctionHandler(int location)
{
/*
	string decodedInstruction,src1;
	decodedInstruction = mapInstruction.at(location).instruction;
	src1 = decodedInstruction.substr(3,decodedInstruction.length()-3-1);
	mapInstruction.at(location).src1 = src1;
	mapInstruction.at(location).src1Value=stoi(src1);
	mapInstruction.at(location).src2 = "R9";
	mapInstruction.at(location).src2Value=0;
	*/
		string decodedInstruction,src1,src2;
		int i=0;
		decodedInstruction = mapInstruction.at(location).instruction;
		if (decodedInstruction.find("\n")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\n"),1,"");
		if (decodedInstruction.find("\r")!=std::string::npos)
  	  decodedInstruction.replace(decodedInstruction.find("\r"),1,"");

		char temp[1024];//[decodedInstruction.length()+1];
	 	char * pch;
	 	strcpy(temp,decodedInstruction.c_str());
		pch = strtok (temp," ,");
		while (pch != NULL)
		{
			if(i==1)
			{
				//Source 1  Register details
				src1 =  string(pch); //decodedInstruction.substr(7,2);
				mapInstruction.at(location).src1 = src1;
				mapInstruction.at(location).src1Value=stoi(src1);
			}
			else if(i==2)
			{
				//Source 1  Register details
				src2 =  string(pch); // decodedInstruction.substr(10,2);
				mapInstruction.at(location).src2 = "R32";
				mapInstruction.at(location).src2Value=0;
			}
	
		  pch = strtok (NULL, " ,");
		  i++;
		}

	return 0;
}
/*
 * Function Name: bzInsturctionHandler
	Author: Aditya Manjrekar
	Date: 24th FEb 2016
	Description: Code to update the surce and destinaltion registers for the BZ Insturction
 */

int instructionHandler::haltInsturctionHandler(int location)
{
	string decodedInstruction,src1;
	decodedInstruction = mapInstruction.at(location).instruction;
	mapInstruction.at(location).dest="";
	mapInstruction.at(location).opcode="";
	mapInstruction.at(location).instruction = "";
	mapInstruction.at(location).src1 = "";
	mapInstruction.at(location).src2 = "";
	mapInstruction.at(location).literal ="";
	mapInstruction.at(location).src1Value=0;
	mapInstruction.at(location).src2Value=0;
	mapInstruction.at(location).destValue =0;
	mapInstruction.at(location).litValue =0;
	mapInstruction.at(location).done =0;

	return 0;
}

