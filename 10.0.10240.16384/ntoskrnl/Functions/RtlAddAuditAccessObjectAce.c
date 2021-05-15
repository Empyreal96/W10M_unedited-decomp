// RtlAddAuditAccessObjectAce 
 
int __fastcall RtlAddAuditAccessObjectAce(unsigned __int8 *a1, unsigned int a2, int a3, int a4, int a5, int a6, _BYTE *a7, char a8, char a9)
{
  int result; // r0

  if ( a8 )
    a3 |= 0x40u;
  if ( a9 )
    a3 |= 0x80u;
  if ( a5 || a6 )
    result = RtlpAddKnownObjectAce(a1, a2, a3, a4, a5, a6, a7, 7);
  else
    result = RtlpAddKnownAce(a1, a2, a3, a4, a7, 2u);
  return result;
}
