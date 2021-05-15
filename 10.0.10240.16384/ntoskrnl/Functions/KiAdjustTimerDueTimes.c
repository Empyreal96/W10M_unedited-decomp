// KiAdjustTimerDueTimes 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiAdjustTimerDueTimes(int result, int a2, int a3)
{
  unsigned int v4; // r7
  int v5; // r10
  unsigned int v6; // lr
  unsigned int *v7; // r5
  _DWORD **v8; // r9
  unsigned int v9; // r4
  _DWORD *v10; // r6
  int *i; // r2
  char v12; // r1
  int *v13; // r4
  int **v14; // r1 OVERLAPPED
  int **v15; // r2 OVERLAPPED
  int v16; // r1
  int v17; // r2
  int v18; // r1
  unsigned __int8 *v19; // r3
  unsigned int v20; // r2
  int **v21; // r1
  unsigned int v22; // r4
  __int64 v23; // r0
  unsigned __int64 v24; // kr00_8
  unsigned int v25; // r0
  int v26; // r5
  int v27; // r3
  int v28; // r1
  int v29; // r7
  unsigned int v30; // r6
  char *v31; // r2
  unsigned int v32; // r1
  char v33; // [sp+8h] [bp-40h] BYREF
  int v34; // [sp+Ch] [bp-3Ch]
  int *v35; // [sp+10h] [bp-38h] BYREF
  int **v36; // [sp+14h] [bp-34h]
  int v37; // [sp+18h] [bp-30h]

  v36 = &v35;
  v4 = 0;
  v34 = a2;
  v35 = (int *)&v35;
  v5 = result;
  v6 = 0;
  v7 = (unsigned int *)(a2 + 256);
  do
  {
    v8 = (_DWORD **)(v7 + 1);
    do
      v9 = __ldrex(v7);
    while ( __strex(1u, v7) );
    __dmb(0xBu);
    if ( v9 )
      return sub_519870(result);
    v10 = *v8;
    while ( v10 != v8 )
    {
      result = (int)(v10 - 6);
      v12 = *((_BYTE *)v10 - 23);
      v10 = (_DWORD *)*v10;
      if ( (v12 & 1) != *(_BYTE *)a3 && (!*(_BYTE *)a3 || (v12 & 2) == 0) )
      {
        v13 = (int *)(result + 24);
        *(_QWORD *)&v14 = *(_QWORD *)(result + 24);
        if ( v14[1] != (int *)(result + 24) || *v15 != v13 )
          __fastfail(3u);
        *v15 = (int *)v14;
        v14[1] = (int *)v15;
        if ( v15 == v14 )
        {
          v7[5] = -1;
          v16 = KiPendingTimerBitmaps[2 * *(unsigned __int8 *)(v34 - 3044) + 1];
          if ( KiSerializeTimerExpiration )
          {
            v18 = v16 + 4 * (v6 >> 5);
            v17 = v6 & 0x1F;
          }
          else
          {
            v17 = *(unsigned __int8 *)(v34 - 3043);
            v18 = v16 + v4;
          }
          __dmb(0xBu);
          result = 1 << (v17 & 7);
          v19 = (unsigned __int8 *)(v18 + (v17 >> 3));
          do
            v20 = __ldrex(v19);
          while ( __strex(v20 & ~(_BYTE)result, v19) );
          __dmb(0xBu);
        }
        v21 = v36;
        *v13 = (int)&v35;
        v13[1] = (int)v21;
        if ( *v21 != (int *)&v35 )
          __fastfail(3u);
        *v21 = v13;
        v36 = (int **)v13;
      }
    }
    __dmb(0xBu);
    v4 += 128;
    *v7 = 0;
    v7 += 6;
    ++v6;
  }
  while ( v4 < 0x8000 );
  for ( i = v35; v35 != (int *)&v35; i = v35 )
  {
    v22 = (unsigned int)(i - 6);
    v23 = *(_QWORD *)i;
    if ( *(int **)(*i + 4) != i || *(int **)HIDWORD(v23) != i )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v23) = v23;
    *(_DWORD *)(v23 + 4) = HIDWORD(v23);
    v24 = *((_QWORD *)i - 1);
    v26 = (v24 - *(_QWORD *)(a3 + 16)) >> 32;
    v25 = v24 - *(_DWORD *)(a3 + 16);
    if ( *(int *)(a3 + 20) >= 0 )
    {
      if ( __PAIR64__(v26, v25) > v24 )
      {
        v25 = 0;
        v26 = 0;
      }
    }
    else if ( __PAIR64__(v26, v25) < v24 )
    {
      v25 = -1;
      v26 = -1;
    }
    v27 = i[2];
    v28 = KiWaitNever;
    v29 = KiWaitAlways;
    *(i - 2) = v25;
    *(i - 1) = v26;
    v30 = bswap32(__ROR4__(v28 ^ v27, -(char)v28) ^ v22);
    *(_DWORD *)v22 |= 0x80u;
    v37 = *(_DWORD *)v22;
    BYTE2(v37) = v25 >> 18;
    *(_DWORD *)v22 = v37;
    if ( *(_BYTE *)(a3 + 24) )
      v31 = &v33;
    else
      v31 = 0;
    result = KiInsertTimerTable(v5, (_DWORD *)v22, v30 ^ v29, (unsigned __int8)(v25 >> 18), v31);
    if ( result )
    {
      if ( (dword_682608 & 0x20000) != 0 )
      {
        result = KiTraceSetTimer(v22, v30 ^ v29, 0);
      }
      else
      {
        __dmb(0xBu);
        do
          v32 = __ldrex((unsigned int *)v22);
        while ( __strex(v32 & 0xFFFFFF7F, (unsigned int *)v22) );
      }
    }
    else
    {
      result = KiTimerWaitTest(v5, v22, 0);
    }
  }
  if ( *(_BYTE *)(v5 + 17) || *(_BYTE *)(a3 + 24) )
    result = KiAdjustTimer2DueTimes(a3);
  return result;
}
