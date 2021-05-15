// KiComputeProcessorDataSize 
 
unsigned int __fastcall KiComputeProcessorDataSize(int a1)
{
  return ((32 * a1 + 20063) & 0xFFFFFF80) + 14464;
}
