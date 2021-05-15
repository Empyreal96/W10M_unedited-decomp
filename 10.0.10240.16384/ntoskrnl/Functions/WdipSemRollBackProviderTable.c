// WdipSemRollBackProviderTable 
 
unsigned int __fastcall WdipSemRollBackProviderTable(unsigned int result)
{
  int v1; // r4
  unsigned int v2; // r7
  int *v3; // r6

  v1 = result;
  v2 = result;
  if ( result < dword_61C760 )
  {
    v3 = &WdipSemProviderTable[result];
    do
    {
      result = WdipSemFastFree(2, *v3);
      *v3++ = 0;
      ++v2;
    }
    while ( v2 < dword_61C760 );
  }
  dword_61C760 = v1;
  return result;
}
