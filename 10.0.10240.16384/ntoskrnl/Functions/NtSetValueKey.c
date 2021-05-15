// NtSetValueKey 
 
int __fastcall NtSetValueKey(int a1, int a2, int a3, int a4, int a5, unsigned int a6)
{
  int *v6; // r8
  __int64 v7; // r0
  int v8; // r3
  unsigned int v9; // r0
  unsigned int v10; // r2
  unsigned int v11; // r1
  unsigned int v12; // r1
  __int16 v13; // r3
  int v14; // r5
  _BYTE *v15; // r10
  int v16; // r0
  int v17; // r1
  unsigned int *v18; // r2
  int v19; // r9
  unsigned int v20; // r1
  unsigned int v21; // r2
  _BYTE *v22; // r3
  unsigned int v23; // r4
  int v24; // r3
  unsigned int v25; // r2
  unsigned int v26; // r8
  unsigned int v27; // lr
  unsigned int v28; // r6
  int v29; // r0
  _BYTE *v30; // r6
  unsigned int v31; // r10
  int v32; // r0
  int v33; // r2
  int v34; // r0
  unsigned int v35; // r1
  unsigned int v36; // r1
  __int16 v37; // r3
  unsigned int v38; // r1
  __int16 v39; // r3
  unsigned int v40; // r4
  unsigned int v41; // r1
  unsigned int v42; // r1
  __int16 v43; // r3
  int v45; // [sp+10h] [bp-110h] BYREF
  _BYTE *v46; // [sp+14h] [bp-10Ch]
  unsigned int v47; // [sp+18h] [bp-108h]
  char v48; // [sp+1Ch] [bp-104h]
  int v49; // [sp+20h] [bp-100h] BYREF
  int v50; // [sp+24h] [bp-FCh]
  int v51; // [sp+28h] [bp-F8h]
  char v52; // [sp+2Ch] [bp-F4h]
  _BYTE *v53; // [sp+30h] [bp-F0h]
  unsigned int v54; // [sp+34h] [bp-ECh]
  _BYTE *v55; // [sp+38h] [bp-E8h]
  int v56; // [sp+3Ch] [bp-E4h]
  int v57; // [sp+40h] [bp-E0h]
  int v58; // [sp+44h] [bp-DCh]
  int v59; // [sp+48h] [bp-D8h]
  int v60; // [sp+4Ch] [bp-D4h]
  int v61; // [sp+50h] [bp-D0h]
  _BYTE *v62; // [sp+54h] [bp-CCh]
  int v63; // [sp+58h] [bp-C8h]
  _DWORD v64[2]; // [sp+60h] [bp-C0h] BYREF
  int v65; // [sp+68h] [bp-B8h]
  int v66; // [sp+6Ch] [bp-B4h]
  int v67; // [sp+70h] [bp-B0h] BYREF
  int v68; // [sp+74h] [bp-ACh]
  char v69; // [sp+78h] [bp-A8h]
  _DWORD v70[12]; // [sp+80h] [bp-A0h] BYREF
  _DWORD v71[4]; // [sp+B0h] [bp-70h] BYREF
  _BYTE _C0[100]; // [sp+C0h] [bp-60h] BYREF
  int varg_r0; // [sp+128h] [bp+8h]
  int varg_r1; // [sp+12Ch] [bp+Ch]
  int varg_r2; // [sp+130h] [bp+10h]
  int varg_r3; // [sp+134h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  v61 = a4;
  varg_r3 = a4;
  v68 = a3;
  varg_r2 = a3;
  v6 = (int *)a2;
  v57 = a1;
  v63 = a1;
  v47 = a5;
  v54 = a5;
  v71[0] = 0;
  v71[1] = 0;
  v71[2] = 0;
  v71[3] = 0;
  v58 = 0;
  v66 = 0;
  if ( CmpTraceRoutine )
  {
    LODWORD(v7) = v71;
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
      CmpTraceRoutine(14, v71, -1073741431, 0, 0, 0);
    return v14;
  }
  memset(v70, 0, 36);
  v45 = 0;
  v46 = 0;
  v15 = 0;
  v62 = 0;
  v53 = 0;
  v67 = 0;
  v60 = 0;
  v48 = 0;
  v51 = 0;
  v56 = 0;
  v59 = 1;
  v52 = 1;
  v65 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v16 = CmObReferenceObjectByHandle(v57, 2);
  v14 = v16;
  v50 = v16;
  if ( v16 == -1073741790
    && CmpVEEnabled
    && (v16 = CmpIsSystemEntity(&v67, v17, v18, (unsigned __int8)CmpVEEnabled)) == 0 )
  {
    v16 = CmObReferenceObjectByHandle(v57, 131097);
    v14 = v16;
    v50 = v16;
    v19 = v49;
    if ( v16 >= 0 )
    {
      v16 = CmKeyBodyNeedsVirtualImage(v49);
      if ( !v16 )
      {
        v16 = ObfDereferenceObject(v49);
        v14 = -1073741790;
        v50 = -1073741790;
      }
    }
    v60 = 1;
    v48 = 1;
  }
  else
  {
    v19 = v49;
  }
  if ( v14 < 0 )
  {
    v26 = 0;
    goto LABEL_107;
  }
  if ( CmpTraceRoutine && v19 )
  {
    v58 = *(_DWORD *)(v19 + 4);
    v66 = v58;
  }
  if ( v65 == 1 )
  {
    if ( (unsigned int)v6 >= MmUserProbeAddress )
      v6 = (int *)MmUserProbeAddress;
    v53 = (_BYTE *)*v6;
    v70[10] = v53;
    v20 = v6[1];
    v70[11] = v20;
    v45 = (int)v53;
    v46 = (_BYTE *)v20;
    if ( (_WORD)v53 )
    {
      if ( (v20 & 1) != 0 )
        ExRaiseDatatypeMisalignment(v16);
      v21 = (unsigned __int16)v53 + v20;
      v22 = (_BYTE *)MmUserProbeAddress;
      if ( v21 > MmUserProbeAddress || v21 < v20 )
      {
        *(_BYTE *)MmUserProbeAddress = 0;
        v20 = (unsigned int)v46;
        v22 = (_BYTE *)MmUserProbeAddress;
      }
    }
    else
    {
      v22 = (_BYTE *)MmUserProbeAddress;
    }
    v23 = a6;
    if ( a6 && (v47 + a6 > (unsigned int)v22 || v47 + a6 < v47) )
    {
      *v22 = 0;
      v20 = (unsigned int)v46;
    }
  }
  else
  {
    v24 = *v6;
    v20 = v6[1];
    __dmb(0xBu);
    v45 = v24;
    v46 = (_BYTE *)v20;
    v15 = 0;
    v55 = 0;
    v23 = a6;
    if ( a6 )
    {
      __dmb(0xBu);
      v20 = (unsigned int)v46;
      v15 = v55;
    }
    v62 = v53;
    v51 = v56;
    v14 = v50;
    v19 = v49;
    v47 = v54;
  }
  v25 = (unsigned __int16)v45;
  if ( (unsigned __int16)v45 <= 0x7FFFu && (v45 & 1) == 0 && v23 <= 0x7FFFF000 )
  {
    v27 = ((unsigned __int16)v45 + 7) & 0xFFFFFFF8;
    v53 = (_BYTE *)v27;
    v28 = v27 + v23;
    if ( v27 + v23 < v23 )
    {
      v14 = -1073741811;
      v50 = -1073741811;
      v26 = v51;
      goto LABEL_105;
    }
    if ( v65 != 1 )
    {
LABEL_75:
      v26 = v51;
      v31 = v47;
      v32 = -1073741790;
      while ( v25 && !*(_WORD *)(v20 + 2 * (v25 >> 1) - 2) )
      {
        v25 = (unsigned __int16)(v25 - 2);
        LOWORD(v45) = v25;
      }
      if ( (*(_DWORD *)(*(_DWORD *)(v19 + 4) + 4) & 0x80) != 0 )
      {
        v14 = -1073741790;
      }
      else
      {
        v64[1] = v64;
        v64[0] = v64;
        v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v33 + 308);
        if ( CmpCallBackCount )
        {
          v32 = ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, v20, v33, CmpCallBackCount);
          if ( !v32 )
          {
            v70[0] = v19;
            v70[1] = &v45;
            v70[2] = v68;
            v70[3] = v61;
            v70[4] = v31;
            v70[5] = v23;
            v32 = CmpCallCallBacks(1, v70, 1, 16, v19, v64);
            v14 = v32;
          }
        }
        if ( v14 < 0 )
        {
          if ( v14 == -1073740541 )
            v14 = 0;
        }
        else
        {
          if ( v60 )
          {
            v14 = CmKeyBodyReplicateToVirtual(&v49, 2, &v67);
            v19 = v49;
          }
          if ( v14 >= 0 )
          {
            __pld(&CmpShutdownRundown);
            v34 = CmpShutdownRundown & 0xFFFFFFFE;
            __dmb(0xBu);
            do
              v35 = __ldrex((unsigned int *)&CmpShutdownRundown);
            while ( v35 == v34 && __strex(v34 - 2, (unsigned int *)&CmpShutdownRundown) );
            if ( v35 != v34 )
              v34 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
            v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v37 = *(_WORD *)(v36 + 0x134) + 1;
            *(_WORD *)(v36 + 308) = v37;
            if ( !v37 && *(_DWORD *)(v36 + 100) != v36 + 100 && !*(_WORD *)(v36 + 310) )
              KiCheckForKernelApcDelivery(v34);
            v59 = 0;
            v14 = CmSetValueKey(v19, &v45, v61, v31, v23, v57, (v69 & 4) != 0);
          }
          v32 = CmPostCallbackNotification(16, v19, v14, v70, v64);
          v14 = v32;
        }
        v38 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v39 = *(_WORD *)(v38 + 0x134) + 1;
        *(_WORD *)(v38 + 308) = v39;
        if ( !v39 && *(_DWORD *)(v38 + 100) != v38 + 100 && !*(_WORD *)(v38 + 310) )
          KiCheckForKernelApcDelivery(v32);
      }
      goto LABEL_105;
    }
    if ( !v28 )
    {
      v30 = v62;
      goto LABEL_69;
    }
    if ( v28 <= 0x40 )
    {
LABEL_67:
      v15 = _C0;
      v55 = _C0;
      v30 = &_C0[v27];
LABEL_69:
      if ( v25 )
      {
        memmove((int)v15, v20, v25);
        v20 = (unsigned int)v15;
        v46 = v15;
        v25 = (unsigned __int16)v45;
      }
      else
      {
        v20 = 0;
        v46 = 0;
      }
      if ( v23 )
      {
        memmove((int)v30, v47, v23);
        v47 = (unsigned int)v30;
        v54 = (unsigned int)v30;
        v20 = (unsigned int)v46;
        v25 = (unsigned __int16)v45;
      }
      else
      {
        v47 = 0;
        v54 = 0;
      }
      goto LABEL_75;
    }
    if ( v23 > 0x40 )
    {
      if ( (unsigned __int16)v45 > 0x40u )
        goto LABEL_59;
    }
    else if ( (unsigned __int16)v45 > 0x40u || v23 >= (unsigned __int16)v45 )
    {
      v28 = (unsigned __int16)v45;
      goto LABEL_59;
    }
    v28 = v23;
