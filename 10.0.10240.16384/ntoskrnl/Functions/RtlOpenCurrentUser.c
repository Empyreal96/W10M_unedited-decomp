// RtlOpenCurrentUser 
 
int RtlOpenCurrentUser()
{
  int v0; // r4
  _DWORD v2[2]; // [sp+0h] [bp-30h] BYREF
  int v3; // [sp+8h] [bp-28h]
  int v4; // [sp+Ch] [bp-24h]
  _DWORD *v5; // [sp+10h] [bp-20h]
  int v6; // [sp+14h] [bp-1Ch]
  int v7; // [sp+18h] [bp-18h]
  int v8; // [sp+1Ch] [bp-14h]

  v0 = RtlFormatCurrentUserKeyPath((unsigned __int16 *)v2);
  if ( v0 >= 0 )
  {
    v3 = 24;
    v4 = 0;
    v5 = v2;
    v6 = 1600;
    v7 = 0;
    v8 = 0;
    v0 = ZwOpenKey();
    RtlFreeAnsiString(v2);
  }
  if ( v0 == -1073741772 )
  {
    RtlInitUnicodeString((unsigned int)v2, L"\\Registry\\User\\.Default");
    v3 = 24;
    v4 = 0;
    v5 = v2;
    v6 = 1600;
    v7 = 0;
    v8 = 0;
    v0 = ZwOpenKey();
  }
  return v0;
}
