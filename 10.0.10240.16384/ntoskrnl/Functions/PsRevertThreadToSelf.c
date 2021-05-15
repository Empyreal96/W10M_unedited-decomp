// PsRevertThreadToSelf 
 
int __fastcall PsRevertThreadToSelf(_DWORD *a1)
{
  return PsImpersonateClient(a1, 0, 0, 0, 2);
}
