// NtSetInformationToken 
 
int __fastcall NtSetInformationToken(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v7; // r2
  int v8; // r5
  int v9; // r1
  int v10; // r0
  int v11; // r4
  int v12; // r0
  int *v13; // r8
  unsigned int v14; // r9
  int v15; // r2
  int v16; // r3
  unsigned __int16 *v17; // r4
  int v18; // r3
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  int v22; // r0
  unsigned int v23; // r1
  __int16 v24; // r3
  unsigned int v25; // r5
  int v26; // r2
  int v27; // r3
  int v28; // r3
  int v29; // r0
  unsigned int v30; // r1
  __int16 v31; // r3
  int v32; // r0
  unsigned int v33; // r1
  __int16 v34; // r3
  int v35; // r0
  unsigned int v36; // r1
  __int16 v37; // r3
  int v38; // r8
  unsigned int v39; // r3
  unsigned int v40; // r9
  int v41; // r2
  int v42; // r3
  unsigned int v43; // r1
  int v44; // r0
  unsigned int v45; // r1
  __int16 v46; // r3
  int v47; // r0
  unsigned int v48; // r1
  __int16 v49; // r3
  int v50; // r0
  int v51; // r5
  int v52; // r0
  int v53; // r0
  unsigned int v54; // r1
  __int16 v55; // r3
  int v56; // r8
  int v57; // r8
  int v58; // r2
  int v59; // r3
  int v60; // r0
  unsigned int v61; // r1
  __int16 v62; // r3
  unsigned int v63; // r2
  int v64; // r9
  int v65; // r0
  unsigned int v66; // r1
  __int16 v67; // r3
  int v68; // r2
  int v69; // r3
  int v70; // r2
  int v71; // r3
  int v72; // r0
  unsigned int v73; // r1
  __int16 v74; // r3
  int v75; // r9
  unsigned int v76; // r8
  int v77; // r2
  int v78; // r3
  int v79; // r8
  int v80; // r2
  int v81; // r3
  int v82; // r3
  unsigned int v83; // r3
  unsigned int v84; // r10
  int v85; // r5
  _BYTE *v86; // r0
  unsigned int v87; // r5
  int v88; // r2
  int v89; // r3
  int *v90; // r0
  int *v91; // r10
  int v92; // r0
  unsigned int v93; // r1
  __int16 v94; // r3
  _BYTE *v95; // r0
  unsigned int v96; // r3
  int v97; // r0
  unsigned int v98; // r1
  __int16 v99; // r3
  int v100; // r0
  unsigned int v101; // r1
  __int16 v102; // r3
  int v103; // r2
  unsigned int v104; // r3
  unsigned int v105; // r3
  int v106; // r3
  int v107; // r3
  unsigned int v108; // r3
  unsigned int v109; // r3
  unsigned int v110; // r0
  unsigned int v111; // r0
  _DWORD *v112; // r1
  int v113; // r1
  int v114; // r0
  unsigned int v115; // r1
  __int16 v116; // r3
  int v117; // r0
  unsigned int v118; // r1
  __int16 v119; // r3
  int v120; // r8
  int v121; // r2
  int v122; // r3
  int v123; // r3
  int v124; // r2
  int v125; // r3
  _DWORD *v126; // r8
  int v127; // r0
  unsigned int v128; // r1
  __int16 v129; // r3
  int v130; // r8
  int *v132; // [sp+8h] [bp-78h]
  unsigned int *v133; // [sp+Ch] [bp-74h]
  char v134; // [sp+18h] [bp-68h]
  int v135; // [sp+1Ch] [bp-64h]
  int v136; // [sp+1Ch] [bp-64h]
  int v137; // [sp+20h] [bp-60h] BYREF
  int v138; // [sp+24h] [bp-5Ch]
  int v139; // [sp+28h] [bp-58h] BYREF
  unsigned __int16 *v140; // [sp+2Ch] [bp-54h]
  _DWORD v141[2]; // [sp+30h] [bp-50h] BYREF
  unsigned int v142[2]; // [sp+38h] [bp-48h] BYREF
  int v143; // [sp+40h] [bp-40h] BYREF
  unsigned __int16 *v144; // [sp+44h] [bp-3Ch]
  int v145; // [sp+48h] [bp-38h]
  unsigned __int16 *v146; // [sp+4Ch] [bp-34h]
  int v147; // [sp+50h] [bp-30h]
  int v148; // [sp+54h] [bp-2Ch]
  int v149; // [sp+58h] [bp-28h]
  int v150; // [sp+5Ch] [bp-24h]
  int varg_r0; // [sp+88h] [bp+8h]
  int varg_r1; // [sp+8Ch] [bp+Ch]
  unsigned int varg_r2; // [sp+90h] [bp+10h]
  unsigned int varg_r3; // [sp+94h] [bp+14h]

  varg_r3 = a4;
  varg_r2 = a3;
  varg_r1 = a2;
  v140 = (unsigned __int16 *)a1;
  varg_r0 = a1;
  v139 = 0;
  v143 = 0;
  v134 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v134 && a4 )
  {
    if ( (a3 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    v7 = a3 + a4;
    if ( a3 + a4 > MmUserProbeAddress || v7 < a3 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  if ( a2 != 4
    && a2 != 5
    && a2 != 12
    && a2 != 6
    && a2 != 14
    && a2 != 16
    && a2 != 19
    && a2 != 17
    && a2 != 25
    && a2 != 27
    && a2 != 23
    && a2 != 24
    && a2 != 26
    && a2 != 39
    && a2 != 42 )
  {
    return -1073741821;
  }
  v9 = 128;
  if ( a2 == 12 )
  {
    v9 = 384;
  }
  else if ( a2 == 19 )
  {
    v9 = 136;
  }
  v10 = ObReferenceObjectByHandle(a1, v9, SeTokenObjectType, v134, &v137);
  v11 = v137;
  v141[0] = v137;
  v138 = v10;
  if ( v10 < 0 )
    return v10;
  switch ( a2 )
  {
    case 4:
      if ( a4 < 4 )
        goto LABEL_55;
      v140 = *(unsigned __int16 **)a3;
      v12 = SeCaptureSid(v140, v134);
      v138 = v12;
      v13 = (int *)v11;
      if ( v12 < 0 )
        goto LABEL_238;
      v14 = 0;
      v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v16 = *(__int16 *)(v15 + 0x134) - 1;
      *(_WORD *)(v15 + 308) = v16;
      ExAcquireResourceExclusiveLite(*(_DWORD *)(v11 + 48), 1, v15, v16);
      __dmb(0xFu);
      v17 = v140;
      while ( 2 )
      {
        if ( v14 >= v13[31] )
        {
          if ( v139 )
            ExAllocateLocallyUniqueId(v13 + 13);
          __dmb(0xFu);
          v22 = ExReleaseResourceLite(v13[12]);
          v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v24 = *(_WORD *)(v23 + 0x134) + 1;
          *(_WORD *)(v23 + 308) = v24;
          if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
            KiCheckForKernelApcDelivery(v22);
          ObfDereferenceObject((int)v13);
          SeReleaseSid(v17, v134, 1);
          v8 = -1073741734;
        }
        else
        {
          if ( !RtlEqualSid(v17, *(unsigned __int16 **)(v13[37] + 8 * v14)) )
          {
            ++v14;
            continue;
          }
          if ( SepIdAssignableAsOwner(v13, v14) )
          {
            v13[36] = v14;
            v18 = 1;
            v139 = 1;
            v8 = 0;
          }
          else
          {
            v8 = -1073741734;
            v18 = v139;
          }
          if ( v18 )
            ExAllocateLocallyUniqueId(v13 + 13);
          __dmb(0xFu);
          v19 = ExReleaseResourceLite(v13[12]);
          v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v21 = *(_WORD *)(v20 + 0x134) + 1;
          *(_WORD *)(v20 + 308) = v21;
          if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
            KiCheckForKernelApcDelivery(v19);
          ObfDereferenceObject((int)v13);
          SeReleaseSid(v17, v134, 1);
          v141[1] = v8;
        }
        break;
      }
      return v8;
    case 5:
      if ( a4 < 4 )
        goto LABEL_55;
      v135 = *(_DWORD *)a3;
      v12 = SeCaptureSid(*(_DWORD *)a3, v134);
      v138 = v12;
      if ( v12 < 0 )
        goto LABEL_238;
      if ( SepIdAssignableAsGroup(v11, v135) )
      {
        v25 = 4 * (*(unsigned __int8 *)(v135 + 1) + 2);
        v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v27 = *(__int16 *)(v26 + 0x134) - 1;
        *(_WORD *)(v26 + 308) = v27;
        ExAcquireResourceExclusiveLite(*(_DWORD *)(v11 + 48), 1, v26, v27);
        __dmb(0xFu);
        v28 = *(_DWORD *)(v11 + 164);
        if ( v28 )
          v25 += *(unsigned __int16 *)(v28 + 2);
        if ( v25 <= *(_DWORD *)(v11 + 136) )
        {
          v8 = SepExpandDynamic((_DWORD *)v11, v25);
          if ( v8 >= 0 )
          {
            SepFreePrimaryGroup(v11);
            SepAppendPrimaryGroup(v11, v135);
            ExAllocateLocallyUniqueId((int *)(v11 + 52));
            __dmb(0xFu);
            v35 = ExReleaseResourceLite(*(_DWORD *)(v11 + 48));
            v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v37 = *(_WORD *)(v36 + 0x134) + 1;
            *(_WORD *)(v36 + 308) = v37;
            if ( !v37 && *(_DWORD *)(v36 + 100) != v36 + 100 && !*(_WORD *)(v36 + 310) )
              KiCheckForKernelApcDelivery(v35);
            v8 = 0;
          }
          else
          {
            __dmb(0xFu);
            v32 = ExReleaseResourceLite(*(_DWORD *)(v11 + 48));
            v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v34 = *(_WORD *)(v33 + 0x134) + 1;
            *(_WORD *)(v33 + 308) = v34;
            if ( !v34 && *(_DWORD *)(v33 + 100) != v33 + 100 && !*(_WORD *)(v33 + 310) )
              KiCheckForKernelApcDelivery(v32);
          }
        }
        else
        {
          __dmb(0xFu);
          v29 = ExReleaseResourceLite(*(_DWORD *)(v11 + 48));
          v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v31 = *(_WORD *)(v30 + 0x134) + 1;
          *(_WORD *)(v30 + 308) = v31;
          if ( !v31 && *(_DWORD *)(v30 + 100) != v30 + 100 && !*(_WORD *)(v30 + 310) )
            KiCheckForKernelApcDelivery(v29);
          v8 = -1073741671;
        }
      }
      else
      {
        v8 = -1073741733;
      }
      ObfDereferenceObject(v11);
      SeReleaseSid(v135, v134, 1);
      return v8;
    case 6:
      if ( a4 < 4 )
        goto LABEL_55;
      v38 = *(_DWORD *)a3;
      v139 = v38;
      if ( v38 )
      {
        v133 = v141;
        v132 = &v139;
        v12 = SeCaptureAcl(v38, v134);
        v138 = v12;
        v39 = v141[0];
        v38 = v139;
      }
      else
      {
        v39 = 0;
        v141[0] = 0;
        v12 = 0;
        v138 = 0;
      }
      v142[0] = v39;
      v40 = v39;
      if ( v12 < 0 )
        goto LABEL_238;
      v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v42 = *(__int16 *)(v41 + 0x134) - 1;
      *(_WORD *)(v41 + 308) = v42;
      ExAcquireResourceExclusiveLite(*(_DWORD *)(v11 + 48), 1, v41, v42);
      __dmb(0xFu);
      v43 = v40 + 4 * (*(unsigned __int8 *)(*(_DWORD *)(v11 + 156) + 1) + 2);
      if ( v43 > *(_DWORD *)(v11 + 136) )
      {
        __dmb(0xFu);
        v44 = ExReleaseResourceLite(*(_DWORD *)(v11 + 48));
        v45 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v46 = *(_WORD *)(v45 + 0x134) + 1;
        *(_WORD *)(v45 + 308) = v46;
        if ( !v46 && *(_DWORD *)(v45 + 100) != v45 + 100 && !*(_WORD *)(v45 + 310) )
          KiCheckForKernelApcDelivery(v44);
        ObfDereferenceObject(v11);
        if ( v38 )
          SeReleaseAcl(v38, v134);
        return -1073741671;
      }
      v8 = SepExpandDynamic((_DWORD *)v11, v43);
      if ( v8 < 0 )
        goto LABEL_92;
      v50 = *(_DWORD *)(v11 + 164);
      if ( !v50 )
      {
        v51 = 0;
        goto LABEL_102;
      }
      v133 = v142;
      v132 = &v143;
      v8 = SeCaptureAcl(v50, 0);
      if ( v8 >= 0 )
      {
        v51 = v143;
LABEL_102:
        v52 = SepFreeDefaultDacl(v11);
        if ( v38 )
          v52 = SepAppendDefaultDacl((_DWORD *)v11, v38);
        SeTokenDefaultDaclChangedAuditAlarm(v52, v11, v140, v51, v38, 0, v132, v133);
        ExAllocateLocallyUniqueId((int *)(v11 + 52));
        __dmb(0xFu);
        v53 = ExReleaseResourceLite(*(_DWORD *)(v11 + 48));
        v54 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v55 = *(_WORD *)(v54 + 0x134) + 1;
        *(_WORD *)(v54 + 308) = v55;
        if ( !v55 && *(_DWORD *)(v54 + 100) != v54 + 100 && !*(_WORD *)(v54 + 310) )
          KiCheckForKernelApcDelivery(v53);
        ObfDereferenceObject(v11);
        if ( v38 )
          SeReleaseAcl(v38, v134);
        if ( v51 )
          SeReleaseAcl(v51, 0);
        return 0;
      }
LABEL_92:
      __dmb(0xFu);
      v47 = ExReleaseResourceLite(*(_DWORD *)(v11 + 48));
      v48 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v49 = *(_WORD *)(v48 + 0x134) + 1;
      *(_WORD *)(v48 + 308) = v49;
      if ( !v49 && *(_DWORD *)(v48 + 100) != v48 + 100 && !*(_WORD *)(v48 + 310) )
        KiCheckForKernelApcDelivery(v47);
      ObfDereferenceObject(v11);
      if ( v38 )
        SeReleaseAcl(v38, v134);
      return v8;
    case 12:
      if ( a4 != 4 )
        goto LABEL_55;
      v56 = *(_DWORD *)a3;
      v145 = v56;
      if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v134, (int)&SeTcbPrivilege) )
        goto LABEL_115;
      v12 = SeSetSessionIdToken(v11, v56);
      goto LABEL_238;
    case 14:
      if ( a4 != 4 )
        goto LABEL_55;
      v57 = *(_DWORD *)a3;
      v147 = v57;
      if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v134, (int)&SeTcbPrivilege) )
        goto LABEL_115;
      if ( v57 )
      {
LABEL_122:
        v8 = -1073741811;
        goto LABEL_239;
      }
      v58 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v59 = *(__int16 *)(v58 + 0x134) - 1;
      *(_WORD *)(v58 + 308) = v59;
      ExAcquireResourceExclusiveLite(*(_DWORD *)(v11 + 48), 1, v58, v59);
      __dmb(0xFu);
      if ( (*(_DWORD *)(v11 + 176) & 0x20) != 0 )
        goto LABEL_125;
      v8 = SepStopReferencingLogonSession(v11);
      if ( v8 >= 0 )
        goto LABEL_125;
      goto LABEL_239;
    case 16:
      if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v134, (int)&SeTcbPrivilege) )
        goto LABEL_115;
      v63 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v63 + 308);
      ExAcquireResourceSharedLite(*(_DWORD *)(v11 + 48), 1);
      v64 = *(unsigned __int8 *)(v11 + 118);
      v65 = ExReleaseResourceLite(*(_DWORD *)(v11 + 48));
      v66 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v67 = *(_WORD *)(v66 + 0x134) + 1;
      *(_WORD *)(v66 + 308) = v67;
      if ( !v67 && *(_DWORD *)(v66 + 100) != v66 + 100 && !*(_WORD *)(v66 + 310) )
        KiCheckForKernelApcDelivery(v65);
      if ( v64 )
        goto LABEL_122;
      if ( !a3 )
      {
        v68 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v69 = *(__int16 *)(v68 + 0x134) - 1;
        *(_WORD *)(v68 + 308) = v69;
        ExAcquireResourceExclusiveLite(*(_DWORD *)(v11 + 48), 1, v68, v69);
        __dmb(0xFu);
        *(_BYTE *)(v11 + 118) = 1;
LABEL_138:
        ExAllocateLocallyUniqueId((int *)(v11 + 52));
LABEL_125:
        __dmb(0xFu);
        v60 = ExReleaseResourceLite(*(_DWORD *)(v11 + 48));
        v61 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v62 = *(_WORD *)(v61 + 0x134) + 1;
        *(_WORD *)(v61 + 308) = v62;
        if ( !v62 && *(_DWORD *)(v61 + 100) != v61 + 100 && !*(_WORD *)(v61 + 310) )
          KiCheckForKernelApcDelivery(v60);
LABEL_129:
        v8 = 0;
        goto LABEL_239;
      }
      v12 = SepCaptureAuditPolicy(a3, v134);
      v138 = v12;
      if ( v12 < 0 )
        goto LABEL_238;
      v70 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v71 = *(__int16 *)(v70 + 0x134) - 1;
      *(_WORD *)(v70 + 308) = v71;
      ExAcquireResourceExclusiveLite(*(_DWORD *)(v11 + 48), 1, v70, v71);
      __dmb(0xFu);
      *(_BYTE *)(v11 + 118) = 2;
      memmove(v11 + 88, 0, 0x1Eu);
      ExAllocateLocallyUniqueId((int *)(v11 + 52));
      __dmb(0xFu);
      v72 = ExReleaseResourceLite(*(_DWORD *)(v11 + 48));
      v73 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v74 = *(_WORD *)(v73 + 0x134) + 1;
      *(_WORD *)(v73 + 308) = v74;
      if ( !v74 && *(_DWORD *)(v73 + 100) != v73 + 100 && !*(_WORD *)(v73 + 310) )
        KiCheckForKernelApcDelivery(v72);
      SepModifyTokenPolicyCounter(v11 + 88, 1);
      ObfDereferenceObject(v11);
      SepReleaseAuditPolicy(0, v134);
      return 0;
    case 17:
      if ( a4 != 8 )
        goto LABEL_55;
      v75 = *(_DWORD *)a3;
      v142[0] = *(_DWORD *)a3;
      v76 = *(_DWORD *)(a3 + 4);
      v142[1] = v76;
      if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v134, (int)&SeTcbPrivilege) )
        goto LABEL_115;
      v77 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v78 = *(__int16 *)(v77 + 0x134) - 1;
      *(_WORD *)(v77 + 308) = v78;
      ExAcquireResourceExclusiveLite(*(_DWORD *)(v11 + 48), 1, v77, v78);
      __dmb(0xFu);
      if ( !*(_QWORD *)(v11 + 196) )
      {
        *(_DWORD *)(v11 + 196) = v75;
        *(_DWORD *)(v11 + 200) = v76;
      }
      goto LABEL_138;
    case 19:
      v144 = 0;
      if ( a4 != 4 )
        goto LABEL_55;
      v144 = *(unsigned __int16 **)a3;
      v12 = SepLinkLogonSessions(v137, (int)v144, v134);
      goto LABEL_238;
    case 23:
      if ( a4 != 4 )
        goto LABEL_55;
      v79 = *(_DWORD *)a3;
      v149 = v79;
      if ( !SeSinglePrivilegeCheck(SeCreateTokenPrivilege, dword_922A04, v134, (int)&SeCreateTokenPrivilege) )
        goto LABEL_115;
      v80 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v81 = *(__int16 *)(v80 + 0x134) - 1;
      *(_WORD *)(v80 + 308) = v81;
      ExAcquireResourceExclusiveLite(*(_DWORD *)(v11 + 48), 1, v80, v81);
      __dmb(0xFu);
      v82 = *(_DWORD *)(v11 + 176);
      if ( v79 )
        v83 = v82 | 0x200;
      else
        v83 = v82 & 0xFFFFFDFF;
      goto LABEL_154;
    case 24:
      if ( a4 != 4 )
        goto LABEL_55;
      v146 = *(unsigned __int16 **)a3;
      SeSetVirtualizationToken(v137);
      goto LABEL_129;
    case 25:
      if ( a4 < 8 )
        goto LABEL_55;
      v12 = SeCaptureSidAndAttributesArray(a3, 1, v134, 0, 0);
      v138 = v12;
      if ( v12 < 0 )
        goto LABEL_238;
      v84 = v142[0];
      v85 = *(_DWORD *)v142[0];
      if ( memcmp(*(_DWORD *)v142[0] + 2, SeUntrustedMandatorySid + 2, 6) )
        goto LABEL_160;
      v86 = (_BYTE *)RtlSubAuthorityCountSid(v85);
      if ( *v86 )
      {
        v87 = *(_DWORD *)RtlSubAuthoritySid(v85, (unsigned __int8)*v86 - 1);
        if ( v87 > 0x4000 )
        {
LABEL_160:
          ObfDereferenceObject(v11);
          SeReleaseLuidAndAttributesArray(v84, v134);
          return -1073740730;
        }
      }
      else
      {
        v87 = 0;
      }
      v88 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v89 = *(__int16 *)(v88 + 0x134) - 1;
      *(_WORD *)(v88 + 308) = v89;
      ExAcquireResourceExclusiveLite(*(_DWORD *)(v11 + 48), 1, v88, v89);
      __dmb(0xFu);
      v90 = (int *)SepLocateTokenIntegrity(v11);
      v91 = v90;
      if ( !v90 )
      {
        __dmb(0xFu);
        v92 = ExReleaseResourceLite(*(_DWORD *)(v11 + 48));
        v93 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v94 = *(_WORD *)(v93 + 0x134) + 1;
        *(_WORD *)(v93 + 308) = v94;
        if ( !v94 && *(_DWORD *)(v93 + 100) != v93 + 100 && !*(_WORD *)(v93 + 310) )
          KiCheckForKernelApcDelivery(v92);
        v8 = -1073740730;
        goto LABEL_211;
      }
      v136 = *v90;
      v95 = (_BYTE *)RtlSubAuthorityCountSid(*v90);
      if ( *v95 )
        v96 = *(_DWORD *)RtlSubAuthoritySid(v136, (unsigned __int8)*v95 - 1);
      else
        v96 = 0;
      if ( v87 <= v96 )
        goto LABEL_186;
      if ( SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v134, (int)&SeTcbPrivilege) )
      {
        if ( *(_BYTE *)(v11 + 180) )
        {
          __dmb(0xFu);
          v100 = ExReleaseResourceLite(*(_DWORD *)(v11 + 48));
          v101 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v102 = *(_WORD *)(v101 + 0x134) + 1;
          *(_WORD *)(v101 + 308) = v102;
          if ( !v102 && *(_DWORD *)(v101 + 100) != v101 + 100 && !*(_WORD *)(v101 + 310) )
            KiCheckForKernelApcDelivery(v100);
          v8 = -1073741525;
        }
        else
        {
LABEL_186:
          if ( *(_BYTE *)(*v91 + 1) )
          {
            *(_DWORD *)RtlSubAuthoritySid(*v91, *(unsigned __int8 *)(*v91 + 1) - 1) = v87;
            if ( v87 < 0x3000 )
            {
              v104 = *(_DWORD *)(v11 + 76) & 0xFFFFFFFE;
              *(_DWORD *)(v11 + 72) &= 0xDFE9F97B;
              *(_DWORD *)(v11 + 76) = v104;
              v103 = *(_DWORD *)(v11 + 80) & 0xDFE9F97B;
              v105 = *(_DWORD *)(v11 + 84) & 0xFFFFFFFE;
              *(_DWORD *)(v11 + 80) = v103;
              *(_DWORD *)(v11 + 84) = v105;
            }
            if ( v87 >= 0x2000 )
            {
              v109 = *(_DWORD *)(v11 + 176);
              if ( (v109 & 0x4000) != 0 )
              {
                SepRemoveAceFromTokenDefaultDacl(v11, *(unsigned __int16 **)(v11 + 480), v103, v109);
                *(_DWORD *)(v11 + 176) &= 0xFFFFBFFF;
                v110 = *(_DWORD *)(v11 + 480);
                if ( v110 )
                {
                  ExFreePoolWithTag(v110);
                  *(_DWORD *)(v11 + 480) = 0;
                }
                v111 = *(_DWORD *)(v11 + 484);
                if ( v111 )
                {
                  ExFreePoolWithTag(v111);
                  *(_DWORD *)(v11 + 484) = 0;
                  *(_DWORD *)(v11 + 488) = 0;
                  memset((_BYTE *)(v11 + 492), 0, 136);
                }
                v112 = *(_DWORD **)(v11 + 628);
                if ( v112 )
                {
                  SepDereferenceLowBoxNumberEntry(*(_DWORD *)(v11 + 120), v112);
                  *(_DWORD *)(v11 + 628) = 0;
                }
                v113 = *(_DWORD *)(v11 + 632);
                if ( v113 )
                {
                  SepDereferenceLowBoxHandlesEntry(*(_DWORD *)(v11 + 192), v113);
                  *(_DWORD *)(v11 + 632) = 0;
                }
              }
              v108 = *(_DWORD *)(v11 + 176) | 0x2000;
            }
            else
            {
              v106 = *(_DWORD *)(v11 + 76) & 2;
              *(_DWORD *)(v11 + 72) &= 0x2800000u;
              *(_DWORD *)(v11 + 76) = v106;
              v107 = *(_DWORD *)(v11 + 84) & 2;
              *(_DWORD *)(v11 + 80) &= 0x2800000u;
              *(_DWORD *)(v11 + 84) = v107;
              v108 = *(_DWORD *)(v11 + 176) & 0xFFFFDFFF;
            }
            *(_DWORD *)(v11 + 176) = v108;
            ExAllocateLocallyUniqueId((int *)(v11 + 52));
            __dmb(0xFu);
            v114 = ExReleaseResourceLite(*(_DWORD *)(v11 + 48));
            v115 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v116 = *(_WORD *)(v115 + 0x134) + 1;
            *(_WORD *)(v115 + 308) = v116;
            if ( !v116 && *(_DWORD *)(v115 + 100) != v115 + 100 && !*(_WORD *)(v115 + 310) )
              KiCheckForKernelApcDelivery(v114);
            v8 = 0;
          }
          else
          {
            __dmb(0xFu);
            v117 = ExReleaseResourceLite(*(_DWORD *)(v11 + 48));
            v118 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v119 = *(_WORD *)(v118 + 0x134) + 1;
            *(_WORD *)(v118 + 308) = v119;
            if ( !v119 && *(_DWORD *)(v118 + 100) != v118 + 100 && !*(_WORD *)(v118 + 310) )
              KiCheckForKernelApcDelivery(v117);
            v8 = -1073741811;
          }
        }
      }
      else
      {
        __dmb(0xFu);
        v97 = ExReleaseResourceLite(*(_DWORD *)(v11 + 48));
        v98 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v99 = *(_WORD *)(v98 + 0x134) + 1;
        *(_WORD *)(v98 + 308) = v99;
        if ( !v99 && *(_DWORD *)(v98 + 100) != v98 + 100 && !*(_WORD *)(v98 + 310) )
          KiCheckForKernelApcDelivery(v97);
        v8 = -1073741727;
      }
