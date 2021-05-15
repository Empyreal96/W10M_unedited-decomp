// MiDeleteSystemPagableVm 
 
int __fastcall MiDeleteSystemPagableVm(int *a1, int a2, unsigned int a3, int a4, char a5, _DWORD *a6)
{
  _DWORD *v6; // r5
  unsigned int v8; // r6
  unsigned int *v9; // r10
  unsigned int v10; // r7
  int v11; // r4
  int v12; // r3
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r4
  unsigned int v17; // r8
  int v18; // r5
  unsigned int v19; // r7
  int v20; // lr
  _DWORD *v21; // r8
  int v22; // r3
  unsigned int v23; // lr
  unsigned __int8 *v24; // r1
  int v25; // r7
  unsigned int v26; // r0
  int v27; // r1
  unsigned int v28; // r10
  int v29; // r2
  unsigned int *v30; // r2
  unsigned int v31; // r0
  unsigned __int8 *v32; // r2
  unsigned int v33; // r1
  int v34; // r2
  unsigned int *v35; // r2
  unsigned int v36; // r5
  int v37; // r3
  int v38; // r4
  char v40; // r1
  int v41; // r0
  int v42; // r3
  int v43; // r2
  unsigned __int8 *v44; // r3
  unsigned int v45; // r0
  unsigned int v46; // r0
  unsigned int v47; // r7
  int v48; // r8
  int v49; // r0
  int v50; // r4
  unsigned int v51; // r2
  unsigned int v52; // r5
  int v53; // r3
  unsigned int v54; // r2
  int v55; // r4
  unsigned __int8 *v56; // r3
  unsigned int v57; // r1
  int v58; // r0
  unsigned int v59; // r1
  int v60; // r8
  unsigned int v61; // r2
  unsigned int v62; // r2
  unsigned int *v63; // r2
  unsigned int v64; // r1
  int v65; // r0
  unsigned int *v66; // r2
  unsigned int v67; // r1
  unsigned __int8 *v68; // r1
  int v69; // r3
  unsigned int v70; // r2
  unsigned __int8 *v71; // r1
  int v72; // r3
  unsigned int v73; // r2
  int v74; // r0
  unsigned __int8 *v75; // r1
  int v76; // r3
  unsigned int v77; // r2
  int v78; // r0
  int v79; // r3
  int v80; // r0
  unsigned int v81; // r2
  unsigned int v82; // r2
  int v83; // r0
  int v84; // r1
  unsigned int v85; // r2
  unsigned int v86; // r2
  int v87; // r0
  unsigned int v88; // r1
  unsigned int v89; // [sp+10h] [bp-118h]
  int v91; // [sp+1Ch] [bp-10Ch]
  unsigned int v92; // [sp+28h] [bp-100h]
  int v93; // [sp+2Ch] [bp-FCh]
  int v95; // [sp+34h] [bp-F4h]
  int v96; // [sp+38h] [bp-F0h]
  int v97; // [sp+40h] [bp-E8h]
  unsigned int v98; // [sp+50h] [bp-D8h] BYREF
  unsigned int v99; // [sp+54h] [bp-D4h]
  unsigned int v100; // [sp+58h] [bp-D0h]
  int v101; // [sp+5Ch] [bp-CCh]
  int v102[4]; // [sp+60h] [bp-C8h] BYREF
  int v103; // [sp+70h] [bp-B8h] BYREF
  char v104; // [sp+74h] [bp-B4h]
  char v105; // [sp+75h] [bp-B3h]
  int v106; // [sp+78h] [bp-B0h]
  int v107; // [sp+7Ch] [bp-ACh]
  int v108; // [sp+80h] [bp-A8h]
  int v109; // [sp+84h] [bp-A4h]

  v6 = a6;
  v8 = a3;
  v9 = (unsigned int *)a1;
  if ( a2 )
    v97 = *(_BYTE *)(*(_DWORD *)a2 + 10) & 1;
  else
    v97 = 0;
  v10 = 0;
  v11 = 0;
  v92 = 0;
  v93 = 0;
  if ( a1 != &dword_634E80 && a1 != &dword_634F00 )
  {
    v10 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
    v92 = v10;
    if ( (a5 & 2) != 0 )
      return sub_538634();
    v11 = 2;
    v93 = 2;
  }
  v12 = a1[23];
  v107 = 0;
  v95 = v12;
  v104 = 0;
  v105 = 0;
  v108 = 0;
  v106 = 33;
  v109 = 0;
  v103 = v11;
  if ( (a5 & 8) == 0 && (dword_682604 & 1) != 0 )
  {
    v100 = a3 << 10;
    v101 = a4;
    if ( a1 == &dword_634F00 )
    {
      v98 = 6;
      v99 = 0;
    }
    else if ( a1 == &dword_634E80 )
    {
      v98 = 4;
      v99 = 0;
    }
    else
    {
      v99 = v10 >> 28;
      v98 = (16 * v10) | 7;
    }
    v102[0] = (int)&v98;
    v102[1] = 0;
    v102[2] = 16;
    v102[3] = 0;
    EtwTraceKernelEvent(v102, 1, 536870913, 633, 289413890);
  }
  v96 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v9);
  }
  else
  {
    v13 = (unsigned __int8 *)v9 + 3;
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 | 0x80, v13) );
    __dmb(0xBu);
    if ( v14 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v9);
    while ( 1 )
    {
      v15 = *v9;
      if ( (*v9 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v15 & 0x40000000) == 0 )
      {
        do
          v59 = __ldrex(v9);
        while ( v59 == v15 && __strex(v15 | 0x40000000, v9) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( a4 )
  {
    while ( 1 )
    {
      v16 = *(_DWORD *)v8;
      if ( !*(_DWORD *)v8 )
        goto LABEL_55;
      if ( (v16 & 2) != 0 )
      {
        v17 = v8 << 10;
        v18 = MmPfnDatabase + 24 * (v16 >> 12);
        if ( (a5 & 8) != 0 )
        {
          v61 = *(_DWORD *)(v18 + 4) | 0x80000000;
          if ( v61 > (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000 || v61 < 0xC0000000 )
          {
            v62 = *(unsigned __int8 *)(v18 + 19);
            if ( ((v62 >> 5) & 1) != 0 )
            {
              *(_BYTE *)(v18 + 19) = v62 & 0xDF;
              ++a6[1];
            }
          }
        }
        else
        {
          if ( !*(_DWORD *)v18 || (*(_BYTE *)(v18 + 19) & 8) != 0 )
          {
            v21 = a6;
            ++*a6;
            if ( v93 == 2 )
            {
              v66 = (unsigned int *)(v92 + 28);
              do
                v67 = __ldrex(v66);
              while ( __strex(v67 - 1, v66) );
            }
          }
          else
          {
            v19 = MiLocateWsle(v8 << 10, (int)v9, *(_DWORD *)v18);
            if ( (*(_DWORD *)(v18 + 20) & 0x8000000) == 0 )
            {
              --v9[16];
              if ( v17 < 0xC0000000 || v17 > 0xC03FFFFF )
                --v9[14];
            }
            MiRemoveWsle(v19, v9);
            MiReleaseWsle(v19, v9, v8 << 10, 1);
            v20 = v95;
            if ( v19 < *(_DWORD *)(v95 + 4) )
            {
              v63 = (unsigned int *)(v92 + 28);
              do
                v64 = __ldrex(v63);
              while ( __strex(v64 - 1, v63) );
              v21 = a6;
              ++*a6;
              v65 = *(_DWORD *)(v95 + 4) - 1;
              if ( v19 != v65 )
              {
                MiSwapWslEntries(v65, v19, (int)v9);
                v20 = v95;
              }
              --*(_DWORD *)(v20 + 4);
            }
            else
            {
              v21 = a6;
            }
          }
          v22 = *(_DWORD *)(v18 + 20);
          v91 = 0;
          v23 = 0;
          v89 = 0;
          if ( (v22 & 0x8000000) != 0 )
          {
            v42 = *(_DWORD *)(v18 + 4);
            if ( (v42 & 0x80000000) == 0 )
              v91 = v42 | 0x80000000;
            if ( (*(_DWORD *)(v18 + 8) & 0x400) == 0 || v97 == 1 || (v16 & 0x100) != 0 )
              ++v21[3];
            v43 = ((v8 >> 10) & 0x3FFFFC) - 0x40000000;
            if ( (*(_DWORD *)v43 & 2) == 0 )
              KeBugCheckEx(26, 399680, v43 << 10);
            v44 = (unsigned __int8 *)(v18 + 15);
            v25 = MmPfnDatabase + 24 * (*(_DWORD *)v43 >> 12);
            do
              v45 = __ldrex(v44);
            while ( __strex(v45 | 0x80, v44) );
            __dmb(0xBu);
            if ( v45 >> 7 )
            {
              v68 = (unsigned __int8 *)(v18 + 15);
              do
              {
                do
                {
                  __dmb(0xAu);
                  __yield();
                  v69 = *(_DWORD *)(v18 + 12);
                  __dmb(0xBu);
                }
                while ( (v69 & 0x80000000) != 0 );
                do
                  v70 = __ldrex(v68);
                while ( __strex(v70 | 0x80, v68) );
                __dmb(0xBu);
              }
              while ( v70 >> 7 );
            }
            if ( (v16 & 0x200) == 0 )
            {
              v23 = MiCaptureDirtyBitToPfn(v18);
              v89 = v23;
            }
            v27 = 0x40000000;
          }
          else
          {
            v24 = (unsigned __int8 *)(v18 + 15);
            v25 = MmPfnDatabase + 24 * (v22 & 0xFFFFF);
            ++a6[3];
            do
              v26 = __ldrex(v24);
            while ( __strex(v26 | 0x80, v24) );
            __dmb(0xBu);
            if ( v26 >> 7 )
            {
              v71 = (unsigned __int8 *)(v18 + 15);
              do
              {
                do
                {
                  __dmb(0xAu);
                  __yield();
                  v72 = *(_DWORD *)(v18 + 12);
                  __dmb(0xBu);
                }
                while ( (v72 & 0x80000000) != 0 );
                do
                  v73 = __ldrex(v71);
                while ( __strex(v73 | 0x80, v71) );
                __dmb(0xBu);
              }
              while ( v73 >> 7 );
            }
            v27 = 0x40000000;
            *(_DWORD *)(v18 + 12) |= 0x40000000u;
            if ( (a5 & 4) != 0 )
            {
              v54 = *(_DWORD *)(v18 + 4) | 0x80000000;
              if ( (v54 > (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000 || v54 < 0xC0000000)
                && ((*(unsigned __int8 *)(v18 + 19) >> 5) & 1) != 0 )
              {
                MiDriverPageIsDangling(v18);
                v23 = 0;
                *(_BYTE *)(v18 + 19) &= 0xDFu;
              }
            }
          }
          v28 = v8 + v27;
          *(_BYTE *)(v18 + 19) &= 0xF7u;
          if ( v8 + v27 > 0x3FFFFF )
          {
            *(_DWORD *)v8 = 0;
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)v8 = 0;
            if ( v8 >= 0xC0300000 && v8 <= 0xC0300FFF )
            {
              v74 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v74, v74 + 4 * (v8 & 0xFFF), 0);
              v23 = v89;
            }
          }
          if ( (*(_BYTE *)(v18 + 18) & 7) != 6 )
            KeBugCheckEx(78, 153, (v18 - MmPfnDatabase) / 24);
          v29 = *(_DWORD *)(v18 + 12);
          *(_DWORD *)(v18 + 12) = v29 & 0xC0000000 | ((v29 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
          if ( (v29 & 0x3FFFFFFF) == 1 )
          {
            v23 = v89;
            v60 = MiPfnShareCountIsZero(v18, 0);
          }
          else
          {
            v60 = 2;
          }
          __dmb(0xBu);
          v30 = (unsigned int *)(v18 + 12);
          do
            v31 = __ldrex(v30);
          while ( __strex(v31 & 0x7FFFFFFF, v30) );
          v32 = (unsigned __int8 *)(v25 + 15);
          do
            v33 = __ldrex(v32);
          while ( __strex(v33 | 0x80, v32) );
          __dmb(0xBu);
          if ( v33 >> 7 )
          {
            v75 = (unsigned __int8 *)(v25 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v76 = *(_DWORD *)(v25 + 12);
                __dmb(0xBu);
              }
              while ( (v76 & 0x80000000) != 0 );
              do
                v77 = __ldrex(v75);
              while ( __strex(v77 | 0x80, v75) );
              __dmb(0xBu);
            }
            while ( v77 >> 7 );
          }
          if ( (*(_BYTE *)(v25 + 18) & 7) != 6 )
            KeBugCheckEx(78, 153, (v25 - MmPfnDatabase) / 24);
          v34 = *(_DWORD *)(v25 + 12);
          *(_DWORD *)(v25 + 12) = v34 & 0xC0000000 | ((v34 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
          if ( (v34 & 0x3FFFFFFF) == 1 )
          {
            MiPfnShareCountIsZero(v25, 0);
            v23 = v89;
          }
          __dmb(0xBu);
          v35 = (unsigned int *)(v25 + 12);
          do
            v36 = __ldrex(v35);
          while ( __strex(v36 & 0x7FFFFFFF, v35) );
          if ( v23 )
            MiReleasePageFileInfo(MiSystemPartition, v23, 1);
          if ( v91 )
            v60 = MiDecrementCombinedPte(v91);
          if ( v60 == 3 )
            ++a6[1];
          if ( (a5 & 1) != 0 )
            goto LABEL_54;
          __dmb(0xFu);
          v37 = KiTbFlushTimeStamp;
          __dmb(0xBu);
          v38 = v37 << 12;
          if ( v28 > 0x3FFFFF )
          {
            *(_DWORD *)v8 = v38;
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)v8 = v38;
            if ( v8 >= 0xC0300000 && v8 <= 0xC0300FFF )
            {
              v78 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v78, v78 + 4 * (v8 & 0xFFF), v38);
            }
          }
          if ( (v38 & 0xFFFFF000) == 0 )
LABEL_54:
            MiInsertTbFlushEntry(&v103, v8 << 10, 1);
        }
      }
      else if ( (v16 & 0x400) != 0 )
      {
        if ( (a5 & 8) == 0 )
        {
          if ( (v16 & 0xFFFFE000) == -8192
            || (v46 = (*(_DWORD *)v8 & 0x1FC | (*(_DWORD *)v8 >> 2) & 0x3FFFFE00) - 0x40000000, v46 < dword_640484)
            || v46 >= dword_640488 )
          {
            if ( v97 == 1 )
            {
              ++v6[3];
            }
            else
            {
              v47 = (*(_DWORD *)v8 & 0x1FC | (*(_DWORD *)v8 >> 2) & 0x3FFFFE00) - 0x40000000;
              v48 = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
              v49 = a2;
              v50 = a2 + 80;
              if ( a2 != -80 )
              {
                while ( 1 )
                {
                  v51 = *(_DWORD *)(v50 + 4);
                  v52 = (*(unsigned __int16 *)(v50 + 16) >> 1) & 0x1F;
                  if ( v47 >= v51 && v47 < v51 + 4 * *(_DWORD *)(v50 + 28) )
                    break;
                  if ( (*(_WORD *)(v50 + 18) & 2) != 0
                    && (v79 = *(_DWORD *)(v49 + 28), (v79 & 0x20) != 0)
                    && (v79 & 0x4000000) != 0 )
                  {
                    v80 = MiGetSharedProtos(v49, v48, v50);
                    if ( v80 )
                    {
                      v81 = *(_DWORD *)(v80 + 16);
                      if ( v47 >= v81 && v47 < v81 + 4 * *(_DWORD *)(v50 + 28) )
                        break;
                    }
                    v49 = a2;
                  }
                  else if ( (*(_DWORD *)(v49 + 28) & 0x20) != 0 )
                  {
                    v53 = *(_DWORD *)(v50 + 12);
                    if ( v53 )
                    {
                      v82 = *(_DWORD *)(v53 + 16);
                      if ( v47 >= v82 && v47 < v82 + 4 * *(_DWORD *)(v50 + 28) )
                        goto LABEL_182;
                    }
                  }
                  v50 = *(_DWORD *)(v50 + 8);
                  if ( !v50 )
                    goto LABEL_106;
                }
                if ( v52 < 4 )
                  goto LABEL_106;
LABEL_182:
                ++a6[3];
              }
            }
          }
          else
          {
            ++v6[3];
            if ( MiDecrementCombinedPte(v46) == 3 )
              ++v6[1];
          }
LABEL_106:
          if ( v8 + 0x40000000 > 0x3FFFFF )
          {
            *(_DWORD *)v8 = 0;
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)v8 = 0;
            if ( v8 >= 0xC0300000 && v8 <= 0xC0300FFF )
            {
              v83 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v83, v83 + 4 * (v8 & 0xFFF), 0);
            }
          }
        }
      }
      else
      {
        if ( (v16 & 0x800) == 0 )
        {
          if ( (a5 & 8) != 0 )
            goto LABEL_55;
          MiReleasePageFileSpace(MiSystemPartition, *(_DWORD *)v8, 1);
          if ( v8 + 0x40000000 > 0x3FFFFF )
          {
            *(_DWORD *)v8 = 0;
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)v8 = 0;
            if ( v8 >= 0xC0300000 && v8 <= 0xC0300FFF )
            {
              v87 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v87, v87 + 4 * (v8 & 0xFFF), 0);
            }
          }
LABEL_63:
          ++v6[3];
          goto LABEL_55;
        }
        if ( (a5 & 8) != 0 )
        {
          v84 = MmPfnDatabase + 24 * (v16 >> 12);
          v85 = *(_DWORD *)(v84 + 4) | 0x80000000;
          if ( v85 > (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000 || v85 < 0xC0000000 )
          {
            v86 = *(unsigned __int8 *)(v84 + 19);
            if ( ((v86 >> 5) & 1) != 0 )
            {
              *(_BYTE *)(v84 + 19) = v86 & 0xDF;
              ++v6[1];
            }
          }
        }
        else
        {
          v40 = 1;
          if ( (a5 & 4) != 0 )
            v40 = 3;
          v41 = MiDeleteTransitionPte((_DWORD *)v8, v40, 1073741312);
          if ( v41 == 1 )
            goto LABEL_56;
          if ( v41 != 3 )
            goto LABEL_63;
          ++v6[1];
          ++v6[3];
        }
      }
LABEL_55:
      v8 += 4;
      --a4;
      if ( (v8 & 0xFFF) == 0 )
      {
        MiUnlockWorkingSetExclusive(a1, v96);
        if ( !a4 )
          return MiFlushTbList(&v103);
        v55 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1);
        }
        else
        {
          v56 = (unsigned __int8 *)a1 + 3;
          do
            v57 = __ldrex(v56);
          while ( __strex(v57 | 0x80, v56) );
          __dmb(0xBu);
          if ( v57 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)a1);
          while ( 1 )
          {
            v58 = *a1;
            if ( (*a1 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v58 & 0x40000000) == 0 )
            {
              do
                v88 = __ldrex((unsigned int *)a1);
              while ( v88 == v58 && __strex(v58 | 0x40000000, (unsigned int *)a1) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
        v96 = v55;
      }
LABEL_56:
      v9 = (unsigned int *)a1;
      if ( !a4 )
        break;
      v6 = a6;
    }
  }
  MiUnlockWorkingSetExclusive(v9, v96);
  return MiFlushTbList(&v103);
}
