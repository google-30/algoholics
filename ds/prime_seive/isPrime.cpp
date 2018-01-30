#include <iostream>
#include<cstring>
using namespace std;

 bool prime[1000004];
 
void SieveOfEratosthenes()
{
    int n=1000004;
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p=2; p<=n; p++)
       if (prime[p])
          cout << p << " ";
}

int main() {
	
	
	
	return 0;
}
