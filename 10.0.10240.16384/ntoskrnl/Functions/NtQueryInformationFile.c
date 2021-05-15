// NtQueryInformationFile 
 
int __fastcall NtQueryInformationFile(int a1, int *a2, _DWORD *a3, unsigned int a4, unsigned int a5)
{
  int *v6; // r9
  int v8; // r10
  unsigned int v9; // r6
  int *v10; // r2
  int v11; // r8
  _DWORD *v12; // r5
  _DWORD *v13; // r3
  int v14; // r0
  int v15; // r4
  int v16; // r0
  int v17; // r10
  int v18; // r4
  int v19; // r4
  int v20; // r3
  unsigned int *v21; // r2
  unsigned int v22; // r1
  signed int v23; // r0
  unsigned int v24; // r1
  __int16 v25; // r3
  int *v26; // r2
  _DWORD *v27; // r2
  unsigned int *v28; // r2
  unsigned int v29; // r1
  int v30; // r0
  unsigned int v31; // r1
  __int16 v32; // r3
  int (__fastcall *v33)(_DWORD *, int, int *, unsigned int *, int); // r8
  int (__fastcall *v34)(_DWORD *, int, int *, unsigned int *, int); // r4
  int v35; // r0
  unsigned __int8 v36; // r0
  int v37; // r2
  unsigned int v38; // r5
  unsigned int *v39; // r1
  int v40; // r4
  unsigned int *v41; // r2
  unsigned int v42; // r1
  int v43; // r0
  unsigned int v44; // r1
  __int16 v45; // r3
  int v46; // r0
  int v47; // r8
  int v48; // r2
  int v49; // r4
  int v50; // r0
  int v51; // r3
  unsigned int v52; // r2
  unsigned __int64 *v53; // r0
  unsigned __int64 v54; // r2
  unsigned int *v55; // r1
  unsigned int v56; // r0
  int v57; // r4
  int v58; // r9
  __int64 v59; // r0
  _DWORD *v60; // r2
  int v61; // r3
  int v62; // r3
  int v63; // r3
  int v64; // r3
  int v65; // r3
  __int64 v66; // r0
  int v67; // r6
  int v68; // r1
  unsigned int v69; // r2
  unsigned int v70; // r3
  _DWORD *v71; // r2
  int v72; // r1
  int v73; // r0
  int v74; // r2
  _WORD *v75; // r3
  _DWORD *v77; // r2
  BOOL v78; // r4
  char v79; // r3
  int v80; // r0
  BOOL v81; // r9
  int v82; // r0
  unsigned int *v83; // r2
  unsigned int v84; // r1
  int v85; // r0
  unsigned int v86; // r1
  int v87; // r3
  int v88; // r0
  _DWORD *v89; // r2
  int v90; // r3
  int v91; // r4
  unsigned int *v92; // r2
  unsigned int v93; // r1
  unsigned int v94; // r1
  __int16 v95; // r3
  char v97; // [sp+9h] [bp-A7h] BYREF
  char v98; // [sp+Ah] [bp-A6h]
  unsigned __int8 v99; // [sp+Bh] [bp-A5h]
  int v100; // [sp+Ch] [bp-A4h]
  int v101; // [sp+10h] [bp-A0h]
  char v103; // [sp+18h] [bp-98h]
  _DWORD *v104; // [sp+1Ch] [bp-94h]
  char v105; // [sp+20h] [bp-90h]
  char v106; // [sp+21h] [bp-8Fh]
  int *v107; // [sp+24h] [bp-8Ch] BYREF
  unsigned int v108; // [sp+28h] [bp-88h]
  int *v109; // [sp+2Ch] [bp-84h] BYREF
  int *v110; // [sp+30h] [bp-80h]
  int v111; // [sp+34h] [bp-7Ch] BYREF
  int v112; // [sp+38h] [bp-78h]
  _DWORD *v113; // [sp+3Ch] [bp-74h] BYREF
  unsigned int v114; // [sp+40h] [bp-70h]
  char v115; // [sp+44h] [bp-6Ch]
  unsigned int *v116; // [sp+48h] [bp-68h]
  unsigned int v117; // [sp+50h] [bp-60h] BYREF
  unsigned int v118; // [sp+54h] [bp-5Ch]
  int v119; // [sp+58h] [bp-58h]
  int v120; // [sp+60h] [bp-50h] BYREF
  int v121; // [sp+64h] [bp-4Ch]
  _DWORD *v122; // [sp+68h] [bp-48h] BYREF
  _BYTE v123[16]; // [sp+70h] [bp-40h] BYREF
  int v124; // [sp+80h] [bp-30h] BYREF
  int v125; // [sp+84h] [bp-2Ch]
  int v126; // [sp+88h] [bp-28h]
  int v127; // [sp+8Ch] [bp-24h]
  int vars4; // [sp+B4h] [bp+4h]
  int varg_r0; // [sp+B8h] [bp+8h]
  int *varg_r1; // [sp+BCh] [bp+Ch]
  _DWORD *varg_r2; // [sp+C0h] [bp+10h]
  unsigned int varg_r3; // [sp+C4h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v108 = a4;
  varg_r3 = a4;
  v110 = a3;
  v6 = a2;
  v104 = a2;
  v111 = a1;
  v116 = (unsigned int *)a2;
  v107 = a3;
  v120 = 0;
  v121 = 0;
  v100 = 0;
  v117 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v109 = (int *)v117;
  v8 = *(char *)(v117 + 0x15A);
  v112 = v8;
  v98 = v8;
  v9 = a5;
  if ( v8 )
  {
    if ( a5 >= 0x40 || !*((_BYTE *)&IopQueryOperationLength + a5) )
      return -1073741821;
    if ( a4 < *((unsigned __int8 *)&IopQueryOperationLength + a5) )
      return -1073741820;
    v10 = a2;
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v10 = (int *)MmUserProbeAddress;
    *v10 = *v10;
    ProbeForWrite(a3, a4, *((unsigned __int8 *)IopQuerySetAlignmentRequirement + a5));
  }
  v11 = ObReferenceObjectByHandle(a1, IopQueryOperationAccess[a5], IoFileObjectType, v8, &v113, &v124);
  v12 = v113;
  v122 = v113;
  if ( v11 >= 0 )
  {
    v13 = (_DWORD *)v113[31];
    if ( v13 )
    {
      if ( (*v13 & 4) != 0 )
      {
        v14 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        v111 = 0;
        v15 = PsReferencePrimaryToken(v14);
        SeQueryInformationToken(v15, 29, &v111);
        ObfDereferenceObject(v15);
        if ( v111 )
        {
          ObfDereferenceObject((int)v12);
          v11 = -1073739504;
        }
      }
    }
  }
  v114 = v11;
  if ( v11 < 0 )
    return v11;
  if ( (v12[11] & 0x800) != 0 )
    v16 = IoGetAttachedDevice(v12[1]);
  else
    v16 = IoGetRelatedDeviceObject(v12);
  v17 = v16;
  v111 = v16;
  v18 = *(_DWORD *)(*(_DWORD *)(v16 + 8) + 40);
  if ( a5 == 51 )
  {
    v106 = 1;
    if ( v108 )
    {
      *(_BYTE *)v110 = (*(_DWORD *)(v12[1] + 32) & 0x10) != 0;
      v106 = 0;
      *v6 = 0;
      v6[1] = 1;
    }
    else
    {
      v11 = -1073741820;
    }
LABEL_26:
    ObfDereferenceObject((int)v12);
    return v11;
  }
  if ( a5 == 58 )
  {
    v19 = IopGetFileVolumeNameInformation(v12[1], v6, v110, v108);
    ObfDereferenceObject((int)v12);
    return v19;
  }
  if ( (v12[11] & 2) != 0 )
  {
    v20 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v20 & 0xFFFFFFC0) + 0x134);
    __dmb(0xBu);
    v21 = v12 + 17;
    do
      v22 = __ldrex(v21);
    while ( __strex(1u, v21) );
    __dmb(0xBu);
    if ( v22 )
    {
      v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v25 = *(_WORD *)(v24 + 0x134) + 1;
      *(_WORD *)(v24 + 308) = v25;
      if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
        KiCheckForKernelApcDelivery(1);
      v23 = IopAcquireFileObjectLock(v12, v112, (v12[11] & 4) != 0, &v97);
      v11 = v23;
      v114 = v23;
      if ( v97 )
        goto LABEL_26;
    }
    else
    {
      v23 = ObfReferenceObject((int)v12);
    }
    if ( a5 == 14 )
    {
      v105 = 1;
      if ( v108 >= 8 )
      {
        v26 = v110;
        *v110 = v12[14];
        v26[1] = v12[15];
        v105 = 0;
        v27 = v104;
        *v104 = 0;
        v27[1] = 8;
      }
      else
      {
        v11 = -1073741820;
      }
      __dmb(0xBu);
      v28 = v12 + 17;
      do
        v29 = __ldrex(v28);
      while ( __strex(0, v28) );
      __dmb(0xBu);
      if ( v12[16] )
        KeSetEvent((int)(v12 + 19), 0, 0);
      v30 = ObfDereferenceObject((int)v12);
      v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v32 = *(_WORD *)(v31 + 0x134) + 1;
      *(_WORD *)(v31 + 308) = v32;
      if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 && !*(_WORD *)(v31 + 310) )
        KiCheckForKernelApcDelivery(v30);
      ObfDereferenceObject((int)v12);
      return v11;
    }
    if ( v18 )
    {
      if ( (v33 = *(int (__fastcall **)(_DWORD *, int, int *, unsigned int *, int))(v18 + 16),
            v101 = (int)v33,
            v34 = *(int (__fastcall **)(_DWORD *, int, int *, unsigned int *, int))(v18 + 20),
            a5 == 4)
        && v33
        || a5 == 5 && v34 )
      {
        v117 = 0;
        v118 = 0;
        v99 = 0;
        v103 = 0;
        if ( (MmVerifierData & 0x10) != 0 )
          v35 = VfFastIoSnapState(v23);
        else
          v35 = 0;
        v119 = v35;
        if ( a5 == 4 )
          v36 = v33(v12, 1, v110, &v117, v17);
        else
          v36 = v34(v12, 1, v110, &v117, v17);
        v99 = v36;
        if ( v119 )
          VfFastIoCheckState(v119, v101);
        v37 = v99;
        if ( v99 )
        {
          v38 = v117;
          v114 = v117;
          v103 = 1;
          v39 = v116;
          v104 = v116;
          *v116 = v117;
          v39[1] = v118;
        }
        else
        {
          v38 = v114;
          v104 = v116;
        }
        if ( v37 )
        {
          __dmb(0xBu);
          v40 = (int)v113;
          v41 = v113 + 17;
          do
            v42 = __ldrex(v41);
          while ( __strex(0, v41) );
          __dmb(0xBu);
          if ( *(_DWORD *)(v40 + 64) )
            KeSetEvent(v40 + 76, 0, 0);
          v43 = ObfDereferenceObject(v40);
          v44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v45 = *(_WORD *)(v44 + 0x134) + 1;
          *(_WORD *)(v44 + 308) = v45;
          if ( !v45 && *(_DWORD *)(v44 + 100) != v44 + 100 && !*(_WORD *)(v44 + 310) )
            KiCheckForKernelApcDelivery(v43);
          ObfDereferenceObject(v40);
          return v38;
        }
        v9 = a5;
        v108 = varg_r3;
        v100 = 0;
        v117 = (unsigned int)v109;
        v112 = v98;
        v17 = v111;
        v12 = v113;
        v110 = v107;
      }
    }
    v101 = 1;
    v97 = 1;
  }
  else
  {
    KeInitializeEvent((int)v123, 1, 0);
    v101 = 0;
    v97 = 0;
  }
  if ( (v12[11] & 0x4000000) == 0 )
    KeResetEvent((int)(v12 + 23));
  v46 = pIoAllocateIrp(v17, *(char *)(v17 + 48), 0, vars4);
  v47 = v46;
  v107 = (int *)v46;
  if ( !v46 )
  {
    IopAllocateIrpCleanup(v12, 0);
    return -1073741670;
  }
  *(_DWORD *)(v46 + 100) = v12;
  *(_DWORD *)(v46 + 80) = v117;
  v48 = v112;
  *(_BYTE *)(v46 + 32) = v112;
  if ( v101 )
  {
    *(_DWORD *)(v46 + 44) = 0;
    *(_DWORD *)(v46 + 40) = v104;
    *(_BYTE *)(v46 + 39) |= 2u;
  }
  else
  {
    if ( v48 == 1 )
      v100 = KeSetKernelStackSwapEnable(0);
    *(_DWORD *)(v47 + 44) = v123;
    *(_DWORD *)(v47 + 40) = &v120;
    *(_DWORD *)(v47 + 8) = 4;
  }
  *(_DWORD *)(v47 + 48) = 0;
  v49 = *(_DWORD *)(v47 + 96) - 40;
  v109 = (int *)v49;
  *(_BYTE *)v49 = 5;
  *(_DWORD *)(v49 + 28) = v12;
  *(_DWORD *)(v47 + 60) = v110;
  *(_DWORD *)(v47 + 12) = 0;
  *(_DWORD *)(v47 + 4) = 0;
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v51 = 40;
    else
      v51 = 32;
    v50 = ExAllocatePoolWithTagPriority(512, v108, 538996553, v51);
    if ( !v50 )
      RtlRaiseStatus(-1073741670);
  }
  else
  {
    v50 = ExAllocatePoolWithQuotaTag(0x200u, v108, 538996553);
  }
  *(_DWORD *)(v47 + 12) = v50;
  v52 = v108;
  *(_DWORD *)(v47 + 8) |= 0x870u;
  *(_DWORD *)(v49 + 8) = v52;
  *(_DWORD *)(v49 + 12) = v9;
  IopQueueThreadIrp(v47);
  if ( IoCountOperations == 1 )
  {
    v53 = (unsigned __int64 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150) + 448);
    do
      v54 = __ldrexd(v53);
    while ( __strexd(v54 + 1, v53) );
    v55 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3036);
    do
      v56 = __ldrex(v55);
    while ( __strex(v56 + 1, v55) );
  }
  v57 = 0;
  v58 = 0;
  switch ( v9 )
  {
    case 8u:
      **(_DWORD **)(v47 + 12) = v125;
      *(_DWORD *)(v47 + 28) = 4;
LABEL_135:
      *(_DWORD *)(v47 + 24) = v58;
      v67 = v101;
      goto LABEL_164;
    case 0x10u:
      v59 = IopGetModeInformation(v12);
      *(_DWORD *)HIDWORD(v59) = v59;
      *(_DWORD *)(v47 + 28) = 4;
      goto LABEL_135;
    case 0x11u:
      **(_DWORD **)(v47 + 12) = *(_DWORD *)(v17 + 92);
      *(_DWORD *)(v47 + 28) = 4;
      goto LABEL_135;
    case 0x29u:
      v60 = *(_DWORD **)(v47 + 12);
      *v60 = 0;
      if ( (v12[11] & 0x4000000) != 0 )
        *v60 = 2;
      if ( (v12[11] & 0x8000000) != 0 )
        *v60 |= 4u;
      if ( (v12[11] & 0x2000000) != 0 )
        *v60 |= 1u;
      *(_DWORD *)(v47 + 28) = 4;
      goto LABEL_135;
    case 0x2Bu:
      v61 = v12[31];
      if ( v61 && (v62 = *(_DWORD *)(v61 + 32)) != 0 )
        v63 = v62 - 1;
      else
        v63 = 2;
      **(_DWORD **)(v47 + 12) = v63;
      *(_DWORD *)(v47 + 28) = 4;
      goto LABEL_135;
    case 0x2Fu:
      v58 = IopQueryProcessIdsUsingFile(v12, *(_DWORD *)(v47 + 12), v108, &v109);
      v57 = 1;
      v115 = 1;
      if ( v58 == -1073741820 )
      {
        v104[1] = v109;
        v64 = v101;
        goto LABEL_134;
      }
      v65 = (int)v109;
      goto LABEL_132;
  }
  if ( v9 != 53 )
  {
    if ( v9 != 18 )
    {
LABEL_133:
      v64 = v101;
      goto LABEL_134;
    }
    *(_DWORD *)(*(_DWORD *)(v47 + 12) + 76) = v125;
    v66 = IopGetModeInformation(v12);
    *(_DWORD *)(HIDWORD(v66) + 88) = v66;
    *(_DWORD *)(HIDWORD(v66) + 92) = *(_DWORD *)(v17 + 92);
    v65 = 12;
LABEL_132:
    *(_DWORD *)(v47 + 28) = v65;
    goto LABEL_133;
  }
  v58 = IopGetNumaNodeInformation(v12, *(_DWORD *)(v47 + 12));
  v57 = 1;
  v64 = v101;
  if ( v58 >= 0 )
    *(_DWORD *)(v47 + 28) = 2;
