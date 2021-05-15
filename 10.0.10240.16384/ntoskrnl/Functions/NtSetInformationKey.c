// NtSetInformationKey 
 
int __fastcall NtSetInformationKey(int a1, int a2, _DWORD *a3, int a4)
{
  __int64 v7; // r0
  int v8; // r3
  unsigned int v9; // r0
  unsigned int v10; // r2
  unsigned int v11; // r1
  unsigned int v12; // r1
  __int16 v13; // r3
  int v14; // r5
  int v15; // r0
  int v16; // r2
  char v17; // r3
  int v18; // r8
  int *v19; // r3
  int v20; // r3
  char v21; // r3
  char v22; // r3
  int *v23; // r3
  int v24; // r3
  __int64 *v25; // r1
  int v26; // r1
  int v27; // r1
  unsigned int v28; // r3
  int v29; // r6
  int v30; // r2
  unsigned int v31; // r0
  unsigned int v32; // r1
  int v33; // r0
  __int16 v34; // r3
  int v35; // r0
  int v36; // r0
  unsigned int v37; // r1
  unsigned int v38; // r1
  __int16 v39; // r3
  unsigned int v40; // r1
  __int16 v41; // r3
  unsigned int v42; // r4
  unsigned int v43; // r1
  unsigned int v44; // r1
  __int16 v45; // r3
  int v47; // [sp+8h] [bp-A0h]
  int v48; // [sp+Ch] [bp-9Ch]
  int v49; // [sp+10h] [bp-98h] BYREF
  _DWORD *v50; // [sp+14h] [bp-94h] BYREF
  int v51; // [sp+18h] [bp-90h]
  _DWORD *v52; // [sp+1Ch] [bp-8Ch] BYREF
  int v53; // [sp+20h] [bp-88h]
  unsigned int v54; // [sp+24h] [bp-84h]
  int v55; // [sp+28h] [bp-80h]
  int v56; // [sp+2Ch] [bp-7Ch]
  int v57; // [sp+30h] [bp-78h]
  int v58; // [sp+34h] [bp-74h]
  int v59; // [sp+38h] [bp-70h]
  int v60; // [sp+3Ch] [bp-6Ch]
  _DWORD v61[2]; // [sp+40h] [bp-68h] BYREF
  __int64 v62; // [sp+48h] [bp-60h] BYREF
  int v63; // [sp+50h] [bp-58h] BYREF
  _DWORD v64[6]; // [sp+54h] [bp-54h] BYREF
  __int64 v65; // [sp+70h] [bp-38h]
  _DWORD _78[18]; // [sp+78h] [bp-30h] BYREF

  _78[14] = a1;
  _78[16] = a3;
  v55 = a4;
  _78[17] = a4;
  v54 = (unsigned int)a3;
  _78[15] = a2;
  v59 = a1;
  v60 = a1;
  v52 = a3;
  v51 = 0;
  v53 = 0;
  v58 = 0;
  BYTE2(v47) = 0;
  v49 = 0;
  v63 = 0;
  memset(v64, 0, sizeof(v64));
  _78[0] = 0;
  _78[1] = 0;
  _78[2] = 0;
  _78[3] = 0;
  v48 = 0;
  v50 = 0;
  if ( CmpTraceRoutine )
  {
    LODWORD(v7) = _78;
    HIDWORD(v7) = 0x20000;
    EtwGetKernelTraceTimestamp(v7);
  }
  v8 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v8 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v9 = CmpShutdownRundown & 0xFFFFFFFE;
  v10 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v11 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v11 == v9 && __strex(v10, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v11 != v9 && !ExfAcquireRundownProtection(&CmpShutdownRundown) )
  {
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v13 = *(_WORD *)(v12 + 0x134) + 1;
    *(_WORD *)(v12 + 308) = v13;
    if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
      KiCheckForKernelApcDelivery(0);
    v14 = -1073741431;
    if ( CmpTraceRoutine )
      CmpTraceRoutine(20, _78, -1073741431, 0, 0, 0);
    return v14;
  }
  v15 = 1;
  v57 = 1;
  BYTE1(v47) = 1;
  v16 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v56 = v16;
  LOBYTE(v47) = v16;
  if ( a2 )
  {
    if ( a2 != 1 )
    {
      if ( a2 <= 1 )
        goto LABEL_33;
      if ( a2 <= 4 )
      {
        if ( v55 != 4 )
        {
          if ( CmpTraceRoutine
            && a1
            && (v17 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A),
                v15 = ObReferenceObjectByHandle(a1, 0, (int)CmKeyObjectType, v17, (int)&v49, 0),
                v15 >= 0) )
          {
            v18 = *(_DWORD *)(v49 + 4);
            v15 = ObfDereferenceObject(v49);
          }
          else
          {
            v18 = 0;
          }
          v14 = -1073741820;
          goto LABEL_118;
        }
        if ( v16 == 1 )
        {
          v19 = a3;
          if ( v54 >= MmUserProbeAddress )
            v19 = (int *)MmUserProbeAddress;
          v20 = *v19;
          v53 = v20;
          LOBYTE(v16) = v56;
        }
        else
        {
          v20 = *a3;
          v53 = *a3;
        }
        v51 = v20;
        goto LABEL_56;
      }
      if ( a2 != 5 )
      {
LABEL_33:
        if ( CmpTraceRoutine )
        {
          if ( a1 )
          {
            v21 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
            v15 = ObReferenceObjectByHandle(a1, 0, (int)CmKeyObjectType, v21, (int)&v49, 0);
            if ( v15 >= 0 )
            {
              v48 = *(_DWORD *)(v49 + 4);
              v15 = ObfDereferenceObject(v49);
            }
          }
        }
        v14 = -1073741821;
LABEL_117:
        v18 = v48;
        goto LABEL_118;
      }
    }
    if ( v55 != 4 )
      goto LABEL_39;
    if ( v16 == 1 )
    {
      v23 = a3;
      if ( v54 >= MmUserProbeAddress )
        v23 = (int *)MmUserProbeAddress;
      v24 = *v23;
      v53 = v24;
      LOBYTE(v16) = v56;
    }
    else
    {
      v24 = *a3;
      v53 = *a3;
    }
    v51 = v24;
  }
  else
  {
    if ( v55 != 8 )
    {
LABEL_39:
      if ( CmpTraceRoutine )
      {
        if ( a1 )
        {
          v22 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
          v15 = ObReferenceObjectByHandle(a1, 0, (int)CmKeyObjectType, v22, (int)&v49, 0);
          if ( v15 >= 0 )
          {
            v48 = *(_DWORD *)(v49 + 4);
            v15 = ObfDereferenceObject(v49);
          }
        }
      }
      v14 = -1073741820;
      goto LABEL_117;
    }
    if ( v16 == 1 )
    {
      v25 = (__int64 *)a3;
      if ( v54 >= MmUserProbeAddress )
        v25 = (__int64 *)MmUserProbeAddress;
      v65 = *v25;
      v62 = v65;
      LOBYTE(v16) = v56;
    }
    else
    {
      v62 = *(_QWORD *)a3;
    }
  }
