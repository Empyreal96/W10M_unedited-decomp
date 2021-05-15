// MiInitializePfnListHead 
 
_DWORD *__fastcall MiInitializePfnListHead(_DWORD *result, int a2)
{
  result[2] = 0xFFFFF;
  result[3] = 0xFFFFF;
  *result = 0;
  result[1] = a2;
  result[4] = 0;
  return result;
}
