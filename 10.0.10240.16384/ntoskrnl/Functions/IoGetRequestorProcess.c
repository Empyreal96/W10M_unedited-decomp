// IoGetRequestorProcess 
 
unsigned int __fastcall IoGetRequestorProcess(int a1)
{
  int v1; // r2

  v1 = *(_DWORD *)(a1 + 80);
  if ( (*(_DWORD *)(a1 + 8) & 0x2000) != 0 )
    return *(_DWORD *)(a1 + 48) & 0xFFFFFFFC;
  if ( !v1 )
    return 0;
  if ( *(_BYTE *)(a1 + 38) )
  {
    if ( *(_BYTE *)(a1 + 38) == 1 )
      return *(_DWORD *)(v1 + 116);
    return 0;
  }
  return *(_DWORD *)(v1 + 336);
}
