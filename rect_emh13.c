/**    Rectangle perimeter and area calculator.    
@file rect_perim_area.c    
@ Emily Huang 
@emh13@rice.edu    
@ 03/09/2021
*/

#include <stdio.h>
/************************************************ *  function prototypes ***********************************************/
unsigned int perimeter(unsigned int h, unsigned int w);
unsigned int area(unsigned int h, unsigned int w);

/************************************************ *  main ***********************************************/
int main(void){
    // defines the variables
    unsigned int height = 5;
    unsigned int width = 5;
    unsigned int p;
    unsigned int a;
    
    // calculates perimeter and area
    p = perimeter(height, width);
    a = area(height, width);
    
    // prints height, width, perimeter, and area
    printf("Height = %i; Width = %i\n", height, width);    
    printf("Perimeter = %i\n", p);    
    printf("Area = %i\n", a);    
    return 0;
}


/************************************************ *  perimeter calculator ***********************************************/
unsigned int perimeter(unsigned int h, unsigned int w)
{   
    // calculates the perimeter 
    unsigned int p = 2 * (h + w);
    return p;
}

/************************************************ *  area calculator ***********************************************/
unsigned int area(unsigned int h, unsigned int w)
{    
    // calculates the area
    unsigned int a = h * w;
    return a;
}
    
    