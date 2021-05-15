// FsRtlNumberOfRunsInLargeMcb 
 
int __fastcall FsRtlNumberOfRunsInLargeMcb(unsigned int **a1)
{
  unsigned int *v2; // r5
  int v3; // r4
  int v4; // r0
  unsigned int v5; // r2
  unsigned int *v7; // r4
  unsigned int *v8; // r5
  unsigned int v9; // r6
  unsigned int v10; // r1

  v2 = *a1;
  v3 = KeAbPreAcquire(*a1, 0, 0);
  v4 = KfRaiseIrql(1);
  do
    v5 = __ldrex((unsigned __int8 *)v2);
  while ( __strex(v5 & 0xFE, (unsigned __int8 *)v2) );
  __dmb(0xBu);
  if ( (v5 & 1) == 0 )
    return sub_525FD8(v4);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v2[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2[7] = v4;
  v7 = *a1;
  v8 = a1[2];
  v9 = (*a1)[7];
  v7[1] = 0;
  __dmb(0xBu);
  do
    v10 = __ldrex(v7);
  while ( !v10 && __strex(1u, v7) );
  if ( v10 )
    ExpReleaseFastMutexContended(v7, v10, 1);
  KfLowerIrql((unsigned __int8)v9);
  KeAbPostRelease(v7);
  return (int)v8;
}
