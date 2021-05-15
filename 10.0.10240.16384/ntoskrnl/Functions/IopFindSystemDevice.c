// IopFindSystemDevice 
 
int __fastcall IopFindSystemDevice(int a1, int *a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r4
  int v7; // r5
  int v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[0] = a4;
  v5 = SiGetSystemDeviceName(
         (int (__fastcall *)(int, unsigned __int16 **))SiGetSystemDisk,
         0,
         0,
         (unsigned __int16 *)v9);
  v6 = v5;
  if ( v5 == -1073741789 )
  {
    v7 = ExAllocatePoolWithTag(1, v9[0], 1146318665);
    if ( v7 )
    {
      v6 = SiGetSystemDeviceName(
             (int (__fastcall *)(int, unsigned __int16 **))SiGetSystemDisk,
             v7,
             v9[0],
             (unsigned __int16 *)v9);
      if ( v6 >= 0 )
        *a2 = v7;
      else
        ExFreePoolWithTag(v7);
    }
    else
    {
      v6 = -1073741670;
    }
  }
  else if ( v5 >= 0 )
  {
    v6 = -1073741595;
  }
  return v6;
}
