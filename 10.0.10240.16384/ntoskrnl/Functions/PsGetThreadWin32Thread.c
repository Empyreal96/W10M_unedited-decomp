// PsGetThreadWin32Thread 
 
int __fastcall PsGetThreadWin32Thread(int a1)
{
  int result; // r0

  result = *(_DWORD *)(a1 + 284);
  __dmb(0xBu);
  return result;
}
