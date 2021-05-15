// KiWakeQueueWaiter 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiWakeQueueWaiter(int a1, int a2, int a3)
{
  __int64 *v3; // r7
  __int64 *v7; // r6
  __int64 v8; // kr00_8
  int v9; // r0
  int v10; // r1
  unsigned int *v11; // lr
  unsigned int v12; // r2
  _BYTE *v14; // r2
  unsigned int *v15; // r2
  unsigned int v16; // r1
  int v17; // r3
  unsigned int *v18; // r5
  unsigned int v19; // r2
  int v20; // r1 OVERLAPPED
  _DWORD *v21; // r2 OVERLAPPED
  int v22; // r3
  unsigned int *v23; // r2
  unsigned int v24; // r1

  v3 = *(__int64 **)(a2 + 12);
  do
  {
    v7 = v3;
    v8 = *v3;
    v3 = (__int64 *)*((_DWORD *)v3 + 1);
    if ( *(__int64 **)(v8 + 4) != v7 || *(__int64 **)HIDWORD(v8) != v7 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v8) = v8;
    *(_DWORD *)(v8 + 4) = HIDWORD(v8);
    if ( *((_BYTE *)v7 + 8) == 1 )
    {
      v9 = *((_DWORD *)v7 + 3);
      v10 = 0;
      v11 = (unsigned int *)(v9 + 44);
      while ( 1 )
      {
        do
          v12 = __ldrex(v11);
        while ( __strex(1u, v11) );
        __dmb(0xBu);
        if ( !v12 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v11 );
      }
      if ( *(_BYTE *)(v9 + 132) == 5 )
      {
        if ( (*(_BYTE *)(v9 + 72) & 7) != 1 )
          return sub_50C228();
        v14 = *(_BYTE **)(v9 + 152);
        if ( v14 )
        {
          if ( (*v14 & 0x7F) == 21 )
          {
            v22 = *(unsigned __int8 *)(v9 + 332);
            *(_DWORD *)(v9 + 332) = v22;
            __dmb(0xBu);
            v23 = (unsigned int *)&v14[4 * v22 + 272];
            do
              v24 = __ldrex(v23);
            while ( __strex(v24 + 1, v23) );
          }
          else
          {
            __dmb(0xBu);
            v15 = (unsigned int *)(v14 + 24);
            do
              v16 = __ldrex(v15);
            while ( __strex(v16 + 1, v15) );
          }
          __dmb(0xBu);
        }
        v17 = *(_DWORD *)(v9 + 436);
        if ( v17 )
        {
          v18 = (unsigned int *)(v17 + 1928);
          while ( 1 )
          {
            do
              v19 = __ldrex(v18);
            while ( __strex(1u, v18) );
            __dmb(0xBu);
            if ( !v19 )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( *v18 );
          }
          if ( *(_DWORD *)(v9 + 436) )
          {
            *(_QWORD *)&v20 = *(_QWORD *)(v9 + 144);
            if ( *(_DWORD *)(v20 + 4) != v9 + 144 || *v21 != v9 + 144 )
              __fastfail(3u);
            *v21 = v20;
            *(_DWORD *)(v20 + 4) = v21;
            *(_DWORD *)(v9 + 436) = 0;
          }
          __dmb(0xBu);
          *v18 = 0;
        }
        *(_BYTE *)(v9 + 132) = 7;
        v10 = 1;
        *(_DWORD *)(v9 + 144) = *(_DWORD *)(a1 + 1540);
        *(_DWORD *)(a1 + 1540) = v9 + 144;
        *(_DWORD *)(v9 + 136) = a3;
      }
      __dmb(0xBu);
      *v11 = 0;
      ++*((_BYTE *)v7 + 9);
      if ( v10 )
        return 1;
    }
    else
    {
      *((_BYTE *)v7 + 9) = 5;
      KiInsertQueueInternal(*((_DWORD *)v7 + 3), v7);
    }
  }
  while ( v3 != (__int64 *)(a2 + 8) );
  return 0;
}
