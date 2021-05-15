// _SysCtxInternalEnumSubkeyCallback 
 
int __fastcall SysCtxInternalEnumSubkeyCallback(int a1, int a2, int a3)
{
  return (*(int (__fastcall **)(_DWORD, int, int, _DWORD))(a3 + 4))(*(_DWORD *)a3, a1, a2, *(_DWORD *)(a3 + 8));
}
