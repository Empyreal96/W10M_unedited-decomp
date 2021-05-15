// sub_96B614 
 
void sub_96B614()
{
  unsigned int v0; // r4
  int v1; // r5
  int v2; // r8
  unsigned int v3; // r9
  int v4; // r3
  int v5; // r6
  int v6; // r0

  if ( v0 <= 0xC03FFFFF )
  {
    v4 = *(_DWORD *)v0;
    v5 = 0;
    __dmb(0xBu);
    *(_DWORD *)v0 = v1;
    if ( (v4 & 2) == 0 && (v1 & 2) != 0 )
      v5 = 1;
    if ( v0 + v2 <= v3 )
    {
      v6 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v6, (_DWORD *)(v6 + 4 * (v0 & 0xFFF)), v1);
    }
    if ( v5 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
    JUMPOUT(0x956FF6);
  }
  JUMPOUT(0x956FF4);
}
