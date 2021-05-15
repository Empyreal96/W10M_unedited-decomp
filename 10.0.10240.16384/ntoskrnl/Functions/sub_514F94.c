// sub_514F94 
 
void __fastcall sub_514F94(int a1, unsigned int a2)
{
  int v2; // r4
  int v3; // r0

  if ( a2 <= 0xC03FFFFF )
  {
    __dmb(0xBu);
    *(_DWORD *)a2 = v2;
    if ( a2 + 1070596096 <= 0xFFF )
    {
      v3 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v3, (_DWORD *)(v3 + 4 * (a2 & 0xFFF)), v2);
    }
    JUMPOUT(0x4324A8);
  }
  JUMPOUT(0x4324A6);
}
