// PiUEventDereferenceEventEntry 
 
int __fastcall PiUEventDereferenceEventEntry(int a1)
{
  unsigned int v2; // r6
  int v3; // r5
  int v4; // r7
  unsigned int v5; // r2
  int v6; // r5
  int v7; // r3
  unsigned int *v8; // r6
  unsigned int v9; // r7
  unsigned int v10; // r1

  v2 = *(_DWORD *)(a1 + 8);
  v3 = KeAbPreAcquire(v2, 0, 0);
  v4 = KfRaiseIrql(1);
  do
    v5 = __ldrex((unsigned __int8 *)v2);
  while ( __strex(v5 & 0xFE, (unsigned __int8 *)v2) );
  __dmb(0xBu);
  if ( (v5 & 1) == 0 )
    ExpAcquireFastMutexContended(v2, v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  *(_DWORD *)(v2 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v2 + 28) = v4;
  v6 = *(_DWORD *)(a1 + 28) - 1;
  v7 = *(unsigned __int8 *)(a1 + 40);
  *(_DWORD *)(a1 + 28) = v6;
  if ( v7 && v6 == 1 )
    KeSetEvent(*(_DWORD *)(a1 + 12), 0, 0);
  v8 = *(unsigned int **)(a1 + 8);
  v9 = v8[7];
  v8[1] = 0;
  __dmb(0xBu);
  do
    v10 = __ldrex(v8);
  while ( !v10 && __strex(1u, v8) );
  if ( v10 )
    ExpReleaseFastMutexContended(v8, v10);
  KfLowerIrql((unsigned __int8)v9);
  KeAbPostRelease((unsigned int)v8);
  if ( !v6 )
    PiUEventFreeEventEntry(a1);
  return v6;
}
