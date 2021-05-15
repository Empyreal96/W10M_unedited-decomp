// IoWMIRegistrationControl 
 
int __fastcall IoWMIRegistrationControl(int a1, int a2)
{
  unsigned int v2; // r6
  int v3; // r7
  int v5; // r8
  int v6; // r4

  v2 = 0;
  v3 = 0;
  v5 = 0;
  if ( !WmipServiceDeviceObject )
    return -1073741823;
  if ( a2 < 0 )
  {
    v2 = 0x80000000;
    a2 &= 0x7FFFFFFFu;
  }
  if ( (a2 & 0x10000) != 0 )
  {
    v3 = a2 & 0xF00000;
    v2 |= a2 & 0xF00000 | 0x10000;
    a2 &= 0xFF0EFFFF;
    v5 = 1;
  }
  switch ( a2 )
  {
    case 1:
      v6 = WmipRegisterDevice(a1, v2);
      if ( v5 )
        WmipSetTraceNotify(a1, v3);
      return v6;
    case 4:
      return WmipUpdateRegistration(a1);
    case 2:
      return WmipDeregisterDevice(a1);
  }
  return sub_7EF004();
}
