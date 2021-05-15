// sub_50B648 
 
void sub_50B648()
{
  unsigned int v0; // r4
  int v1; // r6
  char v2; // r7
  int v3; // r8
  _DWORD *v4; // r10
  unsigned int v5; // r3
  int v6; // r2
  int v7; // r8
  int v8; // r0

  if ( v1 )
    v5 = (*(_DWORD *)(v3 + 16) & 0x1ED | (v4[v1] << 12) | MiDetermineUserGlobalPteMask(0)) & 0xFFFFF1FF;
  else
    v5 = (*(_DWORD *)(v3 + 4) & 0x3ED | (*v4 << 12) | MiDetermineUserGlobalPteMask(v0)) & 0xFFFFF3FF;
  v6 = v5 | 0x12;
  if ( v0 + 0x40000000 > 0x3FFFFF )
  {
    *(_DWORD *)v0 = v6;
  }
  else
  {
    v7 = 0;
    __dmb(0xBu);
    *(_DWORD *)v0 = v6;
    if ( (v2 & 2) == 0 )
      v7 = 1;
    if ( v0 + 1070596096 <= 0xFFF )
    {
      v8 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v8, (_DWORD *)(v8 + 4 * (v0 & 0xFFF)), v6);
    }
    if ( v7 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  JUMPOUT(0x463B0C);
}
