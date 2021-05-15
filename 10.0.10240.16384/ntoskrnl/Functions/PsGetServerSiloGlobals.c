// PsGetServerSiloGlobals 
 
void *__fastcall PsGetServerSiloGlobals(int a1)
{
  void *result; // r0

  if ( a1 == -1 )
    a1 = PsGetCurrentServerSilo();
  if ( a1 )
    result = (void *)sub_50EE28();
  else
    result = &InfrastructureSiloGlobals;
  return result;
}
