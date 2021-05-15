// sub_803020 
 
void sub_803020()
{
  char v0; // r3
  BOOL v1; // r7
  char v2; // r3
  _DWORD *v3; // r5
  int v4; // r9
  unsigned int v5; // r8
  int v6; // r3
  void (__fastcall *v7)(_DWORD, _DWORD, _DWORD); // r0
  void (__fastcall *v8)(int, _DWORD, _DWORD); // r0
  int v9; // r4
  int v10; // r5
  int v11; // r6
  int v12; // r0

  v12 = PsSetProcessTelemetryAppState(v11, 3);
  if ( (PerfGlobalGroupMask[0] & v10) != 0 )
    v12 = EtwTraceProcess(v11, (int *)0x302);
  --*(_WORD *)(v9 + 308);
  v0 = PspNotifyEnableMask;
  __dmb(0xBu);
  v1 = (v0 & 4) != 0;
  v2 = PspNotifyEnableMask;
  __dmb(0xBu);
  if ( (v2 & 2) != 0 || v1 )
  {
    v3 = PspCreateProcessNotifyRoutine;
    v4 = 64;
    do
    {
      v12 = ExReferenceCallBackBlock(v3);
      v5 = v12;
      if ( v12 )
      {
        if ( ExGetCallBackBlockContext(v12) )
        {
          if ( v1 )
          {
            v8 = (void (__fastcall *)(int, _DWORD, _DWORD))KeReadStateSemaphore(v5);
            v8(v11, *(_DWORD *)(v11 + 176), 0);
          }
        }
        else
        {
          v7 = (void (__fastcall *)(_DWORD, _DWORD, _DWORD))KeReadStateSemaphore(v5);
          v7(*(_DWORD *)(v11 + 312), *(_DWORD *)(v11 + 176), 0);
        }
        v12 = (int)ExDereferenceCallBackBlock(v3, v5);
      }
      ++v3;
      --v4;
    }
    while ( v4 );
  }
  v6 = (__int16)(*(_WORD *)(v9 + 308) + 1);
  *(_WORD *)(v9 + 308) = v6;
  if ( !v6 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    KiCheckForKernelApcDelivery(v12);
  JUMPOUT(0x743828);
}
