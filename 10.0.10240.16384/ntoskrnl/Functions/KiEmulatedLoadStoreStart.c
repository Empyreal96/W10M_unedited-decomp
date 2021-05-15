// KiEmulatedLoadStoreStart 
 
unsigned int *__fastcall KiEmulatedLoadStoreStart(unsigned int *result, int a2, int a3, int a4, int a5, char a6)
{
  unsigned int v6; // r4

  if ( (a6 & 0xF) == 0 )
    v6 = __ldrt(result);
  return result;
}
