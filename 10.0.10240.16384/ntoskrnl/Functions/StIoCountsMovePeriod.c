// StIoCountsMovePeriod 
 
_BYTE *__fastcall StIoCountsMovePeriod(int a1, __int64 a2)
{
  __int64 v4; // r6
  int v5; // r0
  int v6; // r2
  int v7; // r3
  int v8; // r3
  _BYTE *v9; // r4

  v4 = *(_QWORD *)(a1 + 8);
  if ( (unsigned __int64)(a2 - v4) >= 0x23C34600 )
  {
    v5 = _rt_udiv64(600000000i64, a2 - v4 + 599999999);
    v6 = (600000000 * (unsigned __int64)(unsigned int)v5 + v4) >> 32;
    v7 = 600000000 * v5 + v4;
  }
  else
  {
    v5 = 1;
    v6 = (unsigned __int64)(v4 + 600000000) >> 32;
    v7 = v4 + 600000000;
  }
  *(_DWORD *)(a1 + 8) = v7;
  *(_DWORD *)(a1 + 12) = v6;
  v8 = *(_DWORD *)(a1 + 4) + v5;
  *(_DWORD *)(a1 + 4) = v8;
  v9 = (_BYTE *)(a1 + 20 * (v8 & 0x3F) + 16);
  memset(v9, 0, 20);
  *(_DWORD *)a1 = v9;
  return v9;
}
