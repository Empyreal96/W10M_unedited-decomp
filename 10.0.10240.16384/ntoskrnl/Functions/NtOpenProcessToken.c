// NtOpenProcessToken 
 
int __fastcall NtOpenProcessToken(int a1, int a2, int a3)
{
  return NtOpenProcessTokenEx(a1, a2, 0, a3);
}
