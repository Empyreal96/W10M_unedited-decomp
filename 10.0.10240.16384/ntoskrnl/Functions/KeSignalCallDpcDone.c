// KeSignalCallDpcDone 
 
unsigned int *__fastcall KeSignalCallDpcDone(unsigned int *result)
{
  unsigned int v1; // r2

  __dmb(0xBu);
  do
    v1 = __ldrex(result);
  while ( __strex(v1 - 1, result) );
  __dmb(0xBu);
  return result;
}
