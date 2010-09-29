import java.math.*;
class Stringer {
  public char[] k_permutation(int k, char [] a)
  {
    char s[] = a.clone();
    int size = s.length;
    BigInteger f = new BigInteger("1");
    for(int i = 2; i < size ; ++i)
      f = f.multiply(new BigInteger(i+""));
    BigInteger K = new BigInteger(k+"");
    for(int i = 1; i < size ; ++i)
      {
	int temp = (f.divide(K).intValue()) % (size + 1 - i);
	
	System.out.println(temp);
	char t = s[i+temp-1];
	for(int j = i+temp ; j>i ; --j)
	  s[j-1] = s[j-2];
	s[i-1] = t;
	f = f.divide(new BigInteger((size-i)+""));
      }
    return s;
  }
  public static void main(String []as)
  {
    char s[] = {'a', 'b','c' };
    Stringer stringer = new Stringer();
    System.out.println(stringer.k_permutation(5, s));
  }
}