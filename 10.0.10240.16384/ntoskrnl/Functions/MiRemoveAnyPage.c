// MiRemoveAnyPage 
 
unsigned int __fastcall MiRemoveAnyPage(_DWORD *a1, unsigned int a2, int a3)
{
  unsigned int *v3; // lr
  int v4; // r5
  int v6; // r10
  int v7; // r4
  int *v8; // r7
  int v9; // r6
  int v10; // r3
  int v11; // r0
  _DWORD *v12; // r6
  unsigned int v13; // r7
  int v14; // r4
  unsigned int result; // r0
  int v16; // r0
  unsigned __int8 *v17; // r3
  unsigned int v18; // r1
  unsigned int *v19; // r0
  unsigned int v20; // r1
  int v21; // r4
  char v22; // r3
  unsigned int v23; // r2
  unsigned int *v24; // r1
  unsigned int v25; // r0
  int v26; // r3
  unsigned int *v27; // r2
  unsigned int v28; // r0
  unsigned int v29; // r6
  unsigned int *v30; // r0
  unsigned int v31; // r3
  unsigned int v32; // r6
  unsigned int v33; // r6
  __int64 v34; // r2
  bool v35; // zf
  unsigned int *v36; // r2
  unsigned int v37; // r0
  unsigned int v38; // r4
  unsigned int v39; // r3
  unsigned int v40; // r3
  int v41; // r1
  int v42; // r0
  unsigned int *v43; // r1
  int *v44; // r0
  unsigned int v45; // r3
  unsigned int *v46; // r2
  unsigned int v47; // r0
  unsigned int *v48; // r2
  unsigned int v49; // r0
  unsigned int *v50; // r10
  int v51; // r0
  int v52; // r0
  int v53; // r0
  int v54; // r0
  _DWORD *v55; // r0
  unsigned int v56; // r3
  unsigned int *v57; // r2
  unsigned int v58; // r0
  unsigned int v59; // r0
  unsigned int v60; // r1
  _DWORD *v61; // r0
  int v62; // r0
  _DWORD *v63; // lr
  unsigned int v64; // r0
  unsigned int v65; // r0
  int v66; // r0
  unsigned int *v67; // r1
  int *v68; // r0
  unsigned int *v69; // r2
  unsigned int v70; // r0
  unsigned int v71; // r0
  unsigned int v72; // r0
  int v73; // r2
  unsigned int v74; // r0
  unsigned int v75; // r0
  unsigned int *v76; // r3
  unsigned int v77; // r2
  int v78; // r1
  unsigned int v79; // r0
  unsigned int v80; // r0
  int v81; // r0
  unsigned int *v82; // r1
  int *v83; // r4
  unsigned int *v84; // r2
  unsigned int v85; // r4
  int v86; // r6
  int v87; // r2
  _DWORD *v88; // r0
  unsigned int v89; // r4
  int v90; // r2
  unsigned __int8 v91; // [sp+0h] [bp-50h] BYREF
  unsigned __int8 v92; // [sp+1h] [bp-4Fh] BYREF
  char v93[2]; // [sp+2h] [bp-4Eh] BYREF
  unsigned int *v94; // [sp+4h] [bp-4Ch]
  int v95; // [sp+8h] [bp-48h]
  int v96; // [sp+Ch] [bp-44h]
  int v97; // [sp+10h] [bp-40h]
  unsigned int v98; // [sp+14h] [bp-3Ch]
  int v99; // [sp+18h] [bp-38h]
  unsigned int *v100; // [sp+1Ch] [bp-34h]
  unsigned int v101; // [sp+20h] [bp-30h]
  int v102; // [sp+28h] [bp-28h] BYREF
  unsigned int *v103; // [sp+2Ch] [bp-24h]

  v3 = (unsigned int *)(a3 & 2);
  v99 = a3;
  v100 = v3;
  v4 = a2;
  if ( (a3 & 2) != 0 )
  {
    v6 = 0;
    v7 = 1;
  }
  else
  {
    v6 = 1;
    v7 = 0;
  }
  v8 = MiState;
  v97 = v7;
  v9 = dword_633814;
  v94 = (unsigned int *)a2;
  v10 = a1[6];
  v96 = dword_633814;
  v11 = v10 + 104 * (a2 >> byte_6337F5);
  if ( *(_DWORD *)(v11 + 4 * v6 + 56) )
  {
    while ( 1 )
    {
      while ( 1 )
      {
LABEL_4:
        while ( 1 )
        {
          v12 = (_DWORD *)(a1[v6 + 256] + 20 * v4);
          v13 = v12[2];
          if ( v13 != 0xFFFFF )
            break;
LABEL_5:
          v9 = v96;
          v4 = (v4 + 1) & v96 | v4 & ~v96;
          if ( (unsigned int *)v4 == v94 )
          {
            if ( v6 == v97 )
            {
              v8 = MiState;
              v3 = v100;
              goto LABEL_70;
            }
            v6 = v97;
          }
        }
        v14 = MmPfnDatabase + 24 * v13;
        v98 = v14;
        if ( (v99 & 1) != 0 )
          return sub_536B4C(1, &KfRaiseIrql);
        v16 = KfRaiseIrql(2);
        v95 = v16;
        v17 = (unsigned __int8 *)(v14 + 15);
        do
          v18 = __ldrex(v17);
        while ( __strex(v18 | 0x80, v17) );
        __dmb(0xBu);
        if ( v18 >> 7 )
          goto LABEL_68;
        if ( (*(_BYTE *)(v14 + 18) & 7) == v6 )
          break;
        __dmb(0xBu);
        v57 = (unsigned int *)(v14 + 12);
        if ( v16 == 17 )
          goto LABEL_100;
        do
          v58 = __ldrex(v57);
        while ( __strex(v58 & 0x7FFFFFFF, v57) );
LABEL_84:
        KfLowerIrql(v95);
      }
      v19 = v12 + 4;
      v102 = 0;
      v103 = v12 + 4;
      __dmb(0xBu);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        if ( !KiTryToAcquireQueuedSpinLockInstrumented(&v102, v12 + 4) )
          goto LABEL_65;
      }
      else
      {
        do
          v20 = __ldrex(v19);
        while ( !v20 && __strex((unsigned int)&v102, v19) );
        __dmb(0xBu);
        if ( v20 )
        {
          __dmb(0xAu);
          __yield();
LABEL_65:
          v35 = v95 == 17;
          __dmb(0xBu);
          v48 = (unsigned int *)(v14 + 12);
          if ( v35 )
          {
            do
              v65 = __ldrex(v48);
            while ( __strex(v65 & 0x7FFFFFFF, v48) );
            goto LABEL_5;
          }
          do
            v49 = __ldrex(v48);
          while ( __strex(v49 & 0x7FFFFFFF, v48) );
          v16 = v95;
LABEL_68:
          KfLowerIrql(v16);
          goto LABEL_5;
        }
      }
      if ( v13 == v12[2] )
      {
        v21 = MmPfnDatabase + 24 * v13;
        v22 = *(_BYTE *)(v21 + 18);
        v23 = *(_DWORD *)(v21 + 20);
        v96 = v21;
        v97 = v22 & 7;
        v24 = *(unsigned int **)&MiSystemPartition[2 * v97 + 1226];
        v101 = dword_633814 & v13 | (v23 >> 28 << byte_6337F5);
        do
          v25 = __ldrex(v24);
        while ( __strex(v25 - 1, v24) );
        if ( dword_634380 != 1 )
        {
LABEL_22:
          --*v12;
          if ( v12[2] == v13 )
          {
            v26 = *(_DWORD *)v21;
            v12[2] = *(_DWORD *)v21;
            if ( v26 == 0xFFFFF )
            {
              v12[3] = 0xFFFFF;
            }
            else
            {
              v27 = (unsigned int *)(MmPfnDatabase + 24 * v26 + 12);
              v28 = *v27;
              v100 = v27;
              do
                v29 = __ldrex(v27);
              while ( v29 == v28 && __strex(v28 | 0xFFFFF, v27) );
              if ( v28 != v29 )
              {
                do
                {
                  v59 = v29;
                  do
                    v60 = __ldrex(v100);
                  while ( v60 == v29 && __strex(v29 | 0xFFFFF, v100) );
                  v29 = v60;
                }
                while ( v59 != v60 );
                v21 = v96;
              }
            }
          }
          else
          {
            *(_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)(v21 + 12) & 0xFFFFF)) = *(_DWORD *)v21;
            if ( *(_DWORD *)v21 == 0xFFFFF )
              v12[3] = *(_DWORD *)(v21 + 12) & 0xFFFFF;
            else
              MiSetPfnBlink(MmPfnDatabase + 24 * *(_DWORD *)v21, *(_DWORD *)(v21 + 12) & 0xFFFFF, 0);
          }
          *(_BYTE *)(v21 + 18) = *(_BYTE *)(v21 + 18) & 0xF8 | 5;
          v100 = (unsigned int *)(unsigned __int8)byte_634378;
          v30 = (unsigned int *)(dword_63F718 + 104 * (v101 >> byte_6337F5) + 4 * (v97 + 14));
          do
            v31 = __ldrex(v30);
          while ( __strex(v31 - 1, v30) );
          do
          {
            v32 = __ldrex((unsigned int *)&dword_640580);
            v33 = v32 - 1;
          }
          while ( __strex(v33, (unsigned int *)&dword_640580) );
          if ( v33 == dword_6402AC || v33 == dword_6402B0 )
            MiUpdateAvailableEvents(MiSystemPartition);
          if ( v33 <= 0x400 && (!dword_6404B8 || !*(_BYTE *)(dword_6404B8 + 44)) )
            MiObtainFreePages(MiSystemPartition);
          HIDWORD(v34) = *(_DWORD *)(v21 + 12);
          *(_DWORD *)v21 = 0;
          *(_QWORD *)(v21 + 8) = v34 & 0xFFF0000000000000ui64;
          if ( v97 == 1 || v100 == (unsigned int *)1 )
            *(_DWORD *)(v21 + 8) = 128;
          v35 = v95 == 17;
          __dmb(0xBu);
          v36 = (unsigned int *)(v98 + 12);
          if ( v35 )
          {
            do
              v80 = __ldrex(v36);
            while ( __strex(v80 & 0x7FFFFFFF, v36) );
          }
          else
          {
            do
              v37 = __ldrex(v36);
            while ( __strex(v37 & 0x7FFFFFFF, v36) );
          }
          if ( (v99 & 1) == 0 )
          {
            v38 = *(unsigned __int16 *)(a1[v6 + 258] + 8 * v4 + 4);
            if ( v6 == 1 )
            {
              v45 = a1[813];
              if ( v38 < v45 )
              {
                v40 = v45 - v38;
                v41 = 1;
LABEL_44:
                MiReplenishPageSlist(a1, v41, v4, v40);
              }
            }
            else
            {
              if ( !*(_DWORD *)(v98 + 8)
                && (MiFlags & 0x80) != 0
                && v13 < 0x200000
                && (*(_BYTE *)(MmPfnDatabase + 24 * v13 + 19) & 0x40) == 0
                && (MmPageValidationFrequency & ++dword_634414) == 0 )
              {
                if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384) )
                {
                  v86 = MiMapPageInHyperSpaceWorker(v13, &v91, 0x80000000);
                  if ( RtlCompareMemoryUlong(v86, 4096, 0) != 4096 )
                    MiPageNotZero(v86, v13);
                  MiUnmapPageInHyperSpaceWorker(v86, v91, 0x80000000);
                }
              }
              v39 = a1[813];
              if ( v38 < v39 )
              {
                v40 = v39 - v38;
                v41 = 0;
                goto LABEL_44;
              }
            }
            if ( (dword_682604 & 0x10000) != 0 )
            {
              KiReleaseQueuedSpinLockInstrumented(&v102);
            }
            else
            {
              v42 = v102;
              if ( !v102 )
              {
                v43 = v103;
                __dmb(0xBu);
                do
                  v44 = (int *)__ldrex(v43);
                while ( v44 == &v102 && __strex(0, v43) );
                if ( v44 == &v102 )
                  goto LABEL_51;
                v42 = KxWaitForLockChainValid(&v102);
              }
              v102 = 0;
              __dmb(0xBu);
              v46 = (unsigned int *)(v42 + 4);
              do
                v47 = __ldrex(v46);
              while ( __strex(v47 ^ 1, v46) );
            }
LABEL_51:
            KfLowerIrql(v95);
            return v13;
          }
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseQueuedSpinLockInstrumented(&v102);
          }
          else
          {
            v81 = v102;
            if ( !v102 )
            {
              v82 = v103;
              __dmb(0xBu);
              do
                v83 = (int *)__ldrex(v82);
              while ( v83 == &v102 && __strex(0, v82) );
              if ( v83 == &v102 )
                return v13;
              v81 = KxWaitForLockChainValid(&v102);
            }
            v102 = 0;
            __dmb(0xBu);
            v84 = (unsigned int *)(v81 + 4);
            do
              v85 = __ldrex(v84);
            while ( __strex(v85 ^ 1, v84) );
          }
          return v13;
        }
        LOBYTE(v72) = 1;
        v73 = v13 & 0x1F;
        v94 = (unsigned int *)(*(_DWORD *)(dword_634388 + 4) + 4 * (v13 >> 5));
        if ( (unsigned int)(v73 + 1) <= 0x20 )
        {
          __dmb(0xBu);
          do
            v74 = __ldrex(v94);
          while ( __strex(v74 | (1 << v73), v94) );
          goto LABEL_133;
        }
        if ( (v13 & 0x1F) == 0 )
          goto LABEL_131;
        v100 = (unsigned int *)(32 - v73);
        __dmb(0xBu);
        do
          v75 = __ldrex(v94);
        while ( __strex(v75 | (((1 << (32 - v73)) - 1) << v73), v94) );
        __dmb(0xBu);
        v72 = 1 - (_DWORD)v100;
        v76 = ++v94;
        if ( (unsigned int)(1 - (_DWORD)v100) >= 0x20 )
        {
          v77 = v72 >> 5;
          do
          {
            v72 -= 32;
            --v77;
            *v76++ = -1;
          }
          while ( v77 );
          v94 = v76;
        }
        if ( v72 )
        {
LABEL_131:
          v78 = (1 << v72) - 1;
          __dmb(0xBu);
          do
            v79 = __ldrex(v94);
          while ( __strex(v79 | v78, v94) );
LABEL_133:
          __dmb(0xBu);
        }
        v21 = v96;
        goto LABEL_22;
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseQueuedSpinLockInstrumented(&v102);
        goto LABEL_116;
      }
      v66 = v102;
      if ( v102 )
        goto LABEL_114;
      v67 = v103;
      __dmb(0xBu);
      do
        v68 = (int *)__ldrex(v67);
      while ( v68 == &v102 && __strex(0, v67) );
      if ( v68 != &v102 )
        break;
