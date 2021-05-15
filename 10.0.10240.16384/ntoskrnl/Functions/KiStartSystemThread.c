// KiStartSystemThread 
 
void __fastcall __noreturn KiStartSystemThread(int a1, int a2, int a3, int a4, int a5, int a6, void (__fastcall *a7)(int, int))
{
  KfLowerIrql(1);
  a7(a6, a5);
  KeBugCheck(14);
}
