// PspShutdownServerSilos 
 
unsigned int PspShutdownServerSilos()
{
  int v0; // r5
  int v1; // r6
  unsigned int v2; // r2
  int *i; // r2
  int v4; // r5
  BOOL v5; // r3
  unsigned int v6; // r1
  int v7; // r5
  int v8; // r8
  unsigned int v9; // r2
  unsigned int v10; // r1

  v0 = KeAbPreAcquire((unsigned int)&PspSiloListLock, 0, 0);
  v1 = KfRaiseIrql(1);
  do
    v2 = __ldrex((unsigned __int8 *)&PspSiloListLock);
  while ( __strex(v2 & 0xFE, (unsigned __int8 *)&PspSiloListLock) );
  __dmb(0xBu);
  if ( (v2 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PspSiloListLock, v0);
  if ( v0 )
    *(_BYTE *)(v0 + 14) |= 1u;
  dword_61DA44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_61DA5C = v1;
LABEL_8:
  for ( i = (int *)PspSiloList; i != &PspSiloList; i = (int *)*i )
  {
    v4 = (int)(i - 5);
    v5 = i != (int *)20 && i[31];
    if ( v5 && PsGetServerSiloState((int)(i - 5)) == 1 )
    {
      if ( v4 )
      {
        PspReferenceSiloObject(v4);
        LOBYTE(v1) = dword_61DA5C;
      }
      dword_61DA44 = 0;
      __dmb(0xBu);
      do
        v6 = __ldrex((unsigned int *)&PspSiloListLock);
      while ( !v6 && __strex(1u, (unsigned int *)&PspSiloListLock) );
      if ( v6 )
        ExpReleaseFastMutexContended((unsigned int *)&PspSiloListLock, v6);
      KfLowerIrql((unsigned __int8)v1);
      KeAbPostRelease((unsigned int)&PspSiloListLock);
      PsTerminateServerSilo(v4, -1073741077);
      if ( v4 )
        PspDereferenceSiloObject(v4);
      v7 = KeAbPreAcquire((unsigned int)&PspSiloListLock, 0, 0);
      v8 = KfRaiseIrql(1);
      do
        v9 = __ldrex((unsigned __int8 *)&PspSiloListLock);
      while ( __strex(v9 & 0xFE, (unsigned __int8 *)&PspSiloListLock) );
      __dmb(0xBu);
      if ( (v9 & 1) == 0 )
        ExpAcquireFastMutexContended((int)&PspSiloListLock, v7);
      if ( v7 )
        *(_BYTE *)(v7 + 14) |= 1u;
      dword_61DA44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      dword_61DA5C = v8;
      LOBYTE(v1) = v8;
      goto LABEL_8;
    }
  }
  dword_61DA44 = 0;
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)&PspSiloListLock);
  while ( !v10 && __strex(1u, (unsigned int *)&PspSiloListLock) );
  if ( v10 )
    ExpReleaseFastMutexContended((unsigned int *)&PspSiloListLock, v10);
  KfLowerIrql((unsigned __int8)v1);
  return KeAbPostRelease((unsigned int)&PspSiloListLock);
}
