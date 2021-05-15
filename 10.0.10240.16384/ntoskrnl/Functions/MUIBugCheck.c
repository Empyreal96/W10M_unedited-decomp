// MUIBugCheck 
 
void __fastcall __noreturn MUIBugCheck(int a1)
{
  KeBugCheckEx(298, 2, a1, 0, 0);
}
