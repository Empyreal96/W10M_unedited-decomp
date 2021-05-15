// MiResolvePageFileFault 
 
int __fastcall MiResolvePageFileFault(unsigned int a1, _DWORD *a2, int a3, int a4, int a5, int a6, int *a7)
{
  unsigned int v7; // r4
  int v9; // r9
  unsigned int v10; // r6
  char v11; // r0
  int result; // r0
  int v13; // r0
  unsigned int v14; // r10
  int v15; // r5
  unsigned int v16; // r6
  int v17; // r0
  unsigned int *v18; // r1
  int v19; // r0
  int v20; // r5
  unsigned int v21; // r4
  bool v22; // r3
  int v23; // r0
  _BYTE *v24; // r8
  int v25; // r7
  int *v26; // r3
  int v27; // r0
  int v28; // r6
  int v29; // r6
  unsigned int v30; // r8
  unsigned int v31; // r5
  unsigned int v32; // r4
  unsigned int v33; // r8
  int *v34; // lr
  int *v35; // r0
  unsigned int *v36; // r9
  char v37; // r7
  unsigned int v38; // r2
  unsigned int v39; // r1
  int v40; // r3
  int v41; // t1
  int v42; // r3
  int v43; // r7
  unsigned int v44; // r3
  unsigned int *v45; // r8
  unsigned int v46; // r0
  unsigned int v47; // r1
  int v48; // r3
  int v49; // t1
  int v50; // r3
  unsigned int v51; // r4
  unsigned int *v52; // r6
  unsigned int v53; // r0
  unsigned int *v54; // r9
  int v55; // r5
  int v56; // r4
  int v57; // r2
  int v58; // r3
  int v59; // r10
  int v60; // r4
  int v61; // lr
  int v62; // r7
  unsigned int v63; // r4
  unsigned int v64; // r5
  int v65; // r8
  int v66; // r7
  int v67; // r3
  int v68; // r6
  int v69; // r4
  int v70; // r5
  int v71; // r3
  int v72; // r1
  int v73; // r0
  unsigned int v74; // r2
  int v75; // r1
  char v76; // r2
  int *v77; // r1
  unsigned int v78; // r6
  unsigned int v79; // r0
  int *v80; // r5
  unsigned int v81; // r2
  int v82; // r2
  int v83; // r0
  unsigned int *v84; // r10
  int v85; // r0
  int v86; // r2
  unsigned int *v87; // r10
  __int16 v88; // r3
  unsigned int *v89; // r0
  signed int v90; // r7
  unsigned int v91; // r9
  signed int v92; // lr
  int v93; // r4
  int v94; // r1
  int v95; // r3
  int v96; // r0
  unsigned int v97; // r3
  unsigned int v98; // r2
  unsigned int v99; // r2
  char v100; // r2
  int v101; // r0
  unsigned int *v102; // r0
  unsigned int v103; // r1
  int v104; // r2
  char v105; // r2
  int v106; // r4
  unsigned int v107; // r3
  char v108; // r3
  unsigned int v109; // r4
  int v110; // r4
  int *v111; // r5
  int *v112; // r1
  unsigned int v113; // r6
  int v114; // r2
  int v115; // t1
  int v116; // [sp+8h] [bp-78h]
  unsigned int v117; // [sp+Ch] [bp-74h]
  unsigned int v118; // [sp+10h] [bp-70h]
  int v119; // [sp+14h] [bp-6Ch]
  unsigned int v120; // [sp+18h] [bp-68h]
  unsigned int v121; // [sp+1Ch] [bp-64h]
  unsigned int *v122; // [sp+20h] [bp-60h] BYREF
  unsigned int v123; // [sp+24h] [bp-5Ch]
  unsigned int *v124; // [sp+28h] [bp-58h]
  unsigned int v125; // [sp+2Ch] [bp-54h]
  unsigned int v126; // [sp+30h] [bp-50h] BYREF
  unsigned __int16 v127; // [sp+34h] [bp-4Ch]
  unsigned __int16 v128; // [sp+36h] [bp-4Ah]
  int v129; // [sp+38h] [bp-48h]
  int v130; // [sp+3Ch] [bp-44h]
  int v131; // [sp+40h] [bp-40h] BYREF
  int v132; // [sp+44h] [bp-3Ch]
  int v133; // [sp+48h] [bp-38h]
  int v134; // [sp+4Ch] [bp-34h]
  int v135; // [sp+50h] [bp-30h]
  int v136; // [sp+54h] [bp-2Ch]
  int *v137; // [sp+58h] [bp-28h]
  int v138; // [sp+5Ch] [bp-24h]
  int v139; // [sp+60h] [bp-20h]
  unsigned int varg_r0; // [sp+88h] [bp+8h]
  _DWORD *varg_r1; // [sp+8Ch] [bp+Ch]
  int varg_r2; // [sp+90h] [bp+10h]
  int varg_r3; // [sp+94h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v7 = *a2;
  v120 = *a2;
  v134 = a4;
  v131 = a3;
  v118 = (unsigned int)a2;
  v125 = a1;
  v116 = 0;
  v9 = 2;
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_BYTE *)(v10 + 0x3C8);
  v139 = v10;
  if ( (v11 & 4) != 0 )
    return sub_53A3C0();
  v13 = a6;
  v138 = a6 & 1;
  if ( (a6 & 1) != 0 && *(_BYTE *)(a6 & 0xFFFFFFFE) == 2 )
  {
    v13 = a6;
    v116 = a6 & 0xFFFFFFFE;
  }
  else if ( (a6 & 1) != 0 && *(_BYTE *)(a6 & 0xFFFFFFFE) == 1 )
  {
    v116 = a6 & 0xFFFFFFFE;
    if ( (v7 & 0x800) != 0 || (v7 & 0x10) == 0 )
      return 0;
    if ( (*(_DWORD *)((a6 & 0xFFFFFFFE) + 40) & 0x200) != 0 && ((v7 >> 2) & 1) == dword_63F99C )
    {
      if ( a4 == 1 )
        MiUnlockProtoPoolPage(a5, 17);
      return 0;
    }
    v9 = 0;
  }
  v14 = 1;
  v15 = *(_DWORD *)(v10 + 116);
  v124 = 0;
  v16 = 16;
  v132 = 0;
  v133 = 2;
  v129 = 1;
  v137 = a2;
  v126 = 16;
  if ( (unsigned int)a2 < 0xC0000000 || (unsigned int)a2 > 0xC03FFFFF )
  {
    v123 = 16;
    if ( (*(_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000) & 0xFFFFE000) == -8192
      || (v99 = (*(_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000) & 0x1FC | (*(_DWORD *)(((a1 >> 10) & 0x3FFFFC)
                                                                                        - 0x40000000) >> 2) & 0x3FFFFE00)
              - 0x40000000,
          v99 < dword_640484)
      || v99 >= dword_640488 )
    {
      v100 = 16;
    }
    else
    {
      v100 = 48;
      v123 = 48;
    }
    if ( (v100 & 0x20) != 0 || *(_DWORD *)(v15 + 272) )
      v16 = 1;
    v126 = v16;
  }
  else
  {
    v123 = (unsigned __int8)v132;
  }
  v17 = MiComputeFaultNode(v131, a1, 0, v13, &v122);
  v18 = v122;
  v130 = 524286;
  v135 = v17;
  if ( (v122
     || v15 == PsInitialSystemProcess
     && v118 <= (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000
     && v118 >= 0xC0000000
     && (v18 = MiLocateAddress(v125), (v122 = v18) != 0))
    && (v18[8] & 0x7FFFFFFF) == v130 )
  {
    v19 = 7;
    v133 = 7;
    v123 = (unsigned __int8)v123 | 0x80;
  }
  else
  {
    v19 = 2;
  }
  v136 = (v120 >> 11) & 1;
  if ( v136 )
  {
    v16 = 1;
    v20 = MmPfnDatabase + 24 * (v120 >> 12);
    v21 = *(_DWORD *)(v20 + 8);
    v126 = 1;
    v133 = v19 | 1;
  }
  else
  {
    v20 = 0;
    v21 = v120;
  }
  v121 = v21;
  if ( (v21 & 0x10) != 0 )
    v22 = ((v21 >> 2) & 1) == dword_63F99C;
  else
    v22 = 0;
  v23 = v22;
  v117 = v23;
  if ( v16 == 1 )
    goto LABEL_19;
  if ( dword_6348DC )
  {
    --dword_6348DC;
    v16 = 1;
    goto LABEL_93;
  }
  if ( v116 )
  {
    if ( ((v123 >> 4) & 1) == 1 )
    {
      if ( !v18 )
      {
        v18 = MiLocateAddress(v125);
        LOBYTE(v23) = v117;
        v122 = v18;
      }
      v104 = (int)v18;
    }
    else
    {
      v104 = 0;
    }
    v24 = (_BYTE *)v116;
    v16 = MiComputeFaultCluster((int)MiSystemPartition, v116, v104, v23 & 1);
    LOBYTE(v23) = v117;
    v126 = v16;
    goto LABEL_20;
  }
  if ( v125 > MmHighestUserAddress )
  {
    v16 = 1;
    v126 = 1;
    if ( (v123 & 0x10) == 0 && (v125 < 0xC0000000 || v125 > 0xC03FFFFF) )
    {
      v23 |= 4u;
      v117 = v23;
      v16 = 16;
LABEL_93:
      v126 = v16;
      goto LABEL_19;
    }
  }
LABEL_19:
  v24 = (_BYTE *)v116;
LABEL_20:
  v25 = v23 & 1;
  if ( (v23 & 1) != 0 && v16 > dword_63F9A4 )
    v126 = dword_63F9A4;
  if ( a5 )
    v26 = &a5;
  else
    v26 = 0;
  v27 = MiAllocateInPageSupport(v118, v9, &v126, v26);
  v28 = v27;
  v119 = v27;
  if ( !v27 )
  {
    v106 = -1073741670;
LABEL_193:
    if ( v24 )
    {
      if ( v106 == -1073741670 )
        v108 = 2;
      else
        v108 = 1;
      v24[1] = v108;
    }
    return v106;
  }
  if ( *(_DWORD *)v118 != v120
    || ((v120 >> 11) & 1) != 0
    && ((v107 = *(unsigned __int8 *)(v20 + 18), ((v107 >> 5) & 1) == 0)
     || (v107 & 8) != 0
     || v21 != *(_DWORD *)(v20 + 8)
     || (*(_BYTE *)(*(_DWORD *)v20 + 97) & 0x10) != 0) )
  {
    v106 = -1073740748;
    if ( v134 == 1 )
      MiUnlockProtoPoolPage(a5, 17);
    MiFreeInPageSupportBlock(v28);
    goto LABEL_193;
  }
  if ( v24 && *v24 == 1 )
  {
    v29 = v116;
    MiSetInPagePrefetchPriority(v116, v27);
  }
  else
  {
    v29 = v116;
  }
  v30 = v126;
  if ( v126 <= 1 || (unsigned int)dword_640580 <= 0x100 )
    goto LABEL_95;
  v31 = (v118 >> 2) & 0x3FF;
  v32 = 1023 - v31;
  if ( (v123 & 0x10) != 0 )
  {
    v102 = v122;
    if ( (v122 || (v102 = MiLocateAddress(v125)) != 0)
      && (v102[7] & 0x8000) == 0
      && (MiGetProtoPteAddress(v102, v125 >> 12, 0, &v122), v122)
      && (*((_WORD *)v122 + 9) & 2) == 0 )
    {
      v103 = v122[1];
      if ( ((int)(v103 + 4 * v122[7] - v118) >> 2) - 1 < v32 )
        v32 = ((int)(v103 + 4 * v122[7] - v118) >> 2) - 1;
      if ( (int)(v118 - v103) >> 2 < v31 )
        v31 = (int)(v118 - v103) >> 2;
    }
    else
    {
      v30 = 1;
    }
  }
  if ( (v29 || (v117 & 4) != 0) && (v31 = 0, !v32) || v30 <= 1 )
  {
LABEL_95:
    v45 = (unsigned int *)v118;
    v51 = v121;
    v52 = 0;
  }
  else
  {
    v33 = v30 - 1;
    v34 = (int *)v118;
    v35 = (int *)(v118 + 4);
    if ( v32 > v33 )
      v32 = v33;
    v36 = (unsigned int *)(v120 >> 13);
    v122 = (unsigned int *)(v120 >> 13);
    if ( (v120 >> 13) + v32 >= 0x7FFFF )
      v32 = v130 - (_DWORD)v36;
    if ( v29 || v25 )
    {
      v37 = v117 | 8;
      v117 |= 8u;
    }
    else
    {
      v37 = v117;
    }
    v38 = v120 & 0xFFFFFC17;
    v130 = v120 & 0xFFFFFC17;
    v39 = v120 & 0xFFFFFC17;
    if ( v32 )
    {
      do
      {
        v39 = v39 & 0x1FFF ^ ((v39 & 0xFFFFE000) + 0x2000);
        v41 = *v35++;
        v40 = v41;
        if ( (v41 & 0x3E0) != 0 && (v40 & 0xFFFFFC17) == v39 )
        {
          v34 = v35 - 1;
        }
        else if ( (v37 & 8) != 0 )
        {
          break;
        }
        --v32;
      }
      while ( v32 );
      v38 = v130;
      v36 = v122;
    }
    v42 = (int)((int)v34 - v118) >> 2;
    v43 = v42 + 1;
    v44 = v33 - v42;
    v45 = (unsigned int *)v118;
    if ( v31 > v44 )
      v31 = v44;
    v46 = v118;
    v47 = v118;
    if ( v31 > (unsigned int)v36 - 1 )
      v31 = (unsigned int)v36 - 1;
    if ( v31 )
    {
      do
      {
        v38 = v38 & 0x1FFF | (((v38 >> 13) - 1) << 13);
        v49 = *(_DWORD *)(v47 - 4);
        v47 -= 4;
        v48 = v49;
        if ( (v49 & 0x3E0) != 0 && (v48 & 0xFFFFFC17) == v38 )
        {
          v46 = v47;
        }
        else if ( (v117 & 8) != 0 )
        {
          break;
        }
        --v31;
      }
      while ( v31 );
      v45 = (unsigned int *)v118;
    }
    v50 = (int)((int)v45 - v46) >> 2;
    v51 = v120 - (v50 << 13);
    v14 = v50 + v43;
    v52 = &v45[-v50];
    v121 = v51;
    v129 = v50 + v43;
    v124 = v52;
  }
  v53 = MiObtainFaultCharges(MiSystemPartition, v14, v133);
  v54 = (unsigned int *)v53;
  v122 = (unsigned int *)v53;
  if ( v14 > v53 )
  {
    if ( &v52[v14 - v53] <= v45 )
    {
      v109 = v51 & 0x1FFF ^ ((v51 & 0xFFFFE000) + ((v14 - v53) << 13));
      v124 = &v52[v14 - v53];
    }
    else
    {
      v109 = v51 + ((v45 - v52) << 13);
      v124 = v45;
    }
    v55 = v53;
    v129 = v53;
    v121 = v109;
  }
  else
  {
    v55 = v129;
  }
  MI_INITIALIZE_COLOR_BASE(v131, v135, &v126);
  v56 = 0;
  v130 = 0;
  v57 = (unsigned __int16)(*(_WORD *)v126 + 1);
  v58 = v127;
  *(_WORD *)v126 = v57;
  v59 = v57 & v58 | v128;
  if ( v138 && *(_BYTE *)(a6 & 0xFFFFFFFE) == 4
    || v125 >= dword_63389C
    && *((_BYTE *)&MiState[2423] + ((int)(((v125 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) == 12
    || PsNtosImageBase
    && (v125 >= PsNtosImageBase && v125 < PsNtosImageEnd || v125 >= PsHalImageBase && v125 < PsHalImageEnd) )
  {
    v56 = 8;
    v130 = 8;
  }
  if ( v116
    && *(_BYTE *)v116 == 1
    && !MiGetAvailablePagesBelowPriority(MiSystemPartition, ((*(_DWORD *)(v116 + 40) >> 3) & 7) + 1)
    || (v60 = MiGetPage((int)MiSystemPartition, v59, v56), v131 = v60, v60 == -1) )
  {
    if ( v134 == 1 )
      MiUnlockProtoPoolPage(a5, 17);
    MiFreeInPageSupportBlock(v119);
    if ( v116 )
      *(_BYTE *)(v116 + 1) = 2;
    MiReturnFaultCharges(MiSystemPartition, v55, v133);
    return -1073741801;
  }
  v61 = v119;
  v62 = *(_BYTE *)(v119 + 114) & 7;
  if ( v55 == 1 )
  {
    v63 = v125;
    v64 = v123 & 0xF0 | v62 | 8;
    LOBYTE(v132) = v123 & 0xF0 | v62 | 8;
    v65 = 1;
    v66 = v119;
    MiInitializeReadInProgressPfn(v125, &v131, 1, v118, v119 + 16, v132);
    *(_WORD *)(v119 + 158) = 16450;
    v67 = v136;
    *(_DWORD *)(v119 + 172) = 4096;
    v68 = v131;
    *(_DWORD *)(v119 + 152) = 0;
    *(_WORD *)(v119 + 156) = 32;
    *(_DWORD *)(v119 + 168) = v63 & 0xFFFFF000;
    *(_DWORD *)(v119 + 176) = 0;
    *(_DWORD *)(v119 + 180) = v68;
    if ( v67 )
    {
      v110 = MmPfnDatabase + 24 * (v120 >> 12);
      MiFlowThroughInsertNode(v119, v110);
      v120 = *(_DWORD *)(v110 + 8);
    }
    goto LABEL_70;
  }
  v77 = (int *)(v119 + 180);
  v78 = 0;
  v79 = v121;
  v80 = (int *)(v119 + 180);
  v65 = 0;
  while ( 1 )
  {
    v81 = *v124;
    if ( (*v124 & 0xC02) != 0 )
      break;
    if ( ((v79 ^ v81) & 0xFFFFE000) != 0 )
      break;
    if ( (v81 & 0x10) == 0 )
      break;
    v82 = (v81 >> 2) & 1;
    if ( v82 != ((v79 >> 2) & 1) || (v82 == dword_63F99C) != (v117 & 1) )
      break;
    if ( v78 )
    {
      if ( v116
        && *(_BYTE *)v116 == 1
        && !MiGetAvailablePagesBelowPriority(MiSystemPartition, ((*(_DWORD *)(v116 + 40) >> 3) & 7) + 1) )
      {
        *v80 = -1;
LABEL_228:
        v61 = v119;
        v77 = (int *)(v119 + 180);
        if ( v116 )
          *(_BYTE *)(v116 + 1) = 2;
        v98 = v117;
        goto LABEL_231;
      }
      v83 = MiGetPage((int)MiSystemPartition, v59, v130);
      *v80 = v83;
      if ( v83 == -1 )
        goto LABEL_228;
      v84 = v124;
      v61 = v119;
      ++v65;
    }
    else
    {
      v84 = v124;
      *v80 = v60;
      ++v65;
    }
LABEL_110:
    v85 = MmPfnDatabase + 24 * *v80;
    if ( v84 == (unsigned int *)v118 )
      MiLockSetPfnPriority(v85, v62);
    else
      MiLockSetPfnPriority(v85, (*(unsigned __int8 *)(v61 + 114) >> 4) & 7);
LABEL_112:
    if ( v116 )
      MiAdvanceFaultList((_DWORD *)v116);
    v77 = (int *)(v119 + 180);
    v86 = v129;
    v87 = v84 + 1;
    v79 = v121 & 0x1FFF ^ ((v121 & 0xFFFFE000) + 0x2000);
    ++v78;
    ++v80;
    v121 = v79;
    v124 = v87;
    if ( v78 == v129 )
    {
      v89 = (unsigned int *)v118;
      goto LABEL_119;
    }
    v61 = v119;
    v88 = *(_WORD *)v126 + 1;
    *(_WORD *)v126 = v88;
    v59 = (unsigned __int16)(v88 & v127) | v128;
  }
  v98 = v117;
  if ( (v117 & 8) == 0 )
  {
    v84 = v124;
    v117 |= 2u;
    *v80 = dword_6348FC;
    goto LABEL_112;
  }
LABEL_231:
  v87 = v124;
  v89 = (unsigned int *)v118;
  if ( (unsigned int)v124 <= v118 )
  {
    v111 = v77;
    if ( v78 > 1 )
    {
      v112 = MiState;
      v113 = v78 - 1;
      do
      {
        v115 = v111[1];
        ++v111;
        v114 = v115;
        if ( v115 != v112[1951] )
        {
          MiReleaseFreshPage(MmPfnDatabase + 24 * v114);
          v112 = MiState;
          --v65;
        }
        --v113;
      }
      while ( v113 );
      v61 = v119;
      v77 = (int *)(v119 + 180);
      v98 = v117;
      v89 = (unsigned int *)v118;
    }
    v80 = v77;
    v78 = 0;
    v129 = 1;
    v117 = v98 & 0xFFFFFFFD;
    v84 = v89;
    goto LABEL_110;
  }
  v86 = v78;
  v129 = v78;
LABEL_119:
  v90 = (signed int)&v87[-v86];
  v68 = v77[((int)v89 - v90) >> 2];
  v91 = (v123 >> 4) & 1;
  if ( v91 == 1 )
    v92 = 0;
  else
    v92 = v90 << 10;
  v93 = v92 & 0xFFF;
  *(_DWORD *)(v119 + 152) = 0;
  *(_WORD *)(v119 + 156) = 4 * (((unsigned int)((v86 << 12) + v93 + 4095) >> 12) + 7);
  *(_WORD *)(v119 + 158) = 66;
  *(_DWORD *)(v119 + 168) = v92 & 0xFFFFF000;
  *(_DWORD *)(v119 + 172) = v86 << 12;
  *(_DWORD *)(v119 + 176) = v93;
  if ( (v117 & 2) != 0 )
  {
    v101 = MiReduceMdl(v119 + 152);
    v95 = v119;
    if ( v101 )
    {
      v90 += 4 * v101;
      if ( v91 != 1 )
        *(_DWORD *)(v119 + 168) += v101 << 12;
    }
    v94 = *(_DWORD *)(v119 + 172) >> 12;
  }
  else
  {
    v94 = v129;
    *(_WORD *)(v119 + 158) = 16450;
    v95 = v119;
  }
  v96 = v95 + 16;
  v118 = v90;
  v120 = *(_DWORD *)v90;
  v97 = v90;
  v66 = v119;
  v64 = v123 & 0xDF;
  LOBYTE(v132) = v123 & 0xDF;
  MiInitializeReadInProgressPfn(v125, (_DWORD *)(v119 + 180), v94, v97, v96, v123 & 0xDF);
  v54 = v122;
LABEL_70:
  v69 = (v64 >> 4) & 1;
  v70 = a5;
  if ( v69 == 1 )
    MiObtainProtoReference(a5, 0);
  v71 = *v137;
  *(_DWORD *)(v66 + 132) = v137;
  *(_DWORD *)(v66 + 96) = v71;
  if ( v116 )
  {
    if ( *(_BYTE *)v116 == 1 )
    {
      v105 = *(_BYTE *)(v66 + 113) | 4;
      *(_BYTE *)(v66 + 113) = v105;
      if ( (*(_DWORD *)(v116 + 40) & 0x2000) != 0 )
        *(_BYTE *)(v66 + 113) = v105 | 0x10;
    }
  }
  v72 = v139;
  if ( ((*(_DWORD *)(*(_DWORD *)(v139 + 336) + 192) & 0x100000) != 0 || ((*(_DWORD *)(v139 + 960) >> 9) & 7u) < 2)
    && (v72 != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) || !*(_DWORD *)(v72 + 1000)) )
  {
    *(_BYTE *)(v66 + 113) |= 0x40u;
  }
  if ( v134 == 1 )
    MiUnlockProtoPoolPage(v70, 17);
  if ( (unsigned int *)v65 != v54 )
    MiReturnFaultCharges(MiSystemPartition, (int)v54 - v65, v133);
  *a7 = v66;
  v73 = (v120 >> 2) & 1;
  if ( (v120 & 0x10) != 0 )
    v74 = v120 >> 13;
  else
    v74 = 0;
  v75 = *(_DWORD *)&MiSystemPartition[2 * v73 + 1800];
  if ( v69 == 1 )
    *(_DWORD *)(v66 + 92) = v70;
  if ( (v117 & 1) != 0 )
  {
    *(_DWORD *)(v66 + 56) = v74 & 0xFFFFFFF | (v73 << 28);
    *(_DWORD *)(v66 + 60) = 0;
    *(_BYTE *)(v66 + 113) |= 0x80u;
  }
  else
  {
    *(_DWORD *)(v66 + 56) = v74 << 12;
    *(_DWORD *)(v66 + 60) = 0;
  }
  *(_DWORD *)(v66 + 116) = *(_DWORD *)(v75 + 32);
  v76 = *(_BYTE *)(v66 + 115) | 0x10;
  *(_BYTE *)(v66 + 115) = v76;
  if ( *(_DWORD *)(v75 + 108)
    && (!v116 || *(_BYTE *)v116 != 1 || (*(_DWORD *)(v116 + 40) & 0x1000) == 0 || (dword_681260 & 1) != 0) )
  {
    *(_BYTE *)(v66 + 115) = v76 | 0x20;
  }
  result = -1073532109;
  *(_DWORD *)(v66 + 136) = v118;
  *(_DWORD *)(v66 + 140) = MmPfnDatabase + 24 * v68;
  return result;
}
