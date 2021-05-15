// memset 
 
_BYTE *__fastcall memset(_BYTE *result, int a2, int a3)
{
  bool v3; // zf
  bool v4; // cc
  int v5; // r2
  _BYTE *v6; // r3
  int v7; // r1
  int i; // r2
  int *v9; // r3
  int v10; // r2

  v3 = a3 == 4;
  v4 = a3 < 4;
  v5 = a3 - 4;
  v6 = result;
  if ( !v4 )
  {
    v7 = (unsigned __int8)a2 | ((unsigned __int8)a2 << 8);
    if ( ((unsigned __int8)result & 3) != 0 )
    {
      if ( ((unsigned __int8)result & 1) != 0 )
      {
        --v5;
        *result = v7;
        v6 = result + 1;
      }
      if ( ((unsigned __int8)v6 & 2) != 0 )
      {
        v5 -= 2;
        *(_WORD *)v6 = v7;
        v6 += 2;
      }
    }
    a2 = v7 | (v7 << 16);
    v4 = v5 < 12;
    for ( i = v5 - 12; !v4; v6 = v9 + 2 )
    {
      *(_DWORD *)v6 = a2;
      *((_DWORD *)v6 + 1) = a2;
      v9 = (int *)(v6 + 8);
      v4 = i < 16;
      i -= 16;
      *v9 = a2;
      v9[1] = a2;
    }
    v4 = i < -8;
    v10 = i + 8;
    if ( !v4 )
    {
      *(_DWORD *)v6 = a2;
      *((_DWORD *)v6 + 1) = a2;
      v6 += 8;
      v10 -= 8;
    }
    v3 = v10 == -4;
    v4 = v10 < -4;
    v5 = v10 + 4;
    if ( !v4 )
    {
      *(_DWORD *)v6 = a2;
      v6 += 4;
    }
  }
  if ( v4 )
  {
    v5 += 4;
    v3 = v5 == 0;
  }
  if ( !v3 )
  {
    *v6 = a2;
    if ( v5 >= 2 )
    {
      v6[1] = a2;
      if ( v5 > 2 )
        v6[2] = a2;
    }
  }
  return result;
}
