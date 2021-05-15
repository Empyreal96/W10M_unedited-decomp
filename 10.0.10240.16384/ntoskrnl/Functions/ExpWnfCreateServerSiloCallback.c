// ExpWnfCreateServerSiloCallback 
 
int __fastcall ExpWnfCreateServerSiloCallback(int a1, int a2, int a3, int a4)
{
  int v5; // r5
  int v6; // r4
  int v8[6]; // [sp+8h] [bp-18h] BYREF

  v8[0] = a3;
  v8[1] = a4;
  v5 = PsAllocateMonitorContextServerSilo(ExpWnfSiloMonitor, 4, v8);
  if ( v5 >= 0 )
  {
    v6 = v8[0];
    *(_DWORD *)v8[0] = 0;
    v5 = PsSetMonitorContextServerSilo(ExpWnfSiloMonitor, a1, 1, v6, 0);
    PsDereferenceMonitorContextServerSilo(v6);
  }
  return v5;
}
