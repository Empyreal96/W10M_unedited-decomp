// IopApcHardError 
 
unsigned int __fastcall IopApcHardError(_DWORD *a1)
{
  IopRaiseHardError(a1[4], a1[5], a1[6]);
  return ExFreePoolWithTag((unsigned int)a1);
}
