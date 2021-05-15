// RtlInterlockedSetClearBits 
 
int __fastcall RtlInterlockedSetClearBits(unsigned int *a1, int a2)
{
  int result; // r0
  unsigned int v4; // r4
  unsigned int v5; // r2

  result = *a1;
  v4 = (result | a2) & 0xFFFFFFDF;
  if ( v4 != result )
  {
    __dmb(0xBu);
    do
      v5 = __ldrex(a1);
    while ( v5 == result && __strex(v4, a1) );
    __dmb(0xBu);
    if ( v5 != result )
      result = sub_515454();
  }
  return result;
}
