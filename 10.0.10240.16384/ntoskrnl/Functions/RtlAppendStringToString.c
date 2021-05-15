// RtlAppendStringToString 
 
int __fastcall RtlAppendStringToString(unsigned __int16 *a1, unsigned __int16 *a2)
{
  unsigned int v2; // r5
  int v4; // r0

  v2 = *a2;
  if ( !*a2 )
    return 0;
  v4 = *a1;
  if ( (int)(v2 + v4) <= a1[1] )
  {
    memmove(v4 + *((_DWORD *)a1 + 1), *((_DWORD *)a2 + 1), v2);
    *a1 += v2;
    return 0;
  }
  return -1073741789;
}
