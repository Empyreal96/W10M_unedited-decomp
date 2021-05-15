// MiObtainProtoReference 
 
int __fastcall MiObtainProtoReference(int a1, char a2)
{
  unsigned __int8 *v3; // r0
  int v4; // r5
  unsigned int v5; // r2
  unsigned int *v6; // r2
  int result; // r0
  unsigned int v8; // r2
  int v9; // r3
  unsigned int v10; // r2

  v3 = (unsigned __int8 *)(a1 + 15);
  v4 = a2 & 1;
  if ( (a2 & 1) != 0 )
  {
    do
      v8 = __ldrex(v3);
    while ( __strex(v8 | 0x80, v3) );
    __dmb(0xBu);
    if ( v8 >> 7 )
      return sub_544938();
  }
  else
  {
    do
      v5 = __ldrex(v3);
    while ( __strex(v5 | 0x80, v3) );
    __dmb(0xBu);
    if ( v5 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v9 = *(_DWORD *)(a1 + 12);
          __dmb(0xBu);
        }
        while ( (v9 & 0x80000000) != 0 );
        do
          v10 = __ldrex(v3);
        while ( __strex(v10 | 0x80, v3) );
        __dmb(0xBu);
      }
      while ( v10 >> 7 );
    }
  }
  MiAddLockedPageCharge(a1, 1);
  __dmb(0xBu);
  v6 = (unsigned int *)(a1 + 12);
  if ( v4 )
  {
    do
      result = __ldrex(v6);
    while ( __strex(result & 0x7FFFFFFF, v6) );
  }
  else
  {
    do
      result = __ldrex(v6);
    while ( __strex(result & 0x7FFFFFFF, v6) );
  }
  return result;
}
