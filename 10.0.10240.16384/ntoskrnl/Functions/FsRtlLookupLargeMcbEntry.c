// FsRtlLookupLargeMcbEntry 
 
int __fastcall FsRtlLookupLargeMcbEntry(unsigned int **a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  unsigned int **v10; // r9
  unsigned int *v11; // r6
  int v12; // r5
  int v13; // r8
  unsigned int v14; // r4
  unsigned int v15; // r1
  unsigned int *v16; // r4
  unsigned int v17; // r5
  unsigned int v18; // r1
  unsigned __int8 v20; // [sp+18h] [bp-28h]
  int varg_r2; // [sp+50h] [bp+10h]
  int varg_r3; // [sp+54h] [bp+14h]

  varg_r2 = a3;
  varg_r3 = a4;
  v10 = a1;
  v11 = *a1;
  v12 = KeAbPreAcquire(*a1, 0, 0);
  v13 = KfRaiseIrql(1);
  do
  {
    v14 = __ldrex((unsigned __int8 *)v11);
    v15 = __strex(v14 & 0xFE, (unsigned __int8 *)v11);
  }
  while ( v15 );
  __dmb(0xBu);
  if ( (v14 & 1) == 0 )
    ExpAcquireFastMutexContended(v11, v12);
  if ( v12 )
    *(_BYTE *)(v12 + 14) |= 1u;
  v11[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11[7] = v13;
  v20 = FsRtlLookupBaseMcbEntry(v10 + 1, v15, a3, a4, a5, a6, a7, a8, a9);
  v16 = *a1;
  v16[1] = 0;
  v17 = v16[7];
  __dmb(0xBu);
  do
    v18 = __ldrex(v16);
  while ( !v18 && __strex(1u, v16) );
  if ( v18 )
    ExpReleaseFastMutexContended(v16, v18, 1);
  KfLowerIrql((unsigned __int8)v17);
  KeAbPostRelease(v16);
  return v20;
}
