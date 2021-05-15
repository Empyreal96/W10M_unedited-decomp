// PopFxRegisterPluginEx 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopFxRegisterPluginEx(unsigned __int16 *a1, int a2, int a3, int a4, unsigned __int16 *a5)
{
  unsigned int v5; // r1
  unsigned int v7; // r3
  int v8; // r3
  int v9; // r4
  unsigned int v10; // r9
  _BYTE *v11; // r0
  _BYTE *v12; // r5
  _BYTE *v13; // r8 OVERLAPPED
  void (__noreturn *v14)(); // r7 OVERLAPPED
  int v15; // r10
  _DWORD *v16; // r3
  unsigned int v17; // r2
  int v18; // r4
  int v19; // r3
  unsigned int v20; // r2
  int v21; // r0
  int v22; // r4
  unsigned int v23; // r2
  int *v24; // r2 OVERLAPPED
  int v25; // r1 OVERLAPPED
  unsigned int v26; // r1
  int v27; // r0
  unsigned int v28; // r1
  int v29; // r3
  int v30; // [sp+8h] [bp-30h]

  v5 = *a5;
  if ( v5 > 3 )
    return sub_554724();
  if ( (v5 != 3 || a5[1] >= 0x30u) && (v5 != 2 || a5[1] >= 0x2Cu) && *a5 && a5[1] >= 0x1Cu )
  {
    v7 = *a1;
    if ( v7 > 3 )
      return -1073700859;
    if ( v7 == 3 )
    {
      if ( a1[1] >= 0x10u )
      {
        if ( *((_DWORD *)a1 + 1) )
        {
LABEL_13:
          if ( (a3 & 1) != 0 )
            v9 = 4;
          else
            v9 = 1;
          v10 = (28 * v9 + 87) & 0xFFFFFFF8;
          v11 = (_BYTE *)ExAllocatePoolWithTag(512, v10 + 88 * v9);
          v12 = v11;
          v30 = (int)v11;
          if ( !v11 )
            return -1073741670;
          memset(v11, 0, v10 + 88 * v9);
          v13 = &v12[v10];
          v14 = PopFxWorkOrderWatchdog;
          v15 = v9;
          do
          {
            KeInitializeTimerEx(v13, 0);
            v13[48] = 19;
            v13[49] = 1;
            *((_WORD *)v13 + 25) = 0;
            *(_QWORD *)(v13 + 60) = *(_QWORD *)&v14;
            *((_DWORD *)v13 + 19) = 0;
            *((_DWORD *)v13 + 14) = 0;
            v13 += 88;
            --v15;
          }
          while ( v15 );
          *(_DWORD *)(v30 + 76) = v9;
          v16 = (_DWORD *)(v30 + 80);
          v17 = v30 + ((28 * v9 + 87) & 0xFFFFFFF8);
          do
          {
            v16[5] = v30;
            v16[2] = PopFxPluginWork;
            v16[3] = v16;
            *v16 = 0;
            v16[6] = v17;
            *(_DWORD *)(v17 + 80) = v16;
            v17 += 88;
            v16 += 7;
            --v9;
          }
          while ( v9 );
          KeInitializeQueue(v30 + 24, 1);
          v18 = PopFxCreateEmergencyWorkerThread(v30 + 24);
          if ( v18 < 0 )
          {
            ExFreePoolWithTag(v30, 1297630800);
          }
          else
          {
            v19 = *a1;
            *(_DWORD *)(v30 + 16) = a3;
            *(_DWORD *)(v30 + 20) = a4;
            *(_DWORD *)(v30 + 8) = v19;
            *(_DWORD *)(v30 + 64) = *((_DWORD *)a1 + 1);
            *(_DWORD *)(v30 + 68) = *((_DWORD *)a1 + 2);
            if ( *a1 >= 3u )
              *(_DWORD *)(v30 + 72) = *((_DWORD *)a1 + 3);
            v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            --*(_WORD *)(v20 + 308);
            v21 = KeAbPreAcquire((unsigned int)&PopFxPluginLock, 0, 0);
            v22 = v21;
            do
              v23 = __ldrex((unsigned __int8 *)&PopFxPluginLock);
            while ( __strex(v23 | 1, (unsigned __int8 *)&PopFxPluginLock) );
            __dmb(0xBu);
            if ( (v23 & 1) != 0 )
              ExfAcquirePushLockExclusiveEx(&PopFxPluginLock, v21, (unsigned int)&PopFxPluginLock);
            if ( v22 )
              *(_BYTE *)(v22 + 14) |= 1u;
            v24 = (int *)PopFxDeviceRegisterHead;
            v25 = *(_DWORD *)PopFxDeviceRegisterHead;
            *(_QWORD *)v30 = *(_QWORD *)&v25;
            if ( *(int **)(v25 + 4) != v24 )
              __fastfail(3u);
            *(_DWORD *)(v25 + 4) = v30;
            *v24 = v30;
            if ( a3 < 0 )
              PopFxDeviceRegisterHead = v30;
            __dmb(0xBu);
            do
              v26 = __ldrex((unsigned int *)&PopFxPluginLock);
            while ( __strex(v26 - 1, (unsigned int *)&PopFxPluginLock) );
            if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
              ExfTryToWakePushLock((unsigned int *)&PopFxPluginLock);
            v27 = KeAbPostRelease((unsigned int)&PopFxPluginLock);
            v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v29 = (__int16)(*(_WORD *)(v28 + 0x134) + 1);
            *(_WORD *)(v28 + 308) = v29;
            if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
              KiCheckForKernelApcDelivery(v27);
            PopDiagTraceFxPluginRegistration(v30, v28, a3, a4, 0);
            *((_DWORD *)a5 + 1) = v30;
            *((_DWORD *)a5 + 2) = PopFxRequestWorker;
            *((_DWORD *)a5 + 6) = PopFxTransitionCriticalResource;
            *((_DWORD *)a5 + 4) = PopFxProcessorHalt;
            *((_DWORD *)a5 + 5) = PopFxRequestInterrupt;
            *((_DWORD *)a5 + 3) = PopFxEnumerateUnmaskedInterrupts;
            if ( *a5 >= 2u )
            {
              *((_DWORD *)a5 + 7) = PopFxProcessorIdleVeto;
              *((_DWORD *)a5 + 8) = PopFxPlatformIdleVeto;
              *((_DWORD *)a5 + 9) = PopFxUpdateProcessorIdleState;
              *((_DWORD *)a5 + 10) = PopFxUpdatePlatformIdleState;
            }
            if ( *a1 >= 3u )
              *((_DWORD *)a5 + 11) = PopFxRequestCommon;
            if ( *a1 == 3 )
            {
              if ( *((_DWORD *)a1 + 3) )
                PopFxAcpiPepRegistered = 1;
            }
            v18 = 0;
          }
          return v18;
        }
        v8 = *((_DWORD *)a1 + 3);
        goto LABEL_12;
      }
    }
    else if ( v7 == 2 && a1[1] >= 0xCu )
    {
      v8 = *((_DWORD *)a1 + 1);
LABEL_12:
      if ( v8 )
        goto LABEL_13;
      return -1073741811;
    }
  }
  return -1073741811;
}
