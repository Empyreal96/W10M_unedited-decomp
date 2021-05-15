// RtlAddAccessAllowedObjectAce 
 
int __fastcall RtlAddAccessAllowedObjectAce(unsigned __int8 *a1, unsigned int a2, int a3, int a4, int a5, int a6, _BYTE *a7)
{
  int result; // r0

  if ( a5 || a6 )
    result = RtlpAddKnownObjectAce(a1, a2, a3, a4, a5, a6, a7, 5);
  else
    result = RtlpAddKnownAce(a1, a2, a3, a4, a7, 0);
  return result;
}
