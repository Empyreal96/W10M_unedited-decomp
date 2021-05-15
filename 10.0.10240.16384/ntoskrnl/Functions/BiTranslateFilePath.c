// BiTranslateFilePath 
 
int __fastcall BiTranslateFilePath(int a1, int a2, int *a3)
{
  int v4; // r4
  int v6; // r5
  char v7[32]; // [sp+8h] [bp-20h] BYREF

  v4 = BiAcquirePrivilege(22, v7);
  if ( v4 >= 0 )
  {
    if ( ZwTranslateFilePath() != -1073741789 )
      return sub_8145C8();
    v6 = ExAllocatePoolWithTag(1, 0, 1262764866);
    if ( v6 )
      v4 = ZwTranslateFilePath();
    else
      v4 = -1073741670;
    BiReleasePrivilege(v7);
    if ( v4 < 0 )
    {
      if ( v6 )
        ExFreePoolWithTag(v6);
    }
    else
    {
      *a3 = v6;
    }
  }
  return v4;
}
