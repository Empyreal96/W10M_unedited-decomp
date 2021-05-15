// sub_969C08 
 
void __fastcall sub_969C08(int a1, int a2, int a3)
{
  unsigned int v3; // r5
  int v4; // r0

  if ( v3 <= 0xC03FFFFF )
  {
    __dmb(0xBu);
    *(_DWORD *)v3 = a3;
    if ( v3 + 1070596096 <= 0xFFF )
    {
      v4 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v4, (_DWORD *)(v4 + 4 * (v3 & 0xFFF)), a3);
    }
    JUMPOUT(0x95333C);
  }
  JUMPOUT(0x95333A);
}
