// NtCreateUserProcess 
 
int __fastcall NtCreateUserProcess(_DWORD *a1, _BYTE *a2, unsigned int a3, int a4, int a5, int a6, unsigned int a7, int a8, int a9, int a10, int a11)
{
  int v12; // r0
  int v13; // r9
  char v14; // r8
  int v15; // r4
  _DWORD *v16; // r2
  _DWORD *v17; // r2
  int v18; // r3
  unsigned int v19; // r2
  _BYTE *v20; // r10
  int v21; // r2
  int v22; // r3
  int v23; // r3
  int v24; // r0
  int *v25; // r6
  _BYTE *v26; // r5
  unsigned __int8 v27; // r2
  int v28; // r5
  int v29; // r3
  int v30; // r2
  unsigned int *v31; // r6
  unsigned int v32; // r1
  int v33; // r0
  int v34; // r1
  __int16 v35; // r3
  unsigned int v36; // r4
  int v37; // r3
  int v38; // r8
  int v39; // r6
  int v40; // r0
  int v41; // r1
  __int16 v42; // r3
  int *v44; // [sp+4h] [bp-62Ch]
  int v45; // [sp+Ch] [bp-624h]
  unsigned __int8 v46; // [sp+30h] [bp-600h] BYREF
  unsigned __int8 v47; // [sp+31h] [bp-5FFh] BYREF
  _BYTE v48[2]; // [sp+32h] [bp-5FEh] BYREF
  _BYTE *v49; // [sp+34h] [bp-5FCh] BYREF
  _BYTE *v50; // [sp+38h] [bp-5F8h]
  int v51; // [sp+3Ch] [bp-5F4h] BYREF
  unsigned int v52; // [sp+40h] [bp-5F0h]
  _BYTE *v53; // [sp+44h] [bp-5ECh]
  int v54; // [sp+48h] [bp-5E8h]
  unsigned int v55; // [sp+4Ch] [bp-5E4h]
  unsigned int v56; // [sp+50h] [bp-5E0h]
  _DWORD *v57; // [sp+54h] [bp-5DCh] BYREF
  unsigned int v58; // [sp+58h] [bp-5D8h] BYREF
  _DWORD *v59; // [sp+5Ch] [bp-5D4h]
  int v60; // [sp+60h] [bp-5D0h]
  unsigned int v61; // [sp+64h] [bp-5CCh]
  int v62; // [sp+68h] [bp-5C8h]
  int v63; // [sp+70h] [bp-5C0h]
  int v64; // [sp+74h] [bp-5BCh]
  int v65; // [sp+78h] [bp-5B8h]
  int v66; // [sp+7Ch] [bp-5B4h]
  __int16 v67; // [sp+80h] [bp-5B0h] BYREF
  int v68; // [sp+84h] [bp-5ACh]
  int v69; // [sp+88h] [bp-5A8h]
  int v70; // [sp+8Ch] [bp-5A4h]
  int v71; // [sp+90h] [bp-5A0h]
  _DWORD v72[2]; // [sp+98h] [bp-598h] BYREF
  _DWORD *v73; // [sp+A0h] [bp-590h]
  int v74; // [sp+A4h] [bp-58Ch]
  int v75; // [sp+A8h] [bp-588h]
  int v76; // [sp+ACh] [bp-584h]
  _DWORD v77[6]; // [sp+B0h] [bp-580h] BYREF
  _BYTE v78[8]; // [sp+C8h] [bp-568h] BYREF
  int v79[4]; // [sp+D0h] [bp-560h] BYREF
  _DWORD v80[60]; // [sp+E0h] [bp-550h] BYREF
  _BYTE v81[28]; // [sp+1D0h] [bp-460h] BYREF
  int v82; // [sp+1ECh] [bp-444h] BYREF
  int v83; // [sp+308h] [bp-328h]
  char v84; // [sp+30Ch] [bp-324h]
  int v85; // [sp+310h] [bp-320h]
  _DWORD v86[82]; // [sp+318h] [bp-318h] BYREF
  int v87; // [sp+460h] [bp-1D0h] BYREF
  int v88; // [sp+470h] [bp-1C0h] BYREF
  _DWORD _474[117]; // [sp+474h] [bp-1BCh] BYREF

  _474[113] = a1;
  _474[114] = a2;
  v60 = a4;
  _474[116] = a4;
  v56 = a3;
  _474[115] = a3;
  v61 = (unsigned int)a2;
  v59 = a1;
  v57 = a1;
  v53 = a2;
  v54 = a5;
  v65 = a5;
  v63 = a6;
  v71 = a6;
  v51 = a9;
  v66 = a9;
  v64 = a10;
  v49 = (_BYTE *)a11;
  v67 = 0;
  v68 = 0;
  v69 = 0;
  v70 = 0;
  v77[0] = 0;
  v77[1] = 0;
  v77[2] = 0;
  v77[3] = 0;
  v77[4] = 0;
  v88 = 0;
  memset(_474, 0, 412);
  v55 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v58 = v55;
  v12 = *(_DWORD *)(v55 + 0x74);
  v50 = (_BYTE *)v12;
  v62 = v12;
  v13 = *(char *)(v55 + 0x15A);
  v48[1] = *(_BYTE *)(v55 + 0x15A);
  v14 = a7;
  v52 = a7;
  if ( (a7 & 0xFFFF6838) != 0 || (a8 & 0xFFFFFFFE) != 0 )
    return -1073741811;
  if ( (a7 & 0x8400) == 33792 )
    return -1073741776;
  v83 = 0;
  v84 = v13;
  if ( v13 )
  {
    v16 = a1;
    if ( (unsigned int)v59 >= MmUserProbeAddress )
      v16 = (_DWORD *)MmUserProbeAddress;
    *v16 = *v16;
    v17 = (_DWORD *)v61;
    if ( v61 >= MmUserProbeAddress )
      v17 = (_DWORD *)MmUserProbeAddress;
    *v17 = *v17;
  }
  if ( a5 )
  {
    if ( v13 && (a5 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v12);
    if ( v13 )
      v18 = 3570;
    else
      v18 = 69618;
    v83 = v18 & *(_DWORD *)(a5 + 12);
  }
  memset(v80, 0, sizeof(v80));
  if ( !a11 || (v15 = PspBuildCreateProcessContext(a11, v13, 0, v80), v15 >= 0) )
  {
    v19 = v80[1];
    if ( (a7 & 0x40) != 0 && (v80[1] & 0x20000) != 0 && !LOBYTE(v80[54]) )
    {
      v14 = a7 & 0xBF;
      v52 = a7 & 0xFFFFFFBF;
      v19 = v80[1] & 0xFFFDFFFF;
      v80[1] &= 0xFFFDFFFF;
    }
    if ( (v14 & 4) != 0 )
    {
      if ( v13 && (v19 & 0x800) == 0 && (v14 & 0x40) == 0 && (v50[734] & 7) != 0 )
        goto LABEL_138;
    }
    else if ( (v19 & 0x800) != 0 )
    {
      goto LABEL_138;
    }
    if ( (v19 & 0x20000) != 0 && (v14 & 0x40) == 0 )
      goto LABEL_138;
    v15 = PspCaptureCreateInfo(v13, a10, v80);
    if ( v15 < 0 )
      goto LABEL_139;
    if ( (v80[1] & 1) != 0 )
    {
      v15 = ObReferenceObjectByHandleWithTag(v80[19], 128, PsProcessType, v13, 1917023056, &v49, 0);
      if ( v15 < 0 )
        goto LABEL_139;
      v20 = v49;
      v80[20] = v49;
      v21 = (int)v50;
    }
    else
    {
      v21 = (int)v50;
      v20 = v50;
    }
    v53 = v20;
    if ( (BYTE1(v80[2]) & 6) == 2 && (v20 != (_BYTE *)v21 || v21 == PsInitialSystemProcess) )
      goto LABEL_138;
    v15 = PspReferenceTokenForNewProcess(v20, v80[22], v13, &v80[23]);
    if ( v15 < 0 )
    {
      v80[23] = 0;
      goto LABEL_139;
    }
    if ( (v80[1] & 0x20) != 0 )
    {
      if ( (v80[1] & 0x20000) != 0 )
        v22 = LOBYTE(v80[54]);
      else
        v22 = 0;
      v46 = v22;
      v15 = SeQuerySigningPolicy(v80[23], (int)&v80[34], (v52 & 0x40) != 0, v22, &v47, v48, &v46);
      if ( v15 < 0 )
        goto LABEL_139;
      if ( v13 == 1 )
        v23 = 1024;
      else
        v23 = 0;
      v72[0] = 24;
      v72[1] = 0;
      v74 = v23 | 0x240;
      v73 = &v80[34];
      v75 = 0;
      v76 = 0;
      v15 = 0;
      if ( off_92049C )
        v15 = off_92049C(v80[23]);
      if ( v15 < 0 )
        goto LABEL_139;
      v15 = PspCreateUserProcessEcp(&v67, v80[23]);
      if ( v15 < 0 )
        goto LABEL_139;
      v15 = IoCreateFileEx(&v80[25], v80[24] | 0x100020, v72, v78, 0, 128, 5, 1, 96, 0, 0, 0, 0, 0, &v67);
      if ( v15 < 0 )
      {
        if ( v80[24] )
          v15 = IoCreateFileEx(&v80[25], 1048608, v72, v78, 0, 128, 5, 1, 96, 0, 0, 0, 0, 0, &v67);
        if ( v15 < 0 )
        {
          v80[25] = 0;
          v24 = 1;
LABEL_61:
          PspUpdateCreateInfo(v24, v80, 0);
          goto LABEL_139;
        }
      }
      v15 = ObReferenceObjectByHandle(v80[25], 1048608, IoFileObjectType, 0, &v49);
      v80[26] = v49;
      if ( v15 < 0 )
      {
        v80[26] = 0;
        goto LABEL_139;
      }
      v73 = 0;
      v15 = MmCreateSpecialImageSection(&v80[27], v72, v47, v80[25], 1, 0);
      if ( v15 < 0 )
      {
        v80[27] = 0;
        v24 = 2;
        goto LABEL_61;
      }
      v15 = ObReferenceObjectByHandle(v80[27], 8, MmSectionObjectType, 0, &v49);
      v80[29] = v49;
      if ( v15 < 0 )
      {
        v80[29] = 0;
        goto LABEL_139;
      }
      if ( (v46 & 7) != 1 && PspCheckForInvalidAccessByProtection(v13, (unsigned __int8)v50[734], v46) )
        LOBYTE(v80[2]) |= 8u;
      v15 = PspCaptureProcessParameters(v13, v51, v80);
      if ( v15 < 0 )
      {
        LOBYTE(v80[2]) &= 0xFBu;
        goto LABEL_139;
      }
      v25 = &v87;
      v26 = v53;
LABEL_86:
      v15 = PspAllocateProcess(v26, v13, v54, v46, v47, v48[0], v80[29], v80[23], v52, v80, v80[22] != 0, &v49, &v51);
      if ( v15 < 0 )
        goto LABEL_139;
      v28 = v51;
      if ( v80[29] )
        PspCreateUserContext(&v88, PspUserThreadStart, v80[7], *(_DWORD *)(v51 + 320));
      ObfReferenceObjectWithTag(v28);
      if ( v25 )
      {
        *(_BYTE *)v25 = 0;
        v29 = 0x40000;
        if ( v80[9] >= 0x40000u )
          v29 = v80[9];
        v25[3] = v29;
        v25[2] = v80[10];
        v25[1] = v80[8];
      }
      v54 = 0;
      v30 = (a8 & 1) != 0;
      if ( (a8 & 2) != 0 )
        v30 |= 2u;
      if ( (a8 & 4) != 0 )
        v30 |= 4u;
      if ( (a8 & 0x10) != 0 )
        v30 |= 0x80u;
      if ( v49 )
      {
        v54 = 2;
        v30 |= 0x10u;
      }
      v79[0] = (int)v77;
      v57 = (_DWORD *)(v30 | 0x60);
      v15 = PspAllocateThread(v28, v63, v13, v80, &v88, v79, 0, 0, &v57, &v58, v25, v86);
      if ( v15 < 0 )
      {
        v31 = (unsigned int *)(v28 + 168);
        __dmb(0xBu);
        do
          v32 = __ldrex(v31);
        while ( __strex(v32 - 1, v31) );
        if ( (v32 & 2) != 0 && (v32 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)(v28 + 168));
        v33 = KeAbPostRelease(v28 + 168);
        v34 = v55;
        v35 = *(_WORD *)(v55 + 308) + 1;
        *(_WORD *)(v55 + 308) = v35;
        if ( !v35 && *(_DWORD *)(v34 + 100) != v34 + 100 && !*(_WORD *)(v34 + 310) )
          KiCheckForKernelApcDelivery(v33);
        PspRundownSingleProcess((unsigned int *)v28, 0);
        goto LABEL_137;
      }
      if ( PspCheckForInvalidAccessByProtection(v13, (unsigned __int8)v50[734], *(unsigned __int8 *)(v28 + 734)) )
      {
        if ( (v56 & 0x2000000) != 0 )
          v56 = (~RtlProtectedAccess[3 * (v46 >> 4) + 1] & 0x1FFFFF | v56) & 0xFDFFFFFF;
        v36 = v60;
        if ( (v60 & 0x2000000) != 0 )
          v36 = (~RtlProtectedAccess[3 * (v46 >> 4) + 2] & 0x1FFFFF | v60) & 0xFDFFFFFF;
      }
      else
      {
        v36 = v60;
      }
      if ( v80[30] )
        v37 = v80[30] + 64;
      else
        v37 = 0;
      v38 = PspInsertProcess(v28, v53, v56, v52, v80[21], v54, v37, v81);
      v44 = v25;
      v39 = v58;
      v40 = PspInsertThread(v58, v28, v77, &v57, v36, v44, v80, v45, v86, v61, v80[3]);
      v15 = v40;
      v41 = v55;
      v42 = *(_WORD *)(v55 + 308) + 1;
      *(_WORD *)(v55 + 308) = v42;
      if ( !v42 && *(_DWORD *)(v41 + 100) != v41 + 100 && !*(_WORD *)(v41 + 310) )
        KiCheckForKernelApcDelivery(v40);
      if ( v38 < 0 )
      {
        PspRundownSingleProcess((unsigned int *)v28, 0);
        v15 = v38;
LABEL_136:
        ObfDereferenceObject(v39);
LABEL_137:
        ObfDereferenceObjectWithTag(v28);
        goto LABEL_139;
      }
      if ( v15 >= 0 )
      {
        v15 = PspCreateObjectHandle(v28, v81, PsProcessType);
        if ( v15 >= 0 )
        {
          if ( v80[5] )
            memmove(v80[5], (int)&v80[7], 0x30u);
          *v59 = v85;
          v15 = PspUpdateCreateInfo(6, v80, v28);
          if ( v15 >= 0 )
            goto LABEL_134;
          ObCloseHandle(v85);
        }
        ObCloseHandle(v86[80]);
      }
LABEL_134:
      SepDeleteAccessState((int)v81);
      SeReleaseSubjectContext((int)&v82);
      if ( v15 < 0 )
        PsTerminateProcess(v28, v15);
      goto LABEL_136;
    }
    if ( v20 == v50
      && v13
      && !v51
      && (v80[2] & 0x600) == 0
      && (v80[1] & 0x80) == 0
      && (v80[1] & 0x20000) == 0
      && (v80[2] & 0x10) == 0 )
    {
      LOBYTE(v80[2]) &= 0xFBu;
      v26 = v53;
      v27 = v53[734];
      v46 = v27;
      v48[0] = v53[733];
      v47 = v53[732];
      if ( (v52 & 0x40) != 0 && (v27 & 7) == 0 )
      {
        v15 = -1073741790;
        goto LABEL_139;
      }
      v88 = 2097167;
      v15 = PspGetContextThreadInternal(v55, &v88, 0, 1);
      if ( v15 < 0 )
      {
LABEL_139:
        PspDeleteCreateProcessContext(v80);
        if ( v68 )
          FsRtlFreeExtraCreateParameterList(v68);
        return v15;
      }
      _474[0] = 297;
      v25 = 0;
      goto LABEL_86;
    }
LABEL_138:
    v15 = -1073741811;
    goto LABEL_139;
  }
  return v15;
}
