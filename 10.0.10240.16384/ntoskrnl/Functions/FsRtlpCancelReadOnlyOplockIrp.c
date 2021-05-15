// FsRtlpCancelReadOnlyOplockIrp 
 
_DWORD *__fastcall FsRtlpCancelReadOnlyOplockIrp(int a1, int a2)
{
  _DWORD *v3; // r6
  unsigned int *v4; // r2
  unsigned int v5; // r4
  _DWORD *result; // r0
  int v7; // r9
  unsigned int v8; // r5
  int v9; // r4
  _DWORD *v10; // r10
  unsigned int v11; // r2
  _DWORD *i; // r4
  unsigned int *v13; // r4
  unsigned int v14; // r5
  unsigned int v15; // r1
  int varsCa; // [sp+34h] [bp+Ch]
  char varsC; // [sp+34h] [bp+Ch]

  varsCa = a2;
  varsC = a2;
  v3 = *(_DWORD **)(a1 + 28);
  __dmb(0xBu);
  v4 = (unsigned int *)(a1 + 56);
  do
    v5 = __ldrex(v4);
  while ( __strex(0, v4) );
  __dmb(0xBu);
  result = (_DWORD *)KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(a1 + 37));
  v7 = 0;
  if ( !a2 )
  {
    v8 = v3[19];
    v9 = KeAbPreAcquire(v8, 0, 0);
    result = (_DWORD *)KfRaiseIrql(1);
    v10 = result;
    do
      v11 = __ldrex((unsigned __int8 *)v8);
    while ( __strex(v11 & 0xFE, (unsigned __int8 *)v8) );
    __dmb(0xBu);
    if ( (v11 & 1) == 0 )
      result = (_DWORD *)ExpAcquireFastMutexContended(v8, v9);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
    *(_DWORD *)(v8 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v8 + 28) = v10;
  }
  for ( i = (_DWORD *)v3[5]; i != v3 + 5; i = (_DWORD *)*i )
  {
    if ( *((_BYTE *)i - 52) )
    {
      i = (_DWORD *)i[1];
      result = (_DWORD *)FsRtlpRemoveAndCompleteReadOnlyIrp(*i, -1073741536, 0);
      v7 = 1;
    }
  }
  if ( v7 )
    result = FsRtlpComputeShareableOplockState(v3);
  if ( !varsC )
  {
    v13 = (unsigned int *)v3[19];
    v13[1] = 0;
    v14 = v13[7];
    __dmb(0xBu);
    do
      v15 = __ldrex(v13);
    while ( !v15 && __strex(1u, v13) );
    if ( v15 )
      ExpReleaseFastMutexContended(v13, v15);
    KfLowerIrql((unsigned __int8)v14);
    result = (_DWORD *)KeAbPostRelease((unsigned int)v13);
  }
  return result;
}
