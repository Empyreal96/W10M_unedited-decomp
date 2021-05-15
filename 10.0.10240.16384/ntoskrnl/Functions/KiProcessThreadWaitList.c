// KiProcessThreadWaitList 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiProcessThreadWaitList(int a1, char a2, char a3)
{
  int **v3; // r7
  int *v7; // r5
  int v8; // r2
  int v9; // r4
  int v10; // r6
  int result; // r0
  int v12; // r3
  unsigned __int8 *v13; // r0
  unsigned int v14; // r2
  int v15; // r1 OVERLAPPED
  _DWORD *v16; // r2 OVERLAPPED
  unsigned int v17; // r1
  int v18; // r4
  unsigned int v19; // r2
  unsigned int *v20; // r0
  unsigned int v21; // r1
  unsigned int v22; // r0
  unsigned __int8 *v23; // r2
  unsigned int v24; // r1
  int *v25; // r4
  int v26; // r1
  unsigned int v27; // r2
  unsigned __int8 *v28; // r3
  unsigned int v29; // r2
  int v30; // r3
  unsigned int *v31; // r0
  unsigned int v32; // r3
  int v33; // r0
  unsigned int v34; // r2
  int v35; // r1
  unsigned int v36; // r2
  unsigned int v37; // r2
  unsigned int v38; // r2
  unsigned int v39; // r1

  v3 = *(int ***)(a1 + 1540);
  *(_DWORD *)(a1 + 1540) = 0;
  while ( 1 )
  {
    v7 = (int *)(v3 - 36);
    v8 = *((unsigned __int8 *)v3 + 219);
    v9 = (int)*(v3 - 1);
    v3 = (int **)*v3;
    v10 = v9 + 24 * v8;
    do
    {
      if ( *(unsigned __int8 *)(v9 + 9) < 5u )
      {
        v13 = *(unsigned __int8 **)(v9 + 16);
        do
          v14 = __ldrex(v13);
        while ( __strex(v14 | 0x80, v13) );
        __dmb(0xBu);
        if ( v14 >> 7 )
        {
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( (*(_DWORD *)v13 & 0x80) != 0 );
            do
              v36 = __ldrex(v13);
            while ( __strex(v36 | 0x80, v13) );
            __dmb(0xBu);
          }
          while ( v36 >> 7 );
        }
        if ( *(_BYTE *)(v9 + 9) == 4 )
        {
          *(_QWORD *)&v15 = *(_QWORD *)v9;
          if ( *(_DWORD *)(*(_DWORD *)v9 + 4) != v9 || *v16 != v9 )
            __fastfail(3u);
          *v16 = v15;
          *(_DWORD *)(v15 + 4) = v16;
        }
        __dmb(0xBu);
        do
          v17 = __ldrex((unsigned int *)v13);
        while ( __strex(v17 & 0xFFFFFF7F, (unsigned int *)v13) );
      }
      v9 += 24;
    }
    while ( v9 != v10 );
    *((_BYTE *)v7 + 350) = a2;
    *((_BYTE *)v7 + 351) = a3;
    if ( (dword_682604 & 0x200) != 0 )
      return sub_50C940();
    v12 = v7[20];
    if ( (v12 & 0x10000) == 0 )
    {
      v18 = v7[29];
      do
        v19 = __ldrex((unsigned __int8 *)v18);
      while ( __strex(v19 | 0x80, (unsigned __int8 *)v18) );
      __dmb(0xBu);
      if ( v19 >> 7 )
      {
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( (*(_DWORD *)v18 & 0x80) != 0 );
          do
            v38 = __ldrex((unsigned __int8 *)v18);
          while ( __strex(v38 | 0x80, (unsigned __int8 *)v18) );
          __dmb(0xBu);
        }
        while ( v38 >> 7 );
      }
      v20 = (unsigned int *)(v18 + 116);
      if ( (*(_DWORD *)(v18 + 116) & 7) == 0 )
      {
        __dmb(0xBu);
        do
          v21 = __ldrex(v20);
        while ( __strex(v21 + 8, v20) );
        __dmb(0xBu);
        do
          v22 = __ldrex((unsigned int *)v18);
        while ( __strex(v22 & 0xFFFFFF7F, (unsigned int *)v18) );
        v23 = (unsigned __int8 *)v7 + 82;
        do
          v24 = __ldrex(v23);
        while ( __strex(v24 & 0xFB, v23) );
        *((_BYTE *)v7 + 132) = 6;
        __pld(&KiStackInSwapListHead);
        v25 = v7 + 36;
        result = KiStackInSwapListHead;
        do
        {
          *v25 = result;
          v26 = result;
          __dmb(0xBu);
          do
            v27 = __ldrex((unsigned int *)&KiStackInSwapListHead);
          while ( v27 == result && __strex((unsigned int)v25, (unsigned int *)&KiStackInSwapListHead) );
          result = v27;
        }
        while ( v27 != v26 );
        if ( !v27 )
          result = KeSetEvent((int)&KiSwapEvent, 10, 0);
        goto LABEL_10;
      }
      v35 = v18;
      goto LABEL_49;
    }
    if ( (v12 & 0x40000) != 0 )
    {
      v28 = (unsigned __int8 *)v7 + 82;
      do
        v29 = __ldrex(v28);
      while ( __strex(v29 & 0xFB, v28) );
      v30 = v7[29];
      __dmb(0xBu);
      v31 = (unsigned int *)(v30 + 116);
      do
        v32 = __ldrex(v31);
      while ( __strex(v32 + 8, v31) );
      __dmb(0xBu);
      if ( (v32 & 7) != 0 )
      {
        v33 = v7[29];
        do
          v34 = __ldrex((unsigned __int8 *)v33);
        while ( __strex(v34 | 0x80, (unsigned __int8 *)v33) );
        __dmb(0xBu);
        if ( v34 >> 7 )
        {
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( (*(_DWORD *)v33 & 0x80) != 0 );
            do
              v37 = __ldrex((unsigned __int8 *)v33);
            while ( __strex(v37 | 0x80, (unsigned __int8 *)v33) );
            __dmb(0xBu);
          }
          while ( v37 >> 7 );
        }
        if ( (*(_DWORD *)(v33 + 116) & 7) != 0 )
        {
          v35 = v33;
LABEL_49:
          result = KiRequestProcessInSwap(v7, v35);
          goto LABEL_10;
        }
        __dmb(0xBu);
        do
          v39 = __ldrex((unsigned int *)v33);
        while ( __strex(v39 & 0xFFFFFF7F, (unsigned int *)v33) );
      }
    }
    result = KiDeferredReadyThread(a1, v7);
LABEL_10:
    if ( !v3 )
      return result;
  }
}
