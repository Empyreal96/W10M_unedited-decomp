// ViCtxAllocateIsrContext 
 
_DWORD *__fastcall ViCtxAllocateIsrContext(int a1, int a2, int a3)
{
  _DWORD *result; // r0

  result = (_DWORD *)ExAllocatePoolWithTag(512, 12, 1920158038);
  if ( result )
  {
    *result = a1;
    result[1] = a2;
    result[2] = a3;
  }
  return result;
}
