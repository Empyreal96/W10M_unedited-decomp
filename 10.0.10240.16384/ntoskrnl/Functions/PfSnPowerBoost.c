// PfSnPowerBoost 
 
int __fastcall PfSnPowerBoost(_DWORD *a1, int a2)
{
  unsigned int v3; // r0
  unsigned int v4; // r1
  unsigned int v5; // r1
  int v7; // r0
  unsigned int v8; // r4
  unsigned int v9; // r2
  unsigned int v10; // r1
  _DWORD *v11; // [sp+0h] [bp-18h]

  v11 = a1;
  if ( !a2 )
  {
    if ( KeCancelTimer((int)(a1 + 2)) )
    {
      PfSnPowerBoostUpdate(0);
      __pld(a1);
      v3 = *a1 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v4 = __ldrex(a1);
      while ( v4 == v3 && __strex(v3 - 2, a1) );
      if ( v4 != v3 )
        ExfReleaseRundownProtection((unsigned __int8 *)a1);
    }
    do
      v5 = __ldrex(a1);
    while ( !v5 && __strex(1u, a1) );
    __dmb(0xBu);
    if ( v5 )
    {
      if ( v5 != 1 )
        ExfWaitForRundownProtectionRelease(a1, v5);
    }
    return (int)v11;
  }
  v7 = PfSnPowerBoostUpdate(1);
  __pld(a1);
  v8 = *a1 & 0xFFFFFFFE;
  v9 = v8 + 2;
  do
    v10 = __ldrex(a1);
  while ( v10 == v8 && __strex(v9, a1) );
  __dmb(0xBu);
  if ( v10 == v8 )
  {
    KiSetTimerEx((int)(a1 + 2), 0, -30000000i64, 0, 0, (int)(a1 + 14));
    return (int)v11;
  }
  return sub_808FEC(v7, v10, v9);
}
