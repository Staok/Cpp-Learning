// Returns n! (the factorial of n).  For negative n, n! is defined to be 1.
int Factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
return result;
}

// Returns true if n is a prime number.
bool IsPrime(int n) {
  if (n <= 1) 
    return false;
  if (n % 2 == 0) 
    return n == 2;

  for (int i = 3; ; i += 2) {
    if (i > n/i) break;
    if (n % i == 0) return false;
  }
  return true;
}
