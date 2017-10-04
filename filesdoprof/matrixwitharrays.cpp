#include <cstdlib>
#include <iostream>

using namespace std;

int main(){

    // create a constant representing the
    // number of array elements
    const unsigned short ni=2;
    const unsigned short nj=2;

    // create an array
    int matnumbers[ni][nj];


    cout<< " you will be prompted to enter " << ni * nj << "numbers, positive or negative but without decimals or comas . \n\n ";

    // create the loop that takes the input
    // the loop should run once for each array element, notice that this is a double loop
    for(int i=0; i <ni; i=i+1)
    for(int j=0; j <nj; ++j)
    {
             // prompt the user
       cout<<"enter a number :";

       // take the input, validate and repronpt if necessary
       while(!(cin>>matnumbers[i][j]))
       {
         // problem! clear cin and reprompt
         cin.clear();
         cin.ignore(100, '\n');
         cout<<"Please enter a valid integer:";
      }
    };

     // print another message
     cout<<"The following numbers have been recorded: \n ";

     // defines  a variable for the total
     int total=0;

     // loop again for the output
     for(int i=0; i <ni;i=i+1)
    for(int j=0; j <nj; ++j)
    {

             // prints all the numbers
      cout<<i<<" "<<j<<" "<<matnumbers[i][j]<<"\n";

             // adds to the total
      total+=matnumbers[i][j];

    };

    // prints the total
     cout<<"The sum of the numbers is: \n";
     cout<<total<<"\n";

    system("pause");
    return EXIT_SUCCESS;
}
