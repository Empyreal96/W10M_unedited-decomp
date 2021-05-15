// WdipSemQueryScenarioTable 
 
unsigned int __fastcall WdipSemQueryScenarioTable(unsigned int a1, int a2)
{
  unsigned int v2; // r4
  unsigned int *v5; // r9
  int v6; // r5
  unsigned int v7; // r7
  unsigned int v8; // r6
  unsigned int v9; // t1

  v2 = 0;
  if ( a1 )
  {
    v5 = (unsigned int *)WdipSemScenarioTable;
    v6 = 0;
    v7 = dword_61C880;
    if ( dword_61C880 )
    {
      while ( 1 )
      {
        v9 = *v5++;
        v8 = v9;
        if ( !memcmp(a1, v9, 16) && a2 == *(unsigned __int16 *)(v8 + 16) )
          break;
        if ( ++v6 >= v7 )
          return v2;
      }
      v2 = v8;
    }
  }
  return v2;
}
