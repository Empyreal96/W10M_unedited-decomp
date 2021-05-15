// MiMoveLargeFreePage 
 
int __fastcall MiMoveLargeFreePage(int a1, __int16 *a2, int a3, int a4)
{
  unsigned int v4; // r5
  int v6; // r10
  unsigned int v8; // r6
  int v9; // r4
  unsigned __int8 *v10; // r1
  unsigned int v11; // r2
  int v12; // r3
  int v13; // r3
  unsigned int v14; // r2
  unsigned int *v15; // r2
  unsigned int v16; // r0
  unsigned int v17; // r4
  int v18; // r9
  unsigned int *v19; // r7
  unsigned __int8 *v20; // r1
  unsigned int v21; // r2
  unsigned int v22; // r3
  unsigned int v23; // r1

  v4 = a1 & 0xFFFFFC00;
  v6 = MiTryUnlinkNodeLargePage(a1 & 0xFFFFFC00, (int)a2, a3, a4);
  if ( v6 > 1 )
    return 0;
  v8 = MmPfnDatabase + 24 * v4;
  if ( MiSystemPartition != a2 )
  {
    v9 = KfRaiseIrql(2);
    v10 = (unsigned __int8 *)(v8 + 15);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | 0x80, v10) );
    __dmb(0xBu);
    v12 = v11 >> 7;
    if ( v11 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v13 = *(_DWORD *)(v8 + 12);
          __dmb(0xBu);
        }
        while ( (v13 & 0x80000000) != 0 );
        do
          v14 = __ldrex(v10);
        while ( __strex(v14 | 0x80, v10) );
        __dmb(0xBu);
        v12 = v14 >> 7;
      }
      while ( v14 >> 7 );
    }
    MiInsertLargePageInNodeList(v4, 0x400u, v6, v12);
    __dmb(0xBu);
    v15 = (unsigned int *)(v8 + 12);
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 & 0x7FFFFFFF, v15) );
    KfLowerIrql(v9);
    return 0;
  }
  v17 = v8 + 24552;
  v18 = KfRaiseIrql(2);
  if ( v8 + 24552 >= v8 )
  {
    v19 = (unsigned int *)(v8 + 24564);
    do
    {
      v20 = (unsigned __int8 *)v19 + 3;
      do
        v21 = __ldrex(v20);
      while ( __strex(v21 | 0x80, v20) );
      while ( 1 )
      {
        __dmb(0xBu);
        if ( !(v21 >> 7) )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
          v22 = *v19;
          __dmb(0xBu);
        }
        while ( (v22 & 0x80000000) != 0 );
        do
          v21 = __ldrex(v20);
        while ( __strex(v21 | 0x80, v20) );
      }
      if ( v17 == v8 )
        MiInsertLargePageInNodeList(v4, 0x400u, v6, 0);
      __dmb(0xBu);
      do
        v23 = __ldrex(v19);
      while ( __strex(v23 & 0x7FFFFFFF, v19) );
      v17 -= 24;
      v19 -= 6;
    }
    while ( v17 >= v8 );
  }
  KfLowerIrql(v18);
  return 1;
}
