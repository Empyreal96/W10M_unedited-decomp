// _PnpCmMatchCallbackRoutine 
 
int __fastcall PnpCmMatchCallbackRoutine(int a1, int a2, int a3, int a4)
{
  int v6; // r0
  int v7; // r1
  int result; // r0

  v6 = CmMapCmObjectTypeToPnpObjectType(a3);
  if ( v6 )
    result = (*(int (__fastcall **)(int, int, int, _DWORD))a4)(a1, v7, v6, *(_DWORD *)(a4 + 4));
  else
    result = 0;
  return result;
}
