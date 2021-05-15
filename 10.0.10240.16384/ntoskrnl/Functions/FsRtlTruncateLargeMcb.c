// FsRtlTruncateLargeMcb 
 
unsigned int __fastcall FsRtlTruncateLargeMcb(unsigned int *a1, int a2, unsigned int a3, int a4)
{
  unsigned int v5; // r6
  int v8; // r5
  int v9; // r10
  unsigned int v10; // r4
  unsigned int *v12; // r4
  int v13; // r5
  unsigned int v14; // r1

  v5 = *a1;
  v8 = KeAbPreAcquire(*a1, 0, 0);
  v9 = KfRaiseIrql(1);
  do
    v10 = __ldrex((unsigned __int8 *)v5);
  while ( __strex(v10 & 0xFE, (unsigned __int8 *)v5) );
  __dmb(0xBu);
  if ( (v10 & 1) == 0 )
    return sub_528B94();
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  *(_DWORD *)(v5 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v5 + 28) = v9;
  FsRtlTruncateBaseMcb((int)(a1 + 1), 0, a3, a4);
  v12 = (unsigned int *)*a1;
  v13 = *(_DWORD *)(*a1 + 28);
  *(_DWORD *)(*a1 + 4) = 0;
  __dmb(0xBu);
  do
    v14 = __ldrex(v12);
  while ( !v14 && __strex(1u, v12) );
  if ( v14 )
    ExpReleaseFastMutexContended(v12, v14);
  KfLowerIrql((unsigned __int8)v13);
  return KeAbPostRelease((unsigned int)v12);
}
