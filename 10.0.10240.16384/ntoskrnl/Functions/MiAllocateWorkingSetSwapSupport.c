// MiAllocateWorkingSetSwapSupport 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiAllocateWorkingSetSwapSupport(int a1)
{
  int result; // r0
  unsigned int v3; // r3

  result = ExAllocatePoolWithTag(512, 8 * (a1 + 2));
  if ( !result )
    return 0;
  v3 = (result + 19) & 0xFFFFFFFC;
  *(_QWORD *)result = *(_QWORD *)(&a1 - 1);
  *(_DWORD *)(result + 8) = 0;
  *(_DWORD *)(result + 12) = 0;
  return result;
}
