// RtlpValidateSDOffsetAndSize 
 
int __fastcall RtlpValidateSDOffsetAndSize(unsigned int a1, unsigned int a2, unsigned int a3, _DWORD *a4)
{
  *a4 = 0;
  if ( a1 < 0x14 || a1 >= a2 || a2 - a1 < a3 || (a1 & 3) != 0 )
    return 0;
  *a4 = a2 - a1;
  return 1;
}
