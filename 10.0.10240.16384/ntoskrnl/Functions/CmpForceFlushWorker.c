// CmpForceFlushWorker 
 
int CmpForceFlushWorker()
{
  int v0; // r3
  unsigned int v1; // r0
  unsigned int v2; // r2
  unsigned int v3; // r1
  unsigned __int8 *v4; // r0
  unsigned int v5; // r4
  unsigned int v6; // r1
  unsigned int v7; // r1
  __int16 v8; // r3
  int result; // r0
  unsigned int v10; // r1

  v0 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v0 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v1 = CmpShutdownRundown & 0xFFFFFFFE;
  v2 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v3 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v3 == v1 && __strex(v2, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v3 == v1 || (v4 = (unsigned __int8 *)ExfAcquireRundownProtection(&CmpShutdownRundown)) != 0 )
  {
    v4 = (unsigned __int8 *)CmpDoFlushAll(0);
    __pld(&CmpShutdownRundown);
    v5 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v6 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v6 == v5 && __strex(v5 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v6 != v5 )
      v4 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
  }
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(_WORD *)(v7 + 0x134) + 1;
  *(_WORD *)(v7 + 308) = v8;
  if ( !v8 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
    KiCheckForKernelApcDelivery((int)v4);
  __dmb(0xBu);
  result = 0;
  do
    v10 = __ldrex((unsigned int *)&CmpForceFlushPending);
  while ( __strex(0, (unsigned int *)&CmpForceFlushPending) );
  __dmb(0xBu);
  return result;
}
