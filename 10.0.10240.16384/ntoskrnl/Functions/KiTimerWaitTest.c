// KiTimerWaitTest 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiTimerWaitTest(int a1, unsigned int a2, int a3)
{
  unsigned int v4; // r4
  signed int v5; // r1
  int v6; // r8
  unsigned int v8; // r4
  int v9; // r9
  BOOL v10; // r5
  unsigned int v11; // r0
  int v12; // r1
  unsigned int v13; // r2
  unsigned int v15; // lr
  unsigned __int64 v16; // kr10_8
  int v17; // r8
  _DWORD *v18; // r5
  unsigned int v19; // r0
  unsigned __int8 *v20; // r3
  int v21; // r5
  int v22; // r1 OVERLAPPED
  unsigned __int8 **v23; // r2 OVERLAPPED
  int v24; // r3
  int v25; // r3
  int v26; // r1
  int v27; // r3
  int v28; // r2
  int v29; // r2
  int v30; // r2
  int v31; // r0
  unsigned __int8 *v32; // r3
  unsigned int v33; // r2
  int v34; // r0
  unsigned int v35; // r3
  int v36; // lr
  int v37; // r0
  int v38; // r1
  unsigned int v39; // r2
  unsigned int v40; // r1
  int v41; // r3
  int v42; // r0
  unsigned int v43; // r3
  int v44; // lr
  int v45; // r0
  int v46; // r1
  unsigned int v47; // r2
  unsigned int v48; // r1
  int v49; // r2
  int *v50; // r1
  BOOL v51; // r2
  unsigned int v52; // r2
  BOOL v53; // r2
  unsigned int v54; // r2
  int v55; // r1
  int **v56; // r0
  int v57; // [sp+8h] [bp-50h]
  int *v58; // [sp+8h] [bp-50h]
  int v59; // [sp+8h] [bp-50h]
  unsigned int v60; // [sp+Ch] [bp-4Ch]
  int v61; // [sp+Ch] [bp-4Ch]
  int v62; // [sp+Ch] [bp-4Ch]
  unsigned int v64; // [sp+14h] [bp-44h]
  unsigned __int8 *v65; // [sp+14h] [bp-44h]
  int v66; // [sp+20h] [bp-38h]
  int v67; // [sp+20h] [bp-38h]
  unsigned int v68; // [sp+28h] [bp-30h]

  v4 = *(_DWORD *)(a2 + 32);
  v5 = *(_DWORD *)(a2 + 40);
  v6 = a3;
  v8 = bswap32(__ROR4__(v4 ^ KiWaitNever, -(char)KiWaitNever) ^ a2) ^ KiWaitAlways;
  v9 = 255;
  v10 = (*(_BYTE *)a2 & 0x7F) == 8;
  if ( v5 )
  {
    v11 = (unsigned __int64)(-10000i64 * v5) >> 32;
    v12 = -10000 * v5;
    v64 = v11;
    v57 = v12;
    if ( *(_BYTE *)(a1 + 1754) )
    {
      v13 = *(_DWORD *)(a1 + 2340) + 1;
      *(_DWORD *)(a1 + 2340) = v13;
      if ( v13 >= 0xBB8 )
        return sub_52EAC4();
      v11 = (__PAIR64__(v11, v12) - *(unsigned int *)(a1 + 2344)) >> 32;
      v12 -= *(_DWORD *)(a1 + 2344);
      v64 = v11;
      v57 = v12;
    }
    while ( 1 )
    {
      v15 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v60 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v15 == MEMORY[0xFFFF9010] )
        break;
      __dmb(0xAu);
      __yield();
    }
    if ( (((__PAIR64__(v11, v12) + __PAIR64__(v15, v60) - *(_QWORD *)(a2 + 16)) >> 32) & 0x80000000) == 0i64 )
    {
      *(_DWORD *)(a2 + 16) = v60;
      *(_DWORD *)(a2 + 20) = v15;
    }
    v61 = 0;
    v68 = *(_DWORD *)a2;
    if ( (*(_DWORD *)a2 & 0xFC00) != 0 )
      v61 = (BYTE1(v68) & 0xFC) << 16;
    BYTE1(v68) = BYTE1(*(_DWORD *)a2) & 0xFE;
    HIBYTE(v68) = 64;
    do
    {
      v16 = *(_QWORD *)(a2 + 16) - __PAIR64__(v64, v57);
      *(_QWORD *)(a2 + 16) = v16;
      BYTE2(v68) = (unsigned int)(v16 + v61) >> 18;
      *(_DWORD *)a2 = v68;
    }
    while ( !KiInsertTimerTable(a1, a2, v8, BYTE2(v68)) );
    v9 = 0;
    v6 = a3;
  }
  *(_DWORD *)(a2 + 4) = 1;
  if ( v10 )
  {
    v17 = *(_DWORD *)(a2 + 8);
    v18 = (_DWORD *)(a2 + 8);
    if ( v17 == a2 + 8 )
    {
LABEL_16:
      v6 = a3;
      *v18 = v18;
      *(_DWORD *)(a2 + 12) = a2 + 8;
      goto LABEL_17;
    }
    while ( 1 )
    {
      v26 = v17;
      v27 = *(unsigned __int8 *)(v17 + 8);
      v17 = *(_DWORD *)v17;
      v58 = (int *)v26;
      if ( v27 == 1 )
      {
        v28 = *(unsigned __int16 *)(v26 + 10);
      }
      else
      {
        if ( v27 == 2 )
        {
          *(_BYTE *)(v26 + 9) = 5;
          v42 = *(_DWORD *)(v26 + 12);
          *(_DWORD *)v26 = 0;
          v62 = v42;
          KfRaiseIrql(2);
          v43 = (unsigned int)KeGetPcr();
          v44 = (v43 & 0xFFFFF000) + 1408;
          v45 = *(_DWORD *)((v43 & 0xFFFFF000) + 0x584);
          v67 = v45;
          if ( (dword_682604 & 0x1000000) != 0 )
          {
            v53 = *(_BYTE *)(v45 + 132) == 2
               && *(_DWORD *)(v45 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
            EtwTraceEnqueueWork(v45, v58, v53);
            v45 = v67;
          }
          v46 = v62;
          do
            v47 = __ldrex((unsigned __int8 *)v62);
          while ( __strex(v47 | 0x80, (unsigned __int8 *)v62) );
          __dmb(0xBu);
          if ( v47 >> 7 )
          {
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
              }
              while ( (*(_DWORD *)v62 & 0x80) != 0 );
              do
                v54 = __ldrex((unsigned __int8 *)v62);
              while ( __strex(v54 | 0x80, (unsigned __int8 *)v62) );
              __dmb(0xBu);
            }
            while ( v54 >> 7 );
          }
          if ( *(_DWORD *)(v62 + 12) == v62 + 8
            || *(_DWORD *)(v62 + 24) >= *(_DWORD *)(v62 + 28)
            || *(_DWORD *)(v45 + 152) == v62 && *(_BYTE *)(v45 + 395) == 15 )
          {
LABEL_98:
            ++*(_DWORD *)(v46 + 4);
            v55 = v46 + 16;
            v56 = *(int ***)(v55 + 4);
            *v58 = v55;
            v58[1] = (int)v56;
            if ( *v56 != (int *)v55 )
              __fastfail(3u);
            *v56 = v58;
            *(_DWORD *)(v55 + 4) = v58;
          }
          else if ( !KiWakeQueueWaiter(v44, v62, (int)v58) )
          {
            v46 = v62;
            goto LABEL_98;
          }
          __dmb(0xBu);
          do
            v48 = __ldrex((unsigned int *)v62);
          while ( __strex(v48 & 0xFFFFFF7F, (unsigned int *)v62) );
          goto LABEL_37;
        }
        v28 = 256;
      }
      KiTryUnwaitThread(a1, v26, v28, 0);
LABEL_37:
      if ( (_DWORD *)v17 == v18 )
        goto LABEL_16;
    }
  }
  v20 = *(unsigned __int8 **)(a2 + 8);
  if ( v20 != (unsigned __int8 *)(a2 + 8) )
  {
    do
    {
      v21 = (int)v20;
      *(_QWORD *)&v22 = *(_QWORD *)v20;
      v65 = *(unsigned __int8 **)v20;
      if ( *(unsigned __int8 **)(*(_DWORD *)v20 + 4) != v20 || *v23 != v20 )
        __fastfail(3u);
      *v23 = (unsigned __int8 *)v22;
      *(_DWORD *)(v22 + 4) = v23;
      v24 = v20[8];
      if ( v24 == 1 )
      {
        if ( KiTryUnwaitThread(a1, v21, *(unsigned __int16 *)(v21 + 10), 0) )
        {
          v25 = *(_DWORD *)(a2 + 4) - 1;
          *(_DWORD *)(a2 + 4) = v25;
          if ( !v25 )
            break;
        }
        goto LABEL_32;
      }
      if ( v24 != 2 )
      {
        KiTryUnwaitThread(a1, v21, 256, 0);
        goto LABEL_32;
      }
      *(_BYTE *)(v21 + 9) = 5;
      v34 = *(_DWORD *)(v21 + 12);
      *(_DWORD *)v21 = 0;
      v59 = v34;
      KfRaiseIrql(2);
      v35 = (unsigned int)KeGetPcr();
      v36 = (v35 & 0xFFFFF000) + 1408;
      v37 = *(_DWORD *)((v35 & 0xFFFFF000) + 0x584);
      v66 = v37;
      if ( (dword_682604 & 0x1000000) != 0 )
      {
        v51 = *(_BYTE *)(v37 + 132) == 2
           && *(_DWORD *)(v37 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
        EtwTraceEnqueueWork(v37, v21, v51);
        v37 = v66;
      }
      v38 = v59;
      do
        v39 = __ldrex((unsigned __int8 *)v59);
      while ( __strex(v39 | 0x80, (unsigned __int8 *)v59) );
      __dmb(0xBu);
      if ( v39 >> 7 )
      {
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( (*(_DWORD *)v59 & 0x80) != 0 );
          do
            v52 = __ldrex((unsigned __int8 *)v59);
          while ( __strex(v52 | 0x80, (unsigned __int8 *)v59) );
          __dmb(0xBu);
        }
        while ( v52 >> 7 );
      }
      if ( *(_DWORD *)(v59 + 12) != v59 + 8
        && *(_DWORD *)(v59 + 24) < *(_DWORD *)(v59 + 28)
        && (*(_DWORD *)(v37 + 152) != v59 || *(_BYTE *)(v37 + 395) != 15) )
      {
        if ( KiWakeQueueWaiter(v36, v59, v21) )
          goto LABEL_53;
        v38 = v59;
      }
      v49 = v38 + 16;
      ++*(_DWORD *)(v38 + 4);
      v50 = *(int **)(v38 + 20);
      *(_DWORD *)v21 = v49;
      *(_DWORD *)(v21 + 4) = v50;
      if ( *v50 != v49 )
        __fastfail(3u);
      *v50 = v21;
      *(_DWORD *)(v49 + 4) = v21;
LABEL_53:
      __dmb(0xBu);
      do
        v40 = __ldrex((unsigned int *)v59);
      while ( __strex(v40 & 0xFFFFFF7F, (unsigned int *)v59) );
      v41 = *(_DWORD *)(a2 + 4) - 1;
      *(_DWORD *)(a2 + 4) = v41;
      if ( !v41 )
        break;
LABEL_32:
      v20 = v65;
    }
    while ( v65 != (unsigned __int8 *)(a2 + 8) );
  }
