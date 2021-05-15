// ExpGetPoolTagInfoTarget 
 
int __fastcall ExpGetPoolTagInfoTarget(int a1, int *a2, unsigned int *a3, unsigned int *a4)
{
  unsigned int *v5; // lr
  unsigned int v7; // r4
  unsigned int v8; // r4
  unsigned int v9; // r7
  int result; // r0
  unsigned int v11; // r2
  unsigned int v12; // r2
  unsigned int v13; // r1
  unsigned int v14; // r2
  int v15; // r0
  int *v16; // r9
  int v17; // lr
  int v18; // r8
  int *v19; // r7
  int *v20; // t1
  _DWORD *i; // r4
  int v22; // t1
  int v23; // r0
  int v24; // r3
  int v25; // r0
  int v26; // r1
  int v27; // r2
  int v28; // r3
  int v29; // r3

  v5 = a3;
  __dmb(0xBu);
  do
  {
    v7 = __ldrex(a4);
    v8 = v7 - 1;
  }
  while ( __strex(v8, a4) );
  __dmb(0xBu);
  v9 = ~v8 & 0x80000000;
  result = v8 & 0x7FFFFFFF;
  if ( (v8 & 0x7FFFFFFF) != 0 )
  {
    while ( (*a4 & 0x80000000) != v9 )
    {
      __dmb(0xAu);
      __yield();
    }
    __dmb(0xBu);
  }
  else
  {
    v15 = a4[1] | v9;
    __dmb(0xBu);
    *a4 = v15;
    result = memmove(*a2, ExPoolTagTables, 28 * a2[1]);
    v16 = &dword_61A4E4;
    v17 = *a2 + 28 * a2[1];
    v18 = 31;
    do
    {
      v20 = (int *)*v16++;
      v19 = v20;
      if ( v20 )
      {
        for ( i = (_DWORD *)*a2; i != (_DWORD *)v17; i += 7 )
        {
          v22 = *v19;
          v19 += 7;
          if ( v22 )
          {
            v23 = i[2];
            i[1] += *(v19 - 6);
            v24 = v23 + *(v19 - 5);
            v25 = i[4];
            v26 = i[3];
            i[2] = v24;
            i[3] = v26 + *(v19 - 4);
            v27 = v25 + *(v19 - 3);
            result = i[6];
            v28 = i[5];
            i[4] = v27;
            i[5] = v28 + *(v19 - 2);
            i[6] = result + *(v19 - 1);
          }
        }
      }
      --v18;
    }
    while ( v18 );
    if ( a2[3] )
      return sub_51C2B4(result);
    v5 = a3;
  }
  __dmb(0xBu);
  do
  {
    v11 = __ldrex(a4);
    v12 = v11 - 1;
  }
  while ( __strex(v12, a4) );
  __dmb(0xBu);
  v13 = ~v12 & 0x80000000;
  if ( (v12 & 0x7FFFFFFF) != 0 )
  {
    while ( (*a4 & 0x80000000) != v13 )
    {
      __dmb(0xAu);
      __yield();
    }
    __dmb(0xBu);
  }
  else
  {
    v29 = a4[1] | v13;
    __dmb(0xBu);
    *a4 = v29;
  }
  __dmb(0xBu);
  do
    v14 = __ldrex(v5);
  while ( __strex(v14 - 1, v5) );
  __dmb(0xBu);
  return result;
}
