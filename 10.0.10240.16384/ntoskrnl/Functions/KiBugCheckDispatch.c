// KiBugCheckDispatch 
 
void __fastcall __noreturn KiBugCheckDispatch(int a1, int a2, int a3, int a4)
{
  int v4; // r12

  KeBugCheckEx(a1, a2, a3, a4, v4);
}
