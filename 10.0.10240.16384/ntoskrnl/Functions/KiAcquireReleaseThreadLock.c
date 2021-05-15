// KiAcquireReleaseThreadLock 
 
int __fastcall KiAcquireReleaseThreadLock(int a1)
{
  int v2; // r0
  int v3; // r3
  int result; // r0

  v2 = KfRaiseIrql(2);
  __dmb(0xFu);
  v3 = *(_DWORD *)(a1 + 44);
  __dmb(0xBu);
  if ( v3 )
    result = sub_52B31C(v2);
  else
    result = KfLowerIrql(v2);
  return result;
}
