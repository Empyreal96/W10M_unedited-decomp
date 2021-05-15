// FsRtlIsEcpAcknowledged 
 
BOOL __fastcall FsRtlIsEcpAcknowledged(int a1)
{
  return (*(_DWORD *)(a1 - 16) & 8) != 0;
}
