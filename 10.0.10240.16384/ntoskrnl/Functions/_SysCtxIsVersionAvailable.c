// _SysCtxIsVersionAvailable 
 
BOOL __fastcall SysCtxIsVersionAvailable(_DWORD *a1)
{
  return *a1 >= 0xA000000u;
}
