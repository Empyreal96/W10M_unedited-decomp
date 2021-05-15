// MiFindBestOutswapPagefile 
 
int __fastcall MiFindBestOutswapPagefile(int a1, int a2)
{
  unsigned int v4; // r1
  int v5; // r4
  __int16 v6; // r3

  *(_DWORD *)a2 = MiWsSwapPageFileNumber();
  v4 = *(_DWORD *)(a1 + 3596);
  __dmb(0xBu);
  v5 = 0;
  if ( !v4 )
    return *(_DWORD *)a2;
  while ( 1 )
  {
    v6 = *(_WORD *)(*(_DWORD *)(a1 + 4 * v5 + 3600) + 96);
    if ( (v6 & 0x10) == 0 && (v6 & 0x40) == 0 && (v6 & 0x80) != 0 )
      break;
    if ( ++v5 >= v4 )
      return *(_DWORD *)a2;
  }
  return sub_51D360(2);
}
