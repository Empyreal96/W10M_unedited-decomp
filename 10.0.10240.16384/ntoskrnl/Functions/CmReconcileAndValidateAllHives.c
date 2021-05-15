// CmReconcileAndValidateAllHives 
 
int CmReconcileAndValidateAllHives()
{
  int v0; // r3
  unsigned int v1; // r0
  unsigned int v2; // r2
  unsigned int v3; // r1
  unsigned int v4; // r1
  __int16 v5; // r3
  int result; // r0
  unsigned __int8 *v7; // r0
  unsigned int v8; // r4
  unsigned int v9; // r1
  unsigned int v10; // r1
  __int16 v11; // r3

  v0 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v0 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v1 = CmpShutdownRundown & 0xFFFFFFFE;
  v2 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v3 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v3 == v1 && __strex(v2, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v3 == v1 || ExfAcquireRundownProtection(&CmpShutdownRundown) )
  {
    v7 = (unsigned __int8 *)CmpDoFlushAll(12);
    __pld(&CmpShutdownRundown);
    v8 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v9 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v9 == v8 && __strex(v8 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v9 != v8 )
      v7 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v11 = *(_WORD *)(v10 + 0x134) + 1;
    *(_WORD *)(v10 + 308) = v11;
    if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
      KiCheckForKernelApcDelivery((int)v7);
    result = 0;
  }
  else
  {
    v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v5 = *(_WORD *)(v4 + 0x134) + 1;
    *(_WORD *)(v4 + 308) = v5;
    if ( !v5 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
      KiCheckForKernelApcDelivery(0);
    result = -1073741431;
  }
  return result;
}
