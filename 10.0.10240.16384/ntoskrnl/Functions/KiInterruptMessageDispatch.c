// KiInterruptMessageDispatch 
 
int __fastcall KiInterruptMessageDispatch(int a1, int a2)
{
  return (*(int (__fastcall **)(int, int, _DWORD))(a1 + 16))(a1, a2, *(_DWORD *)(a1 + 20));
}
