// ExAllocateCacheAwareRundownProtection 
 
int __fastcall ExAllocateCacheAwareRundownProtection(int a1, int a2)
{
  int v4; // r0
  int *v5; // r4
  int v6; // r6
  bool v7; // cc
  int v8; // r0
  int v10; // r3
  unsigned int i; // r5
  unsigned int v12; // r0
  int v13; // r1
  int v14; // r5

  v4 = ExAllocatePoolWithTag(a1, 16, a2);
  v5 = (int *)v4;
  if ( v4 )
  {
    v6 = KeNumberProcessors_0;
    v7 = (unsigned int)KeNumberProcessors_0 > 1;
    *(_DWORD *)(v4 + 12) = KeNumberProcessors_0;
    if ( v7 )
      v14 = KeGetRecommendedSharedDataAlignment();
    else
      v14 = 4;
    v5[2] = v14;
    v8 = ExAllocatePoolWithTag(a1, v6 * v14, a2);
    if ( !v8 )
      return sub_7CFDDC();
    if ( (unsigned int)v5[3] > 1 && ((v14 - 1) & v8) != 0 )
    {
      ExFreePoolWithTag(v8);
      v8 = ExAllocatePoolWithTag(a1, (v5[3] + 1) * v14, a2);
      if ( !v8 )
        return sub_7CFDDC();
      v10 = (v8 + v14 - 1) & ~(v14 - 1);
    }
    else
    {
      v10 = v8;
    }
    *v5 = v10;
    v5[1] = v8;
    for ( i = 0; i < v5[3]; *(_DWORD *)(v13 * v5[2] + *v5) = 0 )
    {
      v12 = v5[3];
      if ( !v12 )
        __brkdiv0();
      v13 = i % v12;
      ++i;
    }
  }
  return (int)v5;
}
