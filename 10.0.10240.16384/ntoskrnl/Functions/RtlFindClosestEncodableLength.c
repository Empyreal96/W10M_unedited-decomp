// RtlFindClosestEncodableLength 
 
int __fastcall RtlFindClosestEncodableLength(unsigned __int64 a1, int a2)
{
  int result; // r0
  __int64 v4; // r2

  if ( !HIDWORD(a1) )
    goto LABEL_2;
  if ( a1 <= 0xFFFFFFFF00i64 )
  {
    if ( (_DWORD)a1 == (a1 & 0xFFFFFF00) )
      goto LABEL_2;
    *(_QWORD *)a2 = __PAIR64__(HIDWORD(a1), (unsigned int)a1 & 0xFFFFFF00) + 256;
    a1 = __PAIR64__(HIDWORD(a1), (unsigned int)a1 & 0xFFFFFF00) + 256;
    if ( a1 <= 0xFFFFFFFF00i64 )
      return 0;
  }
  if ( a1 > 0xFFFFFFFF0000i64 )
    goto LABEL_10;
  if ( (_DWORD)a1 == (a1 & 0xFFFF0000) )
  {
LABEL_2:
    *(_QWORD *)a2 = a1;
    return 0;
  }
  *(_QWORD *)a2 = __PAIR64__(HIDWORD(a1), (unsigned int)a1 & 0xFFFF0000) + 0x10000;
  a1 = __PAIR64__(HIDWORD(a1), (unsigned int)a1 & 0xFFFF0000) + 0x10000;
  if ( a1 <= 0xFFFFFFFF0000i64 )
    return 0;
LABEL_10:
  if ( a1 <= 0xFFFFFFFF00000000ui64 )
  {
    LODWORD(v4) = 0;
    if ( (_DWORD)a1 )
    {
      HIDWORD(v4) = HIDWORD(a1) + 1;
      *(_QWORD *)a2 = v4;
      return 0;
    }
    goto LABEL_2;
  }
  result = -1073741823;
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  return result;
}
