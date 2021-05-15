// VfPendingFinishLogging 
 
unsigned int __fastcall VfPendingFinishLogging(int a1)
{
  unsigned int result; // r0

  result = RtlCaptureStackBackTrace(1u, 0x3Eu, a1 + 8, 0);
  if ( result < 0x3E )
    *(_DWORD *)(a1 + 4 * result + 8) = 0;
  return result;
}
