// SeQueryTrustedPlatformModuleInformation 
 
int __fastcall SeQueryTrustedPlatformModuleInformation(_DWORD *a1, unsigned int a2, _DWORD *a3)
{
  int result; // r0

  result = 0;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    return -1073741790;
  if ( a2 >= 4 )
  {
    *a1 = 0;
    if ( SepOsLoaderTpmDriverLoaded )
      *a1 = 1;
    if ( PnpCoreDriverGroupLoadPhase > 2 )
      *a1 |= 2u;
  }
  else
  {
    if ( a3 )
      *a3 = 4;
    result = -1073741820;
  }
  return result;
}
