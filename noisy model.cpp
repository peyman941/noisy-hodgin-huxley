/*special tanks to zeinab kouhpeyma and //github.com/nosratuallah// for her/his useful help */
/*this is simplest model for noisy model based on hh model in neuroscience*/
-----------------****************************************---------------------------------
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <math.h>
#include<fstream>
#include <time.h>

#define ESP .04


using namespace std;

int main(int argc, char *argv[])
{
    double vth,v1,v2,t, m1,m2, n1,n2, h1,h2, s2;

   double am=(-2.5)/(1-exp(2.5));
   double bm=4.0;
   double an=0.01*(-10)/(1-exp(1));
   double bn=0.125;
   double ah=0.07;
   double bh=1./(1+exp(3.0));
   double I[100000];
 for(int i = 0; i <= 100000; i++)
       I[i] = 0;
   for(int i = 25000; i <= 75000; i++)
           I[i] = 4*(0.1+(rand()%2));

   m1 = am /(am+bm);
   n1 = an/(an+bn);
   h1 = ah/(ah +bh);

 

    vth=-50.0;
    
    v1=-65.0;
    

    ofstream outputV1;
   outputV1.open ("v1.txt");



 

    for(int i =0 ; i<=100000; ++i)
{
     outputV1 << i << '\t' << v1 << '\n';
    

       double alpha_n1 = (0.01 * v1 + 0.55) / double (1-exp((-v1-55) *.1 ));
       double beta_n1 = 0.125 * exp(.0125 * (-v1-65));

       double alpha_m1 =( 0.1 * v1 + 4) / double(1-exp((-v1-40)*.1));
       double beta_m1 = 4 * exp(0.05*(-v1-65));

       double alpha_h1 = 0.07 * exp((-v1-60)*0.05);
       double beta_h1 = 1.0 / double(1+exp((-v1-30)*.1));

    

       n1 +=  ESP *((alpha_n1)*(1-n1) - (beta_n1) *n1);
       m1 +=  ESP *((alpha_m1)*(1-m1) - (beta_m1)*m1);
       h1 +=  ESP *((alpha_h1)*(1-h1)- (beta_h1)*h1);
       v1 +=  ESP *(I[i]-(120*pow(m1,3)*h1*(v1-55.72)+ 36*pow(n1,4)*(v1+77)+0.3*(v1+54.4)));

      
}

    outputV1.close();

}
