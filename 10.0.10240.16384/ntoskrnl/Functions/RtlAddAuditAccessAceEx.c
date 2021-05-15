// RtlAddAuditAccessAceEx 
 
int __fastcall RtlAddAuditAccessAceEx(unsigned __int8 *a1, unsigned int a2, int a3, int a4, _BYTE *a5, char a6, char a7)
{
  if ( a6 )
    a3 |= 0x40u;
  if ( a7 )
    a3 |= 0x80u;
  return RtlpAddKnownAce(a1, a2, a3, a4, a5, 2u);
}
