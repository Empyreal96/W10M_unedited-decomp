// KiSearchForNewThreadOnProcessor 
 
int __fastcall KiSearchForNewThreadOnProcessor(unsigned int a1, unsigned int a2, _DWORD *a3)
{
  int v7; // r3
  int v8; // r6
  int v9; // r2
  unsigned int v10; // r1
  unsigned int v11; // r0
  unsigned int *v12; // r4
  unsigned int v13; // r2
  unsigned int *v14; // r1
  unsigned int v15; // r2
  int v16; // r1
  int v17; // r1
  int v18; // r2
  int v19; // r8
  int v20; // r4
  int v21; // r3
  int v22; // lr
  int v23; // r3
  int v24; // r2
  int v25; // r0
  unsigned __int8 *v26; // r3
  unsigned int v27; // r2
  int v28; // r2
  int v29; // r4
  unsigned __int8 *v30; // r2
  unsigned int v31; // r1
  int v32; // r4
  unsigned int *v33; // r2
  unsigned int v34; // r0
  char v35; // r2
  int v36; // r2
  char v37; // r3
  int v38; // r2
  int v39; // r2
  int v40; // r1
  int v41; // r3
  char v42; // r3
  char v43; // r2
  int v44; // r3
  int v45; // r5
  int v46; // r3
  int v47; // r2
  int v48; // r0
  unsigned __int8 *v49; // r3
  unsigned int v50; // r2
  int v51; // r2
  int v52; // r4
  unsigned __int8 *v53; // r2
  unsigned int v54; // r1
  int v55; // r4
  unsigned int *v56; // r2
  unsigned int v57; // r0
  unsigned int v58; // r3
  int v59; // r3
  int v60; // r2
  int v61; // r1
  int v62; // [sp+8h] [bp-30h]

  while ( 1 )
  {
    while ( 1 )
    {
      if ( !a2 )
        return sub_52F8F4();
      if ( !*(_DWORD *)(a2 + 1932) )
      {
        if ( *(unsigned __int8 *)(a2 + 2986) != *(unsigned __int8 *)(a1 + 2986)
          || (v7 = *(_DWORD *)(a2 + 8)) == 0
          || (v9 = *(_DWORD *)(a2 + 12), v7 == v9)
          || *(_DWORD *)(a2 + 4) != v9 && **(char **)(a2 + 28) < 16 )
        {
          if ( !*(_DWORD *)(a2 + 1976) )
            return 0;
        }
      }
      v10 = a1;
      v11 = a2;
      if ( a1 > a2 )
      {
        v10 = a2;
        v11 = a1;
      }
      v12 = (unsigned int *)(v10 + 24);
      while ( 1 )
      {
        do
          v13 = __ldrex(v12);
        while ( __strex(1u, v12) );
        __dmb(0xBu);
        if ( !v13 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v12 );
      }
      if ( v10 != v11 )
      {
        v14 = (unsigned int *)(v11 + 24);
        while ( 1 )
        {
          do
            v15 = __ldrex(v14);
          while ( __strex(1u, v14) );
          __dmb(0xBu);
          if ( !v15 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v14 );
        }
      }
      v8 = *(_DWORD *)(a1 + 8);
      v16 = 0;
      v62 = 0;
      if ( v8 )
        break;
      if ( !a3 )
      {
        if ( *(unsigned __int8 *)(a2 + 2986) != *(unsigned __int8 *)(a1 + 2986) )
          goto LABEL_82;
        v17 = *(_DWORD *)(a2 + 8);
        if ( !v17 )
          goto LABEL_82;
        v18 = *(_DWORD *)(a2 + 12);
        if ( v17 == v18 || *(_DWORD *)(a2 + 4) != v18 && **(char **)(a2 + 28) < 16 )
          goto LABEL_82;
        if ( *(_DWORD *)(v17 + 352) != KiCpuSetSequence && (*(_DWORD *)(v17 + 76) & 8) == 0 )
          goto LABEL_82;
        v8 = *(_DWORD *)(a2 + 8);
        if ( *(unsigned __int8 *)(a1 + 1052) != *(unsigned __int16 *)(v8 + 360)
          || (*(_DWORD *)(v8 + 356) & *(_DWORD *)(a1 + 1048)) == 0 )
        {
          goto LABEL_82;
        }
        v19 = KiSelectReadyThread(1, a2);
        if ( !v19 )
        {
          v20 = *(_DWORD *)(a2 + 1980);
          if ( v20 )
          {
            while ( 1 )
            {
              v19 = KiSelectThreadFromSchedulingGroup(a2, v20 - 80, 0);
              if ( v19 )
                break;
              v20 = *(_DWORD *)(v20 + 152);
              if ( !v20 )
                goto LABEL_31;
            }
          }
          else
          {
LABEL_31:
            v19 = KiSelectReadyThread(0, a2);
            if ( !v19 )
              goto LABEL_32;
          }
        }
        if ( *(_DWORD *)(v19 + 352) == KiCpuSetSequence || (*(_DWORD *)(v19 + 76) & 8) != 0 )
          goto LABEL_43;
        KiAddThreadToReadyQueue((_DWORD *)a2, 0, v19, 1, 1);
LABEL_32:
        v21 = *(unsigned __int8 *)(a2 + 19);
        v19 = *(_DWORD *)(a2 + 12);
        v22 = *(_DWORD *)(a2 + 2360);
        *(_BYTE *)(a2 + 1755) = 1;
        if ( (v21 & 1) == 0 )
          __fastfail(0x21u);
        v23 = v21 - 1;
        *(_BYTE *)(a2 + 19) = v23;
        if ( !v23 )
        {
          v24 = *(unsigned __int8 *)(a2 + 1053);
          __dmb(0xBu);
          v25 = 1 << (v24 & 7);
          v26 = (unsigned __int8 *)(v22 + (v24 >> 3));
          do
            v27 = __ldrex(v26);
          while ( __strex(v27 | v25, v26) );
          __dmb(0xBu);
        }
        v28 = *(unsigned __int8 *)(a2 + 1053);
        __dmb(0xBu);
        v29 = 1 << (v28 & 7);
        v30 = (unsigned __int8 *)(v22 + (v28 >> 3) + 8);
        do
          v31 = __ldrex(v30);
        while ( __strex(v31 | v29, v30) );
        __dmb(0xBu);
        v32 = *(_DWORD *)(a2 + 3468);
        if ( (v32 & *(_DWORD *)(v22 + 8)) == v32 )
        {
          __dmb(0xBu);
          v33 = (unsigned int *)(v22 + 4);
          do
            v34 = __ldrex(v33);
          while ( __strex(v34 | v32, v33) );
          __dmb(0xBu);
        }
LABEL_43:
        if ( (*(_BYTE *)(v19 + 2) & 4) != 0 )
        {
          if ( *(char *)(v19 + 123) < 16
            && *(_DWORD *)(v19 + 68)
            && (v60 = *(_DWORD *)(v19 + 68)) != 0
            && (v61 = v60 + *(_DWORD *)(a2 + 2352)) != 0
            && KiGetThreadEffectiveRankNonZero(v19, v61, 0) )
          {
            v35 = 1;
          }
          else
          {
            v35 = *(_BYTE *)(v19 + 123);
          }
        }
        else
        {
          v35 = *(_BYTE *)(v19 + 123);
        }
        **(_BYTE **)(a2 + 28) = v35;
        *(_DWORD *)(a2 + 8) = v19;
        *(_BYTE *)(v19 + 132) = 3;
        *(_DWORD *)(v8 + 328) = *(_DWORD *)(a1 + 20);
        if ( v8 )
        {
LABEL_46:
          __dmb(0xBu);
          *(_DWORD *)(a2 + 24) = 0;
          v16 = 0;
          goto LABEL_47;
        }
LABEL_82:
        v58 = *(_DWORD *)(a2 + 1932);
        if ( !v58 || (v8 = KiFindReadyThread((_DWORD *)a1, a2, 0, v58)) == 0 )
          v8 = KiGroupSchedulingMoveThread(a1, a2, a2 + 1976);
        goto LABEL_46;
      }
      if ( (a3[1] & 0xFFFFFFFE) != 0 )
      {
        v8 = KiFindReadyThread((_DWORD *)a1, 0, (int)a3, a3[1] & 0xFFFFFFFE);
        v16 = 0;
      }
      __dmb(0xBu);
      *a3 = 0;
LABEL_47:
      if ( !v8 )
      {
        __dmb(0xBu);
        *(_DWORD *)(a1 + 24) = 0;
        return 0;
      }
      if ( *(_DWORD *)(v8 + 352) == KiCpuSetSequence || (*(_DWORD *)(v8 + 76) & 8) != 0 )
      {
        v36 = 1;
        goto LABEL_50;
      }
      *(_BYTE *)(v8 + 132) = 7;
      __dmb(0xBu);
      *(_DWORD *)(a1 + 24) = 0;
      KiDeferredReadyThread(a1, v8);
    }
    __dmb(0xBu);
    if ( a3 )
      *a3 = 0;
    else
      *(_DWORD *)(a2 + 24) = 0;
    v59 = *(_DWORD *)(a1 + 12);
    *(_DWORD *)(a1 + 8) = 0;
    if ( v8 != v59 )
      break;
    __dmb(0xBu);
    *(_DWORD *)(a1 + 24) = 0;
  }
  v16 = 1;
  v62 = 1;
  v36 = 0;
LABEL_50:
  v37 = 1;
  if ( v36 )
    v37 = 3;
  if ( (v37 & 2) != 0 )
  {
    if ( (*(_BYTE *)(v8 + 2) & 4) != 0 )
    {
      if ( *(char *)(v8 + 123) >= 16 )
        goto LABEL_67;
      if ( !*(_DWORD *)(v8 + 68) )
        goto LABEL_67;
      v38 = *(_DWORD *)(v8 + 68);
      if ( !v38 )
        goto LABEL_67;
      v39 = v38 + *(_DWORD *)(a1 + 2352);
      if ( !v39 )
        goto LABEL_67;
      if ( *(char *)(v8 + 123) >= 16 || (*(_DWORD *)(v8 + 80) & 0x100) != 0 )
      {
        v41 = 0;
      }
      else
      {
        v40 = v39;
        do
        {
          if ( (*(_BYTE *)(v40 + 92) & 2) != 0 )
          {
            v41 = -1;
            goto LABEL_65;
          }
          v40 = *(_DWORD *)(v40 + 236);
        }
        while ( v40 );
        do
        {
          v41 = *(_DWORD *)(v39 + 96);
          if ( v41 )
            break;
          v39 = *(_DWORD *)(v39 + 236);
        }
        while ( v39 );
LABEL_65:
        v16 = v62;
      }
      if ( v41 )
        v42 = 1;
      else
LABEL_67:
        v42 = *(_BYTE *)(v8 + 123);
      v43 = v42;
    }
    else
    {
      v43 = *(_BYTE *)(v8 + 123);
    }
    **(_BYTE **)(a1 + 28) = v43;
  }
  *(_DWORD *)(a1 + 4) = v8;
  *(_BYTE *)(v8 + 132) = 2;
  if ( v16 )
    return v8;
  v44 = *(unsigned __int8 *)(a1 + 19);
  v45 = *(_DWORD *)(a1 + 2360);
  *(_BYTE *)(a1 + 1755) = 0;
  if ( (v44 & 1) != 0 )
    __fastfail(0x21u);
  v46 = v44 + 1;
  *(_BYTE *)(a1 + 19) = v46;
  if ( v46 == 1 )
  {
    v47 = *(unsigned __int8 *)(a1 + 1053);
    __dmb(0xBu);
    v48 = 1 << (v47 & 7);
    v49 = (unsigned __int8 *)(v45 + (v47 >> 3));
    do
      v50 = __ldrex(v49);
    while ( __strex(v50 & ~(_BYTE)v48, v49) );
    __dmb(0xBu);
  }
  v51 = *(unsigned __int8 *)(a1 + 1053);
  __dmb(0xBu);
  v52 = 1 << (v51 & 7);
  v53 = (unsigned __int8 *)(v45 + (v51 >> 3) + 8);
  do
    v54 = __ldrex(v53);
  while ( __strex(v54 & ~(_BYTE)v52, v53) );
  __dmb(0xBu);
  v55 = ~*(_DWORD *)(a1 + 3468);
  __dmb(0xBu);
  v56 = (unsigned int *)(v45 + 4);
  do
    v57 = __ldrex(v56);
  while ( __strex(v57 & v55, v56) );
  __dmb(0xBu);
  return v8;
}
