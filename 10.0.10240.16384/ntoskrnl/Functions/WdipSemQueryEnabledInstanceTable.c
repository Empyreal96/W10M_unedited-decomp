// WdipSemQueryEnabledInstanceTable 
 
int *__fastcall WdipSemQueryEnabledInstanceTable(unsigned int a1)
{
  int v2; // r5
  int *i; // r4

  v2 = 0;
  if ( a1 )
  {
    for ( i = (int *)WdipSemEnabledInstanceTable; &WdipSemEnabledInstanceTable != i; i = (int *)*i )
    {
      if ( !memcmp(a1, (unsigned int)(i + 2), 16) )
        return i;
    }
  }
  return (int *)v2;
}
