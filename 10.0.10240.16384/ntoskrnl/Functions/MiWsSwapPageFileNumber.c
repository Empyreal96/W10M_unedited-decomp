// MiWsSwapPageFileNumber 
 
unsigned int __fastcall MiWsSwapPageFileNumber(int a1)
{
  unsigned int v1; // r1
  int v2; // r2
  unsigned int result; // r0

  v1 = *(_DWORD *)(a1 + 3596);
  v2 = a1;
  __dmb(0xBu);
  result = 0;
  if ( !v1 )
    return 2;
  while ( (*(_WORD *)(*(_DWORD *)(v2 + 3600) + 96) & 0x10) == 0 )
  {
    ++result;
    v2 += 4;
    if ( result >= v1 )
      return 2;
  }
  return result;
}
