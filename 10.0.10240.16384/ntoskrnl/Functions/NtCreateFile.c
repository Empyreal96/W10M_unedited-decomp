// NtCreateFile 
 
int __fastcall NtCreateFile(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  return IopCreateFile(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, 0, 0, 0, 32, 0);
}
