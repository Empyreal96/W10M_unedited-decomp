// NtLoadKeyEx 
 
int __fastcall NtLoadKeyEx(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  int v9; // r3
  int v10; // r0
  unsigned int v11; // r2
  unsigned int v12; // r1
  unsigned int v13; // r1
  __int16 v14; // r3
  int v15; // r4
  unsigned int v16; // r4
  unsigned int v17; // r1
  bool v18; // zf
  unsigned int v19; // r1
  __int16 v20; // r3
  unsigned int v21; // r1
  int v22; // r0
  unsigned int v23; // r1
  unsigned int v24; // r1
  int v25; // r3
  int v26; // r10
  int v27; // r3
  int v28; // r0
  unsigned int v29; // r1
  unsigned int v30; // r1
  __int16 v31; // r3
  unsigned int v32; // r4
  int v33; // r0
  unsigned int v34; // r1
  unsigned int v35; // r1
  __int16 v36; // r3
  int v37; // r0
  unsigned int v38; // r1
  unsigned int v39; // r1
  __int16 v40; // r3
  unsigned __int8 *v41; // r0
  int v42; // r5
  unsigned int v43; // r4
  unsigned int v44; // r1
  bool v45; // zf
  unsigned int v46; // r1
  __int16 v47; // r3
  _DWORD *v48; // r3
  int v49; // r0
  int v50; // r1
  int v51; // r2
  int v52; // r3
  int v53; // r3
  int v54; // r0
  unsigned int v55; // r1
  unsigned int v56; // r1
  __int16 v57; // r3
  unsigned int *v58; // r2
  unsigned int v59; // r2
  unsigned int v60; // r3
  int v61; // r0
  int v62; // r5
  int v63; // r0
  unsigned int v64; // r4
  unsigned int v65; // r1
  unsigned int v66; // r1
  __int16 v67; // r3
  int v68; // lr
  unsigned int v69; // r1
  int v70; // r3
  int v71; // r0
  int v72; // r5
  _BYTE *v73; // r0
  int v74; // r1
  int v75; // r2
  int v76; // r0
  int v77; // r0
  unsigned int v78; // r1
  unsigned int v79; // r1
  __int16 v80; // r3
  unsigned int v81; // r1
  __int16 v82; // r3
  unsigned __int64 *v83; // r0
  unsigned int v84; // r1
  __int16 v85; // r3
  int v86; // r0
  unsigned int v87; // r1
  unsigned int v88; // r1
  __int16 v89; // r3
  unsigned __int8 *v92; // [sp+20h] [bp-130h] BYREF
  unsigned int v93; // [sp+24h] [bp-12Ch] BYREF
  unsigned __int64 v94; // [sp+28h] [bp-128h] BYREF
  int v95; // [sp+30h] [bp-120h]
  char v96; // [sp+34h] [bp-11Ch]
  int v97; // [sp+38h] [bp-118h]
  char v98; // [sp+3Ch] [bp-114h]
  __int64 *v99; // [sp+40h] [bp-110h]
  int v100; // [sp+44h] [bp-10Ch]
  unsigned __int64 *v101; // [sp+48h] [bp-108h] BYREF
  int v102; // [sp+4Ch] [bp-104h]
  int v103; // [sp+50h] [bp-100h] BYREF
  int v104; // [sp+54h] [bp-FCh]
  int v105; // [sp+58h] [bp-F8h]
  int v106; // [sp+5Ch] [bp-F4h]
  int v107; // [sp+60h] [bp-F0h]
  int v108; // [sp+68h] [bp-E8h] BYREF
  unsigned int v109; // [sp+6Ch] [bp-E4h]
  _DWORD v110[2]; // [sp+70h] [bp-E0h] BYREF
  int v111; // [sp+78h] [bp-D8h]
  int v112; // [sp+7Ch] [bp-D4h]
  unsigned int v113; // [sp+80h] [bp-D0h]
  int v114; // [sp+88h] [bp-C8h] BYREF
  _DWORD v115[5]; // [sp+8Ch] [bp-C4h] BYREF
  int v116; // [sp+A0h] [bp-B0h] BYREF
  int v117; // [sp+A8h] [bp-A8h] BYREF
  _DWORD v118[13]; // [sp+ACh] [bp-A4h] BYREF
  int v119; // [sp+E0h] [bp-70h] BYREF
  _BYTE v120[76]; // [sp+E4h] [bp-6Ch] BYREF
  int varg_r0; // [sp+158h] [bp+8h]
  int varg_r1; // [sp+15Ch] [bp+Ch]
  int varg_r2; // [sp+160h] [bp+10h]
  int varg_r3; // [sp+164h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  v105 = a4;
  varg_r3 = a4;
  varg_r2 = a3;
  v114 = 0;
  memset(v115, 0, sizeof(v115));
  v94 = 0i64;
  v97 = 0;
  v110[0] = 0;
  v99 = 0;
  v101 = 0;
  v119 = 0;
  memset(v120, 0, sizeof(v120));
  v95 = 0;
  v113 = 0;
  v112 = 0;
  v96 = 0;
  v100 = 0;
  v103 = 0;
  v104 = 0;
  v9 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v9 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v10 = CmpShutdownRundown & 0xFFFFFFFE;
  v11 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v12 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v12 == v10 && __strex(v11, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v12 != v10 )
  {
    v10 = ExfAcquireRundownProtection(&CmpShutdownRundown);
    if ( !v10 )
    {
      v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v14 = *(_WORD *)(v13 + 0x134) + 1;
      *(_WORD *)(v13 + 308) = v14;
      if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
        KiCheckForKernelApcDelivery(0);
      return -1073741431;
    }
  }
  v106 = 1;
  v107 = 0;
  if ( (a3 & 0xFFFFC00B) != 0 )
  {
    __pld(&CmpShutdownRundown);
    v16 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v17 == v16 && __strex(v16 - 2, (unsigned int *)&CmpShutdownRundown) );
    v18 = v17 == v16;
LABEL_16:
    if ( !v18 )
      v10 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v20 = *(_WORD *)(v19 + 0x134) + 1;
    *(_WORD *)(v19 + 308) = v20;
    if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
      KiCheckForKernelApcDelivery(v10);
    return -1073741583;
  }
  if ( (a3 & 0x2000) != 0 && (a3 & 0x10) == 0 || (a3 & 0x1000) != 0 && (a3 & 0x600) != 1536 )
    goto LABEL_25;
  if ( (a3 & 0x810) != 0 )
    v104 = 1;
  v15 = CmCheckNoTxContext();
  if ( v15 < 0 )
  {
    __pld(&CmpShutdownRundown);
    v22 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v23 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v23 == v22 && __strex(v22 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v23 != v22 )
      v22 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v25 = (__int16)(*(_WORD *)(v24 + 0x134) + 1);
    *(_WORD *)(v24 + 308) = v25;
    if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
      KiCheckForKernelApcDelivery(v22);
    return v15;
  }
  v26 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v98 = v26;
  v27 = a3 & 0x10;
  v93 = v27;
  if ( (a3 & 0x10) == 0 )
  {
    if ( !SeSinglePrivilegeCheck(SeRestorePrivilege, dword_922B9C, v26) )
    {
      __pld(&CmpShutdownRundown);
      v28 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v29 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v29 == v28 && __strex(v28 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v29 != v28 )
        v28 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v31 = *(_WORD *)(v30 + 0x134) + 1;
      *(_WORD *)(v30 + 308) = v31;
      if ( !v31 && *(_DWORD *)(v30 + 100) != v30 + 100 && !*(_WORD *)(v30 + 310) )
        KiCheckForKernelApcDelivery(v28);
      return -1073741727;
    }
    v27 = v93;
  }
  if ( v104 )
  {
    v32 = (unsigned int)a7;
    if ( !a7 )
    {
      __pld(&CmpShutdownRundown);
      v33 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v34 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v34 == v33 && __strex(v33 - 2, (unsigned int *)&CmpShutdownRundown) );
LABEL_61:
      if ( v34 != v33 )
        v33 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v36 = *(_WORD *)(v35 + 0x134) + 1;
      *(_WORD *)(v35 + 308) = v36;
      if ( !v36 && *(_DWORD *)(v35 + 100) != v35 + 100 && !*(_WORD *)(v35 + 310) )
        KiCheckForKernelApcDelivery(v33);
      return -1073741581;
    }
    if ( v27 && (a3 & 0x444) != 0 )
    {
LABEL_25:
      __pld(&CmpShutdownRundown);
      v10 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v21 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v21 == v10 && __strex(v10 - 2, (unsigned int *)&CmpShutdownRundown) );
      v18 = v21 == v10;
      goto LABEL_16;
    }
  }
  else
  {
    if ( a7 )
    {
      __pld(&CmpShutdownRundown);
      v37 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v38 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v38 == v37 && __strex(v37 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v38 != v37 )
        v37 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v40 = *(_WORD *)(v39 + 0x134) + 1;
      *(_WORD *)(v39 + 308) = v40;
      if ( !v40 && *(_DWORD *)(v39 + 100) != v39 + 100 && !*(_WORD *)(v39 + 310) )
        KiCheckForKernelApcDelivery(v37);
      return -1073741580;
    }
    if ( a5 )
    {
      __pld(&CmpShutdownRundown);
      v33 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v34 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v34 == v33 && __strex(v33 - 2, (unsigned int *)&CmpShutdownRundown) );
      goto LABEL_61;
    }
    v32 = 0;
  }
  v109 = 0;
  v102 = 0;
  v111 = 0;
  v41 = (unsigned __int8 *)CmpNameFromAttributes(a2, v26, &v108);
  v42 = (int)v41;
  v92 = v41;
  if ( (int)v41 < 0 )
  {
    __pld(&CmpShutdownRundown);
    v43 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v44 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v44 == v43 && __strex(v43 - 2, (unsigned int *)&CmpShutdownRundown) );
    v45 = v44 == v43;
