// PnpDiagInitialize 
 
int __fastcall PnpDiagInitialize(int a1, int a2)
{
  int v2; // r5
  int v3; // r0
  int v4; // r0

  v2 = 0;
  v3 = McGenEventRegister(
         (int)MS_KernelPnP_Provider,
         a2,
         (int)&MS_KernelPnP_Provider_Context,
         &Microsoft_Windows_Kernel_PnPHandle);
  PnpEtwHandle = Microsoft_Windows_Kernel_PnPHandle;
  if ( v3 < 0 )
    v2 = v3;
  v4 = EtwRegister((int)MS_KernelPnP_Rundown_Provider, (int)PnpDiagRundownRegisterCallback, 0);
  if ( v4 < 0 )
    v2 = v4;
  return v2;
}
