// MiReferenceVad 
 
int __fastcall MiReferenceVad(int result)
{
  unsigned int *v1; // r2
  unsigned int v2; // r1

  v1 = (unsigned int *)(result + 20);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 + 1, v1) );
  __dmb(0xBu);
  return result;
}
