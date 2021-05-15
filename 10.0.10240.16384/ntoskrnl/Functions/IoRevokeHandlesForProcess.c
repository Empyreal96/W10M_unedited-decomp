// IoRevokeHandlesForProcess 
 
int __fastcall IoRevokeHandlesForProcess(int a1, int a2)
{
  int v4; // r4
  int v5; // r4
  int v6; // r6
  int v7; // r0
  int v8; // r6
  int v10[2]; // [sp+10h] [bp-A0h] BYREF
  int v11[6]; // [sp+18h] [bp-98h] BYREF
  _DWORD v12[28]; // [sp+30h] [bp-80h] BYREF

  v10[0] = 0;
  v4 = PsReferencePrimaryToken(a2);
  SeQueryInformationToken(v4, 29, v10);
  ObfDereferenceObjectWithTag(v4);
  if ( !v10[0] )
    return 0;
  v6 = ObReferenceProcessHandleTable(a2);
  if ( !v6 )
    return -1073741811;
  memset(v12, 0, sizeof(v12));
  v11[0] = 24;
  v11[1] = 0;
  v11[2] = a1;
  v11[3] = 576;
  v11[4] = 0;
  v11[5] = 0;
  v12[0] = 7340040;
  v12[4] = 1;
  v5 = ObOpenObjectByName(v11, IoFileObjectType, 0);
  if ( v12[4] == -1096154543 )
  {
    v5 = v12[2];
    if ( v12[2] >= 0 )
    {
      v10[0] = v12[5];
      v10[1] = a2;
      ExEnumHandleTable(v6, IopCheckHandleForRevocation, v10, 0);
      v7 = IopGetDevicePDO(v10[0]);
      v8 = v7;
      if ( v7 )
      {
        PnpDisableUserModeNotifications(v7, a2);
        ObfDereferenceObjectWithTag(v8);
      }
      ObfDereferenceObjectWithTag(v10[0]);
    }
  }
  ObDereferenceProcessHandleTable(a2);
  return v5;
}
