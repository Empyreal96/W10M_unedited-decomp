// FsRtlpCancelExclusiveIrp 
 
int __fastcall FsRtlpCancelExclusiveIrp(int a1, int a2, int a3, int a4)
{
  _DWORD *v6; // r8
  unsigned int *v7; // r4
  unsigned int v8; // r5
  int result; // r0
  unsigned int v10; // r5
  int v11; // r4
  int v12; // r9
  unsigned int v13; // r2
  unsigned int *v14; // r4
  unsigned int v15; // r5
  unsigned int v16; // r1
  int varg_r1a; // [sp+2Ch] [bp+Ch]
  char varg_r1; // [sp+2Ch] [bp+Ch]
  int varg_r2; // [sp+30h] [bp+10h]

  varg_r1a = a2;
  varg_r2 = a3;
  varg_r1 = a2;
  v6 = *(_DWORD **)(a1 + 28);
  __dmb(0xBu);
  v7 = (unsigned int *)(a1 + 56);
  do
    v8 = __ldrex(v7);
  while ( __strex(0, v7) );
  __dmb(0xBu);
  result = KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(a1 + 37));
  if ( !a2 )
  {
    v10 = v6[19];
    v11 = KeAbPreAcquire(v10, 0, 0);
    result = KfRaiseIrql(1);
    v12 = result;
    do
      v13 = __ldrex((unsigned __int8 *)v10);
    while ( __strex(v13 & 0xFE, (unsigned __int8 *)v10) );
    __dmb(0xBu);
    if ( (v13 & 1) == 0 )
      result = ExpAcquireFastMutexContended(v10, v11);
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    *(_DWORD *)(v10 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v10 + 28) = v12;
  }
  if ( *v6 )
  {
    if ( *(_BYTE *)(*v6 + 36) )
    {
      FsRtlpModifyThreadPriorities(v6, 0, 0);
      FsRtlpClearOwnerThread((int)v6, 0);
      *((_BYTE *)v6 + 16) = 0;
      *(_DWORD *)(*v6 + 24) = -1073741536;
      pIofCompleteRequest(*v6, 1);
      *v6 = 0;
      result = ObfDereferenceObjectWithTag(v6[1]);
      v6[1] = 0;
      v6[18] = v6[18] & 0x20 | 1;
      if ( a3 )
      {
        while ( (_DWORD *)v6[11] != v6 + 11 )
          result = FsRtlpRemoveAndCompleteWaitingIrp(v6[11]);
      }
    }
  }
  if ( !varg_r1 )
  {
    v14 = (unsigned int *)v6[19];
    v14[1] = 0;
    v15 = v14[7];
    __dmb(0xBu);
    do
      v16 = __ldrex(v14);
    while ( !v16 && __strex(1u, v14) );
    if ( v16 )
      ExpReleaseFastMutexContended(v14, v16);
    KfLowerIrql((unsigned __int8)v15);
    result = KeAbPostRelease((unsigned int)v14);
  }
  return result;
}
