// MiFreeLargePages 
 
int __fastcall MiFreeLargePages(_DWORD *a1)
{
  _DWORD *v1; // r4
  int v2; // r6
  _DWORD *v3; // r9
  unsigned int v4; // r8
  int v5; // r0
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned __int8 *v8; // r1
  int v9; // r3
  unsigned int v10; // r2
  unsigned int *v11; // r2
  unsigned int v12; // r4

  v1 = a1;
  v2 = 0;
  if ( a1 != (_DWORD *)0xFFFFF )
  {
    do
    {
      v3 = (_DWORD *)*v1;
      v4 = (int)((unsigned __int64)(715827883i64 * ((int)v1 - MmPfnDatabase)) >> 32) >> 2;
      v5 = KfRaiseIrql(2);
      v6 = (unsigned __int8 *)v1 + 15;
      do
        v7 = __ldrex(v6);
      while ( __strex(v7 | 0x80, v6) );
      __dmb(0xBu);
      if ( v7 >> 7 )
      {
        v8 = (unsigned __int8 *)v1 + 15;
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v9 = v1[3];
            __dmb(0xBu);
          }
          while ( v9 < 0 );
          do
            v10 = __ldrex(v8);
          while ( __strex(v10 | 0x80, v8) );
          __dmb(0xBu);
        }
        while ( v10 >> 7 );
      }
      v1[3] = v1[3] & 0xC0000000 | 1;
      __dmb(0xBu);
      v11 = v1 + 3;
      do
        v12 = __ldrex(v11);
      while ( __strex(v12 & 0x7FFFFFFF, v11) );
      KfLowerIrql(v5);
      v2 += MiFreeLargePageMemory(v4 + (v4 >> 31));
      v1 = v3;
    }
    while ( v3 != (_DWORD *)0xFFFFF );
  }
  return v2;
}
