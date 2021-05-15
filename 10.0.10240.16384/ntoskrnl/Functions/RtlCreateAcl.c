// RtlCreateAcl 
 
int __fastcall RtlCreateAcl(int a1, unsigned int a2, int a3)
{
  if ( a2 < 8 )
    return -1073741789;
  if ( (unsigned int)(a3 - 2) > 2 || a2 > 0xFFFC )
    return -1073741811;
  *(_BYTE *)a1 = a3;
  *(_BYTE *)(a1 + 1) = 0;
  *(_WORD *)(a1 + 4) = 0;
  *(_WORD *)(a1 + 6) = 0;
  *(_WORD *)(a1 + 2) = a2 & 0xFFFC;
  return 0;
}
