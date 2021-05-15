// FsRtlSplitLargeMcb 
 
int __fastcall FsRtlSplitLargeMcb(unsigned int *a1, int a2, unsigned int a3, unsigned int a4, int a5)
{
  unsigned int *v6; // r9
  int v7; // r6
  int v8; // r5
  int v9; // r8
  unsigned int v10; // r4
  int v11; // r1
  unsigned int *v12; // r4
  unsigned int v13; // r5
  unsigned int v14; // r1
  unsigned __int8 v16; // [sp+8h] [bp-28h]
  unsigned int varg_r2; // [sp+40h] [bp+10h]
  unsigned int varg_r3; // [sp+44h] [bp+14h]

  varg_r2 = a3;
  varg_r3 = a4;
  v6 = a1;
  v7 = *a1;
  v8 = KeAbPreAcquire(*a1, 0, 0);
  v9 = KfRaiseIrql(1);
  do
  {
    v10 = __ldrex((unsigned __int8 *)v7);
    v11 = __strex(v10 & 0xFE, (unsigned __int8 *)v7);
  }
  while ( v11 );
  __dmb(0xBu);
  if ( (v10 & 1) == 0 )
    ExpAcquireFastMutexContended(v7, v8);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  *(_DWORD *)(v7 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v7 + 28) = v9;
  v16 = FsRtlSplitBaseMcb((int)(v6 + 1), v11, a3, a4, a5);
  v12 = (unsigned int *)*a1;
  v12[1] = 0;
  v13 = v12[7];
  __dmb(0xBu);
  do
    v14 = __ldrex(v12);
  while ( !v14 && __strex(1u, v12) );
  if ( v14 )
    ExpReleaseFastMutexContended(v12, v14);
  KfLowerIrql((unsigned __int8)v13);
  KeAbPostRelease((unsigned int)v12);
  return v16;
}
