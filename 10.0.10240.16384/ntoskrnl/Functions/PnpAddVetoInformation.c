// PnpAddVetoInformation 
 
_DWORD *__fastcall PnpAddVetoInformation(_DWORD *result, _DWORD *a2, unsigned int a3)
{
  _DWORD *v3; // r7
  unsigned int v5; // r4
  int v6; // r6
  _DWORD *v7; // r5
  int v8; // r2
  int v9; // r8
  unsigned int v10; // r3
  _DWORD *v11; // r3
  _DWORD *v12; // r1
  _DWORD *v13; // r1
  _DWORD *v14; // r2
  int *v15; // r6
  _DWORD *v16; // r1
  _DWORD *v17; // r2

  v3 = a2;
  v5 = 0;
  v6 = *a2 - 12;
  v7 = 0;
  v8 = 1;
  v9 = (int)result;
  if ( a2 == (_DWORD *)*a2 )
    goto LABEL_15;
  while ( 1 )
  {
    v10 = *(_DWORD *)(v6 + 8);
    if ( v10 == a3 )
    {
      v11 = *(_DWORD **)v6;
      v7 = (_DWORD *)v6;
      v8 = 0;
      while ( 1 )
      {
        v12 = v11 - 1;
        if ( (_DWORD *)v6 == v11 )
          goto LABEL_11;
        if ( (_DWORD *)*v12 == result )
          return result;
        if ( *v12 > (unsigned int)result )
        {
          v7 = v11;
          goto LABEL_11;
        }
        v11 = (_DWORD *)*v11;
      }
    }
    if ( v10 > a3 )
      break;
LABEL_11:
    v6 = *(_DWORD *)(v6 + 12) - 12;
    if ( v3 == (_DWORD *)(v6 + 12) )
      goto LABEL_14;
  }
  v3 = (_DWORD *)(v6 + 12);
LABEL_14:
  if ( v8 )
  {
LABEL_15:
    result = (_DWORD *)ExAllocatePoolWithTag(1, 20, 1332768336);
    v5 = (unsigned int)result;
    if ( result )
    {
      result[2] = a3;
      v13 = (_DWORD *)v3[1];
      v14 = result + 3;
      result[3] = v3;
      result[4] = v13;
      if ( (_DWORD *)*v13 != v3 )
        __fastfail(3u);
      *v13 = v14;
      v3[1] = v14;
      *result = result;
      result[1] = result;
      v7 = result;
      goto LABEL_19;
    }
  }
  else
  {
LABEL_19:
    result = (_DWORD *)ExAllocatePoolWithTag(1, 12, 1349545552);
    v15 = result;
    if ( result )
    {
      result = (_DWORD *)ObfReferenceObject(v9);
      *v15 = v9;
      v16 = (_DWORD *)v7[1];
      v17 = v15 + 1;
      v15[1] = (int)v7;
      v15[2] = (int)v16;
      if ( (_DWORD *)*v16 != v7 )
        __fastfail(3u);
      *v16 = v17;
      v7[1] = v17;
    }
    else if ( v5 )
    {
      result = (_DWORD *)ExFreePoolWithTag(v5);
    }
  }
  return result;
}
