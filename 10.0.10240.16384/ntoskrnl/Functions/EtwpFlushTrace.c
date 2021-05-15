// EtwpFlushTrace 
 
int __fastcall EtwpFlushTrace(int a1)
{
  int v2; // r6
  int v3; // r4
  int v4; // r2
  int v5; // r3
  int v6; // r5
  int v7; // r2
  int v8; // r8
  unsigned int *v9; // r2
  unsigned int v10; // r0
  _DWORD *v11; // r2
  int v12; // r3
  int v13; // r0
  __int64 v14; // kr00_8
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  int v19; // [sp+0h] [bp-28h] BYREF
  int v20; // [sp+8h] [bp-20h] BYREF
  int v21; // [sp+Ch] [bp-1Ch]

  v19 = 0;
  v20 = 0;
  v21 = 0;
  v2 = 128;
  v3 = EtwpValidateLoggerInfo((_DWORD *)a1);
  if ( v3 < 0 )
    return v3;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(__int16 *)(v4 + 0x134) - 1;
  *(_WORD *)(v4 + 308) = v5;
  v3 = EtwpAcquireLoggerContext(a1, &v19, v4, v5);
  if ( v3 >= 0 )
  {
    v6 = v19;
    v7 = *(_DWORD *)(v19 + 12);
    if ( (v7 & 0x40000) != 0 )
    {
      v3 = -1073741637;
    }
    else
    {
      if ( (v7 & 0x100) != 0 )
        v2 = 160;
      if ( *(_DWORD *)(v19 + 592) )
        v2 |= 0x40u;
      v8 = *(_DWORD *)(v19 + 12) & 0x400;
      if ( (v7 & 0x400) != 0 )
      {
        if ( !*(_DWORD *)(a1 + 132) || !*(_WORD *)(a1 + 128) )
        {
          v3 = -1073741809;
          goto LABEL_30;
        }
        v2 |= 0x40u;
      }
      v3 = EtwpCheckLoggerControlAccess(v2, v19);
      if ( v3 >= 0 )
      {
        if ( v8 )
        {
          v3 = EtwpCaptureString((unsigned __int16 *)(a1 + 128), (unsigned int)&v20);
          if ( v3 < 0 )
            goto LABEL_30;
          *(_DWORD *)(v6 + 116) = v20;
          *(_DWORD *)(v6 + 120) = v21;
          v21 = 0;
          __dmb(0xBu);
          v9 = (unsigned int *)(v6 + 612);
          do
            v10 = __ldrex(v9);
          while ( __strex(v10 | 1, v9) );
          __dmb(0xBu);
          if ( (*(_DWORD *)(v6 + 12) & 0x2000000) != 0 )
          {
            v11 = &EtwpGroupMasks[8 * *(unsigned __int8 *)(v6 + 610)];
            if ( v11 )
            {
              v12 = v11[1];
              if ( (v12 & 4) != 0 && v11 && (v12 & 0x100) != 0 )
                EtwpCCSwapStop(*(_DWORD *)(v6 + 124), 0, v11);
            }
          }
          v13 = EtwpBufferingModeFlush(v6);
        }
        else
        {
          v13 = EtwpSynchronizeWithLogger(v6, 4);
        }
        v3 = v13;
        if ( v13 >= 0 )
        {
          v3 = EtwpGetLoggerInfoFromContext(a1, (int *)v6);
          v14 = *(_QWORD *)&EtwpEventTracingProvRegHandle;
          if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_FLUSH_TRACE) )
            EtwpEventWriteTemplateSession(v14, HIDWORD(v14), ETW_EVENT_FLUSH_TRACE, v6);
        }
        goto LABEL_30;
      }
    }
LABEL_30:
    EtwpReleaseLoggerContext((_DWORD *)v6, 1);
  }
  v15 = RtlFreeAnsiString(&v20);
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v17 = *(_WORD *)(v16 + 0x134) + 1;
  *(_WORD *)(v16 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
    KiCheckForKernelApcDelivery(v15);
  return v3;
}
