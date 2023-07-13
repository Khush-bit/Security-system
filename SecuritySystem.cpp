//Security system project

#include<iostream>
#include<fstream>//for file operations
#include<sstream>//provide templates and types which enables inter operations b/t string buffers and string objects
#include<string>//for strings
using namespace std;

void registration()
{


}


int main()
{
    int a, i=0;
    string text,old,password1,password2,pass, name, password0,age, user,word,word1;
    string creds[2],cp[2];

    cout<<"\n\n\t\t SECURITY SYSTEM\t\t"<<endl;
    cout<<"\t\t 1)Register";
    cout<<"\n\t\t 2)Login";
    cout<<"\n\t\t 3)Change password";
    cout<<"\n\t\t 4)End program";

    do{
        cout<<endl<<endl;
        cout<<"\n\t Enter your choice: ";cin>>a;

        switch(a)
        {
            case 1:
                {
                    cout<<"\n\t\t_______________________________________________\t\t\n";
                    cout<<"\n\t\t         Registration for new users";
                    cout<<"\n\t\t_______________________________________________\t\t\n";
                    cout<<"Enter your username: ";cin>>name;
                    cout<<"Enter your password: ";cin>>password0;
                    cout<<"Enter your age: ";cin>>age;

                    ofstream of1;
                    of1.open("file.txt");
                    if(of1.is_open())
                    {
                        of1<<name<<"\n";
                        of1<<password0<<"\n";
                        cout<<"Registration succesfull"<<endl;
                    }
                    break;
                    
                }
            
            case 2:
                {
                    i=0;
                    cout<<"\n\t\t_______________________________________________\t\t\n";
                    cout<<"\n\t\t            Login for existing users";
                    cout<<"\n\t\t_______________________________________________\t\t\n";
                    
                    ifstream of2;
                    of2.open("file.txt");
                    cout<<"Please enter the username: ";cin>>user;
                    cout<<"Please enter the password: ";cin>>pass;
                    if(of2.is_open())
                    {
                        while(!of2.eof())
                        {
                            while(getline(of2,text))
                            {
                                istringstream iss(text);
                                iss>>word;
                                creds[i]=word;//0th positon will store username
                                i++;  //& 1st position will store password
                            }

                            if(user==creds[0] && pass==creds[1])
                            {
                                cout<<"----LOGIN SUCCESFULL----";
                                cout<<endl<<endl;
                                cout<<" Details: "<<endl;
                                cout<<"Username: "+name<<endl;
                                cout<<"Password: "+pass<<endl;
                                cout<<"Age: "+age<<endl;
                            }

                            else
                            {
                                cout<<endl<<endl;
                                cout<<"Incorrect Credentials"<<endl;
                                cout<<"-Press 2 to login again"<<endl;
                                cout<<"-Press 3 to change password"<<endl;
                                break;
                            }
                        }
                    }
                    break;

                }

            case 3:
            {
                i=0;
                cout<<"\n\t\t_______________________________________________\t\t\n";
                cout<<"\n\t\t                Change password";
                cout<<"\n\t\t_______________________________________________\t\t\n";

                ifstream of0;
                of0.open("file.txt");
                cout<<"Enter the old password: ";
                cin>>old;
                if(of0.is_open())
                {
                    while(of0.eof())
                    {
                        while(getline(of0,text))
                        {
                            istringstream iss(text);
                            iss>>word1;
                            cp[i]=word1;
                            i++;
                        }
                        if(old==cp[1])
                        {
                            of0.close();
                            ofstream of1;
                            if(of1.is_open())
                            {
                                cout<<"Enter your new password: ";
                                cin>>password1;
                                cout<<"Enter your password again: ";
                                cin>>password2;
                                
                                if(password1==password2)
                                {
                                    of1<<cp[0]<<"\n";
                                    of1<<password1;
                                     cout<<"Password changed succesfully!!"<<endl;
                                }

                                else
                                 {
                                    of1<<cp[0]<<"\n";
                                    of1<<old;
                                    cout<<"Password do not match!!"<<endl;
                                }                                
                            }
                        }
                        else{
                            cout<<"Please enter a valid password"<<endl;
                            break;
                        }
                    }
                }
                break;
                
            }

            case 4:
            {
                cout<<"\n\t\t_______________________________________________\t\t\n";
                cout<<"\n\t\t                  THANK YOU!!";
                cout<<"\n\t\t_______________________________________________\t\t\n";
                break;
            }

            default:
            cout<<"Enter a valid choice!!";
        }

    }while(a!=4);
    return 0;
}
