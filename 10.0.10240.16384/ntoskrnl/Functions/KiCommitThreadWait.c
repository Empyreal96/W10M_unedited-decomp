// KiCommitThreadWait 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiCommitThreadWait(int a1, int a2, int a3, int a4, __int64 a5)
{
  unsigned int v6; // r10
  int v8; // lr
  int v9; // r9
  int v10; // r0
  int v11; // r8
  int v12; // r3
  BOOL v13; // r1
  unsigned int *v14; // r7
  unsigned int v15; // r2
  unsigned int *v16; // lr
  unsigned int v17; // r2
  int *v18; // r0
  int v19; // r2
  unsigned int *v20; // lr
  int v21; // r4
  __int64 v23; // r0
  __int64 v24; // r2
  unsigned int v25; // kr10_4
  unsigned int v26; // r0
  unsigned int v27; // r1
  unsigned int *v28; // r2
  unsigned int v29; // r1
  unsigned int *v30; // r1
  unsigned int v31; // r2
  int v32; // r1
  unsigned int v33; // r0
  unsigned __int8 *v34; // r2
  unsigned int v35; // r1
  int v36; // r6
  unsigned __int8 *v37; // r0
  unsigned int v38; // r2
  int v39; // r1 OVERLAPPED
  _DWORD *v40; // r2 OVERLAPPED
  unsigned int v41; // r1
  int v42; // r3
  _BYTE *v43; // r2
  int v44; // r3
  unsigned int *v45; // r2
  unsigned int v46; // r1
  unsigned int *v47; // r2
  unsigned int v48; // r1
  unsigned int v49; // r2
  int v50; // r1
  unsigned int v51; // r2
  unsigned __int8 *v52; // r3
  unsigned int v53; // r2
  unsigned __int8 *v54; // r3
  unsigned int v55; // r2
  unsigned int v56; // [sp+8h] [bp-38h] BYREF
  int v57; // [sp+10h] [bp-30h]
  int varg_r0; // [sp+48h] [bp+8h]
  int varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]
  int varg_r3; // [sp+54h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  __pld((void *)(a1 + 72));
  v6 = a1 + 168;
  v8 = a2;
  v9 = 0;
  v10 = 0;
  if ( a3 )
  {
    *(_DWORD *)(a1 + 76) |= 0x200u;
    *(_DWORD *)v6 |= 0x40000080u;
  }
  v11 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  v12 = *(char *)(a1 + 135);
  *(_DWORD *)(a1 + 140) = a2;
  v13 = v12 && (*(_DWORD *)(a1 + 80) & 0x20) != 0 && *(char *)(a1 + 123) < 25;
  v14 = (unsigned int *)(a1 + 44);
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
  if ( (*(_BYTE *)(a1 + 72) & 0xE7) == 0 )
  {
    *(_BYTE *)(a1 + 72) = *(_BYTE *)(a1 + 72) & 0xF8 | 1;
    if ( v13 )
    {
      v16 = (unsigned int *)(v11 + 1928);
      while ( 1 )
      {
        do
          v17 = __ldrex(v16);
        while ( __strex(1u, v16) );
        __dmb(0xBu);
        if ( !v17 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v16 );
      }
      v18 = *(int **)(v11 + 1924);
      v19 = a1 + 144;
      *(_DWORD *)(a1 + 144) = v11 + 1920;
      *(_DWORD *)(a1 + 148) = v18;
      if ( *v18 != v11 + 1920 )
        sub_52F4D8();
      *v18 = v19;
      *(_DWORD *)(v11 + 1924) = v19;
      *(_DWORD *)(a1 + 436) = v11;
      __dmb(0xBu);
      *v16 = 0;
    }
    if ( (*(_DWORD *)(a1 + 80) & 0x800) != 0 )
    {
      v54 = (unsigned __int8 *)(a1 + 81);
      do
        v55 = __ldrex(v54);
      while ( __strex(v55 & 0xF7, v54) );
    }
    if ( (*(_DWORD *)(a1 + 76) & 0x80000) != 0 )
    {
      v34 = (unsigned __int8 *)(a1 + 82);
      do
        v35 = __ldrex(v34);
      while ( __strex(v35 | 4, v34) );
      if ( !((unsigned __int8)(v35 & 4) >> 2) )
        v9 = 1;
    }
    if ( *(_BYTE *)(a1 + 395) != 15 && (v20 = *(unsigned int **)(a1 + 152)) != 0 )
    {
      __pld(v20);
      if ( (*(_BYTE *)v20 & 0x7F) == 21 )
      {
        v32 = *(unsigned __int8 *)(a1 + 332);
        *(_DWORD *)(a1 + 332) = v32 | 0x100;
        __dmb(0xBu);
        v30 = &v20[v32 + 68];
        do
          v33 = __ldrex(v30);
        while ( __strex(v33 - 1, v30) );
      }
      else
      {
        __dmb(0xBu);
        v28 = v20 + 6;
        do
        {
          v29 = __ldrex(v28);
          v30 = (unsigned int *)(v29 - 1);
        }
        while ( __strex((unsigned int)v30, v28) );
      }
      __dmb(0xBu);
      __dmb(0xBu);
      do
        v31 = __ldrex((unsigned __int8 *)v20);
      while ( __strex(v31 | 0x80, (unsigned __int8 *)v20) );
      __dmb(0xBu);
      __dmb(0xBu);
      *v14 = 0;
      if ( v31 >> 7 )
      {
        KiActivateWaiterQueueWithNoLocks(a1, (unsigned int)v20, 0);
      }
      else if ( (*(_BYTE *)v20 & 0x7F) == 21 )
      {
        KiActivateWaiterPriQueue((int)v20, (int)v30, v31, 21);
      }
      else
      {
        KiActivateWaiterKQueue(v20);
      }
    }
    else
    {
      __dmb(0xBu);
      *v14 = 0;
    }
    if ( v9 )
      KiDecrementProcessStackCount(*(_DWORD *)(a1 + 116));
    *(_BYTE *)(a1 + 349) = 0;
    if ( !a3 )
      return KiSwapThread(a1, v11);
    if ( a3 == 2 )
    {
      HIDWORD(v24) = MEMORY[0xFFFF93B4];
      LODWORD(v23) = MEMORY[0xFFFF93B0];
      HIDWORD(v23) = *(_DWORD *)(a1 + 164);
      LODWORD(v24) = *(_DWORD *)(a1 + 160);
      v25 = v24 + MEMORY[0xFFFF93B0];
      LODWORD(v23) = (unsigned __int64)(v24 + v23) >> 32;
      *(_QWORD *)(v6 + 16) = __PAIR64__(v23, (int)v24 + MEMORY[0xFFFF93B0]) + a5;
      HIDWORD(v24) = (__PAIR64__(v23, v25) + a5) >> 32 << 14;
      v26 = (unsigned __int8)((v25 + (unsigned int)a5) >> 18);
      v57 = *(_DWORD *)v6;
      BYTE2(v57) = BYTE4(v24) | ((v25 + (unsigned int)a5) >> 18);
      BYTE1(v57) &= 0xFEu;
      *(_DWORD *)v6 = v57;
    }
    else
    {
      if ( !KiComputeDueTime((_DWORD *)v6, a5, 0, &v56) )
        goto LABEL_110;
      v26 = v56;
    }
    if ( KiInsertTimerTable(v11, (_DWORD *)v6, 0, v26, 0) )
    {
      if ( (dword_682608 & 0x20000) != 0 )
      {
        KiTraceSetTimer(v6, 0, 1);
      }
      else
      {
        __dmb(0xBu);
        do
          v27 = __ldrex((unsigned int *)v6);
        while ( __strex(v27 & 0xFFFFFF7F, (unsigned int *)v6) );
      }
      return KiSwapThread(a1, v11);
    }
LABEL_110:
    KiTimerWaitTest(v11, v6, 0);
    return KiSwapThread(a1, v11);
  }
  if ( (*(_BYTE *)(a1 + 72) & 7) == 0 )
  {
    if ( (*(_BYTE *)(a1 + 72) & 0x20) != 0 )
    {
      v42 = 256;
    }
    else
    {
      v10 = 1;
      if ( (*(_BYTE *)(a1 + 72) & 0x40) != 0 )
        v42 = 192;
      else
        v42 = 257;
    }
    *(_DWORD *)(a1 + 136) = v42;
  }
  *(_BYTE *)(a1 + 132) = 2;
  if ( *(_BYTE *)(a1 + 395) == 15 )
  {
    v43 = *(_BYTE **)(a1 + 152);
    if ( v43 )
    {
      if ( (*v43 & 0x7F) == 21 )
      {
        v44 = *(unsigned __int8 *)(a1 + 332);
        *(_DWORD *)(a1 + 332) = v44;
        __dmb(0xBu);
        v45 = (unsigned int *)&v43[4 * v44 + 272];
        do
          v46 = __ldrex(v45);
        while ( __strex(v46 + 1, v45) );
      }
      else
      {
        __dmb(0xBu);
        v47 = (unsigned int *)(v43 + 24);
        do
          v48 = __ldrex(v47);
        while ( __strex(v48 + 1, v47) );
      }
      __dmb(0xBu);
    }
  }
  __dmb(0xBu);
  *v14 = 0;
  if ( a3 )
    *(_DWORD *)(a1 + 76) &= 0xFFFFFDFF;
  v21 = *(_DWORD *)(a1 + 136);
  if ( v10 )
  {
    v50 = *(char *)(a1 + 135);
    while ( 1 )
    {
      do
        v51 = __ldrex(v14);
      while ( __strex(1u, v14) );
      __dmb(0xBu);
      if ( !v51 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v14 );
    }
    if ( v21 == 257 )
    {
      if ( (*(_DWORD *)(a1 + 76) & 0x10) != 0 )
      {
        if ( *(_BYTE *)(v50 + a1 + 74) )
        {
          *(_BYTE *)(v50 + a1 + 74) = 0;
        }
        else if ( v50 )
        {
          *(_BYTE *)(a1 + 74) = 0;
        }
      }
      else
      {
        __dmb(0xBu);
        v52 = (unsigned __int8 *)(a1 + 80);
        do
          v53 = __ldrex(v52);
        while ( __strex(v53 & 0xF7, v52) );
        __dmb(0xBu);
      }
    }
    else if ( *(_DWORD *)(a1 + 108) != a1 + 108 )
    {
      *(_BYTE *)(a1 + 122) = 1;
    }
    __dmb(0xBu);
    *v14 = 0;
  }
  v36 = v8 + 24 * *(unsigned __int8 *)(a1 + 363);
  do
  {
    if ( *(unsigned __int8 *)(v8 + 9) < 5u )
    {
      v37 = *(unsigned __int8 **)(v8 + 16);
      do
        v38 = __ldrex(v37);
      while ( __strex(v38 | 0x80, v37) );
      __dmb(0xBu);
      if ( v38 >> 7 )
      {
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( (*(_DWORD *)v37 & 0x80) != 0 );
          do
            v49 = __ldrex(v37);
          while ( __strex(v49 | 0x80, v37) );
          __dmb(0xBu);
        }
        while ( v49 >> 7 );
      }
      if ( *(_BYTE *)(v8 + 9) == 4 )
      {
        *(_QWORD *)&v39 = *(_QWORD *)v8;
        if ( *(_DWORD *)(*(_DWORD *)v8 + 4) != v8 || *v40 != v8 )
          __fastfail(3u);
        *v40 = v39;
        *(_DWORD *)(v39 + 4) = v40;
      }
      __dmb(0xBu);
      do
        v41 = __ldrex((unsigned int *)v37);
      while ( __strex(v41 & 0xFFFFFF7F, (unsigned int *)v37) );
    }
    v8 += 24;
  }
  while ( v8 != v36 );
  if ( *(_DWORD *)(v11 + 1540) )
    KiProcessThreadWaitList(v11, 1, 0);
  KiExitThreadWait(v11, a1, 1);
  return v21;
}
