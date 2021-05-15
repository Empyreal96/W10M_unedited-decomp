// WheapGetPreallocatedErrorRecord 
 
int __fastcall WheapGetPreallocatedErrorRecord(int a1)
{
  int v2; // r3
  int result; // r0
  unsigned int v4; // r4
  unsigned int *v5; // r5
  int v6; // r3
  unsigned int v7; // r2

  v2 = *(_DWORD *)(a1 + 20);
  result = *(_DWORD *)(a1 + 36);
  v4 = 0;
  if ( !v2 )
    return 0;
  while ( 1 )
  {
    v5 = (unsigned int *)(result + 20);
    v6 = *(_DWORD *)(result + 20);
    __dmb(0xBu);
    if ( v6 != 1 )
    {
      __dmb(0xBu);
      do
        v7 = __ldrex(v5);
      while ( !v7 && __strex(1u, v5) );
      __dmb(0xBu);
      if ( !v7 )
        break;
    }
    ++v4;
    result += *(_DWORD *)(result + 8);
    if ( v4 >= *(_DWORD *)(a1 + 20) )
      return 0;
  }
  return result;
}
