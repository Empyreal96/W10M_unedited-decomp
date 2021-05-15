// IoSetThreadHardErrorMode 
 
BOOL __fastcall IoSetThreadHardErrorMode(int a1)
{
  int v1; // r3
  unsigned __int8 *v2; // r3
  unsigned int v3; // r1

  v1 = __mrc(15, 0, 13, 0, 3);
  __dmb(0xBu);
  v2 = (unsigned __int8 *)((v1 & 0xFFFFFFC0) + 960);
  if ( a1 )
  {
    do
      v3 = __ldrex(v2);
    while ( __strex(v3 & 0xEF, v2) );
  }
  else
  {
    do
      v3 = __ldrex(v2);
    while ( __strex(v3 | 0x10, v2) );
  }
  __dmb(0xBu);
  return (unsigned __int8)(v3 & 0x10) >> 4 == 0;
}
