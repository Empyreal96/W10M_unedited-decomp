// NtDisableLastKnownGood 
 
int NtDisableLastKnownGood()
{
  int v0; // r4
  int v1; // r5
  int v3; // [sp+8h] [bp-20h] BYREF
  int v4[3]; // [sp+Ch] [bp-1Ch] BYREF
  __int16 v5; // [sp+18h] [bp-10h] BYREF
  __int16 v6; // [sp+1Ah] [bp-Eh]
  const __int16 *v7; // [sp+1Ch] [bp-Ch]

  v3 = 0;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) != 1 )
    return -1073741790;
  if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, 1, (int)&SeTcbPrivilege) )
    return -1073741727;
  v0 = PnpCtxGetCachedContextBaseKey((_DWORD *)PiPnpRtlCtx, 4, v4);
  if ( v0 >= 0 )
  {
    v6 = 24;
    v5 = 22;
    v7 = L"Control\\Pnp";
    v0 = IopCreateRegistryKeyEx(&v3, v4[0], (int)&v5, 983103, 0, 0);
    v1 = v3;
    if ( v0 >= 0 )
    {
      v4[1] = 1;
      v6 = 22;
      v5 = 20;
      v7 = L"DisableLKG";
      v0 = ZwSetValueKey();
    }
    if ( v1 )
      ZwClose();
  }
  return v0;
}
