// IopQueryXxxInformation 
 
int __fastcall IopQueryXxxInformation(_DWORD *a1, unsigned int a2, unsigned int a3, char a4, int a5, _DWORD *a6, char a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15)
{
  unsigned __int64 v16; // r8
  signed int v18; // r0
  int v20; // r5
  int v21; // r2
  char v22; // r3
  int v23; // r5
  int v24; // r0
  int v25; // r4
  int v26; // [sp+10h] [bp-38h] BYREF
  int v27; // [sp+14h] [bp-34h]
  char var30[52]; // [sp+18h] [bp-30h] BYREF

  v26 = 0;
  v27 = 0;
  v16 = __PAIR64__(a2, a3);
  v18 = ObfReferenceObject((int)a1);
  if ( (a1[11] & 2) != 0 )
    return sub_7E6F04(v18);
  KeInitializeEvent((int)var30, 1, 0);
  v20 = IoGetRelatedDeviceObject(a1);
  v24 = pIoAllocateIrp(v20, *(char *)(v20 + 48), 1, a15);
  v25 = v24;
  if ( v24 )
  {
    *(_DWORD *)(v24 + 100) = a1;
    *(_DWORD *)(v24 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_BYTE *)(v24 + 32) = a4;
    *(_DWORD *)(v24 + 44) = var30;
    *(_DWORD *)(v24 + 8) = 4;
    *(_DWORD *)(v24 + 48) = 0;
    v21 = *(_DWORD *)(v24 + 96);
    *(_DWORD *)(v24 + 40) = &v26;
    if ( a7 )
      v22 = 5;
    else
      v22 = 10;
    *(_BYTE *)(v21 - 40) = v22;
    *(_DWORD *)(v21 - 12) = a1;
    *(_DWORD *)(v24 + 12) = a5;
    *(_DWORD *)(v24 + 8) |= 0x10u;
    *(_QWORD *)(v21 - 32) = v16;
    IopQueueThreadIrp(v24);
    v23 = IofCallDriver(v20, v25);
    if ( v23 == 259 )
    {
      KeWaitForSingleObject((unsigned int)var30, 0, 0, 0, 0);
      v23 = v26;
    }
    *a6 = v27;
  }
  else
  {
    IopAllocateIrpCleanup(a1, 0);
    v23 = -1073741670;
  }
  return v23;
}
