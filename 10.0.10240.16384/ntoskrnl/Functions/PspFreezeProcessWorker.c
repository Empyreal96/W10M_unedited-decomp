// PspFreezeProcessWorker 
 
int __fastcall PspFreezeProcessWorker(int a1)
{
  _DWORD *v2; // r0
  int v3; // r0

  v2 = PsGetServerSiloGlobals(0);
  if ( a1 != PsInitialSystemProcess && a1 != PsIdleProcess && a1 != v2[5] )
  {
    v3 = PsCaptureExceptionPort(a1);
    if ( v3 )
      ObfDereferenceObject(v3);
    if ( (*(_DWORD *)(a1 + 192) & 4) == 0 )
      PsSuspendProcess(a1);
  }
  return 0;
}
