// SmWdWorkItemMarkBusy 
 
int __fastcall SmWdWorkItemMarkBusy(int a1, int a2)
{
  unsigned int *v2; // r6
  unsigned int v3; // r4
  unsigned int v4; // r0
  unsigned int v5; // r1
  unsigned int v7; // r1

  v2 = (unsigned int *)(a1 + 4);
  if ( a2 )
  {
    v3 = *v2;
    __dmb(0xBu);
    do
    {
      if ( (v3 & 0x40000) != 0 )
        break;
      v4 = v3;
      __dmb(0xBu);
      do
        v5 = __ldrex(v2);
      while ( v5 == v3 && __strex(v3 | 0x20000, v2) );
      v3 = v5;
      __dmb(0xBu);
    }
    while ( v5 != v4 );
    __dmb(0xBu);
    if ( (v3 & 0x40000) != 0 )
      return 0;
  }
  else
  {
    __dmb(0xBu);
    do
      v7 = __ldrex(v2);
    while ( __strex(v7 & 0xFFFDFFFF, v2) );
    __dmb(0xBu);
  }
  return 1;
}
