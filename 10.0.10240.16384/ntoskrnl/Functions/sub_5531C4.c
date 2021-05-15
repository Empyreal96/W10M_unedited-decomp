// sub_5531C4 
 
void __fastcall sub_5531C4(int a1, int a2, unsigned int a3)
{
  int v3; // r4
  int v4; // r9
  unsigned int v5; // r10
  int v6; // r3
  int v7; // r6
  int v8; // r0

  if ( a3 <= 0xC03FFFFF )
  {
    v6 = *(_DWORD *)a3;
    v7 = 0;
    __dmb(0xBu);
    *(_DWORD *)a3 = v3;
    if ( (v6 & a1) == 0 && (v3 & a1) != 0 )
      v7 = 1;
    if ( a3 + v4 <= v5 )
    {
      v8 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v8, (_DWORD *)(v8 + 4 * (a3 & 0xFFF)), v3);
    }
    if ( v7 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
    JUMPOUT(0x4F325A);
  }
  JUMPOUT(0x4F3258);
}
