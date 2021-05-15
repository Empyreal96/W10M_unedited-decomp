// IopGetVolumeId 
 
int __fastcall IopGetVolumeId(_DWORD *a1, _DWORD *a2)
{
  int v4; // r7
  _DWORD *v5; // r0
  int v6; // r5
  int result; // r0
  int v8; // r3
  int v9; // r3
  _DWORD *v10; // r6
  int v11; // r2
  int v12; // r3
  int v13; // r4
  int v14; // [sp+18h] [bp-70h]
  char v15[16]; // [sp+20h] [bp-68h] BYREF
  _DWORD v16[22]; // [sp+30h] [bp-58h] BYREF

  KeInitializeEvent((int)v15, 0, 0);
  v4 = IoGetRelatedDeviceObject(a1);
  v5 = (_DWORD *)IoBuildDeviceIoControlRequest(0, v4, 0, 0, 0, 0);
  v6 = (int)v5;
  if ( !v5 )
    return -1073741670;
  v8 = v5[2];
  v5[25] = a1;
  v5[2] = v8 | 4;
  v5[15] = v16;
  v5[3] = v16;
  v9 = v5[24];
  *(_BYTE *)(v9 - 40) = 10;
  *(_DWORD *)(v9 - 32) = 64;
  *(_DWORD *)(v9 - 28) = 8;
  *(_DWORD *)(v9 - 12) = a1;
  ObfReferenceObject((int)a1);
  result = IofCallDriver(v4, v6);
  if ( result == 259 )
  {
    KeWaitForSingleObject((unsigned int)v15, 0, 0, 0, 0);
    result = v14;
  }
  if ( result >= 0 )
  {
    v10 = a2 + 1;
    *a2 = 0;
    v11 = v16[1];
    v12 = v16[2];
    v13 = v16[3];
    *v10 = v16[0];
    v10[1] = v11;
    v10[2] = v12;
    v10[3] = v13;
  }
  return result;
}
