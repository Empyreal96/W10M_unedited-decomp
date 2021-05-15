// PspModifyAncestorBits 
 
int __fastcall PspModifyAncestorBits(int result, int a2, int a3)
{
  unsigned int i; // r6
  unsigned int v5; // r5
  unsigned int *v6; // r2
  unsigned int v7; // r4

  for ( i = *(_DWORD *)(result + 572); i; i = *(_DWORD *)(i + 572) )
  {
    __dmb(0xBu);
    if ( a3 )
    {
      result = i + 744;
      do
        v5 = __ldrex((unsigned int *)result);
      while ( __strex(v5 | a2, (unsigned int *)result) );
    }
    else
    {
      result = ~a2;
      v6 = (unsigned int *)(i + 744);
      do
        v7 = __ldrex(v6);
      while ( __strex(v7 & result, v6) );
    }
    __dmb(0xBu);
  }
  return result;
}
