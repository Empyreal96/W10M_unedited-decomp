// MiFreeWsleList 
 
int __fastcall MiFreeWsleList(int a1, unsigned int *a2, int a3)
{
  unsigned int *v3; // r6
  unsigned int v4; // r3
  int v5; // r4
  int v6; // r7
  int v7; // r5
  unsigned int v9; // r10
  unsigned int v10; // r1
  unsigned int *v11; // r8
  unsigned int v12; // r6
  int v13; // r7
  unsigned int v14; // lr
  unsigned int v15; // r9
  unsigned int v16; // r5
  int v17; // r4
  int v18; // r0
  int v19; // r10
  unsigned int v20; // r9
  unsigned int v21; // r6
  int v22; // r1
  int v23; // r3
  int v24; // r7
  int v25; // r0
  unsigned int v26; // r6
  unsigned int v27; // r1
  unsigned int v28; // r2
  int v29; // r2
  int v30; // r3
  unsigned int *v31; // r2
  unsigned int v32; // r0
  unsigned __int8 *v33; // r1
  unsigned int v34; // r3
  int v35; // r2
  unsigned int v36; // r7
  __int16 *v37; // r8
  unsigned int *v38; // r2
  unsigned int v39; // r5
  int v40; // r7
  _DWORD *v41; // r5
  int v42; // r4
  unsigned int v43; // r0
  unsigned int *v44; // r4
  unsigned int v45; // r5
  unsigned int v46; // r3
  unsigned int v47; // r0
  unsigned int v48; // r2
  unsigned int v49; // r1
  int v50; // r1
  unsigned int v51; // r5
  int v52; // r7
  unsigned __int8 *v53; // r3
  unsigned int v54; // r1
  unsigned int v55; // r5
  int v56; // r1
  int v57; // r2
  int v58; // r3
  int v59; // r2
  int v60; // r3
  bool v61; // zf
  int v62; // r3
  int v63; // r1
  unsigned int v64; // r0
  unsigned int v65; // r2
  int v66; // r8
  int v67; // r5
  unsigned int v68; // r10
  int v69; // r0
  int v70; // r1
  unsigned int v71; // r7
  unsigned int v72; // r2
  unsigned int v73; // r9
  unsigned int *v74; // r1
  unsigned int v75; // r3
  int v76; // r5
  unsigned int v77; // r5
  unsigned int v78; // r2
  unsigned int v79; // r3
  _DWORD *v80; // r1
  int v81; // r7
  unsigned int v82; // r8
  unsigned __int8 *v83; // r3
  unsigned int v84; // r1
  unsigned int *v85; // r2
  unsigned int v86; // r0
  char v87; // r3
  char v88; // r3
  int v89; // r3
  int v90; // r3
  int v91; // r2
  __int64 v92; // kr00_8
  int v93; // r2
  unsigned int *v94; // lr
  unsigned int *v95; // r2
  unsigned int v96; // r0
  int v97; // r2
  unsigned int v98; // r5
  char v99; // r3
  char v100; // r0
  int v101; // r1
  int v102; // r3
  unsigned int *v103; // r2
  unsigned int v104; // r0
  unsigned __int8 *v105; // r3
  unsigned int v106; // r2
  unsigned __int8 *v107; // r3
  unsigned int v108; // r1
  unsigned __int8 *v109; // r1
  int v110; // r3
  unsigned int v111; // r2
  unsigned int *v112; // r2
  unsigned int v113; // r0
  unsigned int *v114; // r2
  unsigned int v115; // r0
  int v116; // r0
  unsigned __int8 *v117; // r1
  int v118; // r3
  unsigned int v119; // r2
  unsigned __int8 *v120; // r1
  int v121; // r3
  unsigned int v122; // r2
  char v123; // r2
  int v124; // r0
  int v125; // r0
  int v126; // r0
  char v127; // r3
  unsigned __int8 *v128; // r1
  int v129; // r3
  unsigned int v130; // r2
  unsigned __int8 *v131; // r1
  int v132; // r3
  unsigned int v133; // r2
  unsigned int v134; // [sp+Ch] [bp-224h]
  int v135; // [sp+14h] [bp-21Ch]
  int v136; // [sp+18h] [bp-218h]
  unsigned int v137; // [sp+1Ch] [bp-214h]
  __int16 *v138; // [sp+1Ch] [bp-214h]
  unsigned int v140; // [sp+24h] [bp-20Ch]
  int v141; // [sp+28h] [bp-208h]
  unsigned int v142; // [sp+30h] [bp-200h]
  unsigned int v144; // [sp+44h] [bp-1ECh]
  int v145; // [sp+48h] [bp-1E8h]
  int v146; // [sp+4Ch] [bp-1E4h]
  int v148; // [sp+60h] [bp-1D0h] BYREF
  char v149; // [sp+64h] [bp-1CCh]
  char v150; // [sp+65h] [bp-1CBh]
  int v151; // [sp+68h] [bp-1C8h]
  int v152; // [sp+6Ch] [bp-1C4h]
  int v153; // [sp+70h] [bp-1C0h]
  int v154; // [sp+74h] [bp-1BCh]
  int v155; // [sp+F8h] [bp-138h] BYREF
  char v156; // [sp+FCh] [bp-134h]
  char v157; // [sp+FDh] [bp-133h]
  int v158; // [sp+100h] [bp-130h]
  int v159; // [sp+104h] [bp-12Ch]
  int v160; // [sp+108h] [bp-128h]
  int v161; // [sp+10Ch] [bp-124h]
  _DWORD v162[40]; // [sp+190h] [bp-A0h]

  v3 = a2;
  v4 = *(_BYTE *)(a1 + 112) & 7;
  v141 = 0;
  if ( (*(_BYTE *)(a1 + 112) & 7) != 0 )
  {
    if ( v4 < 2 )
      v5 = 2;
    else
      v5 = 0;
  }
  else
  {
    v5 = 1;
  }
  v152 = 0;
  v150 = 0;
  v154 = 0;
  v6 = *(_DWORD *)(a1 + 92);
  v149 = 0;
  v148 = v5;
  v153 = 0;
  v151 = 33;
  v7 = *(_DWORD *)(v6 + 252);
  v146 = a1 - 492;
  v135 = v6;
  v136 = v7;
  if ( !v4 && *(_QWORD *)(v6 + 320) )
    return sub_5321C0();
  v9 = 0;
  v144 = 0;
  do
  {
    v10 = 0;
    v134 = 0;
    if ( *v3 )
    {
      while ( 1 )
      {
        v11 = &v3[v10];
        v12 = v11[1];
        if ( v12 )
          break;
LABEL_68:
        v3 = a2;
        ++v10;
        v9 = v144;
        v134 = v10;
        if ( v10 >= *a2 )
          goto LABEL_69;
      }
      v13 = v12 * *(_DWORD *)(v6 + 36);
      v14 = *(_DWORD *)(v13 + v7);
      v15 = ((v14 >> 10) & 0x3FFFFC) - 0x40000000;
      v137 = v15;
      v140 = v14;
      if ( v9 )
        v16 = v162[v10];
      else
        v16 = *(_DWORD *)v15;
      v17 = MmPfnDatabase + 24 * (v16 >> 12);
      if ( v9 )
      {
        v52 = 0;
        if ( (v16 & 0x10) == 0 )
          goto LABEL_75;
        if ( (*(_DWORD *)(v17 + 20) & 0x8000000) != 0 )
        {
          v52 = MmPfnDatabase + 24 * (v16 >> 12);
          v107 = (unsigned __int8 *)(v17 + 15);
          do
            v108 = __ldrex(v107);
          while ( __strex(v108 | 0x80, v107) );
          __dmb(0xBu);
          if ( v108 >> 7 )
          {
            v117 = (unsigned __int8 *)(v17 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v118 = *(_DWORD *)(v17 + 12);
                __dmb(0xBu);
              }
              while ( (v118 & 0x80000000) != 0 );
              do
                v119 = __ldrex(v117);
              while ( __strex(v119 | 0x80, v117) );
              __dmb(0xBu);
            }
            while ( v119 >> 7 );
          }
        }
        if ( MiConfirmPageIsZero(v17, a3) == 1 )
        {
          if ( (*(_DWORD *)(v17 + 20) & 0x8000000) == 0 && (*(_BYTE *)(a1 + 112) & 7) == 0 )
          {
            v95 = (unsigned int *)(v146 + 276);
            do
              v96 = __ldrex(v95);
            while ( __strex(v96 - 1, v95) );
          }
        }
        else
        {
          LOWORD(v16) = v16 & 0xFFEF;
        }
        if ( !v52 )
        {
LABEL_75:
          v53 = (unsigned __int8 *)(v17 + 15);
          do
            v54 = __ldrex(v53);
          while ( __strex(v54 | 0x80, v53) );
          __dmb(0xBu);
          if ( v54 >> 7 )
          {
            v120 = (unsigned __int8 *)(v17 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v121 = *(_DWORD *)(v17 + 12);
                __dmb(0xBu);
              }
              while ( (v121 & 0x80000000) != 0 );
              do
                v122 = __ldrex(v120);
              while ( __strex(v122 | 0x80, v120) );
              __dmb(0xBu);
            }
            while ( v122 >> 7 );
          }
        }
        v142 = 0;
        v138 = 0;
        if ( (v16 & 0x30) != 0 )
        {
          v97 = ((v15 >> 10) & 0x3FFFFC) - 0x40000000;
          v98 = *(_DWORD *)v97;
          if ( (*(_DWORD *)v97 & 2) == 0 )
            KeBugCheckEx(26, 399680, v97 << 10);
          v99 = *(_BYTE *)(v17 + 19);
          v100 = *(_BYTE *)(v17 + 18) & 0xC7;
          v101 = *(_DWORD *)(v17 + 12);
          *(_DWORD *)(v17 + 20) &= 0xF7FFFFFF;
          *(_BYTE *)(v17 + 18) = v100;
          *(_WORD *)(v17 + 16) = 0;
          *(_BYTE *)(v17 + 19) = v99 & 0xDF;
          *(_DWORD *)(v17 + 12) = v101 & 0xC0000000;
          v102 = *(_DWORD *)(v17 + 8);
          if ( (v102 & 0x10) != 0 )
            v36 = v102 & 0xFFFFFFF7;
          else
            v36 = 0;
          if ( v36 )
            v37 = MiSystemPartition;
          else
            v37 = 0;
          MiInsertPageInFreeOrZeroedList((v17 - MmPfnDatabase) / 24, 1);
          __dmb(0xBu);
          v103 = (unsigned int *)(v17 + 12);
          do
            v104 = __ldrex(v103);
          while ( __strex(v104 & 0x7FFFFFFF, v103) );
          v17 = MmPfnDatabase + 24 * (v98 >> 12);
          v105 = (unsigned __int8 *)(v17 + 15);
          do
            v106 = __ldrex(v105);
          while ( __strex(v106 | 0x80, v105) );
          __dmb(0xBu);
          if ( v106 >> 7 )
          {
            v131 = (unsigned __int8 *)(v17 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v132 = *(_DWORD *)(v17 + 12);
                __dmb(0xBu);
              }
              while ( (v132 & 0x80000000) != 0 );
              do
                v133 = __ldrex(v131);
              while ( __strex(v133 | 0x80, v131) );
              __dmb(0xBu);
            }
            while ( v133 >> 7 );
          }
          if ( (*(_BYTE *)(v17 + 18) & 7) != 6 )
            KeBugCheckEx(78, 153, (v17 - MmPfnDatabase) / 24);
          if ( !MiUpdateShareCount(v17, -1) )
            MiPfnShareCountIsZero(v17, 0);
        }
        else
        {
          if ( (v16 & 0x200) == 0 )
          {
            v64 = 0;
            v142 = 0;
            if ( (*(_BYTE *)(v17 + 18) & 0x10) == 0 )
            {
              v90 = *(_DWORD *)(v17 + 8);
              if ( (v90 & 0x400) == 0 && (*(_BYTE *)(v17 + 18) & 8) == 0 )
              {
                v91 = *(_DWORD *)(v17 + 8);
                if ( (v90 & 0x10) != 0 )
                {
                  *(_DWORD *)(v17 + 8) = v90 & 0xFFFFFFEF;
                  v64 = v91 & 0xFFFFFFF7;
                }
                else
                {
                  v64 = 0;
                }
                v142 = v64;
              }
              *(_BYTE *)(v17 + 18) |= 0x10u;
            }
            if ( v64 )
              v138 = MiSystemPartition;
          }
          v55 = *(_DWORD *)(v17 + 20);
          v56 = (v55 >> 27) & 1;
          if ( v56 )
          {
            v57 = ((v15 >> 10) & 0x3FFFFC) - 0x40000000;
            if ( (*(_DWORD *)v57 & 2) == 0 )
              KeBugCheckEx(26, 399680, v57 << 10);
            v58 = *(_DWORD *)v57 >> 12;
          }
          else
          {
            v58 = -1;
          }
          v145 = v58;
          if ( (a3 & 1) != 0
            && (*(_DWORD *)(v17 + 12) & 0x3FFFFFFF) == 1
            && *(_WORD *)(v17 + 16) == 1
            && (*(_BYTE *)(v17 + 18) & 0x10) == 0 )
          {
            v123 = *(_BYTE *)(v17 + 19);
            if ( (v123 & 8) != 0 || (v123 & 7) == 5 )
              *(_BYTE *)(v17 + 19) = v123 & 0xF8 | 4;
          }
          if ( (*(_BYTE *)(v17 + 18) & 7) != 6 )
            KeBugCheckEx(78, 153, (v17 - MmPfnDatabase) / 24);
          v59 = *(_DWORD *)(v17 + 12);
          *(_DWORD *)(v17 + 12) = v59 & 0xC0000000 | ((v59 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
          if ( (v59 & 0x3FFFFFFF) == 1 )
          {
            if ( v56 )
            {
              v65 = *(_DWORD *)(v17 + 8);
              if ( (v65 & 0x400) != 0 )
                v66 = (*(unsigned __int16 *)((*(_DWORD *)(v17 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v17 + 8) & 0x3FC)))
                                           + 0x10) >> 1) & 0x1F;
              else
                v66 = (v65 >> 5) & 0x1F;
              v67 = v55 & 0xFFFFF;
              v68 = *(_DWORD *)(v17 + 4) | 0x80000000;
              v69 = 4;
              v70 = *(unsigned __int8 *)(MmPfnDatabase + 24 * v67 + 18) >> 6;
              if ( !v70 || v70 == 3 )
              {
                v69 = 12;
              }
              else if ( v70 == 2 )
              {
                v69 = 28;
              }
              v71 = (MmProtectToPteMask[v69] & 0xFED | (v67 << 12) | 0x12) & 0xFFFFF1FF;
              v72 = (unsigned int)KeGetPcr();
              v73 = (*(_DWORD *)((v72 & 0xFFFFF000) + 0x1384) & 0xFFFFF000)
                  + ((*(_DWORD *)((v72 & 0xFFFFF000) + 0x1384) & 0xFFF) << 12);
              v74 = (unsigned int *)(((v73 >> 10) & 0x3FFFFC) - 0x40000000);
              v75 = *v74;
              v76 = 0;
              __dmb(0xBu);
              if ( (v75 & 2) == 0 )
                v76 = 1;
              *v74 = v71;
              if ( (unsigned int)v74 >= 0xC0300000 && (unsigned int)v74 <= 0xC0300FFF )
              {
                v124 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                MiArmWriteConvertedHardwarePde(v124, v124 + 4 * ((v73 >> 10) & 0xFFC), v71);
              }
              if ( v76 == 1 )
              {
                __dsb(0xFu);
                __isb(0xFu);
              }
              v77 = v73 + 4 * ((v68 >> 2) & 0x3FF);
              v78 = *(_DWORD *)v77 & 0xFFFFF81C | (32 * (v66 & 0x1F | 0x40));
              if ( v77 < 0xC0000000 || v77 > 0xC03FFFFF )
              {
                *(_DWORD *)v77 = v78;
              }
              else
              {
                __dmb(0xBu);
                *(_DWORD *)v77 = v78;
                if ( v77 + 1070596096 <= 0xFFF )
                {
                  v125 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                  MiArmWriteConvertedHardwarePde(v125, v125 + 4 * (v77 & 0xFFF), v78);
                }
              }
              v79 = (unsigned int)KeGetPcr();
              v80 = (_DWORD *)((((v77 & 0xFFFFF000) >> 10) & 0x3FFFFC) - 0x40000000);
              v81 = (*(_DWORD *)((v79 & 0xFFFFF000) + 0x1384) & 0xFFF) + 1;
              v82 = *(_DWORD *)((v79 & 0xFFFFF000) + 0x1384) & 0xFFFFF000;
              __dmb(0xBu);
              *v80 = 0;
              if ( (unsigned int)v80 >= 0xC0300000 && (unsigned int)v80 <= 0xC0300FFF )
              {
                v126 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                MiArmWriteConvertedHardwarePde(v126, v126 + 4 * (((v77 & 0xFFFFF000) >> 10) & 0xFFC), 0);
              }
              if ( v81 == 16 )
              {
                v159 = 0;
                v160 = 0;
                v155 = 0;
                v158 = 33;
                v156 = 1;
                v157 = 0;
                v161 = 0;
                MiInsertTbFlushEntry(&v155, v82, 16);
                MiFlushTbList(&v155);
                *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384) = v82;
              }
              else
              {
                *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384) = v81 | v82;
              }
            }
            v60 = (unsigned __int16)(*(_WORD *)(v17 + 16) - 1);
            *(_WORD *)(v17 + 16) = v60;
            v61 = v60 == 0;
            v62 = *(_DWORD *)(v17 + 12);
            if ( v61 )
            {
              if ( (v62 & 0x40000000) != 0 )
              {
                if ( (*(_BYTE *)(v17 + 19) & 0x10) != 0 )
                  *(_BYTE *)(v17 + 19) &= 0xEFu;
                MiReleasePageFileSpace(MiSystemPartition, *(_DWORD *)(v17 + 8), 1);
                MiInsertPageInFreeOrZeroedList((v17 - MmPfnDatabase) / 24, 2);
              }
              else
              {
                if ( (*(_BYTE *)(v17 + 18) & 0x10) != 0 )
                {
                  v63 = 8;
                }
                else
                {
                  *(_BYTE *)(v17 + 18) = *(_BYTE *)(v17 + 18) & 0xF8 | 2;
                  v63 = 4;
                }
                MiInsertPageInList(v17, v63);
              }
            }
            else
            {
              v61 = (v62 & 0x40000000) == 0;
              v87 = *(_BYTE *)(v17 + 18);
              if ( v61 )
              {
                v61 = (v87 & 0x10) == 0;
                v88 = v87 & 0xF8;
                if ( v61 )
                  v127 = v88 | 2;
                else
                  v127 = v88 | 3;
              }
              else
              {
                v127 = v87 | 7;
              }
              *(_BYTE *)(v17 + 18) = v127;
              v89 = *(_DWORD *)(v17 + 8);
              if ( (v89 & 0x400) == 0 && (v89 & 0x10) != 0 )
                byte_63F87E = 1;
            }
          }
          if ( v145 != -1 )
          {
            __dmb(0xBu);
            v31 = (unsigned int *)(v17 + 12);
            do
              v32 = __ldrex(v31);
            while ( __strex(v32 & 0x7FFFFFFF, v31) );
            v17 = MmPfnDatabase + 24 * v145;
            v33 = (unsigned __int8 *)(v17 + 15);
            do
              v34 = __ldrex(v33);
            while ( __strex(v34 | 0x80, v33) );
            __dmb(0xBu);
            if ( v34 >> 7 )
            {
              v128 = (unsigned __int8 *)(v17 + 15);
              do
              {
                do
                {
                  __dmb(0xAu);
                  __yield();
                  v129 = *(_DWORD *)(v17 + 12);
                  __dmb(0xBu);
                }
                while ( (v129 & 0x80000000) != 0 );
                do
                  v130 = __ldrex(v128);
                while ( __strex(v130 | 0x80, v128) );
                __dmb(0xBu);
              }
              while ( v130 >> 7 );
            }
            if ( (*(_BYTE *)(v17 + 18) & 7) != 6 )
              KeBugCheckEx(78, 153, (v17 - MmPfnDatabase) / 24);
            v35 = *(_DWORD *)(v17 + 12);
            *(_DWORD *)(v17 + 12) = v35 & 0xC0000000 | ((v35 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
            if ( (v35 & 0x3FFFFFFF) == 1 )
              MiPfnShareCountIsZero(v17, 0);
          }
          v36 = v142;
          v37 = v138;
        }
        __dmb(0xBu);
        v38 = (unsigned int *)(v17 + 12);
        do
          v39 = __ldrex(v38);
        while ( __strex(v39 & 0x7FFFFFFF, v38) );
        if ( v36 )
          MiReleasePageFileInfo(v37, v36, 1);
        v40 = a1;
        v41 = *(_DWORD **)(a1 + 92);
        if ( v12 > v41[4] )
          KeBugCheckEx(26, 268165, v41);
        v42 = *(_DWORD *)(v41[9] * v12 + v41[63]);
        if ( (v42 & 1) == 0 )
          KeBugCheckEx(26, 20496, *(_DWORD *)(a1 + 92));
        v43 = v42 & 0xFFFFF000;
        if ( (int *)a1 == &dword_634F00 )
        {
          if ( PsNtosImageBase
            && (v43 >= PsNtosImageBase && v43 < PsNtosImageEnd || v43 >= PsHalImageBase && v43 < PsHalImageEnd) )
          {
            --dword_632F50;
          }
          else if ( v43 >= dword_63389C
                 && *((_BYTE *)&MiState[2423]
                    + ((int)(((v43 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) == 12 )
          {
            --dword_632F54;
          }
        }
        if ( (v42 & 8) == 0 && (v42 & 4) != 0 )
          MiUpdateWsleHash(v43, v12, a1, 1);
        if ( (dword_682604 & 0x8000000) != 0 )
          MiLogRemoveWsleEvent(v42, *(_BYTE *)(a1 + 112) & 7);
        *(_DWORD *)(v41[9] * v12 + v41[63]) = v42 & 0xFFFFFFFE;
        v44 = *(unsigned int **)(a1 + 92);
        v45 = v44[1];
        if ( v12 >= v45 )
        {
          v46 = v44[9];
          v47 = v44[63];
          v48 = v47 + v46 * v12;
          v49 = *(_DWORD *)v48;
          if ( v46 == 16 && (int)(16 * v12) >> 4 >= v45 )
          {
            v92 = *(_QWORD *)(v48 + 4);
            v93 = 2 * ((v49 >> 9) & 7);
            if ( v49 < 0xC0000000 || v49 > 0xC03FFFFF )
              ++v93;
            v94 = &v44[2 * v93];
            if ( HIDWORD(v92) == 0xFFFFF )
              v94[31] = v92;
            else
              *(_DWORD *)(v47 + 16 * HIDWORD(v92) + 4) = v92;
            if ( (_DWORD)v92 == 0xFFFFF )
              v94[32] = HIDWORD(v92);
            else
              *(_DWORD *)(v47 + 16 * v92 + 8) = HIDWORD(v92);
            v40 = a1;
            --v44[v93 + 15];
          }
          v50 = (v49 >> 9) & 7;
          if ( v50 )
          {
            --*(_DWORD *)(v40 + 4 * (v50 - 1) + 20);
            if ( v50 == 7 )
              MiVolunteerForTrimFirst(v40, -1);
          }
        }
        v51 = *v44;
        if ( *v44 != 0xFFFFF )
        {
          if ( v51 < v44[1] || v51 > v44[4] )
            KeBugCheckEx(26, 20484, v44);
          *(_DWORD *)(v51 * v44[9] + v44[63]) ^= (*(_DWORD *)(v51 * v44[9] + v44[63]) ^ (2 * v12)) & 0xFFE;
        }
        *(_DWORD *)(v44[9] * v12 + v44[63]) = (v51 << 12) | 0xFFE;
        *v44 = v12;
        --*(_DWORD *)(v40 + 60);
        if ( v140 < 0xC0000000 || v140 > 0xC03FFFFF )
          --*(_DWORD *)(v40 + 52);
        goto LABEL_66;
      }
      if ( (*(_DWORD *)(v17 + 12) & 0x3FFFFFFFu) > 1 && (*(_DWORD *)(v17 + 20) & 0x8000000) == 0
        || (v18 = a1, (*(_BYTE *)(a1 + 112) & 7) != 0) && *(unsigned __int16 *)(v17 + 16) > 1u )
      {
        v11[1] = 0;
        ++v141;
        goto LABEL_67;
      }
      if ( (*(_BYTE *)(a1 + 112) & 7) != 0 )
      {
        v19 = MmPfnDatabase + 24 * (v16 >> 12);
        v83 = (unsigned __int8 *)(v17 + 15);
        do
          v84 = __ldrex(v83);
        while ( __strex(v84 | 0x80, v83) );
        __dmb(0xBu);
        if ( v84 >> 7 )
        {
          v109 = (unsigned __int8 *)(v17 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v110 = *(_DWORD *)(v17 + 12);
              __dmb(0xBu);
            }
            while ( (v110 & 0x80000000) != 0 );
            do
              v111 = __ldrex(v109);
            while ( __strex(v111 | 0x80, v109) );
            __dmb(0xBu);
          }
          while ( v111 >> 7 );
        }
        v10 = v134;
      }
      else
      {
        v19 = 0;
      }
      if ( (*(_DWORD *)(v17 + 12) & 0x3FFFFFFFu) > 1 && (*(_DWORD *)(v17 + 20) & 0x8000000) == 0
        || (*(_BYTE *)(a1 + 112) & 7) != 0 && *(unsigned __int16 *)(v17 + 16) > 1u )
      {
        if ( v19 )
        {
          __dmb(0xBu);
          v112 = (unsigned int *)(v19 + 12);
          do
            v113 = __ldrex(v112);
          while ( __strex(v113 & 0x7FFFFFFF, v112) );
          v10 = v134;
        }
        v11[1] = 0;
        ++v141;
        goto LABEL_67;
      }
      v20 = v16 & 0xFFFFFFCF;
      if ( (*(_BYTE *)(a1 + 112) & 7) != 0 )
      {
        v21 = v137;
      }
      else
      {
        v21 = v137;
        if ( (*(_DWORD *)(v17 + 20) & 0x8000000) == 0
          && v137 <= (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000
          && v137 >= 0xC0000000
          && (v16 & 0x200) == 0
          && (*(_DWORD *)(a1 - 300) & 0x8000) != 0 )
        {
          MiCaptureWriteWatchDirtyBit(v146, v14, 0);
          v18 = a1;
        }
      }
      v22 = (*(_DWORD *)(v17 + 20) >> 27) & 1;
      if ( v22 )
      {
        if ( (*(_DWORD *)(v17 + 4) & 0x80000000) == 0 || (*(_DWORD *)(v17 + 8) & 0x400) != 0 )
          goto LABEL_23;
      }
      else
      {
        if ( (*(_BYTE *)(v18 + 112) & 7u) >= 2 )
          goto LABEL_23;
        if ( (*(_BYTE *)(v18 + 112) & 7) == 0 )
          __mrc(15, 0, 13, 0, 3);
      }
      v22 = (*(_DWORD *)(v17 + 20) >> 27) & 1;
      if ( (!v22 || (*(_DWORD *)(v17 + 12) & 0x3FFFFFFF) == 1)
        && (*(_DWORD *)v21 & 0x10) != 0
        && *(_WORD *)(v17 + 16) == 1
        && (*(_BYTE *)(v17 + 18) & 0xC0) == 64
        && (*(_BYTE *)(v17 + 19) & 0x40) == 0
        && ((a3 & 2) != 0 || !(*(_DWORD *)(v21 << 10) | *(_DWORD *)((v21 << 10) + 0xFFC))) )
      {
        v20 |= 0x10u;
      }
      else if ( (a3 & 2) != 0 )
      {
        if ( v19 )
        {
          __dmb(0xBu);
          v114 = (unsigned int *)(v19 + 12);
          do
            v115 = __ldrex(v114);
          while ( __strex(v115 & 0x7FFFFFFF, v114) );
        }
        v11[1] = 0;
        ++v141;
        goto LABEL_66;
      }
LABEL_23:
      if ( v22 )
      {
        v23 = *(_DWORD *)(v13 + v136);
        v24 = a1;
        if ( (v23 & 0x1F0) != 0 )
        {
          v26 = 2 * (v23 & 0x1F0 | 0xFFFFF200);
        }
        else
        {
          v25 = *(_DWORD *)(v17 + 4);
          v26 = (v25 | 0x80000000) & 0x1FC | (4 * ((v25 | 0x80000000) & 0xFFFFFE00 | 0x100));
          if ( (*(_BYTE *)(a1 + 112) & 7u) >= 2 && (v16 & 0x180) == 0 && (v16 & 1) != 0 )
            v26 |= 0x200u;
        }
      }
      else
      {
        v24 = a1;
        v26 = v16 & 0xFFFFF81C | *(_DWORD *)(v17 + 8) & 0x3E0 | 0x800;
        --*(_DWORD *)(a1 + 64);
        if ( v14 < 0xC0000000 || v14 > 0xC03FFFFF )
          --*(_DWORD *)(a1 + 56);
      }
      v27 = *(_DWORD *)v137;
      __dmb(0xBu);
      if ( (v27 & 0x10) != 0 )
        goto LABEL_149;
      __dmb(0xBu);
      do
        v28 = __ldrex((unsigned int *)v137);
      while ( v28 == v27 && __strex(v26, (unsigned int *)v137) );
      __dmb(0xBu);
      if ( v28 != v27 )
      {
LABEL_149:
        if ( v137 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v137 = v26;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v137 = v26;
          if ( v137 >= 0xC0300000 && v137 <= 0xC0300FFF )
          {
            v116 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v116, v116 + 4 * (v137 & 0xFFF), v26);
          }
        }
        MiInsertTbFlushEntry(&v148, v14 & 0xFFFFF000, 1);
      }
      v162[v134] = v20;
      if ( v19 )
      {
        __dmb(0xBu);
        v85 = (unsigned int *)(v19 + 12);
        do
          v86 = __ldrex(v85);
        while ( __strex(v86 & 0x7FFFFFFF, v85) );
      }
      if ( (*(_DWORD *)(v17 + 20) & 0x8000000) == 0 && (a3 & 2) == 0 )
      {
        v29 = *(_DWORD *)(v17 + 8);
        v30 = dword_63F958;
        __dmb(0xBu);
        if ( v30 )
        {
          if ( (v29 & 8) == 0
            && !*(_DWORD *)(v24 + 120)
            && ((v29 & 2) != 0
             || (v29 & 0xC18) != 0
             || (v29 & 0xFFFFE000) != 0x2000
             || (*(_BYTE *)(v17 + 18) & 0x10) != 0
             || (*(_DWORD *)v137 & 0x200) == 0)
            && v137 <= (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000
            && v137 >= 0xC0000000
            && v137 <= 0xC03FFFFF )
          {
            MiReservePageFileSpace(MiSystemPartition, v137, v24);
          }
        }
      }
LABEL_66:
      v10 = v134;
LABEL_67:
      v6 = v135;
      v7 = v136;
      goto LABEL_68;
    }
LABEL_69:
    if ( !v9 )
      MiFlushTbList(&v148);
    v144 = ++v9;
  }
  while ( v9 < 2 );
  return v141;
}
