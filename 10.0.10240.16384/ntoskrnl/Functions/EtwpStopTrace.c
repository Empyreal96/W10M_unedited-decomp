// EtwpStopTrace 
 
int __fastcall EtwpStopTrace(_DWORD *a1, int a2)
{
  int v4; // r4
  unsigned int v5; // r2
  int v6; // r0
  unsigned int v7; // r1
  int v8; // r3
  int *v9; // r5
  int v11; // r7
  unsigned int v12; // r8
  __int64 v13; // kr00_8
  int *v14; // [sp+8h] [bp-30h] BYREF
  int v15[10]; // [sp+10h] [bp-28h] BYREF

  v14 = 0;
  v15[0] = -2000000000;
  v15[1] = -1;
  v4 = EtwpValidateLoggerInfo(a1);
  if ( v4 >= 0 )
  {
    v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v5 + 308);
    v6 = EtwpAcquireLoggerContext(a1, &v14);
    v4 = v6;
    if ( v6 >= 0 )
    {
      v9 = v14;
      if ( a2 )
        goto LABEL_9;
      if ( (v14[3] & 0x40) != 0 )
        return sub_7EE12C();
      v4 = EtwpCheckLoggerControlAccess(128, v14);
      if ( v4 >= 0 )
      {
LABEL_9:
        v11 = *v9;
        if ( (v9[3] & 0x400) != 0 )
        {
          v4 = EtwpStopLoggerInstance(v9);
          v6 = EtwpReleaseLoggerContext(v9, 1);
          if ( v4 >= 0 )
          {
            v4 = EtwpGetLoggerInfoFromContext((int)a1, v9);
            v6 = EtwpFreeLoggerContext(v9);
          }
        }
        else
        {
          v12 = v9[9];
          ObReferenceObjectByPointer(v12, 0x100000, PsThreadType, 0);
          KeResetEvent((int)(v9 + 89));
          if ( ExAcquireRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v11], 1) )
          {
            v4 = EtwpStopLoggerInstance(v9);
            if ( v4 < 0 )
              ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v11], 1);
          }
          else
          {
            v4 = -2147483611;
          }
          EtwpReleaseLoggerContext(v9, 1);
          if ( v4 >= 0 )
          {
            if ( v9[10] >= 0 )
            {
              while ( KeWaitForSingleObject((unsigned int)(v9 + 89), 0, 0, 0, v15) == 258 )
                ;
            }
            v4 = EtwpGetLoggerInfoFromContext((int)a1, v9);
            if ( v4 >= 0 )
            {
              v4 = v9[10];
              v13 = *(_QWORD *)&EtwpEventTracingProvRegHandle;
              if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_STOP_TRACE) )
                EtwpEventWriteTemplateSession(v13, HIDWORD(v13), ETW_EVENT_STOP_TRACE, v9);
            }
            ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v11], 1);
            if ( v4 >= 0 )
              KeWaitForSingleObject(v12, 0, 0, 0, 0);
          }
          v6 = ObfDereferenceObject(v12);
        }
      }
      else
      {
        v6 = EtwpReleaseLoggerContext(v9, 1);
      }
    }
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v8 = (__int16)(*(_WORD *)(v7 + 0x134) + 1);
    *(_WORD *)(v7 + 308) = v8;
    if ( !v8 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
      KiCheckForKernelApcDelivery(v6);
  }
  return v4;
}
