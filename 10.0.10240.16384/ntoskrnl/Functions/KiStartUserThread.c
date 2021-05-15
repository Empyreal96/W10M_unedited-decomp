// KiStartUserThread 
 
// positive sp value has been detected, the output may be wrong!
void __noreturn KiStartUserThread()
{
  int v0; // r0
  int (__fastcall *v1)(); // [sp-40h] [bp-40h]

  KfLowerIrql(1);
  v0 = v1();
  ((void (__fastcall *)(int))KiExceptionRestore)(v0);
}
