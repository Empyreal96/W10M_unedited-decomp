// sub_54E0D8 
 
void __fastcall sub_54E0D8(int a1, int a2, __int16 a3)
{
  unsigned int v3; // r5
  int v4; // r0

  if ( v3 <= 0xC0300FFF )
  {
    v4 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
    MiArmWriteConvertedHardwarePde(v4, (_DWORD *)(v4 + 4 * (v3 & 0xFFF)), a3);
  }
  JUMPOUT(0x4E56F8);
}