LABEL_134:
  if ( v57 )
    goto LABEL_135;
  if ( !v64 )
    ObfReferenceObject((int)v12);
  v68 = v12[31];
  if ( v68 && *(_DWORD *)(v68 + 32) )
  {
    v69 = *(_DWORD *)(v47 + 8) & 0xFFF1FFFF;
    *(_DWORD *)(v47 + 8) = v69;
    v70 = v69 | (*(_DWORD *)(v68 + 32) << 17);
  }
  else
  {
    v71 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    v72 = (v71[240] >> 9) & 7;
    if ( (*(_DWORD *)(v71[84] + 192) & 0x100000) != 0 )
      v72 = 0;
    if ( v72 < 2 && v71 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v71[250] )
      v72 = 2;
    v70 = *(_DWORD *)(v47 + 8) & 0xFFF1FFFF | ((v72 + 1) << 17);
  }
  *(_DWORD *)(v47 + 8) = v70;
  v73 = IoGetIoPriorityHint(v47);
  if ( !*(_BYTE *)(v47 + 32) && v73 < 2 )
  {
    v74 = *(_DWORD *)(v47 + 80);
    if ( !v74 || (*(_DWORD *)(v74 + 76) & 0x400) == 0 && (*(_DWORD *)(v74 + 964) & 0x20) == 0 )
    {
      ++IoKernelIssuedIoBoostedCount;
      *(_DWORD *)(v47 + 8) = *(_DWORD *)(v47 + 8) & 0xFFF1FFFF | 0x60000;
    }
  }
  if ( (*(_BYTE *)(v47 + 39) & 0x80) == 0 && (v75 = *(_WORD **)(v47 + 104)) != 0 && (*v75 & 2) != 0 )
  {
    EtwActivityIdControlKernel(1, &v109);
    v77 = *(_DWORD **)(v47 + 104);
    v124 = v77[3];
    v125 = v77[4];
    v126 = v77[5];
    v127 = v77[6];
    v107 = &v124;
    EtwActivityIdControlKernel(2, &v107);
    v58 = IofCallDriver(v17, v47);
    v107 = v109;
    EtwActivityIdControlKernel(2, &v107);
  }
  else
  {
    v58 = IofCallDriver(v17, v47);
  }
  v67 = v101;
  if ( !v101 )
    ObDereferenceObjectDeferDelete((int)v12);
