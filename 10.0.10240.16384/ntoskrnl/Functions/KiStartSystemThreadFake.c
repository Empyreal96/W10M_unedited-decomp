// KiStartSystemThreadFake 
 
void __fastcall __noreturn KiStartSystemThreadFake(int a1, int a2, int a3, int a4, int a5, int a6, void (__fastcall *a7)(int, int))
{
  KiStartSystemThread(a1, a2, a3, a4, a5, a6, a7);
}
