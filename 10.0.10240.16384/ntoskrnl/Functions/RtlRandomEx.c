// RtlRandomEx 
 
int __fastcall RtlRandomEx(int *a1)
{
  int result; // r0

  result = ExGenRandom(1) & 0x7FFFFFFF;
  *a1 = result;
  return result;
}
