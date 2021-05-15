// PfSnAppLaunchScenarioControl 
 
int __fastcall PfSnAppLaunchScenarioControl(_DWORD *a1, char a2)
{
  int v2; // r6
  int v3; // r5
  int v4; // r4
  int v6; // [sp+10h] [bp-38h] BYREF
  char v7[48]; // [sp+18h] [bp-30h] BYREF

  v6 = 0;
  v2 = 0;
  if ( *a1 != 1 )
    return -1073741735;
  if ( !a1[1] )
    return -1073741811;
  v3 = ObReferenceObjectByHandleWithTag(a1[2], 8, PsProcessType, a2, 1935107664, &v6, 0);
  v4 = v6;
  if ( v3 >= 0 )
  {
    if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) != v4 )
    {
      v2 = 1;
      KiStackAttachProcess(v4, 0, (int)v7);
    }
    PfSnBeginAppLaunch(v4, 0, 9);
    v3 = 0;
    if ( v2 )
      KiUnstackDetachProcess((unsigned int)v7, 0);
  }
  if ( v4 )
    ObfDereferenceObjectWithTag(v4);
  return v3;
}
