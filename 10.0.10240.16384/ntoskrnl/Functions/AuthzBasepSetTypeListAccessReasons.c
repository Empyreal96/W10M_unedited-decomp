// AuthzBasepSetTypeListAccessReasons 
 
int __fastcall AuthzBasepSetTypeListAccessReasons(int result, int a2, int a3, int a4, int a5, char a6)
{
  int i; // r7
  int *v8; // r4
  int v9; // r5

  for ( i = a5; i; --i )
  {
    v8 = *(int **)(a4 + 40);
    v9 = 1;
    if ( v8 )
    {
      while ( v9 )
      {
        if ( (v9 & result) != 0 && (a6 || !*v8) )
          *v8 = a2 | a3;
        ++v8;
        v9 *= 2;
      }
    }
    a4 += 44;
  }
  return result;
}
