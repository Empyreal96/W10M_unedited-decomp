// FsRtlpAcknowledgeOplockBreak 
 
int __fastcall FsRtlpAcknowledgeOplockBreak(int a1, int a2, int a3, int a4, int a5)
{
  int v6; // r5
  unsigned int v7; // r9
  int v8; // r0
  int v9; // r8
  unsigned int v10; // r2
  int v11; // r10
  int v12; // r3
  unsigned int v13; // r3
  int v14; // r1
  int v15; // r0
  int v16; // r8
  unsigned int *v17; // r1
  unsigned int v18; // r0
  int v19; // r3
  unsigned int *v20; // r4
  unsigned int v21; // r1
  int v23; // [sp+4h] [bp-2Ch]
  unsigned int v25; // [sp+8h] [bp-28h]
  int varg_r1; // [sp+3Ch] [bp+Ch]
  int varg_r2; // [sp+40h] [bp+10h]
  int varg_r3; // [sp+44h] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v6 = a1;
  if ( !a1 )
  {
    *(_DWORD *)(a3 + 24) = -1073741597;
    pIofCompleteRequest(a3, 1);
    return -1073741597;
  }
  v7 = *(_DWORD *)(a1 + 76);
  v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = KeAbPreAcquire(v7, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex((unsigned __int8 *)v7);
  while ( __strex(v10 & 0xFE, (unsigned __int8 *)v7) );
  __dmb(0xBu);
  v11 = 1;
  if ( (v10 & 1) == 0 )
    ExpAcquireFastMutexContended(v7, v8);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  *(_DWORD *)(v7 + 4) = v25;
  if ( *(_DWORD *)(v6 + 4) == *(_DWORD *)(a2 + 28) )
  {
    if ( !FsRtlpOplockUpperLowerCompatible(16, a5) )
    {
      v12 = *(_DWORD *)(v6 + 72);
      if ( (v12 & 0x100) != 0 )
      {
        v13 = v12 & 0xFFFFFEFF;
        *(_DWORD *)(v6 + 72) = v13;
        *(_DWORD *)(v6 + 72) = v13 | 0x400;
      }
    }
    if ( a4 && (*(_DWORD *)(v6 + 72) & 0x100) != 0 )
    {
      *(_BYTE *)(*(_DWORD *)(a3 + 96) + 3) |= 1u;
      *(_DWORD *)(a3 + 24) = 0;
      v14 = a3 + 88;
      v15 = *(_DWORD *)(v6 + 20);
      *(_DWORD *)(a3 + 88) = v15;
      *(_DWORD *)(a3 + 92) = v6 + 20;
      if ( *(_DWORD *)(v15 + 4) != v6 + 20 )
        __fastfail(3u);
      *(_DWORD *)(v15 + 4) = v14;
      *(_DWORD *)(v6 + 20) = v14;
      *(_DWORD *)(a3 + 28) = v6;
      v11 = 0;
      v16 = 16;
      *(_BYTE *)(a3 + 37) = KeAcquireQueuedSpinLock(7);
      if ( *(_BYTE *)(a3 + 36) )
      {
        FsRtlpCancelReadOnlyOplockIrp(a3, 1);
      }
      else
      {
        __dmb(0xBu);
        v17 = (unsigned int *)(a3 + 56);
        do
          v18 = __ldrex(v17);
        while ( __strex((unsigned int)FsRtlpReadOnlyOplockIrpCancelRoutine, v17) );
        __dmb(0xBu);
        KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(a3 + 37));
      }
      v23 = 259;
      goto LABEL_28;
    }
    v19 = *(_DWORD *)(v6 + 72);
    if ( (v19 & 0x300) != 0 )
    {
      v23 = 0;
LABEL_27:
      *(_DWORD *)(a3 + 24) = 0;
      pIofCompleteRequest(a3, 1);
      v16 = 1;
LABEL_28:
      while ( *(_DWORD *)(v6 + 44) != v6 + 44 )
        FsRtlpRemoveAndCompleteWaitingIrp(*(_DWORD *)(v6 + 44));
      if ( v11 )
        ObfDereferenceObjectWithTag(*(_DWORD *)(v6 + 4));
      *(_DWORD *)(v6 + 4) = 0;
      FsRtlpModifyThreadPriorities(v6, 0, 0);
      FsRtlpClearOwnerThread(v6, 0);
      *(_BYTE *)(v6 + 16) = 0;
      *(_DWORD *)(v6 + 72) = *(_DWORD *)(v6 + 72) & 0x20 | v16;
      goto LABEL_34;
    }
    if ( (v19 & 0x400) != 0 )
    {
      v23 = 0;
      *(_DWORD *)(a3 + 28) = 8;
      goto LABEL_27;
    }
  }
  v23 = -1073741597;
  *(_DWORD *)(a3 + 24) = -1073741597;
  pIofCompleteRequest(a3, 1);
LABEL_34:
  v20 = *(unsigned int **)(a1 + 76);
  v20[1] = 0;
  __dmb(0xBu);
  do
    v21 = __ldrex(v20);
  while ( !v21 && __strex(1u, v20) );
  if ( v21 )
    ExpReleaseFastMutexContended(v20, v21);
  KeAbPostRelease((unsigned int)v20);
  return v23;
}
