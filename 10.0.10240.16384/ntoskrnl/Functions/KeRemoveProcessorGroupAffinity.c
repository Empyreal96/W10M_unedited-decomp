// KeRemoveProcessorGroupAffinity 
 
_DWORD *__fastcall KeRemoveProcessorGroupAffinity(_DWORD *result, char a2)
{
  *result &= ~(1 << a2);
  return result;
}
