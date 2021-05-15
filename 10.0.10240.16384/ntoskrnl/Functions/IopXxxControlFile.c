// IopXxxControlFile 
 
int __fastcall IopXxxControlFile(int a1, int a2, int a3, int a4, unsigned int a5, int a6, unsigned int a7, unsigned int a8, unsigned int a9, int a10, char a11)
{
  int v13; // r10
  _DWORD *v14; // r4
  _DWORD *v15; // r2
  int v16; // r6
  _DWORD *v17; // r5
  _DWORD *v18; // r3
  int v19; // r0
  int v20; // r4
  int v21; // r3
  int v22; // r9
  int v23; // r3
  unsigned int *v24; // r2
  unsigned int v25; // r1
  unsigned int v26; // r1
  __int16 v27; // r3
  int v28; // r0
  int v29; // r6
  int v30; // r3
  unsigned int v31; // r2
  int v32; // r3
  int v33; // r0
  int v34; // r1
  int v35; // r10
  int *v36; // r2
  int v37; // r4
  int v38; // r6
  unsigned int *v39; // r2
  unsigned int v40; // r1
  int v41; // r0
  unsigned int v42; // r1
  __int16 v43; // r3
  int v44; // r3
  int v45; // r0
  _DWORD *v46; // r6
  int v47; // r4
  int v48; // r3
  unsigned int v49; // r1
  unsigned int v50; // lr
  int v51; // r0
  int v52; // r3
  int v53; // r0
  int v54; // r3
  int v55; // r0
  int v56; // r0
  int v57; // r3
  char v58; // lr
  char v59; // r2
  char v60; // r3
  unsigned int v61; // r2
  int v62; // r8
  _DWORD *v63; // r4
  _DWORD *v64; // r0
  BOOL v65; // r4
  int v67; // [sp+0h] [bp-C8h]
  int v68; // [sp+4h] [bp-C4h]
  char v69; // [sp+18h] [bp-B0h] BYREF
  char v70; // [sp+19h] [bp-AFh]
  int (__fastcall *v71)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // [sp+1Ch] [bp-ACh]
  int v72; // [sp+20h] [bp-A8h]
  unsigned int v73; // [sp+24h] [bp-A4h]
  int v74; // [sp+28h] [bp-A0h]
  int (__fastcall *v75)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // [sp+2Ch] [bp-9Ch] BYREF
  unsigned int v76; // [sp+30h] [bp-98h]
  int v77; // [sp+34h] [bp-94h]
  int v78; // [sp+38h] [bp-90h]
  _DWORD *v79; // [sp+3Ch] [bp-8Ch] BYREF
  int v80; // [sp+40h] [bp-88h]
  int v81; // [sp+44h] [bp-84h]
  int v82; // [sp+48h] [bp-80h] BYREF
  int v83; // [sp+4Ch] [bp-7Ch]
  int v84; // [sp+50h] [bp-78h]
  int (__fastcall *v85)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // [sp+54h] [bp-74h]
  int v86; // [sp+58h] [bp-70h]
  int v87; // [sp+5Ch] [bp-6Ch]
  _DWORD v88[2]; // [sp+60h] [bp-68h] BYREF
  int v89; // [sp+68h] [bp-60h]
  _DWORD *v90; // [sp+6Ch] [bp-5Ch]
  int v91; // [sp+70h] [bp-58h]
  int v92; // [sp+74h] [bp-54h]
  int v93; // [sp+78h] [bp-50h]
  int v94; // [sp+7Ch] [bp-4Ch]
  int v95; // [sp+80h] [bp-48h] BYREF
  int v96; // [sp+84h] [bp-44h]
  int v97; // [sp+88h] [bp-40h]
  int v98; // [sp+8Ch] [bp-3Ch]
  int v99; // [sp+90h] [bp-38h]
  int v100; // [sp+94h] [bp-34h]
  _DWORD *v101; // [sp+98h] [bp-30h]
  int v102; // [sp+9Ch] [bp-2Ch]
  int v103; // [sp+A0h] [bp-28h]
  int v104; // [sp+A4h] [bp-24h]
  int vars4; // [sp+CCh] [bp+4h]
  int varg_r0; // [sp+D0h] [bp+8h]
  int varg_r1; // [sp+D4h] [bp+Ch]
  int varg_r2; // [sp+D8h] [bp+10h]
  int varg_r3; // [sp+DCh] [bp+14h]

  v89 = a4;
  varg_r3 = a4;
  v91 = a3;
  varg_r2 = a3;
  v86 = a2;
  varg_r1 = a2;
  varg_r0 = a1;
  v71 = 0;
  v85 = 0;
  v87 = a6 & 3;
  v88[0] = v87;
  v84 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v92 = v84;
  v70 = *(_BYTE *)(v84 + 0x15A);
  v13 = v70;
  if ( v70 )
  {
    v14 = (_DWORD *)a5;
    v90 = (_DWORD *)a5;
    v15 = (_DWORD *)a5;
    if ( a5 >= MmUserProbeAddress )
      v15 = (_DWORD *)MmUserProbeAddress;
    *v15 = *v15;
    v76 = a9;
    if ( (a6 & 3) != 0 )
    {
      v74 = a10;
    }
    else if ( a9 )
    {
      v74 = a10;
      ProbeForWrite(a9, a10, 1);
    }
    else
    {
      v74 = 0;
    }
    if ( (a6 & 3) == 3 )
    {
      v73 = a8;
      v77 = a7;
    }
    else
    {
      v77 = a7;
      if ( a7 )
      {
        v73 = a8;
        if ( a8 && (a7 + a8 > MmUserProbeAddress || a7 + a8 < a7) )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
      else
      {
        v73 = 0;
      }
    }
    v72 = v93;
  }
  else
  {
    v74 = a10;
    v76 = a9;
    v73 = a8;
    v77 = a7;
    v14 = (_DWORD *)a5;
    v90 = (_DWORD *)a5;
    v72 = v93;
  }
  v68 = (int)&v95;
  v16 = ObReferenceObjectByHandle(a1, 0, IoFileObjectType, v13, &v79);
  v17 = v79;
  if ( v16 < 0 )
    return v16;
  v18 = (_DWORD *)v79[31];
  if ( v18 && (*v18 & 4) != 0 )
  {
    v19 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v75 = 0;
    v20 = PsReferencePrimaryToken(v19);
    SeQueryInformationToken(v20, 29, &v75);
    ObfDereferenceObject(v20);
    if ( v75 )
    {
      ObfDereferenceObject((int)v17);
      return -1073739504;
    }
    v14 = v90;
  }
  if ( v17[27] && v91 )
  {
    ObfDereferenceObject((int)v17);
    return -1073741811;
  }
  if ( v13 && (unsigned __int16)a6 >> 14 && (v96 & ((unsigned __int16)a6 >> 14)) != (unsigned __int16)a6 >> 14 )
  {
    ObfDereferenceObject((int)v17);
    return -1073741790;
  }
  if ( a6 == 606820 || a6 == 623208 )
  {
    v16 = IopCopyOffloadCapable(v17, a6);
    if ( v16 < 0 )
      goto LABEL_51;
  }
  if ( a2 )
  {
    v68 = 0;
    v16 = ObReferenceObjectByHandle(a2, 2, ExEventObjectType, v13, &v75);
    v22 = (int)v75;
    v71 = v75;
    v85 = v75;
    if ( v16 < 0 )
      goto LABEL_51;
    KeResetEvent((int)v75);
  }
  else
  {
    v22 = (int)v71;
  }
  if ( (v17[11] & 2) == 0 )
  {
    v81 = 0;
    v69 = 0;
    goto LABEL_55;
  }
  v23 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v23 & 0xFFFFFFC0) + 0x134);
  __dmb(0xBu);
  v24 = v17 + 17;
  do
    v25 = __ldrex(v24);
  while ( __strex(1u, v24) );
  __dmb(0xBu);
  if ( v25 )
  {
    v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v27 = *(_WORD *)(v26 + 0x134) + 1;
    *(_WORD *)(v26 + 308) = v27;
    if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
      KiCheckForKernelApcDelivery(1);
    v16 = IopAcquireFileObjectLock(v17, v13, (v17[11] & 4) != 0, &v69);
    if ( !v69 )
      goto LABEL_53;
    if ( v22 )
      ObfDereferenceObject(v22);
LABEL_51:
    ObfDereferenceObject((int)v17);
    return v16;
  }
  ObfReferenceObject((int)v17);
