// SwapSplayLinks 
 
_DWORD *__fastcall SwapSplayLinks(_DWORD *result, _DWORD *a2)
{
  _DWORD *v2; // r2
  int v3; // r2
  int v4; // r2
  int v5; // r3
  int v6; // r2
  _DWORD *v7; // r3
  _DWORD *v8; // r3
  _DWORD *v9; // r3
  _DWORD *v10; // r3
  int v11; // r4
  _DWORD *v12; // r3
  _DWORD *v13; // r3
  int v14; // r2
  int v15; // r3
  int v16; // r2
  _DWORD *v17; // r3
  int *v18; // r5
  int *v19; // r4
  int v20; // r2
  _DWORD *v21; // r2
  _DWORD *v22; // r3

  if ( (_DWORD *)*result == result || (_DWORD *)*a2 == result )
  {
    v22 = result;
    result = a2;
    a2 = v22;
  }
  v2 = (_DWORD *)*result;
  if ( (_DWORD *)*result == a2 )
  {
    v3 = *a2;
    if ( (_DWORD *)*a2 == a2 )
    {
      *result = result;
    }
    else
    {
      if ( *(_DWORD **)(v3 + 4) == a2 )
        v17 = (_DWORD *)(v3 + 4);
      else
        v17 = (_DWORD *)(v3 + 8);
      *v17 = result;
      *result = *a2;
    }
    v4 = result[1];
    result[1] = a2[1];
    v5 = a2[2];
    a2[1] = v4;
    v6 = result[2];
    result[2] = v5;
    a2[2] = v6;
    if ( (_DWORD *)result[1] == result )
      result[1] = a2;
    else
      result[2] = a2;
  }
  else
  {
    v11 = *a2;
    v12 = (_DWORD *)v2[1];
    if ( (_DWORD *)*a2 == a2 )
    {
      if ( v12 == result )
        v13 = v2 + 1;
      else
        v13 = v2 + 2;
      *v13 = a2;
      *a2 = *result;
      *result = result;
    }
    else
    {
      if ( v12 == result )
        v18 = v2 + 1;
      else
        v18 = v2 + 2;
      if ( *(_DWORD **)(v11 + 4) == a2 )
        v19 = (int *)(v11 + 4);
      else
        v19 = (int *)(v11 + 8);
      v20 = *v18;
      *v18 = *v19;
      *v19 = v20;
      v21 = (_DWORD *)*result;
      *result = *a2;
      *a2 = v21;
    }
    v14 = result[1];
    result[1] = a2[1];
    v15 = a2[2];
    a2[1] = v14;
    v16 = result[2];
    result[2] = v15;
    a2[2] = v16;
  }
  v7 = (_DWORD *)result[1];
  if ( v7 )
    *v7 = result;
  v8 = (_DWORD *)result[2];
  if ( v8 )
    *v8 = result;
  v9 = (_DWORD *)a2[1];
  if ( v9 )
    *v9 = a2;
  v10 = (_DWORD *)a2[2];
  if ( v10 )
    *v10 = a2;
  return result;
}
