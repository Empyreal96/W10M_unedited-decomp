// PiPagePathSetState 
 
int __fastcall PiPagePathSetState(_DWORD *a1, char a2)
{
  int v4; // r6
  int v5; // r0
  int v6; // r5
  int v8; // r2
  int v9; // r1
  int v10; // r4
  int v11[2]; // [sp+8h] [bp-30h] BYREF
  char v12[40]; // [sp+10h] [bp-28h] BYREF

  v11[0] = 0;
  v11[1] = 0;
  ObfReferenceObject((int)a1);
  KeInitializeEvent((int)v12, 0, 0);
  v4 = IoGetRelatedDeviceObject(a1);
  v5 = IoAllocateIrp(*(_BYTE *)(v4 + 48), 0);
  v6 = v5;
  if ( !v5 )
    return sub_81AB24();
  *(_DWORD *)(v5 + 100) = a1;
  *(_DWORD *)(v5 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v5 + 44) = v12;
  *(_DWORD *)(v5 + 8) = 4;
  v8 = *(_DWORD *)(v5 + 96);
  *(_DWORD *)(v5 + 40) = v11;
  *(_BYTE *)(v5 + 32) = 0;
  *(_DWORD *)(v5 + 48) = 0;
  *(_BYTE *)(v8 - 40) = 27;
  *(_BYTE *)(v8 - 39) = 22;
  *(_DWORD *)(v8 - 12) = a1;
  *(_DWORD *)(v5 + 12) = 0;
  *(_DWORD *)(v5 + 24) = -1073741637;
  *(_DWORD *)(v8 - 28) = 1;
  *(_BYTE *)(v8 - 32) = a2;
  IoQueueThreadIrp(v5);
  PpDevNodeLockTree(1, v9);
  v10 = IofCallDriver(v4, v6);
  if ( v10 == 259 )
  {
    KeWaitForSingleObject((unsigned int)v12, 0, 0, 0, 0);
    v10 = v11[0];
  }
  PpDevNodeUnlockTree(1);
  return v10;
}
