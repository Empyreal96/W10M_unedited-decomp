// FstubGetDiskGeometry 
 
int __fastcall FstubGetDiskGeometry(int a1, _DWORD *a2)
{
  _DWORD *v4; // r9
  int *v6; // r8
  int v7; // r0
  unsigned int v8; // r7
  int v9; // r0
  int v10; // r6
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r3
  int v16[10]; // [sp+18h] [bp-28h] BYREF

  v4 = (_DWORD *)ExAllocatePoolWithTag(512, 24, 1651798854);
  if ( !v4 )
    return sub_7D5C50();
  v6 = (int *)ExAllocatePoolWithTag(512, 8, 1651798854);
  if ( !v6 )
  {
    v10 = -1073741670;
    goto LABEL_16;
  }
  v7 = ExAllocatePoolWithTag(512, 16, 1651798854);
  v8 = v7;
  if ( !v7 )
  {
    v10 = -1073741670;
    goto LABEL_15;
  }
  KeInitializeEvent(v7, 0, 0);
  v9 = IoBuildDeviceIoControlRequest(458752, a1, 0, 0, (int)v4, 24);
  if ( !v9 )
    goto LABEL_18;
  v10 = IofCallDriver(a1, v9);
  if ( v10 == 259 )
  {
    KeWaitForSingleObject(v8, 0, 0, 0, 0);
    v10 = *v6;
  }
  if ( v10 < 0 )
    goto LABEL_14;
  KeResetEvent(v8);
  v11 = IoBuildDeviceIoControlRequest(475228, a1, 0, 0, (int)v16, 8);
  if ( v11 )
  {
    v10 = IofCallDriver(a1, v11);
    if ( v10 == 259 )
    {
      KeWaitForSingleObject(v8, 0, 0, 0, 0);
      v10 = *v6;
    }
    if ( v10 >= 0 )
    {
      v12 = v4[1];
      v13 = v4[2];
      v14 = v4[3];
      *a2 = *v4;
      a2[1] = v12;
      a2[2] = v13;
      a2[3] = v14;
      v15 = v4[5];
      a2[4] = v4[4];
      a2[5] = v15;
      a2[6] = v16[0];
      a2[7] = v16[1];
    }
  }
  else
  {
LABEL_18:
    v10 = -1073741670;
  }
LABEL_14:
  ExFreePoolWithTag(v8);
LABEL_15:
  ExFreePoolWithTag((unsigned int)v6);
LABEL_16:
  ExFreePoolWithTag((unsigned int)v4);
  return v10;
}
