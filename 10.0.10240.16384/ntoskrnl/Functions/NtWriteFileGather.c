// NtWriteFileGather 
 
int __fastcall NtWriteFileGather(int a1, int a2, int a3, int a4, unsigned int a5, unsigned int a6, unsigned int a7, int *a8, int *a9)
{
  int *v9; // r8
  int v10; // r10
  int v11; // r6
  _DWORD *v12; // r5
  _DWORD *v13; // r3
  int v14; // r0
  int v15; // r4
  int v16; // r4
  int v17; // r0
  int v18; // lr
  int v19; // r2
  int v20; // r3
  unsigned int v21; // r0
  unsigned int v22; // r9
  int v23; // r3
  _DWORD *v24; // r2
  int v25; // r4
  unsigned int v26; // r6
  int v27; // r3
  unsigned int v28; // r2
  int *v29; // r4
  int v30; // r3
  unsigned int v31; // r10
  int *v32; // r3
  char v33; // r2
  int v34; // r0
  int v35; // r10
  int v36; // r3
  unsigned int v37; // r2
  unsigned int *v38; // r2
  unsigned int v39; // r1
  unsigned int v40; // r1
  __int16 v41; // r3
  int v42; // r10
  int v43; // r3
  int v44; // r2
  unsigned int *v45; // r2
  unsigned int v46; // r1
  int v47; // r0
  unsigned int v48; // r1
  int v49; // r3
  int v50; // r0
  int v51; // r4
  unsigned __int8 *v52; // r9
  int *v53; // r10
  unsigned int v54; // r0
  int v55; // r3
  int v57; // [sp+0h] [bp-A0h]
  int v58; // [sp+4h] [bp-9Ch]
  int v59; // [sp+8h] [bp-98h]
  int v60; // [sp+Ch] [bp-94h]
  int v61; // [sp+10h] [bp-90h] BYREF
  int v62; // [sp+14h] [bp-8Ch]
  int v63; // [sp+18h] [bp-88h]
  int v64; // [sp+1Ch] [bp-84h]
  int v65; // [sp+20h] [bp-80h]
  int v66; // [sp+24h] [bp-7Ch] BYREF
  int *v67; // [sp+28h] [bp-78h]
  int v68; // [sp+2Ch] [bp-74h]
  int v69; // [sp+30h] [bp-70h]
  int v70; // [sp+34h] [bp-6Ch]
  int v71; // [sp+38h] [bp-68h]
  int v72; // [sp+3Ch] [bp-64h]
  int v73; // [sp+40h] [bp-60h]
  int v74; // [sp+48h] [bp-58h] BYREF
  int v75; // [sp+4Ch] [bp-54h]
  int v76; // [sp+50h] [bp-50h] BYREF
  unsigned __int8 *v77; // [sp+54h] [bp-4Ch]
  unsigned int v78; // [sp+58h] [bp-48h]
  _DWORD *v79; // [sp+5Ch] [bp-44h] BYREF
  int v80; // [sp+60h] [bp-40h]
  int v81; // [sp+64h] [bp-3Ch]
  unsigned int v82; // [sp+68h] [bp-38h]
  int *v83; // [sp+6Ch] [bp-34h]
  int v84; // [sp+70h] [bp-30h]
  _DWORD *v85; // [sp+74h] [bp-2Ch]
  unsigned int v86; // [sp+78h] [bp-28h]
  int v87; // [sp+7Ch] [bp-24h]
  unsigned int v88; // [sp+80h] [bp-20h]
  int vars4; // [sp+A4h] [bp+4h]
  int varg_r0; // [sp+A8h] [bp+8h]
  int varg_r1; // [sp+ACh] [bp+Ch]
  int varg_r2; // [sp+B0h] [bp+10h]
  int varg_r3; // [sp+B4h] [bp+14h]

  varg_r0 = a1;
  v77 = (unsigned __int8 *)a4;
  varg_r3 = a4;
  v81 = a3;
  varg_r2 = a3;
  v62 = a2;
  varg_r1 = a2;
  v9 = 0;
  v83 = 0;
  v10 = 0;
  v69 = 0;
  v84 = 0;
  v73 = 0;
  v80 = 0;
  v64 = 0;
  v71 = 0;
  v63 = 0;
  v72 = 0;
  v86 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v82 = v86;
  v68 = *(char *)(v86 + 0x15A);
  LOBYTE(v65) = v68;
  v11 = ObReferenceObjectByHandle(a1, 0, IoFileObjectType, v68, &v79, &v74);
  v12 = v79;
  v85 = v79;
  if ( v11 >= 0 )
  {
    v13 = (_DWORD *)v79[31];
    if ( v13 )
    {
      if ( (*v13 & 4) != 0 )
      {
        v14 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        v66 = 0;
        v15 = PsReferencePrimaryToken(v14);
        SeQueryInformationToken(v15, 29, &v66);
        ObfDereferenceObject(v15);
        if ( v66 )
        {
          ObfDereferenceObject((int)v12);
          v11 = -1073739504;
        }
      }
    }
  }
  if ( v11 < 0 )
    return v11;
  v16 = v75;
  v76 = v75;
  v17 = IoGetRelatedDeviceObject(v12);
  v18 = v17;
  v70 = v17;
  v79 = (_DWORD *)v17;
  v19 = v12[11];
  if ( (v19 & 8) == 0
    || (v19 & 2) != 0
    || (*(_DWORD *)(v17 + 28) & 4) != 0
    || (v20 = *(_DWORD *)(v17 + 44), v20 != 8)
    && v20 != 6
    && v20 != 32
    && v20 != 3
    && v20 != 20
    && v20 != 9
    && v20 != 54
    && v20 != 83 )
  {
    ObfDereferenceObject((int)v12);
    return -1073741811;
  }
  v21 = a7;
  v22 = ((a7 & 0xFFF) != 0) + (a7 >> 12);
  if ( !v68 )
  {
    v29 = a8;
    if ( a8 )
    {
      v64 = *a8;
      v71 = v64;
      v63 = a8[1];
      v72 = v63;
    }
    v34 = v62;
    if ( a9 )
    {
      v73 = *a9;
      v80 = v73;
    }
    v67 = (int *)a6;
    v78 = a5;
    v33 = v75;
    goto LABEL_81;
  }
  if ( (v19 & 0x80) != 0 )
    v23 = 0;
  else
    v23 = 4;
  if ( ((v23 | 2) & v16) == 0 )
  {
    ObfDereferenceObject((int)v12);
    return -1073741790;
  }
  v87 = 0;
  v78 = a5;
  v24 = (_DWORD *)a5;
  if ( a5 >= MmUserProbeAddress )
    v24 = (_DWORD *)MmUserProbeAddress;
  *v24 = *v24;
  v25 = 8 * v22;
  v67 = (int *)a6;
  if ( 8 * v22 )
  {
    if ( (a6 & 7) != 0 )
      ExRaiseDatatypeMisalignment(a7);
    v26 = MmUserProbeAddress;
    if ( v25 + a6 <= MmUserProbeAddress && v25 + a6 >= a6 )
      goto LABEL_33;
    *(_BYTE *)MmUserProbeAddress = 0;
  }
  v26 = MmUserProbeAddress;
LABEL_33:
  if ( a7 )
  {
    if ( ViVerifierDriverAddedThunkListHead )
    {
      if ( (MmVerifierData & 0x10) != 0 )
        v27 = 40;
      else
        v27 = 32;
      v9 = (int *)ExAllocatePoolWithTagPriority(1, 8 * v22, 538996553, v27);
      if ( !v9 )
        RtlRaiseStatus(-1073741670);
    }
    else
    {
      v9 = (int *)ExAllocatePoolWithQuotaTag(1u, 8 * v22, 538996553);
    }
    v83 = v9;
    memmove((int)v9, (int)v67, 8 * v22);
    v67 = v9;
    v28 = 0;
    v88 = 0;
    while ( v28 < v22 )
    {
      if ( (v9[2 * v28] & 0xFFF) != 0 )
        RtlRaiseStatus(-1073741811);
      v88 = ++v28;
    }
    v26 = MmUserProbeAddress;
    v21 = a7;
    v18 = v70;
  }
  if ( v12[27] && v81 )
    RtlRaiseStatus(-1073741811);
  v29 = a8;
  if ( a8 )
  {
    if ( ((unsigned __int8)a8 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v21);
    v64 = *a8;
    v71 = v64;
    v63 = a8[1];
    v72 = v63;
    v26 = MmUserProbeAddress;
  }
  v30 = v12[11];
  v66 = v30;
  if ( (v30 & 8) != 0 )
  {
    v31 = *(unsigned __int16 *)(v18 + 172);
    if ( *(_WORD *)(v18 + 172) )
    {
      if ( ((v31 - 1) & v21) != 0 )
      {
        if ( !*(_WORD *)(v18 + 172) )
          __brkdiv0();
        if ( v21 % v31 )
          RtlRaiseStatus(-1073741811);
      }
      LOBYTE(v30) = v66;
    }
    if ( a8
      && (v64 != -1 || v63 != -1)
      && (v64 != -2 || v63 != -1 || (v30 & 2) == 0)
      && *(_WORD *)(v18 + 172)
      && ((v31 - 1) & v64) != 0 )
    {
      RtlRaiseStatus(-1073741811);
    }
  }
  v32 = a9;
  if ( a9 )
  {
    if ( (unsigned int)a9 >= v26 )
      v32 = (int *)v26;
    v73 = *v32;
    v80 = v73;
  }
  v10 = 0;
  v33 = v75;
  v34 = v62;
LABEL_81:
  if ( (v33 & 6) == 4 )
  {
    v64 = -1;
    v71 = -1;
    v63 = -1;
    v72 = -1;
  }
  if ( v34 )
  {
    v35 = ObReferenceObjectByHandle(v34, 2, ExEventObjectType, v68, &v76, 0);
    v69 = v76;
    v84 = v76;
    if ( v35 < 0 )
    {
LABEL_85:
      ObfDereferenceObject((int)v12);
      if ( v9 )
        ExFreePoolWithTag((unsigned int)v9);
      return v35;
    }
    v10 = v69;
    KeResetEvent(v69);
  }
  v36 = v12[11];
  if ( (v36 & 2) != 0 )
  {
    v37 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v37 + 308);
    __dmb(0xBu);
    v38 = v12 + 17;
    do
      v39 = __ldrex(v38);
    while ( __strex(1u, v38) );
    __dmb(0xBu);
    if ( v39 )
    {
      v40 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v41 = *(_WORD *)(v40 + 0x134) + 1;
      *(_WORD *)(v40 + 308) = v41;
      if ( !v41 && *(_DWORD *)(v40 + 100) != v40 + 100 && !*(_WORD *)(v40 + 310) )
        KiCheckForKernelApcDelivery(1);
      v35 = IopAcquireFileObjectLock(v12, v68, (v12[11] & 4) != 0, &v61);
      if ( (_BYTE)v61 )
      {
        if ( v69 )
          ObfDereferenceObject(v69);
        goto LABEL_85;
      }
    }
    else
    {
      ObfReferenceObject((int)v12);
    }
    v42 = 1;
    v66 = 1;
    LOBYTE(v61) = 1;
    v43 = v64;
    if ( !v29 && !v64 || (v44 = v63, v64 == -2) && v63 == -1 )
    {
      v43 = v12[14];
      v64 = v43;
      v71 = v43;
      v44 = v12[15];
      v63 = v44;
      v72 = v44;
    }
  }
  else
  {
    if ( !v29 && (v36 & 0x280) == 0 )
    {
      if ( v10 )
        ObfDereferenceObject(v10);
      goto LABEL_110;
    }
    v42 = 0;
    v66 = 0;
    LOBYTE(v61) = 0;
    v43 = v64;
    v44 = v63;
  }
  if ( v44 < 0 && (v44 != -1 || v43 != -1) )
  {
    if ( v69 )
      ObfDereferenceObject(v69);
    if ( v42 )
    {
      __dmb(0xBu);
      v45 = v12 + 17;
      do
        v46 = __ldrex(v45);
      while ( __strex(0, v45) );
      __dmb(0xBu);
      if ( v12[16] )
        KeSetEvent((int)(v12 + 19), 0, 0);
      v47 = ObfDereferenceObject((int)v12);
      v48 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v49 = (__int16)(*(_WORD *)(v48 + 0x134) + 1);
      *(_WORD *)(v48 + 308) = v49;
      if ( !v49 && *(_DWORD *)(v48 + 100) != v48 + 100 && !*(_WORD *)(v48 + 310) )
        KiCheckForKernelApcDelivery(v47);
    }
LABEL_110:
    ObfDereferenceObject((int)v12);
    if ( v9 )
      ExFreePoolWithTag((unsigned int)v9);
    return -1073741811;
  }
  if ( (v12[11] & 0x4000000) == 0 )
    KeResetEvent((int)(v12 + 23));
  v50 = pIoAllocateIrp(v70, *(char *)(v70 + 48), v42 == 0, vars4);
  v51 = v50;
  v74 = v50;
  if ( v50 )
  {
    *(_DWORD *)(v50 + 100) = v12;
    *(_DWORD *)(v50 + 80) = v86;
    *(_DWORD *)(v50 + 84) = 0;
    *(_BYTE *)(v50 + 32) = v68;
    *(_BYTE *)(v50 + 33) = 0;
    *(_BYTE *)(v50 + 36) = 0;
    *(_DWORD *)(v50 + 56) = 0;
    *(_DWORD *)(v50 + 44) = v69;
    *(_DWORD *)(v50 + 40) = v78;
    *(_DWORD *)(v50 + 48) = v81;
    *(_DWORD *)(v50 + 52) = v77;
    v52 = (unsigned __int8 *)(*(_DWORD *)(v50 + 96) - 40);
    v77 = v52;
    *(_DWORD *)v52 = 4;
    *((_DWORD *)v52 + 7) = v12;
    if ( (v12[11] & 0x10) != 0 )
      v52[2] = 4;
    *(_DWORD *)(v50 + 12) = 0;
    *(_DWORD *)(v50 + 4) = 0;
    *(_DWORD *)(v50 + 8) = 0;
    if ( a7 )
    {
      v53 = v67;
      v54 = IoAllocateMdl(*v67, a7, 0, 1, v50);
      v82 = v54;
      if ( !v54 )
        RtlRaiseStatus(-1073741670);
      v76 = *v52;
      MmProbeAndLockSelectedPages(v54, (int)v53, v68, 0, v57, v58, v59, v60, v61, v62, v63, v64, v65);
      if ( (MmTrackLockedPages & 1) != 0 )
        MmUpdateMdlTracker(v82, *(_DWORD *)(*(_DWORD *)(v70 + 8) + 4 * v76 + 56), v70, *(_DWORD *)(v70 + 8) + 4 * v76);
      *(_DWORD *)(v51 + 60) = *v67;
    }
    if ( v9 )
      ExFreePoolWithTag((unsigned int)v9);
    if ( (v12[11] & 8) != 0 )
      v55 = *(_DWORD *)(v51 + 8) | 0xA01;
    else
      v55 = *(_DWORD *)(v51 + 8) | 0xA00;
    *(_DWORD *)(v51 + 8) = v55;
    *((_DWORD *)v52 + 2) = a7;
    *((_DWORD *)v52 + 3) = v73;
    *((_DWORD *)v52 + 4) = v64;
    *((_DWORD *)v52 + 5) = v63;
    v11 = IopSynchronousServiceTail(v70, v51, v12, 1, v68, v66, 1);
  }
  else
  {
    IopAllocateIrpCleanup(v12, v69);
    if ( v9 )
      ExFreePoolWithTag((unsigned int)v9);
    v11 = -1073741670;
  }
  return v11;
}
