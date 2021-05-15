// KiWaitForAllObjects 
 
int __fastcall KiWaitForAllObjects(unsigned int a1, int *a2, char a3, char a4, char a5, int a6, int *a7)
{
  int v7; // r8
  unsigned int v8; // r6
  char *v9; // r5
  unsigned int *v10; // r8
  unsigned int v11; // r7
  unsigned int v12; // t1
  unsigned int v13; // lr
  unsigned int v14; // r4
  char v15; // r2
  __int64 v16; // kr00_8
  unsigned int v17; // r2
  unsigned int v18; // r1
  int v20; // r3
  unsigned int *v21; // r5
  unsigned int v22; // r6
  int v23; // r3
  unsigned int v24; // r3
  unsigned int v25; // r2
  unsigned int v26; // r10
  int *v27; // r2
  unsigned int v28; // r8
  int *v29; // r1
  unsigned int v30; // r0
  int v31; // t1
  unsigned int v32; // r6
  int *v33; // r7
  int *v34; // r2
  int *v35; // t1
  int v36; // r7
  __int64 v37; // r6
  __int64 v38; // r0
  int v39; // r2
  unsigned int v40; // r3
  bool v41; // cf
  unsigned int v42; // r1
  unsigned int v43; // r0
  unsigned int v44; // r6
  unsigned int v45; // r2
  unsigned int v46; // r6
  int *v47; // r2
  int v48; // r1
  int **v49; // r0
  int v50; // r10
  int v51; // r1
  int v52; // r0
  unsigned int v53; // r6
  int *v54; // r0
  _BYTE *v55; // r1
  _BYTE *v56; // t1
  char v57; // r2
  unsigned int v58; // r3
  int v59; // r3
  unsigned int v60; // r2
  char v61; // r2
  int v62; // r3
  _BYTE *v63; // r2
  _DWORD *v64; // r0
  char *v65; // r4
  int v66; // t1
  unsigned int v67; // r3
  unsigned int v68; // r7
  int v69; // r3
  int v70; // r8
  unsigned int *v71; // r1
  unsigned int v72; // r2
  __int64 v73; // r0
  __int64 v74; // kr18_8
  unsigned __int64 *v75; // r6
  unsigned __int64 v76; // kr20_8
  unsigned __int64 v77; // kr28_8
  __int64 v78; // r2
  char v79; // r9
  unsigned int v80; // r6
  int v81; // r4
  unsigned int v82; // r5
  unsigned __int64 *v83; // r4
  unsigned __int64 v84; // kr30_8
  unsigned __int64 v85; // kr38_8
  unsigned int v86; // r3
  unsigned int v87; // r2
  unsigned int v88; // r3
  unsigned int v89; // r2
  unsigned int v90; // r2
  int v91; // r1
  int i; // r1
  int v93; // r4
  void (__fastcall **v94)(int); // r3
  int v95; // r0
  int v96; // [sp+8h] [bp-160h]
  int *v98; // [sp+Ch] [bp-15Ch]
  unsigned __int64 v99; // [sp+10h] [bp-158h]
  int v100; // [sp+18h] [bp-150h]
  unsigned int v101; // [sp+20h] [bp-148h]
  int v103; // [sp+24h] [bp-144h]
  int v105; // [sp+30h] [bp-138h]
  unsigned __int64 v106; // [sp+38h] [bp-130h]
  int v107; // [sp+38h] [bp-130h]
  int v108; // [sp+38h] [bp-130h]
  int v109; // [sp+48h] [bp-120h] BYREF
  char v110; // [sp+4Ch] [bp-11Ch] BYREF

  v7 = a4;
  v96 = a4;
  v8 = 1;
  v109 = *a2;
  if ( a1 > 1 )
  {
    v9 = &v110;
    v10 = (unsigned int *)(a2 + 1);
    do
    {
      v12 = *v10++;
      v11 = v12;
      v13 = v8;
      if ( *((_DWORD *)v9 - 1) > v12 )
      {
        v65 = v9;
        do
        {
          v66 = *((_DWORD *)v65 - 1);
          v65 -= 4;
          --v13;
          *((_DWORD *)v65 + 1) = v66;
        }
        while ( v13 && *((_DWORD *)v65 - 1) > v11 );
      }
      ++v8;
      v9 += 4;
      *(&v109 + v13) = v11;
    }
    while ( v8 < a1 );
    v7 = a4;
  }
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_BYTE *)(v14 + 0x4C);
  v101 = v14;
  *(_BYTE *)(v14 + 76) = v15 & 0xFB;
  v105 = (unsigned __int8)(v15 & 4) >> 2;
  if ( !v105 )
    *(_BYTE *)(v14 + 134) = KfRaiseIrql(2);
  if ( a6 )
  {
    if ( *(int *)(a6 + 4) >= 0 )
    {
      v99 = *(_QWORD *)a6;
      v20 = 1;
    }
    else
    {
      v16 = MEMORY[0xFFFF93B0];
      v17 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v18 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v17 != MEMORY[0xFFFF9010] )
        return sub_5226C8(v16, v18);
      v7 = v96;
      v99 = __PAIR64__(v17, v18) - v16 - *(_QWORD *)(v14 + 160) - *(_QWORD *)a6;
      v20 = 2;
    }
    v100 = v20;
  }
  else
  {
    v100 = 0;
    v99 = v106;
  }
  v21 = (unsigned int *)(v14 + 44);
  while ( 2 )
  {
    v22 = *(unsigned __int8 *)(v14 + 134);
    v107 = v22;
    while ( 1 )
    {
      v23 = *(_DWORD *)(v14 + 76);
      *(_BYTE *)(v14 + 72) = 0;
      v24 = v23 & 0xFFFFFFEF;
      *(_DWORD *)(v14 + 76) = v24;
      *(_BYTE *)(v14 + 135) = v7;
      if ( a5 )
        *(_DWORD *)(v14 + 76) = v24 | 0x10;
      while ( 1 )
      {
        do
          v25 = __ldrex(v21);
        while ( __strex(1u, v21) );
        __dmb(0xBu);
        if ( !v25 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v21 );
      }
      if ( !*(_BYTE *)(v14 + 121) || *(_WORD *)(v14 + 310) || v22 )
        break;
      __dmb(0xBu);
      *v21 = 0;
      KfLowerIrql(1);
      KiDeliverApc(0, 0, 0);
      KfRaiseIrql(2);
      *(_BYTE *)(v14 + 134) = 0;
    }
    v26 = a1;
    if ( a5 )
    {
      if ( *(_BYTE *)(v7 + v14 + 74) )
      {
        *(_BYTE *)(v7 + v14 + 74) = 0;
      }
      else
      {
        if ( v7 && *(_DWORD *)(v14 + 108) != v14 + 108 )
        {
          *(_BYTE *)(v14 + 122) = 1;
          goto LABEL_87;
        }
        if ( !*(_BYTE *)(v14 + 74) )
          goto LABEL_23;
        *(_BYTE *)(v14 + 74) = 0;
      }
      v50 = 257;
LABEL_88:
      __dmb(0xBu);
      *v21 = 0;
      v67 = (unsigned int)KeGetPcr();
      v68 = (v67 & 0xFFFFF000) + 1408;
      v69 = *(_DWORD *)((v67 & 0xFFFFF000) + 0x588);
      if ( v22 >= 2 )
      {
        if ( !v69 || *(_BYTE *)(v68 + 1754) )
          return v50;
        v94 = (void (__fastcall **)(int))&HalRequestSoftwareInterrupt;
        v95 = 2;
LABEL_164:
        (*v94)(v95);
        return v50;
      }
      v70 = *(_DWORD *)(v68 + 4);
      if ( v69 )
      {
        KiAbProcessContextSwitch(*(_DWORD *)(v68 + 4), 0);
        v71 = (unsigned int *)(v68 + 24);
        while ( 1 )
        {
          do
            v72 = __ldrex(v71);
          while ( __strex(1u, v71) );
          __dmb(0xBu);
          if ( !v72 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v71 );
        }
        v103 = *(_DWORD *)(v68 + 8);
        *(_DWORD *)(v68 + 8) = 0;
        __disable_irq();
        *(_BYTE *)(v68 + 16) = 1;
        LODWORD(v73) = ReadTimeStampCounter();
        v75 = (unsigned __int64 *)(v70 + 48);
        v74 = v73 - *(_QWORD *)(v68 + 2376);
        v76 = *(_QWORD *)(v70 + 48) + v74;
        __dmb(0xBu);
        do
          v77 = __ldrexd(v75);
        while ( __strexd(v76, v75) );
        __dmb(0xBu);
        v78 = v74 + *(unsigned int *)(v70 + 56);
        if ( HIDWORD(v78) )
          LODWORD(v78) = -1;
        *(_QWORD *)(v68 + 2376) = v73;
        v79 = *(_BYTE *)(v70 + 2);
        *(_DWORD *)(v70 + 56) = v78;
        if ( (v79 & 0x3E) != 0 )
        {
          if ( (v79 & 0x10) != 0 )
          {
            v80 = v68 + 8 * *(unsigned __int8 *)(v70 + 84);
            *(_QWORD *)(v80 + 2392) = *(_QWORD *)(v80 + 2392) - *(_QWORD *)(v68 + 2384) + *(_QWORD *)(v68 + 2376);
            *(_DWORD *)(v68 + 2384) = 0;
            *(_DWORD *)(v68 + 2388) = 0;
            v79 &= 0xEFu;
          }
          if ( (v79 & 0x3E) != 0 )
          {
            if ( (v79 & 0x20) != 0 )
            {
              v81 = *(_DWORD *)(v70 + 1084);
              if ( v81 )
              {
                v82 = HIDWORD(v74);
                v83 = (unsigned __int64 *)(v81 + 8 * (*(unsigned __int8 *)(v68 + 2986) + 2 * PoGetFrequencyBucket(v68)));
                v84 = *v83 + v74;
                __dmb(0xBu);
                do
                  v85 = __ldrexd(v83);
                while ( __strexd(v84, v83) );
                __dmb(0xBu);
              }
              else
              {
                v82 = HIDWORD(v74);
              }
              v79 &= 0xDFu;
            }
            else
            {
              v82 = HIDWORD(v74);
            }
            if ( (v79 & 0x3E) != 0 )
            {
              v91 = *(_DWORD *)(v70 + 68);
              if ( v91 )
              {
                for ( i = v91 + *(_DWORD *)(v68 + 2352); i; i = *(_DWORD *)(i + 236) )
                  *(_QWORD *)i += __PAIR64__(v82, v74);
              }
              if ( (*(_BYTE *)(v70 + 2) & 8) != 0
                && (*(_DWORD *)(*(_DWORD *)(v68 + 2360) + 260) & *(_DWORD *)(v70 + 356)) != *(_DWORD *)(*(_DWORD *)(v68 + 2360) + 260) )
              {
                *(_QWORD *)(v68 + 2368) += __PAIR64__(v82, v74);
              }
              if ( *(_DWORD *)(v70 + 236) )
                KiEndCounterAccumulation(v70);
            }
          }
        }
        v93 = v103;
        __enable_irq();
        *(_DWORD *)(v68 + 4) = v93;
        *(_BYTE *)(v93 + 132) = 2;
        *(_BYTE *)(v70 + 395) = 32;
        v22 = v107;
        *(_BYTE *)(v70 + 134) = v107;
        KiQueueReadyThread(v68, v70);
        if ( !KiSwapContext(v70, v93, v107) )
          goto LABEL_160;
      }
      else if ( (*(_DWORD *)(v70 + 76) & 0x40) == 0 )
      {
LABEL_160:
        v94 = (void (__fastcall **)(int))&KfLowerIrql;
        v95 = v22;
        goto LABEL_164;
      }
      KfLowerIrql(1);
      *(_DWORD *)(v70 + 76) &= 0xFFFFFFBF;
      KiDeliverApc(0, 0, 0);
      goto LABEL_160;
    }
    if ( (*(_BYTE *)(v14 + 122) & (unsigned __int8)v7) != 0 )
    {
LABEL_87:
      v50 = 192;
      goto LABEL_88;
    }
LABEL_23:
    *(_BYTE *)(v14 + 132) = 5;
    *(_BYTE *)(v14 + 395) = a3;
    __dmb(0xBu);
    *v21 = 0;
    *(_DWORD *)(v14 + 304) = KeTickCount;
    v27 = a7;
    v28 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    if ( a1 )
    {
      v29 = a2;
      v30 = a1;
      do
      {
        v31 = *v29++;
        *((_BYTE *)v27 + 8) = 0;
        *((_BYTE *)v27 + 9) = 4;
        v27[3] = v14;
        v27[4] = v31;
        *((_WORD *)v27 + 5) = 0;
        v27 += 6;
        --v30;
      }
      while ( v30 );
    }
    v32 = 0;
    *(_DWORD *)(v14 + 136) = 0;
    KiLockKobjectArray(&v109, a1, v27);
    v33 = a2;
    do
    {
      v35 = (int *)*v33++;
      v34 = v35;
      if ( (*(_BYTE *)v35 & 0x7F) != 2 )
      {
        if ( v34[1] <= 0 )
          break;
        goto LABEL_45;
      }
      v51 = *(unsigned __int8 *)(v28 + 1754);
      v52 = v34[6];
      if ( v14 == v52 && *((unsigned __int8 *)v34 + 2) == v51 && v34[1] == 0x80000000 )
      {
        KiUnlockKobjectArray(&v109, a1);
        *(_BYTE *)(v14 + 132) = 2;
        __dmb(0xFu);
        v86 = *v21;
        __dmb(0xBu);
        if ( v86 )
        {
          while ( 1 )
          {
            do
              v87 = __ldrex(v21);
            while ( __strex(1u, v21) );
            __dmb(0xBu);
            if ( !v87 )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( *v21 );
          }
          __dmb(0xBu);
          *v21 = 0;
        }
        KiExitThreadWait(v28, v14, v105);
        RtlRaiseStatus(-1073741423);
      }
      if ( v34[1] <= 0 && (v14 != v52 || *((unsigned __int8 *)v34 + 2) != v51) )
        break;
LABEL_45:
      ++v32;
    }
    while ( v32 < a1 );
    if ( v32 == a1 )
    {
      v53 = 0;
      if ( a1 )
      {
        v54 = a2;
        do
        {
          v56 = (_BYTE *)*v54++;
          v55 = v56;
          v57 = *v56;
          v98 = v54;
          if ( (*v56 & 7) == 1 )
          {
            *((_DWORD *)v55 + 1) = 0;
          }
          else if ( (v57 & 0x7F) == 5 )
          {
            --*((_DWORD *)v55 + 1);
          }
          else if ( (v57 & 0x7F) == 2 )
          {
            v59 = *((_DWORD *)v55 + 1) - 1;
            *((_DWORD *)v55 + 1) = v59;
            if ( !v59 )
            {
              while ( 1 )
              {
                do
                  v60 = __ldrex(v21);
                while ( __strex(1u, v21) );
                __dmb(0xBu);
                if ( !v60 )
                  break;
                do
                {
                  __dmb(0xAu);
                  __yield();
                }
                while ( *v21 );
              }
              *(_WORD *)(v14 + 308) -= (unsigned __int8)v55[29];
              if ( *(_DWORD *)(v28 + 4) == v14 )
                v61 = *(_BYTE *)(v28 + 1754);
              else
                v61 = 0;
              v108 = *(_DWORD *)v55;
              BYTE2(v108) = v61;
              *(_DWORD *)v55 = v108;
              v62 = (unsigned __int8)v55[28];
              *((_DWORD *)v55 + 6) = v14;
              if ( v62 )
              {
                v55[28] = 0;
                *(_DWORD *)(v14 + 136) |= 0x80u;
              }
              v63 = v55 + 16;
              v64 = *(_DWORD **)(v14 + 480);
              *((_DWORD *)v55 + 4) = v14 + 476;
              *((_DWORD *)v55 + 5) = v64;
              if ( *v64 != v14 + 476 )
                __fastfail(3u);
              *v64 = v63;
              *(_DWORD *)(v14 + 480) = v63;
              __dmb(0xBu);
              v54 = v98;
              *v21 = 0;
            }
          }
          ++v53;
        }
        while ( v53 < a1 );
      }
      KiUnlockKobjectArray(&v109, a1);
      v50 = *(_DWORD *)(v14 + 136);
      *(_BYTE *)(v14 + 132) = 2;
      __dmb(0xFu);
      v58 = *v21;
      __dmb(0xBu);
      if ( v58 )
      {
        while ( 1 )
        {
          do
            v90 = __ldrex(v21);
          while ( __strex(1u, v21) );
          __dmb(0xBu);
          if ( !v90 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v21 );
        }
        __dmb(0xBu);
        *v21 = 0;
      }
      KiExitThreadWait(v28, v14, v105);
    }
    else
    {
      v36 = v100;
      if ( v100 == 2 )
      {
        v37 = MEMORY[0xFFFF93B0];
        while ( 1 )
        {
          HIDWORD(v38) = MEMORY[0xFFFF900C];
          __dmb(0xBu);
          LODWORD(v38) = MEMORY[0xFFFF9008];
          __dmb(0xBu);
          if ( HIDWORD(v38) == MEMORY[0xFFFF9010] )
            break;
          __dmb(0xAu);
          __yield();
        }
        v14 = v101;
        v26 = a1;
        v21 = (unsigned int *)(v101 + 44);
        v39 = (unsigned __int64)(v38 - *(_QWORD *)(v101 + 160)) >> 32;
        v40 = v38 - *(_DWORD *)(v101 + 160);
        v41 = v40 >= (unsigned int)v37;
        v42 = v40 - v37;
        LODWORD(v37) = HIDWORD(v99);
        v43 = v99;
        v45 = v39 - (HIDWORD(v37) + !v41);
        v36 = 2;
        goto LABEL_34;
      }
      if ( !v100 )
        goto LABEL_37;
      v44 = HIDWORD(v99);
      v43 = v99;
      if ( !v99 )
        goto LABEL_125;
      while ( 1 )
      {
        v45 = MEMORY[0xFFFF9018];
        __dmb(0xBu);
        v42 = MEMORY[0xFFFF9014];
        __dmb(0xBu);
        if ( v45 == MEMORY[0xFFFF901C] )
          break;
        __dmb(0xAu);
        __yield();
      }
LABEL_34:
      if ( v45 > v44 || v45 >= v44 && v42 > v43 )
      {
LABEL_125:
        KiUnlockKobjectArray(&v109, v26);
        *(_BYTE *)(v14 + 132) = 2;
        __dmb(0xFu);
        v88 = *v21;
        __dmb(0xBu);
        if ( v88 )
        {
          while ( 1 )
          {
            do
              v89 = __ldrex(v21);
            while ( __strex(1u, v21) );
            __dmb(0xBu);
            if ( !v89 )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( *v21 );
          }
          __dmb(0xBu);
          *v21 = 0;
        }
        KiExitThreadWait(v28, v14, v105);
        v50 = 258;
      }
      else
      {
LABEL_37:
        v46 = 0;
        if ( v26 )
        {
          v47 = a7;
          do
          {
            v48 = v47[4] + 8;
            v49 = *(int ***)(v47[4] + 12);
            *v47 = v48;
            v47[1] = (int)v49;
            if ( *v49 != (int *)v48 )
              __fastfail(3u);
            *v49 = v47;
            *(_DWORD *)(v48 + 4) = v47;
            ++v46;
            v47 += 6;
          }
          while ( v46 < v26 );
        }
        KiUnlockKobjectArray(&v109, v26);
        *(_BYTE *)(v14 + 363) = v26;
        v50 = KiCommitThreadWait(v14, a7, v36);
        if ( v50 == 256 )
        {
          v105 = 0;
          v7 = v96;
          *(_BYTE *)(v14 + 134) = KfRaiseIrql(2);
          continue;
        }
      }
    }
    return v50;
  }
}
