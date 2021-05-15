// PopComputeTimeout 
 
int __fastcall PopComputeTimeout(int a1, unsigned int a2, int a3)
{
  int result; // r0

  result = a2 + (a3 - dword_61DE58) / 0x3E8u;
  if ( (a2 + (unsigned __int64)((a3 - dword_61DE58) / 0x3E8u)) >> 32 )
    result = -1;
  return result;
}
