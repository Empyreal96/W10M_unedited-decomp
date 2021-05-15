// FsRtlIssueFileNotificationFsctl 
 
int __fastcall FsRtlIssueFileNotificationFsctl(_DWORD *a1, int a2, _DWORD *a3)
{
  int v5; // r7
  int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r3
  int result; // r0
  int v12; // [sp+18h] [bp-50h]
  char v13[16]; // [sp+20h] [bp-48h] BYREF
  _DWORD v14[14]; // [sp+30h] [bp-38h] BYREF

  KeInitializeEvent((int)v13, 0, 0);
  v5 = IoGetRelatedDeviceObject(a1);
  v6 = IoBuildDeviceIoControlRequest(590340, v5, 0, 0, 0, 0);
  if ( !v6 )
    return -1073741670;
  v14[0] = 1;
  v14[1] = 1;
  v7 = a3[1];
  v8 = a3[2];
  v9 = a3[3];
  v14[2] = *a3;
  v14[3] = v7;
  v14[4] = v8;
  v14[5] = v9;
  *(_DWORD *)(v6 + 12) = v14;
  v10 = *(_DWORD *)(v6 + 96);
  *(_BYTE *)(v10 - 40) = 13;
  *(_DWORD *)(v10 - 28) = 24;
  *(_DWORD *)(v10 - 12) = a1;
  result = IofCallDriver(v5, v6);
  if ( result == 259 )
  {
    KeWaitForSingleObject((unsigned int)v13, 0, 0, 0, 0);
    result = v12;
  }
  return result;
}