LABEL_17:
  if ( v8 )
  {
    if ( v6 )
    {
      if ( (!KiSerializeTimerExpiration || *(unsigned __int16 *)(v8 + 2) < 0x20u)
        && (*(_BYTE *)v8 != 26 || !*(_BYTE *)(a1 + 1752)) )
      {
        *(_DWORD *)(a1 + 1700) = v8;
        if ( (*(_DWORD *)(v8 + 8) & *(_DWORD *)(a1 + 1048)) == 0 )
        {
          v30 = *(unsigned __int8 *)(a1 + 1053);
          __dmb(0xBu);
          v31 = 1 << (v30 & 7);
          v32 = (unsigned __int8 *)(v8 + (v30 >> 3) + 8);
          do
            v33 = __ldrex(v32);
          while ( __strex(v33 | v31, v32) );
          __dmb(0xBu);
        }
        goto LABEL_23;
      }
    }
    else
    {
      while ( 1 )
      {
        v29 = MEMORY[0xFFFF9018];
        __dmb(0xBu);
        __dmb(0xBu);
        if ( v29 == MEMORY[0xFFFF901C] )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
    KiInsertQueueDpc(v8);
    return 0;
  }
LABEL_23:
  __dmb(0xBu);
  do
    v19 = __ldrex((unsigned int *)a2);
  while ( __strex(v19 & ~((v9 << 24) | 0x80), (unsigned int *)a2) );
  __dmb(0xBu);
  return v8;
}
