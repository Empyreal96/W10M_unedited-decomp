// PspTerminateServerSiloDeferred 
 
int __fastcall PspTerminateServerSiloDeferred(int a1)
{
  _DWORD *v2; // r0
  _DWORD *v3; // r4
  int v4; // r0
  int v5; // r0
  int result; // r0

  v2 = PsGetServerSiloGlobals(a1);
  v3 = v2;
  if ( *v2 != -1 )
    CsrShutdownSynchronization(a1, *v2, v2[5]);
  v4 = v3[5];
  if ( v4 )
  {
    PsTerminateProcess(v4, -1073741077);
    PspWaitForUsermodeExit(v3[5]);
    ObfDereferenceObject(v3[5]);
    v3[5] = 0;
  }
  v5 = v3[6];
  if ( v5 )
  {
    ObfDereferenceObject(v5);
    v3[6] = 0;
  }
  KeWaitForSingleObject(a1 + 128, 0, 0, 0, 0);
  KeSetEvent(a1, 0, 0);
  result = v3[3];
  if ( result )
  {
    result = ZwClose();
    v3[3] = 0;
  }
  if ( a1 )
    result = PspDereferenceSiloObject(a1);
  return result;
}
