// NtCreatePagingFile 
 
int __fastcall NtCreatePagingFile(int a1, int a2, int a3)
{
  return MiCreatePagingFile(a1, a2, a3, *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A));
}
