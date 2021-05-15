// MmMapIoSpaceEx 
 
int __fastcall MmMapIoSpaceEx(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v6; // r0
  int v7; // r1
  int result; // r0
  int varg_r2; // [sp+20h] [bp+10h]

  varg_r2 = a3;
  v4 = a1;
  v6 = MiMakeProtectionMask(a4);
  if ( (v6 & 2) != 0 )
    result = sub_509D64();
  else
    result = MiMapContiguousMemory(v4, v7, a3, v6);
  return result;
}
