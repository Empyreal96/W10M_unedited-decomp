// PsGetThreadTeb 
 
int __fastcall PsGetThreadTeb(int a1)
{
  return *(_DWORD *)(a1 + 156);
}
