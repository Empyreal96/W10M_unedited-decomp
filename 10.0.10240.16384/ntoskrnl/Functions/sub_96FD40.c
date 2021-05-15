// sub_96FD40 
 
void __fastcall sub_96FD40(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, unsigned int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, char a17, int a18, void **a19, int a20, int a21, int a22, char *a23, int a24, int a25, int a26, char a27, int a28, int a29, int a30, int a31, int a32, int a33, unsigned int a34)
{
  void **v34; // r4
  unsigned int v36; // r6
  int v37; // r8
  int v38; // r0
  unsigned int v39; // r3
  int v40; // r2
  int v41; // lr
  unsigned int v42; // r4
  unsigned int v43; // r7
  unsigned int v44; // r8
  unsigned int v45; // r9
  unsigned __int64 v46; // kr08_8
  unsigned __int64 v47; // kr10_8
  unsigned int *v48; // r0
  unsigned int *v49; // r9
  _DWORD *v50; // r1
  void **v51; // lr
  unsigned int v52; // r7
  int v53; // r4
  int v54; // t1
  unsigned int *v55; // r2
  unsigned __int64 v56; // r0
  int v57; // lr
  unsigned int v58; // r2
  int v59; // r7
  unsigned __int64 *v60; // r4
  unsigned __int64 v61; // kr20_8
  int v62; // r0
  int v63; // r1
  unsigned int v64; // r7
  __int64 v65; // kr28_8
  unsigned __int64 v66; // kr30_8
  unsigned int v67; // r9
  void **v68; // r3
  _DWORD *v69; // r4
  int v70; // r2
  int v71; // r10
  unsigned int v72; // r1
  int v73; // t1
  void **v74; // lr
  unsigned int v75; // r7
  int v76; // r1
  int v77; // t1
  int v78; // r2
  __int64 v79; // kr38_8
  unsigned int v80; // r2
  int v81; // r0
  unsigned int v82; // r1
  int v83; // t1
  unsigned int v84; // r2
  unsigned int v85; // r3
  unsigned int v86; // r8
  int v87; // r5
  unsigned int v88; // r7
  int v89; // r9
  int v90; // r1
  int v91; // r0
  int *v92; // r10
  void **v93; // r2
  unsigned __int16 *v94; // t1
  int v95; // r4
  void **i; // r2
  int v97; // r3
  void **v98; // lr
  unsigned __int16 *v99; // r0
  int v100; // r2
  void **v101; // r8
  int *v102; // r1
  unsigned int v103; // r7
  int v104; // r4
  int v105; // t1
  int v106; // r2
  int v107; // r2
  int v108; // r3
  bool v109; // zf
  unsigned int v110; // [sp+10h] [bp+10h]
  int v111; // [sp+10h] [bp+10h]
  unsigned int v112; // [sp+10h] [bp+10h]
  unsigned int *v113; // [sp+14h] [bp+14h]
  int v114; // [sp+14h] [bp+14h]
  unsigned int v115; // [sp+18h] [bp+18h]
  unsigned int v116; // [sp+1Ch] [bp+1Ch]
  unsigned int v117; // [sp+24h] [bp+24h]

  v37 = v36 * v36;
  v38 = ExAllocatePoolWithTag(1, 8 * v36 * v36, 1634563406);
  v115 = v38;
  if ( !v38 )
    goto LABEL_109;
  memmove(v38, KiActualNodeCost, 8 * v37);
  v39 = v36 - 1;
  v40 = 0;
  if ( v36 != 1 )
  {
    v41 = 0;
    do
    {
      v42 = v40 + 1;
      if ( v40 + 1 < v36 )
      {
        v43 = v115 + 8 * (v41 + v42);
        v44 = v115 + 8 * (v41 + v40 + v36);
        v45 = v36 - v42;
        do
        {
          v46 = *(_QWORD *)v43;
          if ( ((unsigned int)v46 & HIDWORD(v46)) != -1 )
          {
            v47 = (*(_QWORD *)v44 >> 1) + (v46 >> 1);
            *(_QWORD *)v43 = v47;
            *(_DWORD *)v44 = v47;
            *(_DWORD *)(v44 + 4) = *(_DWORD *)(v43 + 4);
          }
          v43 += 8;
          --v45;
          v44 += 8 * v36;
        }
        while ( v45 );
        v39 = v36 - 1;
      }
      ++v40;
      v41 += v36;
    }
    while ( v42 < v39 );
    v34 = &KeNodeBlock;
    v37 = v36 * v36;
  }
  v48 = (unsigned int *)ExAllocatePoolWithTag(1, 2 * ((a9 + 2) * a9 + 2), 538993995);
  v116 = (unsigned int)v48;
  if ( !v48 )
    goto LABEL_107;
  v49 = &v48[a9 + 1];
  v113 = v49;
  *v48 = a9;
  if ( v36 )
  {
    v50 = v48 + 1;
    v51 = v34;
    v52 = v36;
    do
    {
      v54 = (int)*v51++;
      v53 = v54;
      if ( *(unsigned __int16 *)(v54 + 266) == *(unsigned __int16 *)(v54 + 268) )
        *v50++ = *(_DWORD *)(v53 + 276);
      --v52;
    }
    while ( v52 );
  }
  if ( a9 * a9 )
  {
    v55 = &v48[a9 + 1];
    do
    {
      *(_WORD *)v55 = -1;
      v55 = (unsigned int *)((char *)v55 + 2);
    }
    while ( v55 != (unsigned int *)((char *)v49 + 2 * a9 * a9) );
  }
  v56 = 1i64;
  if ( v37 )
  {
    v57 = v37;
    v58 = v115;
    do
    {
      if ( v56 < *(_QWORD *)v58 && (*(_DWORD *)v58 & *(_DWORD *)(v58 + 4)) != -1 )
        v56 = *(_QWORD *)v58;
      v58 += 8;
      --v57;
    }
    while ( v57 );
    if ( v56 > 0x1000000000000i64 )
    {
      v56 >>= 16;
      v59 = v37;
      v60 = (unsigned __int64 *)v115;
      do
      {
        v61 = *v60;
        if ( ((unsigned int)v61 & HIDWORD(v61)) != -1 )
          *v60 = v61 >> 16;
        ++v60;
        --v59;
      }
      while ( v59 );
    }
  }
  if ( !v56 )
    __brkdiv0();
  v62 = _rt_udiv64(v56, 0x8000000000000000ui64);
  if ( v37 )
  {
    v64 = v115;
    do
    {
      v65 = *(_QWORD *)v64;
      if ( ((unsigned int)v65 & HIDWORD(v65)) == -1 )
      {
        *(_DWORD *)v64 = 0xFFFF;
      }
      else
      {
        v66 = (unsigned int)v65 * (unsigned __int64)(unsigned int)v62;
        *(_DWORD *)v64 = v66;
        *(_DWORD *)(v64 + 4) = HIDWORD(v66) + HIDWORD(v65) * v62 + v65 * v63;
        *(_DWORD *)v64 = *(unsigned __int16 *)(v64 + 6);
      }
      *(_DWORD *)(v64 + 4) = 0;
      v64 += 8;
      --v37;
    }
    while ( v37 );
  }
  if ( v36 )
  {
    v67 = v36;
    v110 = v36;
    v68 = &KeNodeBlock;
    do
    {
      v69 = *v68;
      if ( *((unsigned __int16 *)*v68 + 133) == *((unsigned __int16 *)*v68 + 134) )
      {
        v70 = 0;
        v71 = 0;
        if ( a9 )
        {
          v72 = v116;
          while ( 1 )
          {
            v73 = *(_DWORD *)(v72 + 4);
            v72 += 4;
            if ( v73 == v69[69] )
              break;
            if ( ++v70 >= a9 )
              goto LABEL_49;
          }
          v71 = v70 * a9;
        }
LABEL_49:
        v74 = &KeNodeBlock;
        v75 = v36;
        do
        {
          v77 = (int)*v74++;
          v76 = v77;
          v78 = *(unsigned __int16 *)(v77 + 266);
          if ( v78 == *(unsigned __int16 *)(v77 + 268) )
          {
            v79 = *(_QWORD *)(v115 + 8 * (v78 + *((unsigned __int16 *)v69 + 133) * v36));
            if ( v79 != 0xFFFF )
            {
              v80 = 0;
              if ( a9 )
              {
                v81 = *(_DWORD *)(v76 + 276);
                v82 = v116;
                do
                {
                  v83 = *(_DWORD *)(v82 + 4);
                  v82 += 4;
                  if ( v83 == v81 )
                    break;
                  ++v80;
                }
                while ( v80 < a9 );
              }
              v84 = v80 + v71;
              *((_WORD *)v113 + v84) = v79;
              if ( !(_WORD)v79 )
                *((_WORD *)v113 + v84) = 2;
            }
          }
          --v75;
        }
        while ( v75 );
        v67 = v110;
      }
      --v67;
      ++v68;
      v110 = v67;
    }
    while ( v67 );
    v49 = v113;
  }
  if ( a9 )
  {
    v85 = a9 + 1;
    do
    {
      *(_WORD *)v49 = 0;
      v49 = (unsigned int *)((char *)v49 + 2 * v85);
      --a9;
    }
    while ( a9 );
  }
  v86 = 10;
  RtlInitUnicodeString((unsigned int)&a27, L"\\registry\\machine\\SYSTEM\\CurrentControlSet\\Control\\NUMA");
  RtlInitUnicodeString((unsigned int)&a17, L"Variation Threshold");
  a21 = 24;
  a22 = 0;
  a24 = 576;
  a23 = &a27;
  a25 = 0;
  a26 = 0;
  if ( ZwCreateKey() < 0 )
  {
    v87 = -1;
    a13 = -1;
  }
  else
  {
    if ( ZwQueryValueKey() >= 0 && a32 == 4 && a33 == 4 )
    {
      v86 = a34;
      if ( a34 > 0x32 || !a34 )
        v86 = 10;
    }
    v87 = a13;
  }
  v88 = 0;
  v89 = 0;
  if ( !v36 )
    goto LABEL_107;
  v90 = 0;
  v91 = (unsigned __int16)KeNumberNodes;
  v92 = KeNodeDistance;
  v111 = 0;
  v114 = (unsigned __int16)KeNumberNodes;
  v93 = &KeNodeBlock;
LABEL_76:
  v94 = (unsigned __int16 *)*v93;
  a19 = v93 + 1;
  if ( v94[133] != v94[134] )
    goto LABEL_91;
  v95 = 0;
  for ( i = &KeNodeBlock; ; ++i )
  {
    if ( *((unsigned __int16 *)*i + 133) == *((unsigned __int16 *)*i + 134) && v88 != v95 )
    {
      v117 = KeNodeDistance[v95 + v91 * v88];
      v97 = *(_DWORD *)(v115 + 8 * (v90 + v95)) - v117;
      if ( v97 < 0 )
        v97 = v117 - *(_DWORD *)(v115 + 8 * (v90 + v95));
      if ( !v86 )
        __brkdiv0();
      if ( 100 * v97 / v86 > v117 )
      {
        v89 = 1;
LABEL_89:
        if ( v89 )
        {
          if ( v87 != -1 )
          {
            RtlInitUnicodeString((unsigned int)&a17, L"Node Distance");
            ZwSetValueKey();
            v92 = KeNodeDistance;
            v114 = (unsigned __int16)KeNumberNodes;
          }
          v112 = v36;
          v98 = &KeNodeBlock;
          do
          {
            v99 = (unsigned __int16 *)*v98;
            v100 = *((unsigned __int16 *)*v98 + 134);
            if ( *((unsigned __int16 *)*v98 + 133) != v100 )
              v99 = (unsigned __int16 *)*(&KeNodeBlock + v100);
            v101 = &KeNodeBlock;
            v102 = v92;
            v103 = v36;
            do
            {
              v105 = (int)*v101++;
              v104 = v105;
              v106 = *(unsigned __int16 *)(v105 + 268);
              if ( *(unsigned __int16 *)(v105 + 266) != v106 )
                v104 = (int)*(&KeNodeBlock + v106);
              v107 = v99[133];
              v108 = *(unsigned __int16 *)(v104 + 266);
              if ( v107 == v108 )
                *v102 = 0;
              else
                *v102 = *(_DWORD *)(v115 + 8 * (v108 + v107 * v36));
              ++v102;
              --v103;
            }
            while ( v103 );
            ++v98;
            v109 = v112-- == 1;
            v92 += v114;
          }
          while ( !v109 );
          goto LABEL_107;
        }
        v90 = v111;
        v91 = (unsigned __int16)KeNumberNodes;
LABEL_91:
        ++v88;
        v90 += v36;
        v93 = a19;
        v111 = v90;
        if ( v88 >= v36 )
        {
LABEL_107:
          ExFreePoolWithTag(v115);
          if ( v116 )
            ExFreePoolWithTag(v116);
LABEL_109:
          if ( a13 != -1 )
            ZwClose();
          JUMPOUT(0x963F0E);
        }
        goto LABEL_76;
      }
      v90 = v111;
      v91 = (unsigned __int16)KeNumberNodes;
    }
    if ( ++v95 >= v36 )
      goto LABEL_89;
  }
}
