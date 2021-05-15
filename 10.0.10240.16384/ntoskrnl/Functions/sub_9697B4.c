// sub_9697B4 
 
void sub_9697B4()
{
  unsigned int v0; // r5
  int v1; // r6
  int v2; // r3
  int v3; // r4
  int v4; // r0

  if ( v0 <= 0xC03FFFFF )
  {
    v2 = *(_DWORD *)v0;
    v3 = 0;
    __dmb(0xBu);
    *(_DWORD *)v0 = v1;
    if ( (v2 & 2) == 0 && (v1 & 2) != 0 )
      v3 = 1;
    if ( v0 + 1070596096 <= 0xFFF )
    {
      v4 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v4, (_DWORD *)(v4 + 4 * (v0 & 0xFFF)), v1);
    }
    if ( v3 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
    JUMPOUT(0x952AE0);
  }
  JUMPOUT(0x952ADE);
}
