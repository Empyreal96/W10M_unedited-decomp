// NtQueryValueKey 
 
int __fastcall NtQueryValueKey(int a1, _DWORD *a2, int a3, int a4, int a5, unsigned int a6)
{
  int v8; // lr
  __int64 v9; // r0
  int v10; // r3
  unsigned int v11; // r3
  unsigned int v12; // r1
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3
  int v16; // r5
  int (__fastcall *v17)(int, _DWORD *, int, int, int, _DWORD); // r4
  int v18; // r3
  unsigned int v19; // r4
  unsigned int v20; // r1
  unsigned int v21; // r1
  int v22; // r3
  int v23; // r4
  int v24; // r0
  _DWORD *v25; // lr
  _DWORD *v26; // r2
  int v27; // r1
  unsigned int v28; // r2
  _BYTE *v29; // r3
  int v30; // r0
  _DWORD *v31; // r10
  int v32; // r10
  _DWORD *v33; // r2
  unsigned int v34; // r0
  unsigned int v35; // r3
  unsigned int v36; // r2
  unsigned int v37; // r4
  int v38; // r1
  int v39; // r0
  int v40; // r3
  int v41; // r1
  int v42; // r2
  int v43; // r4
  unsigned int v44; // r1
  __int16 v45; // r3
  unsigned int v46; // r1
  unsigned int v47; // r1
  __int16 v48; // r3
  _DWORD *v50; // [sp+10h] [bp-110h]
  unsigned __int64 v51; // [sp+18h] [bp-108h] BYREF
  _DWORD *v52; // [sp+20h] [bp-100h] BYREF
  unsigned int v53; // [sp+24h] [bp-FCh]
  _DWORD *v54; // [sp+28h] [bp-F8h] BYREF
  _DWORD *v55; // [sp+2Ch] [bp-F4h] BYREF
  _DWORD *v56; // [sp+30h] [bp-F0h] BYREF
  int v57; // [sp+34h] [bp-ECh]
  unsigned int v58; // [sp+38h] [bp-E8h]
  _DWORD *v59; // [sp+3Ch] [bp-E4h]
  int v60; // [sp+40h] [bp-E0h]
  _DWORD v61[3]; // [sp+48h] [bp-D8h] BYREF
  int v62; // [sp+54h] [bp-CCh]
  int v63; // [sp+58h] [bp-C8h]
  _DWORD *v64; // [sp+60h] [bp-C0h] BYREF
  _DWORD v65[8]; // [sp+64h] [bp-BCh] BYREF
  _DWORD *v66; // [sp+88h] [bp-98h] BYREF
  _DWORD v67[8]; // [sp+8Ch] [bp-94h] BYREF
  unsigned int v68; // [sp+ACh] [bp-74h]
  _DWORD v69[4]; // [sp+B0h] [bp-70h] BYREF
  _DWORD _C0[30]; // [sp+C0h] [bp-60h] BYREF

  _C0[26] = a1;
  _C0[27] = a2;
  _C0[29] = a4;
  v53 = a4;
  _C0[28] = a3;
  v52 = a2;
  v63 = a4;
  v58 = a6;
  v61[2] = a6;
  v51 = 0i64;
  v64 = 0;
  memset(v65, 0, sizeof(v65));
  v54 = 0;
  v59 = 0;
  v69[0] = 0;
  v69[1] = 0;
  v69[2] = 0;
  v69[3] = 0;
  v8 = 0;
  v57 = 0;
  v62 = 0;
  if ( CmpTraceRoutine )
  {
    LODWORD(v9) = v69;
    HIDWORD(v9) = 0x20000;
    EtwGetKernelTraceTimestamp(v9);
    v8 = 0;
  }
  v10 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v10 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v11 = CmpShutdownRundown & 0xFFFFFFFE;
  v12 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v13 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v13 == v11 && __strex(v12, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v13 != v11 )
  {
    v13 = ExfAcquireRundownProtection(&CmpShutdownRundown);
    if ( !v13 )
    {
      v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v15 = *(_WORD *)(v14 + 0x134) + 1;
      *(_WORD *)(v14 + 308) = v15;
      if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
        KiCheckForKernelApcDelivery(0);
      v16 = -1073741431;
      if ( CmpTraceRoutine )
        CmpTraceRoutine(16, v69, -1073741431, a3, 0, 0);
      return v16;
    }
    v8 = 0;
  }
  if ( !a3 || a3 == 1 || a3 == 3 || a3 == 4 || a3 == 2 )
  {
    v23 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v24 = ObReferenceObjectByHandle(a1, 1, CmKeyObjectType, v23, &v55);
    v16 = v24;
    v25 = v55;
    v50 = v55;
    v56 = v55;
    if ( v24 >= 0 && *v55 != 1803104306 )
    {
      v16 = -1073741816;
      v24 = ObfDereferenceObject((int)v55);
      v25 = v55;
    }
    v60 = v16;
    if ( v16 >= 0 )
    {
      if ( CmpTraceRoutine && v25 )
      {
        v57 = v25[1];
        v62 = v57;
      }
      v26 = v52;
      if ( v23 == 1 )
      {
        if ( (unsigned int)v52 >= MmUserProbeAddress )
          v26 = (_DWORD *)MmUserProbeAddress;
        v52 = (_DWORD *)*v26;
        v67[7] = v52;
        v68 = v26[1];
        v27 = v68;
        v51 = __PAIR64__(v68, (unsigned int)v52);
        if ( (_WORD)v52 )
        {
          if ( (v68 & 1) != 0 )
            ExRaiseDatatypeMisalignment(v24);
          v28 = (unsigned __int16)v52 + v68;
          v29 = (_BYTE *)MmUserProbeAddress;
          if ( v28 > MmUserProbeAddress || v28 < v68 )
          {
            *(_BYTE *)MmUserProbeAddress = 0;
            v27 = HIDWORD(v51);
            v29 = (_BYTE *)MmUserProbeAddress;
          }
        }
        else
        {
          v29 = (_BYTE *)MmUserProbeAddress;
        }
        v30 = (unsigned __int16)v51;
        if ( (_WORD)v51 )
        {
          if ( (unsigned __int16)v51 > 0x40u )
          {
            v31 = (_DWORD *)ExAllocatePoolWithQuotaTag(0x208u, (unsigned __int16)v51, 1853246787);
            v54 = v31;
            v59 = v31;
            if ( !v31 )
            {
              v16 = -1073741670;
              v60 = -1073741670;
              goto LABEL_100;
            }
            v27 = HIDWORD(v51);
            v30 = (unsigned __int16)v51;
          }
          else
          {
            v31 = _C0;
            v54 = _C0;
            v59 = _C0;
          }
          v30 = memmove((int)v31, v27, v30);
          HIDWORD(v51) = v31;
          v29 = (_BYTE *)MmUserProbeAddress;
          v25 = v55;
        }
        v32 = a5;
        if ( a5 )
        {
          if ( (v53 & 3) != 0 )
            ExRaiseDatatypeMisalignment(v30);
          if ( v53 + a5 > (unsigned int)v29 || v53 + a5 < v53 )
          {
            *v29 = 0;
            v29 = (_BYTE *)MmUserProbeAddress;
          }
        }
        v33 = (_DWORD *)v58;
        if ( v58 >= (unsigned int)v29 )
          v33 = v29;
        *v33 = *v33;
        v34 = HIDWORD(v51);
      }
      else
      {
        v35 = *v52;
        v34 = v52[1];
        __dmb(0xBu);
        v51 = __PAIR64__(v34, v35);
        v32 = a5;
        v54 = v59;
        v16 = v60;
        v25 = v56;
        v50 = v56;
      }
      v36 = (unsigned __int16)v51;
      if ( (v51 & 1) != 0 )
      {
        v16 = -1073741811;
        v60 = -1073741811;
      }
      else
      {
        while ( v36 && !*(_WORD *)(v34 + 2 * (v36 >> 1) - 2) )
        {
          v36 = (unsigned __int16)(v36 - 2);
          LOWORD(v51) = v36;
        }
      }
      v37 = v53;
      if ( v16 >= 0 )
      {
        v61[1] = v61;
        v61[0] = v61;
        v38 = __mrc(15, 0, 13, 0, 3);
        v39 = v38 & 0xFFFFFFC0;
        v40 = *(__int16 *)((v38 & 0xFFFFFFC0) + 0x134);
        *(_WORD *)((v38 & 0xFFFFFFC0) + 0x134) = v40 - 1;
        if ( CmpCallBackCount )
        {
          v39 = ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, v38, v40 - 1, CmpCallBackCount);
          if ( !v39 )
          {
            v64 = v50;
            v65[0] = &v51;
            v65[1] = a3;
            v65[2] = v37;
            v65[3] = v32;
            v65[4] = v58;
            v39 = CmpCallCallBacks(8, &v64, 1, 23, v50, v61);
            v16 = v39;
          }
          v25 = v50;
        }
        if ( v16 < 0 )
        {
          if ( v16 == -1073740541 )
            v16 = 0;
        }
        else
        {
          v52 = 0;
          v39 = CmKeyBodyRemapToVirtualForEnum(&v56, &v52);
          v16 = v39;
          v43 = (int)v52;
          if ( v39 < 0
            || v52 && (v39 = CmQueryValueKey(v52, v51, HIDWORD(v51), a3, v53, v32, v58), v16 = v39, v39 != -1073741772) )
          {
            v25 = v56;
            v50 = v56;
          }
          else
          {
            v50 = v56;
            v39 = CmQueryValueKey(v56, v51, HIDWORD(v51), a3, v53, v32, v58);
            v16 = v39;
            v25 = v50;
          }
          if ( CmpCallBackCount )
          {
            v39 = ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, v41, v42, CmpCallBackCount);
            if ( !v39 && (_DWORD *)v61[0] != v61 )
            {
              memset(v67, 0, 24);
              v66 = v50;
              v67[0] = v16;
              v67[2] = v16;
              v67[1] = &v64;
              v39 = CmpCallCallBacks(23, &v66, 0, 23, v50, v61);
              v16 = v67[2];
            }
            v25 = v50;
          }
          if ( v43 )
          {
            v39 = ObfDereferenceObject(v43);
            v25 = v50;
          }
        }
        v44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v45 = *(_WORD *)(v44 + 0x134) + 1;
        *(_WORD *)(v44 + 308) = v45;
        if ( !v45 && *(_DWORD *)(v44 + 100) != v44 + 100 && !*(_WORD *)(v44 + 310) )
        {
          KiCheckForKernelApcDelivery(v39);
          v25 = v50;
        }
      }
      ObfDereferenceObject((int)v25);
    }
