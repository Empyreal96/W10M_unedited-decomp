// VfAllocateCommonBufferEx 
 
int __fastcall VfAllocateCommonBufferEx(int a1, int a2, int a3, int a4)
{
  int (__fastcall *v8)(int, int, int, int); // r5
  int v9; // r10
  int result; // r0
  unsigned int *v11; // r2
  unsigned int v12; // r1

  v8 = (int (__fastcall *)(int, int, int, int))ViGetRealDmaOperation(a1, 76);
  v9 = ViGetAdapterInformationInternal(a1, 1);
  result = v8(a1, a2, a3, a4);
  if ( result && v9 )
  {
    __dmb(0xBu);
    v11 = (unsigned int *)(v9 + 100);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 + 1, v11) );
    __dmb(0xBu);
  }
  return result;
}
