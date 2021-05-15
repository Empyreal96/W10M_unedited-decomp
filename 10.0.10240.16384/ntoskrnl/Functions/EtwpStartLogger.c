// EtwpStartLogger 
 
int __fastcall EtwpStartLogger(int a1)
{
  int v2; // r9
  int v3; // r4
  unsigned int v4; // r7
  int v6; // r4
  int v7; // r1
  int v8; // r2
  int v9; // r3
  unsigned int v10; // r4
  int v11; // r0
  _DWORD *v12; // r5
  unsigned int v13; // r9
  unsigned int *v14; // r1
  unsigned int v15; // r2
  unsigned int *v16; // r6
  int v17; // r1
  int v18; // r2
  int v19; // r3
  int v20; // r3
  int v21; // r2
  unsigned int v22; // r3
  unsigned int v23; // r3
  unsigned int v24; // r3
  unsigned int v25; // r3
  unsigned int v26; // r3
  unsigned int *v27; // r2
  unsigned int v28; // r0
  unsigned int v29; // r2
  int v30; // r3
  unsigned int v31; // r2
  unsigned int v32; // r0
  unsigned int v33; // r1
  unsigned __int64 v34; // kr00_8
  int v35; // r3
  unsigned int v36; // r3
  unsigned int v37; // r1
  __int64 v38; // kr08_8
  int i; // r1
  unsigned int v40; // r3
  int v41; // r0
  unsigned int v42; // r3
  unsigned __int8 *v43; // r3
  unsigned int v44; // r2
  unsigned int *v45; // r2
  unsigned int v46; // r0
  int v47; // r0
  unsigned int *v48; // r1
  unsigned int v49; // r2
  __int16 *v50; // r1
  unsigned int v51; // r1
  int v52; // r0
  __int64 v53; // kr10_8
  int v54; // r2
  int v55; // [sp+10h] [bp-60h]
  _DWORD v56[2]; // [sp+18h] [bp-58h] BYREF
  int v57; // [sp+20h] [bp-50h] BYREF
  unsigned int v58; // [sp+24h] [bp-4Ch] BYREF
  unsigned int v59; // [sp+28h] [bp-48h] BYREF
  unsigned int v60; // [sp+2Ch] [bp-44h]
  int v61; // [sp+30h] [bp-40h]
  unsigned int v62; // [sp+38h] [bp-38h] BYREF
  int v63; // [sp+3Ch] [bp-34h]
  int v64; // [sp+40h] [bp-30h]
  int v65; // [sp+44h] [bp-2Ch]
  int v66; // [sp+48h] [bp-28h]
  int v67; // [sp+4Ch] [bp-24h]

  v2 = 128;
  v61 = 128;
  v58 = 0;
  v55 = 8;
  RtlInitUnicodeString((unsigned int)v56, 0);
  RtlInitUnicodeString((unsigned int)&v59, 0);
  v3 = *(_DWORD *)(a1 + 64);
  v4 = v3 & 0x99ECE5FF;
  if ( (v3 & 3) == 0 && ((v3 & 8) != 0 || (v3 & 4) != 0) )
    v4 |= 1u;
  if ( (v4 & 0x40000) != 0 )
    return sub_8093D4();
  if ( (v4 & 0x80000) != 0 && (v4 & 0x1000000) != 0 )
    v4 &= 0xFEFFFFFF;
  if ( (v4 & 0x400) != 0 )
  {
    if ( *(_DWORD *)(a1 + 132) || (v4 & 0x4000F) != 0 )
      goto LABEL_117;
    if ( (v4 & 0x100) != 0 )
      v4 &= 0xFFFFFEFF;
    if ( *(_DWORD *)(a1 + 68) )
      *(_DWORD *)(a1 + 68) = 0;
    if ( *(_DWORD *)(a1 + 76) )
      *(_DWORD *)(a1 + 76) = 0;
  }
  if ( (v4 & 3) == 3
    || (v4 & 0xC000) == 49152
    || (v4 & 0x700) == 0 && !*(_DWORD *)(a1 + 132)
    || (v4 & 6) == 6
    || (v4 & 2) != 0 && !*(_DWORD *)(a1 + 60)
    || (v4 & 0x20) != 0 && (!*(_DWORD *)(a1 + 60) || (v3 & 0xC) != 0)
    || (v4 & 0x40) != 0
    && ((*(_DWORD *)(a1 + 112) & 2) == 0 || (v4 & 0x402) == 0 && ((v4 & 0x100) == 0 || *(_DWORD *)(a1 + 132)))
    || (v4 & 0xC00000) == 12582912
    || (v4 & 8) != 0
    && (!*(_DWORD *)(a1 + 132)
     || (v4 & 2) != 0
     || !*(_DWORD *)(a1 + 60)
     || (*(_DWORD *)(a1 + 112) & 2) != 0
     || (v3 & 0x2000000) != 0
     || !memcmp(a1 + 24, (unsigned int)SystemTraceControlGuid, 16)
     || !memcmp(a1 + 24, (unsigned int)CKCLGuid, 16)
     || (v4 & 4) != 0)
    || (v3 & 0x3000000) == 50331648
    || (v3 & 0x4000000) != 0
    || (v3 & 0x10000) != 0 )
  {
    goto LABEL_117;
  }
  v6 = EtwpValidateFlagExtension((int *)a1);
  if ( v6 < 0 )
    goto LABEL_231;
  if ( (v4 & 0x100) != 0 )
  {
    v2 = 160;
    v61 = 160;
  }
  if ( *(_WORD *)(a1 + 128) )
    v61 = v2 | 0x40;
  if ( !*(_WORD *)(a1 + 144) || !*(_DWORD *)(a1 + 148) )
    goto LABEL_117;
  v6 = EtwpCaptureString(a1 + 144, v56);
  if ( v6 )
    goto LABEL_231;
  if ( !EtwpLookupLoggerIdByName((unsigned __int16 *)v56) )
    goto LABEL_172;
  if ( !memcmp(a1 + 24, (unsigned int)&NullGuid, 16) )
  {
    v6 = ExUuidCreate((int)&v62);
    if ( v6 < 0 )
      goto LABEL_231;
  }
  else
  {
    v7 = *(_DWORD *)(a1 + 28);
    v8 = *(_DWORD *)(a1 + 32);
    v9 = *(_DWORD *)(a1 + 36);
    v62 = *(_DWORD *)(a1 + 24);
    v63 = v7;
    v64 = v8;
    v65 = v9;
  }
  if ( (v4 & 0xC00000) == 0 )
  {
    if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A)
      && MmGetSessionId(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74)) )
    {
      v4 |= 0x400000u;
    }
    else
    {
      v4 |= 0x800000u;
    }
  }
  if ( !memcmp((unsigned int)&v62, (unsigned int)SystemTraceControlGuid, 16)
    || !memcmp((unsigned int)&v62, (unsigned int)CKCLGuid, 16) )
  {
    RtlFreeAnsiString(v56);
    if ( !memcmp((unsigned int)&v62, (unsigned int)SystemTraceControlGuid, 16) )
    {
      v50 = L"NT Kernel Logger";
      v55 = 0;
      v13 = 0;
    }
    else
    {
      v50 = L"Circular Kernel Context Logger";
      v55 = 1;
      v13 = 2;
    }
    if ( !RtlCreateUnicodeString((int)v56, (unsigned __int16 *)v50) )
      goto LABEL_208;
    v4 |= 0x80u;
    if ( (v4 & 0x1000000) == 0 )
    {
      __dmb(0xBu);
      v45 = &WmipLoggerContext[v13];
      goto LABEL_178;
    }
    goto LABEL_117;
  }
  if ( !memcmp((unsigned int)&v62, (unsigned int)GlobalLoggerGuid, 16) )
  {
    v13 = 1;
    if ( EtwpGetFlagExtension(a1, 1) )
    {
      if ( (v4 & 0x1000000) != 0 )
        goto LABEL_117;
      RtlFreeAnsiString(v56);
      if ( !RtlCreateUnicodeString((int)v56, L"NT Kernel Logger") )
        goto LABEL_208;
      v55 = 0;
    }
    __dmb(0xBu);
    v45 = &WmipLoggerContext[1];
    goto LABEL_178;
  }
  if ( !memcmp((unsigned int)&v62, (unsigned int)AuditLoggerGuid, 16) )
  {
    if ( (v4 & 0x1000000) == 0 )
    {
      RtlFreeAnsiString(v56);
      if ( RtlCreateUnicodeString((int)v56, L"Eventlog-Security") )
      {
        v4 |= 0x80u;
        if ( PsIsCurrentThreadInServerSilo() )
        {
          PsGetMonitorContextServerSilo(EtwSiloMonitor, -1, &v57);
          v47 = v57;
          if ( *(_DWORD *)(v57 + 360) == 64 )
          {
            v13 = 4;
            v48 = &WmipLoggerContext[4];
            do
            {
              __dmb(0xBu);
              do
                v49 = __ldrex(v48);
              while ( v49 == 1 && __strex((unsigned int)WmipLoggerContext + 1, v48) );
              __dmb(0xBu);
              if ( v49 == 1 )
                break;
              ++v13;
              ++v48;
            }
            while ( v13 < 0x40 );
            if ( v13 != 64 )
            {
              *(_DWORD *)(v47 + 360) = v13;
              *(_WORD *)(v47 + 102) = v13;
              PsDereferenceMonitorContextServerSilo(v47);
              goto LABEL_49;
            }
            v6 = -1073741670;
          }
          else
          {
            v6 = -1073741771;
          }
          PsDereferenceMonitorContextServerSilo(v47);
          goto LABEL_231;
        }
        v13 = 3;
        __dmb(0xBu);
        v45 = &WmipLoggerContext[3];
        do
LABEL_178:
          v46 = __ldrex(v45);
        while ( v46 == 1 && __strex((unsigned int)WmipLoggerContext + 1, v45) );
        __dmb(0xBu);
        if ( v46 != 1 )
          goto LABEL_172;
LABEL_49:
        ExAcquireRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v13], 1);
        EtwpGetSecurityDescriptorByGuid((int *)&v62, &v58);
        v6 = EtwpAccessCheck(v58, v61, 0);
        if ( v6 >= 0 )
        {
          if ( (*(_DWORD *)(a1 + 64) & 0x2000000) == 0 || v55 != 8 )
            goto LABEL_51;
          v6 = EtwpCheckCurrentUserGuidAccess(SystemTraceControlGuid, 128);
          if ( v6 >= 0 )
          {
            for ( i = 2; (unsigned int)i < 8; ++i )
            {
              if ( ((*((unsigned __int8 *)&EtwpActiveSystemLoggers + (i >> 3)) >> (i & 7)) & 1) == 0 )
                break;
            }
            v55 = i;
            if ( i == 8 )
            {
              v6 = -1073741670;
              goto LABEL_230;
            }
LABEL_51:
            v16 = (unsigned int *)EtwpInitLoggerContext(v56, v4);
            RtlFreeAnsiString(v56);
            if ( !v16 )
            {
              v6 = -1073741801;
              goto LABEL_230;
            }
            v17 = v63;
            v18 = v64;
            v19 = v65;
            v16[50] = v62;
            v16[51] = v17;
            v16[52] = v18;
            v16[53] = v19;
            v16[54] = *(_DWORD *)(a1 + 60);
            v16[31] = *(_DWORD *)(a1 + 40);
            v20 = *(_DWORD *)(a1 + 68);
            if ( !v20 )
            {
              if ( (v4 & 0x100) == 0 )
              {
LABEL_54:
                v21 = *(_DWORD *)(a1 + 76);
                if ( v21 && (v16[33] || v21 < 0) )
                  *(_DWORD *)(a1 + 76) = 0;
                v22 = *(_DWORD *)(a1 + 76);
                *v16 = v13;
                v16[34] = v22;
                if ( *(_WORD *)(a1 + 128) )
                {
                  if ( *(_DWORD *)(a1 + 132) )
                  {
                    v6 = EtwpCaptureString(a1 + 128, &v59);
                    if ( v6 < 0 )
                      goto LABEL_217;
                  }
                }
                if ( (*(_DWORD *)(a1 + 112) & 2) != 0 )
                {
                  v16[55] = *(_DWORD *)(a1 + 96);
                  *(_DWORD *)(a1 + 96) = 0;
                }
                if ( (v16[3] & 8) != 0 )
                {
                  v16[27] = v59;
                  v16[28] = v60;
                  RtlInitUnicodeString((unsigned int)&v59, 0);
                  v6 = EtwpGenerateFileName(v16 + 27, v16 + 55, v16 + 25);
                  if ( v6 < 0 )
                    goto LABEL_217;
                }
                else
                {
                  v16[25] = v59;
                  v16[26] = v60;
                  RtlInitUnicodeString((unsigned int)&v59, 0);
                }
                v62 = 12;
                v63 = 2;
                LOWORD(v64) = 257;
                v6 = SeCreateClientSecurity(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, (int)&v62, 0, (int)(v16 + 128));
                if ( v6 >= 0 )
                {
                  v23 = v16[152];
                  if ( (v16[3] & 0x100) != 0 )
                    v40 = v23 | 8;
                  else
                    v40 = v23 & 0xFFFFFFF7;
                  v16[152] = v40;
                  if ( (*(_DWORD *)(a1 + 112) & 2) != 0 )
                    v16[152] |= 2u;
                  if ( (*(_DWORD *)(a1 + 112) & 1) != 0 )
                    v16[152] |= 1u;
                  if ( (*(_DWORD *)(a1 + 112) & 0x4000) != 0 )
                    v16[152] |= 0x4000u;
                  EtwpInitializeTimeStamp((int)v16);
                  if ( (unsigned int)v55 < 8 )
                  {
                    v41 = EtwpAllocateTimeStampIndex(v16[31]);
                    if ( v41 == 2 )
                    {
                      v6 = -1073741670;
                      goto LABEL_217;
                    }
                    v42 = v16[3];
                    *((_BYTE *)v16 + 610) = v55;
                    v16[3] = v42 | 0x2000000;
                    if ( (unsigned int)v55 <= 1 )
                      v16[152] |= 0x20u;
                    EtwpSystemLogger[2 * v55] = v13;
                    EtwpSystemLogger[2 * v55 + 1] = v41;
                    __dmb(0xBu);
                    v43 = (unsigned __int8 *)&EtwpActiveSystemLoggers + (v55 >> 3);
                    do
                      v44 = __ldrex(v43);
                    while ( __strex(v44 | (1 << (v55 & 7)), v43) );
                    __dmb(0xBu);
                  }
                  v6 = EtwpCheckForStackTracingExtension();
                  if ( v6 >= 0 )
                  {
                    v24 = *(_DWORD *)(a1 + 52);
                    if ( v24 )
                      v16[38] = v24;
                    v25 = *(_DWORD *)(a1 + 56);
                    if ( v25 )
                      v16[41] = v25;
                    v26 = *(_DWORD *)(a1 + 48);
                    if ( v26 )
                    {
                      if ( v26 > 0x4000 )
                        *(_DWORD *)(a1 + 48) = 0x4000;
                      v16[1] = *(_DWORD *)(a1 + 48) << 10;
                    }
                    if ( !*((_WORD *)v16 + 50) )
                      goto LABEL_86;
                    __dmb(0xBu);
                    v27 = v16 + 153;
                    do
                      v28 = __ldrex(v27);
                    while ( __strex(v28 | 1, v27) );
                    __dmb(0xBu);
                    v16[9] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
                    v6 = EtwpCreateLogFile(v16, 0);
                    if ( v6 >= 0 )
                    {
LABEL_86:
                      v29 = v16[1];
                      if ( v29 < 0x1000 && (*((_WORD *)v16 + 50) || (v16[3] & 0x400) != 0) )
                        v16[152] |= 0x1000u;
                      v30 = v29 - 72;
                      if ( v29 - 72 >= 0xFFFF )
                        v30 = 0xFFFF;
                      v16[2] = v30 & 0xFFFFFFF8;
                      v6 = EtwpAllocateTraceBufferPool(v16);
                      if ( v6 >= 0 )
                      {
                        v31 = v16[54];
                        if ( !v31 || (v16[3] & 0x2000) != 0 )
                        {
                          v33 = 10485760;
                          v32 = 0;
                        }
                        else
                        {
                          v34 = (unsigned __int64)v31 << 20;
                          v32 = HIDWORD(v34);
                          v33 = v34;
                        }
                        v35 = v16[41] * v16[1];
                        if ( !v32 && v33 <= 2 * v35 )
                        {
                          v33 = 2 * v35;
                          v32 = 0;
                        }
                        v16[80] = v33;
                        v16[81] = v32;
                        v6 = ObLogSecurityDescriptor(v58, &v57, 8);
                        if ( v6 >= 0 )
                        {
                          if ( v57 )
                            v36 = v57 + 7;
                          else
                            v36 = 0;
                          v16[144] = v36;
                        }
                        EtwpFreeSecurityDescriptor(&v58);
                        if ( v6 >= 0 )
                        {
                          __dmb(0xBu);
                          do
                            v37 = __ldrex((unsigned int *)&dword_61AD6C);
                          while ( __strex(v37 + 1, (unsigned int *)&dword_61AD6C) );
                          __dmb(0xBu);
                          ExAcquireRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v13], 1);
                          if ( (v16[3] & 0x400) == 0 )
                          {
                            v62 = 24;
                            v63 = 0;
                            v65 = 512;
                            v64 = 0;
                            v66 = 0;
                            v67 = 0;
                            v6 = PsCreateSystemThread((int)&v57, 0x1FFFFF, (int)&v62);
                            if ( v6 < 0 )
                            {
                              ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v13], 1);
LABEL_240:
                              EtwpFreeLoggerContext(v16);
                              return v6;
                            }
                            ZwClose();
                            v6 = KeWaitForSingleObject((unsigned int)(v16 + 89), 0, 0, 0, 0);
                          }
                          v38 = *(_QWORD *)&EtwpEventTracingProvRegHandle;
                          if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_START_TRACE) )
                            EtwpEventWriteTemplateSession(v38, HIDWORD(v38), ETW_EVENT_START_TRACE, v16);
                          KeWaitForSingleObject((unsigned int)(v16 + 118), 0, 0, 0, 0);
                          WmipLoggerContext[v13] = v16;
                          EtwpSendSessionNotification(v16, 5, 0);
                          if ( (v16[3] & 0x2000000) != 0 )
                          {
                            v6 = EtwpCheckForPoolTagFilterExtension(v16, a1, 1);
                            if ( v6 < 0
                              || (EtwpUpdateTagFilter(0, 0, &EtwpObjectTypeFilter[10 * v55]),
                                  v6 = EtwpUpdateLoggerGroupMasks(v16, a1),
                                  v6 < 0) )
                            {
                              v16[10] = v6;
                              EtwpStopLoggerInstance(v16);
                              if ( (v16[3] & 0x400) != 0 )
                              {
                                EtwpGetLoggerInfoFromContext(a1, v16);
                                EtwpReleaseLoggerContext(v16, 1);
                                goto LABEL_240;
                              }
                            }
                          }
                          if ( !memcmp((unsigned int)HeapGuid, (unsigned int)(v16 + 50), 16) )
                          {
                            v54 = 0;
                          }
                          else
                          {
                            if ( memcmp((unsigned int)CritSecGuid, (unsigned int)(v16 + 50), 16) )
                            {
LABEL_111:
                              EtwpGetLoggerInfoFromContext(a1, v16);
                              EtwpReleaseLoggerContext(v16, 1);
                              return v6;
                            }
                            v54 = 1;
                          }
                          v6 = EtwpUpdatePerProcessTracing(a1, *v16, v54);
                          goto LABEL_111;
                        }
                      }
                      EtwpFreeTraceBufferPool(v16);
                    }
                  }
                }
