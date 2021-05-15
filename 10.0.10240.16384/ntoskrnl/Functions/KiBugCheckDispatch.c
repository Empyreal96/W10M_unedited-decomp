// KiBugCheckDispatch 
 
void __fastcall __noreturn KiBugCheckDispatch(int a1, int a2, int a3, int a4)
{
  KeBugCheckEx(a1, a2, a3);
}
