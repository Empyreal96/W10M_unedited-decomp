// FsRtlPrivateFastUnlockAll 
 
int __fastcall FsRtlPrivateFastUnlockAll(int a1, int a2, int a3, int a4, char a5, int a6)
{
  int v6; // r7
  unsigned int *v8; // r4
  int v9; // r9
  unsigned int v10; // r2
  int v11; // r5
  int i; // r3
  int v13; // r10
  int v14; // r0
  int v15; // r6
  int v16; // r7
  unsigned int v17; // r0
  int *v18; // r9
  unsigned int v19; // r1
  unsigned int v20; // lr
  int *v21; // r8
  int v22; // r3
  unsigned __int64 v23; // kr00_8
  _DWORD *v24; // r5
  _DWORD *v25; // r5
  _DWORD *v26; // r7
  unsigned __int64 v27; // kr08_8
  unsigned __int64 v28; // kr10_8
  _DWORD *k; // r3
  int v30; // r6
  int v31; // r5
  unsigned int v32; // r2
  int j; // r3
  int v34; // r6
  unsigned int v35; // r2
  int l; // r3
  int v37; // r6
  int v38; // r8
  unsigned int *v39; // r2
  unsigned int v40; // r1
  int v41; // r1
  int v42; // r6
  unsigned int v43; // r2
  int v44; // [sp+8h] [bp-58h]
  int v45; // [sp+Ch] [bp-54h]
  unsigned int v49; // [sp+1Ch] [bp-44h]
  unsigned int v50; // [sp+20h] [bp-40h]
  unsigned __int64 v51; // [sp+24h] [bp-3Ch]
  int v52; // [sp+2Ch] [bp-34h] BYREF
  unsigned __int64 v53; // [sp+30h] [bp-30h] BYREF
  unsigned __int64 v54; // [sp+38h] [bp-28h] BYREF

  v6 = *(_DWORD *)(a1 + 12);
  v44 = v6;
  v52 = 0;
  if ( !v6 )
    return -1073741698;
  *(_DWORD *)(a2 + 72) = 0;
  v8 = (unsigned int *)(v6 + 16);
  v9 = KfRaiseIrql(2);
  v45 = v9;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51DDCC();
  do
    v10 = __ldrex(v8);
  while ( __strex(1u, v8) );
  __dmb(0xBu);
  if ( v10 )
    KxWaitForSpinLockAndAcquire(v6 + 16);
  v11 = *(_DWORD *)(v6 + 20);
  if ( !v11 )
  {
    if ( *(_DWORD *)(v6 + 24) )
      goto LABEL_28;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v6 + 16);
    }
    else
    {
      __dmb(0xBu);
      *v8 = 0;
    }
    KfLowerIrql(v9);
    return -1073741698;
  }
  for ( i = *(_DWORD *)(v11 + 4); i; i = *(_DWORD *)(i + 4) )
    v11 = i;
  v13 = 0;
  do
  {
    v14 = RtlRealSuccessor(v11);
    v15 = *(_DWORD *)(v11 - 16);
    v16 = v14;
    v17 = 0;
    v18 = 0;
    v19 = 0;
    v51 = 0i64;
    v54 = 0i64;
    v20 = 0;
    v49 = 0;
    v50 = 0;
    v53 = 0i64;
    v21 = (int *)(v11 - 16);
    if ( !v15 )
      goto LABEL_24;
    while ( 1 )
    {
      v22 = *(_DWORD *)(v15 + 32);
      v52 = v15;
      if ( v22 != a2 || *(_DWORD *)(v15 + 36) != a3 || a5 && *(_DWORD *)(v15 + 28) != a4 )
      {
        v21 = (int *)v15;
        goto LABEL_19;
      }
      if ( !v18 )
        v18 = v21;
      v27 = *(_QWORD *)(v15 + 40);
      if ( v27 > __PAIR64__(v49, v20) )
      {
        v49 = HIDWORD(v27);
        v50 = v27;
        v54 = v27;
      }
      if ( *v21 == *(_DWORD *)(v11 + 12) )
        *(_DWORD *)(v11 + 12) = v21;
      *v21 = *(_DWORD *)v15;
      if ( *(_DWORD *)(v44 + 12) )
        break;
      ExFreeToNPagedLookasideList(&FsRtlSharedLockLookasideList, v15);
      v20 = v50;
      v28 = v51;
      v17 = HIDWORD(v28);
      v19 = v28;
LABEL_19:
      if ( !v18 )
      {
        v23 = *(_QWORD *)(v15 + 40);
        if ( v23 > __PAIR64__(v17, v19) )
        {
          v17 = HIDWORD(v23);
          v19 = v23;
          v51 = v23;
          v53 = v23;
        }
      }
      v15 = *v21;
      if ( !*v21 )
        goto LABEL_23;
    }
    v13 = 1;
LABEL_23:
    if ( v18 )
    {
      if ( *(_DWORD *)(v11 - 16) )
      {
        FsRtlSplitLocks(v11 - 16, v18, &v54, &v53);
      }
      else
      {
        v8[1] = RtlDelete(v11);
        ExFreeToNPagedLookasideList(&FsRtlLockTreeNodeLookasideList, v11 - 16);
      }
    }
LABEL_24:
    if ( v13 )
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v8);
      }
      else
      {
        __dmb(0xBu);
        *v8 = 0;
      }
      KfLowerIrql(v45);
      (*(void (__fastcall **)(int, int))(v44 + 12))(a6, v52 + 8);
      v31 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(v8);
      }
      else
      {
        do
          v32 = __ldrex(v8);
        while ( __strex(1u, v8) );
        __dmb(0xBu);
        if ( v32 )
          KxWaitForSpinLockAndAcquire(v8);
      }
      v9 = v31;
      v45 = v31;
      ExFreeToNPagedLookasideList(&FsRtlSharedLockLookasideList, v52);
      v16 = v8[1];
      v13 = 0;
      if ( v16 )
      {
        for ( j = *(_DWORD *)(v16 + 4); j; j = *(_DWORD *)(j + 4) )
          v16 = j;
      }
    }
    else
    {
      v9 = v45;
    }
    v11 = v16;
  }
  while ( v16 );
  v6 = v44;
