// PiUEventInit 
 
int __fastcall PiUEventInit(int a1, int a2)
{
  int result; // r0

  result = 0;
  if ( !a1 )
    return sub_965AFC(0);
  if ( a1 == 1 )
    result = McGenEventRegister(
               (int)Symbol_PnPMgrTriggerProvider,
               a2,
               (int)&Symbol_PnPMgrTriggerProvider_Context,
               &Microsoft_Windows_PnPMgrTriggerProviderHandle);
  return result;
}
