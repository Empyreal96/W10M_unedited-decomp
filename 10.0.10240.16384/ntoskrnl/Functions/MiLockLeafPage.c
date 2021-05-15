// MiLockLeafPage 
 
int __fastcall MiLockLeafPage(unsigned int *a1, int a2)
{
  unsigned int v4; // r4
  int result; // r0
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned int v8; // r1
  unsigned int *v9; // r2
  unsigned int v10; // r0
  unsigned __int8 *v11; // r1
  int v12; // r3
  unsigned int v13; // r2

  while ( 1 )
  {
    v4 = *a1;
    if ( (*a1 & 2) == 0 && ((v4 & 0x400) != 0 || (v4 & 0x800) == 0) )
      break;
    if ( MI_IS_PFN(v4 >> 12) )
    {
      result = MmPfnDatabase + 24 * (v4 >> 12);
      v6 = (unsigned __int8 *)(result + 15);
      if ( a2 )
      {
        do
          v8 = __ldrex(v6);
        while ( __strex(v8 | 0x80, v6) );
        __dmb(0xBu);
        if ( v8 >> 7 )
        {
          v11 = (unsigned __int8 *)(result + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v12 = *(_DWORD *)(result + 12);
              __dmb(0xBu);
            }
            while ( (v12 & 0x80000000) != 0 );
            do
              v13 = __ldrex(v11);
            while ( __strex(v13 | 0x80, v11) );
            __dmb(0xBu);
          }
          while ( v13 >> 7 );
        }
      }
      else
      {
        do
          v7 = __ldrex(v6);
        while ( __strex(v7 | 0x80, v6) );
        __dmb(0xBu);
        if ( v7 >> 7 )
          return sub_538274();
      }
      if ( *a1 == v4 )
        return result;
      __dmb(0xBu);
      v9 = (unsigned int *)(result + 12);
      do
        v10 = __ldrex(v9);
      while ( __strex(v10 & 0x7FFFFFFF, v9) );
    }
  }
  return 0;
}
