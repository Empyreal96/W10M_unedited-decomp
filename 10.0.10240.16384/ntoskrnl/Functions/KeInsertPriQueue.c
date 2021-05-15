// KeInsertPriQueue 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KeInsertPriQueue(int a1, int a2, int a3, int a4, char a5)
{
  int v6; // r8
  _DWORD *v8; // r9
  int v9; // r10
  unsigned int v10; // r3
  int v11; // r7
  unsigned int v12; // r4
  char v13; // r2
  int v14; // r2
  unsigned int v15; // r1
  int v16; // r0
  int v17; // t1
  int v18; // r0
  int v19; // r10
  int v20; // r1 OVERLAPPED
  _DWORD *v21; // r2 OVERLAPPED
  int v22; // r3
  int v23; // r4
  unsigned int *v24; // r1
  unsigned int v25; // r2
  int v26; // r3
  char v27; // r2
  int v28; // r1
  int v29; // r3
  _BYTE *v30; // r2
  int v31; // r3
  unsigned int *v32; // r2
  unsigned int v33; // r1
  int v34; // r3
  int v35; // r1
  int v36; // r3
  int v37; // r7
  int v38; // r3
  unsigned int v39; // r1
  unsigned __int64 *v41; // lr
  unsigned __int64 v42; // r0
  unsigned __int64 v43; // kr00_8
  unsigned __int64 v44; // kr08_8
  unsigned __int64 *v45; // r3
  unsigned __int64 v46; // kr10_8
  unsigned int v47; // r3
  int v48; // r0
  int v49; // r9
  int v50; // r8
  int v51; // r7
  int v52; // r2
  BOOL v53; // r1
  int v54; // r2
  _DWORD *v55; // r2
  unsigned int *v56; // r3
  int v57; // r2
  _DWORD *v58; // r1
  unsigned int v59; // r2
  unsigned __int8 *v60; // r3
  unsigned int v61; // r2
  unsigned int *v62; // r2
  unsigned int v63; // r1
  unsigned int *v64; // r7
  unsigned int v65; // r2
  __int64 v66; // r0
  signed int v67; // r3
  char v68; // r3
  _DWORD *v69; // r8
  char v70; // r2
  int v71; // r2
  int v72; // r1
  char v73; // r3
  int v74; // r0
  int v75; // r7
  char v76; // r2
  int v77; // r2
  int v78; // r1
  char v79; // r3
  char v80; // r2
  int v81; // r2
  int v82; // r1
  char v83; // r3
  _DWORD *v84; // r1
  _DWORD *v85; // r8
  int v86; // r0
  int v87; // r7
  char v88; // r2
  int v89; // r2
  int v90; // r1
  char v91; // r3
  char v92; // r2
  unsigned int *v93; // r2
  unsigned int v94; // r0
  int v95; // r0
  int v96; // r3
  unsigned int *v97; // r2
  unsigned int v98; // r4
  unsigned int v99; // r3
  _DWORD *v100; // [sp+8h] [bp-40h] BYREF
  int v101; // [sp+Ch] [bp-3Ch]
  int v102; // [sp+10h] [bp-38h]
  int v103; // [sp+14h] [bp-34h]
  _DWORD *v104; // [sp+18h] [bp-30h]
  unsigned int *v105; // [sp+1Ch] [bp-2Ch] BYREF
  int v106; // [sp+20h] [bp-28h]
  _DWORD *v107; // [sp+24h] [bp-24h]
  int v108; // [sp+28h] [bp-20h]

  v6 = a1 + 8;
  v8 = (_DWORD *)a2;
  v104 = (_DWORD *)a2;
  v9 = 0;
  v108 = KfRaiseIrql(2);
  v10 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  v11 = *(_DWORD *)(v10 + 4);
  v106 = v10;
  do
    v12 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v12 | 0x80, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( v12 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( (*(_DWORD *)a1 & 0x80) != 0 );
      do
        v59 = __ldrex((unsigned __int8 *)a1);
      while ( __strex(v59 | 0x80, (unsigned __int8 *)a1) );
      __dmb(0xBu);
    }
    while ( v59 >> 7 );
  }
  v13 = a5;
  if ( *(_DWORD *)(v6 + 4) != v6 && (*(_DWORD *)(v11 + 152) != a1 || *(_BYTE *)(v11 + 395) != 15) )
  {
    v14 = 32;
    v15 = 0;
    v16 = a1 + 400;
    do
    {
      v17 = *(_DWORD *)(v16 - 4);
      v16 -= 4;
      --v14;
      v15 += v17;
    }
    while ( v14 > a3 && v15 < *(_DWORD *)(a1 + 400) );
    if ( v15 >= *(_DWORD *)(a1 + 400) )
    {
      v13 = a5;
      goto LABEL_63;
    }
    v18 = *(_DWORD *)(a1 + 12);
    while ( 1 )
    {
      v19 = v18;
      *(_QWORD *)&v20 = *(_QWORD *)v18;
      v18 = *(_DWORD *)(v18 + 4);
      v22 = *(_DWORD *)(v20 + 4);
      v102 = v18;
      if ( v22 != v19 || *v21 != v19 )
        __fastfail(3u);
      *v21 = v20;
      *(_DWORD *)(v20 + 4) = v21;
      v23 = *(_DWORD *)(v19 + 12);
      v103 = 0;
      v24 = (unsigned int *)(v23 + 44);
      v107 = (_DWORD *)(v23 + 44);
      while ( 1 )
      {
        do
          v25 = __ldrex(v24);
        while ( __strex(1u, v24) );
        __dmb(0xBu);
        if ( !v25 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v24 );
      }
      if ( *(_BYTE *)(v23 + 132) != 5 )
        goto LABEL_30;
      v26 = *(_DWORD *)(v23 + 332);
      if ( (unsigned __int8)v26 != a3 )
      {
        if ( (v26 & 0x100) == 0 )
          return sub_52D3BC();
        *(_DWORD *)(v23 + 332) = (unsigned __int8)a3 | *(_DWORD *)(v23 + 332) & 0x100;
      }
      v27 = *(_BYTE *)(v23 + 72);
      v28 = 0;
      v103 = 0;
      v29 = v27 & 7;
      if ( v29 == 1 || v29 == 4 )
      {
        v30 = *(_BYTE **)(v23 + 152);
        if ( v30 )
        {
          if ( (*v30 & 0x7F) == 21 )
          {
            v31 = *(unsigned __int8 *)(v23 + 332);
            *(_DWORD *)(v23 + 332) = v31;
            __dmb(0xBu);
            v32 = (unsigned int *)&v30[4 * v31 + 272];
            do
              v33 = __ldrex(v32);
            while ( __strex(v33 + 1, v32) );
          }
          else
          {
            __dmb(0xBu);
            v62 = (unsigned int *)(v30 + 24);
            do
              v63 = __ldrex(v62);
            while ( __strex(v63 + 1, v62) );
          }
          __dmb(0xBu);
        }
        v34 = *(_DWORD *)(v23 + 436);
        if ( v34 )
        {
          v64 = (unsigned int *)(v34 + 1928);
          while ( 1 )
          {
            do
              v65 = __ldrex(v64);
            while ( __strex(1u, v64) );
            __dmb(0xBu);
            if ( !v65 )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( *v64 );
          }
          if ( *(_DWORD *)(v23 + 436) )
          {
            v66 = *(_QWORD *)(v23 + 144);
            if ( *(_DWORD *)(v66 + 4) != v23 + 144 || *(_DWORD *)HIDWORD(v66) != v23 + 144 )
              __fastfail(3u);
            *(_DWORD *)HIDWORD(v66) = v66;
            *(_DWORD *)(v66 + 4) = HIDWORD(v66);
            v18 = v102;
            *(_DWORD *)(v23 + 436) = 0;
          }
          __dmb(0xBu);
          *v64 = 0;
        }
        v35 = v106;
        *(_BYTE *)(v23 + 132) = 7;
        *(_DWORD *)(v23 + 144) = *(_DWORD *)(v35 + 1540);
        v36 = (int)v104;
        *(_DWORD *)(v35 + 1540) = v23 + 144;
        v28 = 1;
        *(_DWORD *)(v23 + 136) = v36;
        v103 = 1;
      }
      else
      {
        if ( (v27 & 7) == 0 )
        {
          *(_BYTE *)(v23 + 72) = v27 & 0xF8 | 2;
          v103 = 1;
          *(_DWORD *)(v23 + 136) = v104;
          *(_BYTE *)(v19 + 9) = 0;
LABEL_27:
          v37 = (char)a3;
          *(_BYTE *)(v23 + 397) = 0;
          KiAbProcessThreadPriorityModification(v23, (char)a3, 0);
          v38 = *(char *)(v23 + 348);
          *(_BYTE *)(v23 + 347) = a3;
          if ( v38 )
          {
            if ( (v38 & 0xF) != 0 )
              *(_DWORD *)(v23 + 812) = KeTickCount;
            *(_BYTE *)(v23 + 348) = 0;
          }
          if ( a3 != *(char *)(v23 + 123) )
          {
            v41 = (unsigned __int64 *)(v23 + 48);
            while ( 1 )
            {
              v42 = *v41;
              do
                v43 = __ldrexd(v41);
              while ( v43 == v42 && __strexd(v42, v41) );
              if ( __PAIR64__(v42, HIDWORD(v42)) == __PAIR64__(v43, HIDWORD(v43)) )
                break;
              __dmb(0xAu);
              __yield();
            }
            v44 = v42 + (unsigned int)*(unsigned __int8 *)(v23 + 403) * KiCyclesPerClockQuantum;
            if ( (*(_DWORD *)(v23 + 80) & 0x10) != 0 )
            {
              __dmb(0xBu);
              v60 = (unsigned __int8 *)(v23 + 80);
              do
                v61 = __ldrex(v60);
              while ( __strex(v61 & 0xEF, v60) );
              __dmb(0xBu);
            }
            __dmb(0xBu);
            v45 = (unsigned __int64 *)(v23 + 24);
            do
              v46 = __ldrexd(v45);
            while ( __strexd(v44, v45) );
            __dmb(0xBu);
            v47 = *(_DWORD *)(v23 + 800);
            if ( v47 )
            {
              v67 = 31 - __clz(v47);
              if ( (char)a3 < v67 )
                v37 = (char)v67;
            }
            if ( *(char *)(v23 + 123) != v37 )
            {
              v48 = KiAcquireThreadStateLock(v23, &v100, &v105);
              v49 = *(char *)(v23 + 123);
              v101 = 0;
              v50 = 1;
              if ( v48 > 3 )
                goto LABEL_45;
              if ( v48 == 1 )
              {
                KiRemoveThreadFromAnyReadyQueue((int)v100, (int)v105, v23, v49);
                KiAbProcessThreadPriorityModification(v23, v37, 1);
                *(_BYTE *)(v23 + 123) = v37;
                KiPrepareReadyThreadForRescheduling(v23, v37, 0);
                goto LABEL_46;
              }
              if ( v48 == 2 )
              {
                if ( v100[2] )
                  v50 = 0;
                KiAbProcessThreadPriorityModification(v23, v37, 1);
                *(_BYTE *)(v23 + 123) = v37;
                if ( v50 )
                {
                  if ( (*(_BYTE *)(v23 + 2) & 4) != 0 )
                  {
                    if ( v37 < 16
                      && *(_DWORD *)(v23 + 68)
                      && (v81 = *(_DWORD *)(v23 + 68)) != 0
                      && (v82 = v81 + v100[588]) != 0
                      && KiGetThreadEffectiveRankNonZero(v23, v82, 0) )
                    {
                      v83 = 1;
                    }
                    else
                    {
                      v83 = *(_BYTE *)(v23 + 123);
                    }
                    v80 = v83;
                  }
                  else
                  {
                    v80 = v37;
                  }
                  v84 = v100;
                  *(_BYTE *)v100[7] = v80;
                }
                else
                {
                  v84 = v100;
                }
                if ( v37 >= v49 || !v50 )
                  goto LABEL_46;
                if ( *(_BYTE *)(v23 + 132) == 2 )
                {
                  v85 = v100;
                  v86 = KiSelectReadyThreadEx(v100, v23, 0);
                  v87 = v86;
                  if ( !v86 )
                    goto LABEL_46;
                  if ( (*(_BYTE *)(v86 + 2) & 4) != 0 )
                  {
                    if ( *(char *)(v86 + 123) < 16
                      && *(_DWORD *)(v86 + 68)
                      && (v89 = *(_DWORD *)(v86 + 68)) != 0
                      && (v90 = v89 + v85[588]) != 0
                      && KiGetThreadEffectiveRankNonZero(v86, v90, 0) )
                    {
                      v91 = 1;
                    }
                    else
                    {
                      v91 = *(_BYTE *)(v87 + 123);
                    }
                    v88 = v91;
                  }
                  else
                  {
                    v88 = *(_BYTE *)(v86 + 123);
                  }
                  *(_BYTE *)v85[7] = v88;
                  v85[2] = v87;
                  *(_BYTE *)(v87 + 132) = 3;
                  v51 = 1;
                }
                else
                {
                  v92 = v37 + 1;
                  v51 = v101;
                  if ( v84[483] >> v92 )
                    *(_BYTE *)(v23 + 72) |= 0x10u;
                }
              }
              else
              {
                if ( v48 == 3 )
                {
                  KiAbProcessThreadPriorityModification(v23, v37, 1);
                  v68 = *(_BYTE *)(v23 + 2);
                  v69 = v100;
                  *(_BYTE *)(v23 + 123) = v37;
                  if ( (v68 & 4) != 0 )
                  {
                    if ( v37 < 16
                      && *(_DWORD *)(v23 + 68)
                      && (v71 = *(_DWORD *)(v23 + 68)) != 0
                      && (v72 = v69[588] + v71) != 0
                      && KiGetThreadEffectiveRankNonZero(v23, v72, 0) )
                    {
                      v73 = 1;
                    }
                    else
                    {
                      v73 = *(_BYTE *)(v23 + 123);
                    }
                    v70 = v73;
                  }
                  else
                  {
                    v70 = v37;
                  }
                  *(_BYTE *)v69[7] = v70;
                  if ( v37 < v49 )
                  {
                    v74 = KiSelectReadyThreadEx(v69, v23, 0);
                    v75 = v74;
                    if ( v74 )
                    {
                      if ( (*(_BYTE *)(v74 + 2) & 4) != 0 )
                      {
                        if ( *(char *)(v74 + 123) < 16
                          && *(_DWORD *)(v74 + 68)
                          && (v77 = *(_DWORD *)(v74 + 68)) != 0
                          && (v78 = v77 + v69[588]) != 0
                          && KiGetThreadEffectiveRankNonZero(v74, v78, 0) )
                        {
                          v79 = 1;
                        }
                        else
                        {
                          v79 = *(_BYTE *)(v75 + 123);
                        }
                        v76 = v79;
                      }
                      else
                      {
                        v76 = *(_BYTE *)(v74 + 123);
                      }
                      *(_BYTE *)v69[7] = v76;
                      v69[2] = v75;
                      *(_BYTE *)(v75 + 132) = 3;
                      *(_BYTE *)(v23 + 132) = 7;
                      *(_DWORD *)(v23 + 144) = MEMORY[0];
                      MEMORY[0] = v23 + 144;
                    }
                  }
                }
                else
                {
LABEL_45:
                  KiAbProcessThreadPriorityModification(v23, v37, 1);
                  *(_BYTE *)(v23 + 123) = v37;
                }
LABEL_46:
                v51 = v101;
              }
              v52 = *(_DWORD *)(v23 + 68);
              if ( !v52 )
                goto LABEL_48;
              while ( (*(_DWORD *)(v52 + 4) & 2) != 0 )
              {
                v52 = *(_DWORD *)(v52 + 60);
                if ( !v52 )
                  goto LABEL_48;
              }
              if ( (*(_DWORD *)(v23 + 80) & 0x100) != 0 || *(char *)(v23 + 123) >= 16 )
              {
LABEL_48:
                v53 = 0;
                v54 = *((_DWORD *)*(&KiProcessorBlock + *(_DWORD *)(v23 + 364)) + 864);
                if ( v54 )
                  v53 = (*(_DWORD *)(v23 + 356) & v54) == v54;
              }
              else
              {
                v53 = 0;
              }
              if ( v53 != ((*(_DWORD *)(v23 + 80) >> 12) & 1) )
              {
                v93 = (unsigned int *)(v23 + 80);
                do
                  v94 = __ldrex(v93);
                while ( __strex(v94 ^ 0x1000, v93) );
              }
              v55 = v100;
              if ( v100 )
              {
                __dmb(0xBu);
                v55[6] = 0;
              }
              v56 = v105;
              if ( v105 )
              {
                __dmb(0xBu);
                *v56 = 0;
              }
              if ( v51 )
              {
                v95 = v55[5];
                if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) != v95 )
                {
                  v96 = (int)*(&KiProcessorBlock + v95);
                  __dmb(0xBu);
                  v97 = (unsigned int *)(v96 + 1676);
                  do
                    v98 = __ldrex(v97);
                  while ( __strex(v98 | 2, v97) );
                  __dmb(0xBu);
                  v99 = (unsigned int)KeGetPcr();
                  ++*(_DWORD *)((v99 & 0xFFFFF000) + 0x1414);
                  HalSendSoftwareInterrupt(v95, 2);
                }
              }
            }
          }
          v18 = v102;
          goto LABEL_30;
        }
        if ( v29 == 5 )
        {
          *(_BYTE *)(v23 + 72) = v27 & 0xF8 | 6;
          v103 = 0;
          goto LABEL_30;
        }
        if ( v29 == 3 )
          *(_BYTE *)(v19 + 9) = 2;
      }
      if ( v28 )
        goto LABEL_27;
LABEL_30:
      __dmb(0xBu);
      *v107 = 0;
      ++*(_BYTE *)(v19 + 9);
      v9 = v103;
      if ( v103 )
        goto LABEL_31;
      if ( v18 == a1 + 8 )
      {
        v13 = a5;
        v8 = v104;
        break;
      }
    }
  }
LABEL_63:
  if ( (v13 & 2) == 0 )
  {
    ++*(_DWORD *)(a1 + 4);
    v57 = a1 + 8 * (a3 + 2);
    v58 = *(_DWORD **)(v57 + 4);
    *v8 = v57;
    v8[1] = v58;
    if ( *v58 != v57 )
      __fastfail(3u);
    *v58 = v8;
    *(_DWORD *)(v57 + 4) = v8;
  }
LABEL_31:
  __dmb(0xBu);
  do
    v39 = __ldrex((unsigned int *)a1);
  while ( __strex(v39 & 0xFFFFFF7F, (unsigned int *)a1) );
  KiExitDispatcher(v106, (a5 & 1) != 0, 1, 0, v108);
  return v9;
}
