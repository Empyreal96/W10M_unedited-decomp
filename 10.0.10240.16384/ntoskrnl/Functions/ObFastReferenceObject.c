// ObFastReferenceObject 
 
int __fastcall ObFastReferenceObject(_DWORD *a1)
{
  unsigned int v2; // r1
  unsigned int v3; // r0
  int v4; // r5
  unsigned int v6; // r1
  unsigned int v7; // r0
  unsigned int *v8; // r4
  unsigned int v9; // r1

  __pld(a1);
  v2 = *a1;
  if ( (*a1 & 7) != 0 )
  {
    do
    {
      do
        v3 = __ldrex(a1);
      while ( v3 == v2 && __strex(v2 - 1, a1) );
      __dmb(0xBu);
      if ( v3 == v2 )
        break;
      v2 = v3;
    }
    while ( (v3 & 7) != 0 );
  }
  v4 = v2 & 0xFFFFFFF8;
  if ( (v2 & 7) > 1 )
    return v4;
  if ( (v2 & 7) == 0 )
    return 0;
  ObReferenceObjectExWithTag(v4, 7);
  __pld(a1);
  v6 = *a1;
  if ( (*a1 & 7) == 0 )
  {
    while ( v4 == (v6 & 0xFFFFFFF8) )
    {
      do
        v7 = __ldrex(a1);
      while ( v7 == v6 && __strex(v6 + 7, a1) );
      __dmb(0xBu);
      if ( v7 == v6 )
        return v4;
      v6 = v7;
      if ( (v7 & 7) != 0 )
        break;
    }
  }
  v8 = (unsigned int *)(v4 - 24);
  if ( !ObpTraceFlags )
  {
    __dmb(0xBu);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 - 7, v8) );
    if ( (int)(v9 - 7) <= 0 )
    {
      if ( v9 != 7 )
        KeBugCheckEx(24, 0, v4);
      ObpDeferObjectDeletion(v4 - 24);
    }
    return v4;
  }
  return sub_50C76C();
}
