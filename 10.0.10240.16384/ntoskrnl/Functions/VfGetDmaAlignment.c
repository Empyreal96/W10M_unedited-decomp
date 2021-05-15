// VfGetDmaAlignment 
 
int __fastcall VfGetDmaAlignment(int a1)
{
  int (__fastcall *v2)(int); // r3
  int result; // r0

  VF_ASSERT_IRQL(0);
  v2 = (int (__fastcall *)(int))ViGetRealDmaOperation(a1, 36);
  if ( v2 )
    result = v2(a1);
  else
    result = 1;
  return result;
}
