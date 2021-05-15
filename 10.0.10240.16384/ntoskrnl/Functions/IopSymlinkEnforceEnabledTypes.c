// IopSymlinkEnforceEnabledTypes 
 
int __fastcall IopSymlinkEnforceEnabledTypes(BOOL a1, int a2, int a3)
{
  char v5; // r5
  int result; // r0
  _BYTE *v8; // r4
  bool v9; // zf
  _BYTE *v10[6]; // [sp+8h] [bp-18h] BYREF

  v10[0] = 0;
  v5 = IopSymlinkEnabledTypes;
  if ( IopSymlinkEnabledTypes == 15 )
    return 0;
  result = FsRtlFindExtraCreateParameter(a3, (unsigned int)&GUID_ECP_NETWORK_OPEN_CONTEXT, v10, 0);
  if ( result >= 0 || result == -1073741275 )
  {
    v8 = v10[0];
    if ( v10[0] && FsRtlIsEcpFromUserMode((int)v10[0]) )
      goto LABEL_6;
    if ( !a1 )
    {
      if ( !v8 )
        goto LABEL_6;
      a1 = *((_DWORD *)v8 + 4) == 2;
    }
    if ( !a2 && !v8 )
    {
      result = FsRtlAllocateExtraCreateParameter(&GUID_ECP_NETWORK_OPEN_CONTEXT, 0x1Cu, 0, 0, 1767075657, v10);
      if ( result < 0 )
        return result;
      v8 = v10[0];
      memset(v10[0], 0, 28);
      *(_WORD *)v8 = 28;
      *((_WORD *)v8 + 1) = 0;
      FsRtlInsertExtraCreateParameter(a3, (int)v8);
    }
    if ( a1 )
    {
      if ( (v5 & 3) == 0 )
        goto LABEL_6;
      if ( !a2 )
      {
        if ( (v5 & 2) == 0 )
          *((_DWORD *)v8 + 1) = 2;
        if ( (v5 & 1) != 0 )
          return 0;
        goto LABEL_31;
      }
      v9 = (v5 & 1) == 0;
    }
    else
    {
      if ( (v5 & 0xC) == 0 )
        goto LABEL_6;
      if ( !a2 )
      {
        if ( (v5 & 8) == 0 )
          *((_DWORD *)v8 + 1) = 2;
        if ( (v5 & 4) != 0 )
          return 0;
LABEL_31:
        *((_DWORD *)v8 + 1) = 1;
        return 0;
      }
      v9 = (v5 & 4) == 0;
    }
    if ( !v9 )
      return 0;
LABEL_6:
    result = -1073740011;
  }
  return result;
}
