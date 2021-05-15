// NtOpenThread 
 
int __fastcall NtOpenThread(int a1, int a2, int a3, int a4)
{
  int v5; // [sp+0h] [bp-10h]

  v5 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  return PsOpenThread(a1, a2, a3, a4, v5, v5);
}
