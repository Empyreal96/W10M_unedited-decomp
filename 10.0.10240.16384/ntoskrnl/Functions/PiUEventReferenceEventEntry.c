// PiUEventReferenceEventEntry 
 
int __fastcall PiUEventReferenceEventEntry(int a1)
{
  unsigned int v2; // r5
  int v3; // r4
  int v4; // r0
  unsigned int v5; // r2
  unsigned int *v7; // r4
  int v8; // r5
  unsigned int v9; // r6
  unsigned int v10; // r1

  v2 = *(_DWORD *)(a1 + 8);
  v3 = KeAbPreAcquire(v2, 0, 0);
  v4 = KfRaiseIrql(1);
  do
    v5 = __ldrex((unsigned __int8 *)v2);
  while ( __strex(v5 & 0xFE, (unsigned __int8 *)v2) );
  __dmb(0xBu);
  if ( (v5 & 1) == 0 )
    return sub_7E8E3C(v4);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  *(_DWORD *)(v2 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v2 + 28) = v4;
  v7 = *(unsigned int **)(a1 + 8);
  v8 = *(_DWORD *)(a1 + 28) + 1;
  *(_DWORD *)(a1 + 28) = v8;
  v9 = v7[7];
  v7[1] = 0;
  __dmb(0xBu);
  do
    v10 = __ldrex(v7);
  while ( !v10 && __strex(1u, v7) );
  if ( v10 )
    ExpReleaseFastMutexContended(v7, v10);
  KfLowerIrql((unsigned __int8)v9);
  KeAbPostRelease((unsigned int)v7);
  return v8;
}
