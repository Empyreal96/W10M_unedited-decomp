// PsGetThreadId 
 
int __fastcall PsGetThreadId(int a1)
{
  return *(_DWORD *)(a1 + 880);
}
