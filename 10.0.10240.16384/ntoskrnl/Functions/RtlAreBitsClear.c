// RtlAreBitsClear 
 
int __fastcall RtlAreBitsClear(unsigned int *a1, int a2, unsigned int a3)
{
  char v3; // r4
  char v4; // r5
  unsigned int v5; // r6
  unsigned int v6; // r2
  _DWORD *v7; // r1
  _DWORD *v8; // r0
  unsigned int v9; // r2

  v3 = a3;
  v4 = a2;
  v5 = a2 + a3 - 1;
  if ( v5 >= *a1 )
    return 0;
  if ( a3 > 1 )
  {
    v6 = a1[1];
    v7 = (_DWORD *)(v6 + 4 * ((unsigned int)a2 >> 5));
    v8 = (_DWORD *)(v6 + 4 * (v5 >> 5));
    if ( v7 == v8 )
    {
      v9 = 0xFFFFFFFF >> (32 - v3) << (v4 & 0x1F);
      return (*v7 & v9) == 0;
    }
    if ( (*v7 & (-1 << (v4 & 0x1F))) == 0 )
    {
      for ( ++v7; v7 != v8; ++v7 )
      {
        if ( *v7 )
          return 0;
      }
      v9 = 0xFFFFFFFF >> (31 - (v5 & 0x1F));
      return (*v7 & v9) == 0;
    }
    return 0;
  }
  if ( a3 != 1 )
    return 0;
  return ((*(unsigned __int8 *)((a2 >> 3) + a1[1]) >> (a2 & 7)) & 1) == 0;
}