LABEL_93:
    if ( !v45 )
      v41 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v46 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v47 = *(_WORD *)(v46 + 0x134) + 1;
    *(_WORD *)(v46 + 308) = v47;
    if ( !v47 && *(_DWORD *)(v46 + 100) != v46 + 100 && !*(_WORD *)(v46 + 310) )
      KiCheckForKernelApcDelivery((int)v41);
    return v42;
  }
  if ( v26 == 1 )
  {
    if ( (a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v41);
    if ( v104 )
    {
      v48 = (_DWORD *)v32;
      if ( v32 >= MmUserProbeAddress )
        v48 = (_DWORD *)MmUserProbeAddress;
      *v48 = 0;
    }
  }
  v49 = *(_DWORD *)a1;
  v50 = *(_DWORD *)(a1 + 4);
  v51 = *(_DWORD *)(a1 + 8);
  v52 = *(_DWORD *)(a1 + 12);
  v114 = *(_DWORD *)a1;
  v115[0] = v50;
  v115[1] = v51;
  v115[2] = v52;
  v53 = *(_DWORD *)(a1 + 20);
  v115[3] = *(_DWORD *)(a1 + 16);
  v115[4] = v53;
  if ( v93 && v115[0] )
  {
    ExFreePoolWithTag(v109);
    __pld(&CmpShutdownRundown);
    v54 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v55 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v55 == v54 && __strex(v54 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v55 != v54 )
      v54 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v56 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v57 = *(_WORD *)(v56 + 0x134) + 1;
    *(_WORD *)(v56 + 308) = v57;
    if ( !v57 && *(_DWORD *)(v56 + 100) != v56 + 100 && !*(_WORD *)(v56 + 310) )
      KiCheckForKernelApcDelivery(v54);
    return -1073741585;
  }
  if ( v26 == 1 )
  {
    v58 = (unsigned int *)v115[1];
    if ( v115[1] >= (unsigned int)MmUserProbeAddress )
      v58 = (unsigned int *)MmUserProbeAddress;
    v93 = *v58;
    v118[11] = v93;
    v59 = v58[1];
    v118[12] = v59;
    v94 = __PAIR64__(v59, v93);
    if ( (_WORD)v93 )
    {
      if ( (v59 & 1) != 0 )
        ExRaiseDatatypeMisalignment(v49);
      v60 = (unsigned __int16)v93 + v59;
      if ( v60 > MmUserProbeAddress || v60 < v59 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
  }
  else
  {
    v94 = *(_QWORD *)*(_DWORD *)(a1 + 8);
  }
  if ( (_WORD)v94 )
  {
    v61 = ExAllocatePoolWithQuotaTag(9u, (unsigned __int16)v94, 1801604419);
    v62 = v61;
    v102 = v61;
    v111 = v61;
    if ( !v61 )
    {
      v63 = ExFreePoolWithTag(v109);
      __pld(&CmpShutdownRundown);
      v64 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v65 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v65 == v64 && __strex(v64 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v65 != v64 )
        v63 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v66 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v67 = *(_WORD *)(v66 + 0x134) + 1;
      *(_WORD *)(v66 + 308) = v67;
      if ( !v67 && *(_DWORD *)(v66 + 100) != v66 + 100 && !*(_WORD *)(v66 + 310) )
        KiCheckForKernelApcDelivery(v63);
      return -1073741670;
    }
    memmove(v61, SHIDWORD(v94), (unsigned __int16)v94);
    HIDWORD(v94) = v62;
  }
  else
  {
    HIDWORD(v94) = 0;
  }
  v115[1] = &v94;
  v115[3] = 0;
  v42 = (int)v92;
  v68 = 0;
  if ( v105 && (int)v92 >= 0 )
  {
    v42 = CmObReferenceObjectByHandle(v105, 0);
    v68 = v110[0];
    v97 = v110[0];
  }
  if ( a5 )
  {
    if ( v42 < 0 )
    {
LABEL_150:
      if ( v68 )
        ObfDereferenceObject(v68);
      ExFreePoolWithTag(v109);
      if ( v102 )
        ExFreePoolWithTag(v102);
      __pld(&CmpShutdownRundown);
      v41 = (unsigned __int8 *)(CmpShutdownRundown & 0xFFFFFFFE);
      __dmb(0xBu);
      do
        v69 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( (unsigned __int8 *)v69 == v41 && __strex((unsigned int)(v41 - 2), (unsigned int *)&CmpShutdownRundown) );
      v45 = v69 == (_DWORD)v41;
      goto LABEL_93;
    }
    v42 = ObReferenceObjectByHandle(a5, 2, ExEventObjectType, v26, &v93, 0);
    v95 = v93;
    v113 = v93;
    v68 = v97;
  }
  if ( v42 < 0 )
    goto LABEL_150;
  v70 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v70 & 0xFFFFFFC0) + 0x134);
  v71 = CmConvertHandleToKernelHandle(v115[0], CmKeyObjectType, v26, 131097, v115);
  v15 = v71;
  if ( v71 >= 0 )
  {
    v72 = 0;
    v117 = 0;
    v73 = memset(v118, 0, 40);
    v110[1] = v110;
    v110[0] = v110;
    v75 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v75 + 308);
    if ( CmpCallBackCount )
    {
      v73 = (_BYTE *)ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, v74, v75, CmpCallBackCount);
      if ( !v73 )
      {
        if ( v115[0] )
        {
          ObReferenceObjectByHandle(v115[0], 0, CmKeyObjectType, 0, &v93, 0);
          v72 = v93;
        }
        v117 = v72;
        v118[0] = &v94;
        v118[1] = &v108;
        v118[2] = a3;
        v118[3] = v97;
        v118[4] = v95;
        v118[5] = a6;
        v118[6] = a7;
        v73 = (_BYTE *)CmpCallCallBacks(32, &v117, 1, 33, 0, v110);
        v15 = (int)v73;
      }
    }
    if ( v15 < 0 )
    {
      if ( v15 == -1073740541 )
      {
        v15 = 0;
        v112 = 1;
      }
    }
    else
    {
      CmpTraceHiveLoadStart(&v108, a3);
      v107 = 1;
      if ( (a3 & 0x10) != 0 )
      {
        __pld(&CmpShutdownRundown);
        v77 = CmpShutdownRundown & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v78 = __ldrex((unsigned int *)&CmpShutdownRundown);
        while ( v78 == v77 && __strex(v77 - 2, (unsigned int *)&CmpShutdownRundown) );
        if ( v78 != v77 )
          v77 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
        v79 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v80 = *(_WORD *)(v79 + 0x134) + 1;
        *(_WORD *)(v79 + 308) = v80;
        if ( !v80 && *(_DWORD *)(v79 + 100) != v79 + 100 && !*(_WORD *)(v79 + 310) )
          KiCheckForKernelApcDelivery(v77);
        v106 = 0;
        v76 = CmLoadAppKey(&v114, &v108, a3, v97, v95, &v101, &v103);
      }
      else
      {
        v76 = CmLoadKey(&v114, &v108, a3, v97, v95, &v101, &v103);
      }
      v73 = (_BYTE *)CmPostCallbackNotification(33, v72, v76, &v117, v110);
      v15 = (int)v73;
      v99 = (__int64 *)v101;
      v100 = v103;
    }
    v81 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v82 = *(_WORD *)(v81 + 0x134) + 1;
    *(_WORD *)(v81 + 308) = v82;
    if ( !v82 && *(_DWORD *)(v81 + 100) != v81 + 100 && !*(_WORD *)(v81 + 310) )
      KiCheckForKernelApcDelivery((int)v73);
    v71 = v115[0];
    if ( v115[0] )
      v71 = ZwClose();
    if ( v72 )
      v71 = ObfDereferenceObject(v72);
  }
  if ( v97 )
    v71 = ObfDereferenceObject(v97);
  if ( v15 >= 0 && v104 && !v112 )
  {
    v92 = 0;
    if ( (a3 & 0x10) != 0 )
      v119 = 64;
    v83 = (unsigned __int64 *)v99;
    if ( !v99 )
    {
      v99 = (__int64 *)&v94;
      v101 = &v94;
      v83 = &v94;
    }
    v71 = ObReferenceObjectByName(v83, 64, 0, 0, CmKeyObjectType, 0, &v119, &v92);
    v15 = v71;
    if ( v71 >= 0 )
    {
      ObDeleteCapturedInsertInfo(v92);
      v15 = ObOpenObjectByPointer(v92, 64, 0, a6, CmKeyObjectType, v26, &v116);
      v71 = ObfDereferenceObject((int)v92);
      if ( v15 >= 0 )
        *a7 = v116;
    }
    if ( v100 )
    {
      if ( (a3 & 0x10) != 0 )
        v71 = CmReleaseLoadKeyContext(v100, v15);
      else
        v71 = CmpDereferenceKeyControlBlock(v100);
      v100 = 0;
    }
    if ( v15 < 0 && (a3 & 0x800) != 0 )
      v15 = 0;
  }
  if ( v100 )
    v71 = CmReleaseLoadKeyContext(v100, v15);
  v84 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v85 = *(_WORD *)(v84 + 0x134) + 1;
  *(_WORD *)(v84 + 308) = v85;
  if ( !v85 && *(_DWORD *)(v84 + 100) != v84 + 100 && !*(_WORD *)(v84 + 310) )
    KiCheckForKernelApcDelivery(v71);
  if ( v99 && v99 != (__int64 *)&v94 )
    ExFreePoolWithTag((unsigned int)v99);
  if ( v95 )
    ObfDereferenceObject(v95);
  ExFreePoolWithTag(v109);
  if ( v102 )
    ExFreePoolWithTag(v102);
  if ( v106 )
  {
    __pld(&CmpShutdownRundown);
    v86 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v87 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v87 == v86 && __strex(v86 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v87 != v86 )
      v86 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v88 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v89 = *(_WORD *)(v88 + 0x134) + 1;
    *(_WORD *)(v88 + 308) = v89;
    if ( !v89 && *(_DWORD *)(v88 + 100) != v88 + 100 && !*(_WORD *)(v88 + 310) )
      KiCheckForKernelApcDelivery(v86);
  }
  if ( v107 )
    CmpTraceHiveLoadStop(v15);
  return v15;
}
