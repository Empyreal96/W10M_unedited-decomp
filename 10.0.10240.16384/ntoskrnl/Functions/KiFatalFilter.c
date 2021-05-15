// KiFatalFilter 
 
void __fastcall __noreturn KiFatalFilter(int a1, int a2)
{
  KeBugCheckEx(a1, **(_DWORD **)a2, *(_DWORD *)(*(_DWORD *)a2 + 12), *(_DWORD *)a2, *(_DWORD *)(a2 + 4));
}
