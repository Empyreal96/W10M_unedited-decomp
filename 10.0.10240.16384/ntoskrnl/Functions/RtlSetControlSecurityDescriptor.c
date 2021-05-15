// RtlSetControlSecurityDescriptor 
 
int __fastcall RtlSetControlSecurityDescriptor(int a1, int a2, int a3)
{
  if ( (a2 & 0xFFFFC03F) != 0 || (a3 & ~a2) != 0 )
    return -1073741811;
  *(_WORD *)(a1 + 2) = *(_WORD *)(a1 + 2) & ~(_WORD)a2 | a3;
  return 0;
}
