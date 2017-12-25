#include <iostream>
using namespace std;
bool visited[40];
char answer[40];
bool backtrack(char name[],int n,int c)
{
	if(n==0)
	{
		for(int i=0;i<=strlen(name);i++)
		{
			cout<<answer[i];
		}
		cout<<endl;
		return true;
	}
	for(int i=0;i<strlen(name);i++)
	{
		if(visited[i]==false)
		{
			visited[i]=true;
			answer[c]=name[i];
			backtrack(name,n-1,c+1);
			visited[i]=false;
			answer[c]=' ';

		}
	}
	return false;
}

int main() {
    char name[20]="AABC";
    //cout<<strlen(name);
    //ABC
	for(int i=1;i<=strlen(name);i++)
		visited[i]=false;
	backtrack(name,strlen(name),1);
   return 0;
}
