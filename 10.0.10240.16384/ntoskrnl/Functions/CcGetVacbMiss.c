// CcGetVacbMiss 
 
int __fastcall CcGetVacbMiss(int a1, int a2, int a3, int a4, int a5, int a6)
{
  signed __int64 v6; // r8
  int v8; // r10
  unsigned __int8 *v9; // r7
  int v10; // r4
  int v12; // r5
  int v13; // r10
  int v14; // r0
  int v15; // r1
  int v16; // r4
  unsigned int v17; // r2
  int v18; // r7
  unsigned int *v19; // r2
  unsigned int v20; // r1
  unsigned int v21; // r1
  int v22; // r1
  unsigned int v23; // r0
  unsigned int v24; // r2
  unsigned int *v25; // r4
  int v26; // r7
  unsigned int v27; // r1
  unsigned __int8 *v28; // r7
  int v29; // r4
  int v30; // r8
  unsigned int v31; // r2
  unsigned int *v32; // r2
  unsigned int v33; // r1
  unsigned int v34; // r1
  unsigned int *v35; // r4
  int v36; // r1
  unsigned int v37; // r0
  unsigned int v38; // r2
  int v39; // r4
  int v40; // r4
  int v41; // r2
  int v42; // r1
  unsigned int v43; // r0
  unsigned int v44; // r2
  unsigned int *v45; // r4
  int v46; // r7
  unsigned int v47; // r1
  int v48; // r4
  unsigned int *v49; // r4
  int v50; // r10
  unsigned int v51; // r1
  int v52; // [sp+10h] [bp-38h]
  unsigned __int64 v53; // [sp+18h] [bp-30h] BYREF
  unsigned __int64 v54[5]; // [sp+20h] [bp-28h] BYREF
  int varg_r0; // [sp+50h] [bp+8h]
  int varg_r1; // [sp+54h] [bp+Ch]
  int varg_r2; // [sp+58h] [bp+10h]
  int varg_r3; // [sp+5Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  LODWORD(v6) = a3 - (a3 & 0x3FFFF);
  v53 = __PAIR64__(a4, v6);
  HIDWORD(v6) = a4;
  varg_r2 = a3;
  varg_r3 = a4;
  v8 = 0;
  v9 = (unsigned __int8 *)(a1 + 72);
  while ( 1 )
  {
    v10 = KeAcquireQueuedSpinLock(4);
    if ( v8 )
      return sub_53BDB4();
    v12 = CcGetVacbFromFreeList(0);
    KeReleaseQueuedSpinLock(4, v10);
    if ( v12 )
      break;
    while ( CcUnmapInactiveViews(64, 0, 0) )
    {
      v40 = KeAcquireQueuedSpinLock(4);
      v12 = CcGetVacbFromFreeList(0);
      KeReleaseQueuedSpinLock(4, v40);
      if ( v12 )
        goto LABEL_5;
    }
    v41 = a6;
    if ( a6 == 1 )
      ++CcDbgNumberOfFailedHighPriorityMappingsDueToCcResources;
    v13 = -1073741670;
LABEL_100:
    if ( v41 != 1 )
      RtlRaiseStatus(v13);
    v8 = 1;
  }
LABEL_5:
  v54[0] = *(_QWORD *)(a1 + 24) - v6;
  if ( v54[0] > 0x40000 )
    LODWORD(v54[0]) = 0x40000;
  v13 = MmMapViewInSystemCache(*(_DWORD *)(a1 + 108), (unsigned int *)v12, &v53, v54);
  v52 = v13;
  if ( a5 )
  {
    v28 = (unsigned __int8 *)(a1 + 180);
    v29 = KeAbPreAcquire(a1 + 180, 0, 0);
    v30 = KfRaiseIrql(1);
    do
      v31 = __ldrex(v28);
    while ( __strex(v31 & 0xFE, v28) );
    __dmb(0xBu);
    if ( (v31 & 1) == 0 )
      ExpAcquireFastMutexContended(a1 + 180, v29);
    if ( v29 )
      *(_BYTE *)(v29 + 14) |= 1u;
    *(_DWORD *)(a1 + 184) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(a1 + 208) = v30;
    v9 = (unsigned __int8 *)(a1 + 72);
  }
  v14 = KeAbPreAcquire((unsigned int)v9, 0, 0);
  v16 = v14;
  do
    v17 = __ldrex(v9);
  while ( __strex(v17 | 1, v9) );
  __dmb(0xBu);
  if ( (v17 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v9, v14, v9);
  if ( v16 )
    *(_BYTE *)(v16 + 14) |= 1u;
  v6 = v53;
  if ( *(__int64 *)(a1 + 24) > 0x2000000 )
    v18 = CcGetVacbLargeOffset(a1, v15, v53, HIDWORD(v53));
  else
    v18 = *(_DWORD *)(*(_DWORD *)(a1 + 64) + 4 * ((unsigned int)v53 >> 18));
  if ( !v18 )
  {
    if ( v13 < 0 )
      goto LABEL_76;
    if ( !SetVacb(a1, v15, v6, SHIDWORD(v6), v12) )
    {
      v13 = -1073741670;
      CcUnmapVacb(v12, a1, 0);
      goto LABEL_76;
    }
  }
  if ( v13 >= 0 )
  {
    if ( v18 )
    {
      __dmb(0xBu);
      v32 = (unsigned int *)(v18 + 8);
      do
      {
        v33 = __ldrex(v32);
        v34 = v33 + 1;
      }
      while ( __strex(v34, v32) );
      __dmb(0xBu);
      if ( !(_WORD)v34 )
        KeBugCheckEx(52, 2410, -1073740768);
      v35 = (unsigned int *)(a1 + 72);
      __pld((void *)(a1 + 72));
      v36 = *(_DWORD *)(a1 + 72);
      if ( (v36 & 0xFFFFFFF0) > 0x10 )
        v37 = v36 - 16;
      else
        v37 = 0;
      if ( (v36 & 2) != 0 )
        goto LABEL_67;
      __dmb(0xBu);
      do
        v38 = __ldrex(v35);
      while ( v38 == v36 && __strex(v37, v35) );
      if ( v38 != v36 )
LABEL_67:
        ExfReleasePushLock(a1 + 72);
      KeAbPostRelease(a1 + 72);
      if ( a5 )
      {
        v49 = (unsigned int *)(a1 + 180);
        v50 = *(_DWORD *)(a1 + 208);
        *(_DWORD *)(a1 + 184) = 0;
        __dmb(0xBu);
        do
          v51 = __ldrex(v49);
        while ( !v51 && __strex(1u, v49) );
        if ( v51 )
          ExpReleaseFastMutexContended((unsigned int *)(a1 + 180), v51);
        KfLowerIrql((unsigned __int8)v50);
        KeAbPostRelease(a1 + 180);
        v13 = v52;
      }
      CcUnmapVacb(v12, a1, 0);
      v39 = KeAcquireQueuedSpinLock(4);
      CcSetVacbInFreeList(v12, 0);
      KeReleaseQueuedSpinLock(4, v39);
      v12 = v18;
    }
    else
    {
      if ( *(_DWORD *)(v12 + 4) != -1 )
        KeBugCheckEx(52, 1857, -1073740768);
      *(_DWORD *)(v12 + 4) = a1;
      *(_QWORD *)(v12 + 8) = v6;
      __dmb(0xBu);
      v19 = (unsigned int *)(v12 + 8);
      do
      {
        v20 = __ldrex(v19);
        v21 = v20 + 1;
      }
      while ( __strex(v21, v19) );
      __dmb(0xBu);
      if ( !(_WORD)v21 )
        KeBugCheckEx(52, 2410, -1073740768);
      if ( v6 >= *(_QWORD *)(a1 + 240) )
        *(_QWORD *)(a1 + 240) = v6 + 0x40000;
      v9 = (unsigned __int8 *)(a1 + 72);
      __pld((void *)(a1 + 72));
      v22 = *(_DWORD *)(a1 + 72);
      if ( (v22 & 0xFFFFFFF0) > 0x10 )
        v23 = v22 - 16;
      else
        v23 = 0;
      if ( (v22 & 2) != 0 )
        goto LABEL_65;
      __dmb(0xBu);
      do
        v24 = __ldrex((unsigned int *)v9);
      while ( v24 == v22 && __strex(v23, (unsigned int *)v9) );
      if ( v24 != v22 )
LABEL_65:
        ExfReleasePushLock(a1 + 72);
      KeAbPostRelease(a1 + 72);
      if ( !a5 )
        goto LABEL_35;
      v25 = (unsigned int *)(a1 + 180);
      v26 = *(_DWORD *)(a1 + 208);
      *(_DWORD *)(a1 + 184) = 0;
      __dmb(0xBu);
      do
        v27 = __ldrex(v25);
      while ( !v27 && __strex(1u, v25) );
      if ( v27 )
        ExpReleaseFastMutexContended((unsigned int *)(a1 + 180), v27);
      KfLowerIrql((unsigned __int8)v26);
      KeAbPostRelease(a1 + 180);
    }
    v9 = (unsigned __int8 *)(a1 + 72);
    goto LABEL_35;
  }
LABEL_76:
  v9 = (unsigned __int8 *)(a1 + 72);
  __pld((void *)(a1 + 72));
  v42 = *(_DWORD *)(a1 + 72);
  if ( (v42 & 0xFFFFFFF0) <= 0x10 )
    v43 = 0;
  else
    v43 = v42 - 16;
  if ( (v42 & 2) != 0 )
    goto LABEL_84;
  __dmb(0xBu);
  do
    v44 = __ldrex((unsigned int *)v9);
  while ( v44 == v42 && __strex(v43, (unsigned int *)v9) );
  if ( v44 != v42 )
LABEL_84:
    ExfReleasePushLock(a1 + 72);
  KeAbPostRelease(a1 + 72);
  if ( a5 )
  {
    v45 = (unsigned int *)(a1 + 180);
    v46 = *(_DWORD *)(a1 + 208);
    *(_DWORD *)(a1 + 184) = 0;
    __dmb(0xBu);
    do
      v47 = __ldrex(v45);
    while ( !v47 && __strex(1u, v45) );
    if ( v47 )
      ExpReleaseFastMutexContended((unsigned int *)(a1 + 180), v47);
    KfLowerIrql((unsigned __int8)v46);
    KeAbPostRelease(a1 + 180);
    v9 = (unsigned __int8 *)(a1 + 72);
  }
  *(_DWORD *)v12 = 0;
  v48 = KeAcquireQueuedSpinLock(4);
  CcSetVacbInFreeList(v12, 0);
  KeReleaseQueuedSpinLock(4, v48);
  v12 = 0;
  v13 = FsRtlNormalizeNtstatus(v13, -1073741589);
LABEL_35:
  if ( v13 < 0 )
  {
    v41 = a6;
    goto LABEL_100;
  }
  return v12;
}
