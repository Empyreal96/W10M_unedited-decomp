// MiIssueNoPtesBugcheck 
 
void __fastcall __noreturn MiIssueNoPtesBugcheck(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r0
  int v7; // r0
  int v8[4]; // [sp+8h] [bp-10h] BYREF

  v8[0] = a3;
  v8[1] = a4;
  v5 = MiGetHighestPteConsumer(v8);
  if ( v5 )
  {
    v6 = MmGetNumberOfFreeSystemPtes();
    KeBugCheckEx(216, v5, v8[0], v6, 0);
  }
  v7 = MmGetNumberOfFreeSystemPtes();
  KeBugCheckEx(63, 0, a1, v7, 0);
}
