// IoVolumeDeviceToDosName 
 
int __fastcall IoVolumeDeviceToDosName(int a1, unsigned __int16 *a2)
{
  int v5; // r0
  int v6; // r4
  int v7; // r0
  int v8; // r4
  _DWORD *v9; // r5
  int v10; // r0
  int v11; // r3
  unsigned int v12; // r2
  int v13; // [sp+18h] [bp-258h] BYREF
  int v14; // [sp+20h] [bp-250h]
  char v15[16]; // [sp+28h] [bp-248h] BYREF
  int v16; // [sp+38h] [bp-238h] BYREF
  char v17[8]; // [sp+40h] [bp-230h] BYREF
  int v18; // [sp+48h] [bp-228h] BYREF
  char v19[544]; // [sp+50h] [bp-220h] BYREF

  if ( *(_DWORD *)(a1 + 44) != 7 )
    return sub_7D59CC();
  KeInitializeEvent((int)v15, 0, 0);
  v5 = IoBuildDeviceIoControlRequest(5046280, a1, 0, 0, (int)v19, 512);
  if ( !v5 )
    return -1073741670;
  v6 = IofCallDriver(a1, v5);
  if ( v6 == 259 )
  {
    KeWaitForSingleObject((unsigned int)v15, 0, 0, 0, 0);
    v6 = v14;
  }
  if ( v6 < 0 )
    return v6;
  RtlInitUnicodeString((unsigned int)v17, L"\\Device\\MountPointManager");
  v6 = IoGetDeviceObjectPointer(v17, 128, &v16, &v13);
  if ( v6 < 0 )
    return v6;
  KeInitializeEvent((int)v15, 0, 0);
  v7 = IoBuildDeviceIoControlRequest(7143472, v13, (int)v19, 512, (int)&v18, 8);
  if ( !v7 )
  {
LABEL_25:
    v6 = -1073741670;
    goto LABEL_20;
  }
  v6 = IofCallDriver(v13, v7);
  if ( v6 == 259 )
  {
    KeWaitForSingleObject((unsigned int)v15, 0, 0, 0, 0);
    v6 = v14;
  }
  if ( v6 < 0 && v6 != -2147483643 )
    goto LABEL_20;
  v8 = v18 + 8;
  if ( (unsigned int)(v18 + 8) <= 0xFFFF )
  {
    v9 = (_DWORD *)ExAllocatePoolWithTag(1, v18 + 8, 543437380);
    if ( v9 )
    {
      KeInitializeEvent((int)v15, 0, 0);
      v10 = IoBuildDeviceIoControlRequest(7143472, v13, (int)v19, 512, (int)v9, v8);
      if ( v10 )
      {
        v6 = IofCallDriver(v13, v10);
        if ( v6 == 259 )
        {
          KeWaitForSingleObject((unsigned int)v15, 0, 0, 0, 0);
          v6 = v14;
        }
        if ( v6 < 0 )
        {
          ExFreePoolWithTag((unsigned int)v9);
        }
        else
        {
          v11 = *v9 + 65532;
          *a2 = *(_WORD *)v9 - 4;
          v12 = *a2;
          a2[1] = v11 + 2;
          *((_DWORD *)a2 + 1) = v9;
          memmove((int)v9, (int)(v9 + 1), v12);
          v6 = 0;
          *(_WORD *)(*((_DWORD *)a2 + 1) + 2 * (*a2 >> 1)) = 0;
        }
        goto LABEL_20;
      }
      ExFreePoolWithTag((unsigned int)v9);
    }
    goto LABEL_25;
  }
  v6 = -1073741306;
LABEL_20:
  ObfDereferenceObject(v16);
  return v6;
}
