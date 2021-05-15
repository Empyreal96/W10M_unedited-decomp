// KeProcessorGroupAffinity 
 
_DWORD *__fastcall KeProcessorGroupAffinity(_DWORD *result, char a2)
{
  *result = 0;
  result[1] = 0;
  result[2] = 0;
  *result = 1 << a2;
  return result;
}
