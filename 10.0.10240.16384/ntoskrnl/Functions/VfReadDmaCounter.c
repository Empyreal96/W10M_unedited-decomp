// VfReadDmaCounter 
 
int __fastcall VfReadDmaCounter(int a1)
{
  int (__fastcall *v2)(int); // r0

  VF_ASSERT_MAX_IRQL(a1);
  v2 = (int (__fastcall *)(int))ViGetRealDmaOperation(a1, 40);
  return v2(a1);
}
