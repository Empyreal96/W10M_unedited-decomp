// sub_969E28 
 
void __fastcall sub_969E28(int a1, unsigned int a2, int a3)
{
  int *v3; // r4
  int v4; // r8
  unsigned int v5; // r10
  int v6; // r3
  int v7; // r9
  int v8; // r0

  if ( (unsigned int)v3 <= v5 )
  {
    v6 = *v3;
    v7 = 0;
    __dmb(0xBu);
    *v3 = v4;
    if ( (v6 & a1) == 0 )
      v7 = 1;
    if ( (unsigned int)v3 + a3 <= a2 )
    {
      v8 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v8, (_DWORD *)(v8 + 4 * ((unsigned __int16)v3 & 0xFFF)), v4);
    }
    if ( v7 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
    JUMPOUT(0x9539B0);
  }
  JUMPOUT(0x9539AC);
}
