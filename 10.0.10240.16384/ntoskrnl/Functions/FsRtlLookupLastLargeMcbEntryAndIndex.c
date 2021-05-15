// FsRtlLookupLastLargeMcbEntryAndIndex 
 
int __fastcall FsRtlLookupLastLargeMcbEntryAndIndex(unsigned int **a1, int a2, int a3, int a4)
{
  unsigned int **v4; // r10
  unsigned int *v5; // r8
  int v6; // r6
  int v7; // r9
  unsigned int v8; // r5
  unsigned int *v9; // r4
  unsigned int v10; // r5
  unsigned int v11; // r1
  unsigned __int8 v13; // [sp+0h] [bp-30h]
  int varg_r1; // [sp+3Ch] [bp+Ch]
  int varg_r2; // [sp+40h] [bp+10h]
  int varg_r3; // [sp+44h] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
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
  v13 = FsRtlLookupLastBaseMcbEntryAndIndex(v4 + 1, a2, a3, a4, 0);
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
  KeAbPostRelease(v9);
  return v13;
}
