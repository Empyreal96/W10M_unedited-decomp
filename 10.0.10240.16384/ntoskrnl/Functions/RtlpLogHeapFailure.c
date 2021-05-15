// RtlpLogHeapFailure 
 
int __fastcall RtlpLogHeapFailure(int result, int a2, int a3, int a4, int a5)
{
  int v7; // r0

  if ( dword_61830C != a2 )
  {
    dword_618308 = result;
    dword_61830C = a2;
    dword_618310 = a3;
    dword_618314 = a4;
    dword_618318 = a5;
    dword_61831C = 0;
    memset(byte_618338, 0, 128);
    v7 = RtlCaptureStackBackTrace(1u, 0x20u, (int)byte_618338, 0);
    if ( dword_618308 == 3 )
      v7 = RtlpLocateRelatedBlocks(a2, a3);
    RtlpHeapHandleError(v7);
  }
  return result;
}
