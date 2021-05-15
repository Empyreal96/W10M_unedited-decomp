// ExSetPoolFlags 
 
int __fastcall ExSetPoolFlags(int result)
{
  unsigned int v1; // r4

  __dmb(0xBu);
  do
    v1 = __ldrex((unsigned int *)&ExpPoolFlags);
  while ( __strex(v1 | result, (unsigned int *)&ExpPoolFlags) );
  __dmb(0xBu);
  return result;
}
