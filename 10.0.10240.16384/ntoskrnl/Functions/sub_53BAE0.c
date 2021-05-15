// sub_53BAE0 
 
void __fastcall sub_53BAE0(int a1, int a2, __int16 a3)
{
  __int16 v3; // r4
  int v4; // r0

  v4 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
  MiArmWriteConvertedHardwarePde(v4, (_DWORD *)(v4 + 4 * (v3 & 0xFFF)), a3);
  JUMPOUT(0x49D97E);
}
