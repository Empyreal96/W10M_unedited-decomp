// ExAllocatePoolSanityChecks 
 
unsigned int __fastcall __spoils<R0,R2,R3,R12> ExAllocatePoolSanityChecks(int a1, int a2, int *a3, int a4)
{
  int v5; // r6
  int v9; // r0
  int v10; // r3
  int v11; // r0
  unsigned int result; // r0
  int v13; // r0
  int v14; // r0

  v5 = *a3;
  if ( *a3 )
  {
    if ( v5 == 541542722 )
    {
      v9 = VerifierBugCheckIfAppropriate(194, 156, a1 & 0xFFFFFF7F, a2, a4);
      v10 = 828662082;
    }
    else
    {
      v9 = ExpIsPoolTagPrintable(*a3);
      if ( v9 )
        goto LABEL_8;
      v9 = VerifierBugCheckIfAppropriate(194, 157, v5, a1 & 0xFFFFFF7F, a4);
      v10 = 845439298;
    }
  }
  else
  {
    v9 = VerifierBugCheckIfAppropriate(194, 155, a1 & 0xFFFFFF7F, a2, a4);
    v10 = 811884866;
  }
  *a3 = v10;
LABEL_8:
  if ( !a2 )
  {
    v11 = KeGetCurrentIrql(v9);
    v9 = VerifierBugCheckIfAppropriate(196, 0, v11, a1 & 0xFFFFFF7F, 0);
  }
  if ( (a1 & 1) != 0 )
  {
    result = KeGetCurrentIrql(v9);
    if ( result > 1 )
    {
      v14 = KeGetCurrentIrql(result);
      KeBugCheckEx(196, 1, v14, a1 & 0xFFFFFF7F, a2);
    }
  }
  else
  {
    result = KeGetCurrentIrql(v9);
    if ( result > 2 )
    {
      v13 = KeGetCurrentIrql(result);
      KeBugCheckEx(196, 2, v13, a1 & 0xFFFFFF7F, a2);
    }
  }
  return result;
}
