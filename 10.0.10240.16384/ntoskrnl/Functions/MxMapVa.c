// MxMapVa 
 
int __fastcall MxMapVa(unsigned int a1, int a2, int a3)
{
  __int16 v4; // r5
  int v6; // r0
  int v7; // r5
  unsigned int v8; // [sp+0h] [bp-28h]

  v8 = ((a1 >> 20) & 0xFFC) - 1070596096;
  v4 = (dword_681128 | MiDetermineUserGlobalPteMask(0)) & 0x1EC | 0xF013;
  if ( (*(_DWORD *)v8 & 2) != 0 )
    return 1;
  v6 = MxGetNextLargePage(a2);
  if ( v6 == -1 )
    return 0;
  v7 = v4 & 0x3FE | (v6 << 12) | 0x401;
  if ( v8 < 0xC0000000 )
  {
    *(_DWORD *)v8 = v7;
    if ( a3 == 1 )
      KeZeroPages((_DWORD *)(v8 << 20), 0x400000u);
    return 1;
  }
  return sub_96B614();
}
