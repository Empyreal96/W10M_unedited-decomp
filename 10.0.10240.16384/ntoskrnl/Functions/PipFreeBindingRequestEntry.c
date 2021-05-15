// PipFreeBindingRequestEntry 
 
unsigned int __fastcall PipFreeBindingRequestEntry(unsigned int a1)
{
  _DWORD *v2; // r0

  if ( *(_DWORD *)(a1 + 8) == 1 )
  {
    v2 = *(_DWORD **)(a1 + 12);
    if ( v2 )
    {
      RtlFreeAnsiString(v2);
      ExFreePoolWithTag(*(_DWORD *)(a1 + 12));
      *(_DWORD *)(a1 + 12) = 0;
    }
  }
  return ExFreePoolWithTag(a1);
}
