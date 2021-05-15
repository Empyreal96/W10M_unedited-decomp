// RtlpMuiRegCreateRegistryInfo 
 
_DWORD *RtlpMuiRegCreateRegistryInfo()
{
  _BYTE *v0; // r0
  _DWORD *v1; // r4

  v0 = (_BYTE *)ExAllocatePoolWithTag(1, 100, 1920232557);
  v1 = v0;
  if ( !v0 )
    return 0;
  memset(v0, 0, 100);
  *v1 |= 0x400u;
  return v1;
}
