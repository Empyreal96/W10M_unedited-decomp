// MiSessionInsertImage 
 
int __fastcall MiSessionInsertImage(int a1, int a2)
{
  unsigned int *v3; // r9
  unsigned int *v4; // r5
  int v5; // r8
  int v7; // r6
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r0
  _DWORD *v11; // r4
  int v12; // r7
  int v13; // r7
  int v14; // r0
  _DWORD *v15; // r3
  int v16; // r2
  unsigned int *v17; // r2
  unsigned int v18; // r0
  unsigned int v19; // r1
  int v20; // r0
  int v21; // r4
  char v22[4]; // [sp+0h] [bp-70h] BYREF
  int v23; // [sp+4h] [bp-6Ch]
  int v24; // [sp+8h] [bp-68h]
  int v25[24]; // [sp+10h] [bp-60h] BYREF

  v23 = a1;
  v3 = *(unsigned int **)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
  v4 = v3 + 812;
  v5 = ExAllocatePoolWithTag(512, 48);
  if ( !v5 )
    return sub_552A44();
  v7 = *(_DWORD *)(*(_DWORD *)a2 + 4);
  if ( v7 && !MiChargeCommit((int)MiSystemPartition, *(_DWORD *)(*(_DWORD *)a2 + 4), 0) )
  {
    ExFreePoolWithTag(v5, 0);
    return -1073741670;
  }
  v24 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v3 + 812);
  }
  else
  {
    v8 = (unsigned __int8 *)v3 + 3251;
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 0x80, v8) );
    __dmb(0xBu);
    if ( v9 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v3 + 812);
    while ( 1 )
    {
      v10 = *v4;
      if ( (*v4 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v10 & 0x40000000) == 0 )
      {
        do
          v19 = __ldrex(v4);
        while ( v19 == v10 && __strex(v10 | 0x40000000, v4) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  MmLockLoadedModuleListExclusive(v22);
  v11 = (_DWORD *)v3[17];
  v12 = 0;
  if ( v11 )
  {
    v13 = v23;
    while ( 1 )
    {
      v14 = MiSessionImageCompare(v13, v11);
      if ( v14 > 0 )
      {
        v15 = (_DWORD *)v11[1];
        if ( !v15 )
        {
          v12 = 1;
          break;
        }
      }
      else
      {
        if ( v14 >= 0 )
        {
          v20 = (unsigned __int8)v22[0];
          ++v11[8];
          MmUnlockLoadedModuleListExclusive(v20);
          MiUnlockWorkingSetExclusive((int)(v3 + 812), v24);
          v21 = 272;
          ExFreePoolWithTag(v5, 0);
          if ( v7 )
            MiReturnCommit((int)MiSystemPartition, v7);
          return v21;
        }
        v15 = (_DWORD *)*v11;
        if ( !*v11 )
        {
          v12 = 0;
          break;
        }
      }
      v11 = v15;
    }
  }
  memset((_BYTE *)v5, 0, 48);
  v16 = v23;
  *(_DWORD *)(v5 + 40) = v7;
  *(_DWORD *)(v5 + 20) = v16 | 3;
  *(_DWORD *)(v5 + 24) = v16 + (v7 << 12) - 1;
  *(_DWORD *)(v5 + 32) = 1;
  *(_DWORD *)(v5 + 28) = v3[2];
  *(_DWORD *)(v5 + 44) = a2;
  RtlAvlInsertNodeEx((int)(v3 + 17), (int)v11, v12, (_DWORD *)v5);
  MmUnlockLoadedModuleListExclusive((unsigned __int8)v22[0]);
  MiUnlockWorkingSetExclusive((int)(v3 + 812), v24);
  v17 = v3 + 8;
  do
    v18 = __ldrex(v17);
  while ( __strex(v18 + v7, v17) );
  v25[0] = a2;
  MiManageSubsectionView(v25, v5 + 12, 3);
  return 0;
}
