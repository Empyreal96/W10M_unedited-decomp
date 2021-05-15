// RtlAvlRemoveNode 
 
int __fastcall RtlAvlRemoveNode(int result, int a2)
{
  int v2; // r2
  int v3; // r5
  _DWORD *v4; // r8
  int v5; // r4
  int v6; // r2
  char v7; // r3
  int v8; // r5
  unsigned int v9; // r6
  _DWORD *v10; // r3
  int v11; // r7
  int v12; // r6
  unsigned int v13; // r5
  unsigned int v14; // r7
  int v15; // lr
  int v16; // r1
  char v17; // r3
  BOOL v18; // r6
  int v19; // r3
  char v20; // r2
  unsigned __int8 v21; // r1

  v2 = *(_DWORD *)(a2 + 4);
  v3 = *(_DWORD *)a2;
  v4 = (_DWORD *)result;
  if ( *(_DWORD *)a2 )
  {
    if ( v2 )
    {
      if ( (*(_BYTE *)(a2 + 8) & 3) == 3 )
      {
        v19 = *(_DWORD *)(v3 + 4);
        v11 = 0;
        result = *(_DWORD *)a2;
        v5 = *(_DWORD *)a2;
        if ( v19 )
        {
          v11 = 1;
          do
          {
            v5 = result;
            result = v19;
            v19 = *(_DWORD *)(v19 + 4);
          }
          while ( v19 );
        }
        v12 = *(_DWORD *)result;
      }
      else
      {
        v10 = *(_DWORD **)v2;
        v11 = 1;
        result = *(_DWORD *)(a2 + 4);
        v5 = result;
        if ( *(_DWORD *)v2 )
        {
          v11 = 0;
          do
          {
            v5 = result;
            result = (int)v10;
            v10 = (_DWORD *)*v10;
          }
          while ( v10 );
        }
        v12 = *(_DWORD *)(result + 4);
      }
      *(_DWORD *)result = v3;
      *(_DWORD *)(result + 4) = v2;
      if ( (*(_DWORD *)(v3 + 8) & 0xFFFFFFFC) != a2 )
        __fastfail(0x1Du);
      *(_DWORD *)(v3 + 8) = *(_DWORD *)(v3 + 8) & 3 | result;
      if ( (*(_DWORD *)(v2 + 8) & 0xFFFFFFFC) != a2 )
        __fastfail(0x1Du);
      *(_DWORD *)(v2 + 8) = *(_DWORD *)(v2 + 8) & 3 | result;
      if ( (*(_DWORD *)(result + 8) & 0xFFFFFFFC) != v5 )
        __fastfail(0x1Du);
      *(_DWORD *)(v5 + 4 * v11) = v12;
      if ( v12 )
      {
        if ( *(_DWORD *)(v12 + 8) != result )
          sub_544878();
        *(_DWORD *)(v12 + 8) = v5;
      }
      if ( v11 )
        v6 = 3;
      else
        v6 = 1;
      *(_DWORD *)(result + 8) = *(_DWORD *)(a2 + 8);
      v13 = *(_DWORD *)(a2 + 8) & 0xFFFFFFFC;
      if ( v13 )
      {
        v18 = *(_DWORD *)(v13 + 4) == a2;
        if ( *(_DWORD *)(v13 + 4 * v18) != a2 )
          __fastfail(0x1Du);
        *(_DWORD *)(v13 + 4 * v18) = result;
      }
      else
      {
        if ( *v4 != a2 )
          __fastfail(0x1Du);
        *v4 = result;
      }
      while ( 1 )
      {
LABEL_7:
        v7 = *(_BYTE *)(v5 + 8);
        v8 = v7 & 3;
        if ( v8 == (v6 ^ 2) )
        {
          *(_BYTE *)(v5 + 8) = v7 & 0xFC;
          v9 = *(_DWORD *)(v5 + 8) & 0xFFFFFFFC;
        }
        else
        {
          if ( (v7 & 3) == 0 )
          {
            *(_BYTE *)(v5 + 8) ^= (v7 ^ v6) & 3;
            return result;
          }
          v14 = *(_DWORD *)v5;
          v9 = *(_DWORD *)(v5 + 8) & 0xFFFFFFFC;
          if ( v6 == 1 )
            v14 = *(_DWORD *)(v5 + 4);
          v15 = *(_BYTE *)(v14 + 8) & 3;
          if ( v15 == (v6 ^ 2) )
          {
            result = RtlpTreeDoubleRotateNodes(v4, v5, v14, v6 == 1);
            *(_BYTE *)(v5 + 8) &= 0xFCu;
            v20 = *(_BYTE *)(v14 + 8);
            *(_BYTE *)(v14 + 8) = v20 & 0xFC;
            v21 = *(_BYTE *)(result + 8);
            if ( v8 == (v21 & 3) )
            {
              *(_BYTE *)(v5 + 8) ^= (*(_BYTE *)(v5 + 8) ^ v8 ^ 0xFE) & 3;
              v5 = result;
              *(_BYTE *)(result + 8) &= 0xFCu;
            }
            else
            {
              if ( v8 == ((v21 ^ 0xFE) & 3) )
                *(_BYTE *)(v14 + 8) = (v20 & 0xFC ^ v8) & 3 ^ v20 & 0xFC;
              v5 = result;
              *(_BYTE *)(result + 8) &= 0xFCu;
            }
          }
          else
          {
            result = v6 != 1;
            if ( (*(_DWORD *)(v14 + 8) & 0xFFFFFFFC) != v5 )
              __fastfail(0x1Du);
            if ( *(_DWORD *)(v5 + 4 * (v6 == 1)) != v14 )
              __fastfail(0x1Du);
            if ( v9 )
            {
              if ( *(_DWORD *)(v9 + 4) == v5 )
              {
                *(_DWORD *)(v9 + 4) = v14;
              }
              else
              {
                if ( *(_DWORD *)v9 != v5 )
                  __fastfail(0x1Du);
                *(_DWORD *)v9 = v14;
              }
            }
            else
            {
              if ( *v4 != v5 )
                __fastfail(0x1Du);
              *v4 = v14;
            }
            *(_DWORD *)(v14 + 8) = *(_DWORD *)(v14 + 8) & 3 | v9;
            v16 = *(_DWORD *)(v14 + 4 * result);
            if ( v16 )
            {
              if ( (*(_DWORD *)(v16 + 8) & 0xFFFFFFFC) != v14 )
                __fastfail(0x1Du);
              *(_DWORD *)(v16 + 8) = *(_DWORD *)(v16 + 8) & 3 | v5;
            }
            *(_DWORD *)(v5 + 4 * (v6 == 1)) = v16;
            *(_DWORD *)(v14 + 4 * result) = v5;
            *(_DWORD *)(v5 + 8) = *(_DWORD *)(v5 + 8) & 3 | v14;
            v17 = *(_BYTE *)(v14 + 8);
            if ( !v15 )
            {
              *(_BYTE *)(v14 + 8) ^= (v17 ^ v6 ^ 0xFE) & 3;
              return result;
            }
            *(_BYTE *)(v14 + 8) = v17 & 0xFC;
            *(_BYTE *)(v5 + 8) &= 0xFCu;
            v5 = v14;
          }
        }
        if ( !v9 )
          return result;
        v6 = 1;
        if ( *(_DWORD *)(v9 + 4) == v5 )
          v6 = 3;
        v5 = v9;
      }
    }
  }
  else
  {
    v3 = *(_DWORD *)(a2 + 4);
  }
  v5 = *(_DWORD *)(a2 + 8) & 0xFFFFFFFC;
  if ( v3 )
  {
    if ( *(_DWORD *)(v3 + 8) != a2 )
      __fastfail(0x1Du);
    *(_DWORD *)(v3 + 8) = v5;
  }
  if ( v5 )
  {
    if ( *(_DWORD *)(v5 + 4) == a2 )
    {
      v6 = 3;
      *(_DWORD *)(v5 + 4) = v3;
    }
    else
    {
      if ( *(_DWORD *)v5 != a2 )
        __fastfail(0x1Du);
      v6 = 1;
      *(_DWORD *)v5 = v3;
    }
    goto LABEL_7;
  }
  if ( *(_DWORD *)result != a2 )
    __fastfail(0x1Du);
  *(_DWORD *)result = v3;
  return result;
}
