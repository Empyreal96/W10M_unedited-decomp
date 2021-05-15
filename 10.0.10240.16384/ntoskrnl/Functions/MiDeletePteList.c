// MiDeletePteList 
 
int MiDeletePteList(int result, int a2, ...)
{
  unsigned int v2; // r10
  int v3; // r6
  int v4; // r8
  int v5; // r9
  int v6; // r4
  int *v7; // r1
  unsigned int v8; // r5
  int v9; // r7
  int v10; // t1
  unsigned int v11; // r3
  int v12; // r2
  int v13; // r10
  unsigned int v14; // r9
  unsigned int v15; // r7
  unsigned int v16; // r10
  unsigned int v17; // r0
  int v18; // r4
  int v19; // r8
  int v20; // r8
  unsigned __int8 *v21; // r3
  unsigned int v22; // r1
  __int64 v23; // r2
  int v24; // r2
  int v25; // r3
  bool v26; // zf
  int v27; // r3
  int v28; // r1
  unsigned int *v29; // r2
  unsigned int v30; // r0
  int v31; // r4
  unsigned int *v32; // r2
  unsigned int v33; // r0
  int v34; // r3
  int v35; // r5
  int v36; // r4
  unsigned __int8 *v37; // r1
  unsigned int v38; // r3
  int v39; // r2
  unsigned int *v40; // r2
  unsigned int v41; // r0
  unsigned __int8 *v42; // r1
  int v43; // r3
  unsigned int v44; // r2
  char v45; // r3
  char v46; // r3
  int v47; // r3
  int v48; // r8
  unsigned __int8 *v49; // r3
  int v50; // r5
  unsigned int v51; // r1
  int v52; // r2
  unsigned int *v53; // r2
  unsigned int v54; // r4
  int v55; // r0
  int *v56; // r5
  unsigned int v57; // r10
  int v58; // r4
  int v59; // t1
  unsigned int v60; // r1
  unsigned int v61; // r3
  int v62; // r1
  int v63; // r7
  unsigned int v64; // r3
  int v65; // r1
  unsigned int v66; // r3
  int v67; // r2
  unsigned int v68; // r9
  int v69; // r8
  int *v70; // r5
  unsigned int v71; // r10
  int v72; // r4
  int v73; // t1
  unsigned int v74; // r1
  unsigned int v75; // r3
  int v76; // r1
  int v77; // r7
  unsigned int v78; // r3
  int v79; // r1
  int *v80; // r5
  unsigned int v81; // r10
  int v82; // r4
  int v83; // t1
  unsigned int v84; // r1
  unsigned int v85; // r3
  int v86; // r1
  int v87; // r7
  unsigned int v88; // r3
  int v89; // r1
  int v90; // r10
  unsigned int v91; // lr
  int v92; // r2
  int v93; // r3
  void **v94; // r1
  int v95; // r2
  int v96; // t1
  int v97; // r2
  int v98; // r4
  unsigned __int8 *v99; // r1
  int v100; // r3
  unsigned int v101; // r2
  int v102; // r5
  int v103; // r0
  unsigned __int8 *v104; // r1
  int v105; // r3
  unsigned int v106; // r2
  unsigned int v107; // r1
  __int16 v108; // r3
  char v109; // r3
  int v110; // r1
  int v111; // r0
  int v112; // [sp+10h] [bp-60h]
  int v113; // [sp+14h] [bp-5Ch]
  unsigned int v114; // [sp+14h] [bp-5Ch]
  BOOL v115; // [sp+1Ch] [bp-54h]
  int v116; // [sp+20h] [bp-50h]
  unsigned int v117; // [sp+20h] [bp-50h]
  int v118; // [sp+28h] [bp-48h] BYREF
  unsigned int v119; // [sp+2Ch] [bp-44h]
  unsigned int v120; // [sp+30h] [bp-40h]
  int v121; // [sp+34h] [bp-3Ch]
  int v122; // [sp+38h] [bp-38h]
  int v123; // [sp+40h] [bp-30h]
  int v124; // [sp+44h] [bp-2Ch]
  int v125; // [sp+48h] [bp-28h]
  int varg_r2; // [sp+80h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+80h] [bp+10h]
  int varg_r3; // [sp+84h] [bp+14h]
  va_list va1; // [sp+88h] [bp+18h] BYREF

  va_start(va1, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, _DWORD);
  v121 = varg_r3;
  v122 = a2;
  v2 = *(_DWORD *)(result + 12);
  v3 = result;
  v112 = result;
  v120 = v2;
  if ( v2 )
  {
    if ( *(_BYTE *)(result + 5) || *(_DWORD *)(result + 16) > (unsigned int)dword_63382C )
    {
      if ( (*(_BYTE *)(result + 4) & 1) != 0 )
      {
        __dsb(0xFu);
        __mcr(15, 0, 0, 8, 7, 0);
        __dsb(0xFu);
        __isb(0xFu);
      }
      else
      {
        result = KeFlushTb(*(_DWORD *)result, *(_DWORD *)result != 1);
      }
      *(_BYTE *)(v3 + 5) = 0;
LABEL_23:
      *(_DWORD *)(v3 + 12) = 0;
      *(_DWORD *)(v3 + 16) = 0;
      goto LABEL_24;
    }
    if ( (*(_BYTE *)(result + 4) & 1) != 0 )
      return sub_531B40();
    v4 = *(_DWORD *)result;
    v113 = *(_DWORD *)result;
    v115 = *(_DWORD *)result != 1;
    v5 = result + 20;
    __dsb(0xFu);
    if ( v4 == 1 )
    {
      if ( !KiTbDisableSingleByAsidBroadcast )
      {
        if ( (__get_CPSR() & 0x80) != 0 )
        {
          v6 = 0;
        }
        else
        {
          __disable_irq();
          v6 = 1;
        }
        v7 = (int *)(result + 20);
        v8 = v5 + 4 * v2;
        v9 = (unsigned __int8)__mrc(15, 0, 13, 0, 1);
        do
        {
          v10 = *v7++;
          result = v10;
          v11 = v10 & 0xFFFFF000 | v9;
          __mcr(15, 0, v11, 8, 3, 1);
          if ( v11 >= 0xC0000000 && v11 <= 0xC03FFFFF )
          {
            v66 = v9 | ((v11 & 0xFFFFF000) << 10);
            v67 = 4;
            do
            {
              __mcr(15, 0, v66, 8, 3, 1);
              v66 += 0x100000;
              --v67;
            }
            while ( v67 );
          }
          v12 = result & 0x7FF;
          if ( (result & 0x800) != 0 )
            v13 = 0x400000;
          else
            v13 = 4096;
          if ( (result & 0x7FF) != 0 )
          {
            do
            {
              result += v13;
              v117 = result & 0xFFFFF000 | v9;
              __mcr(15, 0, v117, 8, 3, 1);
              if ( v117 + 0x40000000 <= 0x3FFFFF )
              {
                v119 = 4;
                v68 = v9 | ((v117 & 0xFFFFF000) << 10);
                v69 = 4;
                do
                {
                  __mcr(15, 0, v68, 8, 3, 1);
                  v68 += 0x100000;
                  --v69;
                }
                while ( v69 );
              }
              --v12;
            }
            while ( v12 );
          }
        }
        while ( (unsigned int)v7 < v8 );
        v3 = v112;
        v4 = v113;
        v5 = v112 + 20;
        if ( v6 )
          __enable_irq();
LABEL_18:
        __dsb(0xFu);
        __isb(0xFu);
        if ( KiTbSendIpiForBroadcastFlushes )
        {
          __mcr(15, 0, 0, 8, 3, 1);
          __dsb(0xFu);
          v90 = KfRaiseIrql(12);
          v91 = (unsigned int)KeGetPcr() & 0xFFFFF000;
          if ( v115 )
          {
            v123 = *(_DWORD *)&KeActiveProcessors;
            v124 = dword_681D74;
            v125 = dword_681D78[0];
          }
          else
          {
            v92 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v91 + 1412) + 116) + 92);
            v93 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v91 + 1412) + 116) + 96);
            v123 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v91 + 1412) + 116) + 88);
            v124 = v92;
            v125 = v93;
          }
          v94 = &KeNodeBlock;
          if ( KeNodeBlock )
          {
            v95 = (unsigned __int16)KeNumberNodes;
            result = 0;
            if ( KeNumberNodes )
            {
              do
              {
                v96 = (int)*v94++;
                result |= *(_DWORD *)(v96 + 128);
                --v95;
              }
              while ( v95 );
            }
            v97 = v125 & ~result;
            v123 = 65537;
            v124 = 0;
            if ( !v97 )
              goto LABEL_19;
          }
          else
          {
            v97 = v125;
          }
          v125 = v97 & ~(1 << *(_DWORD *)(v91 + 1428));
          KiIpiSendRequestEx(v91 + 1408);
          result = KfLowerIrql(v90);
        }
