// FsRtlAddLargeMcbEntry 
 
int __fastcall FsRtlAddLargeMcbEntry(unsigned int **a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  unsigned int **v9; // r9
  unsigned int *v10; // r6
  int v11; // r5
  int v12; // r8
  unsigned int v13; // r4
  unsigned int v14; // r1
  unsigned int *v15; // r4
  unsigned int v16; // r5
  unsigned int v17; // r1
  int v19; // [sp+10h] [bp-28h]
  unsigned __int8 v20; // [sp+10h] [bp-28h]
  int varg_r1; // [sp+44h] [bp+Ch]
  int varg_r2; // [sp+48h] [bp+10h]
  int varg_r3; // [sp+4Ch] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v19 = a2;
  v9 = a1;
  LOBYTE(v19) = 0;
  v10 = *a1;
  v11 = KeAbPreAcquire(*a1, 0, 0);
  v12 = KfRaiseIrql(1);
  do
  {
    v13 = __ldrex((unsigned __int8 *)v10);
    v14 = __strex(v13 & 0xFE, (unsigned __int8 *)v10);
  }
  while ( v14 );
  __dmb(0xBu);
  if ( (v13 & 1) == 0 )
    ExpAcquireFastMutexContended(v10, v11);
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  v10[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10[7] = v12;
  v20 = FsRtlAddBaseMcbEntry(v9 + 1, v14, a3, a4, a5, a6, a7, a8, v19);
  v15 = *a1;
  v15[1] = 0;
  v16 = v15[7];
  __dmb(0xBu);
  do
    v17 = __ldrex(v15);
  while ( !v17 && __strex(1u, v15) );
  if ( v17 )
    ExpReleaseFastMutexContended(v15, v17, 1);
  KfLowerIrql((unsigned __int8)v16);
  KeAbPostRelease(v15);
  return v20;
}
