// EtwpAllocateStringFilterData 
 
int __fastcall EtwpAllocateStringFilterData(int *a1, _DWORD *a2)
{
  unsigned int v2; // r3
  int v3; // r6
  int v5; // r7
  int v6; // r8
  unsigned int v7; // r2
  unsigned int v8; // r4
  unsigned __int16 *v9; // r1
  int v10; // r3
  int v11; // t1
  int v12; // r9
  unsigned __int16 *v13; // r0
  unsigned __int16 *v14; // r5
  unsigned __int16 *v15; // r7
  unsigned int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // lr
  unsigned __int16 *v19; // r2

  v2 = a1[2];
  v3 = 0;
  if ( v2 > 0x400 )
    return -1073741811;
  v5 = 1;
  v6 = *a1;
  v7 = 0;
  v8 = v2 >> 1;
  if ( v2 >> 1 )
  {
    v9 = (unsigned __int16 *)*a1;
    do
    {
      v11 = *v9++;
      v10 = v11;
      if ( !v11 )
        break;
      if ( v10 == 59 )
        v5 = (unsigned __int16)(v5 + 1);
      ++v7;
    }
    while ( v7 < v8 );
  }
  if ( v7 < v8 - 1 )
    v8 = v7 + 1;
  v12 = v8 + 4 * v5 + 6;
  v13 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 2 * v12, 1182233669);
  v14 = v13;
  if ( !v13 )
    return -1073741801;
  memset(v13, 0, 2 * v12);
  *v14 = v5;
  v15 = &v14[4 * v5 + 6];
  memmove((int)v15, v6, 2 * v8);
  v16 = 1;
  v17 = 0;
  v18 = 0;
  for ( *((_DWORD *)v14 + 2) = v15; v17 < v8; ++v15 )
  {
    if ( !*v15 || v16 >= *v14 )
      break;
    if ( *v15 == 59 )
    {
      *v15 = 0;
      v19 = &v14[4 * v16];
      *(v19 - 2) = v17 - v18;
      *((_DWORD *)v19 + 2) = v15 + 1;
      v16 = (unsigned __int16)(v16 + 1);
      v18 = v17 + 1;
    }
    ++v17;
  }
  v14[4 * v16 - 2] = v8 - v18 - 1;
  *a2 = v14;
  return v3;
}
