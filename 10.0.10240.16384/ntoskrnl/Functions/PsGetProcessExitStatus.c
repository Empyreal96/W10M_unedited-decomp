// PsGetProcessExitStatus 
 
int __fastcall PsGetProcessExitStatus(int a1)
{
  return *(_DWORD *)(a1 + 632);
}
