// RtlValidProcessProtection 
 
int __fastcall RtlValidProcessProtection(unsigned __int8 a1)
{
  if ( a1 <= 0x31u )
    return sub_81BF10();
  return a1 == 65 || a1 > 0x50u && (a1 <= 0x52u || a1 > 0x60u && a1 <= 0x62u);
}