LABEL_53:
  v81 = 1;
  v69 = 1;
LABEL_55:
  if ( (v17[11] & 0x800) != 0 )
    v28 = IoGetAttachedDevice(v17[1]);
  else
    v28 = IoGetRelatedDeviceObject(v17);
  v29 = v28;
  v94 = v28;
  v78 = v28;
  if ( !a11 )
    goto LABEL_110;
  v30 = *(_DWORD *)(*(_DWORD *)(v28 + 8) + 40);
  if ( !v30 )
    goto LABEL_110;
  v75 = *(int (__fastcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(v30 + 40);
  v80 = (int)v75;
  if ( !v75 )
    goto LABEL_110;
  if ( v13 )
  {
    v28 = v76;
    if ( v76 )
    {
      if ( v87 == 1 )
      {
        if ( v74 && (v76 + v74 > MmUserProbeAddress || v76 + v74 < v76) )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
      else if ( v87 == 2 )
      {
        v28 = ProbeForWrite(v76, v74, 1);
      }
    }
  }
  if ( a6 == 589856 )
  {
    __dmb(0xBu);
    do
      v31 = __ldrex((unsigned int *)0xFFFF92DC);
    while ( __strex(v31 + 1, (unsigned int *)0xFFFF92DC) );
    __dmb(0xBu);
  }
  if ( (MmVerifierData & 0x10) != 0 )
    v88[0] = VfFastIoSnapState(v28);
  else
    v88[0] = 0;
  v32 = v75(v17, 1, v77, v73, v76, v74, a6, &v82, v29);
  v80 = v32;
  if ( v88[0] )
  {
    VfFastIoCheckState(v88[0], v75);
    v32 = v80;
  }
  if ( v32 )
  {
    v33 = v82;
    *v14 = v82;
    v34 = v83;
    v14[1] = v83;
    v35 = v81;
    v36 = (int *)v17[27];
    if ( !v36 || (v17[11] & 0x2000000) != 0 && (v33 & 0xC0000000) != 0x80000000 || (v33 & 0xC0000000) == -1073741824 )
    {
      v37 = 0;
      v38 = 0;
    }
    else
    {
      v37 = *v36;
      v38 = v36[1];
    }
    if ( v86 )
    {
      if ( (v17[11] & 0x8000000) == 0 || v37 && (v33 & 0xC0000000) == 0x80000000 )
        KeSetEvent((int)v71, 0, 0);
      ObfDereferenceObject((int)v71);
      v34 = v83;
      v33 = v82;
    }
    if ( v35 )
    {
      __dmb(0xBu);
      v39 = v17 + 17;
      do
        v40 = __ldrex(v39);
      while ( __strex(0, v39) );
      __dmb(0xBu);
      if ( v17[16] )
        KeSetEvent((int)(v17 + 19), 0, 0);
      v41 = ObfDereferenceObject((int)v17);
      v42 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v43 = *(_WORD *)(v42 + 0x134) + 1;
      *(_WORD *)(v42 + 308) = v43;
      if ( !v43 && *(_DWORD *)(v42 + 100) != v42 + 100 && !*(_WORD *)(v42 + 310) )
        KiCheckForKernelApcDelivery(v41);
      v33 = v82;
      v34 = v83;
    }
    if ( v37 && v89 )
    {
      if ( IoSetIoCompletion(v37, v38, v89, v33, v34, 1u) >= 0 )
      {
        v44 = v82;
      }
      else
      {
        v44 = -1073741670;
        v82 = -1073741670;
      }
      if ( (v44 & 0xC0000000) == 0x80000000 )
        v82 = 259;
    }
    ObfDereferenceObject((int)v17);
    v21 = v82;
  }
  else
  {
LABEL_110:
    if ( (v17[11] & 0x4000000) == 0 )
      KeResetEvent((int)(v17 + 23));
    v45 = pIoAllocateIrp(v29, *(char *)(v29 + 48), v81 == 0, vars4);
    v46 = (_DWORD *)v45;
    v88[0] = v45;
    if ( v45 )
    {
      *(_DWORD *)(v45 + 100) = v17;
      *(_DWORD *)(v45 + 80) = v84;
      *(_DWORD *)(v45 + 84) = 0;
      *(_BYTE *)(v45 + 32) = v13;
      *(_BYTE *)(v45 + 33) = 0;
      *(_BYTE *)(v45 + 36) = 0;
      *(_DWORD *)(v45 + 56) = 0;
      *(_DWORD *)(v45 + 44) = v71;
      *(_DWORD *)(v45 + 40) = v90;
      *(_DWORD *)(v45 + 48) = v91;
      *(_DWORD *)(v45 + 52) = v89;
      v47 = *(_DWORD *)(v45 + 96) - 40;
      v86 = v47;
      if ( a11 )
        v48 = 14;
      else
        v48 = 13;
      *(_DWORD *)v47 = v48;
      *(_DWORD *)(v47 + 28) = v17;
      v49 = v74;
      *(_DWORD *)(v47 + 8) = v74;
      v50 = v73;
      *(_DWORD *)(v47 + 12) = v73;
      *(_DWORD *)(v47 + 16) = a6;
      if ( a11 )
        v51 = 516;
      else
        v51 = 512;
      v46[1] = 0;
      v46[3] = 0;
      if ( (*(_DWORD *)(v78 + 28) & 0x80000) != 0 )
      {
        v52 = 3;
        v87 = 3;
      }
      else
      {
        v52 = v87;
      }
      if ( v52 == 3 )
      {
        v46[2] = 0;
        v46[15] = v76;
        *(_DWORD *)(v47 + 20) = v77;
      }
      else if ( v52 )
      {
        if ( (unsigned int)(v52 - 1) <= 1 )
        {
          v46[2] = 0;
          *(_DWORD *)(v47 + 20) = 0;
          if ( v50 && v77 )
          {
            if ( ViVerifierDriverAddedThunkListHead )
            {
              if ( (MmVerifierData & 0x10) != 0 )
                v54 = 40;
              else
                v54 = 32;
              v53 = ExAllocatePoolWithTagPriority(v51, v50, 538996553, v54);
              if ( !v53 )
                RtlRaiseStatus(-1073741670);
            }
            else
            {
              v53 = ExAllocatePoolWithQuotaTag(v51, v50, 538996553);
            }
            v46[3] = v53;
            memmove(v53, v77, v73);
            v46[2] = 48;
            v49 = v74;
          }
          if ( v49 )
          {
            v55 = IoAllocateMdl(v76, v49, 0, 1, (int)v46);
            v46[1] = v55;
            v75 = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v55;
            if ( !v55 )
              RtlRaiseStatus(-1073741670);
            v80 = *(_DWORD *)v47;
            MmProbeAndLockPages(v55);
            if ( (MmTrackLockedPages & 1) != 0 )
              MmUpdateMdlTracker(
                (unsigned int)v75,
                *(_DWORD *)(*(_DWORD *)(v78 + 8) + 4 * v80 + 56),
                v78,
                *(_DWORD *)(v78 + 8) + 4 * v80);
          }
        }
      }
      else
      {
        *(_DWORD *)(v47 + 20) = 0;
        if ( v50 || v49 )
        {
          if ( v50 > v49 )
            v49 = v50;
          if ( ViVerifierDriverAddedThunkListHead )
          {
            if ( (MmVerifierData & 0x10) != 0 )
              v57 = 40;
            else
              v57 = 32;
            v56 = ExAllocatePoolWithTagPriority(v51, v49, 538996553, v57);
            if ( !v56 )
              RtlRaiseStatus(-1073741670);
          }
          else
          {
            v56 = ExAllocatePoolWithQuotaTag(v51, v49, 538996553);
          }
          v46[3] = v56;
          if ( v77 )
            memmove(v56, v77, v73);
          v46[2] = 48;
          v46[15] = v76;
          if ( v74 )
            v46[2] |= 0x40u;
        }
        else
        {
          v46[2] = 0;
          v46[15] = 0;
        }
      }
      v58 = v96;
      v59 = ((v96 & 1) != 0) | *(_BYTE *)(v47 + 2);
      *(_BYTE *)(v47 + 2) = v59;
      if ( (v58 & 2) != 0 )
        v60 = 4;
      else
        v60 = 0;
      *(_BYTE *)(v47 + 2) = v60 | v59;
      if ( !a11 )
        v46[2] |= 0x800u;
      if ( a6 == 589856 )
      {
        __dmb(0xBu);
        do
          v61 = __ldrex((unsigned int *)0xFFFF92DC);
        while ( __strex(v61 + 1, (unsigned int *)0xFFFF92DC) );
        __dmb(0xBu);
      }
      if ( a6 == 589988 )
      {
        v62 = v46[3];
        if ( v73 >= 4 && *(_DWORD *)v62 == -1610612733 )
        {
          v95 = 0;
          v96 = 0;
          v97 = 0;
          v98 = 0;
          v63 = (_DWORD *)v84;
          v64 = (_DWORD *)IoThreadToProcess(v84);
          SeCaptureSubjectContextEx(v63, v64, &v95);
          v65 = RtlIsSandboxedToken((char *)&v95, v13);
          SeReleaseSubjectContext((int)&v95);
          if ( v65 )
          {
            v72 = FsRtlValidateReparsePointBuffer(v73, v62);
            if ( v72 < 0 )
              goto LABEL_174;
            LOWORD(v88[0]) = *(_WORD *)(v62 + 10);
            HIWORD(v88[0]) = v88[0];
            v88[1] = v62 + 16;
            v99 = 24;
            v100 = 0;
            v102 = 1536;
            v101 = v88;
            v103 = 0;
            v104 = 0;
            v68 = 1;
            v67 = 7;
            v72 = ZwOpenFile();
            if ( v72 < 0 )
            {
LABEL_174:
              IopExceptionCleanup(v17, v46, v71, 0, v67, v68);
              return v72;
            }
            ZwClose();
          }
        }
      }
      return IopSynchronousServiceTail(v78, v46, v17, a11 == 0, v13, v81, 2);
    }
    IopAllocateIrpCleanup(v17, v71);
    v21 = -1073741670;
  }
  return v21;
}