LABEL_211:
      ObfDereferenceObject(v11);
      SeReleaseLuidAndAttributesArray(v142[0], v134);
      return v8;
    case 26:
      if ( a4 != 4 )
        goto LABEL_55;
      v120 = *(_DWORD *)a3;
      v148 = v120;
      if ( v120 && !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v134, (int)&SeTcbPrivilege) )
        goto LABEL_115;
      v121 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v122 = *(__int16 *)(v121 + 0x134) - 1;
      *(_WORD *)(v121 + 308) = v122;
      ExAcquireResourceExclusiveLite(*(_DWORD *)(v11 + 48), 1, v121, v122);
      __dmb(0xFu);
      v123 = *(_DWORD *)(v11 + 176);
      if ( v120 )
        v83 = v123 | 0x1000;
      else
        v83 = v123 & 0xFFFFEFFF;
LABEL_154:
      *(_DWORD *)(v11 + 176) = v83;
      goto LABEL_138;
    case 27:
      v142[0] = 0;
      if ( a4 != 4 )
        goto LABEL_55;
      v142[0] = *(_DWORD *)a3;
      if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v134, (int)&SeTcbPrivilege) )
        goto LABEL_115;
      if ( *(_BYTE *)(v11 + 180) )
      {
        v8 = -1073741525;
        goto LABEL_239;
      }
      v12 = SeSetMandatoryPolicyToken(v11, v142);
      goto LABEL_238;
    case 39:
      if ( !a3 || a4 < 8 )
        goto LABEL_55;
      if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v134, (int)&SeTcbPrivilege) )
        goto LABEL_115;
      v8 = SepCaptureTokenSecurityAttributesAndOperationsInformation(a3, v134, v142);
      if ( v8 >= 0 )
      {
        v124 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v125 = *(__int16 *)(v124 + 0x134) - 1;
        *(_WORD *)(v124 + 308) = v125;
        ExAcquireResourceExclusiveLite(*(_DWORD *)(v11 + 48), 1, v124, v125);
        __dmb(0xFu);
        v126 = (_DWORD *)v142[0];
        v8 = AuthzBasepSetSecurityAttributesToken(*(_DWORD *)(v11 + 476), *(int **)(v142[0] + 4), *(_DWORD *)v142[0]);
        ExAllocateLocallyUniqueId((int *)(v11 + 52));
        __dmb(0xFu);
        v127 = ExReleaseResourceLite(*(_DWORD *)(v11 + 48));
        v128 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v129 = *(_WORD *)(v128 + 0x134) + 1;
        *(_WORD *)(v128 + 308) = v129;
        if ( !v129 && *(_DWORD *)(v128 + 100) != v128 + 100 && !*(_WORD *)(v128 + 310) )
          KiCheckForKernelApcDelivery(v127);
        if ( v134 )
        {
          ExFreePoolWithTag(v126[1]);
          if ( *v126 )
            SepFreeCapturedTokenSecurityAttributesInformation(*v126);
          ExFreePoolWithTag((unsigned int)v126);
        }
      }
      goto LABEL_239;
    case 42:
      if ( a4 == 4 )
      {
        v130 = *(_DWORD *)a3;
        v150 = v130;
        if ( SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v134, (int)&SeTcbPrivilege) )
        {
          v12 = SeSetPrivateNameSpaceToken(v11, v130);
LABEL_238:
          v8 = v12;
        }
        else
        {
LABEL_115:
          v8 = -1073741727;
        }
      }
      else
      {
LABEL_55:
        v8 = -1073741820;
      }
LABEL_239:
      ObfDereferenceObject(v11);
      return v8;
    default:
      return -1073741811;
  }
}
