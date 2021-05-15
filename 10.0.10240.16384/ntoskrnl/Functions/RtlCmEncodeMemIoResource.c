// RtlCmEncodeMemIoResource 
 
int __fastcall RtlCmEncodeMemIoResource(int a1, int a2, __int64 a3, int a4, int a5)
{
  __int64 v5; // r4
  __int16 v7; // r3

  v5 = a3;
  if ( a2 != 3 && a2 != 7 )
  {
    if ( a2 != 1 || HIDWORD(a3) )
      return -1073741811;
    *(_BYTE *)a1 = 1;
    *(_DWORD *)(a1 + 4) = a4;
    *(_DWORD *)(a1 + 8) = a5;
    goto LABEL_8;
  }
  LOWORD(a3) = *(_WORD *)(a1 + 2) & 0xF1FF;
  *(_WORD *)(a1 + 2) = a3;
  *(_DWORD *)(a1 + 4) = a4;
  *(_DWORD *)(a1 + 8) = a5;
  if ( !HIDWORD(a3) )
  {
    *(_BYTE *)a1 = 3;
LABEL_8:
    *(_DWORD *)(a1 + 12) = v5;
    return 0;
  }
  if ( (unsigned __int64)v5 > 0xFFFFFFFF00i64 )
  {
    if ( (unsigned __int64)v5 > 0xFFFFFFFF0000i64 )
    {
      if ( (unsigned __int64)v5 <= 0xFFFFFFFF00000000ui64 && !(_DWORD)v5 )
      {
        *(_BYTE *)a1 = 7;
        v7 = a3 | 0x800;
        *(_DWORD *)(a1 + 12) = HIDWORD(v5);
        goto LABEL_21;
      }
    }
    else
    {
      HIDWORD(a3) = v5 >> 16;
      if ( v5 == __PAIR64__(HIWORD(HIDWORD(a3)), HIDWORD(a3) << 16) )
      {
        *(_DWORD *)(a1 + 12) = HIDWORD(a3);
        *(_BYTE *)a1 = 7;
        v7 = a3 | 0x400;
        goto LABEL_21;
      }
    }
  }
  else
  {
    HIDWORD(a3) = v5 >> 8;
    if ( v5 == __PAIR64__(HIBYTE(HIDWORD(a3)), HIDWORD(a3) << 8) )
    {
      *(_DWORD *)(a1 + 12) = HIDWORD(a3);
      *(_BYTE *)a1 = 7;
      v7 = a3 | 0x200;
LABEL_21:
      *(_WORD *)(a1 + 2) = v7;
      return 0;
    }
  }
  return -1073741823;
}
