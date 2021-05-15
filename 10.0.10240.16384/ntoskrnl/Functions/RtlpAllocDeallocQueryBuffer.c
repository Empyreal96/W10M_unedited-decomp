// RtlpAllocDeallocQueryBuffer 
 
int __fastcall RtlpAllocDeallocQueryBuffer(int *a1, unsigned int a2, int a3, int *a4)
{
  int v5; // r6
  int v6; // r4

  v5 = 0;
  v6 = 0;
  if ( a2 )
    ExFreePoolWithTag(a2);
  if ( a1 )
  {
    v5 = ExAllocatePoolWithTag(1, *a1, 1987211602);
    if ( !v5 )
      v6 = -1073741801;
  }
  if ( a4 )
    *a4 = v6;
  return v5;
}
