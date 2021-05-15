// PopSafeCopyUnicodeString 
 
int __fastcall PopSafeCopyUnicodeString(unsigned __int16 *a1, unsigned __int16 **a2, int a3, char a4)
{
  unsigned __int16 *v6; // r6
  int v7; // r0
  unsigned int v8; // r0
  unsigned int v10; // r2
  unsigned int v11; // r0

  v6 = *a2;
  v7 = *a1;
  if ( v7 + 2 > (unsigned int)(a3 - (_DWORD)*a2) )
    return -1073741811;
  if ( a4 && v7 )
  {
    v10 = *((_DWORD *)a1 + 1);
    if ( (v10 & 1) != 0 )
      sub_529514();
    v11 = v7 + v10;
    if ( v11 > MmUserProbeAddress || v11 < v10 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  if ( RtlStringCbCopyUnicodeString(v6) < 0 )
    return -1073741811;
  v8 = wcslen(v6);
  if ( *a1 != 2 * v8 )
    return -1073741811;
  *a2 += v8 + 1;
  return 0;
}
