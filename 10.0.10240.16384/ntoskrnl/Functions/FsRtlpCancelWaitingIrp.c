// FsRtlpCancelWaitingIrp 
 
int __fastcall FsRtlpCancelWaitingIrp(int a1, int a2)
{
  int v3; // r6
  unsigned int *v4; // r2
  unsigned int v5; // r4
  int result; // r0
  unsigned int v7; // r5
  int v8; // r4
  int v9; // r8
  unsigned int v10; // r2
  _DWORD *i; // r4
  unsigned int *v12; // r4
  unsigned int v13; // r5
  unsigned int v14; // r1
  int varsCa; // [sp+24h] [bp+Ch]
  char varsC; // [sp+24h] [bp+Ch]

  varsCa = a2;
  varsC = a2;
  v3 = *(_DWORD *)(a1 + 28);
  __dmb(0xBu);
  v4 = (unsigned int *)(a1 + 56);
  do
    v5 = __ldrex(v4);
  while ( __strex(0, v4) );
  __dmb(0xBu);
  result = KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(a1 + 37));
  if ( !a2 )
  {
    v7 = *(_DWORD *)(v3 + 76);
    v8 = KeAbPreAcquire(v7, 0, 0);
    result = KfRaiseIrql(1);
    v9 = result;
    do
      v10 = __ldrex((unsigned __int8 *)v7);
    while ( __strex(v10 & 0xFE, (unsigned __int8 *)v7) );
    __dmb(0xBu);
    if ( (v10 & 1) == 0 )
      result = ExpAcquireFastMutexContended(v7, v8);
    if ( v8 )
      *(_BYTE *)(v8 + 14) |= 1u;
    *(_DWORD *)(v7 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v7 + 28) = v9;
  }
  for ( i = *(_DWORD **)(v3 + 44); i != (_DWORD *)(v3 + 44); i = (_DWORD *)*i )
  {
    result = (int)i;
    if ( *(_BYTE *)(i[2] + 36) )
    {
      i = (_DWORD *)i[1];
      result = FsRtlpRemoveAndCompleteWaitingIrp(result);
    }
  }
  if ( !varsC )
  {
    v12 = *(unsigned int **)(v3 + 76);
    v12[1] = 0;
    v13 = v12[7];
    __dmb(0xBu);
    do
      v14 = __ldrex(v12);
    while ( !v14 && __strex(1u, v12) );
    if ( v14 )
      ExpReleaseFastMutexContended(v12, v14);
    KfLowerIrql((unsigned __int8)v13);
    result = KeAbPostRelease((unsigned int)v12);
  }
  return result;
}
