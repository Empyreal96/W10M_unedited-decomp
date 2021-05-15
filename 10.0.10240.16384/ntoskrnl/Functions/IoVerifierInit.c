// IoVerifierInit 
 
int __fastcall IoVerifierInit(char a1)
{
  IovpInitCalled = 1;
  IopUpdateFunctionPointers(1, 1, 0, (int)&IovpInitCalled);
  return IoVerifierCheckForSettingsChange(a1);
}
