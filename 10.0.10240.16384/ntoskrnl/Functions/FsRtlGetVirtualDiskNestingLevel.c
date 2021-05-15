// FsRtlGetVirtualDiskNestingLevel 
 
int __fastcall FsRtlGetVirtualDiskNestingLevel(int a1, int *a2, int *a3)
{
  int v4; // r6
  int v5; // r5
  int v9; // r9
  int v10; // r0
  int v11; // r0
  int v12; // r4
  unsigned int v13; // r0
  char v14[4]; // [sp+18h] [bp-58h] BYREF
  int v15; // [sp+1Ch] [bp-54h]
  int v16[2]; // [sp+20h] [bp-50h] BYREF
  int v17[4]; // [sp+28h] [bp-48h] BYREF
  int v18[14]; // [sp+38h] [bp-38h] BYREF

  v4 = 0;
  v5 = 1;
  if ( *(_DWORD *)(a1 + 44) != 7 )
    return sub_55351C();
  v14[0] = 0;
  v14[1] = 0;
  v14[2] = 4;
  v15 = 0;
  v16[1] = (int)v16;
  v16[0] = (int)v16;
  v9 = IoSetThreadHardErrorMode(0);
  v17[1] = 0;
  memset(v18, 0, 20);
  v17[0] = 1;
  v10 = IoBuildDeviceIoControlRequest(2953616, a1, (int)v17, 8, (int)v18, 20);
  if ( v10 )
  {
    v11 = IofCallDriver(a1, v10);
    v12 = v11;
    if ( v11 == 259 )
    {
      v11 = KeWaitForSingleObject((unsigned int)v14, 0, 0, 0, 0);
      v12 = v17[2];
    }
    if ( v12 >= 0 && v17[3] >= 0x14u && v18[0] == 1 )
    {
      v13 = FsRtlQueryMaximumVirtualDiskNestingLevel(v11);
      if ( v18[4] > v13 )
      {
        v4 = FsRtlQueryMaximumVirtualDiskNestingLevel(v13);
      }
      else if ( v18[4] )
      {
        v4 = v18[4];
      }
      if ( LOBYTE(v18[1]) )
        v5 = 0;
      if ( (v18[3] & 2) != 0 )
        v5 |= 2u;
    }
    else if ( v12 != -1073741670 )
    {
      v12 = 0;
    }
  }
  else
  {
    v12 = -1073741670;
  }
  *a2 = v4;
  if ( a3 )
    *a3 = v5;
  IoSetThreadHardErrorMode(v9);
  return v12;
}
