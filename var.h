#include <iostream>
#include <string>
using namespace std;
class Var
{
 char type;
 void* address;

 //releases the memory of the element
 void release_memory()
 {
 switch(type)
     {
         case 'i' :
         {
             int*p;
             p = (int*) address;
             delete p;
             break;
         }
         case 'd' :
        {
            double *g;
            g = (double *)address;
            delete g;
            break;
        }
        case 's' :
        {
            string *s;
            s = (string *) address;
            delete s;
            break;
        }
    
     }
 }
 void allocate_memory_with_value(int i_value)
 {
    type = 'i';
    address = new int;
    int *p;
    p = (int *)address;
    *p = i_value;
 }
 void allocate_memory_with_value(double d_value)
 {
             type = 'd';
             address = new double;
             double *p;
             p = (double *)address;
             *p = d_value;
 }
 void allocate_memory_with_value(string s_value)
 {
            type = 's';
            address = new string;
            string *s;
            s = (string *)address;
            *s = s_value;
 }
 void allocate_memory_with_value(const Var& obj)
 {
    switch(obj.type)
    {
        case 'i' :
        {
            int *p;
            p = (int*)(obj.address);
            allocate_memory_with_value(*p);
            break;
        }
        case 'd' :
        {
            double *d;
            d = (double *)(obj.address);
            allocate_memory_with_value(*d);
         break;
        }
        case 's' :
        {
            string *s;
            s = (string *)(obj.address);
            allocate_memory_with_value(*s);
            break;
        }
        default :
        {
            type= 'n';
            address = NULL;
        }
    }
 }
//get methods

 public:
 //constructor
 Var()
 {
    // cout<<"null instanciation "<<endl;
     type= 'n';
     address = NULL;
 }
 Var(const int &a)
 {
    // cout<<"instance creation in int "<<endl;
     release_memory();
     allocate_memory_with_value(a);
 }
 Var (const double &a)
 {  
     //cout<<"instance creation in double"<<endl;
     release_memory();
   allocate_memory_with_value(a);
 }
  Var(const char *a)
 {
    string g(a);
     release_memory();
    // cout<<"instance creation in string "<<endl;
     allocate_memory_with_value(g);
 }
 Var(const string &a)
 {
     release_memory();
    // cout<<"instance creation in string "<<endl;
     allocate_memory_with_value(a);
 }
 Var(const Var &a)
 {
     //cout<<"instance creation in var"<<endl;
     release_memory();
     allocate_memory_with_value(a);
 }

 ///assignement operator
void operator = (const char *a)
 {
    // cout<<"assignment opertaor"<<endl;
    string g(a);
    release_memory();
    allocate_memory_with_value(g);

 }


 void operator = (const string &a)
 {
    // cout<<"assignment opertaor"<<endl;
     release_memory();
      allocate_memory_with_value(a);

 }
  void operator = (const int &a)
 {
     //cout<<"assignment opertaor"<<endl;
     release_memory();
      allocate_memory_with_value(a);

 }
  void operator = (const double &a)
 {
    // cout<<"assignment opertaor"<<endl;
     release_memory();
      allocate_memory_with_value(a);

 }
 void operator = (const Var &a)
 {
    //  cout<<"assignment opertaor"<<endl;
     release_memory();
      allocate_memory_with_value(a);
 }

//destructor
~Var()
{
    release_memory();
}
//get type
char gettype()
{
    return type;
}

