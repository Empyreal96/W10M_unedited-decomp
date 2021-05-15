// RtlpCompareKnownAces 
 
int __fastcall RtlpCompareKnownAces(unsigned __int16 *a1, unsigned __int16 *a2)
{
  int v2; // r6

  v2 = *(unsigned __int8 *)a2;
  if ( *((unsigned __int8 *)RtlBaseAceType + v2) != *((unsigned __int8 *)RtlBaseAceType + *(unsigned __int8 *)a1) )
    return 0;
  if ( *((_BYTE *)RtlIsSystemAceType + v2) )
    return sub_7C5970();
  return RtlEqualSid(a2 + 4, a1 + 4);
}
