// SeImpersonateClient 
 
int __fastcall SeImpersonateClient(int a1, _DWORD *a2)
{
  return SeImpersonateClientEx(a1, a2);
}
