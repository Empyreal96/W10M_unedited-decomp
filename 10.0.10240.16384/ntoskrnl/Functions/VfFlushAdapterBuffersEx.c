// VfFlushAdapterBuffersEx 
 
int __fastcall VfFlushAdapterBuffersEx(int a1, int a2, int a3)
{
  int (__fastcall *v6)(int, int, int); // r8
  int v7; // r0
  int v8; // r4
  int result; // r0
  unsigned int *v10; // r2
  unsigned int v11; // r1

  v6 = (int (__fastcall *)(int, int, int))ViGetRealDmaOperation(a1, 104);
  v7 = ViGetAdapterInformationInternal(a1, 1);
  v8 = v7;
  if ( v7 )
    VF_ASSERT_MAX_IRQL(v7);
  result = v6(a1, a2, a3);
  if ( v8 && !result )
  {
    __dmb(0xBu);
    v10 = (unsigned int *)(v8 + 116);
    do
      v11 = __ldrex(v10);
    while ( __strex(0, v10) );
    __dmb(0xBu);
  }
  return result;
}
