// RtlCopyUnicodeString 
 
int __fastcall RtlCopyUnicodeString(unsigned __int16 *a1, unsigned __int16 *a2)
{
  int result; // r0
  unsigned int v4; // r5
  int v5; // r6
  int v6; // r1
  int v7; // r0

  if ( !a2 )
    return sub_50C3F4();
  v4 = *a2;
  v5 = *((_DWORD *)a1 + 1);
  if ( v4 > a1[1] )
    v4 = a1[1];
  v6 = *((_DWORD *)a2 + 1);
  v7 = *((_DWORD *)a1 + 1);
  *a1 = v4;
  result = memmove(v7, v6, v4);
  if ( (unsigned int)*a1 + 2 <= a1[1] )
    *(_WORD *)(v5 + 2 * (v4 >> 1)) = 0;
  return result;
}