LABEL_28:
  v24 = (_DWORD *)v8[2];
  if ( v24 )
  {
    for ( k = (_DWORD *)v24[1]; k; k = (_DWORD *)k[1] )
      v24 = k;
    do
    {
      v30 = RtlRealSuccessor(v24);
      if ( v24[10] == a2 && v24[11] == a3 && (!a5 || v24[9] == a4) )
      {
        v8[2] = RtlDelete(v24);
        if ( *(_DWORD *)(v6 + 12) )
        {
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented(v8);
          }
          else
          {
            __dmb(0xBu);
            *v8 = 0;
          }
          KfLowerIrql(v9);
          (*(void (__fastcall **)(int, _DWORD *))(v6 + 12))(a6, v24 + 4);
          v34 = KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            KiAcquireSpinLockInstrumented(v8);
          }
          else
          {
            do
              v35 = __ldrex(v8);
            while ( __strex(1u, v8) );
            __dmb(0xBu);
            if ( v35 )
              KxWaitForSpinLockAndAcquire(v8);
          }
          v9 = v34;
          v30 = v8[2];
          if ( v30 )
          {
            for ( l = *(_DWORD *)(v30 + 4); l; l = *(_DWORD *)(l + 4) )
              v30 = l;
          }
        }
        ExFreeToNPagedLookasideList(&FsRtlExclusiveLockLookasideList, v24);
      }
      v24 = (_DWORD *)v30;
    }
    while ( v30 );
  }
  v25 = (_DWORD *)v8[3];
  v26 = v8 + 3;
  while ( v25 )
  {
    v37 = v25[3];
    v38 = *(_DWORD *)(v37 + 96);
    if ( a2 != *(_DWORD *)(v38 + 28) || a3 != IoGetRequestorProcess(v25[3]) || a5 && a4 != *(_DWORD *)(v38 + 12) )
      goto LABEL_110;
    *(_BYTE *)(v37 + 37) = KeAcquireQueuedSpinLock(7);
    __dmb(0xBu);
    v39 = (unsigned int *)(v37 + 56);
    do
      v40 = __ldrex(v39);
    while ( __strex(0, v39) );
    __dmb(0xBu);
    v41 = *(unsigned __int8 *)(v37 + 37);
    if ( *(_BYTE *)(v37 + 36) )
      v37 = 0;
    KeReleaseQueuedSpinLock(7, v41);
    if ( v37 )
    {
      *(_DWORD *)(v37 + 28) = 0;
      *v26 = *v25;
      if ( v25 == (_DWORD *)v8[4] )
        v8[4] = (unsigned int)v26;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v8);
      }
      else
      {
        __dmb(0xBu);
        *v8 = 0;
      }
      KfLowerIrql(v9);
      FsRtlCompleteLockIrpReal(*(_DWORD *)(v44 + 8), v25[2], v37, -1073741698, &v52, 0);
      v42 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(v8);
      }
      else
      {
        do
          v43 = __ldrex(v8);
        while ( __strex(1u, v8) );
        __dmb(0xBu);
        if ( v43 )
          KxWaitForSpinLockAndAcquire(v8);
      }
      v9 = v42;
      v26 = v8 + 3;
      ExFreeToNPagedLookasideList(&FsRtlWaitingLockLookasideList, v25);
    }
    else
    {
LABEL_110:
      v26 = v25;
    }
    v25 = (_DWORD *)*v26;
  }
  FsRtlPrivateCheckWaitingLocks(v44, v8, v9);
  FsRtlPrivateResetLowestLockOffset(v44);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v8);
  }
  else
  {
    __dmb(0xBu);
    *v8 = 0;
  }
  KfLowerIrql(v9);
  return 0;
}
