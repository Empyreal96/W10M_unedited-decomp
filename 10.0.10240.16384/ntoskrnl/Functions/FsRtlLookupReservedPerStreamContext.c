// FsRtlLookupReservedPerStreamContext 
 
int __fastcall FsRtlLookupReservedPerStreamContext(int a1)
{
  int result; // r0

  if ( !a1 )
    goto LABEL_6;
  if ( (*(_BYTE *)(a1 + 7) & 0xF0u) >= 0x30 )
    return *(_DWORD *)(a1 + 64);
  if ( (*(_BYTE *)(a1 + 6) & 2) != 0 )
    result = sub_51EC70();
  else
LABEL_6:
    result = 0;
  return result;
}
