// sub_54BDEC 
 
void sub_54BDEC()
{
  unsigned int v0; // r5
  int v1; // r0

  if ( v0 <= 0xC0300FFF )
  {
    v1 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
    MiArmWriteConvertedHardwarePde(v1, (_DWORD *)(v1 + 4 * (v0 & 0xFFF)), 0);
  }
  JUMPOUT(0x4D558E);
}
