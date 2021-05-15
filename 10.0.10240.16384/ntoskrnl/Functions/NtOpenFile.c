// NtOpenFile 
 
int __fastcall NtOpenFile(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return IopCreateFile(a1, a2, a3, a4, 0, 0, a5, 1, a6, 0, 0, 0, 0, 0, 32, 0);
}
