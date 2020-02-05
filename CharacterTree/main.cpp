#include<bits/stdc++.h>
using namespace std;

#define MARKER " "

struct Node 
{ 
    string  data; 
    struct Node* left, *right; 
     Node(string val) {
        this->data =val;
    }
}; 

Node* newNode(string val) 
{ 
    Node* temp = new Node(val); 
    // temp->data = val; 
    temp->left = temp->right = NULL; 
    return (temp); 
} 

void addNode(Node *root,string val){
    if(root==NULL){
        root=newNode(val);
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *v=q.front();
        q.pop();
        if(v->left!=NULL){
            q.push(v->left);
        }
        else{
            v->left=newNode(val);
            return;
        }
        if(v->right!=NULL){
            q.push(v->right);
        }
        else{
            v->right=newNode(val);
            return;
        }
    }
}

void serialize(Node *root, ostringstream& OSS) 
{ 
     if (!root) {
        OSS << '#' << MARKER; 
        return;
    }
    
    OSS << root->data << MARKER;
    serialize(root->left, OSS);
    serialize(root->right, OSS);
    return;
} 
  
Node * deSerialize(istringstream& ISS) 
{ 
    string nodeHolder; // Holds either # or a number, in string form
    ISS >> nodeHolder; // Take first string (that isn't ourToken) from stream
    // and put it into nodeHolder;
    if (!nodeHolder.compare("#")) return nullptr; // If nodeHolder is "#" then a node doesn't exist there
    Node* newnode = new Node(nodeHolder);
    newnode->left = deSerialize(ISS);
    newnode->right = deSerialize(ISS);
    return newnode;
} 

void printLevelOrder(Node *root) 
{ 
    if (root == NULL)  return; 
  
    queue<Node *> q; 

    q.push(root); 
  
    while (q.empty() == false) 
    { 
        Node *node = q.front(); 
        cout << node->data <<endl; 
        q.pop(); 
  
      
        if (node->left != NULL) 
            q.push(node->left); 
  
        if (node->right != NULL) 
            q.push(node->right); 
    } 
} 
  
int main(int argc, char **argv) 
{ 
   
    if(1 || strcmp(argv[1],"create")==0){
        
        // string csvFile=argv[2];
        // string outputFile=argv[3];
        string csvFile="file2.csv";
        string outputFile="abc.txt";

        cout<<"Reading CSv File :"<<csvFile<<" and serializing in :"<<outputFile;

        Node *root=NULL;

        //reading the csv file and creating  avector of strings
        vector<string> vec;
        fstream file;
        file.open(csvFile);
        string line;
        while (getline( file, line,'\n'))  {
            istringstream templine(line); 
            string data;
            while (getline( templine, data,',')) {
                vec.push_back(data.c_str());  
            }
        }
        file.close();

        //itearting the vector of strigns to craete a tree 
        for(auto s:vec){
            if(root==NULL){
                root=newNode(s);
            }
            else{
                addNode(root,s);
            }
        }


        ostringstream  f("abc.txt",ios::out);
        serialize(root, f); 

        cout<<"\nContents of the File \n"; 
        printLevelOrder(root);

      
        cout<<"\nSerialized in "<<outputFile<<"\n";

    }
    else if(strcmp(argv[1],"load")==0){
    
        string readFile=argv[2];

        istringstream inpf(readFile,ios::binary|ios::in);
        Node *root1=deSerialize(inpf);

        cout<<"\nContents of the File \n"; 
        printLevelOrder(root1); 
    
    }
  
    return 0; 
} 