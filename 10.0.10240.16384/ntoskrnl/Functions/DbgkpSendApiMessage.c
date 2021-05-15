// DbgkpSendApiMessage 
 
int __fastcall DbgkpSendApiMessage(int a1, char a2, int a3)
{
  int v6; // r7
  int v7; // r3
  int v8; // r4
  int v9; // r2
  int v10; // r3
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3

  if ( (PerfGlobalGroupMask[0] & 0x400000) != 0 )
    EtwTraceDebuggerEvent(
      *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74),
      __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0,
      1);
  do
  {
    v6 = 0;
    if ( a1 == *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) && (a2 & 1) != 0 )
      v6 = DbgkpSuspendProcess(a1);
    *(_DWORD *)(a3 + 28) = 259;
    if ( (a2 & 2) != 0 )
      v7 = 64;
    else
      v7 = 0;
    v8 = DbgkpQueueMessage(a1, (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0), a3, v7, 0);
    ZwFlushInstructionCache();
    if ( v6 )
    {
      v11 = PsThawProcess(a1, 0, v9, v10);
      v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v13 = *(_WORD *)(v12 + 0x134) + 1;
      *(_WORD *)(v12 + 308) = v13;
      if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
        KiCheckForKernelApcDelivery(v11);
    }
  }
  while ( v8 >= 0 && *(_DWORD *)(a3 + 28) == 1073807361 );
  return v8;
}
