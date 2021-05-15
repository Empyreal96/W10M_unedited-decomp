// IoQuerySystemDeviceName 
 
int __fastcall IoQuerySystemDeviceName(int a1, int a2, int a3, unsigned int a4)
{
  int v5; // r4
  int v6; // r5

  if ( a1 != 98 )
    return sub_8156E8();
  v5 = IopRetrieveSystemDeviceName(SyspartDirectGetSystemPartition, a2, a3, a4);
  if ( v5 == -1073740718 && IopAmbiguousSystemDisk )
  {
    v6 = IopFindSystemDevice();
    if ( v6 >= 0 )
      ExFreePoolWithTag(a4);
    if ( v6 == -1073740718 )
      v5 = -1073740719;
  }
  return v5;
}
