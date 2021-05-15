// sub_7CFDEC 
 
void sub_7CFDEC()
{
  _DWORD **v0; // r6
  int v1; // r5
  int v2; // r7
  unsigned int v3; // r2
  int v4; // r3
  _DWORD *v5; // r8
  int v6; // r9
  unsigned int v7; // r5
  int v8; // r7
  int v9; // r0
  unsigned int v10; // r2
  unsigned int v11; // r3
  int v12; // r7
  unsigned int v13; // r1
  unsigned int v14; // r1

  v1 = KeAbPreAcquire((unsigned int)&RawGlobalLock, 0, 0);
  v2 = KfRaiseIrql(1);
  do
    v3 = __ldrex((unsigned __int8 *)&RawGlobalLock);
  while ( __strex(v3 & 0xFE, (unsigned __int8 *)&RawGlobalLock) );
  __dmb(0xBu);
  if ( (v3 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&RawGlobalLock, v1);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  v4 = __mrc(15, 0, 13, 0, 3);
  v5 = *v0;
  dword_61D964 = v4 & 0xFFFFFFC0;
  dword_61D97C = v2;
  if ( v5 != v0 )
  {
    do
    {
      v6 = (int)(v5 - 32);
      v7 = (unsigned int)(v5 + 8);
      v5 = (_DWORD *)*v5;
      v8 = KeAbPreAcquire(v7, 0, 1);
      v9 = KfRaiseIrql(1);
      do
        v10 = __ldrex((unsigned __int8 *)v7);
      while ( __strex(v10 & 0xFE, (unsigned __int8 *)v7) );
      __dmb(0xBu);
      if ( (v10 & 1) != 0 )
      {
        if ( v8 )
          *(_BYTE *)(v8 + 14) |= 1u;
        v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        *(_DWORD *)(v7 + 28) = v9;
        *(_DWORD *)(v7 + 4) = v11;
        if ( !RawCheckForDeleteVolume(v6) )
        {
          v12 = *(_DWORD *)(v7 + 28);
          *(_DWORD *)(v7 + 4) = 0;
          __dmb(0xBu);
          do
            v13 = __ldrex((unsigned int *)v7);
          while ( !v13 && __strex(1u, (unsigned int *)v7) );
          if ( v13 )
            ExpReleaseFastMutexContended((unsigned int *)v7, v13);
          KfLowerIrql((unsigned __int8)v12);
          KeAbPostRelease(v7);
        }
      }
      else
      {
        KfLowerIrql(v9);
        if ( v8 )
          KeAbPostReleaseEx(v7, v8);
        __dmb(0xAu);
        __yield();
      }
    }
    while ( v5 != v0 );
    LOBYTE(v2) = dword_61D97C;
  }
  dword_61D964 = 0;
  __dmb(0xBu);
  do
    v14 = __ldrex((unsigned int *)&RawGlobalLock);
  while ( !v14 && __strex(1u, (unsigned int *)&RawGlobalLock) );
  if ( v14 )
    ExpReleaseFastMutexContended((unsigned int *)&RawGlobalLock, v14);
  KfLowerIrql((unsigned __int8)v2);
  KeAbPostRelease((unsigned int)&RawGlobalLock);
  JUMPOUT(0x789BA2);
}
