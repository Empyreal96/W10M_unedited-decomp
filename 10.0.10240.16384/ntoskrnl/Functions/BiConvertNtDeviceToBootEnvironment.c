// BiConvertNtDeviceToBootEnvironment 
 
int __fastcall BiConvertNtDeviceToBootEnvironment(int *a1, unsigned int a2, int a3, int *a4)
{
  int v5; // r0
  int v7; // r5
  int v10; // r4
  int v11; // [sp+Ch] [bp-24h] BYREF
  char v12[32]; // [sp+10h] [bp-20h] BYREF

  v5 = *a1;
  v7 = 0;
  v11 = 0;
  if ( v5 != 2 )
    return sub_813024();
  if ( a2 < 0x16 )
  {
    v10 = -1073741811;
  }
  else
  {
    if ( !BiIsVolumePartitionInformationRetained(a1 + 5) )
      JUMPOUT(0x81308A);
    v10 = BiCreatePartitionDevice(a1 + 5, a3, &v11, v12);
    v7 = v11;
    if ( v10 >= 0 )
      v10 = 0;
  }
  *a4 = v7;
  return v10;
}
