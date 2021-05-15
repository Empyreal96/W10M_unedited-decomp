// RtlAvlInsertNodeEx 
 
int __fastcall RtlAvlInsertNodeEx(int result, int a2, int a3, _DWORD *a4)
{
  unsigned int v4; // r5
  int v5; // r4
  unsigned int *v6; // r7
  int v7; // r6
  int v8; // r1
  int v9; // r1
  unsigned int v10; // r2
  int v11; // r2
  char v12; // r7
  unsigned __int8 v13; // r1

  v4 = (unsigned int)a4;
  v5 = a2;
  *a4 = 0;
  a4[1] = 0;
  v6 = (unsigned int *)result;
  a4[2] = a2;
  if ( a2 )
  {
    *(_DWORD *)(a2 + 4 * a3) = a4;
    result = -1;
    v7 = *(_BYTE *)(a2 + 8) & 3;
    v8 = (-1 - 2 * a3) & 3;
    if ( (*(_BYTE *)(v5 + 8) & 3) != 0 )
    {
LABEL_5:
      if ( v7 == v8 )
      {
        if ( (*(_BYTE *)(v4 + 8) & 3) == v7 )
        {
          v9 = a3 ^ 1;
          if ( (*(_DWORD *)(v4 + 8) & 0xFFFFFFFC) != v5 )
            sub_50E6D0();
          if ( *(_DWORD *)(v5 + 4 * a3) != v4 )
            __fastfail(0x1Du);
          v10 = *(_DWORD *)(v5 + 8) & 0xFFFFFFFC;
          if ( v10 )
          {
            if ( *(_DWORD *)(v10 + 4) == v5 )
            {
              *(_DWORD *)(v10 + 4) = v4;
            }
            else
            {
              if ( *(_DWORD *)v10 != v5 )
                __fastfail(0x1Du);
              *(_DWORD *)v10 = v4;
            }
          }
          else
          {
            if ( *v6 != v5 )
              __fastfail(0x1Du);
            *v6 = v4;
          }
          *(_DWORD *)(v4 + 8) = *(_DWORD *)(v4 + 8) & 3 | v10;
          v11 = *(_DWORD *)(v4 + 4 * v9);
          if ( v11 )
          {
            if ( (*(_DWORD *)(v11 + 8) & 0xFFFFFFFC) != v4 )
              __fastfail(0x1Du);
            *(_DWORD *)(v11 + 8) = *(_DWORD *)(v11 + 8) & 3 | v5;
          }
          *(_DWORD *)(v5 + 4 * (v9 ^ 1)) = v11;
          *(_DWORD *)(v4 + 4 * v9) = v5;
          *(_DWORD *)(v5 + 8) = *(_DWORD *)(v5 + 8) & 3 | v4;
          result = *(unsigned __int8 *)(v4 + 8);
          *(_BYTE *)(v4 + 8) = result & 0xFC;
          *(_BYTE *)(v5 + 8) &= 0xFCu;
        }
        else
        {
          result = RtlpTreeDoubleRotateNodes(v6, v5, v4, a3);
          *(_BYTE *)(v5 + 8) &= 0xFCu;
          v12 = *(_BYTE *)(v4 + 8) & 0xFC;
          *(_BYTE *)(v4 + 8) = v12;
          v13 = *(_BYTE *)(result + 8);
          if ( v7 == (v13 & 3) )
          {
            *(_BYTE *)(v5 + 8) ^= (*(_BYTE *)(v5 + 8) ^ v7 ^ 0xFE) & 3;
            *(_BYTE *)(result + 8) &= 0xFCu;
          }
          else
          {
            if ( v7 == ((v13 ^ 0xFE) & 3) )
              *(_BYTE *)(v4 + 8) = (v12 ^ v7) & 3 ^ v12;
            *(_BYTE *)(result + 8) &= 0xFCu;
          }
        }
      }
      else
      {
        *(_BYTE *)(v5 + 8) &= 0xFCu;
      }
    }
    else
    {
      while ( 1 )
      {
        v4 = v5;
        *(_BYTE *)(v5 + 8) ^= (*(_BYTE *)(v5 + 8) ^ v8) & 3;
        v5 = *(_DWORD *)(v5 + 8) & 0xFFFFFFFC;
        if ( !v5 )
          break;
        a3 = *(_DWORD *)v5 != v4;
        v7 = *(_BYTE *)(v5 + 8) & 3;
        v8 = (-1 - 2 * a3) & 3;
        if ( (*(_BYTE *)(v5 + 8) & 3) != 0 )
          goto LABEL_5;
      }
    }
  }
  else
  {
    *(_DWORD *)result = a4;
  }
  return result;
}
