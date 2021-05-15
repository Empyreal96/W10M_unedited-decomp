// AuthzBasepGetNextValue 
 
int __fastcall AuthzBasepGetNextValue(int a1, int a2)
{
  int v3; // r6
  int v5; // r3
  int v6; // r4
  int v7; // r5
  int v8; // r2
  int v9; // r3
  unsigned int v10; // r0
  unsigned int v11; // r2
  int v12; // r3
  unsigned int v13; // r2
  int v14; // r1
  int v15; // r2
  int v16; // r3
  _DWORD *v17; // r8
  int v18; // r2
  int v19; // r3
  int v21[6]; // [sp+0h] [bp-18h] BYREF

  v21[0] = 0;
  v3 = 0;
  if ( *(_DWORD *)(a1 + 12) != 1 )
  {
    v13 = *(_DWORD *)(a1 + 8);
    if ( v13 || !*(_DWORD *)(a1 + 4) )
    {
      if ( v13 >= *(_DWORD *)(a1 + 4) )
      {
        if ( !v13 )
          return -1073741275;
        return -2147483622;
      }
      v3 = AuthzBasepQuerySecurityAttributeAndValues(*(int **)(a1 + 16));
      *(_WORD *)a2 = *(_WORD *)a1;
      *(_BYTE *)(a2 + 4) = *(_BYTE *)(a1 + 4);
      *(_DWORD *)(a2 + 20) = *(_DWORD *)(a1 + 20);
      *(_DWORD *)(a2 + 16) = *(_DWORD *)(a1 + 16);
      *(_DWORD *)(a2 + 24) = 0;
      *(_DWORD *)(a2 + 12) = *(_DWORD *)(a1 + 12);
    }
    else
    {
      v14 = *(_DWORD *)(a1 + 4);
      v15 = *(_DWORD *)(a1 + 8);
      v16 = *(_DWORD *)(a1 + 12);
      *(_DWORD *)a2 = *(_DWORD *)a1;
      *(_DWORD *)(a2 + 4) = v14;
      *(_DWORD *)(a2 + 8) = v15;
      *(_DWORD *)(a2 + 12) = v16;
      v17 = (_DWORD *)(a2 + 16);
      v18 = *(_DWORD *)(a1 + 20);
      v19 = *(_DWORD *)(a1 + 24);
      *v17 = *(_DWORD *)(a1 + 16);
      v17[1] = v18;
      v17[2] = v19;
    }
    v12 = *(_DWORD *)(a1 + 8) + 1;
    goto LABEL_14;
  }
  if ( *(_BYTE *)(a1 + 4) )
  {
    v10 = *(_DWORD *)(a1 + 8);
    v11 = *(_DWORD *)(a1 + 20);
    if ( v10 >= v11 )
      return -2147483622;
    v3 = AuthzBasepGetConstantOperand((unsigned __int8 *)(v10 + *(_DWORD *)(a1 + 24)), v11 - v10, a2, v21);
    if ( *(_BYTE *)(a2 + 4) )
      return -1073741406;
    v12 = v21[0] + *(_DWORD *)(a1 + 8);
LABEL_14:
    *(_DWORD *)(a1 + 8) = v12;
    return v3;
  }
  if ( *(_DWORD *)(a1 + 8) )
    return -2147483622;
  *(_DWORD *)(a1 + 8) = *(_DWORD *)(a1 + 20);
  v5 = *(_DWORD *)(a1 + 4);
  v6 = *(_DWORD *)(a1 + 8);
  v7 = *(_DWORD *)(a1 + 12);
  *(_DWORD *)a2 = *(_DWORD *)a1;
  *(_DWORD *)(a2 + 4) = v5;
  *(_DWORD *)(a2 + 8) = v6;
  *(_DWORD *)(a2 + 12) = v7;
  v8 = *(_DWORD *)(a1 + 20);
  v9 = *(_DWORD *)(a1 + 24);
  *(_DWORD *)(a2 + 16) = *(_DWORD *)(a1 + 16);
  *(_DWORD *)(a2 + 20) = v8;
  *(_DWORD *)(a2 + 24) = v9;
  return v3;
}
