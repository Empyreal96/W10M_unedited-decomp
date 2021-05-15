// KiVerifyXcpt10 
 
int KiVerifyXcpt10(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r4
  int v5; // r3
  unsigned int *v6; // r2
  unsigned int v7; // r1
  int v8; // r3
  unsigned int *v9; // r2
  unsigned int v10; // r1
  int v11; // r3
  unsigned int *v12; // r2
  unsigned int v13; // r1
  int v14; // r3
  unsigned int *v15; // r2
  unsigned int v16; // r1
  unsigned int v17; // r1
  int v18; // r3
  unsigned int *v19; // r2
  unsigned int v20; // r1
  int result; // r0
  va_list va; // [sp+20h] [bp+10h] BYREF

  va_start(va, a4);
  v4 = a1;
  if ( *(_DWORD *)(a1 + 4) == 1 )
  {
    for ( *(_DWORD *)(a1 + 8) = 1; ; *(_DWORD *)(a1 + 8) = 0 )
    {
      v5 = *(_DWORD *)(a1 + 8);
      if ( !v5 )
        break;
      if ( v5 == 11 )
        _jump_unwind((int)va, (int)&loc_95DD18 + 1);
      if ( v5 == 1 )
        _jump_unwind((int)va, (int)&loc_95DBF2 + 1);
    }
    *(_DWORD *)(a1 + 8) = 11;
    v6 = *(unsigned int **)a1;
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 + 1, v6) );
    v8 = *(_DWORD *)(a1 + 8) + 11;
    *(_DWORD *)(a1 + 8) = v8;
    if ( v8 == 99 )
      _jump_unwind((int)va, (int)&loc_95DD18 + 1);
    v9 = *(unsigned int **)a1;
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 + 1, v9) );
    v11 = *(_DWORD *)(a1 + 8) + 11;
    *(_DWORD *)(a1 + 8) = v11;
    if ( v11 == 55 )
    {
      *(_DWORD *)(a1 + 8) = 66;
    }
    else
    {
      v12 = *(unsigned int **)a1;
      do
        v13 = __ldrex(v12);
      while ( __strex(v13 + 1, v12) );
    }
    v14 = *(_DWORD *)(a1 + 8) + 11;
    *(_DWORD *)(a1 + 8) = v14;
    if ( v14 != 99 )
      _jump_unwind((int)va, (int)&loc_95DD18 + 1);
    v15 = *(unsigned int **)a1;
    do
    {
      v16 = __ldrex(v15);
      v17 = v16 + 1;
    }
    while ( __strex(v17, v15) );
    v18 = *(_DWORD *)(a1 + 8) + 11;
    *(_DWORD *)(a1 + 8) = v18;
    if ( v18 == 99 )
    {
      v19 = *(unsigned int **)a1;
      do
        v20 = __ldrex(v19);
      while ( __strex(v20 + 1, v19) );
    }
    else
    {
      KiVerifyXcptFilter(a1, v17);
    }
    v4 = a1;
  }
  else
  {
    *(_DWORD *)(a1 + 8) = -1;
    *(_DWORD *)(a1 + 12) = 1;
  }
  result = *(_DWORD *)(v4 + 8);
  *(_QWORD *)(v4 + 16) += result;
  return result;
}
