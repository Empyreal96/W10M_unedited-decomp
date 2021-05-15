// CmpTransMgrPrepare 
 
int __fastcall CmpTransMgrPrepare(int a1, int a2, _DWORD *a3, _BYTE *a4)
{
  int v6; // r6
  unsigned int v7; // r5
  int v8; // r0
  int v9; // r8
  unsigned int v10; // r5
  unsigned int v11; // r1
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  _DWORD *v15; // r5
  int v16; // r0
  int v17; // r4
  unsigned int *v18; // r5
  unsigned int v19; // r0
  unsigned int v20; // r1
  int v21; // r7
  int v22; // r0
  unsigned int v23; // r4
  unsigned int v24; // r1
  unsigned int *v25; // r0
  int i; // r0
  int v27; // r0
  int v28; // r2
  int v29; // r4
  _DWORD *v30; // r4
  int v31; // r3
  unsigned int v32; // r7
  unsigned int v33; // r8
  int v34; // r0
  int v35; // r5
  unsigned int v36; // r2
  int v37; // r0
  unsigned int *v38; // r5
  int v39; // r7
  unsigned int v40; // r1
  unsigned int v41; // r4
  unsigned int v42; // r1
  unsigned int v44; // [sp+0h] [bp-28h]
  _BYTE *v45; // [sp+4h] [bp-24h] BYREF
  _DWORD *v46; // [sp+8h] [bp-20h]

  *a4 = 0;
  *a3 = 0;
  v45 = a4;
  v46 = a3;
  v6 = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = KeAbPreAcquire((unsigned int)&CmpTransactionListLock, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex((unsigned __int8 *)&CmpTransactionListLock);
  while ( __strex(v10 & 0xFE, (unsigned __int8 *)&CmpTransactionListLock) );
  __dmb(0xBu);
  if ( (v10 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&CmpTransactionListLock, v8);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  dword_632184 = v44;
  *(_DWORD *)(a2 + 64) |= 1u;
  dword_632184 = 0;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&CmpTransactionListLock);
  while ( !v11 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
  if ( v11 )
    ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v11);
  v12 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    KiCheckForKernelApcDelivery(v12);
  if ( *(_DWORD *)(a2 + 8) == a2 + 8 )
  {
    v6 = 0;
    *v45 = 1;
    return v6;
  }
  CmpLockRegistry();
  v15 = v46;
  v45 = 0;
  while ( 1 )
  {
    v16 = CmListGetNextElement(a2 + 8, &v45, 0);
    if ( !v16 )
      break;
    if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v16 + 24) + 20) + 3256) == a1 )
      ++*v15;
  }
  v17 = *(_DWORD *)(a1 + 48);
  if ( v17 )
  {
    v18 = (unsigned int *)(v17 + 1832);
    __pld((void *)(v17 + 1832));
    v19 = *(_DWORD *)(v17 + 1832) & 0xFFFFFFFE;
    do
      v20 = __ldrex(v18);
    while ( v20 == v19 && __strex(v19 + 2, v18) );
    __dmb(0xBu);
    if ( v20 == v19 )
      v21 = 1;
    else
      v21 = ExfAcquireRundownProtection((_DWORD *)(v17 + 1832));
    CmpUnlockRegistry();
    if ( v21 )
    {
      v22 = CmpTransMgrSyncHive(v17);
      __pld(v18);
      v6 = v22;
      v23 = *v18 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v24 = __ldrex(v18);
      while ( v24 == v23 && __strex(v23 - 2, v18) );
      if ( v24 != v23 )
      {
        v25 = v18;
        goto LABEL_35;
      }
    }
    return v6;
  }
  for ( i = 0; ; i = v29 )
  {
    v27 = CmpGetNextActiveHive(i);
    v29 = v27;
    if ( !v27 )
    {
      v30 = off_60E8A4;
      v31 = *(_DWORD *)(*((_DWORD *)off_60E8A4 + 8) + 144);
      if ( (v31 & 1) != 0 )
      {
        CmpUnlockRegistry();
        return v6;
      }
      ExAcquireResourceExclusiveLite(*((_DWORD *)off_60E8A4 + 468), 1, v28, v31);
      v32 = v30[467];
      v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v34 = KeAbPreAcquire(v32, 0, 0);
      v35 = v34;
      do
        v36 = __ldrex((unsigned __int8 *)v32);
      while ( __strex(v36 & 0xFE, (unsigned __int8 *)v32) );
      __dmb(0xBu);
      if ( (v36 & 1) == 0 )
        ExpAcquireFastMutexContended(v32, v34);
      if ( v35 )
        *(_BYTE *)(v35 + 14) |= 1u;
      *(_DWORD *)(v32 + 4) = v33;
      v37 = HvpMarkDirty((int)v30, 0, 0x20u);
      v38 = (unsigned int *)v30[467];
      v39 = v37;
      v38[1] = 0;
      __dmb(0xBu);
      do
        v40 = __ldrex(v38);
      while ( !v40 && __strex(1u, v38) );
      if ( v40 )
        ExpReleaseFastMutexContended(v38, v40);
      KeAbPostRelease((unsigned int)v38);
      if ( v39 )
      {
        *(_DWORD *)(v30[8] + 144) |= 1u;
        ExReleaseResourceLite(v30[468]);
        CmpUnlockRegistry();
        if ( CmpFlushHive((int)v30, 0) >= 0 )
          return v6;
      }
      else
      {
        ExReleaseResourceLite(v30[468]);
        CmpUnlockRegistry();
      }
      return -1073741670;
    }
    if ( *(_DWORD *)(v27 + 3256) == a1 && (*(_DWORD *)(v27 + 92) & 2) == 0 && CmpIsHiveBoundToTrans(v27, a2) == 1 )
      break;
LABEL_42:
    ;
  }
  CmpUnlockRegistry();
  v6 = CmpTransMgrSyncHive(v29);
  if ( v6 >= 0 )
  {
    CmpLockRegistry();
    goto LABEL_42;
  }
  v25 = (unsigned int *)(v29 + 1832);
  __pld((void *)(v29 + 1832));
  v41 = *(_DWORD *)(v29 + 1832) & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v42 = __ldrex(v25);
  while ( v42 == v41 && __strex(v41 - 2, v25) );
  if ( v42 != v41 )
LABEL_35:
    ExfReleaseRundownProtection((unsigned __int8 *)v25);
  return v6;
}
