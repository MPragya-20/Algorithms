#include <iostream>
using namespace std;
int c = 0;
int TOF(int n ,char src,char dest, char aux){
    
    if (n == 1){
        cout<<"Move disc 1 from "<<src <<" to "<<dest<<"\n";
        c++;
        
        return c;
    }
    TOF(n-1, src, aux, dest);
    cout<<"Move disc "<<n<<" from "<<src <<" to "<<dest<<"\n"; 
    c++;   
    TOF(n-1, aux, dest, src);
    
}
int main(){
    int n;
    cout<<"Enter number of discs : ";
    cin>>n;
    int count = TOF(n, 'A', 'C', 'B');
    cout<<"Total moves : "<<count;
}