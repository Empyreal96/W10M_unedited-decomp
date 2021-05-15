// MiArmWritePdeOtherProcess 
 
int __fastcall MiArmWritePdeOtherProcess(int a1, _DWORD *a2, int a3, int a4)
{
  int result; // r0
  _DWORD *varg_r1; // [sp+14h] [bp+Ch]

  varg_r1 = a2;
  result = MiArmWriteConvertedHardwarePde(
             *(_DWORD *)(a1 + 32),
             *(_DWORD *)(a1 + 32) + 4 * ((unsigned __int16)a2 & 0xFFF),
             a3);
  __dmb(0xBu);
  *a2 = a3;
  return result;
}
