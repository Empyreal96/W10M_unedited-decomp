// ViCopyBackModifiedBuffer 
 
int __fastcall ViCopyBackModifiedBuffer(_DWORD *a1, int a2, unsigned __int8 *a3, int a4, unsigned int a5)
{
  unsigned int v5; // r4
  unsigned int v11; // r0
  bool v12; // zf
  unsigned int v13; // r1
  unsigned __int8 *v14; // r5
  int v15; // r2
  int v16; // t1
  unsigned int v17; // r4
  char *v18; // r7
  unsigned int i; // r2
  _DWORD *v20; // r1
  int v21; // r1
  unsigned int v22; // r5
  int v23; // r0

  v5 = a5;
  if ( !a5 )
    return 0;
  v11 = RtlCompareMemory(a3, a4, a5);
  v12 = a5 == v11;
  if ( a5 > v11 )
  {
    v13 = a4 + a5;
    v14 = &a3[-a4];
    do
    {
      v15 = v14[v13 - 1];
      v16 = *(unsigned __int8 *)--v13;
      if ( v15 != v16 )
        break;
      --v5;
    }
    while ( v5 > v11 );
    v12 = v5 == v11;
  }
  if ( v12 )
    return 0;
  v17 = v5 - v11;
  v18 = (char *)&a3[v11];
  for ( i = a1[6] - a2 + a1[5] + a1[4]; v11 >= i; i = v20[5] )
  {
    v20 = (_DWORD *)*a1;
    if ( !*a1 )
      break;
    v11 -= i;
    a1 = (_DWORD *)*a1;
    a2 = v20[6] + v20[4];
  }
  v21 = v11 + a2;
  v22 = v17;
  if ( *a1 )
    v22 = i - v11;
  while ( 1 )
  {
    v23 = ViGetMdlBufferSa(a1, v21);
    if ( !v23 )
      break;
    if ( !*a1 )
    {
      memcpy_strict_align(v23, v18, v17);
      return 0;
    }
    if ( v22 > v17 )
      v22 = v17;
    memcpy_strict_align(v23, v18, v22);
    a1 = (_DWORD *)*a1;
    v18 += v22;
    if ( v22 <= v17 )
      v17 -= v22;
    else
      v17 = 0;
    v22 = a1[5];
    v21 = a1[6] + a1[4];
    if ( !v17 )
      return 0;
  }
  return -1073741823;
}
