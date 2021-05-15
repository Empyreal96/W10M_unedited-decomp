// CmpFlushLockedHives 
 
int __fastcall CmpFlushLockedHives(int a1, int a2, int (*a3)(void))
{
  int v3; // r0
  int v4; // r0

  v3 = a3();
  v4 = ((int (*)(void))((*(_DWORD *)(v3 - 64743) + v3 - 65543) | 1))();
  return (*(int (__fastcall **)(int, int))(v4 + 228))(v4 + 752, 1);
}
