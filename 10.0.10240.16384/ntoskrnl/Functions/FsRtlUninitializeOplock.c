// FsRtlUninitializeOplock 
 
int **__fastcall FsRtlUninitializeOplock(int **result)
{
  int *v1; // r5
  int v2; // r6
  unsigned int v3; // r8
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r2
  _DWORD *v7; // r2
  int *v8; // r3
  int v9; // r6
  int v10; // r0
  int v11; // r4
  unsigned int *v12; // r2
  unsigned int v13; // r1
  _DWORD *v14; // r2
  int *v15; // r3
  int v16; // r4
  int v17; // r6
  int v18; // r0
  unsigned int *v19; // r2
  unsigned int v20; // r1
  int v21; // r6
  int v22; // r3
  int v23; // r2
  int v24; // r3
  _DWORD *v25; // r4
  int v26; // r0
  _DWORD *v27; // r1
  int v28; // r4
  int v29; // r6
  int v30; // r4
  unsigned int *v31; // r2
  unsigned int v32; // r1
  int v33; // r4
  int v34; // r3
  int v35; // r2
  int v36; // r3
  int v37; // r0
  unsigned int *v38; // r5
  unsigned int v39; // r1
  int v40; // r0
  int *v41; // [sp+10h] [bp-20h]

  v1 = *result;
  if ( *result )
  {
    v41 = *result;
    *result = 0;
    v2 = v1[19];
    v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v4 = KeAbPreAcquire(v2, 0, 0);
    v5 = v4;
    do
      v6 = __ldrex((unsigned __int8 *)v2);
    while ( __strex(v6 & 0xFE, (unsigned __int8 *)v2) );
    __dmb(0xBu);
    if ( (v6 & 1) == 0 )
      ExpAcquireFastMutexContended(v2, v4);
    if ( v5 )
      *(_BYTE *)(v5 + 14) |= 1u;
    *(_DWORD *)(v2 + 4) = v3;
    while ( 1 )
    {
      v7 = v1 + 11;
      v8 = (int *)v1[11];
      if ( v8 == v1 + 11 )
        break;
      v9 = v1[11];
      v10 = *v8;
      if ( (_DWORD *)v8[1] != v7 || *(_DWORD *)(v10 + 4) != v1[11] )
        __fastfail(3u);
      *v7 = v10;
      *(_DWORD *)(v10 + 4) = v7;
      v11 = *(_DWORD *)(v9 + 8);
      *(_BYTE *)(v11 + 37) = KeAcquireQueuedSpinLock(7);
      __dmb(0xBu);
      v12 = (unsigned int *)(v11 + 56);
      do
        v13 = __ldrex(v12);
      while ( __strex(0, v12) );
      __dmb(0xBu);
      KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(v11 + 37));
      *(_DWORD *)(v11 + 28) = 0;
      (*(void (__fastcall **)(_DWORD, _DWORD))(v9 + 12))(*(_DWORD *)(v9 + 16), *(_DWORD *)(v9 + 8));
      ExFreePoolWithTag(v9, 0);
    }
    while ( 1 )
    {
      v14 = v1 + 5;
      v15 = (int *)v1[5];
      if ( v15 == v1 + 5 )
        break;
      v16 = v1[5];
      v17 = *(_DWORD *)(v16 + 8);
      v18 = *v15;
      if ( (_DWORD *)v15[1] != v14 || *(_DWORD *)(v18 + 4) != v1[5] )
        __fastfail(3u);
      *v14 = v18;
      *(_DWORD *)(v18 + 4) = v14;
      *(_BYTE *)(v16 - 51) = KeAcquireQueuedSpinLock(7);
      __dmb(0xBu);
      v19 = (unsigned int *)(v16 - 32);
      do
        v20 = __ldrex(v19);
      while ( __strex(0, v19) );
      __dmb(0xBu);
      KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(v16 - 51));
      ObfDereferenceObjectWithTag(*(_DWORD *)(v17 + 28));
      if ( *(_DWORD *)(v17 + 16) == 590400 )
      {
        v21 = *(_DWORD *)(v16 - 76);
        memset((_BYTE *)v21, 0, 24);
        *(_WORD *)v21 = 1;
        *(_WORD *)(v21 + 2) = 24;
        v22 = v1[18];
        if ( (v22 & 0x4000) != 0 )
          v23 = 4;
        else
          v23 = 0;
        if ( (v22 & 0x2000) != 0 )
          v24 = 2;
        else
          v24 = 0;
        *(_DWORD *)(v21 + 4) = v24 | v23 | ((v1[18] & 0x1000) != 0);
        *(_DWORD *)(v21 + 8) = 0;
        *(_DWORD *)(v16 - 60) = 24;
      }
      else
      {
        *(_DWORD *)(v16 - 60) = 8;
      }
      *(_DWORD *)(v16 - 64) = 0;
      pIofCompleteRequest(v16 - 88, 1);
    }
    while ( (int *)v1[7] != v1 + 7 )
    {
      v25 = (_DWORD *)v1[7];
      if ( (v1[18] & 0x10000) != 0 && v25[7] )
      {
        FsRtlpOplockDequeueRH(v1[7]);
        v26 = v25[7];
        v27 = (_DWORD *)v25[8];
        if ( *(_DWORD **)(v26 + 4) != v25 + 7 || (_DWORD *)*v27 != v25 + 7 )
          __fastfail(3u);
        *v27 = v26;
        *(_DWORD *)(v26 + 4) = v27;
        if ( (int *)v1[15] == v1 + 15 )
          v1[18] &= 0xFFFCFFFF;
        if ( v25[5] )
          FsRtlpClearOwnerThread(v1, v25);
        ExFreePoolWithTag(v25, 0);
      }
      else
      {
        FsRtlpRemoveAndBreakRHIrp(v25, v1, 1, 0, 0, 0, 0, 0);
      }
    }
    while ( (int *)v1[9] != v1 + 9 )
    {
      v28 = v1[9];
      FsRtlpOplockDequeueRH(v28);
      FsRtlpModifyThreadPriorities(v1, v28, 0);
      ObfDereferenceObjectWithTag(*(_DWORD *)(v28 + 12));
      FsRtlpClearOwnerThread(v1, v28);
      ExFreePoolWithTag(v28, 0);
    }
    v29 = *v1;
    if ( *v1 )
    {
      v30 = *(_DWORD *)(v29 + 96);
      *(_BYTE *)(v29 + 37) = KeAcquireQueuedSpinLock(7);
      __dmb(0xBu);
      v31 = (unsigned int *)(v29 + 56);
      do
        v32 = __ldrex(v31);
      while ( __strex(0, v31) );
      __dmb(0xBu);
      KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(v29 + 37));
      if ( *(_DWORD *)(v30 + 16) == 590400 )
      {
        v33 = *(_DWORD *)(v29 + 12);
        memset((_BYTE *)v33, 0, 24);
        *(_WORD *)v33 = 1;
        *(_WORD *)(v33 + 2) = 24;
        v34 = v1[18];
        if ( (v34 & 0x4000) != 0 )
          v35 = 4;
        else
          v35 = 0;
        if ( (v34 & 0x2000) != 0 )
          v36 = 2;
        else
          v36 = 0;
        *(_DWORD *)(v33 + 4) = v36 | v35 | ((v1[18] & 0x1000) != 0);
        *(_DWORD *)(v33 + 8) = 0;
        *(_DWORD *)(v29 + 28) = 24;
      }
      else
      {
        *(_DWORD *)(v29 + 28) = 8;
      }
      *(_DWORD *)(v29 + 24) = 0;
      pIofCompleteRequest(v29, 1);
      *v1 = 0;
      v37 = v1[1];
      if ( v37 )
        ObfDereferenceObjectWithTag(v37);
      FsRtlpModifyThreadPriorities(v1, 0, 0);
      FsRtlpClearOwnerThread(v1, 0);
    }
    v38 = (unsigned int *)v1[19];
    v38[1] = 0;
    __dmb(0xBu);
    do
      v39 = __ldrex(v38);
    while ( !v39 && __strex(1u, v38) );
    if ( v39 )
      ExpReleaseFastMutexContended(v38, v39, 1);
    KeAbPostRelease(v38);
    v40 = v41[17];
    if ( v40 )
      ExFreePoolWithTag(v40, 0);
    ExFreePoolWithTag(v41[19], 0);
    result = (int **)ExFreePoolWithTag(v41, 0);
  }
  return result;
}
