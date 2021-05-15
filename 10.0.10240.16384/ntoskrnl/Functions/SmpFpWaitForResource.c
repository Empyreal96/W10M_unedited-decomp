// SmpFpWaitForResource 
 
int __fastcall SmpFpWaitForResource(int a1, int a2, unsigned int a3)
{
  unsigned int v3; // r5
  int v6; // r6
  unsigned int *v7; // r4
  unsigned int v8; // r3
  unsigned int v9; // r2
  unsigned int v10; // r3
  int result; // r0
  unsigned int v12; // r2

  v3 = a3;
  if ( a3 )
  {
    v6 = 0;
  }
  else
  {
    v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v6 = 1;
  }
  v7 = (unsigned int *)(a1 + 60);
  while ( 1 )
  {
    v10 = *v7;
    __dmb(0xBu);
    if ( v3 == v10 )
      break;
    v8 = *v7;
    __dmb(0xBu);
    if ( !v8 )
    {
      __dmb(0xBu);
      do
        v9 = __ldrex(v7);
      while ( !v9 && __strex(v3, v7) );
      __dmb(0xBu);
      if ( !v9 )
        break;
    }
    KeWaitForSingleObject(a1 + 4, 0, 0, 0, 0);
  }
  result = SmpFpAllocateResource(a1, a2);
  if ( v6 )
  {
    __dmb(0xBu);
    do
      v12 = __ldrex(v7);
    while ( __strex(result, v7) );
    __dmb(0xBu);
  }
  return result;
}
