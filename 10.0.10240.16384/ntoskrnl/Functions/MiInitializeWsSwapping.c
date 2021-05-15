// MiInitializeWsSwapping 
 
_DWORD *__fastcall MiInitializeWsSwapping(_DWORD *result)
{
  result[163] = 0;
  result[160] = MiContractWsSwapPageFileWorker;
  result[161] = result;
  result[158] = 0;
  return result;
}
