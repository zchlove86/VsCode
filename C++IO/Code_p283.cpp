#include<fstream>
#include<iostream>
using namespace std;
int main()
{
    char data[100];
    //open the file in write mode; 
    ofstream outfile;
    outfile.open("afile.dat");
    cout<<"Writing to the file"<<endl;
    cout<<"Enter your name: ";
    cin.getline(data,100);
    
    //Write user input data to a fiel;
    outfile<<data<<endl;
    cout<<"Enter your age: "<<endl;
    cin>>data;
    cin.ignore();

    //Write user input data to a file again;
    outfile<<data<<endl;
    //close 
    outfile.close();

    //open the file in read mode
    ifstream infile;
    infile.open("afile.dat");

    
    cout<<"Reading from the file"<<endl;
    infile>>data;
    //write date to the screen
    cout<<data<<endl;

    //close the open file
    infile.close();
    return 0;
}
