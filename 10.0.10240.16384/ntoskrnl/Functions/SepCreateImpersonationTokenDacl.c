// SepCreateImpersonationTokenDacl 
 
int __fastcall SepCreateImpersonationTokenDacl(int a1, int a2, int *a3)
{
  int v3; // r7
  int v7; // r8
  int v8; // r0
  int v9; // r9
  int v10; // r0
  int v11; // r6
  int v13; // [sp+8h] [bp-28h]
  int v14; // [sp+Ch] [bp-24h]

  v3 = 0;
  v7 = 0;
  v13 = **(_DWORD **)(a2 + 148);
  if ( (*(_DWORD *)(a2 + 176) & 0x4000) != 0 )
    v3 = *(_DWORD *)(a2 + 480);
  v8 = **(_DWORD **)(a1 + 148);
  v14 = **(_DWORD **)(a1 + 148);
  if ( (*(_DWORD *)(a1 + 176) & 0x4000) != 0 )
    v7 = *(_DWORD *)(a1 + 480);
  v9 = 4
     * (*(unsigned __int8 *)(SeRestrictedSid + 1)
      + *(unsigned __int8 *)(SeAliasAdminsSid + 1)
      + *(unsigned __int8 *)(v8 + 1)
      + *(unsigned __int8 *)(SeLocalSystemSid + 1)
      + *(unsigned __int8 *)(**(_DWORD **)(a2 + 148) + 1)
      + 22);
  if ( v7 )
    v9 += 4 * (*(unsigned __int8 *)(v7 + 1) + 4);
  if ( v3 )
  {
    if ( v7 && RtlEqualSid((unsigned __int16 *)v3, (unsigned __int16 *)v7) )
      v3 = 0;
    else
      v9 += 4 * (*(unsigned __int8 *)(v3 + 1) + 4);
  }
  v10 = ExAllocatePoolWithTag(1, v9, 538994003);
  v11 = v10;
  if ( !v10 )
    return sub_7FC0B0();
  RtlCreateAcl(v10, v9, 2);
  RtlpAddKnownAce(v11, 2, 0, 983551, v13, 0);
  RtlpAddKnownAce(v11, 2, 0, 983551, v14, 0);
  RtlpAddKnownAce(v11, 2, 0, 983551, SeAliasAdminsSid, 0);
  RtlpAddKnownAce(v11, 2, 0, 983551, SeLocalSystemSid, 0);
  if ( v7 )
    RtlpAddKnownAce(v11, 2, 0, 983551, v7, 0);
  if ( v3 )
    RtlAddAccessAllowedAce(v11, 2, 983551, v3);
  if ( *(_DWORD *)(a2 + 152) || *(_DWORD *)(a1 + 152) )
    RtlAddAccessAllowedAce(v11, 2, 983551, SeRestrictedSid);
  *a3 = v11;
  return 0;
}
