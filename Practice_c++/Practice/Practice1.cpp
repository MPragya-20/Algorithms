//Factorial program using oop concept and recursion
#include<iostream>
using namespace std;
class Practice1
{
private:
    int x;
public:
    int fact(int x){
        if ((x == 0)||(x==1)){
            return 1;
        }
        else{
            return (x*fact(x-1));
        }
    }
};

int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    Practice1 obj;
    cout<< "\nThe factorial of "<<n<<" is : "<< obj.fact(n)<<endl;

}
