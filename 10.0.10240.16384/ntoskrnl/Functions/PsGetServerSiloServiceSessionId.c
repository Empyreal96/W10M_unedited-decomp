// PsGetServerSiloServiceSessionId 
 
int __fastcall PsGetServerSiloServiceSessionId(int a1)
{
  return *(_DWORD *)PsGetServerSiloGlobals(a1);
}
