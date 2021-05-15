// SepIsImpersonationAllowedDueToCapability 
 
int __fastcall SepIsImpersonationAllowedDueToCapability(int a1, int a2)
{
  int result; // r0
  int v5; // r9
  int v6; // r6
  int v7; // r9
  int v8; // r6
  bool v9; // nf
  unsigned __int8 v10; // [sp+8h] [bp-20h]

  if ( *(_DWORD *)(a2 + 120) != *(_DWORD *)(a1 + 120) || (*(_DWORD *)(*(_DWORD *)(a2 + 192) + 24) & 0x10) != 0 )
    return 0;
  if ( !RtlIsMultiSessionSku(a1) && SepSidInToken(a1, 0, SeDefaultAccountAliasSid, 0, 0) )
    return sub_7F5080();
  if ( SepAllowSessionImpersonationCap )
  {
    if ( (*(_DWORD *)(a1 + 176) & 0x4000) == 0 )
    {
      v7 = SeSessionImpersonationCapabilityGroupSid;
      v8 = SepSidInToken(a1, 0, SeSessionImpersonationCapabilityGroupSid, 0, 0);
      if ( v8 )
      {
        if ( SeTokenIsRestricted(a1) )
          v8 = SepSidInToken(a1, 0, v7, 0, 1);
        if ( v8 )
          return 1;
      }
    }
  }
  if ( (*(_DWORD *)(a2 + 176) & 0x4000) == 0 )
    return 0;
  v5 = SeConstrainedImpersonationCapabilityGroupSid;
  v6 = SepSidInToken(a1, 0, SeConstrainedImpersonationCapabilityGroupSid, 0, 0);
  if ( v6 )
  {
    if ( SeTokenIsRestricted(a1) )
      v6 = SepSidInToken(a1, 0, v5, 0, 1);
    if ( v6 && (*(_DWORD *)(a1 + 176) & 0x4000) == 0 )
      return 1;
  }
  result = SepSidInTokenSidHash(a1 + 492, 0, (unsigned __int16 *)SeConstrainedImpersonationCapabilitySid, 0, 1, 0);
  v10 = result;
  if ( result )
  {
    v9 = SepCheckCapabilities(a1, *(_DWORD *)(a2 + 488), *(_DWORD *)(a2 + 484)) < 0;
    result = v10;
    if ( !v9 && !v10 )
      result = RtlEqualSid(*(unsigned __int16 **)(a1 + 480), *(unsigned __int16 **)(a2 + 480));
  }
  return result;
}
