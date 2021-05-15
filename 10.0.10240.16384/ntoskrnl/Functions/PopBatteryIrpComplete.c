// PopBatteryIrpComplete 
 
int __fastcall PopBatteryIrpComplete(int a1, int a2, _DWORD *a3)
{
  int v3; // r1
  int v4; // r4
  int v6; // r3

  v3 = *(_DWORD *)(a2 + 24);
  if ( v3 == -1073741536 )
  {
    v4 = 0;
  }
  else
  {
    v6 = a3[14];
    v4 = 1;
    if ( v3 < 0 )
      return sub_5290B8(a1, v3, a3, v6);
    if ( !v6 )
    {
      a3[15] = a3[30];
      a3[14] = 1;
    }
  }
  KeSetEvent(a3 + 10, 0, 0);
  if ( v4 )
    PopBatteryQueueWork(1);
  return -1073741802;
}
