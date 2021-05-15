// CmpSetNetworkValue 
 
int __fastcall CmpSetNetworkValue(int a1)
{
  int v2; // r4
  int v4; // [sp+10h] [bp-30h] BYREF
  int v5[10]; // [sp+18h] [bp-28h] BYREF

  v5[0] = 24;
  v5[1] = 0;
  v5[3] = 64;
  v5[2] = (int)&CmpCurrentControlSetControlPxePathString;
  v5[4] = 0;
  v5[5] = 0;
  v2 = NtCreateKey((int)&v4, 983103, (int)v5, 0, 0);
  if ( v2 >= 0 )
  {
    v2 = NtSetValueKey(v4, (int)&CmpDhcpServerAckString, 0, 3, *(_DWORD *)a1, *(_DWORD *)(a1 + 4));
    if ( v2 >= 0 )
    {
      v2 = NtSetValueKey(v4, (int)&CmpBootServerReplyString, 0, 3, *(_DWORD *)(a1 + 8), *(_DWORD *)(a1 + 12));
      if ( v2 >= 0 )
        v2 = 0;
    }
  }
  NtClose();
  return v2;
}
