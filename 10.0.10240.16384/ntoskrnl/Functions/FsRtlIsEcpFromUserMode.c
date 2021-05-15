// FsRtlIsEcpFromUserMode 
 
BOOL __fastcall FsRtlIsEcpFromUserMode(int a1)
{
  return (*(_DWORD *)(a1 - 16) & 0x10) != 0;
}
