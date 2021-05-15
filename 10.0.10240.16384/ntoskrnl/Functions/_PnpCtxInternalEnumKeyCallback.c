// _PnpCtxInternalEnumKeyCallback 
 
int __fastcall PnpCtxInternalEnumKeyCallback(int a1, int a2, int a3, int a4)
{
  return (*(int (__fastcall **)(_DWORD, int, int, _DWORD))(a4 + 4))(*(_DWORD *)a4, a2, a3, *(_DWORD *)(a4 + 8));
}
