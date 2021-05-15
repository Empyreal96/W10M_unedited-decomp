// MiNumberWsSwapPagefiles 
 
int __fastcall MiNumberWsSwapPagefiles(int a1)
{
  int v1; // r2
  int v2; // r1
  int result; // r0

  v1 = a1;
  v2 = *(_DWORD *)(a1 + 3596);
  result = 0;
  __dmb(0xBu);
  for ( ; v2; --v2 )
  {
    if ( (*(_WORD *)(*(_DWORD *)(v1 + 3600) + 96) & 0x10) != 0 )
      ++result;
    v1 += 4;
  }
  return result;
}
