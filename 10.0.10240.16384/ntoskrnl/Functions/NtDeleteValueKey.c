// NtDeleteValueKey 
 
int __fastcall NtDeleteValueKey(int a1, unsigned int *a2)
{
  int v3; // r4
  __int64 v4; // r0
  int v5; // r10
  int v6; // r3
  unsigned int v7; // r0
  unsigned int v8; // r2
  unsigned int v9; // r1
  unsigned int v10; // r1
  __int16 v11; // r3
  int v12; // r5
  int v13; // r0
  int v14; // r4
  unsigned int v15; // r3
  unsigned int v16; // r1
  int v17; // r0
  unsigned int v18; // r10
  unsigned int v19; // r2
  unsigned int v20; // r3
  int v21; // r0
  unsigned __int16 *v22; // r2
  int v24; // r2
  int v25; // r0
  unsigned int v26; // r1
  unsigned int v27; // r1
  __int16 v28; // r3
  unsigned int v29; // r1
  __int16 v30; // r3
  unsigned int v31; // r4
  unsigned int v32; // r1
  unsigned int v33; // r1
  __int16 v34; // r3
  char *v36; // [sp+4h] [bp-9Ch]
  unsigned __int64 v37; // [sp+8h] [bp-98h] BYREF
  int v38; // [sp+10h] [bp-90h] BYREF
  char v39; // [sp+14h] [bp-8Ch]
  char v40; // [sp+15h] [bp-8Bh]
  unsigned int v41; // [sp+18h] [bp-88h] BYREF
  int v42; // [sp+1Ch] [bp-84h]
  int v43; // [sp+20h] [bp-80h]
  int v44; // [sp+24h] [bp-7Ch]
  int v45; // [sp+28h] [bp-78h]
  int v46; // [sp+2Ch] [bp-74h]
  int v47; // [sp+30h] [bp-70h]
  _DWORD v48[3]; // [sp+38h] [bp-68h] BYREF
  int v49; // [sp+44h] [bp-5Ch]
  int v50; // [sp+48h] [bp-58h] BYREF
  unsigned __int64 *v51; // [sp+4Ch] [bp-54h]
  int v52; // [sp+50h] [bp-50h]
  int v53; // [sp+54h] [bp-4Ch]
  int v54; // [sp+58h] [bp-48h]
  char v55[8]; // [sp+60h] [bp-40h] BYREF
  unsigned int v56; // [sp+68h] [bp-38h]
  unsigned int v57; // [sp+6Ch] [bp-34h]
  _DWORD v58[12]; // [sp+70h] [bp-30h] BYREF

  v3 = a1;
  v45 = a1;
  v48[2] = a1;
  v50 = 0;
  v51 = 0;
  v52 = 0;
  v53 = 0;
  v54 = 0;
  v37 = 0i64;
  v47 = 0;
  v44 = 0;
  v39 = 0;
  v41 = 0;
  v58[0] = 0;
  v58[1] = 0;
  v58[2] = 0;
  v58[3] = 0;
  v43 = 0;
  v49 = 0;
  if ( CmpTraceRoutine )
  {
    LODWORD(v4) = v58;
    HIDWORD(v4) = 0x20000;
    EtwGetKernelTraceTimestamp(v4);
  }
  v5 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v6 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v6 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v7 = CmpShutdownRundown & 0xFFFFFFFE;
  v8 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v9 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v9 == v7 && __strex(v8, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v9 != v7 )
  {
    if ( !ExfAcquireRundownProtection(&CmpShutdownRundown) )
    {
      v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v11 = *(_WORD *)(v10 + 0x134) + 1;
      *(_WORD *)(v10 + 308) = v11;
      if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
        KiCheckForKernelApcDelivery(0);
      v12 = -1073741431;
      if ( CmpTraceRoutine )
        ((void (__fastcall *)(int, _DWORD *, int))CmpTraceRoutine)(15, v58, -1073741431);
      return v12;
    }
    v3 = v45;
  }
  v46 = 1;
  v40 = 1;
  v36 = v55;
  v13 = CmObReferenceObjectByHandle(v3, 2);
  v12 = v13;
  v42 = v13;
  if ( v13 == -1073741790 && CmpVEEnabled && (v13 = CmpIsSystemEntity(&v41)) == 0 )
  {
    v36 = v55;
    v13 = CmObReferenceObjectByHandle(v3, 131097);
    v12 = v13;
    v42 = v13;
    v14 = v38;
    if ( v13 >= 0 )
    {
      v13 = CmKeyBodyNeedsVirtualImage(v38);
      if ( !v13 )
      {
        v13 = ObfDereferenceObject(v38);
        v12 = -1073741790;
        v42 = -1073741790;
      }
    }
    v44 = 1;
    v39 = 1;
  }
  else
  {
    v14 = v38;
  }
  if ( v12 < 0 )
  {
    v18 = 0;
    goto LABEL_81;
  }
  if ( CmpTraceRoutine && v14 )
  {
    v43 = *(_DWORD *)(v14 + 4);
    v49 = v43;
  }
  if ( v5 != 1 )
  {
    v20 = *a2;
    v19 = a2[1];
    __dmb(0xBu);
    v37 = __PAIR64__(v19, v20);
    v18 = v47;
    v12 = v42;
    v14 = v38;
    goto LABEL_42;
  }
  if ( (unsigned int)a2 >= MmUserProbeAddress )
    a2 = (unsigned int *)MmUserProbeAddress;
  v41 = *a2;
  v56 = v41;
  v57 = a2[1];
  v37 = __PAIR64__(v57, v41);
  if ( (_WORD)v41 )
  {
    if ( (v57 & 1) != 0 )
      ExRaiseDatatypeMisalignment(v13);
    v15 = (unsigned __int16)v41 + v57;
    if ( v15 > MmUserProbeAddress || v15 < v57 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  v16 = (unsigned __int16)v37;
  if ( !(_WORD)v37 )
  {
    v19 = 0;
    HIDWORD(v37) = 0;
    v18 = 0;
    goto LABEL_43;
  }
  v17 = ExAllocatePoolWithQuotaTag(0x208u, (unsigned __int16)v37, 1651920195);
  v41 = v17;
  v47 = v17;
  if ( v17 )
  {
    memmove(v17, SHIDWORD(v37), (unsigned __int16)v37);
    v19 = v41;
    HIDWORD(v37) = v41;
    v18 = v41;
LABEL_42:
    v16 = (unsigned __int16)v37;
LABEL_43:
    v21 = 1;
    if ( v12 >= 0 )
    {
      if ( (v16 & 1) != 0 )
      {
        LOWORD(v37) = 0;
        v12 = -1073741811;
      }
      else if ( (*(_DWORD *)(*(_DWORD *)(v14 + 4) + 4) & 0x80) != 0 )
      {
        v12 = -1073741790;
      }
      else
      {
        v22 = (unsigned __int16 *)(v19 + 2 * (v16 >> 1) - 2);
        while ( v16 )
        {
          if ( *v22-- )
            break;
          v16 = (unsigned __int16)(v16 - 2);
          LOWORD(v37) = v16;
        }
        v48[1] = v48;
        v48[0] = v48;
        v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v24 + 308);
        if ( CmpCallBackCount )
        {
          v21 = ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, v16, v24, CmpCallBackCount);
          if ( !v21 )
          {
            v50 = v14;
            v51 = &v37;
            v21 = CmpCallCallBacks(2, &v50, 1, 17, v14, v48);
            v12 = v21;
          }
        }
        if ( v12 < 0 )
        {
          if ( v12 == -1073740541 )
            v12 = 0;
        }
        else
        {
          if ( v44 )
          {
            v12 = CmKeyBodyRemapToVirtual(&v38);
            v14 = v38;
            if ( v12 >= 0 && (!CmpVEEnabled || (*(_WORD *)(*(_DWORD *)(v38 + 4) + 106) & 0x100) == 0) )
              v12 = -1073741790;
          }
          if ( v12 >= 0 )
          {
            __pld(&CmpShutdownRundown);
            v25 = CmpShutdownRundown & 0xFFFFFFFE;
            __dmb(0xBu);
            do
              v26 = __ldrex((unsigned int *)&CmpShutdownRundown);
            while ( v26 == v25 && __strex(v25 - 2, (unsigned int *)&CmpShutdownRundown) );
            if ( v26 != v25 )
              v25 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
            v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v28 = *(_WORD *)(v27 + 0x134) + 1;
            *(_WORD *)(v27 + 308) = v28;
            if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
              KiCheckForKernelApcDelivery(v25);
            v46 = 0;
            v12 = CmDeleteValueKey(v14, v37, HIDWORD(v37), v45, (v55[0] & 4) != 0, v36);
          }
          v21 = CmPostCallbackNotification(17, v14, v12, &v50, v48);
          v12 = v21;
        }
        v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v30 = *(_WORD *)(v29 + 0x134) + 1;
        *(_WORD *)(v29 + 308) = v30;
        if ( !v30 && *(_DWORD *)(v29 + 100) != v29 + 100 && !*(_WORD *)(v29 + 310) )
          KiCheckForKernelApcDelivery(v21);
      }
    }
    goto LABEL_79;
  }
  v12 = -1073741670;
  v42 = -1073741670;
  v18 = 0;
LABEL_79:
  v13 = ObfDereferenceObject(v14);
LABEL_81:
  if ( CmpTraceRoutine )
    v13 = CmpTraceRoutine(15, v58, v12, 0, v43, &v37);
  if ( v18 )
    v13 = ExFreePoolWithTag(v18);
  if ( v46 )
  {
    __pld(&CmpShutdownRundown);
    v31 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v32 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v32 == v31 && __strex(v31 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v32 != v31 )
      v13 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v34 = *(_WORD *)(v33 + 0x134) + 1;
    *(_WORD *)(v33 + 308) = v34;
    if ( !v34 && *(_DWORD *)(v33 + 100) != v33 + 100 && !*(_WORD *)(v33 + 310) )
      KiCheckForKernelApcDelivery(v13);
  }
  return v12;
}
