// RtlCrc32 
 
int __fastcall RtlCrc32(unsigned int a1, unsigned int a2, int a3)
{
  return RtlpComputeCrcInternal(a1, a2, a3, 0, &Crc32Ctrl);
}
