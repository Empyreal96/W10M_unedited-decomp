// SepSidInTokenSidHash 
 
int __fastcall SepSidInTokenSidHash(int a1, unsigned __int16 *a2, unsigned __int16 *a3, int a4, char a5, char a6)
{
  unsigned __int16 *v8; // r6
  int v10; // r0
  int v11; // r3

  v8 = a3;
  if ( a2 && RtlEqualSid((unsigned __int16 *)SePrincipalSelfSid, a3) )
    v8 = a2;
  if ( a6 && RtlEqualSid((unsigned __int16 *)SeOwnerRightsSid, v8) )
    return 1;
  v10 = RtlSidHashLookup(a1, v8);
  if ( !v10 )
    return 0;
  if ( !a5 && v10 == *(_DWORD *)(a1 + 4) )
  {
    if ( (*(_DWORD *)(v10 + 4) & 0x10) != 0 )
      return sub_52D79C();
    return 1;
  }
  v11 = *(_DWORD *)(v10 + 4);
  return (v11 & 4) != 0 || a4 && (v11 & 0x10) != 0;
}
