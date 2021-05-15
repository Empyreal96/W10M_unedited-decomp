// RtlInitializeBitMap 
 
_DWORD *__fastcall RtlInitializeBitMap(_DWORD *result, int a2, int a3)
{
  *result = a3;
  result[1] = a2;
  return result;
}
