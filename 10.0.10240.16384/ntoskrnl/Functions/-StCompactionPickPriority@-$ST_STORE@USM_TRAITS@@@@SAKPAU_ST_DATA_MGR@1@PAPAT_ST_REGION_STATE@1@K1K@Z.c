// -StCompactionPickPriority@-$ST_STORE@USM_TRAITS@@@@SAKPAU_ST_DATA_MGR@1@PAPAT_ST_REGION_STATE@1@K1K@Z 
 
unsigned int __fastcall ST_STORE<SM_TRAITS>::StCompactionPickPriority(int a1, char *a2, int a3, int a4)
{
  unsigned __int16 **v8; // r4
  unsigned int v9; // r7
  unsigned int v10; // r4
  int v11; // lr
  int v12; // r6
  unsigned int v13; // r8
  _WORD *v14; // r0
  unsigned int v15; // r5
  int v16; // r1
  unsigned int *v17; // r4
  int v18; // r0
  unsigned int v19; // r2
  unsigned int v20; // t1
  unsigned int v21; // r4
  _DWORD v23[56]; // [sp-4h] [bp-E0h] BYREF

  memset(v23, 0, 192);
  v8 = (unsigned __int16 **)&a2[4 * a3];
  v9 = 0;
  if ( a2 > (char *)v8 )
    v10 = 0;
  else
    v10 = (unsigned int)((char *)v8 - a2 + 3) >> 2;
  if ( v10 )
  {
    v11 = *(unsigned __int8 *)(a1 + 72);
    do
    {
      if ( v11 )
        v12 = 0;
      else
        v12 = **(unsigned __int16 **)a2 >> 13;
      v13 = v23[6 * v12];
      if ( v13 < 4 )
      {
        v14 = *(_WORD **)a2;
        v23[6 * v12] = v13 + 1;
        v23[6 * v12 + 1] += *v14 & 0x1FFF;
        v23[6 * v12 + 2 + v13] = v14;
      }
      ++v9;
      a2 += 4;
    }
    while ( v9 < v10 );
  }
  v15 = 0;
  v16 = 7;
  v17 = &v23[42];
  v18 = -1;
  do
  {
    v20 = *v17;
    v17 -= 6;
    v19 = v20;
    if ( v20 > 1 && v15 < *(_DWORD *)(a1 + 104) * v19 - v17[7] )
    {
      v15 = *(_DWORD *)(a1 + 104) * v19 - v17[7];
      v18 = v16;
    }
    --v16;
  }
  while ( v16 >= 0 );
  v21 = v23[6 * v18];
  if ( v21 > 4 )
    v21 = 4;
  memmove(a4, (int)&v23[6 * v18 + 2], 4 * v21);
  return v21;
}