LABEL_217:
                if ( (v16[3] & 0x2000000) != 0 )
                  EtwpFreeSystemLoggerIndex(v55);
                if ( (v16[152] & 0x80) != 0 )
                  ExFreePoolWithTag(v16[155]);
                if ( (v16[152] & 0x2000) != 0 )
                {
                  __dmb(0xBu);
                  do
                    v51 = __ldrex((unsigned int *)&dword_61ABF8);
                  while ( __strex(v51 - 1, (unsigned int *)&dword_61ABF8) );
                  __dmb(0xBu);
                }
                RtlFreeAnsiString(v16 + 25);
                RtlFreeAnsiString(v16 + 27);
                if ( v16[148] )
                  ZwClose();
                v52 = v16[163];
                if ( v52 )
                  PspDereferenceSiloObject(v52);
                ExFreePoolWithTag((unsigned int)v16);
                goto LABEL_230;
              }
              if ( (v4 & 0x10) != 0 )
                v20 = 1000;
              else
                v20 = 1;
            }
            v16[33] = v20;
            goto LABEL_54;
          }
        }
LABEL_230:
        ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v13], 1);
        WmipLoggerContext[v13] = 1;
        goto LABEL_231;
      }
LABEL_208:
      v6 = -1073741801;
      goto LABEL_231;
    }
