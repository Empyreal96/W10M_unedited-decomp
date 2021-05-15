// MiArmWriteHardwarePde 
 
int __fastcall MiArmWriteHardwarePde(int a1, __int16 a2, __int16 a3)
{
  return MiArmWriteConvertedHardwarePde(*(_DWORD *)(a1 + 32), (_DWORD *)(*(_DWORD *)(a1 + 32) + 4 * (a3 & 0xFFF)), a2);
}
