// StEtaEndRefresh 
 
unsigned int __fastcall StEtaEndRefresh(int a1)
{
  unsigned int *v1; // r2
  unsigned int result; // r0

  __dmb(0xBu);
  v1 = (unsigned int *)(a1 + 40);
  do
    result = __ldrex(v1);
  while ( __strex(result & 0xFFFFFFFE, v1) );
  __dmb(0xBu);
  return result;
}
