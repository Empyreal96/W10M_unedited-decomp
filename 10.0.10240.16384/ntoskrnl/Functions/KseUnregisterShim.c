// KseUnregisterShim 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KseUnregisterShim(int a1)
{
  int v2; // r7
  int v3; // r3
  int v4; // r9
  unsigned int v5; // r2
  int v6; // r4
  unsigned int v7; // r1
  unsigned int v8; // r1
  unsigned int v9; // r1
  _WORD *v10; // r3
  int v11; // r1 OVERLAPPED
  int v12; // r2 OVERLAPPED
  unsigned int v13; // r1
  unsigned int v14; // r1
  char *v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r1
  _WORD *v18; // r3
  unsigned int v19; // r0
  int v20; // r0
  unsigned int v21; // r1
  __int16 v22; // r3

  if ( !a1 )
    return -1073741811;
  v3 = dword_6416D4;
  __dmb(0xBu);
  if ( v3 != 2 )
    return -1073741823;
  v4 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = KeAbPreAcquire((unsigned int)dword_6416EC, 0, 0);
  do
    v7 = __ldrex((unsigned __int8 *)dword_6416EC);
  while ( __strex(v7 | 1, (unsigned __int8 *)dword_6416EC) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(dword_6416EC, v6, (unsigned int)dword_6416EC);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  if ( KsepIsShimRegistered((int)&KseEngine, *(_DWORD *)(a1 + 4)) )
  {
    if ( MEMORY[0xC] )
    {
      v2 = -1073741790;
      __dmb(0xBu);
      do
      {
        v8 = __ldrex(&KsepHistoryErrorsIndex);
        v9 = v8 + 1;
      }
      while ( __strex(v9, &KsepHistoryErrorsIndex) );
      __dmb(0xBu);
      v10 = &KsepHistoryErrors[4 * (v9 & 0x3F)];
      *((_DWORD *)v10 + 1) = -1073741790;
      v10[1] = 2;
      *v10 = 392;
      if ( (KsepDebugFlag & 2) != 0 )
        KsepDebugPrint(3, (int)"KSE: Ending shim [0x%08X] unregistration. Shim object [0x%08X] ref count is not 0.\n");
      KsepLogError(
        3,
        (int)"KSE: Ending shim [0x%08X] unregistration. Shim object [0x%08X] ref count is not 0.\n",
        **(_DWORD **)(a1 + 4),
        0);
      MEMORY[0x10] |= 4u;
    }
    else
    {
      *(_QWORD *)&v11 = MEMORY[0];
      if ( *(_DWORD *)(MEMORY[0] + 4) || *MEMORY[4] )
        __fastfail(3u);
      *MEMORY[4] = MEMORY[0];
      *(_DWORD *)(v11 + 4) = v12;
      v4 = 1;
      __dmb(0xBu);
      do
      {
        v13 = __ldrex(KsepHistoryMessagesIndex);
        v14 = v13 + 1;
      }
      while ( __strex(v14, KsepHistoryMessagesIndex) );
      __dmb(0xBu);
      v15 = (char *)&KsepHistoryMessages + 8 * (v14 & 0x3F);
      *((_DWORD *)v15 + 1) = 0;
      *((_WORD *)v15 + 1) = 2;
      *(_WORD *)v15 = 409;
      if ( (KsepDebugFlag & 1) != 0 )
        KsepDebugPrint(3, (int)"KSE: Succeeded shim [0x%08X] unregistration.\n");
      KsepLogInfo(3, (int)"KSE: Succeeded shim [0x%08X] unregistration.\n", **(_DWORD **)(a1 + 4));
      v2 = 0;
    }
  }
  else
  {
    v2 = -1073741772;
    __dmb(0xBu);
    do
    {
      v16 = __ldrex(&KsepHistoryErrorsIndex);
      v17 = v16 + 1;
    }
    while ( __strex(v17, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v18 = &KsepHistoryErrors[4 * (v17 & 0x3F)];
    *((_DWORD *)v18 + 1) = -1073741772;
    v18[1] = 2;
    *v18 = 421;
    if ( (KsepDebugFlag & 2) != 0 )
      KsepDebugPrint(3, (int)"KSE: Failed shim [0x%08X] unregistration. Shim not found.\n");
    KsepLogError(3, (int)"KSE: Failed shim [0x%08X] unregistration. Shim not found.\n", **(_DWORD **)(a1 + 4));
  }
  __dmb(0xBu);
  do
    v19 = __ldrex(dword_6416EC);
  while ( __strex(v19 - 1, dword_6416EC) );
  if ( (v19 & 2) != 0 && (v19 & 4) == 0 )
    ExfTryToWakePushLock(dword_6416EC);
  v20 = KeAbPostRelease((unsigned int)dword_6416EC);
  v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v22 = *(_WORD *)(v21 + 0x134) + 1;
  *(_WORD *)(v21 + 308) = v22;
  if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
    KiCheckForKernelApcDelivery(v20);
  if ( v4 )
    KsepPoolFreePaged(0);
  return v2;
}
