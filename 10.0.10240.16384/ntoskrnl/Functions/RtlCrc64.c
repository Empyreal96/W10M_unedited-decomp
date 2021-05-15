// RtlCrc64 
 
int __fastcall RtlCrc64(int a1, int a2, int a3)
{
  return RtlpComputeCrcInternal(a1, a2, a3);
}
