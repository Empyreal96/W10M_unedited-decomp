// EtwpUpdateTrace 
 
int __fastcall EtwpUpdateTrace(int a1)
{
  int v2; // r9
  int v3; // r5
  int v4; // r2
  int v5; // r3
  int v6; // r0
  _DWORD *v7; // r4
  int v8; // r8
  int v9; // r7
  int v10; // r0
  int v11; // r3
  int v12; // r3
  int v13; // r2
  unsigned int v14; // r5
  unsigned int v15; // r0
  unsigned int v16; // r2
  int v17; // r2
  unsigned int *v18; // r2
  unsigned int v19; // r0
  int v20; // r1
  int v21; // r2
  int v22; // r3
  __int64 v23; // kr00_8
  unsigned int v24; // r1
  __int16 v25; // r3
  unsigned int v27[2]; // [sp+0h] [bp-38h] BYREF
  int v28; // [sp+8h] [bp-30h] BYREF
  int v29; // [sp+Ch] [bp-2Ch]
  int v30[2]; // [sp+10h] [bp-28h] BYREF
  char v31; // [sp+18h] [bp-20h]
  char v32; // [sp+19h] [bp-1Fh]

  v27[0] = 0;
  v28 = 0;
  v29 = 0;
  v2 = 128;
  v3 = EtwpValidateLoggerInfo((_DWORD *)a1);
  if ( v3 < 0 )
    return v3;
  v3 = EtwpValidateFlagExtension((int *)a1);
  if ( v3 < 0 )
    return v3;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(__int16 *)(v4 + 0x134) - 1;
  *(_WORD *)(v4 + 308) = v5;
  v6 = EtwpAcquireLoggerContext(a1, v27, v4, v5);
  v3 = v6;
  if ( v6 >= 0 )
  {
    v7 = (_DWORD *)v27[0];
    v8 = *(_DWORD *)(a1 + 64);
    v9 = *(_DWORD *)(v27[0] + 12);
    if ( (v9 & 0x40) != 0
      || (v8 & 1) != 0 && (v8 & 2) != 0
      || (v8 & 0x4000) != 0 && (v8 & 0x8000) != 0
      || (v9 & 2) == 0 && (v8 & 2) != 0
      || (*(_DWORD *)(a1 + 64) & 6) == 6 )
    {
      goto LABEL_88;
    }
    v27[0] = *(_DWORD *)(a1 + 64) & 0x100;
    if ( (v8 & 0x100) != 0 || (v9 & 0x100) != 0 )
      v2 = 160;
    if ( *(_DWORD *)(a1 + 132) && *(_WORD *)(a1 + 128) )
      v2 |= 0x40u;
    v3 = EtwpCheckLoggerControlAccess(v2, (int)v7);
    if ( v3 < 0 )
      goto LABEL_89;
    if ( *(_DWORD *)(a1 + 132) && *(_WORD *)(a1 + 128) )
    {
      if ( (v9 & 8) != 0 || (v8 & 8) != 0 || (v9 & 0x400) != 0 )
        goto LABEL_88;
      v3 = EtwpCaptureString((unsigned __int16 *)(a1 + 128), (unsigned int)&v28);
      if ( v3 < 0 )
        goto LABEL_89;
      v10 = v7[131];
      if ( v10 )
      {
        ObfDereferenceObject(v10);
        v7[131] = 0;
      }
      v30[0] = 12;
      v30[1] = 2;
      v31 = 1;
      v32 = 1;
      v3 = SeCreateClientSecurity(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, (int)v30, 0, (int)(v7 + 128));
      if ( v3 < 0 )
        goto LABEL_89;
      v7[29] = v28;
      v7[30] = v29;
      v29 = 0;
      EtwpSynchronizeWithLogger((int)v7, 4);
      v3 = EtwpSynchronizeWithLogger((int)v7, 2);
      if ( v3 < 0 || !v7[62] )
        goto LABEL_89;
    }
    if ( (v9 & 0x400) != 0 )
      goto LABEL_40;
    if ( v27[0] )
    {
      v9 |= 0x100u;
      if ( !v7[33] )
      {
        if ( (v9 & 0x10) != 0 )
          v11 = 1000;
        else
          v11 = 1;
        v7[33] = v11;
      }
LABEL_40:
      if ( !memcmp((unsigned int)HeapGuid, (unsigned int)(v7 + 50), 16) )
      {
        v13 = 0;
      }
      else
      {
        if ( memcmp((unsigned int)CritSecGuid, (unsigned int)(v7 + 50), 16) )
        {
LABEL_45:
          if ( v3 < 0 )
            goto LABEL_89;
          v3 = EtwpCheckForStackTracingExtension();
          if ( v3 < 0 )
            goto LABEL_89;
          if ( (v7[3] & 0x2000000) != 0 )
          {
            v3 = EtwpCheckSystemTraceAccess(v7, 128);
            if ( v3 < 0 )
              goto LABEL_89;
            v3 = EtwpCheckForPoolTagFilterExtension((int)v7, a1, 0);
            if ( v3 < 0 )
              goto LABEL_89;
            v3 = EtwpUpdateLoggerGroupMasks((int)v7, a1);
            if ( v3 < 0 )
              goto LABEL_89;
          }
          v14 = *(_DWORD *)(a1 + 56);
          if ( v14 )
          {
            if ( v7[1] )
              v15 = EtwpGetSystemMaximumBufferCount(v7);
            else
              v15 = 0;
            if ( v14 > v15 )
              *(_DWORD *)(a1 + 56) = v15;
            v16 = *(_DWORD *)(a1 + 56);
            if ( v16 > v7[41] )
              v7[41] = v16;
          }
          if ( (v9 & 0x400) == 0 )
          {
            v17 = *(_DWORD *)(a1 + 68);
            if ( v17 )
            {
              if ( v17 != v7[33] )
              {
                v7[33] = v17;
                EtwpSynchronizeWithLogger((int)v7, 4);
              }
            }
          }
          if ( (v8 & 0x80000) != 0 )
          {
            if ( v7[56] == 1 )
            {
              v3 = -1073741637;
LABEL_89:
              RtlFreeAnsiString(&v28);
              v6 = EtwpReleaseLoggerContext(v7, 1);
              goto LABEL_90;
            }
            __dmb(0xBu);
            v18 = v7 + 153;
            do
              v19 = __ldrex(v18);
            while ( __strex(v19 | 0x800, v18) );
            __dmb(0xBu);
            v9 |= 0x80000u;
            if ( !KdDebuggerNotPresent && !KdPitchDebugger || KdEventLoggingPresent )
              EtwpSendDbgId(v7);
          }
          else if ( (v9 & 0x80000) != 0 )
          {
            v9 &= 0xFFF7FFFF;
          }
          if ( (v8 & 0x80) == 0
            || (EtwpGetSecurityDescriptorByGuid(v7 + 50, v27),
                v3 = EtwpUpdateLoggerSecurityDescriptor(v7, v27[0]),
                EtwpFreeSecurityDescriptor(v27),
                v3 >= 0) )
          {
            v7[3] = v9;
            v20 = *(_DWORD *)(a1 + 76);
            if ( v20 )
            {
              if ( v7[33] || (v9 & 0x400) != 0 )
                goto LABEL_85;
              if ( (v9 & 0x10000000) != 0 )
                v21 = 1;
              else
                v21 = KeNumberProcessors_0;
              v22 = v7[41] - v21 - 1;
              if ( v20 > v22 )
                *(_DWORD *)(a1 + 76) = v22;
              if ( *(int *)(a1 + 76) < 0 )
LABEL_85:
                *(_DWORD *)(a1 + 76) = 0;
            }
            v7[34] = *(_DWORD *)(a1 + 76);
            v3 = EtwpGetLoggerInfoFromContext(a1, v7);
            v23 = *(_QWORD *)&EtwpEventTracingProvRegHandle;
            if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_UPDATE_TRACE) )
              EtwpEventWriteTemplateSession(v23, HIDWORD(v23), ETW_EVENT_UPDATE_TRACE, v7);
          }
          goto LABEL_89;
        }
        v13 = 1;
      }
      v3 = EtwpUpdatePerProcessTracing(a1, *v7, v13, v12);
      goto LABEL_45;
    }
    if ( (v9 & 0x100) == 0 )
      goto LABEL_40;
    if ( v7[148] )
    {
      v9 &= 0xFFFFFEFF;
      EtwpSynchronizeWithLogger((int)v7, 8);
      goto LABEL_40;
    }
LABEL_88:
    v3 = -1073741811;
    goto LABEL_89;
  }
LABEL_90:
  v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v25 = *(_WORD *)(v24 + 0x134) + 1;
  *(_WORD *)(v24 + 308) = v25;
  if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
    KiCheckForKernelApcDelivery(v6);
  return v3;
}
