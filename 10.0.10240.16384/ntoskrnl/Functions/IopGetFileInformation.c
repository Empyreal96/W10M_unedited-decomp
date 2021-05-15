// IopGetFileInformation 
 
int __fastcall IopGetFileInformation(_DWORD *a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v9; // r6
  int v10; // r0
  int v11; // r4
  int v12; // r2
  int v13; // r3
  int result; // r0
  int v15; // [sp+8h] [bp-38h] BYREF
  int v16; // [sp+Ch] [bp-34h]
  char var30[52]; // [sp+10h] [bp-30h] BYREF
  int vars4; // [sp+44h] [bp+4h]

  v15 = 0;
  v16 = 0;
  ObfReferenceObject((int)a1);
  KeInitializeEvent((int)var30, 1, 0);
  v9 = IoGetRelatedDeviceObject(a1);
  v10 = pIoAllocateIrp(v9, *(char *)(v9 + 48), 0, vars4);
  v11 = v10;
  if ( !v10 )
    return sub_7C4328();
  *(_DWORD *)(v10 + 100) = a1;
  *(_DWORD *)(v10 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v10 + 44) = var30;
  *(_DWORD *)(v10 + 8) = 4100;
  v12 = *(_DWORD *)(v10 + 96);
  *(_DWORD *)(v10 + 40) = &v15;
  *(_BYTE *)(v10 + 32) = 0;
  *(_DWORD *)(v10 + 48) = 0;
  *(_BYTE *)(v12 - 40) = 5;
  *(_DWORD *)(v12 - 12) = a1;
  v13 = *(_DWORD *)(v10 + 8);
  *(_DWORD *)(v10 + 12) = a4;
  *(_DWORD *)(v10 + 8) = v13 | 0x10;
  *(_DWORD *)(v12 - 32) = a2;
  *(_DWORD *)(v12 - 28) = a3;
  IopQueueThreadIrp(v10);
  result = IofCallDriver(v9, v11);
  if ( result == 259 )
  {
    KeWaitForSingleObject((unsigned int)var30, 0, 0, 0, 0);
    result = v15;
  }
  *a5 = v16;
  return result;
}
