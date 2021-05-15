// GetNextWchar 
 
int __fastcall GetNextWchar(unsigned __int16 *a1, int *a2, int a3)
{
  unsigned int v3; // r5

  v3 = 0;
  if ( *a2 < (unsigned int)(*a1 >> 1) )
  {
    v3 = *(unsigned __int16 *)(*((_DWORD *)a1 + 1) + 2 * (*a2)++);
    if ( v3 <= 0x20 )
      goto LABEL_13;
    if ( v3 >= 0x7F )
      return sub_7E816C();
    if ( v3 == 46 && a3 )
LABEL_13:
      JUMPOUT(0x7E817E);
    if ( ((1 << ((int)v3 % 32)) & RtlFatIllegalTable[v3 >> 5]) != 0 )
      v3 = 95;
    if ( v3 >= 0x61 && v3 <= 0x7A )
      v3 = (unsigned __int16)(v3 - 32);
  }
  return v3;
}
