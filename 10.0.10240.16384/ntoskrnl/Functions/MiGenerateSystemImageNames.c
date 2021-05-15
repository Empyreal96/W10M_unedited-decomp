// MiGenerateSystemImageNames 
 
int __fastcall MiGenerateSystemImageNames(_DWORD *a1, unsigned __int16 *a2, _DWORD *a3, int a4, unsigned __int16 *a5, int a6)
{
  _WORD *v7; // r2
  int result; // r0
  int v11; // r3
  _WORD *v12; // r6
  unsigned __int16 v13; // r3
  unsigned int v14; // r2
  unsigned int v15; // r1
  unsigned int v16; // r3
  int v17; // r1
  int v18; // r0

  v7 = (_WORD *)a1[1];
  if ( *v7 != 92 )
    return sub_7CDA38();
  v11 = *(unsigned __int16 *)a1 >> 1;
  v12 = &v7[v11];
  if ( *(v12 - 1) == 92 )
  {
LABEL_6:
    *(_WORD *)a4 = 2 * (((int)v7 + 2 * v11 - (int)v12) >> 1);
    *(_DWORD *)(a4 + 4) = v12;
    *(_WORD *)(a4 + 2) = *(_WORD *)a4;
    *(_DWORD *)a5 = *a1;
    *((_DWORD *)a5 + 1) = a1[1];
    v13 = *a5 - *(_WORD *)a4;
    *a5 = v13;
    a5[1] = v13;
    *(_DWORD *)a6 = *a1;
    *(_DWORD *)(a6 + 4) = a1[1];
    if ( a2 )
    {
      v14 = *a5;
      *(_WORD *)(a6 + 2) = v14;
      v15 = (unsigned __int16)(*a2 + v14);
      if ( v15 < v14 )
        return -1073741670;
      *(_WORD *)(a6 + 2) = v15;
      v16 = (unsigned __int16)(*(_WORD *)a4 + v15);
      if ( v16 < v15 )
        return -1073741670;
      v17 = (unsigned __int16)(*(_WORD *)a4 + v15);
      *(_WORD *)(a6 + 2) = v16;
      v18 = ExAllocatePoolWithTag(1, v17, 1682730317);
      *(_DWORD *)(a6 + 4) = v18;
      if ( !v18 )
        return -1073741670;
      *(_WORD *)a6 = 0;
      RtlAppendUnicodeStringToString((unsigned __int16 *)a6, a5);
      RtlAppendUnicodeStringToString((unsigned __int16 *)a6, a2);
      RtlAppendUnicodeStringToString((unsigned __int16 *)a6, (unsigned __int16 *)a4);
      *(_DWORD *)(a4 + 4) = *(_DWORD *)(a6 + 4) + 2 * (*a5 >> 1);
      *(_WORD *)a4 += *a2;
      *(_WORD *)(a4 + 2) += *a2;
    }
    if ( a3 )
    {
      *(_DWORD *)a4 = *a3;
      *(_DWORD *)(a4 + 4) = a3[1];
    }
    result = 0;
  }
  else
  {
    while ( --v12 != v7 )
    {
      if ( *(v12 - 1) == 92 )
        goto LABEL_6;
    }
    result = -1073741585;
  }
  return result;
}
