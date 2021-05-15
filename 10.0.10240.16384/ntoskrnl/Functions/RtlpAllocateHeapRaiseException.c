// RtlpAllocateHeapRaiseException 
 
int __fastcall RtlpAllocateHeapRaiseException(int a1)
{
  int v2[24]; // [sp+0h] [bp-60h] BYREF

  v2[5] = a1;
  v2[0] = -1073741801;
  v2[2] = 0;
  v2[4] = 1;
  v2[1] = 0;
  v2[3] = (int)RtlRaiseException;
  return RtlRaiseException((int)v2);
}
