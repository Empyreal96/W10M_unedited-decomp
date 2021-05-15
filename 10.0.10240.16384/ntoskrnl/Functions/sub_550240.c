// sub_550240 
 
void sub_550240()
{
  int *v0; // r4
  int *v1; // r6
  unsigned int v2; // r7
  int v3; // r8
  unsigned __int8 *v4; // r3
  unsigned int v5; // r1
  unsigned __int8 *v6; // r1
  int v7; // r3
  unsigned int v8; // r2
  unsigned int *v9; // r2
  unsigned int v10; // r0

  while ( 1 )
  {
    v1 = (int *)*v0;
    v2 = (int)((unsigned __int64)(715827883i64 * ((int)v0 - MmPfnDatabase)) >> 32) >> 2;
    v3 = KfRaiseIrql(2);
    v4 = (unsigned __int8 *)v0 + 15;
    do
      v5 = __ldrex(v4);
    while ( __strex(v5 | 0x80, v4) );
    __dmb(0xBu);
    if ( v5 >> 7 )
    {
      v6 = (unsigned __int8 *)v0 + 15;
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v7 = v0[3];
          __dmb(0xBu);
        }
        while ( v7 < 0 );
        do
          v8 = __ldrex(v6);
        while ( __strex(v8 | 0x80, v6) );
        __dmb(0xBu);
      }
      while ( v8 >> 7 );
    }
    MiInsertLargePageInNodeList(v2 + (v2 >> 31), 0x400u, *((_BYTE *)v0 + 18) & 7, *((unsigned __int8 *)v0 + 18));
    __dmb(0xBu);
    v9 = (unsigned int *)(v0 + 3);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 & 0x7FFFFFFF, v9) );
    KfLowerIrql(v3);
    v0 = v1;
    if ( !v1 )
      JUMPOUT(0x4EC014);
  }
}
