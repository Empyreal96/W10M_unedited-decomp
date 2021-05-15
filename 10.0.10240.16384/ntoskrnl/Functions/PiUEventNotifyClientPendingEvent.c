// PiUEventNotifyClientPendingEvent 
 
int __fastcall PiUEventNotifyClientPendingEvent(int a1)
{
  unsigned int v2; // r5
  int v3; // r4
  int v4; // r1
  int v5; // r7
  int v6; // r2
  int v8; // r3
  unsigned int *v9; // r4
  unsigned int v10; // r5
  unsigned int v11; // r1

  v2 = *(_DWORD *)(a1 + 8);
  v3 = KeAbPreAcquire(v2, 0, 0);
  v5 = KfRaiseIrql(1);
  do
    v6 = __ldrex((unsigned __int8 *)v2);
  while ( __strex(v6 & 0xFE, (unsigned __int8 *)v2) );
  __dmb(0xBu);
  if ( (v6 & 1) == 0 )
    return sub_7E8E24();
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v2 + 4) = v8;
  *(_DWORD *)(v2 + 28) = v5;
  PiUEventEstimateRequiredClientBufferSize(a1, v4, v6, v8);
  v9 = *(unsigned int **)(a1 + 8);
  v10 = v9[7];
  v9[1] = 0;
  __dmb(0xBu);
  do
    v11 = __ldrex(v9);
  while ( !v11 && __strex(1u, v9) );
  if ( v11 )
    ExpReleaseFastMutexContended(v9, v11);
  KfLowerIrql((unsigned __int8)v10);
  KeAbPostRelease((unsigned int)v9);
  return ZwUpdateWnfStateData();
}
