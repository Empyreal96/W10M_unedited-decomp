// IopSetRemoteLink 
 
int __fastcall IopSetRemoteLink(_DWORD *a1, int a2, int a3)
{
  int v5; // r4
  int v6; // r8
  _DWORD *v7; // r6
  int result; // r0
  int v9; // r3
  int v10; // r3
  int v11; // [sp+18h] [bp-140h]
  char v12[16]; // [sp+20h] [bp-138h] BYREF
  int v13[74]; // [sp+30h] [bp-128h] BYREF

  v5 = 0;
  KeInitializeEvent((int)v12, 0, 0);
  v6 = IoGetRelatedDeviceObject(a1);
  v7 = (_DWORD *)IoBuildDeviceIoControlRequest(1310956, v6, 0, 0, 0, 0);
  if ( !v7 )
    return -1073741670;
  if ( a3 )
  {
    v9 = *(_DWORD *)(a3 + 4);
    v5 = v9 + 8;
    if ( (unsigned int)(v9 + 8) > 0x10C )
      return -1073741789;
    memmove((int)v13, a3, v9 + 8);
    v13[0] = 0;
  }
  v7[2] |= 4u;
  v7[3] = v13;
  v10 = v7[24];
  v7[25] = a1;
  *(_DWORD *)(v10 - 12) = a1;
  *(_BYTE *)(v10 - 40) = 13;
  *(_BYTE *)(v10 - 39) = 4;
  *(_DWORD *)(v10 - 28) = v5;
  ObfReferenceObject((int)a1);
  result = IofCallDriver(v6, (int)v7);
  if ( result == 259 )
  {
    KeWaitForSingleObject((unsigned int)v12, 0, 0, 0, 0);
    result = v11;
  }
  return result;
}
