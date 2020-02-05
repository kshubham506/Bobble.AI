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

    void serialize(Node *root, fstream &OSS) 
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
    
    Node * deSerialize(fstream &ISS) 
    { 
        string nodeHolder; 
        ISS >> nodeHolder; 
        if (!nodeHolder.compare("#")) 
            return nullptr; 
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
    
        if(strcmp(argv[1],"create")==0)  {
            string csvFile=argv[2];
            string outputFile=argv[3];
            // string csvFile="file2.csv";
            // string outputFile="abc.dat";

            cout<<"\nReading CSV File :"<<csvFile<<" and serializing in :"<<outputFile;

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

            //for serializing the tree into file
            fstream file1;
            file1.open(outputFile, ios::out);
            serialize(root, file1); 
            file1.close();

        
            cout<<"\nSerialized in "<<outputFile<<"\n";

        }
        else if( strcmp(argv[1],"load")==0){
        
            
            string readFile=argv[2];
            // string readFile="abc.txt";

            fstream file2;
            file2.open(readFile,ios::in);
            Node *root1=deSerialize(file2);

            cout<<"\nContents of the File \n"; 
            printLevelOrder(root1); 
        
        }
        else{
            cout<<"\nInvalid Command Line Inputs , Check Again";
        }
    
        return 0; 
    } 