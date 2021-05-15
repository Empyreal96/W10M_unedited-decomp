// wcstombs 
 
int __fastcall wcstombs(int a1, unsigned __int16 *a2, int a3)
{
  int v6; // r0
  unsigned int v7; // r0
  int result; // r0
  int v9[4]; // [sp+8h] [bp-10h] BYREF

  v9[0] = 0;
  if ( a1 )
  {
    wcslen(a2);
    v6 = RtlUnicodeToMultiByteN(a1, a3, v9, a2);
  }
  else
  {
    v7 = wcslen(a2);
    v6 = RtlUnicodeToMultiByteSize(v9, a2, 2 * (v7 + 1));
  }
  if ( v6 >= 0 )
    return v9[0] - 1;
  result = -1;
  gbl_errno = 42;
  return result;
}
