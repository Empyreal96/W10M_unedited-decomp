// MiCloneProcessAddressSpace 
 
int __fastcall MiCloneProcessAddressSpace(int a1, _DWORD *a2, int a3)
{
  char v3; // r7
  _DWORD *v4; // r8
  int v7; // r9
  _DWORD *v8; // r6
  int v9; // r7
  int v10; // r7
  int v11; // r0
  _DWORD *v12; // r4
  int v14; // r1
  int v15; // r2
  int v16; // r0
  int v17; // r3
  _DWORD *v18; // [sp+8h] [bp-50h] BYREF
  int v19; // [sp+Ch] [bp-4Ch]
  int v20; // [sp+10h] [bp-48h] BYREF
  int v21; // [sp+14h] [bp-44h]
  _DWORD *v22; // [sp+18h] [bp-40h]
  char v23[56]; // [sp+20h] [bp-38h] BYREF

  v3 = a3;
  v20 = 0;
  v21 = a3;
  v4 = 0;
  v18 = 0;
  v7 = 0;
  v8 = 0;
  v22 = *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  MiGetThreadPartition();
  MiLockDownWorkingSet((int)a2, 1);
  if ( v22 != (_DWORD *)a1 )
  {
    v7 = 1;
    KiStackAttachProcess(a1, 0, (int)v23);
  }
  if ( MEMORY[0xC0402140] && (v3 & 1) == 0 )
  {
    v9 = -1073741637;
LABEL_18:
    if ( v7 )
      KiUnstackDetachProcess((unsigned int)v23, 0);
    MiDeleteAllPartialCloneVads(a2);
    MiLockDownWorkingSet((int)a2, 0);
    return v9;
  }
  v19 = MiLockVadRange(a1, -1, 0xFFFFFFFF);
  if ( !v19 )
  {
    v9 = -1073741558;
LABEL_14:
    MiUnlockVadRange(a1, 0xFFFFFFFF, v19);
    if ( v4 )
    {
      do
      {
        v12 = (_DWORD *)*v4;
        PsReturnProcessNonPagedPoolQuota((int)a2, v4[8]);
        ExFreePoolWithTag((unsigned int)v4);
        v4 = v12;
      }
      while ( v12 );
    }
    if ( v8 )
      MiFreeCloneDescriptor(a2, v8);
    goto LABEL_18;
  }
  v9 = MiCreateCloneChain((int)a2, &v18);
  if ( v9 < 0 || (v9 = MiAllocateChildVads((int)a2, &v20), v9 < 0) )
  {
LABEL_13:
    v4 = v18;
    goto LABEL_14;
  }
  v10 = v21;
  if ( (v21 & 1) != 0 )
  {
    v11 = MiBuildNewCloneDescriptor((int)a2, 2u, MEMORY[0xC0402140], MEMORY[0xC0402144]);
    v8 = (_DWORD *)v11;
    if ( !v11 )
    {
      v9 = -1073741670;
      goto LABEL_13;
    }
    memset(*(_BYTE **)(v11 + 12), 0, 16 * *(_DWORD *)(v11 + 20));
    *(_DWORD *)(v8[3] + 8) = *(_DWORD *)(v8[3] + 8) & 0x7FFFFFF | 0x20000000;
    *(_DWORD *)(v8[3] + 24) = *(_DWORD *)(v8[3] + 24) & 0x7FFFFFF | 0x8000000;
  }
  v4 = v18;
  v9 = MiCloneVads(a1, a2, (int)v18, (int)v8, v10);
  if ( v9 < 0 )
    goto LABEL_14;
  MiUnlockVadRange(a1, 0xFFFFFFFF, v19);
  if ( v7 )
  {
    KiUnstackDetachProcess((unsigned int)v23, 0);
    v7 = 0;
  }
  if ( v22 != a2 )
  {
    v7 = 1;
    KiStackAttachProcess((int)a2, 0, (int)v23);
  }
  MiMapChildLargePageVads(a2, v20);
  MiCreateForkWsles();
  if ( v8 )
  {
    v14 = v8[5];
    v15 = 0;
    if ( !v14 )
      goto LABEL_34;
    v16 = v8[3];
    do
    {
      v17 = *(_DWORD *)(v16 + 12);
      v16 += 16;
      v15 += v17;
      --v14;
    }
    while ( v14 );
    if ( v15 )
    {
      v8[6] = v15;
      MiInsertClone((int)a2, v8);
    }
    else
    {
LABEL_34:
      MiFreeCloneDescriptor(a2, v8);
    }
  }
  MiLockDownWorkingSet((int)a2, 0);
  if ( v7 )
    KiUnstackDetachProcess((unsigned int)v23, 0);
  return 0;
}
