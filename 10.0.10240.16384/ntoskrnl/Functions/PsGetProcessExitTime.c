// PsGetProcessExitTime 
 
_DWORD *__fastcall PsGetProcessExitTime(_DWORD *result)
{
  int v1; // r2

  v1 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  *result = *(_DWORD *)(v1 + 696);
  result[1] = *(_DWORD *)(v1 + 700);
  return result;
}
