// PopFxBugCheck 
 
void __fastcall __noreturn PopFxBugCheck(int a1, int a2, int a3, int a4)
{
  KeBugCheckEx(160, a1, a2, a3, a4);
}
