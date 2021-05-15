// PnpPrepareDriverLoading 
 
int __fastcall PnpPrepareDriverLoading(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v9; // r0
  int v10; // r0
  int v11; // r4
  int v13; // [sp+8h] [bp-30h] BYREF
  _DWORD v14[10]; // [sp+10h] [bp-28h] BYREF

  *a5 = 0;
  v9 = RtlImageNtHeader(a3);
  if ( !v9 )
    return -1073741823;
  v14[0] = 0;
  v14[1] = 0;
  v14[2] = 0;
  v14[3] = 0;
  v10 = PpCheckInDriverDatabase(a1, a2, a3, *(_DWORD *)(v9 + 80), a4, v14);
  v11 = v10;
  if ( v10 == -1073740948 || v10 == -1073740949 )
    PnpSetBlockedDriverEvent(v14);
  if ( IopGetRegistryValue(a2, L"PnpFlags", 0, &v13) >= 0 )
    return sub_7CBF94();
  return v11;
}
