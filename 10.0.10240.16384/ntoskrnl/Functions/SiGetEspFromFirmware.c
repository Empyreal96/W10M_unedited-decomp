// SiGetEspFromFirmware 
 
int __fastcall SiGetEspFromFirmware(int a1, int a2, int a3)
{
  int v3; // r8
  int v4; // r4
  int v5; // r1
  int v6; // r2
  int v7; // r3
  char v9[40]; // [sp+10h] [bp-28h] BYREF

  v3 = 0;
  v4 = BiAcquirePrivilege(22, (int)v9, a3, 0);
  if ( v4 < 0 )
    return v4;
  v4 = ZwQueryBootEntryOrder();
  if ( v4 != -1073741789 )
    goto LABEL_6;
  v3 = ExAllocatePoolWithTag(1, 0, 1263556947);
  if ( v3 )
  {
    v4 = ZwQueryBootEntryOrder();
LABEL_6:
    if ( !v4 )
    {
      v7 = 0;
      v4 = -1073741275;
    }
    goto LABEL_8;
  }
  v4 = -1073741801;
LABEL_8:
  BiReleasePrivilege((int)v9, v5, v6, v7);
  if ( v3 )
    ExFreePoolWithTag(v3);
  return v4;
}
