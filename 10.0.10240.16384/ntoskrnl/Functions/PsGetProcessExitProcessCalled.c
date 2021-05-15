// PsGetProcessExitProcessCalled 
 
BOOL __fastcall PsGetProcessExitProcessCalled(int a1)
{
  return (*(_DWORD *)(a1 + 192) & 4) != 0;
}
