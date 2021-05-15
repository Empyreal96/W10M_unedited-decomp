// KeQueryHeteroCpuPolicyThread 
 
int __fastcall KeQueryHeteroCpuPolicyThread(int a1, int a2)
{
  int result; // r0

  if ( !a2 )
    return *(unsigned __int8 *)(a1 + 85);
  result = *(_BYTE *)(a1 + 86) & 0x7F;
  if ( result == 8 )
    result = KiDefaultHeteroCpuPolicy;
  return result;
}
