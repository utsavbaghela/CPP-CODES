
#include <iostream>
#include <string.h>
using namespace std;
int compare(const void *a, const void * b)
{
    return ( *(char *)a - *(char *)b );
}
void permuteutil(int count[],char string[],char result[],int level,int n)
{
	for(int i=n;i<strlen(string);i++)
	{
		if(count[i]==0)
			continue;
		else
		{
			result[level]=string[i];
			for(int j=0;j<=level;j++)
				cout<<result[j];
			cout<<endl;
			count[i]--;
			permuteutil(count,string,result,level+1,i);
			count[i]++;

		}
	}
}
void permute(char str[],int size)
{

	qsort(str, size, sizeof( str[0] ), compare);
	    cout<<"FOR STRING "<<str<< " POWER SET POSSIBLE ARE : \n";

	    int count[size];
	    for(int i=0;i<size;i++)
	    	    {count[i]=1;}
	    char *string=new char(size);

	    int z=0,x=0,newsize=0;
	    for(int i=0;i<size;i++)
	    {
	    		if(str[i]==str[i+1])
	    			{
	    				string[z]=str[i];
	    				count[x]++;
	    				continue;
	    			}
	    		else

	    			{
	    			string[z]=str[i];
	    			z++;
	    			x++;
	    			newsize++;
	    			}

	    }
	    delete string;

	    char result[]="zzzz";

	    //cout<<result;
	    int newcount[newsize];
	    for(int i=0;i<newsize;i++)
	    	    {
	         newcount[i]=count[i];
	    	    }


	   permuteutil(newcount,string,result,0,0);

}


int main()
{
    char str[] = "aabc";
    int size = strlen(str);
    cout<<size<<"\n";
    //cout<<strlen(result);
    permute(str,size);
    return 0;
}
