// NtWriteFile 
 
int __fastcall NtWriteFile(int a1, int a2, int a3, int a4, int *a5, unsigned int a6, unsigned int a7, int *a8, int *a9)
{
  int v9; // r10
  int v10; // r9
  _DWORD *v11; // r5
  _DWORD *v12; // r3
  int v13; // r0
  int v14; // r4
  int v15; // r0
  int v16; // r6
  int *v17; // r2
  unsigned int v18; // r2
  unsigned int v19; // r6
  int *v20; // r4
  int v21; // r3
  int v22; // r0
  int v23; // r10
  int v24; // r1
  int *v25; // r3
  int v26; // r1
  int v27; // lr
  int v28; // r0
  int v29; // r3
  int v30; // r3
  unsigned int *v31; // r1
  unsigned int v32; // r2
  unsigned int v33; // r1
  __int16 v34; // r3
  int v35; // r10
  int v36; // r10
  unsigned int *v37; // r1
  unsigned int v38; // r2
  int v39; // r0
  unsigned int v40; // r1
  __int16 v41; // r3
  int v42; // r4
  int v43; // r3
  int v44; // r2
  int v45; // r3
  unsigned __int64 *v46; // r0
  unsigned __int64 v47; // r2
  unsigned int *v48; // r1
  unsigned int v49; // r0
  int v50; // r4
  unsigned __int64 *v51; // r0
  unsigned __int64 v52; // r2
  unsigned __int64 *v53; // r2
  unsigned __int64 v54; // r0
  int *v55; // r3
  int v56; // r4
  unsigned int *v57; // r2
  unsigned int v58; // r1
  int v59; // r0
  unsigned int v60; // r1
  __int16 v61; // r3
  unsigned int *v62; // r2
  unsigned int v63; // r1
  int v64; // r0
  unsigned int v65; // r1
  __int16 v66; // r3
  int v67; // r0
  _DWORD *v68; // r4
  int v69; // r1
  int v70; // lr
  unsigned __int8 *v71; // r6
  int v72; // r0
  int v73; // r3
  int v74; // r1
  int v75; // r0
  int v76; // r3
  unsigned int v77; // r0
  int v78; // r3
  int v80; // [sp+10h] [bp-98h] BYREF
  int v81; // [sp+18h] [bp-90h] BYREF
  int v82; // [sp+1Ch] [bp-8Ch]
  char v83; // [sp+20h] [bp-88h]
  unsigned int v84; // [sp+24h] [bp-84h]
  int v85; // [sp+28h] [bp-80h]
  int v86; // [sp+2Ch] [bp-7Ch]
  int v87; // [sp+30h] [bp-78h]
  int v88; // [sp+38h] [bp-70h] BYREF
  int v89; // [sp+3Ch] [bp-6Ch]
  int v90; // [sp+40h] [bp-68h] BYREF
  int v91; // [sp+44h] [bp-64h]
  int v92; // [sp+48h] [bp-60h]
  int v93; // [sp+4Ch] [bp-5Ch]
  int v94; // [sp+50h] [bp-58h]
  int v95; // [sp+54h] [bp-54h] BYREF
  _DWORD *v96; // [sp+58h] [bp-50h] BYREF
  int *v97; // [sp+5Ch] [bp-4Ch]
  int v98; // [sp+60h] [bp-48h]
  unsigned __int8 *v99; // [sp+64h] [bp-44h]
  int v100; // [sp+68h] [bp-40h]
  int v101; // [sp+6Ch] [bp-3Ch]
  int v102; // [sp+70h] [bp-38h]
  int v103; // [sp+74h] [bp-34h]
  int v104; // [sp+78h] [bp-30h]
  _BYTE _80[44]; // [sp+80h] [bp-28h] BYREF
  int vars4; // [sp+ACh] [bp+4h]
  int varg_r0; // [sp+B0h] [bp+8h]
  int varg_r1; // [sp+B4h] [bp+Ch]
  int varg_r2; // [sp+B8h] [bp+10h]
  int varg_r3; // [sp+BCh] [bp+14h]

  varg_r0 = a1;
  v99 = (unsigned __int8 *)a4;
  varg_r3 = a4;
  v103 = a3;
  varg_r2 = a3;
  v102 = a2;
  varg_r1 = a2;
  v91 = 0;
  v100 = 0;
  v94 = 0;
  v98 = 0;
  v81 = 0;
  v82 = 0;
  v101 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v90 = v101;
  v9 = *(char *)(v101 + 0x15A);
  v93 = v9;
  v83 = v9;
  v10 = ObReferenceFileObjectForWrite(a1, v9, &v96, _80);
  v11 = v96;
  if ( v10 < 0 )
    return v10;
  v12 = (_DWORD *)v96[31];
  if ( v12 )
  {
    if ( (*v12 & 4) != 0 )
    {
      v13 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      v95 = 0;
      v14 = PsReferencePrimaryToken(v13);
      SeQueryInformationToken(v14, 29, &v95);
      ObfDereferenceObject(v14);
      if ( v95 )
      {
        ObfDereferenceObject((int)v11);
        return -1073739504;
      }
    }
  }
  v15 = IoGetRelatedDeviceObject(v11);
  v16 = v15;
  v86 = v15;
  v95 = v15;
  if ( v9 )
  {
    v104 = 0;
    v97 = a5;
    v17 = a5;
    if ( (unsigned int)a5 >= MmUserProbeAddress )
      v17 = (int *)MmUserProbeAddress;
    *v17 = *v17;
    v84 = a7;
    v18 = a6;
    v19 = MmUserProbeAddress;
    v92 = a6;
    if ( a7 && (a6 + a7 > MmUserProbeAddress || a6 + a7 < a6) )
    {
      *(_BYTE *)MmUserProbeAddress = 0;
      v19 = MmUserProbeAddress;
    }
    if ( v11[27] && v103 )
      goto LABEL_15;
    v20 = a8;
    if ( a8 )
    {
      if ( ((unsigned __int8)a8 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v15);
      v21 = *a8;
      v81 = *a8;
      v22 = a8[1];
      v82 = v22;
      v19 = MmUserProbeAddress;
    }
    else
    {
      v22 = v82;
      v21 = v81;
    }
    v88 = v21;
    v85 = v22;
    v23 = v11[11];
    if ( (v23 & 8) != 0 )
    {
      if ( (v24 = *(unsigned __int16 *)(v86 + 172), (v87 = v24) != 0) && ((v24 - 1) & a7) != 0
        || (a6 & *(_DWORD *)(v86 + 92)) != 0 )
      {
        if ( v24 )
        {
          if ( !v87 )
            __brkdiv0();
          if ( a7 % v87 )
            goto LABEL_15;
          v18 = a6;
          v22 = v85;
          v24 = v87;
        }
        if ( (v18 & *(_DWORD *)(v86 + 92)) != 0 )
          goto LABEL_15;
      }
      if ( a8 && (v88 != -1 || v22 != -1) && (v88 != -2 || v22 != -1 || (v23 & 2) == 0) && v24 && ((v24 - 1) & v88) != 0 )
      {
LABEL_15:
        ObfDereferenceObject((int)v11);
        v10 = -1073741811;
        v85 = -1073741811;
        v88 = v81;
        return v10;
      }
    }
    v25 = a9;
    if ( a9 )
    {
      if ( (unsigned int)a9 >= v19 )
        v25 = (int *)v19;
      v94 = *v25;
      v98 = v94;
      v26 = v82;
      v88 = v81;
    }
    else
    {
      v26 = v85;
    }
    v16 = v86;
  }
  else
  {
    v20 = a8;
    if ( a8 )
    {
      v27 = *a8;
      v81 = *a8;
      v26 = a8[1];
      v82 = v26;
    }
    else
    {
      v26 = v82;
      v27 = v81;
    }
    v88 = v27;
    if ( a9 )
    {
      v94 = *a9;
      v98 = v94;
    }
    v84 = a7;
    v92 = a6;
    v97 = a5;
  }
  if ( (_80[4] & 6) == 4 )
  {
    v28 = -1;
    v81 = -1;
    v26 = -1;
    v82 = -1;
  }
  else
  {
    v28 = v88;
  }
  if ( v102 )
  {
    v87 = ObReferenceObjectByHandle(v102, 2, ExEventObjectType, v93, &v90);
    v91 = v90;
    v100 = v90;
    if ( v87 < 0 )
    {
      ObfDereferenceObject((int)v11);
      return v87;
    }
    KeResetEvent(v90);
    v26 = v82;
    v28 = v81;
  }
  v90 = *(_DWORD *)(*(_DWORD *)(v16 + 8) + 40);
  v29 = v11[11];
  if ( (v29 & 2) != 0 )
  {
    v30 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v30 & 0xFFFFFFC0) + 0x134);
    __dmb(0xBu);
    v31 = v11 + 17;
    do
      v32 = __ldrex(v31);
    while ( __strex(1u, v31) );
    __dmb(0xBu);
    if ( v32 )
    {
      v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v34 = *(_WORD *)(v33 + 0x134) + 1;
      *(_WORD *)(v33 + 308) = v34;
      if ( !v34 && *(_DWORD *)(v33 + 100) != v33 + 100 && !*(_WORD *)(v33 + 310) )
        KiCheckForKernelApcDelivery(1);
      v35 = IopAcquireFileObjectLock(v11, v93, (v11[11] & 4) != 0, &v80);
      if ( (_BYTE)v80 )
      {
        if ( v91 )
          ObfDereferenceObject(v91);
        ObfDereferenceObject((int)v11);
        return v35;
      }
    }
    else
    {
      ObfReferenceObject((int)v11);
    }
    v36 = 1;
    LOBYTE(v80) = 1;
    v28 = v81;
    if ( !v20 && !v81 || (v26 = v82, v81 == -2) && v82 == -1 )
    {
      v28 = v11[14];
      v81 = v28;
      v26 = v11[15];
      v82 = v26;
    }
    if ( v11[6] )
    {
      v87 = *(_DWORD *)(v90 + 12);
      if ( v26 < 0 && (v26 != -1 || v28 != -1) )
      {
        if ( v91 )
          ObfDereferenceObject(v91);
        __dmb(0xBu);
        v37 = v11 + 17;
        do
          v38 = __ldrex(v37);
        while ( __strex(0, v37) );
        __dmb(0xBu);
        if ( v11[16] )
          KeSetEvent((int)(v11 + 19), 0, 0);
        v39 = ObfDereferenceObject((int)v11);
        v40 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v41 = *(_WORD *)(v40 + 0x134) + 1;
        *(_WORD *)(v40 + 308) = v41;
        if ( !v41 && *(_DWORD *)(v40 + 100) != v40 + 100 && !*(_WORD *)(v40 + 310) )
          KiCheckForKernelApcDelivery(v39);
LABEL_130:
        ObfDereferenceObject((int)v11);
        return -1073741811;
      }
      if ( (MmVerifierData & 0x10) != 0 )
        v42 = VfFastIoSnapState(v28);
      else
        v42 = 0;
      v43 = ((int (__fastcall *)(_DWORD *, int *, unsigned int, int, int, int, int *, int, int))v87)(
              v11,
              &v81,
              v84,
              1,
              v94,
              v92,
              &v88,
              v16,
              v80);
      v90 = v43;
      if ( v42 )
      {
        VfFastIoCheckState(v42, v87);
        v43 = v90;
      }
      if ( v43 )
      {
        v44 = v88;
        if ( !v88 )
        {
          v45 = IoCountOperations;
          if ( IoCountOperations == 1 )
          {
            v46 = (unsigned __int64 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150) + 440);
            do
              v47 = __ldrexd(v46);
            while ( __strexd(v47 + 1, v46) );
            v48 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3032);
            do
              v49 = __ldrex(v48);
            while ( __strex(v49 + 1, v48) );
            v45 = IoCountOperations;
            v44 = v88;
          }
          v50 = v89;
          if ( v45 == 1 )
          {
            v51 = (unsigned __int64 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150) + 464);
            do
              v52 = __ldrexd(v51);
            while ( __strexd(v52 + (unsigned int)v50, v51) );
            v53 = (unsigned __int64 *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3048);
            do
              v54 = __ldrexd(v53);
            while ( __strexd(v54 + (unsigned int)v50, v53) );
            v50 = v89;
            v44 = v88;
          }
          v55 = v97;
          *v97 = v44;
          v55[1] = v50;
          v56 = v91;
          if ( v102 )
          {
            if ( (v11[11] & 0x8000000) == 0 )
              KeSetEvent(v91, 0, 0);
            ObfDereferenceObject(v56);
          }
          __dmb(0xBu);
          v57 = v11 + 17;
          do
            v58 = __ldrex(v57);
          while ( __strex(0, v57) );
          __dmb(0xBu);
          if ( v11[16] )
            KeSetEvent((int)(v11 + 19), 0, 0);
          v59 = ObfDereferenceObject((int)v11);
          v60 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v61 = *(_WORD *)(v60 + 0x134) + 1;
          *(_WORD *)(v60 + 308) = v61;
          if ( !v61 && *(_DWORD *)(v60 + 100) != v60 + 100 && !*(_WORD *)(v60 + 310) )
            KiCheckForKernelApcDelivery(v59);
          ObfDereferenceObject((int)v11);
          return v88;
        }
      }
      v26 = v82;
      v28 = v81;
    }
  }
  else
  {
    if ( !v20 && (v29 & 0x280) == 0 )
    {
      if ( v91 )
        ObfDereferenceObject(v91);
      goto LABEL_130;
    }
    v36 = 0;
    LOBYTE(v80) = 0;
  }
  if ( v26 < 0 && (v26 != -1 || v28 != -1) )
  {
    if ( v91 )
      ObfDereferenceObject(v91);
    if ( v36 )
    {
      __dmb(0xBu);
      v62 = v11 + 17;
      do
        v63 = __ldrex(v62);
      while ( __strex(0, v62) );
      __dmb(0xBu);
      if ( v11[16] )
        KeSetEvent((int)(v11 + 19), 0, 0);
      v64 = ObfDereferenceObject((int)v11);
      v65 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v66 = *(_WORD *)(v65 + 0x134) + 1;
      *(_WORD *)(v65 + 308) = v66;
      if ( !v66 && *(_DWORD *)(v65 + 100) != v65 + 100 && !*(_WORD *)(v65 + 310) )
        KiCheckForKernelApcDelivery(v64);
    }
    goto LABEL_130;
  }
  if ( (v11[11] & 0x4000000) == 0 )
    KeResetEvent((int)(v11 + 23));
  v67 = pIoAllocateIrp(v16, *(char *)(v16 + 48), v36 == 0, vars4);
  v68 = (_DWORD *)v67;
  v87 = v67;
  v69 = v91;
  if ( v67 )
  {
    *(_DWORD *)(v67 + 100) = v11;
    *(_DWORD *)(v67 + 80) = v101;
    *(_DWORD *)(v67 + 84) = 0;
    v70 = v93;
    *(_WORD *)(v67 + 32) = (unsigned __int8)v93;
    *(_BYTE *)(v67 + 36) = 0;
    *(_DWORD *)(v67 + 56) = 0;
    *(_DWORD *)(v67 + 44) = v69;
    *(_DWORD *)(v67 + 40) = v97;
    *(_DWORD *)(v67 + 48) = v103;
    *(_DWORD *)(v67 + 52) = v99;
    v71 = (unsigned __int8 *)(*(_DWORD *)(v67 + 96) - 40);
    v99 = v71;
    *(_DWORD *)v71 = 4;
    *((_DWORD *)v71 + 7) = v11;
    if ( (v11[11] & 0x10) != 0 )
      v71[2] = 4;
    *(_DWORD *)(v67 + 12) = 0;
    *(_DWORD *)(v67 + 4) = 0;
    v72 = v86;
    v73 = *(_DWORD *)(v86 + 28);
    v74 = v84;
    if ( (v73 & 4) != 0 )
    {
      if ( v84 )
      {
        if ( ViVerifierDriverAddedThunkListHead )
        {
          if ( (MmVerifierData & 0x10) != 0 )
            v76 = 40;
          else
            v76 = 32;
          v75 = ExAllocatePoolWithTagPriority(516, v84, 538996553, v76);
          if ( !v75 )
            RtlRaiseStatus(-1073741670);
        }
        else
        {
          v75 = ExAllocatePoolWithQuotaTag(0x204u, v84, 538996553);
        }
        v68[3] = v75;
        memmove(v75, v92, v84);
        v72 = v86;
        v74 = v84;
        v70 = v93;
        v68[2] = 48;
      }
      else
      {
        v68[2] = 16;
      }
    }
    else
    {
      v68[2] = 0;
      if ( (v73 & 0x10) != 0 )
      {
        if ( v74 )
        {
          v77 = IoAllocateMdl(v92, v74, 0, 1, (int)v68);
          v101 = v77;
          if ( !v77 )
            RtlRaiseStatus(-1073741670);
          v90 = *v71;
          MmProbeAndLockPages(v77);
          if ( (MmTrackLockedPages & 1) != 0 )
            MmUpdateMdlTracker(
              v101,
              *(_DWORD *)(*(_DWORD *)(v86 + 8) + 4 * v90 + 56),
              v86,
              *(_DWORD *)(v86 + 8) + 4 * v90);
          v72 = v86;
          v74 = v84;
          v70 = v93;
        }
      }
      else
      {
        v68[15] = v92;
      }
    }
    if ( (v11[11] & 8) != 0 )
      v78 = v68[2] | 0xA01;
    else
      v78 = v68[2] | 0xA00;
    v68[2] = v78;
    *((_DWORD *)v71 + 2) = v74;
    *((_DWORD *)v71 + 3) = v94;
    *((_DWORD *)v71 + 4) = v81;
    *((_DWORD *)v71 + 5) = v82;
    v10 = IopSynchronousServiceTail(v72, v68, v11, 1, v70, v36, 1);
  }
  else
  {
    IopAllocateIrpCleanup(v11, v91);
    v10 = -1073741670;
  }
  return v10;
}
