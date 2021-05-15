// ExDisableResourceBoostLite 
 
int __fastcall ExDisableResourceBoostLite(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  _DWORD v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[1] = a3;
  v7[2] = a4;
  v5 = ExpLockResource(a1, v7);
  *(_WORD *)(a1 + 14) |= 8u;
  return ExpUnlockResource(v5, v7);
}
