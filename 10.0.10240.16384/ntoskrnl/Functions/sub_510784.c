// sub_510784 
 
void sub_510784()
{
  int v0; // r4
  unsigned int v1; // r5
  unsigned int v2; // r10
  int v3; // r3
  int v4; // r7
  int v5; // r0

  if ( v1 <= 0xC03FFFFF )
  {
    v3 = *(_DWORD *)v1;
    v4 = 0;
    __dmb(0xBu);
    *(_DWORD *)v1 = v0;
    if ( (v3 & 2) == 0 && (v0 & 2) != 0 )
      v4 = 1;
    if ( v1 + 1070596096 <= v2 )
    {
      v5 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v5, (_DWORD *)(v5 + 4 * (v1 & 0xFFF)), v0);
    }
    if ( v4 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
    JUMPOUT(0x4282D0);
  }
  JUMPOUT(0x4282CE);
}
