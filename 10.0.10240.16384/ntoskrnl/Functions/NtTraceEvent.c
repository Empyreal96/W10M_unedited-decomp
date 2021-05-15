// NtTraceEvent 
 
int __fastcall NtTraceEvent(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v7; // r3
  int v8; // r4
  int v9; // r0
  _DWORD *v10; // r10
  int v12; // r0
  int v13; // r8
  int v14; // r8
  int v15; // r3
  int v16; // r0
  unsigned int v17; // r2
  int v18; // r2
  unsigned int v19; // r4
  int v20; // r8
  int v21; // r6
  unsigned int v22; // r2
  int v23; // r0
  int v24; // r2
  unsigned int v25; // r1
  int v26; // r3
  int v27; // r2
  BOOL v28; // r3
  int v29; // r0
  unsigned int v30; // r1
  int v31; // r3
  _BYTE *v32; // r3
  int v33; // r1
  int v34; // r2
  int v35; // r3
  int v36; // r0
  int v37; // r4
  _BYTE *v38; // r2
  unsigned int v39; // r1
  int v40; // r4
  int v41; // r10
  _BYTE v43[3]; // [sp+45h] [bp-E3h] BYREF
  int v44; // [sp+48h] [bp-E0h]
  int v45; // [sp+4Ch] [bp-DCh]
  int v46; // [sp+50h] [bp-D8h]
  int v47; // [sp+54h] [bp-D4h]
  unsigned int *v48; // [sp+58h] [bp-D0h]
  int v49; // [sp+5Ch] [bp-CCh]
  _DWORD *v50; // [sp+60h] [bp-C8h] BYREF
  __int64 v51; // [sp+68h] [bp-C0h]
  int v52; // [sp+70h] [bp-B8h] BYREF
  int v53; // [sp+78h] [bp-B0h]
  int v54; // [sp+7Ch] [bp-ACh]
  int v55; // [sp+80h] [bp-A8h]
  int v56; // [sp+84h] [bp-A4h]
  unsigned int v57; // [sp+88h] [bp-A0h]
  int v58; // [sp+8Ch] [bp-9Ch]
  int v59; // [sp+90h] [bp-98h]
  int v60; // [sp+94h] [bp-94h]
  __int64 v61; // [sp+98h] [bp-90h]
  _DWORD *v62; // [sp+A0h] [bp-88h]
  int v63; // [sp+A8h] [bp-80h]
  int v64; // [sp+ACh] [bp-7Ch]
  int v65; // [sp+B0h] [bp-78h]
  int v66; // [sp+B4h] [bp-74h]
  int v67; // [sp+B8h] [bp-70h]
  int v68; // [sp+C0h] [bp-68h]
  int v69; // [sp+C4h] [bp-64h]
  int v70; // [sp+C8h] [bp-60h]
  int v71; // [sp+CCh] [bp-5Ch]
  int v72; // [sp+D0h] [bp-58h]
  unsigned int v73; // [sp+D4h] [bp-54h]
  int v74; // [sp+D8h] [bp-50h]
  int v75; // [sp+E0h] [bp-48h]
  int v76; // [sp+E4h] [bp-44h]
  _DWORD v77[4]; // [sp+E8h] [bp-40h] BYREF
  _DWORD _F8[18]; // [sp+F8h] [bp-30h] BYREF

  _F8[14] = a1;
  _F8[17] = a4;
  _F8[16] = a3;
  _F8[15] = a2;
  v52 = a1;
  LODWORD(v51) = a4;
  v7 = a2 & 0xFF00;
  if ( v7 == 768 )
  {
    if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    {
      if ( (a4 & 7) != 0 )
        ((void (*)(void))ExRaiseDatatypeMisalignment)();
      if ( a4 + 120 > MmUserProbeAddress || a4 + 120 < a4 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
    v46 = *(_DWORD *)(a4 + 88);
    v74 = v46;
    v47 = *(_DWORD *)(a4 + 84);
    v67 = v47;
    v49 = *(unsigned __int16 *)(a4 + 82);
    v65 = v49;
    v48 = 0;
    v66 = 0;
    v50 = *(_DWORD **)(a4 + 112);
    v62 = v50;
    v44 = *(_DWORD *)(a4 + 48);
    v45 = *(_DWORD *)(a4 + 52);
    v68 = v44;
    v69 = v45;
    v53 = *(unsigned __int8 *)(a4 + 44);
    v43[1] = v53;
    v57 = 0;
    if ( *(_BYTE *)(a4 + 80) )
      v57 = a4 + 96;
    v13 = ObReferenceObjectByHandle(a1, 2048, EtwpRegistrationObjectType, 1, &v52, 0);
    if ( v13 >= 0 )
    {
      v75 = 0;
      v76 = 0;
      v40 = v52;
      v41 = *(_DWORD *)(v52 + 16);
      v52 = *(_DWORD *)(v52 + 20);
      v61 = 0i64;
      if ( *(_BYTE *)(v40 + 51) )
        v13 = EtwpWriteUserEvent(v41);
      if ( *(_BYTE *)(v40 + 52) )
        v13 = EtwpWriteUserEvent(v41);
      ObfDereferenceObjectWithTag(v40, 1953261124);
    }
    return v13;
  }
  if ( v7 != 512 )
  {
    if ( v7 > 0x600 )
    {
      if ( v7 != 1792 )
      {
        if ( v7 == 2048 )
          return EtwTraceEvent(
                   a1,
                   a1 >> 31,
                   a4,
                   72,
                   -1073020928,
                   *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A));
        return -1073741811;
      }
      if ( a1 )
      {
        if ( (a4 & 7) != 0 )
          ((void (*)(void))ExRaiseDatatypeMisalignment)();
        v32 = (_BYTE *)MmUserProbeAddress;
        if ( a4 + 120 > MmUserProbeAddress || a4 + 120 < a4 )
        {
          *(_BYTE *)MmUserProbeAddress = 0;
          v32 = (_BYTE *)MmUserProbeAddress;
        }
        if ( (a1 & 3) != 0 )
          ((void (*)(void))ExRaiseDatatypeMisalignment)();
        if ( a1 + 16 > (unsigned int)v32 || a1 + 16 < (unsigned int)a1 )
          *v32 = 0;
        v56 = *(_DWORD *)(a4 + 88);
        v55 = *(_DWORD *)(a4 + 84);
        v46 = *(_DWORD *)(a4 + 112);
        v58 = v46;
        v45 = *(_DWORD *)(a4 + 48);
        v44 = *(_DWORD *)(a4 + 52);
        v59 = v45;
        v60 = v44;
        v47 = *(unsigned __int8 *)(a4 + 44);
        v33 = *(_DWORD *)(a1 + 4);
        v34 = *(_DWORD *)(a1 + 8);
        v35 = *(_DWORD *)(a1 + 12);
        _F8[0] = *(_DWORD *)a1;
        _F8[1] = v33;
        _F8[2] = v34;
        _F8[3] = v35;
        v36 = EtwpFindGuidEntryByGuid(_F8, 0);
        v37 = v36;
        if ( v36 )
        {
          if ( *(_DWORD *)(v36 + 56) )
          {
            v13 = EtwpAccessCheck(*(_DWORD *)(v36 + 36), 2048, 0);
            if ( v13 >= 0 )
            {
              v43[0] = 0;
              KeWaitForSingleObject(&EtwpNotificationMutex, 0, 0);
              EtwpUpdateEnableMask(v37, 0, 1, v43, 0);
              KeReleaseMutant(&EtwpNotificationMutex, 1);
              v13 = EtwpWriteUserEvent(v37);
            }
            EtwpUnreferenceGuidEntry(v37);
            return v13;
          }
          EtwpUnreferenceGuidEntry(v36);
        }
        return -1073741054;
      }
      return -1073741811;
    }
    if ( v7 != 1536 )
    {
      if ( v7 == 256 )
        return EtwTraceEvent(
                 a1,
                 a1 >> 31,
                 a4,
                 48,
                 -1073086464,
                 *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A));
      if ( v7 != 1024 )
      {
        if ( v7 == 1280 )
        {
          v8 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x36C);
          v9 = PsGetMonitorContextServerSilo(EtwSiloMonitor, -1, &v50);
          v10 = v50;
          if ( *v50 != v8 )
          {
            PspDereferenceMonitorContextServerSilo(v50 - 12);
            return -1073741790;
          }
          if ( (a4 & 7) != 0 )
            ExRaiseDatatypeMisalignment(v9);
          if ( a4 + 120 > MmUserProbeAddress || a4 + 120 < a4 )
            *(_BYTE *)MmUserProbeAddress = 0;
          v71 = *(_DWORD *)(a4 + 88);
          v70 = *(_DWORD *)(a4 + 84);
          v72 = *(_DWORD *)(a4 + 112);
          v12 = *(_DWORD *)(a4 + 52);
          v63 = *(_DWORD *)(a4 + 48);
          v64 = v12;
          v13 = EtwpWriteUserEvent(v10 + 2);
          PspDereferenceMonitorContextServerSilo(v10 - 12);
          return v13;
        }
        return -1073741811;
      }
      v61 = a1;
      v14 = (unsigned __int16)a1;
      LODWORD(v51) = (unsigned __int16)a1;
      if ( (unsigned __int16)a1 == 0xFFFF )
      {
        v14 = 0;
        LODWORD(v51) = 0;
      }
      else if ( (unsigned __int16)a1 >= 0x40u )
      {
        return -1073741811;
      }
      if ( a3 > 0xFFDF )
        return -1073741675;
      ExAcquireRundownProtectionCacheAwareEx(EtwpLoggerRundown[v14], 1);
      v15 = WmipLoggerContext[v14];
      if ( (v15 & 1) == 0 && PsEqualCurrentServerSilo(*(_DWORD *)(v15 + 652)) )
      {
        v16 = ExReleaseRundownProtectionCacheAwareEx(EtwpLoggerRundown[v14], 1);
        if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) == 1 )
        {
          if ( a3 != -32 )
          {
            if ( (a4 & 7) != 0 )
              ExRaiseDatatypeMisalignment(v16);
            v17 = a4 + a3 + 32;
            if ( v17 > MmUserProbeAddress || v17 < a4 )
              *(_BYTE *)MmUserProbeAddress = 0;
          }
          v73 = a4 + 32;
          v18 = *(unsigned __int16 *)(a4 + 6);
          v77[0] = a4 + 32;
          v77[1] = 0;
          v77[2] = a3;
          v77[3] = 0;
          EtwpLogSystemEventUnsafe(v77, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, v14, 1, v18, a2 & 0xF00FF | 0x3100);
          return 0;
        }
        return -1073741637;
      }
      ExReleaseRundownProtectionCacheAwareEx(EtwpLoggerRundown[v14], 1);
      return -1073741811;
    }
    v19 = (unsigned __int16)a1;
    if ( (unsigned __int16)a1 == 0xFFFF || !(_WORD)a1 )
      v19 = (unsigned __int16)EtwpSystemLogger;
    if ( v19 >= 0x40 )
      return -1073741816;
    v20 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v21 = 0;
    if ( v20 == 1 || (unsigned int)KeGetCurrentIrql() < 2 )
    {
      v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v22 + 308);
      v23 = ExAcquireRundownProtectionCacheAwareEx(EtwpLoggerRundown[v19], 1);
      if ( !v23 )
        goto LABEL_47;
      v21 = 1;
    }
    v24 = WmipLoggerContext[v19];
    if ( (v24 & 1) == 0 )
    {
      if ( v24 )
      {
        if ( (*(_DWORD *)(v24 + 12) & 0x2000000) != 0 )
        {
          v27 = *(unsigned __int8 *)(v24 + 610);
          v28 = &EtwpGroupMasks[8 * v27] && (EtwpGroupMasks[8 * v27 + 1] & 0x28) != 0;
          v13 = EtwpSetMark(v19, a4, a3, v28, v20);
        }
        else
        {
          v13 = -1073741811;
        }
        if ( v21 )
        {
          v29 = ExReleaseRundownProtectionCacheAwareEx(EtwpLoggerRundown[v19], 1);
          v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v31 = (__int16)(*(_WORD *)(v30 + 0x134) + 1);
          *(_WORD *)(v30 + 308) = v31;
          if ( !v31 && *(_DWORD *)(v30 + 100) != v30 + 100 && !*(_WORD *)(v30 + 310) )
            KiCheckForKernelApcDelivery(v29);
        }
        return v13;
      }
      return -1073741816;
    }
    if ( !v21 )
      return -1073741816;
    v23 = ExReleaseRundownProtectionCacheAwareEx(EtwpLoggerRundown[v19], 1);
