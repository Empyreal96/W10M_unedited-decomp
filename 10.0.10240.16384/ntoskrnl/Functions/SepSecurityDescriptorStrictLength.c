// SepSecurityDescriptorStrictLength 
 
int __fastcall SepSecurityDescriptorStrictLength(int a1)
{
  __int16 v1; // r2
  BOOL v2; // r6
  int v3; // r5
  unsigned int v4; // r1
  int v5; // r3
  int v6; // r4
  unsigned int v7; // r3
  int v8; // r3
  int v9; // r4
  unsigned int v10; // r3
  unsigned int v11; // r3
  int v12; // r3
  int v13; // r4
  unsigned int v14; // r3
  unsigned int v15; // r3
  int v16; // r3
  int v17; // r2
  unsigned int v18; // r3
  unsigned int v19; // r3

  v1 = *(_WORD *)(a1 + 2);
  v2 = (v1 & 0x8000) != 0;
  v3 = 20;
  v4 = a1 + 20;
  if ( (v1 & 0x8000) != 0 )
  {
    v5 = *(_DWORD *)(a1 + 4);
    if ( !v5 )
      goto LABEL_7;
    v6 = v5 + a1;
  }
  else
  {
    v6 = *(_DWORD *)(a1 + 4);
  }
  if ( v6 )
  {
    v7 = (4 * *(unsigned __int8 *)(v6 + 1) + 11) & 0xFFFFFFFC;
    v3 = v7 + 20;
    v4 = v7 + v6;
  }
LABEL_7:
  if ( (*(_WORD *)(a1 + 2) & 0x8000) != 0 )
  {
    v8 = *(_DWORD *)(a1 + 8);
    if ( !v8 )
      goto LABEL_14;
    v9 = v8 + a1;
  }
  else
  {
    v9 = *(_DWORD *)(a1 + 8);
  }
  if ( v9 )
  {
    v10 = (4 * *(unsigned __int8 *)(v9 + 1) + 11) & 0xFFFFFFFC;
    v3 += v10;
    v11 = v10 + v9;
    if ( v11 > v4 )
      v4 = v11;
  }
LABEL_14:
  if ( (v1 & 4) == 0 )
    goto LABEL_22;
  if ( (*(_WORD *)(a1 + 2) & 0x8000) != 0 )
  {
    v12 = *(_DWORD *)(a1 + 16);
    if ( !v12 )
      goto LABEL_22;
    v13 = v12 + a1;
  }
  else
  {
    v13 = *(_DWORD *)(a1 + 16);
  }
  if ( v13 )
  {
    v14 = (*(unsigned __int16 *)(v13 + 2) + 3) & 0xFFFFFFFC;
    v3 += v14;
    v15 = v14 + v13;
    if ( v15 > v4 )
      v4 = v15;
  }
LABEL_22:
  if ( (v1 & 0x10) == 0 )
    goto LABEL_30;
  if ( (*(_WORD *)(a1 + 2) & 0x8000) != 0 )
  {
    v16 = *(_DWORD *)(a1 + 12);
    if ( !v16 )
      goto LABEL_30;
    v17 = v16 + a1;
  }
  else
  {
    v17 = *(_DWORD *)(a1 + 12);
  }
  if ( v17 )
  {
    v18 = (*(unsigned __int16 *)(v17 + 2) + 3) & 0xFFFFFFFC;
    v3 += v18;
    v19 = v18 + v17;
    if ( v19 > v4 )
      v4 = v19;
  }
LABEL_30:
  if ( v2 )
    v3 = v4 - a1;
  return v3;
}
