#include<bits/stdc++.h>
#include<string.h>
#include "a.cpp"

using namespace std; 

//template for generic type
template<typename K, typename V> 
  
//Hashnode class 
class HashNode 
{ 
    public: 
    V value; 
    K key; 
      
    //Constructor of hashnode  
    HashNode(K key, V value) 
    { 
        this->value = value; 
        this->key = key; 
    } 
}; 

template<typename K, typename V> 


//Our own Hashmap class 
class HashMap 
{ 
    public: 
    //hash element array 
    HashNode<K,V> **arr; 
    int capacity; 
    //current size 
    int size; 
    //dummy node 
    HashNode<K,V> *dummy; 
  
    public: 
    HashMap() 
    { 
        //Initial capacity of hash array 
        capacity = 10; 
        size=0; 
        arr = new HashNode<K,V>*[capacity]; 
          
        //Initialise all elements of array as NULL 
        for(int i=0 ; i < capacity ; i++) 
            arr[i] = NULL; 
          
        //dummy node with value and key -1 
        dummy = new HashNode<K,V>(-1, "-1"); 
    } 
    // This implements hash function to find index 
    // for a key 
    int hashCode(K key) 
    { 
        return key % capacity; 
    } 
      
    //Function to add key value pair 
    void insertNode(K key, V value) 
    { 
        HashNode<K,V> *temp = new HashNode<K,V>(key, value); 
          
        // Apply hash function to find index for given key 
        int hashIndex = hashCode(key); 
          
        //find next free space  
        while(arr[hashIndex] != NULL && arr[hashIndex]->key != key 
               && arr[hashIndex]->key != -1) 
        { 
            hashIndex++; 
            hashIndex %= capacity; 
        } 
          
        //if new node to be inserted increase the current size 
        if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1) 
            size++; 
        arr[hashIndex] = temp; 
    } 
      
    //Function to delete a key value pair 
    V deleteNode(int key) 
    { 
        // Apply hash function to find index for given key 
        int hashIndex = hashCode(key); 
          
        //finding the node with given key 
        while(arr[hashIndex] != NULL) 
        { 
            //if node found 
            if(arr[hashIndex]->key == key) 
            { 
                HashNode<K,V> *temp = arr[hashIndex]; 
                  
                //Insert dummy node here for further use 
                arr[hashIndex] = dummy; 
                  
                // Reduce size 
                size--; 
                return temp->value; 
            } 
            hashIndex++; 
            hashIndex %= capacity; 
  
        } 
          
        //If not found return null 
        return NULL; 
    } 
      
    //Function to search the value for a given key 
    V get(int key) 
    { 
    	
        // Apply hash function to find index for given key 
        int hashIndex = hashCode(key); 
        int counter=0; 
        //finding the node with given key    
        while(arr[hashIndex] != NULL) 
        {     
             if(counter++>capacity)  //to avoid infinite loop 
                return "";         
            //if node found return its value 
            if(arr[hashIndex]->key == key) 
                return arr[hashIndex]->value; 
            hashIndex++; 
            hashIndex %= capacity; 
        } 
          
       return "";
    } 
      
    //Return current size  
    int sizeofMap() 
    { 
        return size; 
    } 
      
    //Return true if size is 0 
    bool isEmpty() 
    { 
        return size == 0; 
    } 
    
      //Function to display the stored key value pairs 
    //void display(fstream& f1, int key) 
    void display(ofstream& f, int key) 
    { 
         for(int i=0;i<=capacity;i++)
         {
            if(arr[i] != NULL && arr[i]->key != -1) 
                f<< "key = " << arr[i]->key  
                     <<"  value = "<< arr[i]->value << endl; 
        }
    }
      
  
}; 

HashMap<int, string> *h = new HashMap<int, string>;

//basket class used to record details of each business

class basket
{

   public:
   string itemname;
   int itemid, needwant;
   
   
};

char bname[20]; int num,sales,nt,pm;

//insertfile function is used to take details of the products in the inventory
 void insertfile(string uname, int n)
 {
 
     //file object
     ofstream f1; string ifilename, insert="insert.txt";
     ifilename=uname+insert;
     f1.open(ifilename,ios::app);
  
     //if file doesn't exist
     if(!f1)
       exit(1);
     
     if(n==1)
       goto label1;
     
     
     //input for the variables declared above
     cout<<"Enter the name of the business:";
     cin.ignore();
     cin.getline(bname,20);
     cout<<"Enter the sales:";
     cin>>sales;
     goto label1;
     
 label1:
     cout<<"no of prods:";
     cin>>num;
 
     
   
     //class object
     basket b[num];
  
     //taking input of inventory
     for(int i=0;i<num;i++)
     {
       cout<<"Enter the itemid:\n";
       cin>>b[i].itemid;
       cout<<"Enter the itemname:\n";
       cin.ignore();
       getline(cin,b[i].itemname);
       cout<<"Enter whether the item is a need or a want:(0/1)\n";
       cin>>b[i].needwant;
   
   
       //creatin string objects to pass the fields as a value to the hashmap
       string s1, s2;
   
       s1 = b[i].itemname;
       s2 = to_string(b[i].needwant);
  
      s1 = s1+","+s2;
   
      //inserting key value pair into the hashmap 
      h->insertNode(b[i].itemid, s1);
  
   }
      //writing the product details to the file 
      h->display(f1, b[0].itemid);
  
    
    f1.close();
    
   
}

