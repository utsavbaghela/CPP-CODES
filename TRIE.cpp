
#include <iostream>
#include <string>
#include <stdbool.h>
using namespace std;
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define index_to_char(c) ((char)(97+c))


struct trienode
{
	struct trienode* children[ALPHABET_SIZE];
	bool isleaf;
};
struct trienode* getnode()
{
	trienode *pnode=new trienode;
	if (pnode!=NULL)
	    {
	        int i;
	        pnode->isleaf = false;

	        for (i = 0; i < ALPHABET_SIZE; i++)
	            pnode->children[i] = NULL;
	    }
	return pnode;
}
void insert(trienode* root,char *key)
{
	    int level;
	    int length = strlen(key);
	    int index;
	    trienode* pointer=root;

	    for(int level=0;level<length;level++)
	    {
	    	index = CHAR_TO_INDEX(key[level]);
	    	//index=u
	    	if(pointer->children[index]==NULL)
	    		pointer->children[index]=getnode();

	    	pointer=pointer->children[index];
	    }
	    pointer->isleaf=true;
}

bool search(trienode *root, char *key)
	{
	    int level;
	    int length = strlen(key);
	    int index;
	    trienode *pointer = root;

	    for (level = 0; level < length; level++)
	    {
	        index = CHAR_TO_INDEX(key[level]);
	        if(pointer->children[index]==NULL)
	        	return false;
	        pointer=pointer->children[index];
	        cout<<index_to_char(index)<<" ";
	    }
	    return (pointer != NULL && pointer->isleaf);


}

int main()
{
	 char keys[][8] = {"utsav","utvas", "jolly", "shruti", "umang",
	                   };
	struct trienode *root=getnode();
	 int i;
	    for (i = 0; i < ARRAY_SIZE(keys); i++)
	        insert(root, keys[i]);

	    if(search(root, "jolly"))
	    	cout<<"YES PRESENT IN TRAI"<<" \n";
	    else
	    	cout<<"NOT PRESENT IN TRAI"<<" \n";
	return 0;
}
