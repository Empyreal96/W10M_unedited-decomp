// PfpGetPageListCount 
 
int __fastcall PfpGetPageListCount(int a1, unsigned int a2, unsigned int a3)
{
  int result; // r0
  int *v5; // r4
  int v6; // r2
  int v7; // t1

  result = 0;
  if ( a2 <= a3 )
  {
    v5 = (int *)(a1 + 4 * a2);
    v6 = a3 - a2 + 1;
    do
    {
      v7 = *v5++;
      result += v7;
      --v6;
    }
    while ( v6 );
  }
  return result;
}
