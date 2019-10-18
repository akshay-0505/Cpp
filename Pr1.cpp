#include<iostream>

using namespace std;

//Structure Defination
struct stud{
	int roll;
	char name[20];
}s[10],tmp;

//global variables 
int n;

//fuction definition

//Accept Data
void getData()
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<"Enter Roll no and Name"<<endl;
		cin>>s[i].roll>>s[i].name;
	}
}

//Print Data
void putData()
{
	int i;
	cout<<"Sorted list is:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"Roll no: "<<s[i].roll<<endl<<" Name: "<<s[i].name<<endl;
	}
}

//main function
int main()
{

	int i,j,k,f=0,searchRoll,lb=0,ub=n-1;
	cout<<"Enter No of Students";
	cin>>n;

	getData();
	
	//Sorting Logic
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(s[j].roll>s[j+1].roll)
			{
				tmp=s[j];
				s[j]=s[j+1];
				s[j+1]=tmp;
			}
		}
	}	

	//binary search logic
	i=0;
	cout<<"Enter Roll no to be searched";
	cin>>searchRoll;
	while((lb<ub)&&(f==0))
	{
		k=(lb+ub)/2;
		if(searchRoll==s[k].roll)
		{
			f=1;
			break;
		}
		else if(searchRoll<s[k].roll)
		{
			ub=k-1;
		}
		else
		{
			lb=k+1;
		}
	}
	
	//print Search Result
	if(f==1)
	{	
		cout<<"Record Found..."<<endl;
		cout<<"roll no: "<<s[k].roll<<" Name: "<<s[k].name<<endl; 
	}
	else
	{
		cout<<"No such record found..."<<endl;
	}
	

	putData();
	
	return 0;
}
