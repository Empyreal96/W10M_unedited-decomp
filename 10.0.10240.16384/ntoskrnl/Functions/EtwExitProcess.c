// EtwExitProcess 
 
unsigned int __fastcall EtwExitProcess(unsigned int result)
{
  unsigned int v1; // r4

  v1 = *(_DWORD *)(result + 348);
  if ( v1 )
  {
    *(_DWORD *)(result + 348) = 0;
    if ( (v1 & 1) != 0 )
    {
      result = ObfDereferenceObject(v1 ^ 1);
    }
    else
    {
      if ( *(_DWORD *)v1 )
        ObfDereferenceObject(*(_DWORD *)v1);
      result = ExFreePoolWithTag(v1);
    }
  }
  return result;
}