LABEL_59:
    if ( v28 )
    {
      v29 = ExAllocatePoolWithQuotaTag(0x208u, v28, 1851157827);
      v51 = v29;
      v56 = v29;
      if ( !v29 )
      {
        v14 = -1073741670;
        v50 = -1073741670;
        v26 = 0;
        goto LABEL_105;
      }
      v20 = (unsigned int)v46;
      v25 = (unsigned __int16)v45;
      if ( v28 == v23 )
      {
        v15 = _C0;
        v55 = _C0;
        v30 = (_BYTE *)v29;
      }
      else
      {
        v15 = (_BYTE *)v29;
        v55 = (_BYTE *)v29;
        if ( v28 == (unsigned __int16)v45 )
          v30 = _C0;
        else
          v30 = &v53[v29];
      }
      goto LABEL_69;
    }
    goto LABEL_67;
  }
  v14 = -1073741811;
  v50 = -1073741811;
  v26 = v51;
LABEL_105:
  v16 = ObfDereferenceObject(v19);
LABEL_107:
  if ( CmpTraceRoutine )
    v16 = CmpTraceRoutine(14, v71, v14, 0, v58, &v45);
  if ( v26 )
    v16 = ExFreePoolWithTag(v26);
  if ( v59 )
  {
    __pld(&CmpShutdownRundown);
    v40 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v41 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v41 == v40 && __strex(v40 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v41 != v40 )
      v16 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v42 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v43 = *(_WORD *)(v42 + 0x134) + 1;
    *(_WORD *)(v42 + 308) = v43;
    if ( !v43 && *(_DWORD *)(v42 + 100) != v42 + 100 && !*(_WORD *)(v42 + 310) )
      KiCheckForKernelApcDelivery(v16);
  }
  return v14;
}
