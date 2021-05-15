// FsRtlLookupLastLargeMcbEntry 
 
int __fastcall FsRtlLookupLastLargeMcbEntry(unsigned int *a1, _DWORD *a2, int *a3, int a4)
{
  unsigned int *v5; // r9
  int v6; // r6
  int v7; // r5
  int v8; // r8
  unsigned int v9; // r4
  unsigned int *v10; // r4
  unsigned int v11; // r5
  unsigned int v12; // r1
  unsigned __int8 v14; // [sp+0h] [bp-28h]
  _DWORD *varg_r1; // [sp+34h] [bp+Ch]
  int *varg_r2; // [sp+38h] [bp+10h]

  varg_r1 = a2;
  varg_r2 = a3;
  v5 = a1;
  v6 = *a1;
  v7 = KeAbPreAcquire(*a1, 0, 0);
  v8 = KfRaiseIrql(1);
  do
    v9 = __ldrex((unsigned __int8 *)v6);
  while ( __strex(v9 & 0xFE, (unsigned __int8 *)v6) );
  __dmb(0xBu);
  if ( (v9 & 1) == 0 )
    ExpAcquireFastMutexContended(v6, v7);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  *(_DWORD *)(v6 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v6 + 28) = v8;
  v14 = FsRtlLookupLastBaseMcbEntry((int)(v5 + 1), a2, a3);
  v10 = (unsigned int *)*a1;
  v10[1] = 0;
  v11 = v10[7];
  __dmb(0xBu);
  do
    v12 = __ldrex(v10);
  while ( !v12 && __strex(1u, v10) );
  if ( v12 )
    ExpReleaseFastMutexContended(v10, v12);
  KfLowerIrql((unsigned __int8)v11);
  KeAbPostRelease((unsigned int)v10);
  return v14;
}
