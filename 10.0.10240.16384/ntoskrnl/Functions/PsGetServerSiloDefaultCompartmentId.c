// PsGetServerSiloDefaultCompartmentId 
 
int __fastcall PsGetServerSiloDefaultCompartmentId(int a1)
{
  return *((_DWORD *)PsGetServerSiloGlobals(a1) + 15);
}
