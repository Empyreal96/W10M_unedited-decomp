// PopWakeInfoReference 
 
int __fastcall PopWakeInfoReference(int result)
{
  unsigned int *v1; // r2
  unsigned int v2; // r1

  __dmb(0xBu);
  v1 = (unsigned int *)(result + 8);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 + 1, v1) );
  __dmb(0xBu);
  return result;
}
