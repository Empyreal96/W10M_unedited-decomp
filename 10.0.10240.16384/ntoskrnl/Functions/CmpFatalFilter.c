// CmpFatalFilter 
 
void __fastcall __noreturn CmpFatalFilter(int a1, int a2)
{
  KeBugCheckEx(309, **(_DWORD **)a1, *(_DWORD *)(a1 + 4), *(_DWORD *)(a2 + 28), a2);
}
