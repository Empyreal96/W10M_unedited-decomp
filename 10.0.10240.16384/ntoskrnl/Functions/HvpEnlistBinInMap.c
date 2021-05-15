// HvpEnlistBinInMap 
 
int __fastcall HvpEnlistBinInMap(int a1, unsigned int a2, int a3, int a4, int a5)
{
  int v6; // r6

  if ( a4 )
    v6 = a4;
  else
    v6 = a3;
  if ( (*(_DWORD *)(v6 + 8) & 0xFFF) != 0 )
    return sub_803EE0();
  if ( *(_DWORD *)(v6 + 8) + a5 > a2 )
    JUMPOUT(0x803EF2);
  HvpPointMapEntriesToBuffer(a1, a3, a4, *(_DWORD *)(v6 + 8), a5, 0);
  if ( (*(_BYTE *)(a1 + 72) & 2) == 0 )
  {
    *(_DWORD *)(a1 + 76) += 32;
    if ( !HvpEnlistFreeCells(a1, v6, a5) )
      JUMPOUT(0x803F30);
  }
  return 0;
}
