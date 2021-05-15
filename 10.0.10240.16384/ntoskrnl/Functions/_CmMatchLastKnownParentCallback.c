// _CmMatchLastKnownParentCallback 
 
BOOL __fastcall CmMatchLastKnownParentCallback(int a1, int a2, int a3, int a4)
{
  BOOL v5; // r4
  int v7; // [sp+20h] [bp-1A8h] BYREF
  char v8[4]; // [sp+24h] [bp-1A4h] BYREF
  unsigned __int16 v9[208]; // [sp+28h] [bp-1A0h] BYREF

  v5 = 0;
  v7 = 0;
  if ( PnpGetObjectProperty(a1, a2, 1, 0, 0, (int)DEVPKEY_Device_LastKnownParent, (int)&v7, (int)v9, 400, (int)v8, 0) >= 0
    && v7 == 18 )
  {
    v5 = wcsicmp(a4, v9) == 0;
  }
  return v5;
}
