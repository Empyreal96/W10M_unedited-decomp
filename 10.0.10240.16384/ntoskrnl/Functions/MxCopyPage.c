// MxCopyPage 
 
int __fastcall MxCopyPage(int a1, int a2)
{
  unsigned int v4; // r0
  int v5; // r5
  unsigned int v6; // r4
  unsigned int v7; // r2
  int v9; // r3
  int v10; // r6
  int v11; // r0
  int v12; // r0

  v4 = MxGetPhase0Mapping();
  v5 = v4;
  if ( !v4 )
    sub_964FE4();
  v6 = ((v4 >> 10) & 0x3FFFFC) - 0x40000000;
  v7 = (dword_681120 & 0x1ED | (a1 << 12) | MiDetermineUserGlobalPteMask(v6)) & 0xFFFFF1FF | 0x12;
  if ( v6 < 0xC0000000 || v6 > 0xC03FFFFF )
  {
    *(_DWORD *)v6 = v7;
  }
  else
  {
    v9 = *(_DWORD *)v6;
    v10 = 0;
    __dmb(0xBu);
    *(_DWORD *)v6 = v7;
    if ( (v9 & 2) == 0 )
      v10 = 1;
    if ( v6 + 1070596096 <= 0xFFF )
    {
      v11 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v11, (_DWORD *)(v11 + 4 * (v6 & 0xFFF)), v7);
    }
    if ( v10 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  memmove(v5, a2, 0x1000u);
  if ( v6 < 0xC0000000 || v6 > 0xC03FFFFF )
  {
    *(_DWORD *)v6 = 0;
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v6 = 0;
    if ( v6 + 1070596096 <= 0xFFF )
    {
      v12 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v12, (_DWORD *)(v12 + 4 * (v6 & 0xFFF)), 0);
    }
  }
  return KeFlushSingleTb(v5, 1);
}
