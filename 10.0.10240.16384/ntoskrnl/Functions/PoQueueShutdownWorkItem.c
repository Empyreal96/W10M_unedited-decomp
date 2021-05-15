// PoQueueShutdownWorkItem 
 
int __fastcall PoQueueShutdownWorkItem(int *a1)
{
  int v2; // r5
  int v3; // r7
  unsigned int v4; // r2
  int **v5; // r1
  int v6; // r5
  unsigned int v7; // r1

  v2 = KeAbPreAcquire((unsigned int)&PopShutdownListMutex, 0, 0);
  v3 = KfRaiseIrql(1);
  do
    v4 = __ldrex((unsigned __int8 *)&PopShutdownListMutex);
  while ( __strex(v4 & 0xFE, (unsigned __int8 *)&PopShutdownListMutex) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PopShutdownListMutex, v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_61F424 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_61F43C = v3;
  if ( PopShutdownListAvailable )
  {
    v5 = (int **)dword_61F44C;
    *a1 = (int)&PopShutdownQueue;
    a1[1] = (int)v5;
    if ( *v5 != &PopShutdownQueue )
      __fastfail(3u);
    *v5 = a1;
    LOBYTE(v3) = dword_61F43C;
    dword_61F44C = (int)a1;
    v6 = 0;
  }
  else
  {
    v6 = -1073741077;
  }
  dword_61F424 = 0;
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&PopShutdownListMutex);
  while ( !v7 && __strex(1u, (unsigned int *)&PopShutdownListMutex) );
  if ( v7 )
    ExpReleaseFastMutexContended((unsigned int *)&PopShutdownListMutex, v7);
  KfLowerIrql((unsigned __int8)v3);
  KeAbPostRelease((unsigned int)&PopShutdownListMutex);
  return v6;
}
