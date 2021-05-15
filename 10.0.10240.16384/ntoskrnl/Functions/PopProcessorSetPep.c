// PopProcessorSetPep 
 
int __fastcall PopProcessorSetPep(int a1)
{
  int v1; // r2
  int result; // r0

  v1 = *(_DWORD *)(a1 + 36);
  if ( !v1 || !*(_DWORD *)(v1 + 68) )
    return -1073741822;
  result = 0;
  PopFxProcessorPlugin = v1;
  return result;
}
