//Josh Manning U57872687
#include <fstream>
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int int main(int argc, char const *argv[])
{
	/* code */
	//do all the vec stuff in another function??
	std::vector<Point> vec;
	Point temp;
	ifstream file("points.txt");

	if (!file.is_open())
		cout << "cannot open file" << endl;

	else
	{
		while(file>>temp.x_coord>>temp.y_coord)//will this work
		{
			vec.push_back(temp);
		}
	}
	//test if the above properly put into vector
	for (int i=0; i<vec.size();v++)
		cout << vec[i] << endl;
	return 0;
}

class Point ()
{
	float x_coord;
	float y_coord;
}

//check if colinear
//what type of function??
bool colinear()

