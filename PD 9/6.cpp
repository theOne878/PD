#include <iostream>
using namespace std;

int main(){
	string line;
	int space = ' ';
	cout << "Enter a string: ";
	getline(cin, line);
	cout << "Reversed string: ";
	
	for(int i=line.length()-1;i>=0;i--)
	{
		if(i==0)
		{
			for(int j=i; j<line.length()+1; j++)
			{
				cout << line[j];
				if(line[j]==' '){
					break;
				}
			}
		}
		if(line[i]==' '){
			for(int j=i+1; j<line.length()+1; j++)
			{
				cout << line[j];
				if(line[j]==' '){
					break;
				}
			}
		}
	}
}
