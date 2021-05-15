// FsRtlRemoveLargeMcbEntry 
 
int __fastcall FsRtlRemoveLargeMcbEntry(unsigned int **a1, int a2, int a3, int a4)
{
  unsigned int **v4; // r6
  unsigned int *v5; // r5
  int v6; // r4
  int v7; // r8
  unsigned int v8; // r1
  unsigned int *v9; // r4
  unsigned int v10; // r5
  unsigned int v11; // r1

  v4 = a1;
  v5 = *a1;
  v6 = KeAbPreAcquire(*a1, 0, 0);
  v7 = KfRaiseIrql(1);
  do
    v8 = __ldrex((unsigned __int8 *)v5);
  while ( __strex(v8 & 0xFE, (unsigned __int8 *)v5) );
  __dmb(0xBu);
  if ( (v8 & 1) == 0 )
    ExpAcquireFastMutexContended(v5, v6);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  v5[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5[7] = v7;
  FsRtlRemoveBaseMcbEntry(v4 + 1);
  v9 = *a1;
  v9[1] = 0;
  v10 = v9[7];
  __dmb(0xBu);
  do
    v11 = __ldrex(v9);
  while ( !v11 && __strex(1u, v9) );
  if ( v11 )
    ExpReleaseFastMutexContended(v9, v11, 1);
  KfLowerIrql((unsigned __int8)v10);
  return KeAbPostRelease(v9);
}
