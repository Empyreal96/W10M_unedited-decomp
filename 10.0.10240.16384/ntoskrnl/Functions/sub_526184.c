// sub_526184 
 
void sub_526184()
{
  int v0; // r5
  int v1; // r6
  int v2; // r9
  unsigned int v3; // r2
  unsigned int v4; // r1
  _DWORD *i; // r3
  int v6; // r3
  int v7; // r2
  int v8; // r3
  unsigned int v9; // r0
  unsigned int v10; // r3
  int v11; // r4
  int v12; // r3
  int *v13; // r0

  v3 = v1 + 80;
  v4 = *(_DWORD *)(v1 + 84);
  if ( v4 )
  {
    for ( i = *(_DWORD **)v4; i; i = (_DWORD *)*i )
      v4 = (unsigned int)i;
  }
  else
  {
    v6 = *(_DWORD *)(v1 + 88);
    while ( 1 )
    {
      v4 = v6 & 0xFFFFFFFC;
      if ( (v6 & 0xFFFFFFFC) == 0 || *(_DWORD *)v4 == v3 )
        break;
      v6 = *(_DWORD *)(v4 + 8);
      v3 = v4;
    }
  }
  if ( !v4 )
LABEL_30:
    JUMPOUT(0x46123A);
  v7 = *(_DWORD *)(v1 + 96);
  v8 = v7 - *(_DWORD *)(v4 + 16);
  if ( !v8 )
  {
    if ( *(_WORD *)(v1 + 94) )
    {
      v9 = 31 - __clz(*(unsigned __int16 *)(v1 + 94));
      v10 = 0;
      if ( *(_WORD *)(v4 + 14) )
        v10 = 31 - __clz(*(unsigned __int16 *)(v4 + 14));
      v8 = v10 - v9;
    }
    else
    {
      if ( !v7 )
      {
        if ( *(_QWORD *)v1 <= *(_QWORD *)(v4 - 80) )
          goto LABEL_30;
        goto LABEL_21;
      }
      v8 = 1;
    }
  }
  if ( v8 <= 0 )
    goto LABEL_30;
LABEL_21:
  v11 = v1;
  do
  {
    v12 = *(_DWORD *)(v11 + 236);
    if ( v12 )
      v13 = (int *)(v12 + 228);
    else
      v13 = (int *)(v2 + v0);
    *(_BYTE *)(v11 + 92) &= 0xFEu;
    RtlRbRemoveNode(v13, (_DWORD *)(v11 + 80));
    v11 = *(_DWORD *)(v11 + 236);
  }
  while ( v11 && (*(_BYTE *)(v11 + 92) & 1) != 0 && !*(_DWORD *)(v11 + 228) && !*(_WORD *)(v11 + 94) );
  KiInsertSchedulingGroupQueue(v2, v1, 0);
  goto LABEL_30;
}
