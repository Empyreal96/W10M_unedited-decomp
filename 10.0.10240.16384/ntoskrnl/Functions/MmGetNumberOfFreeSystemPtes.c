// MmGetNumberOfFreeSystemPtes 
 
unsigned int MmGetNumberOfFreeSystemPtes()
{
  return MiGetNumberOfCachedPtes(&dword_634D58) + ((unsigned int)dword_635310 >> 12) + dword_634D88;
}