LABEL_19:
        v2 = v120;
        if ( VmTbFlushEnabled )
          result = VmFlushTb(v120, v5);
        if ( ExTbFlushActive )
        {
          v98 = KfRaiseIrql(15);
          ExFlushTb(v120, v5, v4);
          result = KfLowerIrql(v98);
        }
        goto LABEL_23;
      }
      v56 = (int *)(result + 20);
      v57 = v5 + 4 * v2;
      do
      {
        v59 = *v56++;
        v58 = v59;
        v60 = v59 & 0xFFFFF000;
        __mcr(15, 0, v59 & 0xFFFFF000, 8, 3, 3);
        if ( (v59 & 0xFFFFF000) + 0x40000000 <= 0x3FFFFF )
        {
          v61 = (v60 & 0xFFFFF000) << 10;
          v62 = 4;
          do
          {
            __mcr(15, 0, v61, 8, 3, 3);
            v61 += 0x100000;
            --v62;
          }
          while ( v62 );
        }
        result = v58 & 0x7FF;
        if ( (v58 & 0x800) != 0 )
          v63 = 0x400000;
        else
          v63 = 4096;
        if ( (v58 & 0x7FF) != 0 )
        {
          do
          {
            v58 += v63;
            __mcr(15, 0, v58 & 0xFFFFF000, 8, 3, 3);
            if ( (v58 & 0xFFFFF000) + 0x40000000 <= 0x3FFFFF )
            {
              v64 = (v58 & 0xFFFFF000) << 10;
              v65 = 4;
              do
              {
                __mcr(15, 0, v64, 8, 3, 3);
                v64 += 0x100000;
                --v65;
              }
              while ( v65 );
            }
            --result;
          }
          while ( result );
        }
      }
      while ( (unsigned int)v56 < v57 );
    }
    else if ( v4 )
    {
      if ( v4 != 2 )
        goto LABEL_18;
      v80 = (int *)(result + 20);
      v81 = v5 + 4 * v2;
      do
      {
        v83 = *v80++;
        v82 = v83;
        v84 = v83 & 0xFFFFF000;
        __mcr(15, 0, v83 & 0xFFFFF000, 8, 3, 3);
        if ( (v83 & 0xFFFFF000) + 0x40000000 <= 0x3FFFFF )
        {
          v85 = (v84 & 0xFFFFF000) << 10;
          v86 = 4;
          do
          {
            __mcr(15, 0, v85, 8, 3, 3);
            v85 += 0x100000;
            --v86;
          }
          while ( v86 );
        }
        result = v82 & 0x7FF;
        if ( (v82 & 0x800) != 0 )
          v87 = 0x400000;
        else
          v87 = 4096;
        if ( (v82 & 0x7FF) != 0 )
        {
          do
          {
            v82 += v87;
            __mcr(15, 0, v82 & 0xFFFFF000, 8, 3, 3);
            if ( (v82 & 0xFFFFF000) + 0x40000000 <= 0x3FFFFF )
            {
              v88 = (v82 & 0xFFFFF000) << 10;
              v89 = 4;
              do
              {
                __mcr(15, 0, v88, 8, 3, 3);
                v88 += 0x100000;
                --v89;
              }
              while ( v89 );
            }
            --result;
          }
          while ( result );
        }
      }
      while ( (unsigned int)v80 < v81 );
    }
    else
    {
      v70 = (int *)(result + 20);
      v71 = v5 + 4 * v2;
      do
      {
        v73 = *v70++;
        v72 = v73;
        v74 = v73 & 0xFFFFF000;
        __mcr(15, 0, v73 & 0xFFFFF000, 8, 3, 3);
        if ( (v73 & 0xFFFFF000) + 0x40000000 <= 0x3FFFFF )
        {
          v75 = (v74 & 0xFFFFF000) << 10;
          v76 = 4;
          do
          {
            __mcr(15, 0, v75, 8, 3, 3);
            v75 += 0x100000;
            --v76;
          }
          while ( v76 );
        }
        result = v72 & 0x7FF;
        if ( (v72 & 0x800) != 0 )
          v77 = 0x400000;
        else
          v77 = 4096;
        if ( (v72 & 0x7FF) != 0 )
        {
          do
          {
            v72 += v77;
            __mcr(15, 0, v72 & 0xFFFFF000, 8, 3, 3);
            if ( (v72 & 0xFFFFF000) + 0x40000000 <= 0x3FFFFF )
            {
              v78 = (v72 & 0xFFFFF000) << 10;
              v79 = 4;
              do
              {
                __mcr(15, 0, v78, 8, 3, 3);
                v78 += 0x100000;
                --v79;
              }
              while ( v79 );
            }
            --result;
          }
          while ( result );
        }
      }
      while ( (unsigned int)v70 < v71 );
    }
    v3 = v112;
    v4 = v113;
    v5 = v112 + 20;
    goto LABEL_18;
  }
