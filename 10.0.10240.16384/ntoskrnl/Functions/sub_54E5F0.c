// sub_54E5F0 
 
void sub_54E5F0()
{
  unsigned int v0; // r4
  unsigned int v1; // r10
  int v2; // r0

  if ( v0 <= v1 )
  {
    v2 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
    MiArmWriteConvertedHardwarePde(v2, (_DWORD *)(v2 + 4 * (v0 & 0xFFF)), 0);
  }
  JUMPOUT(0x4E6A74);
}
