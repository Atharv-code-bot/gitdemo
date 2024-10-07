#include<iostream>
#include<vector>
using namespace std;


struct Node { 
int data; 
vector<Node*> children; 
};


bool exists(int target,Node*root){

    if(!root->children.empty())
    { 
        for(int i=0;i<root->children.size();i++)
        {
            bool flag= exists(target,root->children[i]);
            if(flag==true)
            {
                return true;
            }
        }
    }
    else{ 
        return root->data==target;
    }

    return false;
}
