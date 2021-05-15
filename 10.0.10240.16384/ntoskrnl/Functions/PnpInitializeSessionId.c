// PnpInitializeSessionId 
 
int __fastcall PnpInitializeSessionId(int a1, int a2, int a3)
{
  int v4; // r3
  int result; // r0

  v4 = *(_DWORD *)(a1 + 8);
  result = -1;
  if ( v4 && (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v4 + 16) + 176) + 16) & 0x400) != 0 )
    return sub_7C9C38(-1);
  if ( !a3 )
    result = PnpSetObjectProperty(
               PiPnpRtlCtx,
               *(_DWORD *)(a1 + 24),
               1,
               a2,
               0,
               (int)DEVPKEY_Device_SessionId,
               0,
               0,
               0,
               0);
  return result;
}
