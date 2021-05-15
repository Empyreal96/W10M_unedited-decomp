// KeBugCheckEx 
 
void __fastcall __noreturn KeBugCheckEx(int a1, int a2, int a3, int a4, int a5)
{
  KeBugCheck2(a1, a2, a3, a4, a5, 0);
}
