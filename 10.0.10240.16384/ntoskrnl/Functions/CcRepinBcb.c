// CcRepinBcb 
 
int __fastcall CcRepinBcb(int a1)
{
  int v2; // r6
  int v3; // r4
  int v4; // r0
  unsigned int v5; // r2
  unsigned int *v7; // r4
  int v8; // r5
  unsigned int v9; // r1

  if ( *(_WORD *)a1 != 765 )
    KeBugCheckEx(52, 7655, -1073740768);
  v2 = *(_DWORD *)(a1 + 112) + 180;
  v3 = KeAbPreAcquire(v2, 0, 0);
  v4 = KfRaiseIrql(1);
  do
    v5 = __ldrex((unsigned __int8 *)v2);
  while ( __strex(v5 & 0xFE, (unsigned __int8 *)v2) );
  __dmb(0xBu);
  if ( (v5 & 1) == 0 )
    return sub_524E2C(v4);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  *(_DWORD *)(v2 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v2 + 28) = v4;
  ++*(_DWORD *)(a1 + 52);
  v7 = (unsigned int *)(*(_DWORD *)(a1 + 112) + 180);
  v8 = *(_DWORD *)(*(_DWORD *)(a1 + 112) + 208);
  v7[1] = 0;
  __dmb(0xBu);
  do
    v9 = __ldrex(v7);
  while ( !v9 && __strex(1u, v7) );
  if ( v9 )
    ExpReleaseFastMutexContended(v7, v9, 1);
  KfLowerIrql((unsigned __int8)v8);
  return KeAbPostRelease(v7);
}
