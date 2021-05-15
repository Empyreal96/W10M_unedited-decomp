// KeRemoveProcessorAffinityEx 
 
int __fastcall KeRemoveProcessorAffinityEx(int result, char a2)
{
  *(_DWORD *)(result + 8) &= ~(1 << a2);
  return result;
}
