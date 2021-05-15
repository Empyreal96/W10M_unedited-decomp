// ViPoolLogStackCallout 
 
unsigned int __fastcall ViPoolLogStackCallout(int a1)
{
  unsigned int result; // r0

  result = RtlCaptureStackBackTrace(2u, 0xDu, a1 + 12, 0);
  if ( result < 0xD )
    *(_DWORD *)(a1 + 4 * result + 12) = 0;
  return result;
}
