// AlpcpGetDataFromUserVaSafe 
 
int __fastcall AlpcpGetDataFromUserVaSafe(int a1, int a2)
{
  return memmove(a2, *(_DWORD *)(a1 + 88), *(unsigned __int16 *)(a1 + 120));
}
