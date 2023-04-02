#include <iostream>
#include <map>
using namespace std;

struct node {
    char s;
    struct node* next=NULL;
};

class stack1
{
    struct node * top=NULL;
    public:
    void push(char c)
    {
        struct node * temp  = new node;
        if(top==NULL)
            {
                top = temp;
                top->s = c;
            }
        else{
                temp->next = top;
                top = temp;
                top->s = c;
            }
        return;
    }

    char pop()
    {
        if(top==NULL)
            {
                cout<<"underflow"<<endl;
                return '0';
            }
        else
            {
                struct node * temp = top ;
                char c  = temp->s;
                top = top->next;
                free(temp);
                return c;
            }
    }
    char top_elem()
    {
        if(top!=NULL)
            return top->s;
        else
            {
                return 'e';

            }
    }
    bool is_empty()
    {
        if(top==NULL)
        {
            return true;
        }
        return false;
    }
};

float evaluate(int a, char c, int  b)
{
    if(c=='+' || c=='-')
        return (a+b);
    else if(c=='*')
        return a*b;
    else
        return a/b;
}

string infix_to_postfix(string s)
{
     stack1 St;
    map<char, int >m;
    m['(']=5;
    m['/']= 4;
    m['*']=3;
    m['+']=2;
    m['-']=2;

    string postfix="";
    int i=0;
    while(s[i]!='\0')
    {

        if(s[i]=='('  || m[s[i]]>1)
        {
            if(St.is_empty() )
            {
                St.push(s[i]);
            }
            else if(m[s[i]] >= m[St.top_elem()])
            {
                St.push(s[i]);
            }
            else if(s[i]=='(' || St.top_elem()=='(')
            {
                St.push(s[i]);
            }
            else
            {
                while (!(St.is_empty()) && m[s[i]]< m[St.top_elem()])  
                 {
                    char p = St.pop();  
                    if(p!= '(')        
                        postfix += p;
                    if(St.top_elem()=='(')
                       { break;}
                 }
                St.push(s[i]);
            }
        }
        else if(s[i]==')')
        {
            while(!(St.top_elem()=='('))
            {
                char p = St.pop();
                if(p!= '(')        
                    postfix += p;
            }
            char t = St.pop();
        }
        else{
            postfix += s[i];
        }
        i++;
    }
    while (!(St.is_empty()))
    {
        char p = St.pop();
        if(p!='(')
            postfix +=p;
    }
    return postfix;
}

float equation_evaluation(string s)
{  
    stack1 St;
    map<char, int >m;
    m[')']=6;
    m['(']=5;
    m['/']= 4;
    m['*']=3;
    m['+']=2;
    m['-']=2;

    //assigning the values with variables
    map<char , int > demo;
    int i=0, j=97;
    int a=0; bool neg=false;
    string finall="";
    while(s[i]!='\0')
    {
        if(s[i]>= '0' && s[i] <= '9')
        {
            a=a*10+(int ) (s[i]-'0');
        }
        else if(s[i]=='(' )
        {
            finall += s[i];
        }
        else{
            if( m[s[i]] >=1 && s[i-1]!=')')
                 {  char b = j;
                    demo[b] = a;

                    if(neg)
                        {
                            demo[b]=-a;
                            neg = false;
                        }

                    finall += b;
                    j++;
                    finall +=s[i];
                    a=0;
                }
           else
                {
                    finall +=s[i];
                }

            if(s[i]=='-')
                {
                    neg = true;
                }
        }
        i++;
    }
    if(s[i-1]!= ')')
   { char b = j;
    demo[b] = a;
        if(neg)
        {
            demo[b]=-a;
            neg = false;
        }
    finall += b;
          
    }
    s=finall;
    string postfix = infix_to_postfix(s);

    //Evaluation of the postfix expression
    s=postfix;
    i=0;int k=122;
    stack1 operand;
    map<char, int>value;

    while(s[i]!='\0')
    {
        if(m[s[i]]<1)
        {
            operand.push(s[i]);
        }
        else 
        {
            int b = demo[operand.pop()];
            int a = demo[operand.pop()];
            char z = k;
            value[z] = evaluate(a, s[i], b);
            cout<<a<<s[i]<<b<<endl;
            cout<<"res :"<<value[z]<<endl;
            demo[z] = value[z];
            operand.push(z);
            k--;
        }
        i++;
    }
    return value[operand.pop()];
}

int main()
{
    int t;
    cin>>t;
    string s;
    float p;

    while(t--)
    {
        cin>>s;
        if(s.size()<=30)
            {
                p = equation_evaluation(s);
                cout<<p<<endl;
            }
        else
            {
                cout<<"overflow"<<endl;
            }
    }
    return 0;
}
