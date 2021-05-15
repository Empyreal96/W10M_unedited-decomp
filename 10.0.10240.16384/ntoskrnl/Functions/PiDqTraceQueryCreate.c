// PiDqTraceQueryCreate 
 
int PiDqTraceQueryCreate()
{
  int result; // r0

  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x400000) != 0 )
    result = sub_7C7E2C();
  else
    result = 0;
  return result;
}
