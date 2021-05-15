// IopDeleteFile 
 
_DWORD *__fastcall IopDeleteFile(int a1)
{
  _DWORD *result; // r0
  _DWORD *v3; // r5
  int v4; // r0
  int v5; // r9
  _DWORD *v6; // r6
  int v7; // r3
  unsigned int v8; // r1
  int v9; // r7
  int v10; // r0
  int v11; // r8
  int *v12; // r3
  unsigned int v13; // r6
  unsigned int v14; // [sp+8h] [bp-40h] BYREF
  char v15; // [sp+10h] [bp-38h] BYREF
  char v16[48]; // [sp+18h] [bp-30h] BYREF

  result = *(_DWORD **)(a1 + 4);
  v3 = 0;
  if ( result )
  {
    if ( (*(_DWORD *)(a1 + 44) & 0x800) != 0 )
      v4 = IoGetAttachedDevice((int)result);
    else
      v4 = IoGetRelatedDeviceObject((_DWORD *)a1);
    v5 = v4;
    if ( (*(_DWORD *)(a1 + 44) & 0x240000) == 0 )
      return (_DWORD *)sub_7FB364();
    KeInitializeEvent((int)v16, 1, 0);
    if ( (*(_DWORD *)(a1 + 44) & 0x4000000) == 0 )
      KeResetEvent(a1 + 92);
    v6 = (_DWORD *)IopAllocateIrpMustSucceed(v5, *(_BYTE *)(v5 + 48));
    v7 = v6[24];
    *(_BYTE *)(v7 - 40) = 2;
    *(_DWORD *)(v7 - 12) = a1;
    v6[10] = &v15;
    v6[11] = v16;
    v6[25] = a1;
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v6[2] = 1028;
    v6[20] = v8;
    v6[3] = 0;
    IopQueueThreadIrp((int)v6);
    v9 = *(_DWORD *)(a1 + 8);
    if ( v9 )
    {
      if ( (*(_DWORD *)(a1 + 44) & 0x800) == 0 )
      {
        IopDecrementVpbRefCount(*(_DWORD *)(a1 + 8), 1);
        v3 = *(_DWORD **)(v9 + 8);
        if ( v3 )
          IopIncrementDeviceObjectRefCount(*(_DWORD *)(v9 + 8), 1);
      }
    }
    v10 = *(_DWORD *)(a1 + 4);
    if ( (*(_DWORD *)(v10 + 28) & 0x400) != 0 )
    {
      IopDecrementDeviceObjectRefCount(v10, 1);
      v11 = 1;
    }
    else
    {
      v11 = 0;
    }
    if ( IofCallDriver(v5, (int)v6) == 259 )
      KeWaitForSingleObject((unsigned int)v16, 0, 0, 0, 0);
    v6[20] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    IopDequeueIrpFromThread(v6);
    IoFreeIrp((int)v6);
    if ( *(_WORD *)(a1 + 48) )
      ExFreePoolWithTag(*(_DWORD *)(a1 + 52));
    v12 = *(int **)(a1 + 108);
    if ( v12 )
    {
      ObfDereferenceObject(*v12);
      ExFreePoolWithTag(*(_DWORD *)(a1 + 108));
    }
    if ( *(_DWORD *)(a1 + 124) )
    {
      IoGetFileObjectFilterContext(a1, (int *)&v14, 0);
      v13 = v14;
      if ( v14 )
      {
        IoChangeFileObjectFilterContext(a1, v14, 0);
        ExFreePoolWithTag(v13);
      }
    }
    result = *(_DWORD **)(a1 + 4);
    if ( !v11 )
      result = (_DWORD *)IopDecrementDeviceObjectRef(result, 0, *(char *)(a1 - 9) >= 0);
    if ( v3 && v9 )
    {
      if ( *(char *)(a1 - 9) >= 0 )
        result = (_DWORD *)IopDecrementDeviceObjectRef(v3, 0, 1);
      else
        result = (_DWORD *)IopDecrementDeviceObjectRef(v3, 0, 0);
    }
  }
  if ( *(_DWORD *)(a1 + 124) )
    result = (_DWORD *)IopDeleteFileObjectExtension(a1);
  return result;
}
