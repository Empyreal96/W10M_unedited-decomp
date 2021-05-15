// MiCombineCompareThread 
 
int __fastcall MiCombineCompareThread(unsigned int a1, int a2)
{
  unsigned int v2; // r3

  v2 = *(_DWORD *)(a2 + 12);
  if ( a1 > v2 )
    return 1;
  if ( a1 >= v2 )
    return 0;
  return -1;
}
