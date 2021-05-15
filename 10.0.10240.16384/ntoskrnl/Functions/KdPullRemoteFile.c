// KdPullRemoteFile 
 
int __fastcall KdPullRemoteFile(int a1)
{
  int v2; // r6
  int v3; // r4
  int v5; // [sp+20h] [bp-58h] BYREF
  int v6; // [sp+24h] [bp-54h]
  char v7[80]; // [sp+28h] [bp-50h] BYREF

  v5 = 0;
  v6 = 0;
  if ( KdPitchDebugger )
    return -1073740972;
  v2 = ExAllocatePoolWithTag(512, 0x2000, 1867080779);
  if ( !v2 )
    return -1073741801;
  v3 = KdpCreateRemoteFile(&v5, v7, a1);
  if ( v3 >= 0 )
    return sub_903870();
  if ( v5 )
    KdpCloseRemoteFile(v5);
  if ( v6 )
    ZwClose();
  ExFreePoolWithTag(v2);
  return v3;
}
