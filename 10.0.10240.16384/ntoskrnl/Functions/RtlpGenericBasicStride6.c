// RtlpGenericBasicStride6 
 
int __fastcall RtlpGenericBasicStride6(int a1, int a2, int a3)
{
  int v4; // r2
  int result; // r0

  if ( RtlpGenericStrideWorker(0, -1, a3, a1) )
    result = RtlpGenericStrideWorker(-1, 0, v4, a1);
  else
    result = 0;
  return result;
}
