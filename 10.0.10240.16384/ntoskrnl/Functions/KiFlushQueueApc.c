// KiFlushQueueApc 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiFlushQueueApc(int a1, int a2)
{
  int v2; // r8
  int v4; // r5
  _DWORD *v5; // r4
  int *v6; // r5
  int v8; // r0
  unsigned int *v9; // r7
  unsigned int v10; // r2
  unsigned int v11; // r2
  int v12; // r1 OVERLAPPED
  _DWORD *v13; // r2 OVERLAPPED
  int *v14; // r3

  a2 = (char)a2;
  v2 = a2;
  if ( (char)a2 != 1 )
  {
    v4 = a1 + 8 * (char)a2;
    v5 = (_DWORD *)(v4 + 100);
    if ( *(_DWORD *)(v4 + 100) == v4 + 100 )
      return 0;
    v8 = KfRaiseIrql(2);
    v9 = (unsigned int *)(a1 + 44);
    while ( 1 )
    {
      do
        v11 = __ldrex(v9);
      while ( __strex(1u, v9) );
      __dmb(0xBu);
      if ( !v11 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v9 );
    }
    goto LABEL_16;
  }
  v8 = KfRaiseIrql(2);
  v9 = (unsigned int *)(a1 + 44);
  do
    v10 = __ldrex(v9);
  while ( __strex(1u, v9) );
  __dmb(0xBu);
  if ( !v10 )
  {
    v5 = (_DWORD *)(a1 + 108);
    v4 = a1 + 8;
    if ( *(_DWORD *)(a1 + 108) == a1 + 108 )
    {
      __dmb(0xBu);
      *v9 = 0;
      KfLowerIrql(v8);
      return 0;
    }
LABEL_16:
    v6 = *(int **)(v4 + 100);
    if ( v6 == (int *)(a1 + 8 * v2 + 100) )
    {
      v6 = 0;
    }
    else
    {
      *(_QWORD *)&v12 = *(_QWORD *)v5;
      if ( *(_DWORD **)(*v5 + 4) != v5 || (_DWORD *)*v13 != v5 )
        __fastfail(3u);
      *v13 = v12;
      *(_DWORD *)(v12 + 4) = v13;
      v14 = v6;
      do
      {
        *((_BYTE *)v14 + 34) = 0;
        v14 = (int *)*v14;
      }
      while ( v14 != v6 );
      *v5 = v5;
      v5[1] = v5;
    }
    __dmb(0xBu);
    *v9 = 0;
    KfLowerIrql(v8);
    return (int)v6;
  }
  return sub_52B0FC(v8, 1);
}
