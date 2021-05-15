// RtlAppendAsciizToString 
 
int __fastcall RtlAppendAsciizToString(unsigned __int16 *a1, unsigned int a2)
{
  char *v4; // r0
  __int16 v5; // r6
  int v6; // r1

  if ( !a2 )
    return 0;
  v4 = strlen(a2);
  v5 = (__int16)v4;
  if ( (unsigned int)v4 <= 0xFFFF )
  {
    v6 = *a1;
    if ( (unsigned int)&v4[v6] <= a1[1] )
    {
      memmove(v6 + *((_DWORD *)a1 + 1), a2, (unsigned int)v4);
      *a1 += v5;
      return 0;
    }
  }
  return -1073741789;
}
