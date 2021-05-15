// KiIpiCompleteIpiRequest 
 
unsigned int __fastcall KiIpiCompleteIpiRequest(int a1, int a2)
{
  unsigned int *v2; // r2
  unsigned int v3; // r0
  unsigned int result; // r0
  unsigned int *v5; // r2
  unsigned int v6; // r0

  __dmb(0xBu);
  v2 = *(unsigned int **)(a1 + 24);
  do
  {
    v3 = __ldrex(v2);
    result = v3 - 1;
  }
  while ( __strex(result, v2) );
  __dmb(0xBu);
  if ( !result )
  {
    __dmb(0xBu);
    v5 = (unsigned int *)(a2 + 1668);
    do
    {
      v6 = __ldrex(v5);
      result = v6 - 1;
    }
    while ( __strex(result, v5) );
    __dmb(0xBu);
    if ( !result )
    {
      __dmb(0xBu);
      *(_DWORD *)(a2 + 1536) = 0;
    }
  }
  return result;
}
