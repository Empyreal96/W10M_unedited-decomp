// sub_542568 
 
void __fastcall sub_542568(unsigned int a1, unsigned int a2, __int16 a3)
{
  int v3; // r0

  if ( a2 <= a1 )
  {
    v3 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
    MiArmWriteConvertedHardwarePde(v3, (_DWORD *)(v3 + 4 * (a2 & 0xFFF)), a3);
  }
  JUMPOUT(0x4B4508);
}
