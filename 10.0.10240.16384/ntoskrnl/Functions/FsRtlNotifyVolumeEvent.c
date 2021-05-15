// FsRtlNotifyVolumeEvent 
 
int __fastcall FsRtlNotifyVolumeEvent(int a1, int a2)
{
  __int16 v3[10]; // [sp+0h] [bp-30h] BYREF
  int v4; // [sp+14h] [bp-1Ch]
  int v5; // [sp+18h] [bp-18h]

  v3[0] = 1;
  v4 = 0;
  v5 = -1;
  v3[1] = 28;
  return FsRtlNotifyVolumeEventEx(a1, a2, v3);
}
