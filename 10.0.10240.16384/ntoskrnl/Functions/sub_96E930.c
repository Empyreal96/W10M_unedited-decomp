// sub_96E930 
 
void __fastcall sub_96E930(int a1, int a2, int a3)
{
  unsigned int v3; // r4
  int v4; // r3
  int v5; // r8
  int v6; // r0

  if ( v3 <= 0xC03FFFFF )
  {
    v4 = *(_DWORD *)v3;
    v5 = 0;
    __dmb(0xBu);
    *(_DWORD *)v3 = a3;
    if ( (v4 & 2) == 0 )
      v5 = 1;
    if ( v3 + 1070596096 <= 0xFFF )
    {
      v6 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v6, (_DWORD *)(v6 + 4 * (v3 & 0xFFF)), a3);
    }
    if ( v5 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
    JUMPOUT(0x961986);
  }
  JUMPOUT(0x961984);
}
