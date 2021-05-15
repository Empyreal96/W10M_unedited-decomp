// NtReadFile 
 
int __fastcall NtReadFile(int a1, int a2, int a3, int a4, int *a5, int a6, unsigned int a7, int *a8, int *a9)
{
  int v9; // r10
  int v10; // r9
  _DWORD *v11; // r5
  _DWORD *v12; // r3
  int v13; // r0
  int v14; // r4
  int v15; // r6
  int *v16; // r2
  int v17; // r0
  int *v18; // r4
  int v19; // r9
  unsigned int v20; // r10
  int v21; // r2
  int *v22; // r3
  int v23; // r0
  int v24; // r3
  int v25; // r10
  int v26; // r2
  int v27; // r10
  int v28; // r3
  int v29; // r3
  unsigned int *v30; // r1
  unsigned int v31; // r2
  signed int v32; // r0
  unsigned int v33; // r1
  __int16 v34; // r3
  int (__fastcall *v35)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // r10
  unsigned int *v36; // r1
  unsigned int v37; // r2
  int v38; // r0
  unsigned int v39; // r1
  __int16 v40; // r3
  int v41; // r4
  int v42; // r10
  int v43; // r2
  int v44; // r3
  unsigned __int64 *v45; // r0
  unsigned __int64 v46; // r2
  unsigned int *v47; // r1
  unsigned int v48; // r0
  int v49; // r4
  unsigned __int64 *v50; // r0
  unsigned __int64 v51; // r2
  unsigned __int64 *v52; // r2
  unsigned __int64 v53; // r0
  int *v54; // r3
  int v55; // r4
  unsigned int *v56; // r2
  unsigned int v57; // r1
  int v58; // r0
  unsigned int v59; // r1
  __int16 v60; // r3
  int v61; // r10
  unsigned int *v62; // r2
  unsigned int v63; // r1
  int v64; // r0
  unsigned int v65; // r1
  __int16 v66; // r3
  int v67; // r0
  _DWORD *v68; // r4
  int v69; // r1
  _DWORD *v70; // r6
  int v71; // r0
  int v72; // r3
  int v73; // lr
  int v74; // r0
  int v75; // r3
  int v76; // r0
  int v77; // r3
  _BYTE v79[4]; // [sp+10h] [bp-80h] BYREF
  int v80; // [sp+14h] [bp-7Ch]
  int v81; // [sp+18h] [bp-78h] BYREF
  int v82; // [sp+1Ch] [bp-74h]
  int v83; // [sp+20h] [bp-70h]
  unsigned int v84; // [sp+24h] [bp-6Ch]
  int (__fastcall *v85)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // [sp+28h] [bp-68h]
  int v86; // [sp+30h] [bp-60h] BYREF
  int v87; // [sp+34h] [bp-5Ch]
  int v88; // [sp+38h] [bp-58h]
  int v89; // [sp+3Ch] [bp-54h]
  int v90; // [sp+40h] [bp-50h]
  int (__fastcall *v91)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // [sp+44h] [bp-4Ch] BYREF
  _DWORD *v92; // [sp+48h] [bp-48h] BYREF
  int v93; // [sp+4Ch] [bp-44h] BYREF
  int v94; // [sp+50h] [bp-40h]
  int (__fastcall *v95)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // [sp+54h] [bp-3Ch]
  int v96; // [sp+58h] [bp-38h]
  int *v97; // [sp+5Ch] [bp-34h]
  _DWORD *v98; // [sp+60h] [bp-30h]
  int v99; // [sp+64h] [bp-2Ch]
  int v100; // [sp+68h] [bp-28h]
  unsigned int v101; // [sp+6Ch] [bp-24h]
  int vars4; // [sp+94h] [bp+4h]
  int varg_r0; // [sp+98h] [bp+8h]
  int varg_r1; // [sp+9Ch] [bp+Ch]
  int varg_r2; // [sp+A0h] [bp+10h]
  int varg_r3; // [sp+A4h] [bp+14h]

  varg_r0 = a1;
  v98 = (_DWORD *)a4;
  varg_r3 = a4;
  v99 = a3;
  varg_r2 = a3;
  v83 = a2;
  varg_r1 = a2;
  v85 = 0;
  v95 = 0;
  v88 = 0;
  v96 = 0;
  v81 = 0;
  v82 = 0;
  v101 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v91 = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v101;
  v9 = *(char *)(v101 + 0x15A);
  v80 = v9;
  v79[1] = v9;
  v10 = ObReferenceObjectByHandle(a1, 1, IoFileObjectType, v9, &v92);
  v11 = v92;
  if ( v10 < 0 )
    return v10;
  v12 = (_DWORD *)v92[31];
  if ( v12 )
  {
    if ( (*v12 & 4) != 0 )
    {
      v13 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      v93 = 0;
      v14 = PsReferencePrimaryToken(v13);
      SeQueryInformationToken(v14, 29, &v93);
      ObfDereferenceObject(v14);
      if ( v93 )
      {
        ObfDereferenceObject((int)v11);
        return -1073739504;
      }
    }
  }
  v15 = IoGetRelatedDeviceObject(v11);
  v94 = v15;
  v93 = v15;
  if ( v9 )
  {
    v100 = 0;
    v97 = a5;
    v16 = a5;
    if ( (unsigned int)a5 >= MmUserProbeAddress )
      v16 = (int *)MmUserProbeAddress;
    *v16 = *v16;
    v84 = a7;
    v89 = a6;
    v17 = ProbeForWrite(a6, a7, 1);
    if ( v11[27] && v99 )
      goto LABEL_11;
    v18 = a8;
    if ( a8 )
    {
      if ( ((unsigned __int8)a8 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v17);
      v19 = *a8;
      v81 = *a8;
      v86 = a8[1];
      v82 = v86;
    }
    else
    {
      v86 = v82;
      v19 = v81;
    }
    if ( (v11[11] & 8) == 0 )
    {
LABEL_31:
      v22 = a9;
      if ( a9 )
      {
        if ( (unsigned int)a9 >= MmUserProbeAddress )
          v22 = (int *)MmUserProbeAddress;
        v88 = *v22;
        v96 = v88;
        v86 = v82;
      }
      v9 = v80;
      v23 = v83;
      goto LABEL_42;
    }
    v20 = *(unsigned __int16 *)(v15 + 172);
    if ( *(_WORD *)(v15 + 172) && ((v20 - 1) & a7) != 0 )
    {
      v21 = a6;
    }
    else
    {
      v21 = a6;
      if ( (*(_DWORD *)(v15 + 92) & a6) == 0 )
      {
LABEL_28:
        if ( a8 && *(_WORD *)(v15 + 172) && ((v20 - 1) & v19) != 0 )
          goto LABEL_11;
        goto LABEL_31;
      }
    }
    if ( *(_WORD *)(v15 + 172) )
    {
      if ( a7 % v20 )
      {
LABEL_11:
        ObfDereferenceObject((int)v11);
        v10 = -1073741811;
        v90 = -1073741811;
        v86 = v82;
        return v10;
      }
      v21 = a6;
    }
    if ( (*(_DWORD *)(v15 + 92) & v21) != 0 )
      goto LABEL_11;
    goto LABEL_28;
  }
  v18 = a8;
  if ( a8 )
  {
    v81 = *a8;
    v24 = a8[1];
    v82 = v24;
  }
  else
  {
    v24 = v82;
  }
  v86 = v24;
  v23 = v83;
  if ( a9 )
  {
    v88 = *a9;
    v96 = v88;
  }
  v84 = a7;
  v89 = a6;
  v97 = a5;
LABEL_42:
  if ( v23 )
  {
    v25 = ObReferenceObjectByHandle(v23, 2, ExEventObjectType, v9, &v91);
    v85 = v91;
    v95 = v91;
    if ( v25 < 0 )
    {
      ObfDereferenceObject((int)v11);
      return v25;
    }
    KeResetEvent((int)v91);
    v26 = v82;
  }
  else
  {
    v26 = v86;
  }
  v27 = *(_DWORD *)(*(_DWORD *)(v15 + 8) + 40);
  v28 = v11[11];
  if ( (v28 & 2) != 0 )
  {
    v29 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v29 & 0xFFFFFFC0) + 0x134);
    __dmb(0xBu);
    v30 = v11 + 17;
    do
      v31 = __ldrex(v30);
    while ( __strex(1u, v30) );
    __dmb(0xBu);
    if ( v31 )
    {
      v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v34 = *(_WORD *)(v33 + 0x134) + 1;
      *(_WORD *)(v33 + 308) = v34;
      if ( !v34 && *(_DWORD *)(v33 + 100) != v33 + 100 && !*(_WORD *)(v33 + 310) )
        KiCheckForKernelApcDelivery(1);
      v32 = IopAcquireFileObjectLock(v11, v80, (v11[11] & 4) != 0, v79);
      v91 = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v32;
      if ( v79[0] )
      {
        if ( v85 )
          ObfDereferenceObject((int)v85);
        ObfDereferenceObject((int)v11);
        return (int)v91;
      }
    }
    else
    {
      v32 = ObfReferenceObject((int)v11);
    }
    if ( !v18 || (v26 = v82, v81 == -2) && v82 == -1 )
    {
      v81 = v11[14];
      v26 = v11[15];
      v82 = v26;
    }
    if ( v11[6] )
    {
      v35 = *(int (__fastcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(v27 + 8);
      v91 = v35;
      if ( v26 < 0 )
      {
        if ( v85 )
          ObfDereferenceObject((int)v85);
        __dmb(0xBu);
        v36 = v11 + 17;
        do
          v37 = __ldrex(v36);
        while ( __strex(0, v36) );
        __dmb(0xBu);
        if ( v11[16] )
          KeSetEvent((int)(v11 + 19), 0, 0);
        v38 = ObfDereferenceObject((int)v11);
        v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v40 = *(_WORD *)(v39 + 0x134) + 1;
        *(_WORD *)(v39 + 308) = v40;
        if ( !v40 && *(_DWORD *)(v39 + 100) != v39 + 100 && !*(_WORD *)(v39 + 310) )
          KiCheckForKernelApcDelivery(v38);
LABEL_117:
        ObfDereferenceObject((int)v11);
        return -1073741811;
      }
      if ( (MmVerifierData & 0x10) != 0 )
        v41 = VfFastIoSnapState(v32);
      else
        v41 = 0;
      v42 = v35(v11, &v81, v84, 1, v88, v89, &v86, v15);
      if ( v41 )
        VfFastIoCheckState(v41, v91);
      if ( v42 )
      {
        v43 = v86;
        if ( !v86 || v86 == -2147483643 || v86 == -1073741807 )
        {
          v44 = IoCountOperations;
          if ( IoCountOperations == 1 )
          {
            v45 = (unsigned __int64 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150) + 432);
            do
              v46 = __ldrexd(v45);
            while ( __strexd(v46 + 1, v45) );
            v47 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3028);
            do
              v48 = __ldrex(v47);
            while ( __strex(v48 + 1, v47) );
            v43 = v86;
            v44 = IoCountOperations;
          }
          v49 = v87;
          if ( v44 == 1 )
          {
            v50 = (unsigned __int64 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150) + 456);
            do
              v51 = __ldrexd(v50);
            while ( __strexd(v51 + (unsigned int)v49, v50) );
            v52 = (unsigned __int64 *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3040);
            do
              v53 = __ldrexd(v52);
            while ( __strexd(v53 + (unsigned int)v49, v52) );
            v49 = v87;
            v43 = v86;
          }
          v54 = v97;
          *v97 = v43;
          v54[1] = v49;
          v55 = (int)v85;
          if ( v83 )
          {
            if ( (v11[11] & 0x8000000) == 0 )
              KeSetEvent((int)v85, 0, 0);
            ObfDereferenceObject(v55);
          }
          __dmb(0xBu);
          v56 = v11 + 17;
          do
            v57 = __ldrex(v56);
          while ( __strex(0, v56) );
          __dmb(0xBu);
          if ( v11[16] )
            KeSetEvent((int)(v11 + 19), 0, 0);
          v58 = ObfDereferenceObject((int)v11);
          v59 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v60 = *(_WORD *)(v59 + 0x134) + 1;
          *(_WORD *)(v59 + 308) = v60;
          if ( !v60 && *(_DWORD *)(v59 + 100) != v59 + 100 && !*(_WORD *)(v59 + 310) )
            KiCheckForKernelApcDelivery(v58);
          ObfDereferenceObject((int)v11);
          return v86;
        }
      }
      v26 = v82;
    }
    v61 = 1;
  }
  else
  {
    if ( !v18 && (v28 & 0x280) == 0 )
    {
      if ( v85 )
        ObfDereferenceObject((int)v85);
      goto LABEL_117;
    }
    v61 = 0;
  }
  v79[0] = v61;
  if ( v26 < 0 )
  {
    if ( v85 )
      ObfDereferenceObject((int)v85);
    if ( v61 )
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
    goto LABEL_117;
  }
  if ( (v11[11] & 0x4000000) == 0 )
    KeResetEvent((int)(v11 + 23));
  v67 = pIoAllocateIrp(v15, *(char *)(v15 + 48), v61 == 0, vars4);
  v68 = (_DWORD *)v67;
  v83 = v67;
  if ( v67 )
  {
    *(_DWORD *)(v67 + 100) = v11;
    *(_DWORD *)(v67 + 80) = v101;
    *(_DWORD *)(v67 + 84) = 0;
    v69 = v80;
    *(_WORD *)(v67 + 32) = (unsigned __int8)v80;
    *(_BYTE *)(v67 + 36) = 0;
    *(_DWORD *)(v67 + 56) = 0;
    *(_DWORD *)(v67 + 44) = v85;
    *(_DWORD *)(v67 + 40) = v97;
    *(_DWORD *)(v67 + 48) = v99;
    *(_DWORD *)(v67 + 52) = v98;
    v70 = (_DWORD *)(*(_DWORD *)(v67 + 96) - 40);
    v98 = v70;
    *v70 = 3;
    v70[7] = v11;
    *(_DWORD *)(v67 + 12) = 0;
    *(_DWORD *)(v67 + 4) = 0;
    v71 = v94;
    v72 = *(_DWORD *)(v94 + 28);
    v73 = v84;
    if ( (v72 & 4) != 0 )
    {
      if ( v84 )
      {
        if ( ViVerifierDriverAddedThunkListHead )
        {
          if ( (MmVerifierData & 0x10) != 0 )
            v75 = 40;
          else
            v75 = 32;
          v74 = ExAllocatePoolWithTagPriority(516, v84, 538996553, v75);
          if ( !v74 )
            RtlRaiseStatus(-1073741670);
        }
        else
        {
          v74 = ExAllocatePoolWithQuotaTag(0x204u, v84, 538996553);
        }
        v68[3] = v74;
        v71 = v94;
        v69 = v80;
        v73 = v84;
        v68[15] = v89;
        v68[2] = 112;
      }
      else
      {
        v68[2] = 80;
      }
    }
    else
    {
      v68[2] = 0;
      if ( (v72 & 0x10) != 0 )
      {
        if ( v73 )
        {
          v76 = IoAllocateMdl(v89, v73, 0, 1, (int)v68);
          if ( !v76 )
            RtlRaiseStatus(-1073741670);
          MmProbeAndLockPages(v76);
          v71 = v94;
          v69 = v80;
          v73 = v84;
        }
      }
      else
      {
        v68[15] = v89;
      }
    }
    if ( (v11[11] & 8) != 0 )
      v77 = v68[2] | 0x901;
    else
      v77 = v68[2] | 0x900;
    v68[2] = v77;
    v70[2] = v73;
    v70[3] = v88;
    v70[4] = v81;
    v70[5] = v82;
    v10 = IopSynchronousServiceTail(v71, v68, v11, 1, v69, v61, 0);
  }
  else
  {
    IopAllocateIrpCleanup(v11, v85);
    v10 = -1073741670;
  }
  return v10;
}
