#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ofstream writeData;
    ifstream readData;
    int num, temp[5], temp2;
    string show;

    writeData.open( "UTS1.DAT", ios::out );

    for( int n = 0; n < 5; n++ ){
        cout << "masukan ankga ke " << n << " : ";
        cin >> num;
        temp[n] = num;
        writeData << num << " ";
    }

    writeData.close();

    writeData.open("UTS2.DAT", ios::out );

    for( int i = 0; i < 5; i++ ){

        for( int j = 0; j < 5; j++ ){
            if( temp[j] < temp[i] ){
                temp2 = temp[j];
                temp[j] = temp[i];
                temp[i] = temp2;
            }
        }

    }

    for( int i = 0; i < 5; i++ ){
        writeData << temp[i] << "\n";
    }


    writeData.close();

    cout << "\n\nouput angka : " << endl;

    readData.open("UTS1.DAT", ios::in);

    while( getline(readData, show) ){
        cout << show << "\n";
    }

    readData.close();



    return 0;
}
