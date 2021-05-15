// PsIsProcessBeingDebugged 
 
BOOL __fastcall PsIsProcessBeingDebugged(int a1)
{
  return *(_DWORD *)(a1 + 340) != 0;
}
