// IoBuildPartialMdl 
 
_DWORD *__fastcall IoBuildPartialMdl(int a1, int a2, unsigned int a3, int a4)
{
  unsigned int v5; // r5
  unsigned int v7; // r3
  unsigned int v8; // r10
  _DWORD *result; // r0
  int v11; // r3
  __int16 v12; // r0
  unsigned int v13; // r1
  int v14; // r2

  v5 = *(_DWORD *)(a1 + 16);
  v7 = a3 - *(_DWORD *)(a1 + 24);
  v8 = v7 - v5;
  if ( !a4 )
    return (_DWORD *)sub_51CA9C();
  if ( a3 < v5 || v7 - v5 > *(_DWORD *)(a1 + 20) )
    KeBugCheck2(302, a1, a2, a3, a4, 0);
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(a1 + 8);
  *(_DWORD *)(a2 + 16) = a3 & 0xFFFFF000;
  v11 = *(_DWORD *)(a1 + 16);
  *(_DWORD *)(a2 + 20) = a4;
  *(_DWORD *)(a2 + 24) = a3 & 0xFFF;
  v12 = *(_WORD *)(a2 + 6) & 8;
  *(_WORD *)(a2 + 6) = v12;
  *(_WORD *)(a2 + 6) = *(_WORD *)(a1 + 6) & 0x48C5 | v12 | 0x10;
  result = (_DWORD *)(a1 + 4 * ((((a3 & 0xFFFFF000) - v11) >> 12) + 7));
  *(_DWORD *)(a2 + 12) = *(_DWORD *)(a1 + 12) + v8;
  v13 = ((a3 & 0xFFF) + a4 + 4095) >> 12;
  if ( v13 )
  {
    v14 = a2 + 28 - (_DWORD)result;
    do
    {
      *(_DWORD *)((char *)result + v14) = *result;
      ++result;
      --v13;
    }
    while ( v13 );
  }
  return result;
}