LABEL_56:
  if ( a2 == 5 )
    v26 = 0;
  else
    v26 = 2;
  v15 = ObReferenceObjectByHandle(a1, v26, (int)CmKeyObjectType, v16, (int)&v52, 0);
  v29 = (int)v52;
  v50 = v52;
  v14 = v15;
  if ( v15 == -1073741790 )
  {
    if ( CmpVEEnabled )
    {
      v15 = CmpIsSystemEntity(&v49, v27, (unsigned int *)(unsigned __int8)CmpVEEnabled, v28);
      if ( !v15 && a2 != 2 && a2 != 3 )
      {
        v15 = ObReferenceObjectByHandle(v59, 131097, (int)CmKeyObjectType, v56, (int)&v52, 0);
        v14 = v15;
        v29 = (int)v52;
        v50 = v52;
        if ( v15 >= 0 )
        {
          v15 = CmKeyBodyNeedsVirtualImage(v52);
          if ( !v15 )
          {
            v15 = ObfDereferenceObject(v29);
            v14 = -1073741790;
          }
        }
        v58 = 1;
      }
    }
  }
  if ( v14 < 0 )
    goto LABEL_117;
  if ( CmpTraceRoutine && v29 )
    v48 = *(_DWORD *)(v29 + 4);
  if ( (*(_DWORD *)(*(_DWORD *)(v29 + 4) + 4) & 0x80) == 0 || a2 == 5 )
  {
    v61[1] = v61;
    v61[0] = v61;
    v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v30 + 308);
    if ( CmpCallBackCount )
    {
      v15 = ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, v27, v30, CmpCallBackCount);
      if ( !v15 )
      {
        v63 = v29;
        v64[0] = a2;
        v64[1] = v54;
        v64[2] = v55;
        v15 = CmpCallCallBacks(3, &v63, 1, 18, v29, v61);
        v14 = v15;
      }
    }
    if ( v14 < 0 )
    {
      if ( v14 == -1073740541 )
        v14 = 0;
      goto LABEL_112;
    }
    if ( a2 )
    {
      if ( a2 > 4 )
      {
        *(_WORD *)(v29 + 26) = v51;
LABEL_109:
        v15 = CmPostCallbackNotification(18, v29, v14);
        v14 = v15;
LABEL_112:
        v40 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v41 = *(_WORD *)(v40 + 0x134) + 1;
        *(_WORD *)(v40 + 308) = v41;
        if ( !v41 && *(_DWORD *)(v40 + 100) != v40 + 100 && !*(_WORD *)(v40 + 310) )
          KiCheckForKernelApcDelivery(v15);
        goto LABEL_116;
      }
      if ( v58 )
      {
        v14 = CmKeyBodyReplicateToVirtual(&v50, 2, &v49);
        v29 = (int)v50;
      }
      if ( v14 < 0 )
        goto LABEL_109;
      __pld(&CmpShutdownRundown);
      v31 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v32 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v32 == v31 && __strex(v31 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v32 != v31 )
        ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v34 = *(_WORD *)(v33 + 0x134) + 1;
      *(_WORD *)(v33 + 308) = v34;
      if ( !v34 && *(_DWORD *)(v33 + 100) != v33 + 100 && !*(_WORD *)(v33 + 310) )
        KiCheckForKernelApcDelivery(v33);
      v57 = 0;
      v35 = CmSetKeyFlags(v29, a2, v51);
    }
    else
    {
      if ( v58 )
      {
        v14 = CmKeyBodyReplicateToVirtual(&v50, 2, &v49);
        v29 = (int)v50;
      }
      if ( v14 < 0 )
        goto LABEL_109;
      __pld(&CmpShutdownRundown);
      v36 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v37 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v37 == v36 && __strex(v36 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v37 != v36 )
        v36 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v38 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v39 = *(_WORD *)(v38 + 0x134) + 1;
      *(_WORD *)(v38 + 308) = v39;
      if ( !v39 && *(_DWORD *)(v38 + 100) != v38 + 100 && !*(_WORD *)(v38 + 310) )
        KiCheckForKernelApcDelivery(v36);
      v57 = 0;
      v35 = CmSetLastWriteTimeKey(v29, &v62);
    }
    v14 = v35;
    goto LABEL_109;
  }
  v14 = -1073741790;
LABEL_116:
  v15 = ObfDereferenceObject(v29);
  v18 = v48;
LABEL_118:
  if ( CmpTraceRoutine )
    v15 = ((int (__fastcall *)(int, _DWORD *, int, _DWORD, int, _DWORD, int))CmpTraceRoutine)(
            20,
            _78,
            v14,
            0,
            v18,
            0,
            v47);
  if ( v57 )
  {
    __pld(&CmpShutdownRundown);
    v42 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v43 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v43 == v42 && __strex(v42 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v43 != v42 )
      v15 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v45 = *(_WORD *)(v44 + 0x134) + 1;
    *(_WORD *)(v44 + 308) = v45;
    if ( !v45 && *(_DWORD *)(v44 + 100) != v44 + 100 && !*(_WORD *)(v44 + 310) )
      KiCheckForKernelApcDelivery(v15);
  }
  return v14;
}
