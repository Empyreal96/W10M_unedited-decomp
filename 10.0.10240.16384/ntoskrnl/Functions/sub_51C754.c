// sub_51C754 
 
void __fastcall sub_51C754(int a1, unsigned int a2, __int16 a3)
{
  unsigned int v3; // r4
  int v4; // r0

  if ( v3 <= a2 )
  {
    v4 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
    MiArmWriteConvertedHardwarePde(v4, (_DWORD *)(v4 + 4 * (v3 & 0xFFF)), a3);
  }
  JUMPOUT(0x4477D8);
}
