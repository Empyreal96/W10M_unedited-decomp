// NtAccessCheck 
 
int __fastcall NtAccessCheck(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  return SeAccessCheckByType(a1, 0, a2, a3, 0, 0, a4, a5, a6, a7, a8, 0);
}
