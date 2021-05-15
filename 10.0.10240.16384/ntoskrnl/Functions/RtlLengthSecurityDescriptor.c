// RtlLengthSecurityDescriptor 
 
unsigned int __fastcall RtlLengthSecurityDescriptor(int a1)
{
  __int16 v1; // r2
  unsigned int v2; // r1
  int v3; // r3
  int v4; // r3
  int v5; // r3
  int v6; // r3
  int v7; // r3
  int v8; // r3
  int v9; // r3
  int v10; // r3

  v1 = *(_WORD *)(a1 + 2);
  v2 = 20;
  if ( (v1 & 0x8000) != 0 )
  {
    v3 = *(_DWORD *)(a1 + 4);
    if ( !v3 )
      goto LABEL_6;
    v4 = v3 + a1;
  }
  else
  {
    v4 = *(_DWORD *)(a1 + 4);
  }
  if ( v4 )
    v2 = ((4 * *(unsigned __int8 *)(v4 + 1) + 11) & 0xFFFFFFFC) + 20;
LABEL_6:
  if ( (*(_WORD *)(a1 + 2) & 0x8000) != 0 )
  {
    v5 = *(_DWORD *)(a1 + 8);
    if ( !v5 )
      goto LABEL_11;
    v6 = v5 + a1;
  }
  else
  {
    v6 = *(_DWORD *)(a1 + 8);
  }
  if ( v6 )
    v2 += (4 * *(unsigned __int8 *)(v6 + 1) + 11) & 0xFFFFFFFC;
LABEL_11:
  if ( (v1 & 4) == 0 )
    goto LABEL_17;
  if ( (*(_WORD *)(a1 + 2) & 0x8000) != 0 )
  {
    v7 = *(_DWORD *)(a1 + 16);
    if ( !v7 )
      goto LABEL_17;
    v8 = v7 + a1;
  }
  else
  {
    v8 = *(_DWORD *)(a1 + 16);
  }
  if ( v8 )
    v2 += (*(unsigned __int16 *)(v8 + 2) + 3) & 0xFFFFFFFC;
LABEL_17:
  if ( (v1 & 0x10) == 0 )
    return v2;
  if ( (*(_WORD *)(a1 + 2) & 0x8000) != 0 )
  {
    v9 = *(_DWORD *)(a1 + 12);
    if ( !v9 )
      return v2;
    v10 = v9 + a1;
  }
  else
  {
    v10 = *(_DWORD *)(a1 + 12);
  }
  if ( !v10 )
    return v2;
  return ((*(unsigned __int16 *)(v10 + 2) + 3) & 0xFFFFFFFC) + v2;
}
