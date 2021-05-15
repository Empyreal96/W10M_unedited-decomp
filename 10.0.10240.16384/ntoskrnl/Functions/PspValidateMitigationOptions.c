// PspValidateMitigationOptions 
 
int __fastcall PspValidateMitigationOptions(__int64 a1, __int64 a2)
{
  int result; // r0

  if ( HIDWORD(a1) & 0xFFF88888 | a1 & 0x88888888
    || (a2 & a1) != 0
    || (a1 & 0x3000) == 12288
    || (a1 & 0x30000) == 196608
    || (a1 & 0x300000) == 3145728
    || (a1 & 0x3000000) == 50331648
    || (a1 & 0x30000000) == 805306368
    || (BYTE4(a1) & 0x30) == 48
    || (BYTE4(a1) & 3) == 3
    || (WORD2(a1) & 0x300) == 768
    || (WORD2(a1) & 0x3000) == 12288 )
  {
    result = -1073741811;
  }
  else
  {
    result = 0;
  }
  return result;
}
