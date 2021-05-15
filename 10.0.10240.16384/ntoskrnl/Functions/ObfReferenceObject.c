// ObfReferenceObject 
 
signed int __fastcall ObfReferenceObject(int a1)
{
  unsigned int *v1; // r4
  signed int result; // r0
  unsigned int v3; // r0

  v1 = (unsigned int *)(a1 - 24);
  if ( ObpTraceFlags )
    return sub_50C82C();
  do
  {
    v3 = __ldrex(v1);
    result = v3 + 1;
  }
  while ( __strex(result, v1) );
  __dmb(0xBu);
  if ( result <= 1 )
    KeBugCheckEx(24, 0, v1 + 6);
  return result;
}
