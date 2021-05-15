// MiMapDummyPages 
 
int MiMapDummyPages()
{
  int v0; // r0
  unsigned int v1; // r4
  unsigned int v2; // r5
  unsigned int v4; // r4
  int v5; // r2
  int v6; // r3
  int v7; // r5
  int v8; // r0

  v0 = MiReservePtes(&dword_634D58, 2u);
  v1 = v0;
  if ( !v0 )
    return 0;
  v2 = (dword_681114 & 0x3ED | (dword_634900 << 12) | MiDetermineUserGlobalPteMask(v0)) & 0xFFFFF3FF | 0x12;
  if ( v1 >= 0xC0000000 )
    return sub_9704E0();
  *(_DWORD *)v1 = v2;
  dword_634904 = v1 << 10;
  v4 = v1 + 4;
  v5 = v2 & 0xFFF | (dword_6348F4 << 12);
  if ( v4 < 0xC0000000 || v4 > 0xC03FFFFF )
  {
    *(_DWORD *)v4 = v5;
  }
  else
  {
    v6 = *(_DWORD *)v4;
    v7 = 0;
    __dmb(0xBu);
    *(_DWORD *)v4 = v5;
    if ( (v6 & 2) == 0 )
      v7 = 1;
    if ( v4 + 1070596096 <= 0xFFF )
    {
      v8 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v8, (_DWORD *)(v8 + 4 * (v4 & 0xFFF)), v5);
    }
    if ( v7 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  dword_634908 = v4 << 10;
  return 1;
}
