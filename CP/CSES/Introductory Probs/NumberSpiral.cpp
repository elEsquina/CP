#include <iostream>
using namespace std;


int main(){
    int t; 
    long x, y, s;

    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> x; 
        cin >> y;

        if (y > x){
            if (y % 2 == 1)
                s = y*y - x + 1;
            else 
                s = y*y - 2*y + x + 1;
        }
        else{
            if (x % 2 == 1)
                s = x*x - 2*x + y + 1;       
            else 
                s = x*x - y + 1;
        }


        cout << s << endl;
    }


    return 0;
}