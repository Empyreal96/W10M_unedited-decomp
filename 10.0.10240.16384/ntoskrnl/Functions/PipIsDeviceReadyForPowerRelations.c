// PipIsDeviceReadyForPowerRelations 
 
BOOL __fastcall PipIsDeviceReadyForPowerRelations(int a1)
{
  int v1; // r3
  BOOL result; // r0

  result = 0;
  if ( a1 )
  {
    v1 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
    if ( v1 )
    {
      if ( *(_DWORD *)(v1 + 172) != 769 )
        result = 1;
    }
  }
  return result;
}
