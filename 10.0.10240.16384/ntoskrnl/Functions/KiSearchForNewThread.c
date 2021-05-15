// KiSearchForNewThread 
 
int __fastcall KiSearchForNewThread(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v7; // r9
  int v8; // r3
  int v9; // r7
  int v10; // r3
  int v11; // r2
  int v12; // r0
  unsigned __int8 *v13; // r3
  unsigned int v14; // r2
  int v15; // r2
  int v16; // r4
  unsigned __int8 *v17; // r2
  unsigned int v18; // r1
  int v19; // r4
  unsigned int *v20; // r2
  unsigned int v21; // r0
  int v22; // r4
  char v23; // r2
  BOOL v24; // r3
  int v25; // r6
  char v26; // r10
  int v27; // r8
  int v28; // r9
  int v29; // r2
  int v30; // r2
  unsigned int v31; // r7
  char v32; // r1
  char v34; // r2
  int v35; // r2
  int v36; // r2
  int v37; // r1
  int v38; // r3
  unsigned int *v39; // r9
  unsigned int v40; // r2
  int v41; // r2
  int v42; // r1
  char v43; // r3
  unsigned int v44; // r7
  char v45; // r2
  int v46; // r0
  int v47; // [sp+0h] [bp-28h] BYREF
  int v48; // [sp+4h] [bp-24h]
  int v49; // [sp+8h] [bp-20h]

  v47 = a2;
  v48 = a3;
  v49 = a4;
  v5 = *(_DWORD *)(a1 + 8);
  if ( v5 )
  {
    *(_DWORD *)(a1 + 4) = v5;
    *(_DWORD *)(a1 + 8) = 0;
    *(_BYTE *)(v5 + 132) = 2;
    return v5;
  }
  while ( 1 )
  {
    v5 = KiSelectReadyThread(1, a1);
    if ( !v5 )
    {
      v7 = *(_DWORD *)(a1 + 1980);
      if ( v7 )
      {
        while ( 1 )
        {
          v5 = KiSelectThreadFromSchedulingGroup(a1, v7 - 80, 0);
          if ( v5 )
            break;
          v7 = *(_DWORD *)(v7 + 152);
          if ( !v7 )
            goto LABEL_4;
        }
      }
      else
      {
LABEL_4:
        v5 = KiSelectReadyThread(0, a1);
        if ( !v5 )
        {
          if ( !a2 )
          {
            v8 = *(unsigned __int8 *)(a1 + 19);
            v9 = *(_DWORD *)(a1 + 2360);
            *(_BYTE *)(a1 + 1755) = 0;
            if ( (v8 & 1) == 0 )
              sub_52F74C();
            v10 = v8 - 1;
            *(_BYTE *)(a1 + 19) = v10;
            if ( !v10 )
            {
              v11 = *(unsigned __int8 *)(a1 + 1053);
              __dmb(0xBu);
              v12 = 1 << (v11 & 7);
              v13 = (unsigned __int8 *)(v9 + (v11 >> 3));
              do
                v14 = __ldrex(v13);
              while ( __strex(v14 | v12, v13) );
              __dmb(0xBu);
            }
            v15 = *(unsigned __int8 *)(a1 + 1053);
            __dmb(0xBu);
            v16 = 1 << (v15 & 7);
            v17 = (unsigned __int8 *)(v9 + (v15 >> 3) + 8);
            do
              v18 = __ldrex(v17);
            while ( __strex(v18 | v16, v17) );
            __dmb(0xBu);
            v19 = *(_DWORD *)(a1 + 3468);
            if ( (v19 & *(_DWORD *)(v9 + 8)) == v19 )
            {
              __dmb(0xBu);
              v20 = (unsigned int *)(v9 + 4);
              do
                v21 = __ldrex(v20);
              while ( __strex(v21 | v19, v20) );
              __dmb(0xBu);
            }
            v22 = *(_DWORD *)(a1 + 12);
            if ( (*(_BYTE *)(v22 + 2) & 4) != 0 )
            {
              if ( *(char *)(v22 + 123) < 16
                && *(_DWORD *)(v22 + 68)
                && (v41 = *(_DWORD *)(v22 + 68)) != 0
                && (v42 = v41 + *(_DWORD *)(a1 + 2352)) != 0
                && KiGetThreadEffectiveRankNonZero(*(_DWORD *)(a1 + 12), v42, 0) )
              {
                v43 = 1;
              }
              else
              {
                v43 = *(_BYTE *)(v22 + 123);
              }
              v23 = v43;
            }
            else
            {
              v23 = *(_BYTE *)(v22 + 123);
            }
            **(_BYTE **)(a1 + 28) = v23;
          }
          v24 = (*(_BYTE *)(a1 + 19) & 2) != 0;
          __dmb(0xBu);
          *(_DWORD *)(a1 + 24) = 0;
          if ( !v24 )
          {
            v25 = *(_DWORD *)(a1 + 2360);
            v26 = *(_BYTE *)(a1 + 1053);
            v27 = *(unsigned __int16 *)(v25 + 266);
            v28 = *(_DWORD *)(v25 + 256);
            v47 = 0;
LABEL_23:
            v29 = *(_DWORD *)(v25 + 272);
            if ( *(unsigned __int16 *)(v25 + 266) == v27 )
              v29 &= ~*(_DWORD *)(a1 + 3456);
            if ( v29 )
            {
              v44 = __ROR4__(v29, v26);
              do
              {
                v45 = __clz(__rbit(v44));
                v44 ^= 1 << v45;
                v5 = KiSearchForNewThreadOnProcessor(
                       a1,
                       0,
                       *((_DWORD *)*(&KiProcessorBlock + ((v45 + v26) & 0x1F)) + 865));
                if ( v5 )
                  return v5;
              }
              while ( v44 );
            }
            v30 = *(_DWORD *)(v25 + 260);
            if ( *(unsigned __int16 *)(v25 + 266) == v27 )
              v30 ^= *(_DWORD *)(a1 + 1048);
            if ( (v30 & ~*(_DWORD *)(v25 + 8)) != 0 )
            {
              v31 = __ROR4__(v30 & ~*(_DWORD *)(v25 + 8), v26);
              do
              {
                v32 = __clz(__rbit(v31));
                v31 ^= 1 << v32;
                v5 = KiSearchForNewThreadOnProcessor(a1, *(&KiProcessorBlock + ((v32 + v26) & 0x1F)), 0);
                if ( v5 )
                  return v5;
              }
              while ( v31 );
            }
            v28 &= ~(1 << *(_WORD *)(v25 + 266));
            if ( v28 )
            {
              while ( 1 )
              {
                v46 = MmGetNextNode(v27, &v47);
                if ( v46 == -1 )
                  break;
                if ( ((1 << v46) & v28) != 0 )
                {
                  v25 = (int)*(&KeNodeBlock + v46);
                  goto LABEL_23;
                }
              }
            }
          }
          return 0;
        }
      }
    }
    v48 = MEMORY[0x681FE4];
    if ( *(_DWORD *)(v5 + 352) == KiCpuSetSequence || (*(_DWORD *)(v5 + 76) & 8) != 0 )
      break;
    *(_BYTE *)(v5 + 132) = 7;
    __dmb(0xBu);
    v39 = (unsigned int *)(a1 + 24);
    *(_DWORD *)(a1 + 24) = 0;
    KiDeferredReadyThread(a1, v5);
    while ( 1 )
    {
      do
        v40 = __ldrex(v39);
      while ( __strex(1u, v39) );
      __dmb(0xBu);
      if ( !v40 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v39 );
    }
    if ( a2 && *(_DWORD *)(a1 + 8) == *(_DWORD *)(a1 + 12) )
      *(_DWORD *)(a1 + 8) = 0;
    v5 = *(_DWORD *)(a1 + 8);
    if ( v5 )
    {
      *(_DWORD *)(a1 + 4) = v5;
      *(_DWORD *)(a1 + 8) = 0;
      *(_BYTE *)(v5 + 132) = 2;
      return v5;
    }
  }
  if ( (*(_BYTE *)(v5 + 2) & 4) == 0 )
  {
    v34 = *(_BYTE *)(v5 + 123);
    goto LABEL_39;
  }
  if ( *(char *)(v5 + 123) >= 16
    || !*(_DWORD *)(v5 + 68)
    || (v35 = *(_DWORD *)(v5 + 68)) == 0
    || (v36 = v35 + *(_DWORD *)(a1 + 2352)) == 0 )
  {
LABEL_54:
    v34 = *(_BYTE *)(v5 + 123);
    goto LABEL_39;
  }
  if ( *(char *)(v5 + 123) >= 16 || (*(_DWORD *)(v5 + 80) & 0x100) != 0 )
  {
    v38 = 0;
LABEL_53:
    if ( v38 )
      goto LABEL_55;
    goto LABEL_54;
  }
  v37 = v36;
  do
  {
    if ( (*(_BYTE *)(v37 + 92) & 2) != 0 )
    {
      v38 = -1;
      goto LABEL_53;
    }
    v37 = *(_DWORD *)(v37 + 236);
  }
  while ( v37 );
  while ( 1 )
  {
    v38 = *(_DWORD *)(v36 + 96);
    if ( v38 )
      break;
    v36 = *(_DWORD *)(v36 + 236);
    if ( !v36 )
      goto LABEL_53;
  }
LABEL_55:
  v34 = 1;
LABEL_39:
  **(_BYTE **)(a1 + 28) = v34;
  *(_DWORD *)(a1 + 4) = v5;
  *(_BYTE *)(v5 + 132) = 2;
  if ( !a2 )
    return v5;
  KiSetProcessorIdle(a1, 0, 0);
  return v5;
}
