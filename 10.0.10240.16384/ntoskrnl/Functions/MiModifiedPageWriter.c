// MiModifiedPageWriter 
 
int __fastcall MiModifiedPageWriter(unsigned int a1)
{
  int v2; // r0
  int v3; // r4
  int v4; // r7
  unsigned int v5; // r10
  int v6; // r6
  __int64 v7; // r0
  unsigned int v8; // r10
  int v9; // r2
  int v10; // r2
  unsigned int v11; // r6
  int v12; // r3
  _DWORD *v13; // r0
  char v14; // r8
  int v15; // r7
  __int64 *v16; // r6
  __int64 v17; // r2
  __int16 v18; // r3
  __int16 v19; // r3
  __int16 v21; // r3
  unsigned int v22; // r8
  unsigned int v23; // r7
  unsigned int v24; // r6
  int v25; // r2
  unsigned int *v26; // r2
  unsigned int **v27; // r1
  int v28; // r3
  unsigned int v29; // t0
  BOOL v30; // r9
  int v31; // r7
  unsigned int v32; // r6
  int v33; // r8
  unsigned int v34; // r6
  unsigned int v35; // r7
  unsigned int *v36; // r2
  unsigned int v37; // r1
  __int16 v38; // r3
  unsigned int *v39; // r0
  unsigned int v40; // r1
  int v41; // r8
  unsigned int v42; // r7
  unsigned int i; // r6
  _DWORD *v44; // r9
  __int16 v45; // r3
  __int16 v46; // r3
  int v47; // [sp+10h] [bp-D8h]
  int v48; // [sp+10h] [bp-D8h]
  unsigned int v49[2]; // [sp+18h] [bp-D0h] BYREF
  int v50; // [sp+20h] [bp-C8h]
  int v51[12]; // [sp+28h] [bp-C0h] BYREF
  unsigned int v52[4]; // [sp+58h] [bp-90h] BYREF
  int v53[32]; // [sp+68h] [bp-80h] BYREF

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(a1 + 560) = v2;
  *(_DWORD *)(v2 + 964) |= 2u;
  v50 = KeSetActualBasePriorityThread(v2, 18);
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v49[0] = a1 + 120;
  v49[1] = a1 + 428;
  v52[0] = a1 + 120;
  v4 = a1 + 520;
  v5 = a1 + 544;
  v6 = a1 + 404;
  *(_DWORD *)(a1 + 484) = 0;
  *(_DWORD *)(a1 + 488) = 0;
  v47 = v3;
  v52[1] = a1 + 520;
  v52[2] = a1 + 544;
  v52[3] = a1 + 404;
  LODWORD(v7) = KeWaitForMultipleObjects(2u, v49, 1, 19, 0, 0, 0, v51);
  if ( (_DWORD)v7 )
  {
    v8 = a1 + 536;
    v9 = v3 + 100;
    while ( 1 )
    {
      while ( 1 )
      {
        if ( *(_DWORD *)(a1 + 124) )
        {
LABEL_88:
          v5 = a1 + 544;
          goto LABEL_89;
        }
        if ( !*(_DWORD *)(a1 + 4120) )
          goto LABEL_40;
        --*(_WORD *)(v3 + 310);
        if ( *(_DWORD *)v8 == v8 )
        {
          *(_BYTE *)(a1 + 381) = 1;
          v19 = *(_WORD *)(v3 + 310) + 1;
          *(_WORD *)(v3 + 310) = v19;
          if ( !v19 && *(_DWORD *)(v3 + 100) != v9 )
            return sub_5515B8();
          LODWORD(v7) = KeWaitForMultipleObjects(4u, v52, 1, 19, 0, 0, 0, v53);
          if ( !(_DWORD)v7 )
            goto LABEL_88;
          --*(_WORD *)(v3 + 310);
          *(_BYTE *)(a1 + 381) = 0;
        }
        if ( *(_DWORD *)(a1 + 408) )
        {
          LODWORD(v7) = KeResetEvent(v6);
          if ( *(_DWORD *)(a1 + 400) )
            LODWORD(v7) = IoBoostThreadIoPriority(v3, 2, 0);
        }
        if ( *(_DWORD *)(a1 + 524) )
        {
          LODWORD(v7) = KeResetEvent(v4);
          __dmb(0xFu);
          v22 = *(_DWORD *)(a1 + 3596);
          __dmb(0xBu);
          v23 = 0;
          if ( v22 )
          {
            v24 = a1;
            do
            {
              v25 = *(_DWORD *)(v24 + 3600);
              if ( (*(_BYTE *)(v25 + 98) & 1) != 0 )
              {
                *(_BYTE *)(v25 + 98) &= 0xFEu;
                LODWORD(v7) = 0;
                do
                {
                  v26 = *(unsigned int **)(*(_DWORD *)(v24 + 3600) + v7 + 36);
                  if ( v26 && *v26 == -1719109871 )
                  {
                    v27 = *(unsigned int ***)(v8 + 4);
                    *v26 = v8;
                    v26[1] = (unsigned int)v27;
                    if ( *v27 != (unsigned int *)v8 )
                      __fastfail(3u);
                    *v27 = v26;
                    *(_DWORD *)(v8 + 4) = v26;
                  }
                  LODWORD(v7) = v7 + 4;
                }
                while ( (unsigned int)v7 < 8 );
              }
              ++v23;
              v24 += 4;
            }
            while ( v23 < v22 );
          }
        }
        v10 = *(_DWORD *)(a1 + 3840);
        v11 = *(_DWORD *)(a1 + 4120);
        if ( v10 < 0 )
          v10 = 0;
        if ( *(_DWORD *)(a1 + 480) < 0x800u && (v11 > *(_DWORD *)(a1 + 3592) >> 2 || v11 > (unsigned int)v10 >> 2) )
        {
          LODWORD(v7) = *(_DWORD *)(a1 + 488);
          if ( (unsigned int)v7 >= 0x40 )
          {
            HIDWORD(v7) = *(_DWORD *)(a1 + 484);
            v29 = HIDWORD(v7) / (unsigned int)v7;
            HIDWORD(v7) %= (unsigned int)v7;
            LODWORD(v7) = v29;
            if ( v29 < (unsigned int)dword_681270 >> 3 )
            {
              v30 = *(_DWORD *)(a1 + 1792) > 3 * (v11 >> 2);
              v31 = *(_DWORD *)(a1 + 3596);
              __dmb(0xBu);
              if ( v31 )
              {
                v32 = a1;
                do
                {
                  v33 = *(_DWORD *)(v32 + 3600);
                  LODWORD(v7) = MiFreeModifiedReservations(v33, HIDWORD(v7), v10);
                  if ( v30 && (*(_WORD *)(a1 + 516) & 1) == 0 )
                    *(_DWORD *)(v33 + 76) = dword_681270;
                  v32 += 4;
                  --v31;
                }
                while ( v31 );
                v3 = v47;
                v8 = a1 + 536;
              }
              ++*(_DWORD *)(a1 + 496);
              if ( v30 )
              {
                do
                {
                  v7 = MEMORY[0xFFFF93B0];
                  while ( 1 )
                  {
                    v34 = MEMORY[0xFFFF900C];
                    __dmb(0xBu);
                    v35 = MEMORY[0xFFFF9008];
                    __dmb(0xBu);
                    if ( v34 == MEMORY[0xFFFF9010] )
                      break;
                    __dmb(0xAu);
                    __yield();
                  }
                }
                while ( v7 != MEMORY[0xFFFF93B0] );
                *(_QWORD *)(a1 + 504) = __PAIR64__(v34, v35) - v7;
                __dmb(0xFu);
                *(_WORD *)(a1 + 516) |= 1u;
                ++*(_DWORD *)(a1 + 492);
              }
              *(_DWORD *)(a1 + 484) = 0;
              *(_DWORD *)(a1 + 488) = 0;
            }
          }
        }
        if ( *(_DWORD *)v8 != v8 )
          break;
        v6 = a1 + 404;
        v4 = a1 + 520;
        v28 = (__int16)(*(_WORD *)(v3 + 310) + 1);
        *(_WORD *)(v3 + 310) = v28;
        v9 = v3 + 100;
        if ( !v28 )
        {
          v6 = a1 + 404;
          v9 = v3 + 100;
          v4 = a1 + 520;
          if ( *(_DWORD *)(v3 + 100) != v3 + 100 )
          {
            LODWORD(v7) = KiCheckForKernelApcDelivery(v7);
            goto LABEL_25;
          }
        }
      }
      v12 = *(_DWORD *)(a1 + 664);
      if ( (v12 & 1) != 0 && (v12 & 0xFFFFFFFE) == 0 )
      {
        v36 = (unsigned int *)(a1 + 664);
        do
          v37 = __ldrex(v36);
        while ( v37 == 1 && __strex(0, v36) );
        if ( v37 == 1 )
          break;
      }
      v13 = (_DWORD *)MiUseLowIoPriorityForModifiedPages((_DWORD *)a1);
      if ( v13 )
      {
        if ( *(_DWORD *)(a1 + 4120) < *(_DWORD *)(a1 + 424) )
        {
          v21 = *(_WORD *)(v3 + 310) + 1;
          *(_WORD *)(v3 + 310) = v21;
          if ( !v21 && *(_DWORD *)(v3 + 100) != v3 + 100 )
            KiCheckForKernelApcDelivery((int)v13);
LABEL_39:
          v6 = a1 + 404;
LABEL_40:
          *(_DWORD *)(a1 + 484) = 0;
          *(_DWORD *)(a1 + 488) = 0;
          LODWORD(v7) = KeWaitForMultipleObjects(2u, v49, 1, 19, 0, 0, 0, v51);
          if ( !(_DWORD)v7 )
            goto LABEL_88;
          goto LABEL_26;
        }
        *(_DWORD *)(a1 + 420) = 4;
        v14 = 0;
        v13 = (_DWORD *)KeSetActualBasePriorityThread(v3, 4);
        v15 = (int)v13;
      }
      else
      {
        if ( *(_DWORD *)(a1 + 400) )
          v13 = IoBoostThreadIoPriority(v3, 2, 0);
        v14 = 2;
        v15 = -1;
      }
      v16 = *(__int64 **)v8;
      v17 = *(_QWORD *)*(_DWORD *)v8;
      if ( HIDWORD(v17) != v8 || *(__int64 **)(v17 + 4) != v16 )
        __fastfail(3u);
      *(_DWORD *)v8 = v17;
      *(_DWORD *)(v17 + 4) = v8;
      *(_DWORD *)v16 = 97;
      *((_DWORD *)v16 + 5) ^= ((unsigned __int8)*((_DWORD *)v16 + 5) ^ (unsigned __int8)(4 * v14)) & 0x1C;
      v18 = *(_WORD *)(v3 + 310) + 1;
      *(_WORD *)(v3 + 310) = v18;
      if ( !v18 && *(_DWORD *)(v3 + 100) != v3 + 100 )
        KiCheckForKernelApcDelivery((int)v13);
      LODWORD(v7) = MiGatherPagefilePages((int)v16);
      v6 = a1 + 404;
      v9 = v3 + 100;
      if ( v15 != -1 )
      {
        LODWORD(v7) = KeQueryPriorityThread(v3);
        if ( (_DWORD)v7 != 18 )
          LODWORD(v7) = KeSetActualBasePriorityThread(v3, v15);
        *(_DWORD *)(a1 + 420) = 18;
LABEL_25:
        v6 = a1 + 404;
LABEL_26:
        v9 = v3 + 100;
      }
      v4 = a1 + 520;
    }
    v38 = *(_WORD *)(v3 + 310) + 1;
    *(_WORD *)(v3 + 310) = v38;
    if ( !v38 && *(_DWORD *)(v3 + 100) != v3 + 100 )
      KiCheckForKernelApcDelivery(0);
    KeResetEvent(a1 + 428);
    goto LABEL_39;
  }
LABEL_89:
  v39 = (unsigned int *)(a1 + 564);
  do
    v40 = __ldrex(v39);
  while ( !v40 && __strex(1u, v39) );
  __dmb(0xBu);
  if ( v40 && v40 != 1 )
    v39 = ExfWaitForRundownProtectionRelease(v39, v40);
  if ( *(_DWORD *)(a1 + 408) )
  {
    v39 = (unsigned int *)KeResetEvent(v6);
    if ( *(_DWORD *)(a1 + 400) )
      v39 = IoBoostThreadIoPriority(v3, 2, 0);
  }
  v41 = *(_DWORD *)(a1 + 3596);
  v48 = v41;
  __dmb(0xBu);
  if ( v41 )
  {
    v42 = a1;
    v49[0] = a1;
    do
    {
      if ( *(_DWORD *)(v42 + 3600) )
      {
        --*(_WORD *)(v3 + 310);
        for ( i = 0; i < 8; i += 4 )
        {
          v44 = *(_DWORD **)(*(_DWORD *)(v42 + 3600) + i + 36);
          if ( v44 )
          {
            while ( *v44 == 97 )
            {
              *(_BYTE *)(a1 + 381) = 1;
              v45 = *(_WORD *)(v3 + 310) + 1;
              *(_WORD *)(v3 + 310) = v45;
              if ( !v45 && *(_DWORD *)(v3 + 100) != v3 + 100 )
                KiCheckForKernelApcDelivery((int)v39);
              v39 = (unsigned int *)KeWaitForSingleObject(v5, 19, 0, 0, 0);
              --*(_WORD *)(v3 + 310);
            }
            v42 = v49[0];
          }
        }
        v41 = v48;
        v46 = *(_WORD *)(v3 + 310) + 1;
        *(_WORD *)(v3 + 310) = v46;
        if ( !v46 && *(_DWORD *)(v3 + 100) != v3 + 100 )
          v39 = (unsigned int *)KiCheckForKernelApcDelivery((int)v39);
      }
      v42 += 4;
      v48 = --v41;
      v49[0] = v42;
    }
    while ( v41 );
  }
  return KeSetActualBasePriorityThread(v3, v50);
}
