// CmWorkerEngineDequeueWorkItem 
 
int __fastcall CmWorkerEngineDequeueWorkItem(_DWORD *a1)
{
  int v2; // r8
  int v3; // r6
  int v4; // r7
  unsigned int v5; // r2
  _DWORD *v6; // r2
  _DWORD *v7; // r1
  unsigned int v8; // r1

  v2 = 0;
  v3 = KeAbPreAcquire((unsigned int)&CmpWorkerEngineLock, 0, 0);
  v4 = KfRaiseIrql(1);
  do
    v5 = __ldrex((unsigned __int8 *)&CmpWorkerEngineLock);
  while ( __strex(v5 & 0xFE, (unsigned __int8 *)&CmpWorkerEngineLock) );
  __dmb(0xBu);
  if ( (v5 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&CmpWorkerEngineLock, v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  dword_6324A4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_6324BC = v4;
  v6 = (_DWORD *)*a1;
  if ( (_DWORD *)*a1 != a1 )
  {
    v7 = (_DWORD *)a1[1];
    if ( (_DWORD *)v6[1] != a1 || (_DWORD *)*v7 != a1 )
      __fastfail(3u);
    *v7 = v6;
    v6[1] = v7;
    *a1 = a1;
    a1[1] = a1;
    LOBYTE(v4) = dword_6324BC;
    v2 = 1;
  }
  dword_6324A4 = 0;
  __dmb(0xBu);
  do
    v8 = __ldrex(&CmpWorkerEngineLock);
  while ( !v8 && __strex(1u, &CmpWorkerEngineLock) );
  if ( v8 )
    ExpReleaseFastMutexContended(&CmpWorkerEngineLock, v8);
  KfLowerIrql((unsigned __int8)v4);
  KeAbPostRelease((unsigned int)&CmpWorkerEngineLock);
  return v2;
}
