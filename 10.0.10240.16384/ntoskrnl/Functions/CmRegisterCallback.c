// CmRegisterCallback 
 
int __fastcall CmRegisterCallback(int a1, int a2)
{
  return CmpRegisterCallbackInternal(a1, a2, &CmLegacyAltitude, 1);
}
