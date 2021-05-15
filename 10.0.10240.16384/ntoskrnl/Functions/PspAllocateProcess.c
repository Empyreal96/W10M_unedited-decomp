// PspAllocateProcess 
 
int PspAllocateProcess(_DWORD *a1, char a2, int a3, int a4, char a5, char a6, int a7, int a8, ...)
{
  int v8; // r8
  unsigned int v9; // r6
  _DWORD *v10; // r2
  int v11; // r3
  int v12; // r4
  unsigned int v13; // r0
  unsigned int v14; // r10
  _BYTE *v15; // r5
  int v16; // r1
  int v17; // r3
  int v18; // r3
  _DWORD *v19; // r10
  int v20; // r2
  int v21; // r0
  int v22; // r4
  int v23; // r9
  int v24; // r4
  unsigned int *v25; // r9
  unsigned int v26; // r0
  unsigned int v27; // r1
  int v28; // r3
  unsigned int v29; // r4
  unsigned int v30; // r1
  unsigned int v31; // r2
  unsigned int v32; // r0
  int v33; // r3
  int v34; // r0
  int v35; // r0
  int v36; // r0
  int v37; // r0
  int v38; // r4
  int v39; // r3
  int v40; // r2
  __int16 v41; // r1
  int v42; // r0
  char v43; // r9
  int v44; // r9
  int v45; // r9
  int v46; // r0
  int v47; // r9
  int v48; // r0
  _DWORD *v49; // r1
  int v50; // r2
  int v51; // r3
  int v52; // r0
  int v53; // r3
  unsigned int *v54; // r0
  unsigned int v55; // r1
  int v56; // r4
  int v57; // r4
  unsigned int *v58; // r0
  unsigned int v59; // r1
  __int64 v60; // r0
  int v61; // r3
  _DWORD *v62; // r3
  unsigned int v63; // r2
  int v64; // r0
  int v65; // r0
  __int64 v66; // r0
  int v67; // r9
  unsigned int v68; // r9
  int v69; // r0
  unsigned int v70; // r9
  int v71; // r2
  int v72; // r9
  _DWORD *v73; // r10
  __int16 v74; // r9
  int v75; // r10
  int v76; // r0
  int v77; // r0
  int v78; // r2
  int v79; // r1
  unsigned int *v80; // r0
  unsigned int v81; // r1
  _DWORD *v82; // r9
  int v83; // r3
  int v84; // r9
  unsigned int *v85; // r8
  int v86; // r0
  unsigned __int8 *v87; // r4
  int v88; // r0
  int v89; // r6
  unsigned int v90; // r2
  int v91; // r0
  unsigned int v92; // r1
  int v93; // r0
  __int16 v94; // r3
  bool v95; // zf
  __int64 *v96; // r0
  int v97; // r1
  __int64 v98; // r0
  unsigned int v99; // r4
  unsigned int v100; // lr
  int v102; // [sp+4h] [bp-194h]
  int v103; // [sp+Ch] [bp-18Ch]
  int v104; // [sp+18h] [bp-180h]
  int v105; // [sp+1Ch] [bp-17Ch]
  __int64 v106; // [sp+20h] [bp-178h] BYREF
  int v107; // [sp+28h] [bp-170h] BYREF
  _DWORD *v108; // [sp+2Ch] [bp-16Ch]
  int v109; // [sp+30h] [bp-168h]
  int v110; // [sp+34h] [bp-164h] BYREF
  _DWORD *v111; // [sp+38h] [bp-160h]
  _DWORD *v112; // [sp+3Ch] [bp-15Ch]
  int v113; // [sp+40h] [bp-158h] BYREF
  int v114; // [sp+44h] [bp-154h]
  int v115; // [sp+48h] [bp-150h]
  int v116; // [sp+4Ch] [bp-14Ch] BYREF
  int v117; // [sp+50h] [bp-148h] BYREF
  int v118; // [sp+54h] [bp-144h] BYREF
  int v119; // [sp+58h] [bp-140h]
  int v120; // [sp+5Ch] [bp-13Ch] BYREF
  unsigned int *v121; // [sp+60h] [bp-138h]
  _DWORD *v122; // [sp+64h] [bp-134h]
  int v123; // [sp+68h] [bp-130h] BYREF
  int v124; // [sp+6Ch] [bp-12Ch]
  _DWORD *v125; // [sp+70h] [bp-128h]
  unsigned int *v126; // [sp+74h] [bp-124h]
  int v127; // [sp+78h] [bp-120h] BYREF
  int v128; // [sp+7Ch] [bp-11Ch]
  int v129; // [sp+80h] [bp-118h]
  _BYTE *v130; // [sp+84h] [bp-114h] BYREF
  int v131; // [sp+88h] [bp-110h]
  int v132; // [sp+8Ch] [bp-10Ch] BYREF
  _DWORD v133[2]; // [sp+90h] [bp-108h] BYREF
  int v134; // [sp+98h] [bp-100h]
  int v135; // [sp+9Ch] [bp-FCh] BYREF
  _DWORD *v136; // [sp+A0h] [bp-F8h]
  int v137; // [sp+A4h] [bp-F4h]
  _DWORD *v138; // [sp+A8h] [bp-F0h]
  unsigned int *v139; // [sp+ACh] [bp-ECh]
  unsigned int v140[16]; // [sp+B0h] [bp-E8h] BYREF
  int v141; // [sp+F0h] [bp-A8h] BYREF
  int v142; // [sp+F8h] [bp-A0h]
  int v143[7]; // [sp+100h] [bp-98h] BYREF
  unsigned __int16 v144; // [sp+11Eh] [bp-7Ah]
  char v145; // [sp+123h] [bp-75h]
  _BYTE v146[24]; // [sp+130h] [bp-68h] BYREF
  _DWORD v147[6]; // [sp+148h] [bp-50h] BYREF
  _DWORD _160[15]; // [sp+160h] [bp-38h] BYREF
  int varg_r3; // [sp+1ACh] [bp+14h]
  int v150; // [sp+1C0h] [bp+28h] BYREF
  va_list va; // [sp+1C0h] [bp+28h]
  unsigned int v152; // [sp+1C4h] [bp+2Ch]
  int v153; // [sp+1C8h] [bp+30h]
  int v154; // [sp+1CCh] [bp+34h]
  _DWORD *v155; // [sp+1D0h] [bp+38h]
  va_list va1; // [sp+1D4h] [bp+3Ch] BYREF

  va_start(va1, a8);
  va_start(va, a8);
  v150 = va_arg(va1, _DWORD);
  v152 = va_arg(va1, _DWORD);
  v153 = va_arg(va1, _DWORD);
  v154 = va_arg(va1, _DWORD);
  v155 = va_arg(va1, _DWORD *);
  v126 = (unsigned int *)a3;
  v109 = a2;
  v108 = a1;
  v140[1] = (unsigned int)a1;
  v115 = a7;
  v124 = a8;
  v8 = v152;
  v140[3] = v152;
  v131 = v154;
  v136 = v155;
  v138 = v155;
  v9 = 0;
  v121 = (unsigned int *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v140[2] = (unsigned int)v121;
  v112 = (_DWORD *)v121[29];
  v10 = 0;
  v122 = 0;
  LODWORD(v106) = 0;
  v118 = 0;
  v123 = 0;
  v120 = 0;
  v119 = 0;
  v104 = v150;
  if ( (v150 & 0x800) != 0 )
  {
    v9 = 1024;
    if ( (v150 & 0x2000) != 0 )
    {
      v9 = 66560;
      if ( (v150 & 0x4000) != 0 )
        v9 = 197632;
    }
  }
  if ( (v150 & 0x100) != 0 )
  {
    v10 = a1;
    v122 = a1;
  }
  if ( v8 && (*(_DWORD *)(v8 + 4) & 0x2000) != 0 )
  {
    if ( v10 )
      return -1073741776;
    LODWORD(v106) = *(&KeNodeBlock + *(unsigned __int16 *)(v8 + 146));
    v118 = v106;
  }
  else if ( a1 && (a1[47] & 0x200000) != 0 )
  {
    v122 = a1;
    v120 = 0x200000;
  }
  memset(v147, 0, sizeof(v147));
  v125 = 0;
  v111 = 0;
  v12 = 888;
  v116 = 0;
  v114 = 0;
  if ( !PsDisableDiskCounters )
  {
    v116 = 888;
    v12 = 928;
    v9 |= 0x200u;
  }
  if ( PoEnergyEstimationEnabled() )
  {
    v114 = (v12 + 7) & 0xFFFFFFF8;
    v12 = v114 + 144;
    v9 |= 0x2000u;
  }
  v13 = KeQueryMaximumGroupCount();
  v117 = v13;
  v14 = 0;
  if ( v13 > 1 )
  {
    v14 = (v12 + 3) & 0xFFFFFFFC;
    v12 = v14 + 8 * v13;
  }
  v103 = v12;
  v102 = v12;
  v11 = ObCreateObjectEx(v109, PsProcessType, v126, v109);
  if ( v11 < 0 )
    return v11;
  v15 = v130;
  ObfReferenceObjectWithTag((int)v130);
  ObfDereferenceObjectWithTag((int)v130);
  memset(v130, 0, v12);
  *((_DWORD *)v130 + 164) = 0;
  *((_DWORD *)v15 + 165) = 0;
  *((_DWORD *)v15 + 166) = 0;
  *((_DWORD *)v15 + 167) = 0;
  *((_DWORD *)v15 + 164) = 0;
  *((_DWORD *)v15 + 166) = v15 + 660;
  *((_DWORD *)v15 + 165) = v15 + 660;
  *((_DWORD *)v15 + 43) = 0;
  *((_DWORD *)v15 + 42) = 0;
  *((_DWORD *)v15 + 100) = v15 + 396;
  *((_DWORD *)v15 + 99) = v15 + 396;
  *((_DWORD *)v15 + 190) = v15 + 756;
  *((_DWORD *)v15 + 189) = v15 + 756;
  v15[734] = varg_r3;
  v15[732] = a5;
  v15[733] = a6;
  v16 = (v9 >> 10) & 1;
  if ( v16 )
    *((_DWORD *)v15 + 184) |= 1u;
  if ( (v104 & 0x8000) != 0 )
    *((_DWORD *)v15 + 184) |= 0x80u;
  if ( v14 )
  {
    *((_DWORD *)v15 + 184) |= 0x200u;
    *((_DWORD *)v15 + 220) = &v15[v14];
    *((_DWORD *)v15 + 221) = &v15[4 * v117 + v14];
  }
  v17 = v112[44];
  if ( (v104 & 0x200) == 0 )
    v17 |= 2u;
  *((_DWORD *)v15 + 79) = v17;
  if ( (v9 & 0x200) != 0 )
    *((_DWORD *)v15 + 194) = &v15[v116];
  if ( (v9 & 0x2000) != 0 )
    *((_DWORD *)v15 + 199) = &v15[v114];
  if ( v8 && (*(_DWORD *)(v8 + 4) & 0x200) != 0 )
  {
    v18 = *(_DWORD *)(v8 + 188);
    v19 = v108;
  }
  else
  {
    v19 = v108;
    if ( v108 )
      v18 = v108[103];
    else
      v18 = 1;
  }
  *((_DWORD *)v15 + 103) = v18;
  *((_DWORD *)v15 + 158) = 259;
  if ( v19 )
  {
    v20 = (v19[48] >> 27) & 7;
    v21 = (v19[47] >> 12) & 7;
    *((_DWORD *)v15 + 78) = v19[44];
  }
  else
  {
    v21 = MmGetDefaultPagePriority();
  }
  v139 = (unsigned int *)(v15 + 192);
  *((_DWORD *)v15 + 48) = *((_DWORD *)v15 + 48) & 0xC7FFFFFF | (v20 << 27);
  v126 = (unsigned int *)(v15 + 188);
  *((_DWORD *)v15 + 47) = *((_DWORD *)v15 + 47) & 0xFFFF8FFF | (v21 << 12);
  v22 = v115;
  if ( v16 )
    goto LABEL_66;
  v119 = v115;
  if ( !v115 )
  {
    if ( v19 )
    {
      if ( v153 )
        goto LABEL_46;
      if ( v19 == (_DWORD *)PsInitialSystemProcess )
      {
        v24 = -1073741811;
        goto LABEL_321;
      }
      v25 = v19 + 43;
      __pld(v19 + 43);
      v26 = v19[43] & 0xFFFFFFFE;
      do
        v27 = __ldrex(v25);
      while ( v27 == v26 && __strex(v26 + 2, v25) );
      __dmb(0xBu);
      if ( v27 == v26 || ExfAcquireRundownProtection(v19 + 43) )
      {
        v28 = v19[73];
        v115 = v28;
        if ( v28 )
          ObfReferenceObject(v28);
        __pld(v25);
        v29 = *v25 & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v30 = __ldrex(v25);
        while ( v30 == v29 && __strex(v29 - 2, v25) );
        if ( v30 != v29 )
          ExfReleaseRundownProtection((unsigned __int8 *)v19 + 172);
      }
      v22 = v115;
      if ( !v115 )
      {
        v24 = -1073741558;
        goto LABEL_321;
      }
    }
LABEL_66:
    v23 = v104;
    goto LABEL_67;
  }
  v23 = v104;
  if ( (v104 & 0x1000) != 0 )
  {
LABEL_46:
    v24 = -1073741776;
LABEL_321:
    PspRundownSingleProcess((unsigned int *)v15, 0);
    ObfDereferenceObjectWithTag((int)v15);
    return v24;
  }
  ObfReferenceObject(v115);
LABEL_67:
  *((_DWORD *)v15 + 73) = v22;
  v114 = 0;
  if ( v8 )
  {
    v24 = MmGetSectionInformation(v22, 1, (int *)(v8 + 28));
    if ( v24 < 0 )
      goto LABEL_321;
    v31 = v9 & 0xFFFFFE7F | (32 * (*(_BYTE *)(v8 + 63) & 4 | (4 * (*(_BYTE *)(v8 + 63) & 2))));
    v32 = *(unsigned __int16 *)(v8 + 60);
    v33 = (v31 & 0x100) != 0 && v32 == 332 && (*(_BYTE *)(v8 + 63) & 1) != 0;
    v9 = (v31 ^ (v33 << 15)) & 0x8000 ^ v31;
    if ( (*(_WORD *)(v8 + 56) & *(_WORD *)(v8 + 10)) != 0 )
    {
      v24 = -1073741701;
LABEL_76:
      v34 = 3;
LABEL_77:
      PspUpdateCreateInfo(v34, v8, 0);
      goto LABEL_321;
    }
    if ( (v9 & 0x8000) == 0 && (v32 < MEMORY[0xFFFF902C] || v32 > MEMORY[0xFFFF902E]) && (v9 & 0x4000) == 0 )
    {
      v24 = -1073741701;
      v34 = 4;
      goto LABEL_77;
    }
    if ( v119 )
    {
      v114 = *(unsigned __int16 *)(v8 + 58);
      v35 = RtlpOpenImageFileOptionsKey();
      if ( v35 < 0 )
      {
        if ( v35 == -1073741772 )
          *(_BYTE *)(v8 + 8) |= 0x40u;
        *(_DWORD *)(v8 + 112) = 0;
      }
      v36 = *(_DWORD *)(v8 + 112);
      if ( v36 )
      {
        if ( (*(_BYTE *)(v8 + 8) & 0x80) != 0 )
          goto LABEL_96;
        v37 = RtlQueryImageFileKeyOption(v36, L"Debugger", 1, &v132, 2u, v140);
        if ( v37 >= 0 )
        {
          if ( v140[0] != 2 || !(_WORD)v132 )
            goto LABEL_96;
        }
        else if ( v37 != -2147483643 )
        {
LABEL_96:
          v110 = 0;
          if ( RtlQueryImageFileKeyOption(*(_DWORD *)(v8 + 112), L"UseLargePages", 4, &v110, 4u, 0) >= 0 )
          {
            if ( v110 )
            {
              v104 = v23 | 0x10;
              v150 = v23 | 0x10;
              if ( (v9 & 0x4000) == 0 )
              {
                v140[10] = 24;
                v140[11] = *(_DWORD *)(v8 + 112);
                v140[13] = 576;
                v140[12] = (unsigned int)&PspLargePageDLLKeyName;
                v140[14] = 0;
                v140[15] = 0;
                if ( ZwOpenKey() >= 0 )
                {
                  v110 = 0;
                  if ( RtlQueryImageFileKeyOption(v134, L"ntdll.dll", 4, &v110, 4u, 0) >= 0 && v110 )
                  {
                    v104 = v23 | 0x30;
                    v150 = v23 | 0x30;
                  }
                  ObCloseHandle(v134);
                }
              }
            }
          }
          if ( !v122 )
          {
            PspReadIFEONodeOptions((int)v15, *(_DWORD *)(v8 + 112), (int)&v118, 0);
            LODWORD(v106) = v118;
          }
          v135 = 0;
          if ( RtlQueryImageFileKeyOption(*(_DWORD *)(v8 + 112), L"ForceWakeCharge", 4, &v135, 4u, 0) >= 0 && v135 )
            v120 |= 0x40u;
          v140[4] = 24;
          v140[5] = *(_DWORD *)(v8 + 112);
          v140[7] = 576;
          v140[6] = (unsigned int)&PspPerfOptionsKeyName;
          v140[8] = 0;
          v140[9] = 0;
          if ( ZwOpenKey() >= 0 )
          {
            PspReadIFEOPerfOptions(v137, v147);
            ObCloseHandle(v137);
          }
          goto LABEL_115;
        }
        v24 = -1073741767;
        v34 = 5;
        goto LABEL_77;
      }
    }
  }
  else if ( v22 )
  {
    v24 = MmGetSectionInformation(v22, 1, v143);
    if ( v24 < 0 )
      goto LABEL_321;
    v9 = v9 & 0xFFFFFE7F | (32 * (v145 & 4 | (4 * (v145 & 2))));
    v114 = v144;
    if ( !v119 )
    {
      v123 = 8;
      v9 |= 0x800u;
    }
  }
LABEL_115:
  v24 = SeQueryInformationToken(v124, 29, &v116);
  if ( v24 < 0 )
    goto LABEL_321;
  if ( (v114 & 0x1000) != 0 && !v116 )
  {
    v24 = -1073741790;
    if ( !v8 )
      goto LABEL_321;
    goto LABEL_76;
  }
  v38 = 0;
  v39 = v109;
  if ( v109 )
  {
    if ( v8 && (*(_DWORD *)(v8 + 4) & 0x100) != 0 && *(_BYTE *)(v8 + 144) == 4 )
    {
      _160[0] = 14;
      v38 = 1;
    }
    v40 = v153;
    if ( v153 )
      _160[v38++] = 3;
    v41 = v104;
    if ( (v104 & 0x30) != 0 )
      _160[v38++] = 4;
    if ( (v104 & 0x80) != 0 )
    {
      v42 = MmIsSessionLeaderProcess(v112);
      v41 = v104;
      if ( !v42 )
        _160[v38++] = 10;
      v40 = v153;
    }
    if ( (v41 & 0x8400) != 0 )
      _160[v38++] = 7;
    if ( v38 )
    {
      if ( RtlAcquirePrivilege((int)_160, v38, v40 != 0) >= 0 )
        v9 |= 0x10u;
      v125 = v111;
    }
    v39 = v109;
  }
  v43 = v104;
  if ( (v104 & 0x8400) != 0 && !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v39, v39) )
    goto LABEL_143;
  *((_DWORD *)v15 + 48) |= v123;
  *((_DWORD *)v15 + 47) |= v120;
  if ( v19 )
  {
    v117 = 0;
    v44 = 0;
    v123 = 0;
    v9 &= 0xFFFFFFFE;
    v110 = 0;
    LOBYTE(v107) = 0;
    if ( v153 )
    {
      if ( SeSinglePrivilegeCheck(SeAssignPrimaryTokenPrivilege, dword_9227D4, v109, v153) )
        v9 |= 4u;
      else
        v9 &= 0xFFFFFFFB;
      v45 = v124;
      v24 = SeIsTokenAssignableToProcess(v124, (bool *)&v107);
      if ( v24 < 0 )
        goto LABEL_319;
      v110 = (unsigned __int8)v107;
      if ( !(_BYTE)v107 && (v9 & 4) == 0 )
        goto LABEL_143;
      v24 = SeQuerySessionIdToken(v45, &v123);
      if ( v24 < 0 )
        goto LABEL_319;
      v46 = MmGetSessionIdEx((int)v112);
      v44 = v123;
      if ( v123 != v46 )
      {
        if ( (v9 & 4) == 0 )
        {
LABEL_143:
          v24 = -1073741727;
          goto LABEL_319;
        }
        if ( (v104 & 0x80) != 0 )
        {
          v24 = -1073741811;
          goto LABEL_319;
        }
        v9 |= 1u;
      }
    }
    else if ( !v119 )
    {
      v44 = MmGetSessionIdEx((int)v19);
      v9 = v9 & 0xFFFFFFFE | (v44 != MmGetSessionIdEx((int)v112));
    }
    if ( (v9 & 1) != 0 )
    {
      v24 = PspAttachSession(v44, v146, &v117);
      if ( v24 < 0 )
      {
        LOBYTE(v9) = v9 & 0xFE;
        goto LABEL_319;
      }
      *((_DWORD *)v15 + 47) |= 0x80u;
      v47 = v117;
    }
    else
    {
      v47 = 0;
    }
    if ( v153 )
    {
      if ( !v110 )
      {
        v48 = PspAssignProcessQuotaBlock(0, (int)v15, v124);
        v24 = v48;
        if ( v48 < 0 )
        {
          if ( (v9 & 1) != 0 )
            PspDetachSession(v47, v146);
          goto LABEL_319;
        }
        goto LABEL_174;
      }
    }
    else if ( !v110 )
    {
      v49 = v108;
      goto LABEL_173;
    }
    v49 = v112;
LABEL_173:
    v48 = PspInheritQuota((int)v15, (int)v49);
LABEL_174:
    if ( (v147[1] & 1) != 0 )
    {
      v50 = v147[5];
      v51 = 1;
    }
    else
    {
      v50 = PspMaximumWorkingSet;
      v51 = 0;
    }
    v9 ^= (v9 ^ (32
               * MmCreateProcessAddressSpace(
                   v48,
                   PspMinimumWorkingSet,
                   v50,
                   v51,
                   (int)v15,
                   v102,
                   0,
                   v103,
                   (int)&v130,
                   0,
                   v104,
                   v105,
                   v106,
                   SHIDWORD(v106),
                   v107,
                   (int)v108,
                   v109,
                   v110,
                   (int)v111,
                   (int)v112,
                   v113,
                   v114,
                   v115,
                   v116,
                   v117))) & 0x20;
    if ( (v9 & 1) != 0 )
      PspDetachSession(v47, v146);
    if ( (v9 & 0x20) == 0 )
      goto LABEL_180;
    v19 = v108;
    v43 = v104;
    goto LABEL_184;
  }
  v52 = PspInheritQuota((int)v15, 0);
  v24 = MmInitializeHandBuiltProcess(v52);
  if ( v24 < 0 )
    goto LABEL_319;
LABEL_184:
  if ( !v122 )
  {
    v53 = v106;
    if ( !(_DWORD)v106 )
    {
      if ( !v19 )
      {
        v56 = 0;
LABEL_197:
        v127 = 0;
        v129 = 0;
        v128 = (unsigned __int16)v56;
        v127 = dword_681D78[v56];
        __dmb(0xBu);
        v43 = v150;
        v104 = v150;
        v57 = v118;
        v125 = v111;
        v15 = v130;
        goto LABEL_201;
      }
      if ( (v19[47] & 0x100000) == 0 )
      {
        v118 = PspSelectNodeForProcess();
        v56 = *(unsigned __int16 *)(v118 + 264);
        if ( KeForceGroupAwareness && (unsigned int)KeQueryActiveGroupCount() > 1 && !v56 )
        {
          v118 = 0;
          v56 = 1;
        }
        goto LABEL_197;
      }
      __dmb(0xBu);
      v54 = v126;
      do
        v55 = __ldrex(v54);
      while ( __strex(v55 | 0x100000, v54) );
      __dmb(0xBu);
      v53 = (int)*(&KeNodeBlock + *((unsigned __int16 *)v19 + 57));
      v118 = v53;
    }
    v56 = *(unsigned __int16 *)(v53 + 264);
    goto LABEL_197;
  }
  KeQueryAffinityProcess((int)v122, &v141, 0, &v120);
  if ( v142 )
  {
    v128 = 0;
    v129 = 0;
    v127 = v142;
  }
  v57 = (int)*(&KeNodeBlock + *((unsigned __int16 *)&v120 + (unsigned __int16)v128));
LABEL_201:
  __dmb(0xBu);
  v58 = v139;
  do
    v59 = __ldrex(v58);
  while ( __strex(v59 | 0x40000, v58) );
  __dmb(0xBu);
  v60 = MmGetSessionSchedulingGroupByProcess(v15);
  v24 = KeInitializeProcess(v15, 8, &v127, v57, v60, HIDWORD(v60));
  if ( v24 < 0 )
    goto LABEL_319;
  v24 = PspInitializeProcessSecurity(v19, v15, v124, v153, v131);
  if ( v24 < 0 )
    goto LABEL_319;
  v15[375] = 2;
  if ( v19 )
  {
    v61 = *((unsigned __int8 *)v19 + 375);
    if ( v61 == 1 || v61 == 5 )
      v15[375] = v61;
    v62 = (_DWORD *)(v8 ? *(_DWORD *)(v8 + 176) : 0);
    v63 = v8 ? *(_DWORD *)(v8 + 172) : 0;
    v64 = (int)((v43 & 4) != 0 ? v19 : 0);
    v65 = ObInitProcess(v64, (int)v15, v63, v62);
  }
  else
  {
    *((_DWORD *)v15 + 84) = v112[84];
    v65 = MmInitializeHandBuiltProcess2(v15);
  }
  v24 = v65;
  if ( v65 < 0 )
    goto LABEL_319;
  if ( (v147[0] & 7) != 0 )
    PspApplyIFEOPerfOptions(v15, v147, v109);
  if ( v8 )
  {
    if ( (*(_DWORD *)(v8 + 4) & 0x100) != 0 )
    {
      v24 = PspSetProcessPriorityClass((int)v15, *(unsigned __int8 *)(v8 + 144));
      if ( v24 < 0 )
        goto LABEL_319;
    }
  }
  v15[104] = PspComputeQuantumAndPriority(v15, 0, &v113, 0);
  v15[105] = v113;
  v24 = 0;
  v111 = 0;
  v117 = 0;
  v106 = 0i64;
  PspReadIFEOMitigationOptions(v8, &v106);
  v66 = PspInheritMitigationOptions(PspSystemMitigationOptions, dword_68259C, v106, HIDWORD(v106));
  v106 = v66;
  v67 = HIWORD(HIDWORD(v66)) & 3;
  if ( v8 && (*(_DWORD *)(v8 + 4) & 0x10000) != 0 )
  {
    v66 = PspInheritMitigationOptions(v66, HIDWORD(v66), *(_DWORD *)(v8 + 208), *(_DWORD *)(v8 + 212));
    v106 = v66;
  }
  v68 = (v67 << 16) | 0x100;
  if ( v116 )
    v68 |= 4u;
  if ( (v68 & 0xFF00) == 0 && (v68 & 4) != 0 )
    v68 = v68 & 0xFFFF00FF | 0x100;
  if ( (v68 & 0xFF00) != 0 )
  {
    v69 = PspHardenMitigationOptions(&v106);
    v24 = v69;
    if ( v8 && (*(_DWORD *)(v8 + 4) & 0x10000) != 0 )
    {
      if ( v69 < 0 )
        goto LABEL_321;
      v66 = v106;
    }
    else
    {
      v66 = v106;
      if ( !v106 )
      {
        v66 = 1118993i64;
        v106 = 1118993i64;
      }
      v24 = 0;
    }
  }
  if ( (v9 & 0x400) != 0 )
  {
    LODWORD(v106) = v66 & 0xFFEEFFFF | 0x220000;
    HIDWORD(v106) = HIDWORD(v66) & 0xFFFFFCFF | 0x200;
  }
  v70 = v68 & 0xFFFFFFFE | ((v9 & 0x180) != 0);
  v71 = ((unsigned __int8)v70 ^ (unsigned __int8)(2 * ((v114 & 0x20) != 0))) & 2 ^ v70;
  PspApplyMitigationOptions(
    v15,
    v108,
    &v106,
    ((unsigned __int8)v71 ^ (unsigned __int8)(8 * ((v114 & 0x4000) != 0))) & 8 ^ v71);
  if ( v8 )
    *(_QWORD *)(v8 + 208) = v106;
  v131 = SeSecurityAttributePresent(v124, (int)&PspPackagedAppClaim);
  v9 ^= (((v9 ^ ((v116 != 0) << 18)) & 0x40000 ^ v9 | (((v104 & 0x10000) != 0) << 18)) ^ (v9 ^ ((v116 != 0) << 18)) & 0x40000 ^ v9) & 0x40000 ^ (v9 ^ ((v116 != 0) << 18)) & 0x40000;
  LODWORD(v106) = v9;
  SmProcessCreateNotification(v15, (v9 >> 18) & 1);
  if ( (v104 & 0x80) != 0
    && !MmIsSessionLeaderProcess(v112)
    && !SeSinglePrivilegeCheck(SeLoadDriverPrivilege, dword_922B84, v109, (int)&SeLoadDriverPrivilege) )
  {
    goto LABEL_143;
  }
  v72 = (v9 >> 10) & 1;
  if ( v72 || v119 )
  {
    if ( (v9 & 0x10000) != 0 )
    {
      v73 = v108;
      v77 = MmInitializeProcessAddressSpace(v15, (int)v108, 0, (int *)va);
    }
    else
    {
      v77 = MmInitializeProcessAddressSpace(v15, 0, v115, (int *)va);
      v73 = v108;
    }
    v24 = v77;
    if ( v77 < 0 )
      goto LABEL_319;
    if ( v8 )
    {
      v78 = *(_DWORD *)(*(_DWORD *)MiSectionControlArea(v115) + 24);
      v79 = *((_DWORD *)v15 + 74);
      if ( v78 != v79 )
        *(_DWORD *)(v8 + 28) = *(_DWORD *)(v8 + 28) - v78 + v79;
    }
    v111 = (_DWORD *)v24;
    v117 = v24;
    if ( !v72 )
      v9 |= 2u;
    v9 = (((unsigned __int8)v9 | 8) ^ (((v150 & 0x10) != 0) << 6)) & 0x40 ^ (v9 | 8);
    LODWORD(v106) = v9;
    goto LABEL_266;
  }
  v73 = v108;
  if ( !v108 )
    goto LABEL_266;
  *((_DWORD *)v15 + 74) = v108[74];
  v24 = MmInitializeProcessAddressSpace(v15, (int)v73, 0, (int *)va);
  if ( v24 < 0 )
  {
LABEL_319:
    if ( (v9 & 0x10) != 0 )
      RtlReleasePrivilege(v125);
    goto LABEL_321;
  }
  v74 = v150;
  v9 = (((unsigned __int8)v9 | 2) ^ (((v150 & 0x10) != 0) << 6)) & 0x40 ^ (v9 | 2);
  LODWORD(v106) = v9;
  v75 = *(unsigned __int16 *)(v73[95] + 2);
  v76 = ExAllocatePoolWithTag(512, v75 + 8, 1632658771);
  *((_DWORD *)v15 + 95) = v76;
  if ( !v76 )
  {
LABEL_180:
    v24 = -1073741670;
    goto LABEL_319;
  }
  memmove(v76, v108[95], v75 + 8);
  *(_DWORD *)(*((_DWORD *)v15 + 95) + 4) = *((_DWORD *)v15 + 95) + 8;
  v73 = v108;
  *((_DWORD *)v15 + 75) = v108[75];
  if ( (v74 & 0x1000) != 0 )
  {
    *((_DWORD *)v15 + 73) = 0;
    ObfDereferenceObject(v115);
  }
LABEL_266:
  if ( (v9 & 0x10) != 0 )
    RtlReleasePrivilege(v125);
  if ( (v9 & 2) != 0 )
  {
    v133[0] = 0;
    v133[1] = -1;
    HIBYTE(v133[0]) = (((((v9 & 0x40) != 0) ^ (2 * ((v15[734] & 7) != 0))) & 2 ^ ((v9 & 0x40) != 0)) & 0xBB | (4 * (((v9 & 0x80) != 0) | (16 * ((v15[734] & 7) == 1))))) & 0xCF | (16 * (v131 & 1 | (2 * (v116 != 0))));
    if ( v119 )
    {
      v24 = MmCreatePeb(v15, (unsigned __int8 *)v133, (int)(v15 + 320), &v127);
      if ( v24 < 0 )
      {
        *((_DWORD *)v15 + 80) = 0;
        goto LABEL_321;
      }
      if ( v127 )
      {
        __dmb(0xBu);
        v80 = v126;
        do
          v81 = __ldrex(v80);
        while ( __strex(v81 & 0xFFCFFFFF, v80) );
        __dmb(0xBu);
        PspSetProcessAffinitySafe(v15, 1, 0, &v127);
      }
    }
    else
    {
      v82 = (_DWORD *)v73[80];
      *((_DWORD *)v15 + 80) = v82;
      if ( (v9 & 0x800) == 0 )
      {
        LOBYTE(v133[0]) = 1;
        KiStackAttachProcess((int)v15, 0, (int)v146);
        if ( MmSecureVirtualMemory((unsigned int)v82, 592, 4, v83) )
        {
          *v82 = v133[0];
          v82[1] = -1;
        }
        else
        {
          v24 = -1073741503;
        }
        KiUnstackDetachProcess((unsigned int)v146, 0);
        if ( v24 < 0 )
          goto LABEL_321;
      }
    }
  }
  v84 = (v9 >> 3) & 1;
  if ( v84 && v8 )
  {
    v24 = PspSetupUserProcessAddressSpace((int)v73, (int)v15, (unsigned int)v146, v8);
  }
  else if ( (v9 & 2) != 0 && (v9 & 0x800) == 0 )
  {
    v24 = 0;
    KiStackAttachProcess((int)v15, 0, (int)v146);
    v85 = v121;
    PspWritePebAffinityInfo(v121, v15);
    if ( v84 )
    {
      v86 = MmMapApiSetView((int)v15);
      v24 = v86;
      if ( v86 >= 0 )
        v24 = PspPrepareSystemDllInitBlock(v86, 0);
    }
    KiUnstackDetachProcess((unsigned int)v146, 0);
    goto LABEL_292;
  }
  v85 = v121;
LABEL_292:
  if ( v24 < 0 )
    goto LABEL_321;
  --*((_WORD *)v85 + 154);
  v87 = v15 + 168;
  v88 = KeAbPreAcquire((unsigned int)(v15 + 168), 0, 0);
  v89 = v88;
  do
    v90 = __ldrex(v87);
  while ( __strex(v90 | 1, v87) );
  __dmb(0xBu);
  if ( (v90 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)v15 + 42, v88, (unsigned int)(v15 + 168));
  if ( v89 )
    *(_BYTE *)(v89 + 14) |= 1u;
  v91 = ExCreateHandle(PspCidTable, v15);
  *((_DWORD *)v15 + 44) = v91;
  if ( !v91 )
  {
    __dmb(0xBu);
    do
      v92 = __ldrex((unsigned int *)v87);
    while ( __strex(v92 - 1, (unsigned int *)v87) );
    if ( (v92 & 2) != 0 && (v92 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v15 + 42);
    v93 = KeAbPostRelease((unsigned int)(v15 + 168));
    v94 = *((_WORD *)v85 + 154) + 1;
    *((_WORD *)v85 + 154) = v94;
    if ( !v94 && (unsigned int *)v85[25] != v85 + 25 && !*((_WORD *)v85 + 155) )
      KiCheckForKernelApcDelivery(v93);
    v24 = -1073741670;
    goto LABEL_321;
  }
  v95 = KeQuerySystemTimeUnsafe() == 0;
  v96 = (__int64 *)(v15 + 200);
  if ( v95 )
    KeQuerySystemTime(v96);
  else
    KeQuerySystemTimePrecise(v96);
  *((_DWORD *)v15 + 206) = KeQueryInterruptTime();
  *((_DWORD *)v15 + 207) = v97;
  do
  {
    v98 = MEMORY[0xFFFF93B0];
    while ( 1 )
    {
      v99 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v100 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v99 == MEMORY[0xFFFF9010] )
        break;
      __dmb(0xAu);
      __yield();
    }
  }
  while ( v98 != MEMORY[0xFFFF93B0] );
  *((_QWORD *)v15 + 104) = __PAIR64__(v99, v100) - v98;
  *((_DWORD *)v15 + 212) = *((_DWORD *)v15 + 206);
  *((_DWORD *)v15 + 213) = *((_DWORD *)v15 + 207);
  *v136 = v15;
  return (int)v111;
}
