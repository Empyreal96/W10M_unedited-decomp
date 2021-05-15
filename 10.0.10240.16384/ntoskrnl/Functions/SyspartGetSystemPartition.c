// SyspartGetSystemPartition 
 
int __fastcall SyspartGetSystemPartition(int a1, int a2, int a3, int a4)
{
  int v7; // r0
  int result; // r0
  int v9; // [sp+0h] [bp-20h]

  v9 = a3;
  v7 = ZwQuerySystemInformation();
  if ( v7 == -1073741789 )
    result = sub_812E0C();
  else
    result = SiGetSystemDeviceName(SiGetSystemPartition, a1, a2, a3, v9, a4);
  return result;
}
