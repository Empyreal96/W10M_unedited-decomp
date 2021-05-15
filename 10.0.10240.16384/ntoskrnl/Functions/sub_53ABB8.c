// sub_53ABB8 
 
void sub_53ABB8()
{
  unsigned int v0; // r4
  int v1; // r5
  int v2; // r0

  if ( v0 <= 0xC03FFFFF )
  {
    __dmb(0xBu);
    *(_DWORD *)v0 = v1;
    if ( v0 + 1070596096 <= 0xFFF )
    {
      v2 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v2, (_DWORD *)(v2 + 4 * (v0 & 0xFFF)), v1);
    }
    JUMPOUT(0x49B65C);
  }
  JUMPOUT(0x49B65A);
}
