// MmFreeAccessPfnBuffer 
 
int __fastcall MmFreeAccessPfnBuffer(int a1, int a2)
{
  unsigned int v3; // r0

  if ( !*(_DWORD *)(a1 + 4) )
  {
    v3 = *(_DWORD *)(a1 + 44);
    if ( v3 > 1 )
    {
      if ( a2 )
        ObDereferenceObjectDeferDeleteWithTag(v3);
      else
        ObfDereferenceObjectWithTag(v3);
    }
  }
  return ExFreePoolWithTag(a1);
}
