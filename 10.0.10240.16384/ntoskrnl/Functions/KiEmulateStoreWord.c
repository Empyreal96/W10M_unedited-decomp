// KiEmulateStoreWord 
 
unsigned int *__fastcall KiEmulateStoreWord(unsigned int *result, int a2, int a3, int a4, int a5, char a6)
{
  unsigned int v6; // r4

  if ( (a6 & 0xF) != 0 )
    *result = v6;
  else
    __strt(v6, result);
  return result;
}
