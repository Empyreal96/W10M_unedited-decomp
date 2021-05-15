// BgGetContext 
 
int __fastcall BgGetContext(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r0
  int v5; // r4
  int v7; // [sp+0h] [bp-8h] BYREF

  v7 = a4;
  v4 = BgpFwGetCurrentIrql(a1);
  if ( v4 > 2 )
    return 0;
  v5 = 0;
  v7 = 0;
  BgpFwAcquireLock(v4);
  if ( (dword_619018 & 1) != 0 )
  {
    ResFwGetContext(&v7);
    v5 = v7;
  }
  BgpFwReleaseLock();
  return v5;
}
