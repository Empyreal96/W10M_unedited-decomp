// ObReferenceObjectExWithTag 
 
int __fastcall ObReferenceObjectExWithTag(int a1, int a2)
{
  unsigned int *v2; // r5
  int v4; // r0

  v2 = (unsigned int *)(a1 - 24);
  if ( ObpTraceFlags )
    return sub_50AAC4();
  do
    v4 = __ldrex(v2);
  while ( __strex(v4 + a2, v2) );
  __dmb(0xBu);
  if ( v4 <= 0 )
    KeBugCheckEx(24, 0, v2 + 6);
  return v4 + a2;
}
