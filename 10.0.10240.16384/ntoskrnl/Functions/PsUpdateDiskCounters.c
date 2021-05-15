// PsUpdateDiskCounters 
 
unsigned int __fastcall PsUpdateDiskCounters(unsigned int result, __int64 a2, __int64 a3, unsigned int a4, unsigned int a5, unsigned int a6)
{
  unsigned __int64 *v7; // r5
  unsigned __int64 v8; // r0
  unsigned __int64 *v9; // r3
  unsigned __int64 v10; // kr00_8
  unsigned __int64 *v11; // r3
  unsigned __int64 v12; // kr08_8
  unsigned __int64 *v13; // r3
  unsigned __int64 v14; // kr10_8
  unsigned __int64 *v15; // r3
  unsigned __int64 v16; // kr18_8

  v7 = *(unsigned __int64 **)(result + 776);
  if ( v7 )
  {
    if ( a2 )
    {
      __dmb(0xBu);
      do
        v8 = __ldrexd(v7);
      while ( __strexd(v8 + a2, v7) );
      __dmb(0xBu);
    }
    if ( a3 )
    {
      __dmb(0xBu);
      v11 = v7 + 1;
      do
        v12 = __ldrexd(v11);
      while ( __strexd(v12 + a3, v11) );
      __dmb(0xBu);
    }
    if ( a4 )
    {
      __dmb(0xBu);
      v9 = v7 + 2;
      do
        v10 = __ldrexd(v9);
      while ( __strexd(v10 + a4, v9) );
      __dmb(0xBu);
    }
    if ( a5 )
    {
      __dmb(0xBu);
      v13 = v7 + 3;
      do
        v14 = __ldrexd(v13);
      while ( __strexd(v14 + a5, v13) );
      __dmb(0xBu);
    }
    result = a6;
    if ( a6 )
    {
      __dmb(0xBu);
      v15 = v7 + 4;
      do
        v16 = __ldrexd(v15);
      while ( __strexd(v16 + a6, v15) );
      __dmb(0xBu);
    }
  }
  return result;
}
