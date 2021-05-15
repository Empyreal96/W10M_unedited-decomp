// KiInitializeDpcList 
 
_DWORD *__fastcall KiInitializeDpcList(_DWORD *result)
{
  *result = 0;
  result[1] = result;
  return result;
}
