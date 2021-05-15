// FsRtlpCancelOplockRHIrp 
 
int __fastcall FsRtlpCancelOplockRHIrp(int a1, int a2, int a3, int a4)
{
  int v4; // r10
  int v6; // r8
  unsigned int *v7; // r4
  unsigned int v8; // r5
  int result; // r0
  int v10; // r9
  int v11; // r5
  int v12; // r4
  int v13; // r10
  unsigned int v14; // r2
  _DWORD *i; // r4
  unsigned int *v16; // r4
  unsigned int v17; // r5
  unsigned int v18; // r1
  int varg_r1a; // [sp+4Ch] [bp+Ch]
  char varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]

  varg_r1a = a2;
  varg_r2 = a3;
  v4 = a3;
  varg_r1 = a2;
  v6 = *(_DWORD *)(a1 + 28);
  __dmb(0xBu);
  v7 = (unsigned int *)(a1 + 56);
  do
    v8 = __ldrex(v7);
  while ( __strex(0, v7) );
  __dmb(0xBu);
  result = KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(a1 + 37));
  v10 = 0;
  if ( !a2 )
  {
    v11 = *(_DWORD *)(v6 + 76);
    v12 = KeAbPreAcquire(v11, 0, 0);
    result = KfRaiseIrql(1);
    v13 = result;
    do
      v14 = __ldrex((unsigned __int8 *)v11);
    while ( __strex(v14 & 0xFE, (unsigned __int8 *)v11) );
    __dmb(0xBu);
    if ( (v14 & 1) == 0 )
      result = ExpAcquireFastMutexContended(v11, v12);
    if ( v12 )
      *(_BYTE *)(v12 + 14) |= 1u;
    *(_DWORD *)(v11 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v11 + 28) = v13;
    v4 = a3;
  }
  for ( i = *(_DWORD **)(v6 + 28); i != (_DWORD *)(v6 + 28); i = (_DWORD *)*i )
  {
    if ( !i[7] )
    {
      if ( *(_BYTE *)(i[2] + 36) )
      {
        i = (_DWORD *)i[1];
        result = FsRtlpRemoveAndBreakRHIrp(*i, v6, 1, -1073741536, 0, 0, 0, 0);
        v10 = 1;
      }
    }
  }
  if ( v10 )
  {
    if ( v4 )
      result = FsRtlpReleaseIrpsWaitingForRH(v6);
    if ( *(_DWORD *)(v6 + 28) == v6 + 28 )
      result = FsRtlpComputeShareableOplockState(v6);
  }
  if ( !varg_r1 )
  {
    v16 = *(unsigned int **)(v6 + 76);
    v16[1] = 0;
    v17 = v16[7];
    __dmb(0xBu);
    do
      v18 = __ldrex(v16);
    while ( !v18 && __strex(1u, v16) );
    if ( v18 )
      ExpReleaseFastMutexContended(v16, v18, 1);
    KfLowerIrql((unsigned __int8)v17);
    result = KeAbPostRelease(v16);
  }
  return result;
}