 //type convertion
string getstring()
{
    string S;
    switch(type)
    {
        case 'i':
        {
            int *p ;
            p = (int *)address;
            S =to_string(*p);
            break;
        }
        case 'd':
        {
            double *p;
            p = (double *)address;
            S = to_string(*p);
            //removing trailing zeros
             int  i = S.length();
            i -=1;
            while(i!=0 && S[i] == '0'){S.pop_back();
            i--;}
       
            break;
        }
        case 's':
        {
            string *p;
            p = (string *)address;
            S = *p;
            break;
        }
        default :
         S = "";

    }
    return S;
}
double getdouble()
{
    double D;
    switch(type)
    {
        case 'i':
        {
            int *p;
            p = (int* )address;
            return *p;
        }
        case 'd':
        {
            double *d;
            d = (double *)address;
            return *d;
        }
        case 's':
        {
            try{
            string *s;
            s = (string *)address;
            double d = stod(*s);
            return d;
            }
            catch(...)
            {
                cout<<"\n }} invalid type convertion : string to double error {{"<<endl;
                throw "string_to_double_err";
            }
        }
        default:
        return 0.0;
    }
    return 0;
}
int getint()
{
    switch(type)
    {
        case 'i':
        {
            int *p;
            p = (int* )address;
            return *p;
        }
        case 'd':
        {
            double *d;
            d = (double *)address;
            return *d;
        }
        case 's':
        {
            try{
            string *s;
            s = (string *)address;
            double d = stod(*s);
           
            return d;


            }
            catch(...)
            {
                cout<<"\n }} invalid type convertion : string to integer convertion {{"<<endl;
                throw "string_to_int_err";
            }
        }
        default:
        return 0;
    }
    return 0;
}

//arithmetic operations
Var operator+ ( Var B)
{
    Var c;
   if(type == 's'|| B.type == 's')
   {
       string a = this->getstring();
       string b = B.getstring();
       c = a.append(b);
   }
   else if(type == 'd'|| B.type == 'd')
   {
       double a = this->getdouble();
       double b = B.getdouble();
       c = a+b;
   }
   else if(type == 'i' ||B.type == 'i')
   {
       int a = this->getint();
       int b = B.getint();
       c = a+b;
   }
    return c;
}
Var operator-(Var B)
{
    Var c;
    if(type == 's'||B.type == 's')
    {
        cout<<"\n }} invalid operation : subtraction on string {{"<<endl;
        throw "invalid operation :: subtracting string";
    }
    else if (type == 'd'|| B.type == 'd')
    {
        double a = this->getdouble();
        double b = B.getdouble();
        c = a-b;
    }
    else if(type == 'i' || B.type == 'i')
    {
        int a = this->getint();
        int b = B.getint();
        c = a-b;
    }
    return c;
}
Var operator*(Var B)
{
    Var c;
    if(type == 's'||B.type == 's')
    {
        cout<<"\n }} invalid operation : multiplication on string  {{"<<endl;
        throw "invalid operation :: subtracting string";
    }
    else if (type == 'd'|| B.type == 'd')
    {
        double a = this->getdouble();
        double b = B.getdouble();
        c = a*b;
    }
    else if(type == 'i' || B.type == 'i')
    {
        int a = this->getint();
        int b = B.getint();
        c = a*b;
    }
    return c;

}
Var operator/(Var B)
{
     Var c;
    if(type == 's'||B.type == 's')
    {
        cout<<"\n }} invalid operation : division on  string {{"<<endl;
        throw "invalid operation : division string";
    }
    else if (type == 'd'|| B.type == 'd')
    {
        double a = this->getdouble();
        double b = B.getdouble();
        c = a/b;
    }
    else if(type == 'i' || B.type == 'i')
    {
        int a = this->getint();
        int b = B.getint();
        c = a/b;
    }
    return c;
}
//string operations

char& operator[](int i)
{
    if(type == 's')
    {
        string *p;
        p = (string *)address;
        string &a = *p;
        return a[i];
     
    }
    cout<<"\n }} invalid operator : [] operator used in int/double  {{"<<endl;
    throw "invalid operator : [] operator used in int/double ";

}
void push_back(char g)
{
   
    if(type == 's')
    {
        string &a = *(string *)address;
        a.push_back(g);
        return;
    }
    cout<<"\n }} push_back() : not defined for double /int  {{"<<endl;
    throw " push_back() : not defined for double /int  ";
}
void append(string s)
{
    if(type == 's')
    {
        string &a = *(string *)address;
        a.append(s);
        return;
    }
    cout<<"\n }} append() : not defined for double /int  {{"<<endl;
    throw " append() : not defined for double /int  ";
}
void  pop_back()
{
      if(type == 's')
    {
        string &a = *(string *)address;
        a.pop_back();
        return;
    }
    cout<<"\n }} pop_back() : not defined for double /int  {{"<<endl;
    throw " pop_back() : not defined for double /int  ";
}
string::iterator begin()
{
 
    if(type == 's')
    {
        string &a = *(string *)address;
       
        return a.begin();
    }
    cout<<"\n }} begin() : not defined for double /int  {{"<<endl;
    throw " begin() : not defined for double /int  ";   
}
string::iterator end()
{
    if(type == 's')
    {
        string &a = *(string *)address;
       
        return a.end();
    }
    cout<<"\n }} end() : not defined for double /int  {{"<<endl;
    throw " end() : not defined for double /int  "; 
}
int size()
{
    if(type == 's')
    {
        string &a = *(string *)address;
       
        return a.size();
    }
    cout<<"\n }} size() : not defined for double /int  {{"<<endl;
    throw " size() : not defined for double /int  "; 
}
int length()
{
      if(type == 's')
    {
        string &a = *(string *)address;
       
        return a.length();
    }
    cout<<"\n }} length() : not defined for double /int  {{"<<endl;
    throw " length() : not defined for double /int  "; 
}
 //overloading io operations
 friend ostream &operator<<(ostream& output,const Var &a)
 {
     void * f = a.address;
     char ty = a.type;
     switch(ty)
     {
         case 'i':
         {
             int* ptr;
             ptr = (int*) f;
             output<<(*ptr);
            break;
         }
         case 'd':
         {
             double* ptr;
             ptr = (double *)f;
             output<<(*ptr);
             break;
         }
         case 's':
         {
             string* ptr;
             ptr = (string *)f;
             output<<(*ptr);
             break;
         }
         default:
          output<<"NULL";
     }
     
     return output;
 }
 //getting value;
friend  istream & operator >> (istream & in, Var & a)
 {
     string s1;
     //istringstream inp(s1);
     in>>s1;
     int i = 0;
     int n = s1.size();
     int isalpha = 0;
     int isdecimal = 0;
    int count = 0;
     while(i<n)
     {
         if(s1[i]>='0' && s1[i] <='9' )count++;
         if(s1[i] == '.')isdecimal = 1;
         i++;
     }
     a.release_memory();
     if(count == n)
     {
         //interger type
         int v = stoi(s1);
         a.allocate_memory_with_value(v);
     }
     else if(isdecimal ==1 && count == n-1){
         //double type 
         double f = stod(s1);
         a.allocate_memory_with_value(f);
     }
     else a.allocate_memory_with_value(s1);

     return in;
     
 }
};
/*
int main()
{
    Var a,c;
    int b;
    cin>>a;
    cout<<" enter the index "<<endl;cin>> b;
    cout<<a[b]<<endl;
}
*/
///array testing
/*
int main()
{
    Var a[10];
    for(int i = 0;i<3; i++)
    {
        cin>>a[i];
    }
    Var g;
    g = " hello world";
    cout<<" output  : "<< g << endl;
    g.push_back('c');
    cout<<" output  : "<< g << endl;
    g.append("hell is");
    cout<<" output  : "<< g << endl;
    g.pop_back();
    cout<<" output  : "<< g << endl;
    cout<<" length of the string is : "<< g.size() <<endl;
    cout<<" length of the string is : "<< g.length() <<endl;
    int count = 0;
    for(auto it = g.begin() ; it< g.end(); it++)
    {
        cout<<(*it) <<" ";
        count++;
    }
    cout<<" the count is : "<<count<<endl;
    cout<<" the output is "<<endl;
    for(int i = 0;i<3; i++)
    {
        cout<<a[i] <<" ";
    }
    cout<<endl;
    return 0;
}

*/
/*
int main()
{
  Var a,b,c;
  a = 100.89;
  b = 200;
  a = a.getint();
  c = a+b;
 cout<<c<<endl;
  c = a-b;

  cout<<c<<endl;
 c = a*b;
 cout<<c<<endl;
 c = a/b;
 cout<<c<<endl;

c = b+a;
 cout<<c<<endl;
  c = b-a;

  cout<<c<<endl;
 c = b*a;
 cout<<c<<endl;
 c = b/a;
 cout<<c<<endl;

   // cout<<f+"hello"<<endl;
   
return 0;
}

*/

