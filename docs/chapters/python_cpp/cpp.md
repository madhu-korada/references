---
layout: default
title: C++
lang-ref: chapter1.0
---

* absolute :- ```fabs()``` or ```abs()```

* rounding :- ```round(5.0245) = 5```

* rounding to 'n' decimals :- 
```cpp
float round(float var) 
{ 
    // 37.66666 * 100 =3766.66 
    // 3766.66 + .5 =3767.16    for rounding off value 
    // then type cast to int so value is 3767 
    // then divided by 100 so the value converted into 37.67 
    float value = (int)(var * 100 + .5); 
    return (float)value / 100; 
} 
int main() 
{ 
    float var = 37.66666; 
    cout << round(var); 
    return 0; 
} 
// output is 37.67
```
* or
```cpp
#include <iostream> 
using namespace std; 
float round(float var) 
{ 
    // we use array of chars to store number as a string. 
    char str[40];  
  
    // Print in string the value of var with two decimal point 
    sprintf(str, "%.2f", var); 
  
    // scan string value in var  
    sscanf(str, "%f", &var);  
  
    return var;  
} 
int main() 
{ 
    float var = 37.66666; 
    cout << round(var); 
    return 0; 
} 
// output is 37.67
```