LABEL_24:
  v114 = 0;
  v14 = 0;
  if ( v2 )
  {
    do
    {
      v15 = *(_DWORD *)(v3 + 4 * v14 + 20) & 0xFFFFF000;
      v116 = (*(_DWORD *)(v3 + 4 * v14 + 20) & 0x7FF) + 1;
      v119 = v15;
      do
      {
        v16 = ((v15 >> 10) & 0x3FFFFC) - 0x40000000;
        v17 = *(_DWORD *)v16 & 0xFFFFFBFF | 2;
        v18 = MmPfnDatabase + 24 * (v17 >> 12);
        v19 = *(_DWORD *)(v18 + 20);
        v118 = v17;
        if ( (v19 & 0x8000000) != 0 )
        {
          v48 = *(_DWORD *)(v18 + 4);
          v118 = *(_DWORD *)(((v16 >> 10) & 0x3FFFFC) - 0x40000000) >> 12;
          v49 = (unsigned __int8 *)(v18 + 15);
          v50 = 0;
          do
            v51 = __ldrex(v49);
          while ( __strex(v51 | 0x80, v49) );
          __dmb(0xBu);
          if ( v51 >> 7 )
          {
            v99 = (unsigned __int8 *)(v18 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v100 = *(_DWORD *)(v18 + 12);
                __dmb(0xBu);
              }
              while ( (v100 & 0x80000000) != 0 );
              do
                v101 = __ldrex(v99);
              while ( __strex(v101 | 0x80, v99) );
              __dmb(0xBu);
            }
            while ( v101 >> 7 );
          }
          if ( (v17 & 0x200) == 0 )
            v50 = MiCaptureDirtyBitToPfn(v18);
          if ( (*(_BYTE *)(v18 + 18) & 7) != 6 )
            KeBugCheckEx(78, 153, (v18 - MmPfnDatabase) / 24);
          v52 = *(_DWORD *)(v18 + 12);
          *(_DWORD *)(v18 + 12) = v52 & 0xC0000000 | ((v52 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
          if ( (v52 & 0x3FFFFFFF) == 1 )
            MiPfnShareCountIsZero(v18, 0);
          __dmb(0xBu);
          v53 = (unsigned int *)(v18 + 12);
          do
            v54 = __ldrex(v53);
          while ( __strex(v54 & 0x7FFFFFFF, v53) );
          if ( v50 )
            MiReleasePageFileInfo(MiSystemPartition, v50, 1);
          if ( v48 >= 0 )
          {
            v55 = MiDecrementCombinedPte(v48 | 0x80000000);
          }
          else
          {
            v102 = v122;
            v103 = MiLocateCloneAddress(v122, v48 | 0x80000000);
            v55 = MiDecrementCloneBlockReference(v103, v48 | 0x80000000, v102);
          }
          if ( v55 == 3 )
          {
            ++*(_DWORD *)(v121 + 4);
          }
          else if ( v55 == 5 )
          {
            ++*(_DWORD *)(v121 + 8);
          }
          v31 = varg_r2;
          v20 = v118;
          v15 = v119;
        }
        else
        {
          v20 = v19 & 0xFFFFF;
          v21 = (unsigned __int8 *)(v18 + 15);
          do
            v22 = __ldrex(v21);
          while ( __strex(v22 | 0x80, v21) );
          __dmb(0xBu);
          if ( v22 >> 7 )
          {
            v104 = (unsigned __int8 *)(v18 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v105 = *(_DWORD *)(v18 + 12);
                __dmb(0xBu);
              }
              while ( (v105 & 0x80000000) != 0 );
              do
                v106 = __ldrex(v104);
              while ( __strex(v106 | 0x80, v104) );
              __dmb(0xBu);
            }
            while ( v106 >> 7 );
          }
          v23 = *(_QWORD *)(v18 + 8);
          *(_DWORD *)(v18 + 12) = HIDWORD(v23) | 0x40000000;
          if ( (v23 & 8) != 0 )
          {
            v107 = *(_DWORD *)(v18 + 8);
            v108 = *(_WORD *)(*(_DWORD *)&MiSystemPartition[2 * ((v107 >> 2) & 1) + 1800] + 96);
            if ( (v108 & 0x10) == 0 && ((v108 & 0x20) == 0 || (v107 & 8) == 0) && *(_WORD *)(v18 + 16) == 1 && varg_r2 )
            {
              v114 = v23;
              *(_DWORD *)(v18 + 8) &= 0xFFFFFFF7;
            }
          }
          if ( (*(_BYTE *)(v18 + 18) & 7) != 6 )
            KeBugCheckEx(78, 153, (v18 - MmPfnDatabase) / 24);
          v24 = *(_DWORD *)(v18 + 12);
          *(_DWORD *)(v18 + 12) = v24 & 0xC0000000 | ((v24 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
          if ( (v24 & 0x3FFFFFFF) == 1 )
          {
            if ( (*(_DWORD *)(v18 + 20) & 0x8000000) != 0 )
              MiMakeProtoTransition(v18);
            v25 = (unsigned __int16)(*(_WORD *)(v18 + 16) - 1);
            *(_WORD *)(v18 + 16) = v25;
            v26 = v25 == 0;
            v27 = *(_DWORD *)(v18 + 12);
            if ( v26 )
            {
              if ( (v27 & 0x40000000) != 0 )
              {
                if ( (*(_BYTE *)(v18 + 19) & 0x10) != 0 )
                  *(_BYTE *)(v18 + 19) &= 0xEFu;
                v28 = *(_DWORD *)(v18 + 8);
                if ( (v28 & 0x400) == 0 )
                {
                  if ( (v28 & 0x10) == 0 && (v28 & 8) == 0 )
                    v28 = 0;
                  if ( v28 )
                    MiReleasePageFileInfo(MiSystemPartition, v28, 0);
                }
                MiInsertPageInFreeOrZeroedList((v18 - MmPfnDatabase) / 24, 2);
              }
              else
              {
                if ( (*(_BYTE *)(v18 + 18) & 0x10) != 0 )
                {
                  v110 = 8;
                }
                else
                {
                  *(_BYTE *)(v18 + 18) = *(_BYTE *)(v18 + 18) & 0xF8 | 2;
                  v110 = 4;
                }
                MiInsertPageInList(v18, v110);
              }
            }
            else
            {
              v26 = (v27 & 0x40000000) == 0;
              v45 = *(_BYTE *)(v18 + 18);
              if ( v26 )
              {
                v26 = (v45 & 0x10) == 0;
                v109 = v45 & 0xF8;
                if ( v26 )
                  v46 = v109 | 2;
                else
                  v46 = v109 | 3;
              }
              else
              {
                v46 = v45 | 7;
              }
              *(_BYTE *)(v18 + 18) = v46;
              v47 = *(_DWORD *)(v18 + 8);
              if ( (v47 & 0x400) == 0 && (v47 & 0x10) != 0 )
                byte_63F87E = 1;
              ++*(_DWORD *)(v121 + 4);
            }
          }
          __dmb(0xBu);
          v29 = (unsigned int *)(v18 + 12);
          do
            v30 = __ldrex(v29);
          while ( __strex(v30 & 0x7FFFFFFF, v29) );
          if ( v114 )
          {
            MI_SET_PAGING_FILE_INFO(
              &v118,
              (int *)varg_r2a,
              *(_DWORD *)&MiSystemPartition[2 * ((v114 >> 2) & 1) + 1800],
              v114 >> 13,
              2);
            v31 = v118;
            v114 = 0;
          }
          else
          {
            v31 = varg_r2;
          }
          v32 = (unsigned int *)(v122 + 276);
          do
            v33 = __ldrex(v32);
          while ( __strex(v33 - 1, v32) );
        }
        if ( v16 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v16 = v31;
        }
        else
        {
          v34 = *(_DWORD *)v16;
          v35 = 0;
          __dmb(0xBu);
          *(_DWORD *)v16 = v31;
          if ( (v34 & 2) == 0 && (v31 & 2) != 0 )
            v35 = 1;
          if ( v16 >= 0xC0300000 && v16 <= 0xC0300FFF )
          {
            v111 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v111, v111 + 4 * (v16 & 0xFFF), v31);
          }
          if ( v35 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        v36 = MmPfnDatabase + 24 * v20;
        v37 = (unsigned __int8 *)(v36 + 15);
        do
          v38 = __ldrex(v37);
        while ( __strex(v38 | 0x80, v37) );
        __dmb(0xBu);
        if ( v38 >> 7 )
        {
          v42 = (unsigned __int8 *)(v36 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v43 = *(_DWORD *)(v36 + 12);
              __dmb(0xBu);
            }
            while ( (v43 & 0x80000000) != 0 );
            do
              v44 = __ldrex(v42);
            while ( __strex(v44 | 0x80, v42) );
            __dmb(0xBu);
          }
          while ( v44 >> 7 );
        }
        if ( (*(_BYTE *)(v36 + 18) & 7) != 6 )
          KeBugCheckEx(78, 153, (v36 - MmPfnDatabase) / 24);
        v39 = *(_DWORD *)(v36 + 12);
        *(_DWORD *)(v36 + 12) = v39 & 0xC0000000 | ((v39 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
        if ( (v39 & 0x3FFFFFFF) == 1 )
          MiPfnShareCountIsZero(v36, 0);
        __dmb(0xBu);
        v40 = (unsigned int *)(v36 + 12);
        do
          v41 = __ldrex(v40);
        while ( __strex(v41 & 0x7FFFFFFF, v40) );
        v15 += 4096;
        v26 = v116-- == 1;
        v119 = v15;
        result = 2;
      }
      while ( !v26 );
      ++v14;
    }
    while ( v14 < v120 );
  }
  return result;
}
