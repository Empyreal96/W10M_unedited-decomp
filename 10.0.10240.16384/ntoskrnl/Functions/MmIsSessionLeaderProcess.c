// MmIsSessionLeaderProcess 
 
BOOL __fastcall MmIsSessionLeaderProcess(int a1)
{
  return a1 == *((_DWORD *)PsGetCurrentServerSiloGlobals() + 7);
}
