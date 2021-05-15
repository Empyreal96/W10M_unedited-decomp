// PsGetProcessJob 
 
int __fastcall PsGetProcessJob(int a1)
{
  int result; // r0

  result = *(_DWORD *)(a1 + 288);
  __dmb(0xBu);
  return result;
}
