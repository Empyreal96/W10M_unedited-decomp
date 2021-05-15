// sub_510220 
 
void __fastcall sub_510220(int a1, unsigned int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // r2
  int v11; // r4
  int v12; // r0

  if ( a2 <= 0xC03FFFFF )
  {
    v10 = *(_DWORD *)a2;
    v11 = 0;
    __dmb(0xBu);
    *(_DWORD *)a2 = a10;
    if ( (v10 & 2) == 0 && (a10 & 2) != 0 )
      v11 = 1;
    if ( a2 + 1070596096 <= 0xFFF )
    {
      v12 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v12, (_DWORD *)(v12 + 4 * (a2 & 0xFFF)), a10);
    }
    if ( v11 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
    JUMPOUT(0x426B00);
  }
  JUMPOUT(0x426AFC);
}
