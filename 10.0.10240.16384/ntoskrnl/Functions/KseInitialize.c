// KseInitialize 
 
int __fastcall KseInitialize(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v7; // r0
  unsigned int v8; // r1
  unsigned int v9; // r1
  char *v10; // r3
  unsigned int v12; // r4
  int v13; // r2
  unsigned int v14; // r2
  unsigned int v15; // r2
  _WORD *v16; // r3
  unsigned int v17; // r2
  unsigned int v18; // r2
  _WORD *v19; // r3
  unsigned int v20; // r2
  unsigned int v21; // r2
  _WORD *v22; // r3
  int v23[8]; // [sp+0h] [bp-20h] BYREF

  v23[0] = a4;
  v5 = 0;
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      v23[0] = 0;
      EtwRegister((int)KernelShimEngineProvider, 0, 0);
      v5 = KseShimDatabaseOpen(v23);
      if ( v5 >= 0 && v23[0] )
      {
        KseShimDatabaseClose(v23[0]);
      }
      else
      {
        v5 = -1073741637;
        dword_6416D8 |= 0x80u;
      }
      if ( v5 >= 0 )
      {
        KseVersionLieInitialize();
        v7 = KseRegisterShim((int)&KseSkipDriverUnloadShim, 0, 0);
        if ( v7 < 0 )
        {
          __dmb(0xBu);
          do
          {
            v14 = __ldrex(&KsepHistoryErrorsIndex);
            v15 = v14 + 1;
          }
          while ( __strex(v15, &KsepHistoryErrorsIndex) );
          __dmb(0xBu);
          v16 = &KsepHistoryErrors[4 * (v15 & 0x3F)];
          *((_DWORD *)v16 + 1) = v7;
          v16[1] = 13;
          *v16 = 147;
          if ( (KsepDebugFlag & 2) != 0 )
            KsepDebugPrint(12, (int)"Built-in SkipDriverUnload shims: failed to register.\n");
          KsepLogError(12, (int)"Built-in SkipDriverUnload shims: failed to register.\n");
        }
      }
    }
    goto LABEL_8;
  }
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)&dword_6416D4);
  while ( !v12 && __strex(1u, (unsigned int *)&dword_6416D4) );
  __dmb(0xBu);
  if ( v12 == 2 )
    return 0;
  if ( v12 == 1 )
    return 259;
  if ( KseShimDatabaseBootInitialize(*(_DWORD *)(*(_DWORD *)(a1 + 132) + 40), *(_DWORD *)(*(_DWORD *)(a1 + 132) + 44)) < 0 )
    return -1073741823;
  if ( !InitSafeBootMode )
  {
    v13 = *(_DWORD *)(a1 + 132);
    if ( *(_DWORD *)(v13 + 40) )
    {
      if ( *(_DWORD *)(v13 + 44) )
      {
        v5 = KsepEngineInitialize(&KseEngine);
        if ( v5 < 0 || (v5 = KsepMatchInitMachineInfo(), v5 < 0) )
        {
LABEL_39:
          __dmb(0xBu);
          dword_6416D4 = 0;
          KsepEngineUninitialize(&KseEngine);
          __dmb(0xBu);
          if ( v5 == -1073741637 )
          {
            do
            {
              v17 = __ldrex(&KsepHistoryErrorsIndex);
              v18 = v17 + 1;
            }
            while ( __strex(v18, &KsepHistoryErrorsIndex) );
            __dmb(0xBu);
            v19 = &KsepHistoryErrors[4 * (v18 & 0x3F)];
            *((_DWORD *)v19 + 1) = -1073741637;
            v19[1] = 5;
            *v19 = 250;
            if ( (KsepDebugFlag & 2) != 0 )
              KsepDebugPrint(
                1,
                (int)"KSE: Engine not initialized (disabled explicitly, safe boot on, verifier on, WinPE mode or loader issue)\n");
            KsepLogError(
              1,
              (int)"KSE: Engine not initialized (disabled explicitly, safe boot on, verifier on, WinPE mode or loader issue)\n");
          }
          else
          {
            do
            {
              v20 = __ldrex(&KsepHistoryErrorsIndex);
              v21 = v20 + 1;
            }
            while ( __strex(v21, &KsepHistoryErrorsIndex) );
            __dmb(0xBu);
            v22 = &KsepHistoryErrors[4 * (v21 & 0x3F)];
            *((_DWORD *)v22 + 1) = v5;
            v22[1] = 5;
            *v22 = 254;
            if ( (KsepDebugFlag & 2) != 0 )
              KsepDebugPrint(1, (int)"KSE: Initialization failed: 0x%x\n");
            KsepLogError(1, (int)"KSE: Initialization failed: 0x%x\n", v5);
          }
          return v5;
        }
        __dmb(0xBu);
        dword_6416D4 = 2;
        KseDriverScopeInitialize();
LABEL_8:
        __dmb(0xBu);
        do
        {
          v8 = __ldrex(KsepHistoryMessagesIndex);
          v9 = v8 + 1;
        }
        while ( __strex(v9, KsepHistoryMessagesIndex) );
        __dmb(0xBu);
        v10 = (char *)&KsepHistoryMessages + 8 * (v9 & 0x3F);
        *((_DWORD *)v10 + 1) = 0;
        *((_WORD *)v10 + 1) = 5;
        *(_WORD *)v10 = 222;
        if ( (KsepDebugFlag & 1) != 0 )
          KsepDebugPrint(1, (int)"KSE: Initialized phase 0x%x\n");
        KsepLogInfo(1, (int)"KSE: Initialized phase 0x%x\n", a2);
        if ( InitIsWinPEMode )
          KseEngine |= 1u;
        if ( v5 >= 0 )
          return v5;
        goto LABEL_39;
      }
    }
  }
  return sub_965C30();
}
