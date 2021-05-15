// PsGetCurrentServerSiloGlobals 
 
void *PsGetCurrentServerSiloGlobals()
{
  return PsGetServerSiloGlobals(-1);
}
