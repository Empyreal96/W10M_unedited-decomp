// EtwpCompareGuid 
 
int __fastcall EtwpCompareGuid(unsigned int a1, unsigned int a2)
{
  return memcmp(a1, a2, 16);
}
