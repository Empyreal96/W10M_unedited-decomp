// IovpLogStackCallout 
 
unsigned int __fastcall IovpLogStackCallout(int a1)
{
  unsigned int result; // r0

  result = RtlCaptureStackBackTrace(2u, 0xCu, a1 + 16, 0);
  if ( result < 0xC )
    *(_DWORD *)(a1 + 4 * result + 16) = 0;
  return result;
}