LABEL_47:
    v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v26 = (__int16)(*(_WORD *)(v25 + 0x134) + 1);
    *(_WORD *)(v25 + 308) = v26;
    if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
      KiCheckForKernelApcDelivery(v23);
    return -1073741816;
  }
  v51 = a1;
  v48 = 0;
  if ( a3 != 40 )
    return -1073741811;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) != 1 )
    return -1073741637;
  __dmb(0xBu);
  __dmb(0xBu);
  if ( (a4 & 7) != 0 )
    ((void (*)(void))ExRaiseDatatypeMisalignment)();
  __dmb(0xBu);
  v38 = (_BYTE *)MmUserProbeAddress;
  if ( a4 + 40 > MmUserProbeAddress )
    goto LABEL_94;
  __dmb(0xBu);
  __dmb(0xBu);
  if ( a4 + 40 < a4 )
  {
    v38 = (_BYTE *)MmUserProbeAddress;
LABEL_94:
    *v38 = 0;
  }
  __dmb(0xBu);
  v49 = *(_DWORD *)(a4 + 24);
  __dmb(0xBu);
  v48 = *(unsigned int **)(a4 + 32);
  __dmb(0xBu);
  v39 = *(_DWORD *)(a4 + 28);
  if ( v39 > 0x10000 )
  {
    v13 = -1073741811;
    v54 = -1073741811;
    return v13;
  }
  if ( v39 && ((unsigned int)v48 + v39 > MmUserProbeAddress || (unsigned int *)((char *)v48 + v39) < v48) )
    *(_BYTE *)MmUserProbeAddress = 0;
  v49 |= 0x40u;
  HIDWORD(v51) = v39;
  __dmb(0xBu);
  __dmb(0xBu);
  return EtwpTraceMessageVa(v51, SHIDWORD(v51), v49, (_DWORD *)(a4 + 8), *(_WORD *)(a4 + 4), v48, 1);
}
