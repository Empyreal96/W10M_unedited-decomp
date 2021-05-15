// KiFindReadyThread 
 
int __fastcall KiFindReadyThread(_DWORD *a1, int a2, int a3, unsigned int a4)
{
  int v7; // lr
  int v8; // r8
  int v9; // r10
  unsigned int v10; // r3
  _DWORD *v11; // r1
  unsigned int v12; // r2
  int v13; // r0
  int result; // r0
  int v15; // r2
  int v16; // r2
  __int64 v17; // kr00_8
  _DWORD *v18; // r3
  char v19; // [sp+0h] [bp-28h]

  if ( a2 )
    v7 = a2 + 2048;
  else
    v7 = a3 + 8;
  v8 = a1[262];
  v9 = 64;
LABEL_4:
  v10 = __clz(a4);
  v19 = 31 - v10;
  v11 = *(_DWORD **)(v7 + 8 * (31 - v10));
  a4 ^= 1 << (31 - v10);
  while ( 1 )
  {
    v12 = *((unsigned __int8 *)v11 - 59);
    v13 = v11[53];
    if ( v12 >= 5 )
      return sub_51ED84(v13);
    if ( *((_BYTE *)v11 - 59) && (*(_DWORD *)(a1[590] + 8 * v12 + 296) & v13) != 0 )
      v13 &= *(_DWORD *)(a1[590] + 8 * v12 + 296);
    if ( (v13 & v8) == 0 )
      goto LABEL_19;
    v15 = *(v11 - 19);
    if ( !v15 )
      break;
    v16 = v15 + a1[588];
    if ( !v16 )
      break;
    while ( (*(_BYTE *)(v16 + 92) & 2) == 0 )
    {
      v16 = *(_DWORD *)(v16 + 236);
      if ( !v16 )
        goto LABEL_13;
    }
LABEL_19:
    v11 = (_DWORD *)*v11;
    --v9;
    if ( v11 == (_DWORD *)(v7 + 8 * (31 - v10)) || !v9 )
    {
      if ( !a4 )
        return 0;
      if ( !v9 )
        return 0;
      goto LABEL_4;
    }
  }
LABEL_13:
  v17 = *(_QWORD *)v11;
  v18 = *(_DWORD **)(*v11 + 4);
  if ( a2 )
  {
    if ( v18 != v11 || *(_DWORD **)HIDWORD(v17) != v11 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v17) = v17;
    *(_DWORD *)(v17 + 4) = HIDWORD(v17);
    if ( HIDWORD(v17) == (_DWORD)v17 )
      *(_DWORD *)(a2 + 1932) ^= 1 << v19;
  }
  else
  {
    if ( v18 != v11 || *(_DWORD **)HIDWORD(v17) != v11 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v17) = v17;
    *(_DWORD *)(v17 + 4) = HIDWORD(v17);
    if ( HIDWORD(v17) == (_DWORD)v17 )
      *(_DWORD *)(a3 + 4) ^= 1 << v19;
  }
  result = (int)(v11 - 36);
  v11[46] = a1[5];
  return result;
}
