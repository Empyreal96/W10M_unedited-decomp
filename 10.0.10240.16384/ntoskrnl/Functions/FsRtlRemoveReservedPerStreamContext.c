// FsRtlRemoveReservedPerStreamContext 
 
_DWORD *__fastcall FsRtlRemoveReservedPerStreamContext(int a1, int a2, int a3)
{
  int v3; // r3

  if ( !a1 || (*(_BYTE *)(a1 + 7) & 0xF0u) < 0x30 )
    return FsRtlRemovePerStreamContext(a1, a2, a3);
  v3 = *(_DWORD *)(a1 + 64);
  *(_DWORD *)(a1 + 64) = 0;
  return (_DWORD *)v3;
}
