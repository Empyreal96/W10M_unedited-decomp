// WdipSemQueryProviderTable 
 
unsigned int __fastcall WdipSemQueryProviderTable(unsigned int a1)
{
  unsigned int v2; // r4
  unsigned int *v3; // r9
  int v4; // r5
  unsigned int v5; // r7
  unsigned int v6; // r8
  unsigned int v7; // t1

  v2 = 0;
  if ( a1 )
  {
    v3 = (unsigned int *)WdipSemProviderTable;
    v4 = 0;
    v5 = dword_61C760;
    if ( dword_61C760 )
    {
      while ( 1 )
      {
        v7 = *v3++;
        v6 = v7;
        if ( !memcmp(a1, v7, 16) )
          break;
        if ( ++v4 >= v5 )
          return v2;
      }
      v2 = v6;
    }
  }
  return v2;
}
