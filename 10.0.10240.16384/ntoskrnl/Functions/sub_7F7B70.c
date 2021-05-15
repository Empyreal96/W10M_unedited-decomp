// sub_7F7B70 
 
void sub_7F7B70()
{
  const char *v0; // r5
  int v1; // r4

  v1 = PsGetProcessServerSilo((int)v0);
  if ( PsGetServerSiloState(v1) != 2 )
    PspCatchCriticalBreak("Terminating critical process 0x%p (%s)\n", v0, v0 + 360);
  if ( v1 )
    PspDereferenceSiloObject(v1);
  JUMPOUT(0x71CCA2);
}
