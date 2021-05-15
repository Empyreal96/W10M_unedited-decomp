// mbstowcs 
 
unsigned int __fastcall mbstowcs(_WORD *a1, unsigned int a2, int a3, unsigned int a4)
{
  unsigned int result; // r0
  _WORD *v8; // r3
  unsigned int v9[4]; // [sp+8h] [bp-10h] BYREF

  v9[0] = a4;
  if ( !a1 )
    return (unsigned int)strlen(a2);
  if ( !a3 )
    return 0;
  v9[0] = mbstrlen(a2);
  if ( RtlMultiByteToUnicodeN(a1, 2 * a3, v9, a2) >= 0 )
  {
    result = v9[0] >> 1;
    v8 = &a1[v9[0] >> 1];
    v9[0] >>= 1;
    if ( !*(v8 - 1) )
      --result;
  }
  else
  {
    gbl_errno = 42;
    *a1 = 0;
    result = -1;
  }
  return result;
}
