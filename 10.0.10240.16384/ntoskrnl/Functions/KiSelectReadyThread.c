// KiSelectReadyThread 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiSelectReadyThread(signed int a1, int a2)
{
  unsigned int v2; // r7
  unsigned int *v3; // r6
  int v5; // r1
  unsigned int v7; // r9
  int result; // r0
  signed int v9; // r1
  unsigned int v10; // r3
  signed int v11; // r3
  unsigned int v12; // r2
  unsigned int v13; // r1
  unsigned int v14; // r3
  int v15; // r2
  unsigned int v16; // r3
  unsigned int *v17; // r8
  int v18; // lr
  unsigned int **v19; // r1 OVERLAPPED
  unsigned int **v20; // r2 OVERLAPPED
  int v21; // r2
  int v22; // lr
  int v23; // r1
  int v24; // r2
  __int64 *v25; // r8
  __int64 v26; // kr00_8
  int v27; // [sp+0h] [bp-28h]
  int v28; // [sp+4h] [bp-24h]
  int v29; // [sp+8h] [bp-20h]

  v2 = 1 << a1;
  v3 = *(unsigned int **)(a2 + 3460);
  v5 = *(_DWORD *)(*(_DWORD *)(a2 + 2360) + 136);
  v29 = v5;
  if ( (*(_BYTE *)(a2 + 19) & 2) != 0 && (*(_DWORD *)(a2 + 3456) & v5) != 0 )
    v3 = 0;
  while ( 1 )
  {
    v7 = *(_DWORD *)(a2 + 1932);
    result = 0;
    v27 = -2;
    v28 = -1;
    v9 = -1;
    if ( v7 >= v2 )
    {
      v9 = 31 - __clz(v7);
      v7 = 1 << v9;
      v28 = v9;
    }
    if ( v3 )
    {
      v10 = v3[1];
      if ( v10 >= v2 )
      {
        v11 = 31 - __clz(v10);
        v27 = v11;
      }
      else
      {
        v11 = -2;
      }
      v9 = v28;
      if ( v11 > v28 || v11 == v28 && ((*(unsigned __int8 *)(a2 + (v28 >> 3) + 1936) >> (v28 & 7)) & 1) == 0 )
      {
        while ( 1 )
        {
          do
            v12 = __ldrex(v3);
          while ( __strex(1u, v3) );
          __dmb(0xBu);
          if ( !v12 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v3 );
        }
        v13 = v3[1];
LABEL_15:
        if ( v13 >= v2 && v13 >= v7 )
        {
          v14 = __clz(v13);
          v15 = 31 - v14;
          v16 = 32 - v14;
          v27 = v15;
          v17 = (unsigned int *)v3[2 * v16];
          v13 ^= 1 << v15;
          while ( 1 )
          {
            result = (int)(v17 - 36);
            if ( *((unsigned __int8 *)v17 - 59) >= 5u )
              return sub_52F7FC();
            v18 = -1;
            if ( *((_BYTE *)v17 - 59) )
              v18 = *(_DWORD *)(*(_DWORD *)(a2 + 2360) + 8 * *((unsigned __int8 *)v17 - 59) + 296);
            if ( (*(_DWORD *)(a2 + 1048) & v18) != 0 || (*(_DWORD *)(a2 + 3456) & v18 & v29) == 0 )
              break;
            v17 = (unsigned int *)*v17;
            result = 0;
            if ( v17 == &v3[2 * v16] )
              goto LABEL_15;
          }
          *(_QWORD *)&v19 = *(_QWORD *)v17;
          if ( *(unsigned int **)(*v17 + 4) != v17 || *v20 != v17 )
            __fastfail(3u);
          *v20 = (unsigned int *)v19;
          v19[1] = (unsigned int *)v20;
          if ( v20 == v19 )
            v3[1] ^= 1 << v27;
          v17[46] = *(_DWORD *)(a2 + 20);
        }
        __dmb(0xBu);
        *v3 = 0;
        if ( result )
        {
          if ( v27 == v28 )
            *(_BYTE *)(a2 + (v28 >> 3) + 1936) |= 1 << (v28 & 7);
          goto LABEL_31;
        }
        v9 = v28;
      }
    }
    if ( v9 >= a1 )
    {
      v25 = *(__int64 **)(a2 + 8 * v9 + 2048);
      v26 = *v25;
      result = (int)(v25 - 18);
      if ( *(__int64 **)(*(_DWORD *)v25 + 4) != v25 || *(__int64 **)HIDWORD(v26) != v25 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v26) = v26;
      *(_DWORD *)(v26 + 4) = HIDWORD(v26);
      if ( HIDWORD(v26) == (_DWORD)v26 )
        *(_DWORD *)(a2 + 1932) ^= 1 << v9;
      if ( v28 == v27 )
        *(_BYTE *)(a2 + (v28 >> 3) + 1936) &= ~(1 << (v28 & 7));
    }
    if ( !result )
      return result;
LABEL_31:
    v21 = *(_DWORD *)(result + 68);
    if ( !v21 )
      return result;
    v22 = v21 + *(_DWORD *)(a2 + 2352);
    if ( !v22 )
      return result;
    v23 = v21 + *(_DWORD *)(a2 + 2352);
    if ( *(char *)(result + 123) >= 16
      || (*(_DWORD *)(result + 80) & 0x100) != 0
      || *(_DWORD *)(result + 308)
      || *(_BYTE *)(result + 134) == 1 )
    {
      return result;
    }
    v24 = v21 + *(_DWORD *)(a2 + 2352);
    while ( (*(_BYTE *)(v24 + 92) & 2) == 0 )
    {
      v24 = *(_DWORD *)(v24 + 236);
      if ( !v24 )
      {
        while ( !*(_DWORD *)(v23 + 96) )
        {
          v23 = *(_DWORD *)(v23 + 236);
          if ( !v23 )
            return result;
        }
        break;
      }
    }
    KiAddThreadToScbQueue(a2, v22, result, 0);
  }
}
