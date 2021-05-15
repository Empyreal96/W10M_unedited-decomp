// PfFbBufferListUpdateMax 
 
unsigned int __fastcall PfFbBufferListUpdateMax(int a1, unsigned int a2)
{
  unsigned int *v2; // r2
  unsigned int result; // r0

  __dmb(0xBu);
  v2 = (unsigned int *)(a1 + 52);
  do
    result = __ldrex(v2);
  while ( __strex(a2, v2) );
  __dmb(0xBu);
  return result;
}
