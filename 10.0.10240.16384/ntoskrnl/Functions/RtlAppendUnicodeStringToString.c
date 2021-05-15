// RtlAppendUnicodeStringToString 
 
int __fastcall RtlAppendUnicodeStringToString(unsigned __int16 *a1, unsigned __int16 *a2)
{
  unsigned int v2; // r4
  unsigned int v4; // r0
  int v5; // r6
  int v6; // r3

  v2 = *a2;
  if ( !*a2 )
    return 0;
  v4 = *a1;
  if ( (int)(v4 + v2) <= a1[1] )
  {
    v5 = *((_DWORD *)a1 + 1) + 2 * (v4 >> 1);
    memmove(v5, *((_DWORD *)a2 + 1), v2);
    v6 = (unsigned __int16)(*a1 + v2);
    *a1 = v6;
    if ( v6 + 1 < a1[1] )
      *(_WORD *)(v5 + 2 * (v2 >> 1)) = 0;
    return 0;
  }
  return -1073741789;
}
