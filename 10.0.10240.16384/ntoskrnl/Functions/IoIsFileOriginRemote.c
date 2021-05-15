// IoIsFileOriginRemote 
 
BOOL __fastcall IoIsFileOriginRemote(int a1)
{
  return (*(_DWORD *)(a1 + 44) & 0x1000000) != 0;
}
