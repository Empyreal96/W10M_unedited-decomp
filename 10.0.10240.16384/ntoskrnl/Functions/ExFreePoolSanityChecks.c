// ExFreePoolSanityChecks 
 
unsigned int __fastcall ExFreePoolSanityChecks(unsigned int a1)
{
  unsigned int result; // r0
  int v3; // r1
  int v4; // r2
  int v5; // r0
  int v6; // r5
  int v7; // r0
  int v8; // r0
  unsigned int v9; // r3
  int v10; // r5
  int v11; // r0
  int v12; // r0

  result = KevSkipVerification(a1);
  if ( !result )
  {
    if ( a1 <= MmHighestUserAddress )
      KeBugCheckEx(196, 16, a1, 0, 0);
    if ( !ExpSpecialAllocations || (result = MmIsSpecialPoolAddress(a1, v3, v4)) == 0 )
    {
      if ( (a1 & 0xFFF) != 0 )
      {
        if ( (a1 & 7) != 0 )
          KeBugCheckEx(196, 22, 7739, a1, 0);
        v9 = *(unsigned __int16 *)(a1 - 6);
        if ( (v9 & 0x600) == 0 )
          KeBugCheckEx(196, 19, 7749, a1 - 8, *(_DWORD *)(a1 - 8));
        v10 = (v9 >> 9) & 3;
        if ( ((v9 >> 9) & 1) != 0 )
        {
          result = KeGetCurrentIrql(0);
          if ( result > 1 )
          {
            v11 = KeGetCurrentIrql(result);
            KeBugCheckEx(196, 17, v11, v10, a1);
          }
        }
        else
        {
          result = KeGetCurrentIrql(0);
          if ( result > 2 )
          {
            v12 = KeGetCurrentIrql(result);
            KeBugCheckEx(196, 18, v12, v10, a1);
          }
        }
        if ( (*(_WORD *)(a1 - 6) & 0x400) == 0 )
          KeBugCheckEx(196, 20, 7778, a1 - 8, 0);
      }
      else
      {
        v5 = MmDeterminePoolType(a1);
        v6 = v5;
        if ( (v5 & 1) != 0 )
        {
          result = KeGetCurrentIrql(v5);
          if ( result > 1 )
          {
            v8 = KeGetCurrentIrql(result);
            KeBugCheckEx(196, 17, v8, v6, a1);
          }
        }
        else
        {
          result = KeGetCurrentIrql(v5);
          if ( result > 2 )
          {
            v7 = KeGetCurrentIrql(result);
            KeBugCheckEx(196, 18, v7, v6, a1);
          }
        }
      }
    }
  }
  return result;
}