LABEL_164:
  if ( v58 != 259 )
  {
    if ( !v67 )
      *(_DWORD *)(v47 + 44) = 0;
    *(_DWORD *)(v47 + 40) = v104;
    v91 = KfRaiseIrql(1);
    IopCompleteRequest(v47 + 64, (int)&v109, &v107, &v122, &v107);
    KfLowerIrql(v91);
    if ( !v67 )
      goto LABEL_201;
    __dmb(0xBu);
    v92 = v12 + 17;
    do
      v93 = __ldrex(v92);
    while ( __strex(0, v92) );
    __dmb(0xBu);
    if ( v12[16] )
      KeSetEvent((int)(v12 + 19), 0, 0);
    v85 = ObfDereferenceObject((int)v12);
    v94 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v95 = *(_WORD *)(v94 + 0x134) + 1;
    *(_WORD *)(v94 + 308) = v95;
    if ( v95 || *(_DWORD *)(v94 + 100) == v94 + 100 || *(_WORD *)(v94 + 310) )
      goto LABEL_201;
    goto LABEL_200;
  }
  if ( !v67 )
  {
    v88 = KeWaitForSingleObject((unsigned int)v123, 0, v112, 0, 0);
    if ( v88 == 257 || v88 == 192 )
      IopCancelAlertedRequest(v123, v47);
    v58 = v120;
    v89 = v104;
    *v104 = v120;
    v89[1] = v121;
    v90 = v100;
    goto LABEL_202;
  }
  v78 = (v12[11] & 4) != 0;
  while ( 1 )
  {
    v79 = v78 ? (_BYTE)v112 : 0;
    v80 = KeWaitForSingleObject((unsigned int)(v12 + 23), 0, v79, (_DWORD *)1, 0);
    if ( v80 != 257 && v80 != 192 )
      break;
    if ( !v78 && (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C0) & 1) == 0 )
    {
      v81 = 0;
      v82 = KfRaiseIrql(1);
      if ( !v12[24] )
        v81 = *(unsigned __int8 *)(v47 + 36) == 1;
      KfLowerIrql(v82);
      if ( !v81 )
        continue;
    }
    IopCancelAlertedRequest(v12 + 23, v47);
    break;
  }
  v58 = v12[7];
  __dmb(0xBu);
  v83 = v12 + 17;
  do
    v84 = __ldrex(v83);
  while ( __strex(0, v83) );
  __dmb(0xBu);
  if ( v12[16] )
    KeSetEvent((int)(v12 + 19), 0, 0);
  v85 = ObfDereferenceObject((int)v12);
  v86 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v87 = (__int16)(*(_WORD *)(v86 + 0x134) + 1);
  *(_WORD *)(v86 + 308) = v87;
  if ( !v87 && *(_DWORD *)(v86 + 100) != v86 + 100 && !*(_WORD *)(v86 + 310) )
LABEL_200:
    KiCheckForKernelApcDelivery(v85);
LABEL_201:
  v90 = v100;
LABEL_202:
  if ( v90 )
    KeSetKernelStackSwapEnable(1);
  return v58;
}
