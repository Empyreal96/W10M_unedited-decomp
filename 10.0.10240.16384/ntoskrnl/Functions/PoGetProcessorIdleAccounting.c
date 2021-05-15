// PoGetProcessorIdleAccounting 
 
_DWORD *__fastcall PoGetProcessorIdleAccounting(_DWORD *result)
{
  int v1; // r3

  v1 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1104);
  if ( v1 )
  {
    if ( !result )
      return result;
    *result = *(_DWORD *)(v1 + 4);
  }
  else
  {
    if ( !result )
      return result;
    *result = 0;
  }
  result[1] = 0;
  return result;
}
