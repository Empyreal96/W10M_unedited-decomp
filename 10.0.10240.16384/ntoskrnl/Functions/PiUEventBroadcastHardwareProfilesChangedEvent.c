// PiUEventBroadcastHardwareProfilesChangedEvent 
 
__int64 __fastcall PiUEventBroadcastHardwareProfilesChangedEvent(__int64 a1, int a2, int a3)
{
  int v3; // r4
  __int64 v5; // [sp+0h] [bp-18h]
  __int64 vars8; // [sp+20h] [bp+8h] BYREF

  v5 = a1;
  vars8 = a1;
  if ( (_DWORD)a1 == -1 )
  {
    v5 = 0i64;
    ZwUpdateWnfStateData();
  }
  else
  {
    v3 = MmGetSessionById(a1, SHIDWORD(a1), a2, a3);
    if ( v3 )
    {
      HIDWORD(v5) = 0;
      LODWORD(v5) = &vars8;
      ZwUpdateWnfStateData();
      ObfDereferenceObject(v3);
    }
  }
  return v5;
}
