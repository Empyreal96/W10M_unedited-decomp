// FsRtlInsertReservedPerStreamContext 
 
int __fastcall FsRtlInsertReservedPerStreamContext(int a1, int a2)
{
  if ( !a1 || (*(_BYTE *)(a1 + 6) & 2) == 0 )
    return -1073741808;
  if ( (*(_BYTE *)(a1 + 7) & 0xF0u) < 0x30 )
    return sub_523530();
  *(_DWORD *)(a1 + 64) = a2;
  return 0;
}
