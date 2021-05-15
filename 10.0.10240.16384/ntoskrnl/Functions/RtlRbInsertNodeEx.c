// RtlRbInsertNodeEx 
 
unsigned int __fastcall RtlRbInsertNodeEx(unsigned int result, unsigned int a2, int a3, _DWORD *a4)
{
  unsigned int v4; // r4
  _DWORD *v5; // r6
  int v6; // r5
  int v7; // r7
  int v8; // r7
  int v9; // r4
  unsigned int v10; // r2
  int v11; // r2

  v4 = (unsigned int)a4;
  *a4 = 0;
  a4[1] = 0;
  v5 = (_DWORD *)result;
  if ( a2 )
  {
    *(_DWORD *)(a2 + 4 * a3) = a4;
    a4[2] = a2 | 1;
    if ( !a3 && a2 == *(_DWORD *)(result + 4) )
      *(_DWORD *)(result + 4) = a4;
    if ( (*(_BYTE *)(a2 + 8) & 1) != 0 )
    {
      while ( 1 )
      {
        result = *(_DWORD *)(a2 + 8) & 0xFFFFFFFC;
        v6 = *(_DWORD *)result != a2;
        v7 = *(_DWORD *)(result + 4 * (*(_DWORD *)result == a2));
        if ( !v7 || (*(_BYTE *)(v7 + 8) & 1) == 0 )
          break;
        v4 = *(_DWORD *)(a2 + 8) & 0xFFFFFFFC;
        *(_BYTE *)(a2 + 8) &= 0xFEu;
        *(_BYTE *)(v7 + 8) &= 0xFEu;
        a2 = *(_DWORD *)(result + 8) & 0xFFFFFFFC;
        if ( a2 )
        {
          *(_BYTE *)(result + 8) |= 1u;
          a3 = result != *(_DWORD *)a2;
          if ( (*(_BYTE *)(a2 + 8) & 1) != 0 )
            continue;
        }
        return result;
      }
      if ( a3 != v6 )
      {
        if ( (*(_DWORD *)(v4 + 8) & 0xFFFFFFFC) != a2 )
          sub_50C1E8();
        if ( *(_DWORD *)(a2 + 4 * (*(_DWORD *)result == a2)) != v4 )
          __fastfail(0x1Du);
        if ( *(_DWORD *)(result + 4 * v6) != a2 )
          __fastfail(0x1Du);
        *(_DWORD *)(result + 4 * v6) = v4;
        *(_DWORD *)(v4 + 8) = *(_DWORD *)(v4 + 8) & 3 | result;
        v8 = *(_DWORD *)(v4 + 4 * v6);
        if ( v8 )
        {
          if ( (*(_DWORD *)(v8 + 8) & 0xFFFFFFFC) != v4 )
            __fastfail(0x1Du);
          *(_DWORD *)(v8 + 8) = *(_DWORD *)(v8 + 8) & 3 | a2;
        }
        *(_DWORD *)(a2 + 4 * (v6 ^ 1)) = v8;
        *(_DWORD *)(v4 + 4 * v6) = a2;
        *(_DWORD *)(a2 + 8) = *(_DWORD *)(a2 + 8) & 3 | v4;
        a2 = v4;
      }
      v9 = v6 ^ 1;
      if ( (*(_DWORD *)(a2 + 8) & 0xFFFFFFFC) != result )
        __fastfail(0x1Du);
      if ( *(_DWORD *)(result + 4 * v6) != a2 )
        __fastfail(0x1Du);
      v10 = *(_DWORD *)(result + 8) & 0xFFFFFFFC;
      if ( v10 )
      {
        if ( *(_DWORD *)(v10 + 4) == result )
        {
          *(_DWORD *)(v10 + 4) = a2;
        }
        else
        {
          if ( *(_DWORD *)v10 != result )
            __fastfail(0x1Du);
          *(_DWORD *)v10 = a2;
        }
      }
      else
      {
        if ( *v5 != result )
          __fastfail(0x1Du);
        *v5 = a2;
      }
      *(_DWORD *)(a2 + 8) = *(_DWORD *)(a2 + 8) & 3 | v10;
      v11 = *(_DWORD *)(a2 + 4 * v9);
      if ( v11 )
      {
        if ( (*(_DWORD *)(v11 + 8) & 0xFFFFFFFC) != a2 )
          __fastfail(0x1Du);
        *(_DWORD *)(v11 + 8) = *(_DWORD *)(v11 + 8) & 3 | result;
      }
      *(_DWORD *)(result + 4 * v6) = v11;
      *(_DWORD *)(a2 + 4 * v9) = result;
      *(_DWORD *)(result + 8) = *(_DWORD *)(result + 8) & 3 | a2;
      *(_BYTE *)(result + 8) |= 1u;
      *(_BYTE *)(a2 + 8) &= 0xFEu;
    }
  }
  else
  {
    *(_DWORD *)result = a4;
    *(_DWORD *)(result + 4) = a4;
    a4[2] = 0;
  }
  return result;
}
