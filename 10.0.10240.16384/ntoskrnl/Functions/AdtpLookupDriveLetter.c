// AdtpLookupDriveLetter 
 
int __fastcall AdtpLookupDriveLetter(unsigned __int16 *a1, __int16 *a2, _WORD *a3)
{
  __int16 *v4; // r5
  int v6; // r6
  int result; // r0
  unsigned int v8; // r3
  unsigned int v9; // r8

  v4 = &word_9278D0;
  v6 = 25;
  while ( 1 )
  {
    if ( !*((_DWORD *)v4 + 1) )
      goto LABEL_3;
    v8 = (unsigned __int16)*v4;
    v9 = *a1;
    if ( v8 >= v9 )
      goto LABEL_3;
    *a1 = v8;
    if ( *(_WORD *)(*((_DWORD *)a1 + 1) + 2 * (v8 >> 1)) == 92 )
    {
      if ( RtlEqualUnicodeString(a1, (unsigned __int16 *)v4, 1) )
        break;
    }
    *a1 = v9;
LABEL_3:
    --v6;
    v4 -= 6;
    if ( v6 < 0 )
      return 0;
  }
  *a1 = v9;
  result = 1;
  *a3 = DriveMappingArray[6 * v6];
  *a2 = *v4;
  return result;
}
