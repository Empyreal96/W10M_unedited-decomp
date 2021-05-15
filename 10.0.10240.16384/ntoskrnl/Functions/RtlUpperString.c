// RtlUpperString 
 
int __fastcall RtlUpperString(int result, unsigned __int16 *a2)
{
  unsigned int v2; // r4
  _BYTE *v3; // r5
  char *v4; // r6
  int v5; // t1

  v2 = *a2;
  v3 = *(_BYTE **)(result + 4);
  v4 = (char *)*((_DWORD *)a2 + 1);
  if ( v2 > *(unsigned __int16 *)(result + 2) )
    v2 = *(unsigned __int16 *)(result + 2);
  for ( *(_WORD *)result = v2; v2; --v2 )
  {
    v5 = *v4++;
    result = RtlUpperChar(v5);
    *v3++ = result;
  }
  return result;
}
