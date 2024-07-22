#include <iostream>
#include <math.h>
#include <tuple>

float a,b,c;

float res;
float x,y,z;

using namespace std;

tuple<float, float> cuadratica(float a, float b, float c);

int main(){

  cout<<"Ingrese el valor a"<<endl;
  cin>>x;

  cout<<"Ingrese el valor b"<<endl;
  cin>>y;

  cout<<"Ingrese el valor c"<<endl;
  cin>>z;

    float root1,root2;
       
        tie(root1,root2) = cuadratica(x,y,z);

        if(isnan(root1)&&isnan(root2)){
            cout<<"la primera raiz es: "<< y*-1<<"+("<<(y*y)-(4*x*z)<<"i) / "<<2*x<<endl;
            cout<<"la segunda raiz es: "<< y*-1<<"-("<<(y*y)-(4*x*z)<<"i) / "<<2*x<<endl;
        }
        else{
        cout<<"la primera raiez es: "<< root1<<endl<< "la segunda raiz es: "<< root2<<endl;

        }

}
tuple<float, float> cuadratica(float a, float b, float c){
  

    float b1=b*-1;
    float b2=pow(b,2);
    float disc= 4*a*c;
    float divis=2*a;

    if(!isnan(sqrt(b2-disc))){
        res = (b1 + sqrt(b2-disc))/divis;
        float res2 =  (b1 - sqrt(b2-(disc)))/divis;
        return make_tuple(res, res2);
        
    }

    else{
        
        return make_tuple(sqrt(b2-disc), sqrt(b2-disc));

    }
  }
