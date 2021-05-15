// KeAddProcessorGroupAffinity 
 
_DWORD *__fastcall KeAddProcessorGroupAffinity(_DWORD *result, char a2)
{
  *result |= 1 << a2;
  return result;
}
