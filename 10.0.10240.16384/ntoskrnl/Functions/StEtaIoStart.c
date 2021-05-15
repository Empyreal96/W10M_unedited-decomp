// StEtaIoStart 
 
int __fastcall StEtaIoStart(_DWORD *a1, unsigned int a2, int a3, unsigned int a4)
{
  unsigned int v4; // r8
  unsigned int *v7; // r0
  unsigned int v8; // t1
  unsigned int *i; // r4
  unsigned int v10; // r6
  unsigned int *v11; // r10
  signed int v12; // r5
  unsigned int *v13; // r2
  unsigned int v14; // r0
  signed int v15; // r0
  signed int v16; // r1
  bool v17; // cc
  signed int v18; // r2
  unsigned int v19; // r1
  int result; // r0
  unsigned __int16 *v21; // r1
  unsigned int v22; // r2
  int v23; // r3
  int v24[2]; // [sp+0h] [bp-30h] BYREF
  int v25[10]; // [sp+8h] [bp-28h] BYREF

  v4 = a4;
  if ( (a4 & 1) != 0 )
  {
    v7 = (unsigned int *)a1[a3 + 4];
    v4 = a4 & 0xFFFFFFFE;
    do
    {
      v8 = *v7;
      v7 += 8;
    }
    while ( v8 < a2 );
    i = v7 - 8;
  }
  else
  {
    for ( i = (unsigned int *)a1[a3 + 4]; *i < a2; i += 8 )
      ;
    *((_WORD *)i + 2) = 0;
  }
  v10 = i[2];
  v11 = a1 + 3;
  v12 = a1[3];
  __dmb(0xBu);
  v13 = a1 + 2;
  do
  {
    v14 = __ldrex(v13);
    v15 = v14 + 1;
  }
  while ( __strex(v15, v13) );
  __dmb(0xBu);
  if ( v15 == 1 )
  {
    KeQueryPerformanceCounter(v24, 0);
    *a1 = v24[0];
    a1[1] = v24[1];
    __dmb(0xBu);
    do
      v16 = __ldrex(v11);
    while ( v16 == v12 && __strex(v10, v11) );
    __dmb(0xBu);
    if ( v16 != v12 )
    {
      v17 = v16 <= v12;
      do
      {
        if ( !v17 )
          v10 += v16 - v12;
        v12 = v16;
        __dmb(0xBu);
        do
          v18 = __ldrex(v11);
        while ( v18 == v16 && __strex(v10, v11) );
        v16 = v18;
        __dmb(0xBu);
        v17 = v18 <= v12;
      }
      while ( v18 != v12 );
      return 0;
    }
  }
  else
  {
    __dmb(0xBu);
    do
      v19 = __ldrex(v11);
    while ( __strex(v19 + v10, v11) );
    __dmb(0xBu);
    if ( v15 > 1 )
      return 0;
  }
  v21 = (unsigned __int16 *)&a1[a3 + 6];
  v22 = (unsigned __int16)(*((_WORD *)i + 3) + 1);
  *((_WORD *)i + 3) = v22;
  if ( v22 >= *v21 && (!v21[1] || (v21[1] & (unsigned __int16)v22) != 0) )
    return 0;
  KeQueryPerformanceCounter(v25, 0);
  v23 = v25[0];
  i[6] = v4;
  result = 1;
  i[4] = v23;
  i[5] = v25[1];
  return result;
}
