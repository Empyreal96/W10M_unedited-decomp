// ExpAeThresholdInitWorker 
 
unsigned int __fastcall ExpAeThresholdInitWorker(int a1, int *a2, unsigned int *a3, unsigned int *a4)
{
  unsigned int v5; // r4
  unsigned int v6; // r4
  unsigned int v7; // r1
  int v8; // r9
  int v9; // r0
  unsigned int v10; // r1
  unsigned int v11; // r10
  int v12; // r4
  unsigned int v13; // r6
  __int64 v14; // r0
  __int64 v15; // kr00_8
  unsigned int result; // r0
  unsigned int v17; // r4
  unsigned int *v18; // r2
  unsigned int v19; // r1
  unsigned __int64 *v20; // r3
  unsigned __int64 v21; // kr08_8
  unsigned int v22; // r2
  unsigned int v23; // r5
  unsigned int v24; // r4
  int v25; // r0
  unsigned __int64 v26; // [sp+0h] [bp-30h]
  int v27; // [sp+8h] [bp-28h]

  v26 = 0i64;
  __dmb(0xBu);
  do
  {
    v5 = __ldrex(a4);
    v6 = v5 - 1;
  }
  while ( __strex(v6, a4) );
  __dmb(0xBu);
  v7 = ~v6 & 0x80000000;
  if ( (v6 & 0x7FFFFFFF) != 0 )
  {
    while ( (*a4 & 0x80000000) != v7 )
    {
      __dmb(0xAu);
      __yield();
    }
    __dmb(0xBu);
  }
  else
  {
    v25 = a4[1] | v7;
    __dmb(0xBu);
    *a4 = v25;
  }
  v8 = 1024;
  do
  {
    v9 = ReadTimeStampCounter();
    __pld(a2);
    v11 = v10;
    v27 = v9;
    v12 = *a2;
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)a2);
    while ( v13 == v12 && __strex(v12 + 1, (unsigned int *)a2) );
    __dmb(0xBu);
    if ( v13 != v12 )
    {
      do
      {
        v23 = v13;
        __dmb(0xBu);
        do
          v24 = __ldrex((unsigned int *)a2);
        while ( v24 == v13 && __strex(v13 + 1, (unsigned int *)a2) );
        v13 = v24;
        __dmb(0xBu);
      }
      while ( v24 != v23 );
    }
    LODWORD(v14) = ReadTimeStampCounter();
    v15 = v14 - __PAIR64__(v11, v27);
    result = v26 + v14 - v27;
    v17 = (v26 + v15) >> 32;
    v26 = __PAIR64__(v17, result);
    --v8;
  }
  while ( v8 );
  __dmb(0xBu);
  v18 = (unsigned int *)(a2 + 34);
  do
    v19 = __ldrex(v18);
  while ( __strex(v19 + 1, v18) );
  __dmb(0xBu);
  v20 = (unsigned __int64 *)(a2 + 32);
  do
    v21 = __ldrexd(v20);
  while ( __strexd(v21 + __PAIR64__(v17, result), v20) );
  __dmb(0xBu);
  do
    v22 = __ldrex(a3);
  while ( __strex(v22 - 1, a3) );
  __dmb(0xBu);
  return result;
}