LABEL_117:
    v6 = -1073741811;
    goto LABEL_231;
  }
  if ( !wcsicmp(v56[1], L"Eventlog-Security") && memcmp((unsigned int)&v62, (unsigned int)AuditLoggerGuid, 16) )
    goto LABEL_172;
  v10 = 4;
  while ( 1 )
  {
    v11 = EtwpAcquireLoggerContextByLoggerId(v10, 0);
    v12 = (_DWORD *)v11;
    if ( v11 )
      break;
LABEL_40:
    if ( ++v10 >= 0x40 )
      goto LABEL_41;
  }
  if ( memcmp(v11 + 200, (unsigned int)&v62, 16) )
  {
    EtwpReleaseLoggerContext(v12, 0);
    goto LABEL_40;
  }
  EtwpReleaseLoggerContext(v12, 0);
LABEL_41:
  if ( v10 < 0x40 )
  {
LABEL_172:
    v6 = -1073741771;
    goto LABEL_231;
  }
  v13 = 4;
  v14 = &WmipLoggerContext[4];
  do
  {
    __dmb(0xBu);
    do
      v15 = __ldrex(v14);
    while ( v15 == 1 && __strex((unsigned int)WmipLoggerContext + 1, v14) );
    __dmb(0xBu);
    if ( v15 == 1 )
      break;
    ++v13;
    ++v14;
  }
  while ( v13 < 0x40 );
  if ( v13 < 0x40 )
    goto LABEL_49;
  v6 = -1073741670;
LABEL_231:
  v53 = *(_QWORD *)&EtwpEventTracingProvRegHandle;
  if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_SESSION_START_FAILED) )
    EtwpEventWriteTemplateAdmin(v53, HIDWORD(v53), ETW_EVENT_SESSION_START_FAILED);
  RtlFreeAnsiString(v56);
  RtlFreeAnsiString(&v59);
  EtwpFreeSecurityDescriptor(&v58);
  return v6;
}
