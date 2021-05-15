// PerfDiagInitialize 
 
int PerfDiagInitialize()
{
  int result; // r0
  unsigned int v1; // [sp+8h] [bp-20h]
  int v2; // [sp+Ch] [bp-1Ch]
  int v3; // [sp+10h] [bp-18h] BYREF
  __int16 v4; // [sp+14h] [bp-14h]
  __int16 v5; // [sp+16h] [bp-12h]
  char v6; // [sp+18h] [bp-10h]
  char v7; // [sp+19h] [bp-Fh]
  char v8; // [sp+1Ah] [bp-Eh]
  char v9; // [sp+1Bh] [bp-Dh]
  char v10; // [sp+1Ch] [bp-Ch]
  char v11; // [sp+1Dh] [bp-Bh]
  char v12; // [sp+1Eh] [bp-Ah]
  char v13; // [sp+1Fh] [bp-9h]

  dword_61CB40 = 0;
  dword_61CB44 = 0;
  EtwRegister((int)&MS_Kernel_BootDiagnostics_SystemProxy_Provider, (int)PerfDiagpBootSystemProxyCallback, 0);
  EtwRegister((int)&MS_Kernel_BootDiagnostics_UserProxy_Provider, (int)PerfDiagpBootUserProxyCallback, 0);
  EtwRegister((int)&MS_Kernel_SecondaryLogonDiagnostics_Proxy_Provider, (int)PerfDiagpSecondaryLogonProxyCallback, 0);
  EtwRegister((int)&MS_Kernel_ShutdownDiagnostics_Proxy_Provider, (int)PerfDiagpShutdownProxyCallback, 0);
  result = EtwRegister((int)MS_Kernel_BootDiagnostics_Provider, 0, 0);
  if ( result >= 0 )
  {
    v3 = 1729382729;
    v4 = 20786;
    v5 = 18521;
    v6 = 0x80;
    v7 = 54;
    v8 = -89;
    v9 = 55;
    v10 = -76;
    v11 = 56;
    v12 = 37;
    v13 = -40;
    EtwWriteStartScenario(v1, v2, (int)KMBootEvt_SystemBoot_Start, (int)&v3);
    result = EtwUnregister(v1);
  }
  return result;
}
