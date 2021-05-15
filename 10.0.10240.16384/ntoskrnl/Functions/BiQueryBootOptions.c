// BiQueryBootOptions 
 
int __fastcall BiQueryBootOptions(int *a1, _DWORD *a2, int a3, int a4)
{
  int v6; // r5
  int v7; // r4
  _DWORD v9[6]; // [sp+8h] [bp-18h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  *a1 = 0;
  *a2 = 0;
  v6 = 0;
  v7 = BiAcquirePrivilege(22, v9);
  if ( v7 < 0 )
    return v7;
  v7 = ZwQueryBootOptions();
  if ( v7 != -1073741789 )
    goto LABEL_5;
  v6 = ExAllocatePoolWithTag(1, 0, 1262764866);
  if ( v6 )
  {
    v7 = ZwQueryBootOptions();
LABEL_5:
    if ( v7 < 0 )
      return sub_814600();
    *a1 = v6;
    *a2 = 0;
    goto LABEL_8;
  }
  v7 = -1073741670;
LABEL_8:
  BiReleasePrivilege(v9);
  return v7;
}
