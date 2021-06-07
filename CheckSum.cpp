#include <string>
#include <iostream>
using namespace std;


string addBinary(string a, string b)
{
    string result = ""; 
    int s = 0;          

    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1)
    {
        s += ((i >= 0)? a[i] - '0': 0);
        s += ((j >= 0)? b[j] - '0': 0);
 
        result = char(s % 2 + '0') + result;
 
        s /= 2;
 
        i--; j--;
    }

    return result;
}

string checkFront(string str)
{
    string start_str = "x";

    while(start_str != "")
    {
        int size = str.size();
        int size_needed = size - 3;
        if(size_needed>0)
        {
            for(int a = 0; a < size_needed; a++)
            {
                start_str += *str.begin();
                str.erase (str.begin());
            }
            str = addBinary(start_str, str);
        }
        else
         start_str = "";    
    }
    return str;
    
}



string threeDivider(string given_string, bool isSecond)
{
    string str = given_string;
    string new_string = "";
    string old_string = "";
    string sum = "";

    int counter = 0;


    for (string::iterator  j = str.begin(); j != str.end(); ++j)
    {
        if(counter !=3){ new_string += *j; counter++;}

        if(counter ==3)
        {
            sum = addBinary(old_string, new_string);
            old_string = new_string;
            new_string = "";
            counter = 0;
        }
    }
    sum = checkFront(sum);

    if(!isSecond){
        for (string::iterator  j = sum.begin(); j != sum.end(); ++j)
        {
            char new_char = *j;
            if(new_char== '1') new_string +="0";
            else new_string +="1";
        }
        return new_string;
    }
    else 
    return sum;

}

int main()
{
    string str = "100100";  
    string complement = threeDivider(str, false);
    cout<<complement<<endl;
    string end_value = threeDivider(str, true);
    cout<<end_value<<endl;
    string temp_result = addBinary(complement, end_value);
    cout << stoi(temp_result) << endl;
    string result = "";
    for (string::iterator  j = temp_result.begin(); j != temp_result.end(); ++j)
        {
            char new_char = *j;
            if(new_char== '1') result +="0";
            else result +="1";
        }
    if(stoi(result) == 0){
        cout << "Ningun error en el proceso "<< endl;
    }
    else cout << "Hubo un error en el proceso"<< endl;
     

}
