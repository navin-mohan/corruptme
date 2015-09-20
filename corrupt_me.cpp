#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdio.h>
using namespace std;

int corruptme(char filepath[])
{
    char buffer[]="#@$#3d";   //Hashed :D
    fstream file;
    file.open(filepath,ios::in|ios::out);
    if(!file)
        return 0;
    //Adding characters to the file
    for(int i=1;i<20;i++)
    {

        file.seekg(i*14);
        file.write(buffer,7);
        file.read(buffer,7);

    }

    return 1;
}

int main()
{
    char filename[20];
    cout<<"Make sure the target file is in the same folder as this file.\n";
    cout<<"Enter the file name: ";
    gets(filename);
    if(corruptme(filename))
        cout<<"Target File has been corrupted!" ;
    else
        cout<<"ERROR : File could not be opened.";
    getch();

}