void modifyfile(string username)
{

    cout<<"\n1. Insert new products\n";
    cout<<"\n2. Delete a product entry\n";
    int c;
    cout<<"\nEnter your choice:";
    cin>>c;
   
 
    switch(c)
    { 
      case 1: insertfile(username,1);
              break;
     
               
      case 2:  int c; 
               string deletedvalue;
               cout<<"\nEnter the item id whose entry you would like to delete:";
               cin>>c;
               deletedvalue = h->deleteNode(c);
               break;
     }
      
    
    
}
    
    

void callapriori()
{
    if(remove("output2.txt")==0)
     cout<<"Deleted intoutput successfully\n";
    else
     cout<<"Couldn't delete intoutput\n";
  
  
    if(remove("op2.txt")==0)
     cout<<"Deleted foutput successfully\n";
    else
     cout<<"Couldn't delete foutput\n";
  
    string minSupport;
    cout<<"Enter min support value:";
    cin>>minSupport;
   
    string inputFileName;
    cout<<"Enter the transaction file name:";
    cin>>inputFileName;
    
    string outputFileName = "output2.txt";
    
    InputReader inputReader(inputFileName);
   
    vector<vector<int> > transactions = inputReader.getTransactions();
    
    Apriori apriori(transactions, stold(minSupport));
   
    apriori.process();
    
    OutputPrinter outputPrinter(outputFileName, apriori.getAssociationRules());
    
   
}


    
    
void formatoutput(int c, string uname)
{

    string foutput;
    string display="final.txt";
    foutput=uname+display;
    
    if(c==3)
    {
     goto label2;
     label2:
     string l; fstream f3;
     f3.open(foutput);
     if (f3.is_open())
     {   //checking whether the file is open
        
         while(getline(f3, l))
         { 
           //read data from file object and put it into string.
           cout << l << "\n"; //print the data of the string
           
         }
         f3.close(); //close the file object.
     }
    }
    else
    {
       
       ofstream fin; ifstream finalread; 
       fin.open("final.txt");
  
       cout<<setiosflags(ios::left);
    
       fin <<"\n\t\t\t\t\t--------------------------------------------------------------------------------\t\n";
       fin <<"\t\t\t\t\t\t\t\t\tSALES ANALYSIS MASTER\n";
       fin <<"\n\t\t\t\t\t--------------------------------------------------------------------------------\t\n";
     
       fin <<"\nYour account details:\n";
       fin <<"\nNAME OF THE BUSINESS:"<<bname<<"\n";
       fin <<"\nTOTAL SALES IN THE TRANSACTION PERIOD MENTIONED:"<<sales<<"\n";
       fin <<"\nNUMBER OF ITEMS IN YOUR INVENTORY:"<<num<<"\n";

     
       fin <<"\nFrequently bought together items for your transaction data is given below";
       fin <<"\nThe data is represented in the form on association rules X -> Y: where X and Y are itemsets containing items from your inventory."
       <<"X represents the itemset and Y represented the associative itemset.\n";
       fin <<"\n\n"<<setw(20)<<"ITEMSET"<<"\t\t\t\t\t"<<setw(20)<<"ASSOCIATIVE ITEMSET\n";    
    
    
       FILE* ff;
       char c;
       vector <string> tokens;
    
       ff= fopen("op2.txt", "r");
    
       for (c = getc(ff); c != EOF; c = getc(ff)) 
       {    
         if(c!='\n')
         {
           if(isdigit(c))
           {
              string s, iname ="";
              int key = (int) (c)-48;
              s=h->get(key);
              for(int i=0;s[i]!=',';i++)
              {
                iname+=s[i];
              }
              
              fin<<setw(20)<<iname<<"\t\t\t\t\t"<<setw(20);
           }
        }
        else
          fin<<endl;
      }
     
      fin <<"\n\nThis inference will aid in understanding the trend in your transactions. Three fundamental applications of this inference are:\n";
      fin <<"\n1. Clearing your inventory by selling the frequently bought items together using various strategies such as combo packs and combined discount.\n";
      fin <<"\n2. Exposing your consumers to a wide array of your products thereby attracting them to a larger range of options to choose from and enhancing"
      <<"the user experience.\n";
      fin <<"\n3. Burgeoning your consumer network in the long run.\n";
      fin<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------\n";
       
      fclose(ff);
      goto label2;
      
     
    
     
 }
}

char username[10];

int main()
{
 
  int ch;  
  cout<<"\nWELCOME TO SALES ANALYSIS MASTER\n";
  cout<<"\nEnter username:\n";
  //cin.ignore();
  cin.getline(username,20);
      
    
  menu:
      while(true)
      {
          cout<<"\n1. Create Inventory\n";
          cout<<"\n2. Modify Inventory\n";
          cout<<"\n3. View Recent Inference\n";
          cout<<"\n4. Draw New Inference\n";
          cout<<"\nEnter your choice:\n";
          cin>>ch;
      
         switch(ch)
         {
            case 1:  insertfile(username,0);
                     break;
            case 2:  modifyfile(username);
                     break;
            case 3:  formatoutput(3,username);
                     break;
            case 4:  callapriori();
                     formatoutput(4,username);
                     break;
         }
     }
     return 0;
}
