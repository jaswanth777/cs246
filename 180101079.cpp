#include<bits/stdc++.h>
using namespace std;

class course{
             public:
		string name;
                string number;
};
class student{
              public:
		string name;
                string rollno;
		vector<string> courses;
		vector<int> coursepref;
                vector<string> grades;
};
//quick msort for integers
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; 
    int i = (low - 1); 
  
    for (int j = low; j <= high- 1; j++) 
    { 

        if (arr[j] <= pivot) 
        { 
            i++;   
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 

        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

//quick sort for strings
void swap(char *a, char *b) 
	{ 
	 const char *s1=a;
         const char *s2=b;
	 strcpy(a,s2);
	 strcpy(b,s1);
	 }

int partition (vector<string>arr,vector<int>p, int low, int high) 
{ 
    string pivot = arr[high]; 
    int i = (low - 1); 
  
    for (int j = low; j <= high- 1; j++) 
    { 

        if (arr[j] <= pivot) 
        { 
            i++;   
            swap(arr[i], arr[j]); 
            swap(&p[i], &p[j]);
        } 
    } 
    swap(arr[i + 1], arr[high]);
    swap(&p[i + 1], &p[high]);  
    return (i + 1); 
} 
  

void quickSort(vector<string>arr, vector<int>p,int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr,p, low, high); 

        quickSort(arr,p, low, pi - 1); 
        quickSort(arr,p, pi + 1, high); 
    } 
} 

int partition (vector<string>arr, int low, int high) 
{ 
    string pivot = arr[high]; 
    int i = (low - 1); 
  
    for (int j = low; j <= high- 1; j++) 
    { 

        if (arr[j] <= pivot) 
        { 
            i++;   
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]);  
    return (i + 1); 
} 

void quickSort(vector<string>arr,int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 

        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    }
} 


int main()
        {
         fstream f1;
         fstream f2;
         fstream f3;
	 fstream fout;
         f1.open("students01.csv", ios::in);
         vector<student>sd;
	 vector<string>sdname;
	 vector<int>sdindex;
	 vector<string>row;
         student a; 
	 string line, word;
	 while (!f1.eof())
              { 
		row.clear();
		getline(f1, line);
		stringstream s(line);
		while (getline(s, word, ','))
                     {
			row.push_back(word); 
		      }
		a.rollno =row[1];
                a.name = row[0];
                sd.push_back(a);
              }
	for(int i=0;i<sd.size();i++)
		{
		 sdindex[i]=i;
                 sdname[i]=sd[i].name;
		 }
	quickSort(sdname,sdindex,1,sd.size()-1);
	f2.open("grades01.csv", ios::in);
	 while (!f2.eof())
              { 
		row.clear();
		getline(f2, line);
		stringstream s(line);
		while (getline(s, word, ','))
                     {
			row.push_back(word); 
		      }
		for(int i=0;i<sd.size();i++)
		    {
		     if(sd[i].rollno == row[0])
                       {
                        sd[i].courses.push_back(row[1]);
                        sd[i].grades.push_back(row[2]);
                        break;
                        }
		     }
              }
	for(int i=0;i<sd.size();i++)
	   {
            for(int j=0;j<sd[i].courses.size();j++)
                sd[i].coursepref[j]=j;
            quickSort(sd[i].courses,sd[i].coursepref,1,sd[i].courses.size()-1);
           }
	vector<course>cs;
        course c;
	f3.open("courses01.csv", ios::in);
	while (!f3.eof())
              { 
		row.clear();
		getline(f3, line);
		stringstream s(line);
		while (getline(s, word, ','))
                     {
			row.push_back(word); 
		      }
                c.number = row[1];
		c.name = row[2];
                cs.push_back(c);
	       }
	fout.open("grades_sorted_Q.csv",  ios::out | ios::app);
        for(int i=0;i<sdname.size();i++)
           {
            for(int j=0;j<sd[sdindex[i]].courses.size();j++)
	       {
                fout<<sdname[i]<<","<<sd[sdindex[i]].courses[j]<<","<<sd[sdindex[i]].grades[sd[sdindex[i]].coursepref[j]]<<"\n";
                }
           }
	return 0;
}

