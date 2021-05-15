// RawCompletionRoutine 
 
int __fastcall RawCompletionRoutine(int a1, int a2, int a3)
{
  unsigned __int8 *v3; // r6
  int v5; // r3
  unsigned int v7; // r4
  int v8; // r6
  int v9; // r7
  unsigned int v10; // r2
  int v11; // r5
  unsigned int v12; // r1
  int v13; // r4

  v3 = *(unsigned __int8 **)(a2 + 96);
  v5 = *v3;
  if ( v5 == 3 || v5 == 4 )
  {
    v13 = *((_DWORD *)v3 + 7);
    if ( v13 )
    {
      if ( (*(_DWORD *)(v13 + 44) & 2) != 0 && *(int *)(a2 + 24) >= 0 )
        *(_QWORD *)(v13 + 56) += *(unsigned int *)(a2 + 28);
    }
  }
  if ( *(_BYTE *)(a2 + 33) )
    *(_BYTE *)(*(_DWORD *)(a2 + 96) + 3) |= 1u;
  if ( *(_DWORD *)(a3 + 148) )
    return sub_55318C();
  ExReleaseRundownProtectionCacheAwareEx(*(_DWORD **)(a3 + 156), 1);
  if ( *v3 == 27 )
  {
    v7 = a3 + 160;
    v8 = KeAbPreAcquire(a3 + 160, 0, 0);
    v9 = KfRaiseIrql(1);
    do
      v10 = __ldrex((unsigned __int8 *)v7);
    while ( __strex(v10 & 0xFE, (unsigned __int8 *)v7) );
    __dmb(0xBu);
    if ( (v10 & 1) == 0 )
      ExpAcquireFastMutexContended(a3 + 160, v8);
    if ( v8 )
      *(_BYTE *)(v8 + 14) |= 1u;
    *(_DWORD *)(a3 + 164) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(a3 + 188) = v9;
    --*(_DWORD *)(a3 + 80);
    if ( *(_DWORD *)(a3 + 76) || !RawInitiateDeleteVolume(a3, 0, 0) )
    {
      v11 = *(_DWORD *)(a3 + 188);
      *(_DWORD *)(v7 + 4) = 0;
      __dmb(0xBu);
      do
        v12 = __ldrex((unsigned int *)v7);
      while ( !v12 && __strex(1u, (unsigned int *)v7) );
      if ( v12 )
        ExpReleaseFastMutexContended((unsigned int *)v7, v12);
      KfLowerIrql((unsigned __int8)v11);
      KeAbPostRelease(v7);
    }
  }
  return 0;
}
