// PspExpandLimit 
 
int __fastcall PspExpandLimit(int a1, int a2, int a3, int a4)
{
  char *v5; // r8
  int v8; // r4
  int v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[0] = a4;
  v5 = (char *)&PspQuotaExpansionDescriptors + 28 * a1;
  PspLockQuotaExpansion(v5, v10);
  v8 = (*((int (__fastcall **)(int, _DWORD, int, int))v5 + 3))(a1, 0, a3, a4);
  PspUnlockQuotaExpansion(v5, LOBYTE(v10[0]));
  return v8;
}
