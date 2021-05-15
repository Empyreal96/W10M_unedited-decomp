// RtlAddAuditAccessAce 
 
int __fastcall RtlAddAuditAccessAce(unsigned __int8 *a1, int a2, int a3, _BYTE *a4)
{
  return RtlpAddKnownAce(a1, 2u, 192, a3, a4, 2u);
}
