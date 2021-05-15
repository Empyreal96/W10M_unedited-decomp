// RtlRbRemoveNode 
 
int __fastcall RtlRbRemoveNode(int *a1, _DWORD *a2)
{
  __int64 v2; // r2
  _DWORD *v3; // r4
  int result; // r0
  unsigned int v6; // r6
  BOOL v7; // r7
  int v8; // lr
  int v9; // r3
  BOOL v10; // r9
  int v11; // r8
  unsigned int v12; // lr
  int v13; // r3
  int v14; // r8
  unsigned int v15; // r9
  char v16; // r1
  unsigned int v17; // r2
  int v18; // r2
  unsigned int v19; // r2
  unsigned int v20; // r2
  int v21; // r1
  unsigned int v22; // r2
  int v23; // r2

  v3 = (_DWORD *)a2[1];
  LODWORD(v2) = *a2;
  if ( *a2 )
  {
    if ( v3 )
    {
      v7 = 1;
      result = a2[1];
      v6 = result;
      if ( *v3 )
      {
        v7 = 0;
        do
        {
          v6 = result;
          result = *(_DWORD *)result;
        }
        while ( *(_DWORD *)result );
      }
      *(_DWORD *)result = v2;
      if ( (_DWORD *)(*(_DWORD *)(v2 + 8) & 0xFFFFFFFC) != a2 )
        sub_530EDC();
      *(_DWORD *)(v2 + 8) = *(_DWORD *)(v2 + 8) & 3 | result;
      if ( (_DWORD *)(v3[2] & 0xFFFFFFFC) != a2 )
        __fastfail(0x1Du);
      v3[2] = v3[2] & 3 | result;
      v2 = *(_QWORD *)(result + 4);
      *(_DWORD *)(result + 4) = v3;
      if ( (HIDWORD(v2) & 0xFFFFFFFC) != v6 )
        __fastfail(0x1Du);
      v8 = *(_BYTE *)(result + 8) & 1;
      *(_DWORD *)(result + 8) = a2[2];
      v9 = a2[2];
      if ( v9 )
      {
        v10 = *(_DWORD *)((v9 & 0xFFFFFFFC) + 4) == (_DWORD)a2;
        if ( *(_DWORD **)((v9 & 0xFFFFFFFC) + 4 * v10) != a2 )
          __fastfail(0x1Du);
        *(_DWORD *)((v9 & 0xFFFFFFFC) + 4 * v10) = result;
      }
      else
      {
        if ( (_DWORD *)*a1 != a2 )
          __fastfail(0x1Du);
        *a1 = result;
      }
      goto LABEL_15;
    }
  }
  else
  {
    LODWORD(v2) = a2[1];
  }
  result = (int)a2;
  v6 = a2[2] & 0xFFFFFFFC;
  if ( !v6 )
  {
    if ( (_DWORD)v2 )
      *(_DWORD *)(v2 + 8) = 0;
    if ( (_DWORD *)*a1 != a2 )
      __fastfail(0x1Du);
    a1[1] = v2;
    *a1 = v2;
    return result;
  }
  if ( *(_DWORD **)(v6 + 4) == a2 )
  {
    v7 = 1;
  }
  else
  {
    if ( *(_DWORD **)v6 != a2 )
      __fastfail(0x1Du);
    v7 = 0;
    if ( (_DWORD *)a1[1] == a2 )
    {
      if ( (_DWORD)v2 )
        a1[1] = v2;
      else
        a1[1] = v6;
    }
  }
  v8 = a2[2] & 1;
LABEL_15:
  *(_DWORD *)(v6 + 4 * v7) = v2;
  if ( (_DWORD)v2 )
  {
    if ( (*(_DWORD *)(v2 + 8) & 0xFFFFFFFC) != result )
      __fastfail(0x1Du);
    *(_DWORD *)(v2 + 8) = v6;
  }
  else if ( !v8 )
  {
    while ( 1 )
    {
      v11 = !v7;
      v12 = *(_DWORD *)(v6 + 4 * !v7);
      if ( (*(_BYTE *)(v12 + 8) & 1) != 0 )
      {
        if ( (*(_DWORD *)(v12 + 8) & 0xFFFFFFFC) != v6 )
          __fastfail(0x1Du);
        v22 = *(_DWORD *)(v6 + 8) & 0xFFFFFFFC;
        if ( v22 )
        {
          if ( *(_DWORD *)(v22 + 4) == v6 )
          {
            *(_DWORD *)(v22 + 4) = v12;
          }
          else
          {
            if ( *(_DWORD *)v22 != v6 )
              __fastfail(0x1Du);
            *(_DWORD *)v22 = v12;
          }
        }
        else
        {
          if ( *a1 != v6 )
            __fastfail(0x1Du);
          *a1 = v12;
        }
        *(_DWORD *)(v12 + 8) = *(_DWORD *)(v12 + 8) & 3 | v22;
        v23 = *(_DWORD *)(v12 + 4 * v7);
        if ( v23 )
        {
          if ( (*(_DWORD *)(v23 + 8) & 0xFFFFFFFC) != v12 )
            __fastfail(0x1Du);
          *(_DWORD *)(v23 + 8) = *(_DWORD *)(v23 + 8) & 3 | v6;
        }
        *(_DWORD *)(v6 + 4 * v11) = v23;
        *(_DWORD *)(v12 + 4 * v7) = v6;
        *(_DWORD *)(v6 + 8) = *(_DWORD *)(v6 + 8) & 3 | v12;
        result = *(unsigned __int8 *)(v12 + 8);
        *(_BYTE *)(v12 + 8) = result & 0xFE;
        *(_BYTE *)(v6 + 8) |= 1u;
        v12 = *(_DWORD *)(v6 + 4 * v11);
      }
      if ( *(_DWORD *)v12 && (*(_BYTE *)(*(_DWORD *)v12 + 8) & 1) != 0 )
        break;
      v13 = *(_DWORD *)(v12 + 4);
      if ( v13 )
      {
        if ( (*(_BYTE *)(v13 + 8) & 1) != 0 )
          break;
      }
      if ( (*(_BYTE *)(v6 + 8) & 1) != 0 )
      {
        *(_BYTE *)(v6 + 8) &= 0xFEu;
        *(_BYTE *)(v12 + 8) |= 1u;
        return result;
      }
      *(_BYTE *)(v12 + 8) |= 1u;
      v19 = *(_DWORD *)(v6 + 8) & 0xFFFFFFFC;
      if ( !v19 )
        return result;
      v7 = *(_DWORD *)(v19 + 4) == v6;
      v6 = *(_DWORD *)(v6 + 8) & 0xFFFFFFFC;
    }
    v14 = !v7;
    v15 = *(_DWORD *)(v12 + 4 * !v7);
    if ( !v15 || (*(_BYTE *)(v15 + 8) & 1) == 0 )
    {
      v20 = *(_DWORD *)(v12 + 4 * v7);
      *(_BYTE *)(v20 + 8) &= 0xFEu;
      if ( (*(_DWORD *)(v20 + 8) & 0xFFFFFFFC) != v12 )
        __fastfail(0x1Du);
      if ( *(_DWORD *)(v12 + 4 * v7) != v20 )
        __fastfail(0x1Du);
      if ( *(_DWORD *)(v6 + 4 * v14) != v12 || (*(_DWORD *)(v12 + 8) & 0xFFFFFFFC) != v6 )
        __fastfail(0x1Du);
      *(_DWORD *)(v6 + 4 * v14) = v20;
      *(_DWORD *)(v20 + 8) = *(_DWORD *)(v20 + 8) & 3 | v6;
      v21 = *(_DWORD *)(v20 + 4 * v14);
      if ( v21 )
      {
        if ( (*(_DWORD *)(v21 + 8) & 0xFFFFFFFC) != v20 )
          __fastfail(0x1Du);
        *(_DWORD *)(v21 + 8) = *(_DWORD *)(v21 + 8) & 3 | v12;
      }
      *(_DWORD *)(v12 + 4 * v7) = v21;
      *(_DWORD *)(v20 + 4 * v14) = v12;
      v15 = v12;
      *(_DWORD *)(v12 + 8) = *(_DWORD *)(v12 + 8) & 3 | v20;
      v12 = v20;
    }
    *(_BYTE *)(v12 + 8) ^= (*(_BYTE *)(v6 + 8) ^ *(_BYTE *)(v12 + 8)) & 1;
    *(_BYTE *)(v6 + 8) &= 0xFEu;
    v16 = *(_BYTE *)(v15 + 8);
    result = v16 & 0xFE;
    *(_BYTE *)(v15 + 8) = v16 & 0xFE;
    if ( (*(_DWORD *)(v12 + 8) & 0xFFFFFFFC) != v6 )
      __fastfail(0x1Du);
    if ( *(_DWORD *)(v6 + 4 * v14) != v12 )
      __fastfail(0x1Du);
    v17 = *(_DWORD *)(v6 + 8) & 0xFFFFFFFC;
    if ( v17 )
    {
      if ( *(_DWORD *)(v17 + 4) == v6 )
      {
        *(_DWORD *)(v17 + 4) = v12;
      }
      else
      {
        if ( *(_DWORD *)v17 != v6 )
          __fastfail(0x1Du);
        *(_DWORD *)v17 = v12;
      }
    }
    else
    {
      if ( *a1 != v6 )
        __fastfail(0x1Du);
      *a1 = v12;
    }
    *(_DWORD *)(v12 + 8) = *(_DWORD *)(v12 + 8) & 3 | v17;
    v18 = *(_DWORD *)(v12 + 4 * v7);
    if ( v18 )
    {
      if ( (*(_DWORD *)(v18 + 8) & 0xFFFFFFFC) != v12 )
        __fastfail(0x1Du);
      *(_DWORD *)(v18 + 8) = *(_DWORD *)(v18 + 8) & 3 | v6;
    }
    *(_DWORD *)(v6 + 4 * v14) = v18;
    *(_DWORD *)(v12 + 4 * v7) = v6;
    *(_DWORD *)(v6 + 8) = *(_DWORD *)(v6 + 8) & 3 | v12;
  }
  return result;
}
