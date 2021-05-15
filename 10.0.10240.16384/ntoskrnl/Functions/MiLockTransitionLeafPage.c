// MiLockTransitionLeafPage 
 
int __fastcall MiLockTransitionLeafPage(unsigned int *a1, unsigned int a2)
{
  unsigned int v4; // r7
  int v6; // r4
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r1
  unsigned __int8 *v10; // r1
  int v11; // r3
  unsigned int v12; // r2
  unsigned int *v13; // r2
  unsigned int v14; // r0

  while ( 1 )
  {
    do
    {
      v4 = *a1;
      if ( a2 > 1 )
        return sub_537AE0();
      if ( (v4 & 0x800) == 0 )
        return 0;
    }
    while ( !MI_IS_PFN(v4 >> 12) );
    v6 = MmPfnDatabase + 24 * (v4 >> 12);
    v7 = (unsigned __int8 *)(v6 + 15);
    if ( a2 == 1 )
    {
      do
        v9 = __ldrex(v7);
      while ( __strex(v9 | 0x80, v7) );
      __dmb(0xBu);
      if ( v9 >> 7 )
        return 0;
    }
    else
    {
      do
        v8 = __ldrex(v7);
      while ( __strex(v8 | 0x80, v7) );
      __dmb(0xBu);
      if ( v8 >> 7 )
      {
        v10 = (unsigned __int8 *)(v6 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v11 = *(_DWORD *)(v6 + 12);
            __dmb(0xBu);
          }
          while ( (v11 & 0x80000000) != 0 );
          do
            v12 = __ldrex(v10);
          while ( __strex(v12 | 0x80, v10) );
          __dmb(0xBu);
        }
        while ( v12 >> 7 );
      }
    }
    if ( *a1 == v4 )
      break;
    __dmb(0xBu);
    v13 = (unsigned int *)(v6 + 12);
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 & 0x7FFFFFFF, v13) );
  }
  if ( (unsigned int *)(*(_DWORD *)(v6 + 4) | 0x80000000) != a1 )
    KeBugCheckEx(26, 1041, a1);
  return v6;
}