LABEL_116:
      v35 = v95 == 17;
      __dmb(0xBu);
      v57 = (unsigned int *)(v14 + 12);
      if ( !v35 )
      {
        do
          v71 = __ldrex(v57);
        while ( __strex(v71 & 0x7FFFFFFF, v57) );
        goto LABEL_84;
      }
      do
LABEL_100:
        v64 = __ldrex(v57);
      while ( __strex(v64 & 0x7FFFFFFF, v57) );
    }
    v66 = KxWaitForLockChainValid(&v102);
LABEL_114:
    v102 = 0;
    __dmb(0xBu);
    v69 = (unsigned int *)(v66 + 4);
    do
      v70 = __ldrex(v69);
    while ( __strex(v70 ^ 1, v69) );
    goto LABEL_116;
  }
  while ( v6 != v7 )
  {
    v6 = v7;
    if ( *(_DWORD *)(v11 + 4 * v7 + 56) )
      goto LABEL_4;
  }
LABEL_70:
  v50 = v94;
  v96 = 715827883;
  while ( v3 )
  {
    v53 = a1[258] + 8 * v4;
    if ( *(_WORD *)(v53 + 4) )
    {
      v62 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v53);
      v63 = (_DWORD *)v62;
      v101 = v62;
      if ( v62 )
      {
        result = ((int)((unsigned __int64)((v62 - MmPfnDatabase) * (__int64)v96) >> 32) >> 2)
               + ((unsigned int)((unsigned __int64)((v62 - MmPfnDatabase) * (__int64)v96) >> 32) >> 31);
        v63[2] = 0;
        v98 = result;
        if ( (MiFlags & 0x80) != 0 && result < 0x200000 && (*(_BYTE *)(MmPfnDatabase + 24 * result + 19) & 0x40) == 0 )
        {
          v87 = v8[1637] + 1;
          v8[1637] = v87;
          if ( (MmPageValidationFrequency & v87) == 0 )
          {
            if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384) )
            {
              v99 = MiMapPageInHyperSpaceWorker(result, &v92, 0x80000000);
              if ( RtlCompareMemoryUlong(v99, 4096, 0) != 4096 )
                MiPageNotZero(v99, v98);
              MiUnmapPageInHyperSpaceWorker(v99, v92, 0x80000000);
              v63 = (_DWORD *)v101;
              result = v98;
            }
          }
        }
        *v63 = 0;
        if ( result != -1 )
          return result;
      }
    }
    v54 = a1[259] + 8 * v4;
    if ( *(_WORD *)(v54 + 4) )
    {
      v55 = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)v54);
      if ( v55 )
      {
        v56 = ((int)((unsigned __int64)(((int)v55 - MmPfnDatabase) * (__int64)v96) >> 32) >> 2)
            + ((unsigned int)((unsigned __int64)(((int)v55 - MmPfnDatabase) * (__int64)v96) >> 32) >> 31);
        v55[2] = 128;
        *v55 = 0;
        if ( v56 != -1 )
          return v56;
      }
    }
