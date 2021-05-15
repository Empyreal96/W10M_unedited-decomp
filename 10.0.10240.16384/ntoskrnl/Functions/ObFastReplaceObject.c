// ObFastReplaceObject 
 
int __fastcall ObFastReplaceObject(unsigned int *a1, int a2)
{
  int v4; // r1
  unsigned int v5; // r2
  unsigned int v6; // r5
  int v7; // r7
  unsigned int *v8; // r6
  unsigned int v10; // r4

  if ( a2 )
  {
    ObReferenceObjectExWithTag(a2, 7);
    v4 = a2 | 7;
  }
  else
  {
    v4 = 0;
  }
  __dmb(0xBu);
  do
    v5 = __ldrex(a1);
  while ( __strex(v4, a1) );
  __dmb(0xBu);
  v6 = v5 & 0xFFFFFFF8;
  if ( (v5 & 0xFFFFFFF8) != 0 )
  {
    v7 = v5 & 7;
    if ( (v5 & 7) != 0 )
    {
      v8 = (unsigned int *)(v6 - 24);
      if ( ObpTraceFlags )
        return sub_53E694();
      __dmb(0xBu);
      do
        v10 = __ldrex(v8);
      while ( __strex(v10 - v7, v8) );
      if ( (int)(v10 - v7) <= 0 )
      {
        if ( v10 != v7 )
          KeBugCheckEx(24, 0, v6);
        ObpDeferObjectDeletion(v6 - 24);
      }
    }
  }
  return v6;
}
