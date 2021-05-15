// SdbpCheckMatchingDevice 
 
int __fastcall SdbpCheckMatchingDevice(_DWORD *a1, int a2, int a3, int a4, int a5, int a6)
{
  int (*v6)(void); // r7
  int v8; // r4
  int v10; // r0
  int v11; // r2
  int v12; // r3

  v6 = *(int (**)(void))(a2 + 616);
  v8 = 0;
  *a1 = 0;
  if ( v6 )
  {
    v10 = SdbFindFirstTag(a3, a5, 24577);
    if ( v10 )
    {
      if ( SdbGetStringTagPtr(a3, v10, v11, v12) )
      {
        v8 = 1;
        *a1 = v6();
        if ( a6 )
          *(_DWORD *)(a6 + 40) = 1;
      }
      else
      {
        AslLogCallPrintf(1, (int)"SdbpCheckMatchingDevice", 1782, "Failed to get HWID");
      }
    }
    else
    {
      AslLogCallPrintf(1, (int)"SdbpCheckMatchingDevice", 1776, "Failed to read HWID attribute");
    }
  }
  else
  {
    AslLogCallPrintf(1, (int)"SdbpCheckMatchingDevice", 1770, "No device query callback specified");
  }
  return v8;
}
