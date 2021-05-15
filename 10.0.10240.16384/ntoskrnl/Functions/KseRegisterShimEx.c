// KseRegisterShimEx 
 
int __fastcall KseRegisterShimEx(int a1, int a2, int a3, int a4)
{
  int v8; // r3
  int v9; // r6
  int v10; // r9
  char *v11; // r7
  unsigned int v12; // r2
  int v13; // r6
  unsigned int v14; // r1
  unsigned int v15; // r0
  int v16; // r0
  unsigned int v17; // r1
  int v18; // r3
  unsigned int v19; // r1
  unsigned int v20; // r1
  char *v21; // r3
  unsigned int v22; // r1
  unsigned int v23; // r1
  _WORD *v24; // r3
  unsigned int v25; // r0
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  unsigned int v29; // r1
  unsigned int v30; // r1
  _WORD *v31; // r3
  char **v32; // r1
  int var20[10]; // [sp+0h] [bp-20h] BYREF

  var20[0] = a4;
  if ( !a1 )
    return sub_7CF144();
  v8 = dword_6416D4;
  __dmb(0xBu);
  if ( v8 != 2 )
    return -1073741823;
  var20[0] = 0;
  v9 = KsepGetLoadedModulesList(var20);
  v10 = var20[0];
  if ( v9 >= 0 )
  {
    if ( KsepValidateShimProviderAndData(var20[9], var20[0], a1) )
    {
      v11 = (char *)KsepPoolAllocatePaged(24);
      if ( v11 )
      {
        v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v12 + 308);
        v13 = KeAbPreAcquire((unsigned int)dword_6416EC, 0, 0);
        do
          v14 = __ldrex((unsigned __int8 *)dword_6416EC);
        while ( __strex(v14 | 1, (unsigned __int8 *)dword_6416EC) );
        __dmb(0xBu);
        if ( (v14 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(dword_6416EC, v13, (unsigned int)dword_6416EC);
        if ( v13 )
          *(_BYTE *)(v13 + 14) |= 1u;
        if ( KsepIsShimRegistered(&KseEngine, *(_DWORD *)(a1 + 4), 1, 0) )
        {
          __dmb(0xBu);
          do
            v25 = __ldrex(dword_6416EC);
          while ( __strex(v25 - 1, dword_6416EC) );
          if ( (v25 & 2) != 0 && (v25 & 4) == 0 )
            ExfTryToWakePushLock(dword_6416EC);
          v26 = KeAbPostRelease((unsigned int)dword_6416EC);
          v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v28 = *(_WORD *)(v27 + 0x134) + 1;
          *(_WORD *)(v27 + 308) = v28;
          if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
            KiCheckForKernelApcDelivery(v26);
          v9 = -1073741771;
          __dmb(0xBu);
          do
          {
            v29 = __ldrex(&KsepHistoryErrorsIndex);
            v30 = v29 + 1;
          }
          while ( __strex(v30, &KsepHistoryErrorsIndex) );
          __dmb(0xBu);
          v31 = &KsepHistoryErrors[4 * (v30 & 0x3F)];
          *((_DWORD *)v31 + 1) = -1073741771;
          v31[1] = 2;
          *v31 = 248;
          if ( (KsepDebugFlag & 2) != 0 )
            KsepDebugPrint(2, (int)"KSE: Attempt to re-register shim [0x%08X]\n");
          KsepLogError(2, (int)"KSE: Attempt to re-register shim [0x%08X]\n", **(_DWORD **)(a1 + 4));
          KsepPoolFreePaged((int)v11);
        }
        else
        {
          *((_DWORD *)v11 + 2) = a1;
          *((_DWORD *)v11 + 3) = 0;
          *((_DWORD *)v11 + 4) = a3;
          *((_DWORD *)v11 + 5) = a4;
          v32 = (char **)dword_6416E0;
          *(_DWORD *)v11 = algn_6416DC;
          *((_DWORD *)v11 + 1) = v32;
          if ( *v32 != algn_6416DC )
            __fastfail(3u);
          *v32 = v11;
          dword_6416E0 = (int)v11;
          __dmb(0xBu);
          do
            v15 = __ldrex(dword_6416EC);
          while ( __strex(v15 - 1, dword_6416EC) );
          if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
            ExfTryToWakePushLock(dword_6416EC);
          v16 = KeAbPostRelease((unsigned int)dword_6416EC);
          v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v18 = (__int16)(*(_WORD *)(v17 + 0x134) + 1);
          *(_WORD *)(v17 + 308) = v18;
          if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
            KiCheckForKernelApcDelivery(v16);
          *(_DWORD *)(a1 + 12) = &dword_6416EC[1];
          v9 = 0;
          __dmb(0xBu);
          do
          {
            v19 = __ldrex(KsepHistoryMessagesIndex);
            v20 = v19 + 1;
          }
          while ( __strex(v20, KsepHistoryMessagesIndex) );
          __dmb(0xBu);
          v21 = (char *)&KsepHistoryMessages + 8 * (v20 & 0x3F);
          *((_DWORD *)v21 + 1) = 0;
          *((_WORD *)v21 + 1) = 2;
          *(_WORD *)v21 = 291;
          if ( (KsepDebugFlag & 1) != 0 )
            KsepDebugPrint(2, (int)"KSE: Succeeded shim [0x%08X] registration\n");
          KsepLogInfo(2, (int)"KSE: Succeeded shim [0x%08X] registration\n", **(_DWORD **)(a1 + 4));
        }
      }
      else
      {
        v9 = -1073741670;
      }
    }
    else
    {
      v9 = -1073741823;
      __dmb(0xBu);
      do
      {
        v22 = __ldrex(&KsepHistoryErrorsIndex);
        v23 = v22 + 1;
      }
      while ( __strex(v23, &KsepHistoryErrorsIndex) );
      __dmb(0xBu);
      v24 = &KsepHistoryErrors[4 * (v23 & 0x3F)];
      *((_DWORD *)v24 + 1) = -1073741823;
      v24[1] = 2;
      *v24 = 215;
      if ( (KsepDebugFlag & 2) != 0 )
        KsepDebugPrint(2, (int)"KSE: Shim [0x%08X] is not valid\n");
      KsepLogError(2, (int)"KSE: Shim [0x%08X] is not valid\n", **(_DWORD **)(a1 + 4));
    }
  }
  if ( v10 )
    KsepPoolFreePaged(v10);
  return v9;
}
