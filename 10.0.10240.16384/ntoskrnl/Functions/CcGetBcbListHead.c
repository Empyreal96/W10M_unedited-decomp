// CcGetBcbListHead 
 
int __fastcall CcGetBcbListHead(int a1, __int64 a2)
{
  __int64 v3; // r4
  int v4; // r6
  unsigned int v6; // r3
  int v7; // r1

  v3 = *(_QWORD *)(a1 + 24);
  v4 = HIDWORD(a2);
  if ( v3 <= 0x200000 || (*(_DWORD *)(a1 + 96) & 0x200) == 0 )
    return a1 + 16;
  if ( SHIDWORD(v3) > 0 || (unsigned int)v3 > 0x2000000 )
    return sub_54A508();
  if ( a2 >= v3 )
    return a1 + 16;
  if ( *(_DWORD *)(a1 + 28) )
  {
    v7 = -1;
  }
  else
  {
    v6 = *(_DWORD *)(a1 + 24);
    if ( v6 <= 0x100000 )
      v7 = 16;
    else
      v7 = 4 * (v6 >> 18);
  }
  return *(_DWORD *)(a1 + 64) + 8 * ((v4 << 13) | ((unsigned int)a2 >> 19)) + v7;
}
