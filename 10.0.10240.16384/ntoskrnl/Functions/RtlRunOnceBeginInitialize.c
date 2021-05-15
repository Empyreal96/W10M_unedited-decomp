// RtlRunOnceBeginInitialize 
 
int __fastcall RtlRunOnceBeginInitialize(unsigned int *a1, int a2, unsigned int *a3)
{
  unsigned int v4; // r0
  int v5; // r4
  BOOL v7; // r5
  unsigned int v8; // r7
  char v9; // r3
  unsigned int v10; // r1

  if ( (a2 & 0xFFFFFFFC) != 0 || ((a2 - 1) & a2) != 0 )
    return -1073741584;
  v4 = *a1;
  __dmb(0xBu);
  v5 = 0;
  if ( (v4 & 3) == 2 )
  {
    if ( a3 )
      *a3 = v4 & 0xFFFFFFFC;
  }
  else if ( (a2 & 1) != 0 )
  {
    v5 = -1073741823;
  }
  else
  {
    v7 = (a2 & 2) == 0;
    do
    {
      if ( (v4 & 3) != 0 )
        return sub_7D529C();
      v8 = v4;
      if ( v7 )
        v9 = 1;
      else
        v9 = 3;
      __dmb(0xBu);
      do
        v10 = __ldrex(a1);
      while ( v10 == v4 && __strex(v9 & 3, a1) );
      v4 = v10;
      __dmb(0xBu);
    }
    while ( v10 != v8 );
    v5 = 259;
  }
  return v5;
}
