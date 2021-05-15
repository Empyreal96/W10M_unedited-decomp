// SeValidSecurityDescriptor 
 
int __fastcall SeValidSecurityDescriptor(unsigned int a1, int a2)
{
  unsigned int v4; // r2
  unsigned int v5; // r1
  _BYTE *v6; // r2
  unsigned int v7; // r3
  unsigned int v8; // r2
  unsigned int v9; // r1
  _BYTE *v10; // r2
  unsigned int v11; // r3
  unsigned int v12; // r2
  unsigned int v13; // r2
  int result; // r0

  if ( a1 < 0x14 )
    goto LABEL_31;
  if ( *(_BYTE *)a2 != 1 )
    goto LABEL_31;
  if ( (*(_WORD *)(a2 + 2) & 0x8000) == 0 )
    goto LABEL_31;
  v4 = *(_DWORD *)(a2 + 4);
  if ( !v4 )
    goto LABEL_31;
  if ( ((v4 + 3) & 0xFFFFFFFC) != v4 )
    goto LABEL_31;
  if ( v4 > a1 )
    goto LABEL_31;
  v5 = a1 - v4;
  if ( a1 - v4 < 0xC )
    goto LABEL_31;
  v6 = (_BYTE *)(v4 + a2);
  if ( *v6 != 1 )
    goto LABEL_31;
  v7 = (unsigned __int8)v6[1];
  if ( v7 > 0xF )
    goto LABEL_31;
  if ( v5 < 4 * (v7 + 2) )
    goto LABEL_31;
  v8 = *(_DWORD *)(a2 + 8);
  if ( v8 )
  {
    if ( ((v8 + 3) & 0xFFFFFFFC) != v8 )
      goto LABEL_31;
    if ( v8 > a1 )
      goto LABEL_31;
    v9 = a1 - v8;
    if ( a1 - v8 < 0xC )
      goto LABEL_31;
    v10 = (_BYTE *)(v8 + a2);
    if ( *v10 != 1 )
      goto LABEL_31;
    v11 = (unsigned __int8)v10[1];
    if ( v11 > 0xF || v9 < 4 * (v11 + 2) )
      goto LABEL_31;
  }
  if ( ((v12 = *(_DWORD *)(a2 + 16)) == 0
     || ((v12 + 3) & 0xFFFFFFFC) == v12
     && v12 <= a1
     && a1 - v12 >= 8
     && a1 - v12 >= *(unsigned __int16 *)(v12 + a2 + 2)
     && RtlValidAcl((unsigned __int8 *)(v12 + a2)))
    && ((v13 = *(_DWORD *)(a2 + 12)) == 0
     || ((v13 + 3) & 0xFFFFFFFC) == v13
     && v13 <= a1
     && a1 - v13 >= 8
     && a1 - v13 >= *(unsigned __int16 *)(v13 + a2 + 2)
     && RtlValidAcl((unsigned __int8 *)(v13 + a2))) )
  {
    result = 1;
  }
  else
  {
LABEL_31:
    result = 0;
  }
  return result;
}
