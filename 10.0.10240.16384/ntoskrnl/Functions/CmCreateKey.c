// CmCreateKey 
 
int __fastcall CmCreateKey(_DWORD *a1, unsigned int a2, int a3, int a4, unsigned int *a5, int a6, _DWORD *a7, int a8)
{
  int v9; // r5
  unsigned int v10; // r4
  __int64 v11; // r0
  int v12; // r3
  unsigned int v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  int v16; // r6
  void **v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  int v20; // r3
  unsigned int *v21; // r2
  unsigned int v22; // r1
  unsigned int v23; // r8
  int v24; // r0
  _DWORD *v25; // r2
  _DWORD *v26; // r2
  unsigned int *v27; // r2
  unsigned int v28; // r2
  unsigned int v29; // r3
  int v30; // lr
  unsigned int v31; // r3
  int v32; // r3
  unsigned int v33; // r4
  unsigned int v34; // r1
  unsigned int v35; // r1
  __int16 v36; // r3
  int *v38; // [sp+8h] [bp-F0h]
  int v39; // [sp+14h] [bp-E4h]
  int v41; // [sp+1Ch] [bp-DCh] BYREF
  int v42; // [sp+20h] [bp-D8h]
  int v43; // [sp+24h] [bp-D4h]
  unsigned __int64 v44; // [sp+28h] [bp-D0h] BYREF
  unsigned __int64 v45; // [sp+30h] [bp-C8h]
  int v46; // [sp+38h] [bp-C0h]
  int v47; // [sp+3Ch] [bp-BCh] BYREF
  int v48; // [sp+40h] [bp-B8h]
  _DWORD *v49; // [sp+44h] [bp-B4h]
  unsigned int v50; // [sp+48h] [bp-B0h]
  unsigned int v51; // [sp+4Ch] [bp-ACh]
  int v52; // [sp+50h] [bp-A8h]
  int v53; // [sp+54h] [bp-A4h]
  _DWORD *v54; // [sp+58h] [bp-A0h]
  _DWORD *v55; // [sp+5Ch] [bp-9Ch]
  int v56; // [sp+60h] [bp-98h]
  unsigned int v57; // [sp+68h] [bp-90h]
  unsigned int v58; // [sp+6Ch] [bp-8Ch]
  unsigned int v59; // [sp+70h] [bp-88h]
  unsigned int v60; // [sp+74h] [bp-84h]
  int v61; // [sp+78h] [bp-80h]
  _DWORD v62[19]; // [sp+7Ch] [bp-7Ch] BYREF
  _DWORD _C8[15]; // [sp+C8h] [bp-30h] BYREF
  unsigned int varg_r1; // [sp+104h] [bp+Ch]
  int varg_r2; // [sp+108h] [bp+10h]
  int varg_r3; // [sp+10Ch] [bp+14h]

  _C8[14] = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v49 = a1;
  v54 = a1;
  v56 = a3;
  v55 = a7;
  v52 = a8;
  v47 = a8;
  v9 = 0;
  v43 = 0;
  v61 = 0;
  memset(v62, 0, sizeof(v62));
  v41 = 0;
  v44 = 0i64;
  v45 = 0i64;
  v10 = 0;
  v42 = 0;
  _C8[0] = 0;
  _C8[1] = 0;
  _C8[2] = 0;
  _C8[3] = 0;
  v46 = 0;
  v48 = 0;
  if ( CmpTraceRoutine )
  {
    LODWORD(v11) = _C8;
    HIDWORD(v11) = 0x20000;
    EtwGetKernelTraceTimestamp(v11);
  }
  v62[5] = a2 & 0x300;
  v51 = a2 & 0xFFFFFCFF;
  varg_r1 = a2 & 0xFFFFFCFF;
  v12 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v12 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v13 = CmpShutdownRundown & 0xFFFFFFFE;
  v14 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v15 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v15 == v13 && __strex(v14, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v15 == v13 )
  {
    v16 = 1;
  }
  else
  {
    v17 = (void **)ExfAcquireRundownProtection(&CmpShutdownRundown);
    v16 = (int)v17;
    if ( !v17 )
    {
      v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v19 = *(_WORD *)(v18 + 0x134) + 1;
      *(_WORD *)(v18 + 308) = v19;
      if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
        v17 = (void **)KiCheckForKernelApcDelivery(0);
      v20 = (unsigned __int8)HvShutdownComplete;
      __dmb(0xBu);
      if ( v20 && (PopShutdownCleanly & 8) != 0 )
        KeBugCheckEx(81, 14, 1, a3, 0);
      v9 = -1073741431;
      v10 = v42;
      goto LABEL_68;
    }
  }
  v53 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v53 == 1 )
  {
    v21 = a5;
    v17 = &CmKeyObjectType;
    if ( a5 )
    {
      if ( (unsigned int)a5 >= MmUserProbeAddress )
        v21 = (unsigned int *)MmUserProbeAddress;
      v50 = *v21;
      v57 = v50;
      v22 = v21[1];
      v39 = v22;
      v58 = v22;
      v45 = __PAIR64__(v22, v50);
      v23 = (unsigned __int16)v50;
      if ( (_WORD)v50 )
      {
        if ( (v22 & 1) != 0 )
          ExRaiseDatatypeMisalignment(&CmKeyObjectType);
        if ( (unsigned __int16)v50 + v22 > MmUserProbeAddress || (unsigned __int16)v50 + v22 < v22 )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
      if ( (v23 & 1) != 0 )
      {
        v9 = -1073741811;
        v43 = -1073741811;
        goto LABEL_68;
      }
      if ( v23 )
      {
        v24 = ExAllocatePoolWithQuotaTag(0x208u, v23, 2019773763);
        v10 = v24;
        v42 = v24;
        if ( !v24 )
        {
          v9 = -1073741670;
          v43 = -1073741670;
          v17 = &CmKeyObjectType;
          goto LABEL_68;
        }
        memmove(v24, v39, v23);
        v39 = v10;
        HIDWORD(v45) = v10;
        v17 = &CmKeyObjectType;
      }
    }
    else
    {
      v39 = HIDWORD(v45);
    }
    v25 = v49;
    if ( (unsigned int)v49 >= MmUserProbeAddress )
      v25 = (_DWORD *)MmUserProbeAddress;
    *v25 = 0;
    if ( a7 )
    {
      v26 = a7;
      if ( (unsigned int)a7 >= MmUserProbeAddress )
        v26 = (_DWORD *)MmUserProbeAddress;
      *v26 = *v26;
    }
    if ( (a3 & 3) != 0 )
      ExRaiseDatatypeMisalignment(&CmKeyObjectType);
    v27 = *(unsigned int **)(a3 + 8);
    if ( (unsigned int)v27 >= MmUserProbeAddress )
      v27 = (unsigned int *)MmUserProbeAddress;
    v50 = *v27;
    v59 = v50;
    v28 = v27[1];
    v60 = v28;
    v44 = __PAIR64__(v28, v50);
    if ( (_WORD)v50 )
    {
      if ( (v28 & 1) != 0 )
        ExRaiseDatatypeMisalignment(&CmKeyObjectType);
      v29 = (unsigned __int16)v50 + v28;
      if ( v29 > MmUserProbeAddress || v29 < v28 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
    if ( (v44 & 1) != 0 )
    {
      v9 = -1073741811;
      v43 = -1073741811;
      goto LABEL_68;
    }
    v30 = *(_DWORD *)(a3 + 4);
    v41 = v30;
  }
  else
  {
    if ( a5 )
    {
      v31 = *a5;
      v39 = a5[1];
      __dmb(0xBu);
      LODWORD(v45) = v31;
      v9 = v43;
      v10 = v42;
    }
    else
    {
      v39 = HIDWORD(v45);
    }
    v44 = *(_QWORD *)*(_DWORD *)(a3 + 8);
    v30 = *(_DWORD *)(a3 + 4);
    v41 = v30;
    v17 = &CmKeyObjectType;
  }
  if ( v9 >= 0 )
  {
    if ( CmpTraceRoutine && v30 )
    {
      v32 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
      if ( ObReferenceObjectByHandle(v30, 0, CmKeyObjectType, v32, &v47) >= 0 )
      {
        v46 = *(_DWORD *)(v47 + 4);
        v48 = v46;
        ObfDereferenceObject(v47);
      }
      v17 = &CmKeyObjectType;
    }
    if ( (a6 & 0x100000F) == a6 )
    {
      v62[4] = a6;
      v61 = 1;
      v62[1] = v39;
      v62[0] = (unsigned __int16)v45;
      v62[12] = v52;
      v38 = &v41;
      v17 = (void **)ObOpenObjectByName(a3, CmKeyObjectType, v53);
      v9 = (int)v17;
      if ( (int)v17 >= 0 )
      {
        *v49 = v41;
        if ( a7 )
          *a7 = v62[6];
      }
    }
    else
    {
      v9 = -1073741811;
    }
  }
LABEL_68:
  if ( CmpTraceRoutine )
    v17 = (void **)((int (__fastcall *)(int, _DWORD *, int, _DWORD, int, unsigned __int64 *, int *))CmpTraceRoutine)(
                     10,
                     _C8,
                     v9,
                     0,
                     v46,
                     &v44,
                     v38);
  if ( v10 )
    v17 = (void **)ExFreePoolWithTag(v10);
  if ( v16 )
  {
    __pld(&CmpShutdownRundown);
    v33 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v34 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v34 == v33 && __strex(v33 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v34 != v33 )
      v17 = (void **)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v36 = *(_WORD *)(v35 + 0x134) + 1;
    *(_WORD *)(v35 + 308) = v36;
    if ( !v36 && *(_DWORD *)(v35 + 100) != v35 + 100 && !*(_WORD *)(v35 + 310) )
      KiCheckForKernelApcDelivery((int)v17);
  }
  return v9;
}
