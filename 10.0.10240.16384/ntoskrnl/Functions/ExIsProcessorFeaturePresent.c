// ExIsProcessorFeaturePresent 
 
int __fastcall ExIsProcessorFeaturePresent(unsigned int a1)
{
  int result; // r0

  if ( a1 >= 0x40 )
    result = 0;
  else
    result = *(unsigned __int8 *)(a1 - 28044);
  return result;
}
