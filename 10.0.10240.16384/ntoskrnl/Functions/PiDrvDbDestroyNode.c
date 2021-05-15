// PiDrvDbDestroyNode 
 
unsigned int __fastcall PiDrvDbDestroyNode(unsigned int a1)
{
  RtlFreeAnsiString((_DWORD *)(a1 + 8));
  RtlFreeAnsiString((_DWORD *)(a1 + 16));
  RtlFreeAnsiString((_DWORD *)(a1 + 24));
  if ( *(_BYTE *)(a1 + 100) )
    ExDeleteResourceLite((_DWORD *)(a1 + 44));
  if ( *(_DWORD *)(a1 + 264) )
    ZwClose();
  return ExFreePoolWithTag(a1);
}
