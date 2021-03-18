#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

class file 
{  
    protected:
        ifstream inFile;      
               
    public:    
        file();
        ~file();
        void loop();
};

file::file() 
{
    inFile.open("dane_obrazki.txt");
    if (!inFile.good())
        {
            cerr << "Blad - pliku nie da sie otworzyc!\n";
            exit(1);
        }
}


file::~file() 
{
    inFile.close();
}

struct rc 
{
    int row;
    int column;
};

void file::loop() 
{
    int tab[20][20];
    int a;
    int Row=0;
    int Column=0;
    int sum;
    string row[21];
    string column[21];

    while(tab >> a) 
    {
        for(int b = 0; b < sizeof(tab) && inFile >> a; b++) 
        {
            for(int i=0; i<=20; i++) 
            {
                inFile >> row[i];

                for(int j=0; j<=20; j++)
                {
                    inFile >> column[j];

                    if (row[i][j] & column[j][i]==0) 
                    {
                        inFile >> sum;
                    }
                    cout << '\n';
                    
                    for(int k=0; k<=20; k++) 
                    {
                        for(int d=0; d<=21; d++) 
                        {
                            if(row & column % 2==0) 
                            {
                                int sum = 0;

                                if((sum%2==0 && row[i][20] !='0') || (sum%2==1 && row[i][20]=='1')) 
                                { 
                                    cout << Row << "," << '\n';
                                    Row++;
                                }

                                if((sum%2==0 && column[j][20] !='0') || (sum%2==1 && column[j][20]=='1')) 
                                {
                                    cout << Column << "," << '\n';
                                    Column++;
                                }
                            }
                        }
                        dane.close();
                    }
                }
            }
        }
    }
}

int main() 
{
    file inFile;
    inFile.loop();
    return 0;
}
