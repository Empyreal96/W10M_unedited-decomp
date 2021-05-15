// SepRmDereferenceCapTable 
 
int __fastcall SepRmDereferenceCapTable(int result)
{
  unsigned int *v1; // r2
  unsigned int v2; // r1
  signed int v3; // r1

  __dmb(0xBu);
  v1 = (unsigned int *)(result + 36);
  do
  {
    v2 = __ldrex(v1);
    v3 = v2 - 1;
  }
  while ( __strex(v3, v1) );
  if ( v3 <= 0 )
  {
    if ( v3 )
      __fastfail(0xEu);
    __dmb(0xBu);
    result = SepRmDestroyCapTable(result);
  }
  return result;
}