LABEL_100:
    if ( CmpTraceRoutine )
      CmpTraceRoutine(16, v69, v16, a3, v57, &v51);
    if ( v54 && v54 != _C0 )
      ExFreePoolWithTag((unsigned int)v54);
    __pld(&CmpShutdownRundown);
    v13 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v46 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v46 == v13 && __strex(v13 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v46 != v13 )
      v13 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v47 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v48 = *(_WORD *)(v47 + 0x134) + 1;
    *(_WORD *)(v47 + 308) = v48;
    if ( !v48 && *(_DWORD *)(v47 + 100) != v47 + 100 && !*(_WORD *)(v47 + 310) )
      goto LABEL_113;
    return v16;
  }
  v17 = (int (__fastcall *)(int, _DWORD *, int, int, int, _DWORD))CmpTraceRoutine;
  if ( CmpTraceRoutine && a1 )
  {
    v18 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v13 = ObReferenceObjectByHandle(a1, 0, CmKeyObjectType, v18, &v54);
    if ( v13 < 0 )
    {
      v17 = (int (__fastcall *)(int, _DWORD *, int, int, int, _DWORD))CmpTraceRoutine;
      v8 = 0;
    }
    else
    {
      v57 = v54[1];
      v13 = ObfDereferenceObject((int)v54);
      v17 = (int (__fastcall *)(int, _DWORD *, int, int, int, _DWORD))CmpTraceRoutine;
      v8 = v57;
    }
  }
  v16 = -1073741811;
  if ( v17 )
    v13 = v17(16, v69, -1073741811, a3, v8, 0);
  __pld(&CmpShutdownRundown);
  v19 = CmpShutdownRundown & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v20 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v20 == v19 && __strex(v19 - 2, (unsigned int *)&CmpShutdownRundown) );
  if ( v20 != v19 )
    v13 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
  v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v22 = (__int16)(*(_WORD *)(v21 + 0x134) + 1);
  *(_WORD *)(v21 + 308) = v22;
  if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
LABEL_113:
    KiCheckForKernelApcDelivery(v13);
  return v16;
}
