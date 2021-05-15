// PpmInfoWriteData 
 
int __fastcall PpmInfoWriteData(unsigned __int8 *a1, unsigned int a2, int a3, int a4, int a5)
{
  __int64 v6; // kr00_8
  char v7; // r7
  int result; // r0
  _BYTE *v10; // r4
  unsigned int v11; // r2
  int v12; // r6
  unsigned int v13; // r2
  _BYTE *v14; // r7
  unsigned int v15; // r9

  v6 = *(_QWORD *)(a4 + 16);
  v7 = *(_BYTE *)(a4 + 25);
  result = 0;
  v10 = (_BYTE *)(v6 + HIDWORD(v6) * a3 + a5);
  if ( (v7 & 8) == 0 )
  {
    if ( HIDWORD(v6) == 1 )
    {
      v11 = *a1;
      v12 = (unsigned __int8)*v10;
      if ( v11 < *(_DWORD *)(a4 + 8) )
      {
        v11 = *(_DWORD *)(a4 + 8);
      }
      else if ( v11 > *(_DWORD *)(a4 + 12) )
      {
        return sub_7C369C(0);
      }
      *v10 = v11;
      return v12 != v11;
    }
    v11 = *(_DWORD *)a1;
    v12 = *(_DWORD *)v10;
    if ( *(_DWORD *)a1 >= *(_DWORD *)(a4 + 8) )
    {
      if ( v11 <= *(_DWORD *)(a4 + 12) )
      {
LABEL_11:
        *(_DWORD *)v10 = v11;
        return v12 != v11;
      }
      if ( (v7 & 0x10) == 0 )
      {
        v11 = *(_DWORD *)(a4 + 12);
        goto LABEL_11;
      }
    }
    v11 = *(_DWORD *)(a4 + 8);
    goto LABEL_11;
  }
  if ( a2 >= HIDWORD(v6) )
    a2 = HIDWORD(v6);
  v13 = 0;
  if ( a2 )
  {
    v14 = v10;
    v15 = a2;
    while ( 1 )
    {
      v13 = (unsigned __int8)v14[a1 - v10];
      if ( v13 < *(_DWORD *)(a4 + 8) )
        goto LABEL_27;
      if ( v13 > *(_DWORD *)(a4 + 12) )
        break;
LABEL_18:
      if ( (unsigned __int8)*v14 != v13 )
      {
        result = 1;
        *v14 = v13;
      }
      ++v14;
      if ( !--v15 )
        goto LABEL_21;
    }
    if ( (*(_BYTE *)(a4 + 25) & 0x10) == 0 )
    {
      v13 = *(_DWORD *)(a4 + 12);
      goto LABEL_18;
    }
LABEL_27:
    v13 = *(_DWORD *)(a4 + 8);
    goto LABEL_18;
  }
LABEL_21:
  while ( a2 < HIDWORD(v6) )
  {
    if ( (unsigned __int8)v10[a2] != v13 )
    {
      result = 1;
      v10[a2] = v13;
    }
    ++a2;
  }
  return result;
}
