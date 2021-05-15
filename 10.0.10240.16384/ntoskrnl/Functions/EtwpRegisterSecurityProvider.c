// EtwpRegisterSecurityProvider 
 
int __fastcall EtwpRegisterSecurityProvider(int a1, int a2, int a3, int a4)
{
  int *v4; // r5
  int v5; // r4
  int v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[0] = a3;
  v7[1] = a4;
  PsGetMonitorContextServerSilo(EtwSiloMonitor, -1, v7);
  v4 = (int *)v7[0];
  if ( *(_DWORD *)v7[0] )
  {
    v5 = -1073741790;
  }
  else
  {
    *v4 = PsGetCurrentThreadProcessId();
    v5 = 0;
  }
  PsDereferenceMonitorContextServerSilo((int)v4);
  return v5;
}
