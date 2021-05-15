// FsRtlGetNextLargeMcbEntry 
 
int __fastcall FsRtlGetNextLargeMcbEntry(unsigned int **a1, int a2, int a3, int a4, int a5)
{
  unsigned int *v5; // r7
  int v9; // r6
  int v10; // r0
  unsigned int v11; // r5
  int v13; // r0
  unsigned int *v14; // r4
  int v15; // r5
  unsigned int v16; // r6
  unsigned int v17; // r1

  v5 = *a1;
  v9 = KeAbPreAcquire(*a1, 0, 0);
  v10 = KfRaiseIrql(1);
  do
    v11 = __ldrex((unsigned __int8 *)v5);
  while ( __strex(v11 & 0xFE, (unsigned __int8 *)v5) );
  __dmb(0xBu);
  if ( (v11 & 1) == 0 )
    return sub_520EDC();
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  v5[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5[7] = v10;
  v13 = FsRtlGetNextBaseMcbEntry(a1 + 1, a2, a3, a4, a5);
  v14 = *a1;
  v15 = v13;
  v16 = (*a1)[7];
  (*a1)[1] = 0;
  __dmb(0xBu);
  do
    v17 = __ldrex(v14);
  while ( !v17 && __strex(1u, v14) );
  if ( v17 )
    ExpReleaseFastMutexContended(v14, v17, 1);
  KfLowerIrql((unsigned __int8)v16);
  KeAbPostRelease(v14);
  return v15;
}
