// future::wait
#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // std::chrono::milliseconds

// a non-optimized way of checking for prime numbers:
bool is_prime (int x) {
 for (int i=2; i<x; ++i) if (x%i==0) return false;
 return true;
}

int main ()
{
 // call function asynchronously:
 std::future<bool> fut = std::async (is_prime,194232491); 

 std::cout << "checking...\n";
 fut.wait();

 std::cout << "\n194232491 ";
 if (fut.get())      // guaranteed to be ready (and not block) after wait returns
   std::cout << "is prime.\n";
 else
   std::cout << "is not prime.\n";

 return 0;
}
