// MiVerifyImageHeader 
 
int __fastcall MiVerifyImageHeader(int a1, int a2, int a3, unsigned int a4)
{
  int v8; // r1
  __int64 v9; // kr00_8
  int v10; // lr
  unsigned int v11; // r2
  __int64 v12; // kr08_8
  __int64 v13; // kr10_8
  int v14; // r3
  int v15; // r3
  __int64 v16; // kr18_8
  int v17; // r3
  int v18; // r1
  int v19; // r6
  int v20; // r7
  int v21; // r2
  int v22; // r2
  int v23; // r0
  int v24; // r6
  unsigned int v25; // r3
  unsigned int v26; // r2
  unsigned int v27; // r3

  if ( (a2 & 3) != 0 )
    return sub_7D4B94();
  if ( *(_DWORD *)a2 != 17744 )
  {
    if ( (unsigned __int16)*(_DWORD *)a2 == 17742 )
    {
      if ( !MiCheckDosCalls(a2, a4) )
      {
        if ( *(_BYTE *)(a2 + 54) == 2 )
          return -1073741519;
        if ( !*(_BYTE *)(a2 + 54) )
        {
          v17 = *(_WORD *)(a2 + 62) & 0xFF00;
          if ( v17 == 512 || v17 == 768 )
            return -1073741519;
        }
      }
      v18 = *(unsigned __int8 *)(a2 + 54);
      if ( v18 == 5
        || *(unsigned __int16 *)(a2 + 4) == *(unsigned __int16 *)(a2 + 42)
        || v18 == 1 && !memcmp(a3 + 512, (unsigned int)"16STUB", 6) )
      {
        return sub_7D4B94();
      }
      v19 = *(unsigned __int16 *)(a3 + 8);
      if ( (unsigned int)(16 * v19) <= 0xFC6 )
      {
        v20 = a3 + 16 * v19;
        if ( !strcmp((const char *)(v20 + 24), "Phar Lap Software, Inc.") )
        {
          v21 = *(unsigned __int16 *)(v20 + 56);
          if ( v21 == 19280 || v21 == 20304 || v21 == 22096 )
            return sub_7D4B94();
        }
      }
      v22 = 16 * v19;
      if ( (unsigned int)(16 * v19 + 50) <= 0x1000 )
      {
        v23 = a3 + 16 * v19;
        v24 = *(unsigned __int16 *)(v23 + 48);
        if ( (unsigned int)(v22 + v24) <= 0xFDC
          && !memcmp(v23 + v24, (unsigned int)"Copyright (C) Rational Systems, Inc.", 36) )
        {
          return sub_7D4B94();
        }
      }
      v25 = *(_DWORD *)(a2 + 44);
      v26 = *(_DWORD *)(a3 + 60);
      if ( v25 > v26 )
      {
        v27 = v25 - v26;
        if ( v27 + 16 > v27 && v27 + 16 < a4 && !memcmp(v27 + a2 + 1, (unsigned int)"1-2-3 Preloader", 15) )
          return sub_7D4B94();
      }
      return -1073741541;
    }
    return sub_7D4B94();
  }
  v8 = *(unsigned __int16 *)(a2 + 4);
  if ( !*(_WORD *)(a2 + 4) && !*(_WORD *)(a2 + 20) )
    return sub_7D4B94();
  if ( (*(_WORD *)(a2 + 22) & 2) == 0 )
    return -1073741701;
  v9 = *(_QWORD *)(a2 + 52);
  v10 = *(unsigned __int16 *)(a2 + 24);
  v11 = *(_DWORD *)(a2 + 60);
  *(_DWORD *)a1 = v9;
  *(_DWORD *)(a1 + 4) = v11;
  v12 = *(_QWORD *)(a2 + 80);
  v13 = *(_QWORD *)(a2 + 112);
  *(_DWORD *)(a1 + 16) = v13;
  *(_DWORD *)(a1 + 20) = HIDWORD(v12);
  v14 = *(_DWORD *)(a2 + 40);
  *(_WORD *)(a1 + 36) = v10;
  *(_DWORD *)(a1 + 24) = v14;
  v15 = *(_DWORD *)(a2 + 96);
  *(_DWORD *)(a1 + 8) = HIDWORD(v9);
  *(_DWORD *)(a1 + 12) = v12;
  *(_BYTE *)(a1 + 92) = 0;
  *(_DWORD *)(a1 + 28) = v15;
  *(_DWORD *)(a1 + 32) = *(_DWORD *)(a2 + 100);
  *(_WORD *)(a1 + 38) = *(_WORD *)(a2 + 92);
  *(_WORD *)(a1 + 40) = *(_WORD *)(a2 + 72);
  *(_WORD *)(a1 + 42) = *(_WORD *)(a2 + 74);
  *(_WORD *)(a1 + 44) = *(_WORD *)(a2 + 64);
  *(_WORD *)(a1 + 46) = *(_WORD *)(a2 + 66);
  *(_WORD *)(a1 + 48) = *(_WORD *)(a2 + 94);
  *(_DWORD *)(a1 + 52) = *(_DWORD *)(a2 + 88);
  *(_DWORD *)(a1 + 56) = *(_DWORD *)(a2 + 28);
  if ( HIDWORD(v13) > 6 && *(_DWORD *)(a2 + 168) )
    *(_BYTE *)(a1 + 92) = 1;
  if ( HIDWORD(v13) > 0xC )
  {
    *(_DWORD *)(a1 + 60) = *(_DWORD *)(a2 + 216);
    *(_DWORD *)(a1 + 64) = *(_DWORD *)(a2 + 220);
  }
  if ( HIDWORD(v13) <= 0xE )
  {
    *(_DWORD *)(a1 + 68) = 0;
    *(_DWORD *)(a1 + 72) = 0;
  }
  else
  {
    v16 = *(_QWORD *)(a2 + 232);
    *(_QWORD *)(a1 + 68) = v16;
    if ( (_DWORD)v16 && HIDWORD(v16) )
      *(_DWORD *)(a1 + 16) = v13 | 1;
  }
  if ( HIDWORD(v13) <= 5 )
  {
    *(_DWORD *)(a1 + 76) = 0;
    *(_DWORD *)(a1 + 80) = 0;
  }
  else
  {
    *(_DWORD *)(a1 + 76) = *(_DWORD *)(a2 + 160);
    *(_DWORD *)(a1 + 80) = *(_DWORD *)(a2 + 164);
  }
  if ( HIDWORD(v13) <= 0xA )
  {
    *(_DWORD *)(a1 + 84) = 0;
    *(_DWORD *)(a1 + 88) = 0;
  }
  else
  {
    *(_DWORD *)(a1 + 84) = *(_DWORD *)(a2 + 200);
    *(_DWORD *)(a1 + 88) = *(_DWORD *)(a2 + 204);
  }
  if ( v10 == 267 )
  {
    if ( ((v11 & 0x1FF) == 0 || v11 == HIDWORD(v9))
      && v11
      && ((HIDWORD(v9) - 1) & HIDWORD(v9)) == 0
      && ((v11 - 1) & v11) == 0
      && HIDWORD(v9) >= v11
      && (unsigned int)v12 <= 0x77000000
      && (v8 == 452 || v8 == 332) )
    {
      return 0;
    }
    return -1073741701;
  }
  if ( v10 != 523 )
    return -1073741701;
  return -1073740966;
}
