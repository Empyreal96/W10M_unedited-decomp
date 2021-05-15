// AuthzBasepEvaluateSetRelationship 
 
int __fastcall AuthzBasepEvaluateSetRelationship(int a1, int a2, int *a3)
{
  int result; // r0
  int *v5; // r6
  int v6; // r8
  int v7; // r9
  int v9; // r3
  int v10; // r7
  int v11; // r2
  int v12; // r3
  int v13; // r7
  int v14; // r2
  int v15; // r3
  int v16; // r7
  int v17; // r2
  int v18; // r2
  int v19; // r2
  int v20; // r3
  int v21; // r7
  int v22; // r2
  __int16 v23; // [sp+0h] [bp-58h] BYREF
  char v24; // [sp+4h] [bp-54h]
  int v25; // [sp+8h] [bp-50h]
  int v26; // [sp+10h] [bp-48h]
  int v27; // [sp+14h] [bp-44h]
  int v28; // [sp+18h] [bp-40h]
  char v29[56]; // [sp+20h] [bp-38h] BYREF

  result = 0;
  v5 = a3;
  v6 = 0;
  v7 = 0;
  *a3 = 0;
  if ( !a1 )
  {
    if ( *(_DWORD *)(a2 + 12) != 1 && *(_DWORD *)(a2 + 40) != 1 )
    {
      a3 = *(int **)(a2 + 4);
      if ( a3 != *(int **)(a2 + 32) )
        return result;
    }
    v15 = 1;
    while ( 1 )
    {
      v16 = *(_DWORD *)(a2 + 8);
      result = AuthzBasepGetNextValue(a2, &v23, a3, v15);
      if ( result == -2147483622 )
        break;
      if ( result < 0 )
        goto LABEL_58;
      if ( *(_WORD *)(a2 + 28) == 4 )
      {
        result = AuthzBasepGetNextValue(a2, v29, v17, 4);
        if ( result < 0 )
          goto LABEL_58;
        v24 = *(_BYTE *)(a2 + 4);
        v23 = *(_WORD *)a2;
        v26 = *(_DWORD *)(a2 + 16);
        v25 = 0;
        v27 = *(_DWORD *)(a2 + 8);
        v28 = *(_DWORD *)(a2 + 24) + v16;
      }
      ++v6;
      result = ((int (__fastcall *)(__int16 *, int, int *, _DWORD))AuthzBasepValueInSet)(&v23, a2 + 28, v5, 0);
      if ( result < 0 )
      {
LABEL_58:
        *v5 = -1;
        return result;
      }
      v15 = *v5;
      if ( *v5 != 1 )
        return result;
    }
    v18 = *(_DWORD *)(a2 + 12);
    result = 0;
    if ( v18 == 1 && !*(_BYTE *)(a2 + 4) )
    {
      if ( *(_DWORD *)(a2 + 40) == 1 )
        goto LABEL_43;
      if ( *(_DWORD *)(a2 + 32) == 1 )
        return result;
    }
    if ( *(_DWORD *)(a2 + 40) != 1 )
    {
LABEL_46:
      AuthzBasepRestartOperandValueEnumeration(a2);
      while ( 1 )
      {
        v21 = *(_DWORD *)(a2 + 36);
        result = AuthzBasepGetNextValue(a2 + 28, &v23, v19, v20);
        if ( result == -2147483622 )
          break;
        if ( result < 0 )
          goto LABEL_58;
        if ( *(_WORD *)a2 == 4 )
        {
          result = AuthzBasepGetNextValue(a2 + 28, v29, v22, 4);
          if ( result < 0 )
            goto LABEL_58;
          v24 = *(_BYTE *)(a2 + 32);
          v23 = *(_WORD *)(a2 + 28);
          v26 = *(_DWORD *)(a2 + 44);
          v25 = 0;
          v27 = *(_DWORD *)(a2 + 36);
          v28 = *(_DWORD *)(a2 + 52) + v21;
        }
        ++v7;
        result = ((int (__fastcall *)(__int16 *, int, int *, _DWORD))AuthzBasepValueInSet)(&v23, a2, v5, 0);
        if ( result < 0 )
          goto LABEL_58;
        v20 = *v5;
        if ( *v5 != 1 )
          return result;
      }
      result = 0;
      if ( v6 != v7 )
        *v5 = 0;
      return result;
    }
LABEL_43:
    if ( !*(_BYTE *)(a2 + 32) && v18 != 1 && *(_DWORD *)(a2 + 4) == 1 )
      return result;
    goto LABEL_46;
  }
  if ( a1 != 1 )
  {
    if ( a1 != 2 )
      return result;
    v9 = 1;
    while ( 1 )
    {
      v10 = *(_DWORD *)(a2 + 8);
      result = AuthzBasepGetNextValue(a2, &v23, a3, v9);
      if ( result == -2147483622 )
        goto LABEL_13;
      if ( result < 0 )
        goto LABEL_58;
      if ( *(_WORD *)(a2 + 28) == 4 )
      {
        result = AuthzBasepGetNextValue(a2, v29, v11, 4);
        if ( result < 0 )
          goto LABEL_58;
        v24 = *(_BYTE *)(a2 + 4);
        v23 = *(_WORD *)a2;
        v26 = *(_DWORD *)(a2 + 16);
        v25 = 0;
        v27 = *(_DWORD *)(a2 + 8);
        v28 = *(_DWORD *)(a2 + 24) + v10;
      }
      result = ((int (__fastcall *)(__int16 *, int, int *, int))AuthzBasepValueInSet)(&v23, a2 + 28, v5, 1);
      if ( result < 0 )
        goto LABEL_58;
      v9 = *v5;
      if ( *v5 )
        return result;
    }
  }
  if ( *(_DWORD *)(a2 + 12) == 1
    || *(_DWORD *)(a2 + 40) == 1
    || (a3 = *(int **)(a2 + 4), (unsigned int)a3 >= *(_DWORD *)(a2 + 32)) )
  {
    v12 = 1;
    while ( 1 )
    {
      v13 = *(_DWORD *)(a2 + 36);
      result = AuthzBasepGetNextValue(a2 + 28, &v23, a3, v12);
      if ( result == -2147483622 )
        break;
      if ( result < 0 )
        goto LABEL_58;
      if ( *(_WORD *)a2 == 4 )
      {
        result = AuthzBasepGetNextValue(a2 + 28, v29, v14, 4);
        if ( result < 0 )
          goto LABEL_58;
        v24 = *(_BYTE *)(a2 + 32);
        v23 = *(_WORD *)(a2 + 28);
        v26 = *(_DWORD *)(a2 + 44);
        v25 = 0;
        v27 = *(_DWORD *)(a2 + 36);
        v28 = *(_DWORD *)(a2 + 52) + v13;
      }
      result = ((int (__fastcall *)(__int16 *, int, int *, _DWORD))AuthzBasepValueInSet)(&v23, a2, v5, 0);
      if ( result < 0 )
        goto LABEL_58;
      v12 = *v5;
      if ( *v5 != 1 )
        return result;
    }
LABEL_13:
    result = 0;
  }
  return result;
}
