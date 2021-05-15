// KiSuspendThread 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiSuspendThread(int a1, int a2, unsigned int a3, int a4)
{
  unsigned int *v5; // r6
  int result; // r0
  unsigned int v8; // r2
  int v9; // r5
  int v10; // r2
  int v11; // r3
  int v12; // r0
  int v13; // r7
  unsigned __int8 *v14; // r5
  unsigned int v15; // r2
  int v16; // r1 OVERLAPPED
  _DWORD *v17; // r2 OVERLAPPED
  unsigned int v18; // r1
  unsigned __int8 *v19; // r2
  unsigned int v20; // r1
  unsigned int v21; // r2
  char v22; // r3
  __int64 v23; // r0
  unsigned int v24; // r5
  unsigned int v25; // r7
  unsigned __int64 v26; // kr00_8
  int v27; // r2
  int v28; // r3
  unsigned __int64 v29; // [sp+0h] [bp-28h] BYREF
  int v30; // [sp+8h] [bp-20h]

  v29 = __PAIR64__(a3, a2);
  v30 = a4;
  v5 = (unsigned int *)(a1 + 44);
  result = 0;
  while ( 1 )
  {
    do
      v8 = __ldrex(v5);
    while ( __strex(1u, v5) );
    __dmb(0xBu);
    if ( !v8 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v5 );
  }
  if ( (*(_DWORD *)(a1 + 76) & 0x4000) != 0 )
  {
    if ( *(_DWORD *)(a1 + 456) )
    {
      *(_DWORD *)(a1 + 456) = 0;
      v9 = 0;
      if ( !*(_BYTE *)(a1 + 446) )
      {
        v9 = 1;
        *(_BYTE *)(a1 + 446) = 1;
        KiInsertQueueApc(a1 + 400);
      }
      if ( KiDisableLightWeightSuspend
        || *(_BYTE *)(a1 + 132) != 5
        || (*(_BYTE *)(a1 + 72) & 7) != 1
        || *(_DWORD *)(a1 + 308)
        || *(_BYTE *)(a1 + 134)
        || *(_BYTE *)(a1 + 120)
        || *(_BYTE *)(a1 + 362)
        || *(_BYTE *)(*(_DWORD *)(a1 + 140) + 9) != 5 && *(_BYTE *)(*(_DWORD *)(a1 + 140) + 8) != 1 )
      {
        if ( v9 )
          KiSignalThreadForApc(a2, a1 + 400, 2);
      }
      else
      {
        v10 = *(unsigned __int8 *)(a1 + 135);
        *(_BYTE *)(a1 + 72) = 3;
        v11 = *(_DWORD *)(a1 + 76);
        *(_BYTE *)(a1 + 121) = 1;
        *(_DWORD *)(a1 + 76) ^= (v11 ^ (v10 << 18)) & 0x40000;
        __dmb(0xBu);
        *v5 = 0;
        v12 = *(_DWORD *)(a1 + 140);
        v13 = v12 + 24 * *(unsigned __int8 *)(a1 + 363);
        do
        {
          if ( *(unsigned __int8 *)(v12 + 9) < 5u )
          {
            v14 = *(unsigned __int8 **)(v12 + 16);
            do
              v15 = __ldrex(v14);
            while ( __strex(v15 | 0x80, v14) );
            __dmb(0xBu);
            if ( v15 >> 7 )
              return sub_52177C();
            if ( *(_BYTE *)(v12 + 9) == 4 )
            {
              *(_QWORD *)&v16 = *(_QWORD *)v12;
              if ( *(_DWORD *)(*(_DWORD *)v12 + 4) != v12 || *v17 != v12 )
                __fastfail(3u);
              *v17 = v16;
              *(_DWORD *)(v16 + 4) = v17;
            }
            __dmb(0xBu);
            do
              v18 = __ldrex((unsigned int *)v14);
            while ( __strex(v18 & 0xFFFFFF7F, (unsigned int *)v14) );
            *(_BYTE *)(v12 + 9) = 6;
          }
          v12 += 24;
        }
        while ( v12 != v13 );
        if ( (*(_DWORD *)(a1 + 76) & 0x200) != 0 )
        {
          v23 = KeQueryInterruptTime(v12);
          v24 = HIDWORD(v23);
          v25 = v23;
          if ( (unsigned int)KiCancelTimer(a1 + 168, 1) )
          {
            v26 = *(_QWORD *)(a1 + 184);
            if ( v26 <= __PAIR64__(v24, v25) )
            {
              *(_DWORD *)(a1 + 184) = 0;
              *(_DWORD *)(a1 + 188) = 0;
            }
            else
            {
              if ( (*(_BYTE *)(a1 + 169) & 1) != 0 )
              {
                KeQuerySystemTime(&v29);
                v27 = (v29 + *(_QWORD *)(a1 + 184) - __PAIR64__(v24, v25)) >> 32;
                v28 = v29 + *(_DWORD *)(a1 + 184) - v25;
              }
              else
              {
                v27 = (__PAIR64__(v24, v25) - v26) >> 32;
                v28 = v25 - v26;
              }
              *(_DWORD *)(a1 + 184) = v28;
              *(_DWORD *)(a1 + 188) = v27;
            }
          }
          else
          {
            *(_DWORD *)(a1 + 184) = 0;
            *(_DWORD *)(a1 + 188) = 0;
            *(_BYTE *)(a1 + 297) = 4;
            *(_DWORD *)(a1 + 176) = a1 + 288;
            *(_DWORD *)(a1 + 180) = a1 + 288;
          }
        }
        v19 = (unsigned __int8 *)(a1 + 82);
        do
          v20 = __ldrex(v19);
        while ( __strex(v20 | 4, v19) );
        if ( !((unsigned __int8)(v20 & 4) >> 2) )
          KiDecrementProcessStackCount(*(_DWORD *)(a1 + 116));
        while ( 1 )
        {
          do
            v21 = __ldrex(v5);
          while ( __strex(1u, v5) );
          __dmb(0xBu);
          if ( !v21 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v5 );
        }
        *(_DWORD *)(a1 + 76) = *(_DWORD *)(a1 + 76) & 0xFFFDFDFF | ((*(_DWORD *)(a1 + 76) & 0x200) << 8);
        v22 = *(_BYTE *)(a1 + 72) & 0xF8 | 4;
        *(_BYTE *)(a1 + 72) = v22;
        if ( (v22 & 0x20) != 0 )
          KiSignalThread(a2, a1, 256, 0);
      }
    }
    result = 1;
  }
  __dmb(0xBu);
  *v5 = 0;
  return result;
}
