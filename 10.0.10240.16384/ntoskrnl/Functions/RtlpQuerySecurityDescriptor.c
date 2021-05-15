// RtlpQuerySecurityDescriptor 
 
int __fastcall RtlpQuerySecurityDescriptor(int result, _DWORD *a2, unsigned int *a3, _DWORD *a4, unsigned int *a5, _DWORD *a6, unsigned int *a7, _DWORD *a8, unsigned int *a9)
{
  __int16 v9; // r5
  int v11; // r4
  int v12; // r2
  int v13; // r3
  int v14; // r2
  int v15; // r4
  int v16; // r3
  int v17; // r3

  v9 = *(_WORD *)(result + 2);
  if ( (v9 & 0x8000) != 0 )
  {
    v15 = *(_DWORD *)(result + 4);
    if ( v15 )
      v11 = v15 + result;
    else
      v11 = 0;
  }
  else
  {
    v11 = *(_DWORD *)(result + 4);
  }
  *a2 = v11;
  if ( v11 )
    *a3 = (4 * *(unsigned __int8 *)(v11 + 1) + 11) & 0xFFFFFFFC;
  else
    *a3 = 0;
  if ( (v9 & 4) == 0 )
    goto LABEL_31;
  if ( (v9 & 0x8000) == 0 )
  {
    v12 = *(_DWORD *)(result + 16);
    goto LABEL_8;
  }
  v16 = *(_DWORD *)(result + 16);
  if ( v16 )
    v12 = v16 + result;
  else
LABEL_31:
    v12 = 0;
LABEL_8:
  *a6 = v12;
  if ( v12 )
    *a7 = (*(unsigned __int16 *)(v12 + 2) + 3) & 0xFFFFFFFC;
  else
    *a7 = 0;
  if ( (v9 & 0x8000) != 0 )
  {
    v17 = *(_DWORD *)(result + 8);
    if ( v17 )
      v13 = v17 + result;
    else
      v13 = 0;
  }
  else
  {
    v13 = *(_DWORD *)(result + 8);
  }
  *a4 = v13;
  if ( v13 )
    *a5 = (4 * *(unsigned __int8 *)(v13 + 1) + 11) & 0xFFFFFFFC;
  else
    *a5 = 0;
  if ( (v9 & 0x10) != 0 )
  {
    if ( (v9 & 0x8000) != 0 )
      return sub_7DDA68();
    v14 = *(_DWORD *)(result + 12);
  }
  else
  {
    v14 = 0;
  }
  *a8 = v14;
  if ( v14 )
    *a9 = (*(unsigned __int16 *)(v14 + 2) + 3) & 0xFFFFFFFC;
  else
    *a9 = 0;
  return result;
}
