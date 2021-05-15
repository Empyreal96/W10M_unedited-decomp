// PopCheckAndHandleThermalConditions 
 
int __fastcall PopCheckAndHandleThermalConditions(int result)
{
  int v1; // r4
  int v2; // r5
  int v3; // r6
  int v4; // r1
  __int64 v5; // r0
  int v6; // r0
  int v7; // r0
  __int64 v8; // r0
  int v9; // r0
  int v10; // r3
  int v11; // r3
  int v12; // r2
  int v13; // r5
  int v14[4]; // [sp+8h] [bp-38h] BYREF
  int v15[10]; // [sp+18h] [bp-28h] BYREF

  v1 = result;
  v2 = 0;
  v3 = 0;
  if ( *(_BYTE *)(result + 262) )
    return sub_551EEC();
  if ( *(_BYTE *)(result + 261) )
  {
    v3 = 1;
    PopDiagTraceZoneS4TripPointExceeded(result + 160, *(_DWORD *)(result + 24));
    v5 = PopSqmThermalHibernate(v1);
    v6 = PopAcquirePolicyLock(v5, HIDWORD(v5));
    if ( byte_61EA46 && byte_61EA48 && byte_61EA56 == 2 )
    {
      PopThermalHibernateInitiated = 1;
      PopThermalStandbyEndTracking();
      v14[2] = 0;
      v14[0] = 3;
      v14[1] = -1073741820;
      v15[2] = 0;
      v15[3] = 0;
      v15[0] = 1;
      v15[1] = 128;
      v6 = ((int (__fastcall *)(int *, _DWORD, int *, int, int))PopExecutePowerAction)(v15, 0, v14, 5, 1);
    }
    else
    {
      v2 = 1;
    }
    if ( v2 )
    {
      v6 = PopThermalWriteShutdownToRegistry(v6);
      if ( !PopThermalCriticalShutdownInitiated )
      {
        v7 = PopThermalStandbyEndTracking();
        PopThermalCriticalShutdownInitiated = 1;
        v6 = PopCriticalShutdown(v7);
      }
    }
    result = PopReleasePolicyLock(v6);
  }
  v4 = *(_BYTE *)(v1 + 276) != 0;
  if ( *(unsigned __int8 *)(v1 + 41) != v4 )
  {
    *(_BYTE *)(v1 + 41) = v4;
    result = PopUpdateOverThrottledCount(v1);
  }
  if ( *(unsigned __int8 *)(v1 + 40) != *(unsigned __int8 *)(v1 + 263) )
  {
    v8 = PopDiagTraceThermalStateChange(*(_DWORD *)(v1 + 24));
    v9 = PopAcquirePolicyLock(v8, HIDWORD(v8));
    v10 = *(unsigned __int8 *)(v1 + 263);
    *(_BYTE *)(v1 + 40) = v10;
    if ( v10 )
    {
      v11 = dword_61E4A4 + 1;
      dword_61E4A4 = v11;
      if ( v11 == 1 )
      {
        byte_61E4A8 = 1;
        v9 = PopTraceCr3Tripped(v9);
        v11 = dword_61E4A4;
      }
    }
    else
    {
      v11 = --dword_61E4A4;
    }
    if ( v11 )
    {
      v12 = (unsigned __int8)byte_61E4A1;
      v13 = 1;
    }
    else
    {
      v13 = 0;
      v9 = PopThermalStandbyEndTracking();
      v12 = (unsigned __int8)byte_61E4A1;
      if ( byte_61E4A1 )
      {
        v9 = PopThermalStandbyNotify(0);
        byte_61E4A1 = 0;
        return PopReleasePolicyLock(v9);
      }
    }
    if ( !v3 && v13 && PopSystemThermalInfo && !v12 )
    {
      v9 = PopThermalStandbyNotify(1);
      byte_61E4A1 = 1;
      PopSystemThermalInfo = 0;
    }
    return PopReleasePolicyLock(v9);
  }
  return result;
}
