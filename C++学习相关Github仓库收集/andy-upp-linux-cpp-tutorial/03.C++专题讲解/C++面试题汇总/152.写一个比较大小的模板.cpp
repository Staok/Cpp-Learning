   #include<iostream> 
   using namespace std; 
   template<typename type1,typename type2>//函数模板 
   type1 Max(type1 a,type2 b) 
   { 
       return a > b ? a : b; 
   } 

   int main() 
   { 
       cout<<"Max = "<<Max(5.5,'a')<<endl; 
       return 0;
   }