// KiResumeThread 
 
unsigned int __fastcall KiResumeThread(unsigned int result, int a2, int a3)
{
  int v3; // r6
  int v4; // r10
  int v5; // r5
  unsigned int *v6; // r8
  unsigned int v7; // r4
  int *v8; // r7
  int *v9; // r5
  unsigned int v10; // r1
  int *v11; // r4
  int v12; // r3
  int v13; // r2
  unsigned int v14; // lr
  unsigned int v15; // r7
  __int16 v16; // r9
  int v17; // r4
  int v18; // r0
  unsigned int v19; // r2
  int *v20; // r1
  unsigned int v21; // r1
  unsigned int v22; // r2
  int v23; // r2
  bool v24; // zf
  unsigned int *v25; // r4
  unsigned int v26; // r1
  int v27; // r6
  unsigned int v28; // r10
  int v29; // r8
  BOOL v30; // r2
  unsigned int v31; // r2
  _DWORD *v32; // r1
  unsigned int v33; // r1
  int v34; // [sp+8h] [bp-28h]

  v3 = a3;
  *(_DWORD *)(result + 456) = 1;
  v4 = a2;
  v5 = result;
  v6 = (unsigned int *)(result + 44);
  while ( 1 )
  {
    do
      v7 = __ldrex(v6);
    while ( __strex(1u, v6) );
    __dmb(0xBu);
    if ( !v7 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v6 );
  }
  if ( *(_BYTE *)(result + 132) != 5 )
    goto LABEL_5;
  v10 = *(unsigned __int8 *)(result + 72);
  if ( (v10 & 7) != 4 )
    goto LABEL_5;
  if ( a3 )
  {
LABEL_15:
    *(_BYTE *)(v5 + 72) = v10 & 0xF8 | 1;
LABEL_5:
    if ( v3 )
    {
      result = KiIsTerminationRequested(v5);
      if ( result )
      {
        if ( *(_BYTE *)(v5 + 132) == 5 )
          result = KiSignalThread(v4, v5, 256, 0);
      }
      else
      {
        result = KiSignalThreadForApc(v4, v5 + 400, 2);
      }
    }
    __dmb(0xBu);
    *v6 = 0;
    v8 = *(int **)(v5 + 460);
    v9 = (int *)(v5 + 460);
    while ( 1 )
    {
      if ( v8 == v9 )
      {
        v9[1] = (int)v9;
        *v9 = (int)v9;
        return result;
      }
      v11 = v8;
      v12 = *((unsigned __int8 *)v8 + 8);
      v8 = (int *)*v8;
      if ( v12 == 1 )
        break;
      if ( v12 == 2 )
      {
        *((_BYTE *)v11 + 9) = 5;
        v27 = v11[3];
        *v11 = 0;
        result = KfRaiseIrql(2);
        v28 = (unsigned int)KeGetPcr() & 0xFFFFF000;
        v29 = *(_DWORD *)(v28 + 1412);
        if ( (dword_682604 & 0x1000000) != 0 )
        {
          v30 = *(_BYTE *)(v29 + 132) == 2
             && *(_DWORD *)(v29 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
          result = EtwTraceEnqueueWork(*(_DWORD *)(v28 + 1412), v11, v30);
        }
        do
          v31 = __ldrex((unsigned __int8 *)v27);
        while ( __strex(v31 | 0x80, (unsigned __int8 *)v27) );
        while ( 1 )
        {
          __dmb(0xBu);
          if ( !(v31 >> 7) )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( (*(_DWORD *)v27 & 0x80) != 0 );
          do
            v31 = __ldrex((unsigned __int8 *)v27);
          while ( __strex(v31 | 0x80, (unsigned __int8 *)v27) );
        }
        if ( *(_DWORD *)(v27 + 12) == v27 + 8
          || *(_DWORD *)(v27 + 24) >= *(_DWORD *)(v27 + 28)
          || *(_DWORD *)(v29 + 152) == v27 && *(_BYTE *)(v29 + 395) == 15
          || (result = KiWakeQueueWaiter(v28 + 1408, v27, v11)) == 0 )
        {
          ++*(_DWORD *)(v27 + 4);
          v32 = *(_DWORD **)(v27 + 20);
          *v11 = v27 + 16;
          v11[1] = (int)v32;
          if ( *v32 != v27 + 16 )
            __fastfail(3u);
          *v32 = v11;
          *(_DWORD *)(v27 + 20) = v11;
        }
        __dmb(0xBu);
        do
          v33 = __ldrex((unsigned int *)v27);
        while ( __strex(v33 & 0xFFFFFF7F, (unsigned int *)v27) );
        v4 = a2;
      }
      else
      {
        v13 = 256;
LABEL_18:
        result = KiTryUnwaitThread(v4, v11, v13, 0);
      }
    }
    v13 = *((unsigned __int16 *)v11 + 5);
    goto LABEL_18;
  }
  *(_BYTE *)(result + 72) = v10 & 0xF8 | 5;
  __dmb(0xBu);
  *v6 = 0;
  v14 = *(unsigned __int8 *)(result + 363);
  v15 = 0;
  v16 = 0;
  if ( !*(_BYTE *)(result + 363) )
    goto LABEL_35;
  v10 = 4;
  while ( 1 )
  {
    v17 = *(_DWORD *)(v5 + 140) + 24 * v15;
    if ( *(_BYTE *)(v17 + 9) == 6 )
      break;
LABEL_34:
    v15 = (unsigned __int8)(v15 + 1);
    if ( v15 >= v14 )
      goto LABEL_35;
  }
  *(_BYTE *)(v17 + 9) = 4;
  v18 = *(_DWORD *)(v17 + 16);
  do
    v19 = __ldrex((unsigned __int8 *)v18);
  while ( __strex(v19 | 0x80, (unsigned __int8 *)v18) );
  __dmb(0xBu);
  if ( !(v19 >> 7) )
  {
    if ( *(int *)(v18 + 4) <= 0 && (*(_BYTE *)v18 & 0x7F) != 2 )
    {
      v20 = *(int **)(v18 + 12);
      *(_DWORD *)v17 = v18 + 8;
      *(_DWORD *)(v17 + 4) = v20;
      if ( *v20 != v18 + 8 )
        __fastfail(3u);
      *v20 = v17;
      *(_DWORD *)(v18 + 12) = v17;
      __dmb(0xBu);
      do
        v21 = __ldrex((unsigned int *)v18);
      while ( __strex(v21 & 0xFFFFFF7F, (unsigned int *)v18) );
      v10 = 4;
      goto LABEL_34;
    }
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)v18);
    while ( __strex(v10 & 0xFFFFFF7F, (unsigned int *)v18) );
    *(_BYTE *)(v17 + 9) = 5;
    v3 = 1;
LABEL_35:
    if ( (*(_DWORD *)(v5 + 76) & 0x20000) != 0 && !v3 )
    {
      *(_DWORD *)(v5 + 168) |= 0x40000080u;
      v25 = (unsigned int *)(v5 + 168);
      if ( KiComputeDueTime(v5 + 168, v10, *(_DWORD *)(v5 + 184), *(_DWORD *)(v5 + 188), 0) )
      {
        v16 = 1;
        if ( KiInsertTimerTable(v4, v5 + 168, 0, v34) )
        {
          if ( (dword_682608 & 0x20000) != 0 )
          {
            KiTraceSetTimer(v5 + 168, 0, 1);
          }
          else
          {
            __dmb(0xBu);
            do
              v26 = __ldrex(v25);
            while ( __strex(v26 & 0xFFFFFF7F, v25) );
          }
        }
        else
        {
          KiTimerWaitTest(v4, v5 + 168, 0);
        }
      }
      else
      {
        v3 = 1;
      }
    }
    while ( 1 )
    {
      do
        v22 = __ldrex(v6);
      while ( __strex(1u, v6) );
      __dmb(0xBu);
      if ( !v22 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v6 );
    }
    LOBYTE(v10) = *(_BYTE *)(v5 + 72);
    result = (*(_DWORD *)(v5 + 76) ^ ((unsigned __int16)*(_DWORD *)(v5 + 76) ^ (unsigned __int16)(v16 << 9)) & 0x200) & 0xFFFDFFFF;
    *(_DWORD *)(v5 + 76) = result;
    if ( (v10 & 0xE7) == 5 )
    {
      v23 = *(char *)(v5 + 135);
      if ( ((result >> 4) & 1) == 0 )
      {
        v24 = (unsigned __int8)(*(_BYTE *)(v5 + 122) & v23) == 0;
LABEL_44:
        if ( v24 )
        {
          if ( *(_BYTE *)(v5 + 395) == 37 && (*(_DWORD *)(v5 + 80) & 8) != 0 )
            v3 = 1;
          goto LABEL_15;
        }
        goto LABEL_67;
      }
      if ( !*(_BYTE *)(v23 + v5 + 74) && (!*(_BYTE *)(v5 + 135) || *(_DWORD *)(v5 + 108) == v5 + 108) )
      {
        v24 = *(_BYTE *)(v5 + 74) == 0;
        goto LABEL_44;
      }
    }
LABEL_67:
    v3 = 1;
    goto LABEL_15;
  }
  return sub_52B1B0();
}
