// IopGetSetObjectId 
 
int __fastcall IopGetSetObjectId(_DWORD *a1, int a2, int a3, int a4)
{
  int v8; // r9
  _DWORD *v9; // r0
  int v10; // r4
  int v11; // r2
  int result; // r0
  int v13; // [sp+18h] [bp-38h]
  char v14[48]; // [sp+20h] [bp-30h] BYREF

  KeInitializeEvent((int)v14, 0, 0);
  v8 = IoGetRelatedDeviceObject(a1);
  v9 = (_DWORD *)IoBuildDeviceIoControlRequest(a4, v8, 0, 0, 0, 0);
  v10 = (int)v9;
  if ( !v9 )
    return -1073741670;
  v11 = v9[24];
  v9[2] |= 4u;
  v9[15] = a2;
  v9[3] = a2;
  v9[25] = a1;
  *(_BYTE *)(v11 - 40) = 13;
  *(_DWORD *)(v11 - 12) = a1;
  *(_BYTE *)(v11 - 39) = 4;
  if ( a4 == 1310952 || a4 == 590016 || a4 == 589980 )
    *(_DWORD *)(v11 - 32) = a3;
  else
    *(_DWORD *)(v11 - 28) = a3;
  ObfReferenceObject((int)a1);
  result = IofCallDriver(v8, v10);
  if ( result == 259 )
  {
    KeWaitForSingleObject((unsigned int)v14, 0, 0, 0, 0);
    result = v13;
  }
  return result;
}
