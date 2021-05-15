// SepCopyClientTokenAndSetSilo 
 
int __fastcall SepCopyClientTokenAndSetSilo(int a1, int a2, int a3, int *a4)
{
  int v6; // r4
  int v7; // r1

  v6 = SeCopyClientToken(a1, a2, a3, 0, 0, a4);
  if ( v6 >= 0 )
  {
    v7 = *(_DWORD *)PsGetServerSiloGlobals(a3);
    if ( v7 != -1 )
      v6 = SeSetSessionIdToken(*a4, v7);
    if ( v6 < 0 || (v6 = SepSetServerSiloToken(*a4, a3), v6 < 0) )
    {
      ObfDereferenceObject(*a4);
      *a4 = 0;
    }
  }
  return v6;
}
