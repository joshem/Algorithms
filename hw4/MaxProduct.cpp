//Josh Manning U57872687
#include "MaxProduct.h"


using namespace std;

long MaxProductClass::MaxProduct(string filename){
	ifstream myFile;
	string myString;
	stringstream numbers;
	vector<int> myVec;
	vector<int> myMax;
	int temp;
	int MaxTemp=0;
	myFile.open(filename.c_str());
	while(getline(myFile,myString))
	{
		//this accounts for spaces, differentiates different numbers
		numbers.clear();
		numbers.str("");
		numbers<<myString;
		MaxTemp=0; //reinitialize max for next loop
		//put numbers into vector
		while(numbers>>temp)
		{
			if (temp!= -999999)//don't put this into vector, it is the line terminator
				myVec.push_back(temp);//put number into vector
		}
		//checking for max numbers
		if(myVec.size()==1) MaxTemp=myVec[0]; 	//if there is 1 num on line
		
		//if there is two nums on line:
		else if (myVec.size()==2) {
			MaxTemp= myVec[0];
			int multiply = myVec[0]*myVec[1];
			int second_element = myVec[1];
			if(MaxTemp<multiply) MaxTemp=multiply;
			if(MaxTemp<second_element) MaxTemp=second_element;
		}

		//now for lines with more than three
		//NOTE:need to use previous logic for some
		//Q:does it matter if i sort vector??
		//A: YES, it will mess up the sequence provided!!!!
		//CONCLUSION: put vec into new vector, sort the newVec
		else if (myVec.size()>=3)
		{
			//this finds the largest single value in vector
			//max_element didn't work...			
			vector<int> sorted = myVec;
			std::sort (sorted.begin(),sorted.end());
			int largestValue = sorted.back();
			
			//values used in for loop
			int multiplyTwo=0;
			int multiplyTwo_Temp;
			int multiplyThree=0;
			int multiplyThree_Temp;
			//iterate through loop
			for (int i=0;i<myVec.size()-1;i++)
			{
				//finds largest of two multiplied together
				multiplyTwo_Temp=myVec[i]*myVec[i+1];
				if(multiplyTwo_Temp>multiplyTwo) multiplyTwo=multiplyTwo_Temp;
				
				//finds largest of three multiplied together
				multiplyThree_Temp=myVec[i-1]*myVec[i]*myVec[i+1];//something's wrong here
				if (multiplyThree_Temp>multiplyThree) multiplyThree=multiplyThree_Temp;
			}
			
			//now find largest value of line!
			//first: push maxes into vector
			vector<int> maxLine;
			maxLine.push_back(largestValue);
			maxLine.push_back(multiplyTwo);
			maxLine.push_back(multiplyThree);
			std::sort (maxLine.begin(),maxLine.end()); //now sort this vector
			MaxTemp = maxLine.back();//put largest value into MaxTemp
			/*cout << "Maxline elements below: " << endl;
			for (int i=0;i<maxLine.size();i++)
				cout << maxLine[i] << endl;*/
			
			

			
			
		}
		
		myMax.push_back(MaxTemp);//puts max of line into max vector
		myVec.clear();//clears vector for next line
		
	}
	//cout << "end of maxline!" << endl;
	for (int i=0;i<myMax.size();i++)
	{
		cout << myMax[i] << endl;
	}
	//find the largest max
	vector<int> sortedMax = myMax;
	std::sort (sortedMax.begin(),sortedMax.end());
	int largestMax = sortedMax.back();
	//cout << largestMax << endl; 

	return largestMax;
}