LABEL_74:
    v4 = (v4 + 1) & v9 | v4 & ~v9;
    if ( (unsigned int *)v4 == v50 )
      return -1;
    v3 = v100;
  }
  v51 = a1[259] + 8 * v4;
  if ( *(_WORD *)(v51 + 4) )
  {
    v61 = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)v51);
    if ( v61 )
    {
      v56 = ((int)((unsigned __int64)(((int)v61 - MmPfnDatabase) * (__int64)v96) >> 32) >> 2)
          + ((unsigned int)((unsigned __int64)(((int)v61 - MmPfnDatabase) * (__int64)v96) >> 32) >> 31);
      v61[2] = 128;
      *v61 = 0;
      if ( v56 != -1 )
        return v56;
    }
  }
  v52 = a1[258] + 8 * v4;
  if ( !*(_WORD *)(v52 + 4) )
    goto LABEL_74;
  v88 = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)v52);
  v101 = (unsigned int)v88;
  if ( !v88 )
    goto LABEL_74;
  v89 = ((int)((unsigned __int64)(((int)v88 - MmPfnDatabase) * (__int64)v96) >> 32) >> 2)
      + ((unsigned int)((unsigned __int64)(((int)v88 - MmPfnDatabase) * (__int64)v96) >> 32) >> 31);
  v88[2] = 0;
  if ( (MiFlags & 0x80) != 0 && v89 < 0x200000 && (*(_BYTE *)(MmPfnDatabase + 24 * v89 + 19) & 0x40) == 0 )
  {
    v90 = v8[1637] + 1;
    v8[1637] = v90;
    if ( (MmPageValidationFrequency & v90) == 0 )
    {
      if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384) )
      {
        v99 = MiMapPageInHyperSpaceWorker(v89, v93, 0x80000000);
        if ( RtlCompareMemoryUlong(v99, 4096, 0) != 4096 )
          MiPageNotZero(v99, v89);
        MiUnmapPageInHyperSpaceWorker(v99, (unsigned __int8)v93[0], 0x80000000);
        v88 = (_DWORD *)v101;
      }
    }
  }
  *v88 = 0;
  if ( v89 == -1 )
    goto LABEL_74;
  return v89;
}
