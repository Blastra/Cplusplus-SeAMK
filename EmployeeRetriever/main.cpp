/*

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class CEmployee {
public:
    string firstName;
    string lastName;
    double salary;
};


int main()
{
    CEmployee *employees[10];
    ifstream emplFile;
    string line;
    int i=0;

    emplFile.open("EmployeeList.txt",ios::in);
    if (emplFile.is_open())
    {
        while ( getline (emplFile,line) )
        {

            employees[i] = line;

          cout << line << "\n";
        }
        //emplFile << "har";
        //emplFile << "jur";
        //emplFile << "ner";
        emplFile.close();
    }
    else cout << "Unable to open file";



    return 0;

    /*

    //Etsitään kansio, jossa suoritettava ohjelma on.
    //Vain Linux-ratkaisu. Tiedostopolku ei salli välilyöntejä.

    //Ohjelma sallii syötteekseen vain tiedoston EmployeeSalaries.txt
    //suoritettavan ohjelman kansiossa.


    stringstream virtaus;
    char bufferiKoko[1024];
    string muunnettuBuf;
    string kokoPolku;
    char suffiksi[64] = "/EmployeeSalaries.txt";


    int linkki = readlink("/proc/self/exe", bufferiKoko,sizeof(bufferiKoko));

    bufferiKoko[linkki]='\0';

    virtaus << bufferiKoko;
    virtaus >> muunnettuBuf;
    cout << (muunnettuBuf+"/EmployeeSalaries.txt");

    //Muodostetaan koko tiedostonimi

    //Avataan tiedosto




    //ssize_t readlink(, char buffer)
    */


}

