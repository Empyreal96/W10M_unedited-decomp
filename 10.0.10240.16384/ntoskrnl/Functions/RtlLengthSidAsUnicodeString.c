// RtlLengthSidAsUnicodeString 
 
int __fastcall RtlLengthSidAsUnicodeString(unsigned __int8 *a1, _DWORD *a2)
{
  int v4; // r1

  if ( RtlValidSid(a1, a2) != 1 )
    return -1073741704;
  if ( a1[2] || a1[3] )
    v4 = 14;
  else
    v4 = 10;
  *a2 = 2 * (11 * a1[1] + v4 + 4);
  return 0;
}
