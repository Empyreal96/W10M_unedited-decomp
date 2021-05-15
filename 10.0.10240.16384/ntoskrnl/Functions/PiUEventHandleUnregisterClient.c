// PiUEventHandleUnregisterClient 
 
int __fastcall PiUEventHandleUnregisterClient(int a1)
{
  int v1; // r6
  unsigned int v3; // r7
  int v4; // r4
  int v5; // r8
  unsigned int v6; // r2
  unsigned int *v7; // r4
  unsigned int v8; // r6
  unsigned int v9; // r1

  v1 = *(_DWORD *)(a1 + 16);
  if ( !v1 )
    return sub_7EA420();
  v3 = *(_DWORD *)(v1 + 8);
  v4 = KeAbPreAcquire(v3, 0, 0);
  v5 = KfRaiseIrql(1);
  do
    v6 = __ldrex((unsigned __int8 *)v3);
  while ( __strex(v6 & 0xFE, (unsigned __int8 *)v3) );
  __dmb(0xBu);
  if ( (v6 & 1) == 0 )
    ExpAcquireFastMutexContended(v3, v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  *(_DWORD *)(v3 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v3 + 28) = v5;
  v7 = *(unsigned int **)(v1 + 8);
  *(_BYTE *)(v1 + 84) = 0;
  v8 = v7[7];
  v7[1] = 0;
  __dmb(0xBu);
  do
    v9 = __ldrex(v7);
  while ( !v9 && __strex(1u, v7) );
  if ( v9 )
    ExpReleaseFastMutexContended(v7, v9);
  KfLowerIrql((unsigned __int8)v8);
  KeAbPostRelease((unsigned int)v7);
  return 0;
}
