// PopRecalculateCBTriggerLevels 
 
int PopRecalculateCBTriggerLevels()
{
  int *v0; // r4
  int v1; // r6
  int i; // r5
  int v3; // r2

  PopAcquirePolicyLock();
  v0 = &PopCB;
  v1 = 4;
  for ( i = PopPolicy + 96; ; i += 24 )
  {
    v3 = v0[53];
    if ( (v3 & 0x80) == 0 )
    {
      v0[55] = *(_DWORD *)(i + 4);
      if ( *(_BYTE *)i )
      {
        v0[53] = v3 | 0x80;
        if ( PopBatteryCheckTrigger(v0 + 52) )
          break;
      }
    }
    v0 += 4;
    if ( !--v1 )
      return PopReleasePolicyLock();
  }
  return sub_7F36F4();
}
