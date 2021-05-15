// KiFatalExceptionHandler 
 
void __fastcall __noreturn KiFatalExceptionHandler(int a1)
{
  KeBugCheck2(30, *(_DWORD *)a1, *(_DWORD *)(a1 + 12), *(_DWORD *)(a1 + 20), *(_DWORD *)(a1 + 24), 0);
}
