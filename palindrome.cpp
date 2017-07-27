#include <iostream>
#include <cstring>
using namespace std;
int main()
{
   char input[] = "xyxxmalayalamabc";
   char* ptr = input;
   int location = 0;
   int maximumsize = 0;
   for ( int i = 0; i < strlen(input) - 1; i++ ) 
   {
       int left = i;
       int right = i;
       int count = 0;
       while ( left > 0 ) 
       {
           if ( input[left--] != input[right++] ) 
           {
               break;
           }
           count++;
       }
       if ( count > maximumsize ) 
       {
          maximumsize = count;
          location = i;
       }
   }

   cout << maximumsize << " @ " << location << endl;
   int start = location - maximumsize;
   int end = location + maximumsize;
   for ( int i = start + 1; i < end; i++ ) {
       cout << input[i];
   }
   return 0;
}
