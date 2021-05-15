// PiPnpRtlInit 
 
int __fastcall PiPnpRtlInit(int a1)
{
  int result; // r0
  int v3; // r1
  int v4; // r2
  int v5; // r3
  unsigned int *v6; // r1
  unsigned int v7; // r0
  int v8; // r3
  unsigned int *v9; // r1
  unsigned int v10; // r0
  int v11; // r3
  unsigned int *v12; // r1
  unsigned int v13; // r0

  if ( a1 )
    return PiDrvDbInit(a1);
  PiPnpRtlActiveOperations = (int)&PiPnpRtlActiveOperations;
  *(_DWORD *)algn_63023C = &PiPnpRtlActiveOperations;
  result = ExInitializeResourceLite((int)&PiPnpRtlRemoveOperationDispatchLock);
  if ( result >= 0 )
  {
    result = ExInitializeResourceLite((int)&PiPnpRtlActiveOperationsLock);
    if ( result >= 0 )
    {
      result = PnpCtxOpenMachine(result, v3, v4, 0);
      if ( result >= 0 )
      {
        result = PnpCtxSetNtPlugPlayRoutine(PiPnpRtlCtx, 1, PiPnpRtlGetDeviceNtPropertyRoutine);
        if ( result >= 0 )
        {
          result = PnpCtxSetNtPlugPlayRoutine(PiPnpRtlCtx, 2, PiPnpRtlGetDeviceStatus);
          if ( result >= 0 )
          {
            result = PnpCtxSetNtPlugPlayRoutine(PiPnpRtlCtx, 3, PiPnpRtlGetDeviceRelatedDeviceRoutine);
            if ( result >= 0 )
            {
              result = PnpCtxSetNtPlugPlayRoutine(PiPnpRtlCtx, 4, PiPnpRtlGetDeviceRelationsList);
              if ( result >= 0 )
              {
                result = PnpCtxSetNtPlugPlayRoutine(PiPnpRtlCtx, 5, PiPnpRtlGetDeviceInterfaceEnabled);
                if ( result >= 0 )
                {
                  v5 = PiPnpRtlCtx;
                  __dmb(0xBu);
                  v6 = (unsigned int *)(v5 + 152);
                  do
                    v7 = __ldrex(v6);
                  while ( __strex((unsigned int)PiPnpRtlObjectActionCallback, v6) );
                  __dmb(0xBu);
                  v8 = PiPnpRtlCtx;
                  __dmb(0xBu);
                  v9 = (unsigned int *)(v8 + 160);
                  do
                    v10 = __ldrex(v9);
                  while ( __strex((unsigned int)PiPnpRtlCmActionCallback, v9) );
                  __dmb(0xBu);
                  v11 = PiPnpRtlCtx;
                  __dmb(0xBu);
                  v12 = (unsigned int *)(v11 + 156);
                  do
                    v13 = __ldrex(v12);
                  while ( __strex((unsigned int)PiPnpRtlObjectEventCallback, v12) );
                  __dmb(0xBu);
                  return PiDrvDbInit(a1);
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}
