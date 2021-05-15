// SmKmGetCacheStatsBucketIndex 
 
unsigned int __fastcall SmKmGetCacheStatsBucketIndex(int a1, unsigned int *a2, int a3, int a4)
{
  unsigned int v4; // r5
  int v6; // r9
  unsigned int v7; // r6
  int v8; // r7
  unsigned int v9; // r10
  int *v10; // r4
  unsigned int *v11; // r5
  unsigned int v12; // r0
  unsigned int v13; // r1
  int v14; // r4
  unsigned int v15; // r4
  unsigned int v16; // r1
  _DWORD *v17; // r0
  unsigned int v18; // r4
  unsigned int v19; // r1
  unsigned int result; // r0
  unsigned int v21; // t1
  unsigned int v22; // [sp+0h] [bp-28h]
  int v23; // [sp+4h] [bp-24h] BYREF
  int v24[8]; // [sp+8h] [bp-20h] BYREF

  v23 = a3;
  v24[0] = a4;
  v4 = 0;
  v22 = 0;
  v6 = a1;
  v7 = 0;
  v8 = a1;
  do
  {
    if ( (*(_WORD *)(v8 + 12) & 0x800) == 0 )
      goto LABEL_23;
    v9 = v7 | (32 * (*(_WORD *)(v8 + 12) & 0x7FF));
    v10 = (int *)(v6 + 96 * (v9 & 0x1F));
    v11 = (unsigned int *)(v10 + 1);
    __pld(v10 + 1);
    v12 = v10[1] & 0xFFFFFFFE;
    do
      v13 = __ldrex(v11);
    while ( v13 == v12 && __strex(v12 + 2, v11) );
    __dmb(0xBu);
    if ( v13 == v12 || ExfAcquireRundownProtection(v10 + 1) )
    {
      if ( (v10[3] & 0x7FF) == v9 >> 5 )
      {
        v14 = *v10;
        goto LABEL_16;
      }
      __pld(v11);
      v15 = *v11 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v16 = __ldrex(v11);
      while ( v16 == v15 && __strex(v15 - 2, v11) );
      if ( v16 != v15 )
        ExfReleaseRundownProtection((unsigned __int8 *)v11);
    }
    v14 = 0;
LABEL_16:
    if ( v14 )
    {
      ST_STORE<SM_TRAITS>::StDmGetSpaceStats(v14 + 56, v24, &v23);
      v4 = v22 + (*(_DWORD *)(v14 + 184) << (*(_DWORD *)(v14 + 28) - 6) >> 10);
      v17 = (_DWORD *)(v6 + 96 * (v7 & 0x1F) + 4);
      __pld(v17);
      v22 = v4;
      v18 = *v17 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v19 = __ldrex(v17);
      while ( v19 == v18 && __strex(v18 - 2, v17) );
      if ( v19 != v18 )
        ExfReleaseRundownProtection((unsigned __int8 *)v17);
    }
    else
    {
      v4 = v22;
    }
LABEL_23:
    ++v7;
    v8 += 96;
  }
  while ( v7 < 0x20 );
  for ( result = 0; result < 8; ++result )
  {
    v21 = *a2++;
    if ( v4 <= v21 )
      break;
  }
  return result;
}
