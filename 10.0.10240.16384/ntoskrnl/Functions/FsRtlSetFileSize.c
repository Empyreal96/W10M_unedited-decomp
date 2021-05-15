// FsRtlSetFileSize 
 
int __fastcall FsRtlSetFileSize(int a1, int *a2)
{
  __int64 v2; // r6
  int v3; // r4
  BOOL v4; // r0
  int v5; // r2
  int v6; // r5
  int v7; // r4
  int v9[2]; // [sp+8h] [bp-38h] BYREF
  int v10[2]; // [sp+10h] [bp-30h] BYREF
  char v11[40]; // [sp+18h] [bp-28h] BYREF

  v9[0] = 0;
  v9[1] = 0;
  HIDWORD(v2) = a1;
  v10[0] = *a2;
  v10[1] = a2[1];
  KeInitializeEvent((int)v11, 0, 0);
  LODWORD(v2) = IoGetRelatedDeviceObject((_DWORD *)HIDWORD(v2));
  v3 = IoAllocateIrpEx(v2, *(_BYTE *)(v2 + 48), 0);
  if ( !v3 )
    return -1073741670;
  v4 = IoSetThreadHardErrorMode(0);
  *(_DWORD *)(v3 + 8) = 66;
  *(_DWORD *)(v3 + 40) = v9;
  v5 = *(_DWORD *)(v3 + 96);
  *(_DWORD *)(v3 + 44) = v11;
  v6 = v4;
  *(_BYTE *)(v3 + 32) = 0;
  *(_DWORD *)(v3 + 100) = HIDWORD(v2);
  *(_DWORD *)(v3 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v3 + 12) = v10;
  *(_BYTE *)(v5 - 40) = 6;
  *(_DWORD *)(v5 - 32) = 8;
  *(_DWORD *)(v5 - 28) = 20;
  *(_QWORD *)(v5 - 16) = v2;
  v7 = IofCallDriver(v2, v3);
  if ( v7 == 259 )
    KeWaitForSingleObject((unsigned int)v11, 0, 0, 0, 0);
  if ( v7 < 0 )
    v9[0] = v7;
  IoSetThreadHardErrorMode(v6);
  return v9[0];
}
