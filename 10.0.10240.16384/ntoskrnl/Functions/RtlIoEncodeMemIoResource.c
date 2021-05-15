// RtlIoEncodeMemIoResource 
 
int __fastcall RtlIoEncodeMemIoResource(int a1, int a2, __int64 a3, unsigned __int64 a4, int a5, int a6, int a7, int a8)
{
  __int64 v8; // r4
  __int16 v11; // lr
  unsigned int v12; // r1
  unsigned int v13; // r2
  unsigned int v14; // r6
  unsigned int v15; // r3
  __int16 v16; // r3
  unsigned int v17; // r1
  unsigned int v18; // r2
  unsigned int v19; // r6
  unsigned int v20; // r3
  unsigned int v21; // r2
  unsigned int v22; // r1

  v8 = a4;
  if ( a2 != 3 && a2 != 7 )
  {
    if ( a2 != 1 || HIDWORD(a3) || HIDWORD(a4) )
      return -1073741811;
    *(_BYTE *)(a1 + 1) = 1;
    *(_DWORD *)(a1 + 16) = a5;
    *(_DWORD *)(a1 + 20) = a6;
    *(_DWORD *)(a1 + 24) = a7;
    *(_DWORD *)(a1 + 28) = a8;
    goto LABEL_9;
  }
  v11 = *(_WORD *)(a1 + 4) & 0xF1FF;
  *(_WORD *)(a1 + 4) = v11;
  *(_DWORD *)(a1 + 16) = a5;
  *(_DWORD *)(a1 + 20) = a6;
  *(_DWORD *)(a1 + 24) = a7;
  *(_DWORD *)(a1 + 28) = a8;
  if ( !HIDWORD(a3) && !HIDWORD(a4) )
  {
    *(_BYTE *)(a1 + 1) = 3;
LABEL_9:
    *(_DWORD *)(a1 + 8) = a3;
    *(_DWORD *)(a1 + 12) = a4;
    return 0;
  }
  if ( (unsigned __int64)a3 > 0xFFFFFFFF00i64 )
  {
    if ( (unsigned __int64)a3 > 0xFFFFFFFF0000i64 )
    {
      if ( (unsigned __int64)a3 > 0xFFFFFFFF00000000ui64 || (_DWORD)a3 || a4 > 0xFFFFFFFF00000000ui64 )
        return -1073741823;
      while ( (_DWORD)v8 )
      {
        v21 = HIDWORD(v8);
        v22 = v8;
        v8 *= 2i64;
        if ( v8 < __PAIR64__(v21, v22) )
          return -1073741823;
      }
      *(_DWORD *)(a1 + 8) = HIDWORD(a3);
      *(_DWORD *)(a1 + 12) = HIDWORD(v8);
      v16 = v11 | 0x800;
    }
    else
    {
      v17 = a3 >> 16;
      if ( a3 != __PAIR64__(HIWORD(v17), v17 << 16) || a4 > 0xFFFFFFFF0000i64 )
        return -1073741823;
      while ( 1 )
      {
        v20 = v8 >> 16;
        if ( v8 == __PAIR64__(HIWORD(v20), v20 << 16) )
          break;
        v18 = HIDWORD(v8);
        v19 = v8;
        v8 *= 2i64;
        if ( v8 < __PAIR64__(v18, v19) )
          return -1073741823;
      }
      *(_DWORD *)(a1 + 8) = v17;
      *(_DWORD *)(a1 + 12) = v20;
      v16 = v11 | 0x400;
    }
LABEL_35:
    *(_BYTE *)(a1 + 1) = 7;
    *(_WORD *)(a1 + 4) = v16;
    return 0;
  }
  v12 = a3 >> 8;
  if ( a3 == __PAIR64__(HIBYTE(v12), v12 << 8) && a4 <= 0xFFFFFFFF00i64 )
  {
    while ( 1 )
    {
      v15 = v8 >> 8;
      if ( v8 == __PAIR64__(HIBYTE(v15), v15 << 8) )
        break;
      v13 = HIDWORD(v8);
      v14 = v8;
      v8 *= 2i64;
      if ( v8 < __PAIR64__(v13, v14) )
        return -1073741823;
    }
    *(_DWORD *)(a1 + 8) = v12;
    *(_DWORD *)(a1 + 12) = v15;
    v16 = v11 | 0x200;
    goto LABEL_35;
  }
  return -1073741823;
}
