// IovUnloadDrivers 
 
int IovUnloadDrivers()
{
  int v0; // r8
  _DWORD *v2; // r4
  _DWORD *v3; // r5
  int v4; // r7
  int v5; // r2
  _DWORD *v6; // r5
  _DWORD *v7; // r6
  int v8; // r0
  unsigned int v9; // r5
  int v10; // r0

  if ( !PopShutdownCleanly )
    return -1073741823;
  v2 = 0;
  IovDriverListHead = 0;
  v0 = ObEnumerateObjectsByType();
  while ( 1 )
  {
    v3 = (_DWORD *)IovDriverListHead;
    if ( !IovDriverListHead )
      break;
    IovDriverListHead = *(_DWORD *)IovDriverListHead;
    if ( IovpUnloadDriver(v3[1]) == 259 )
    {
      *v3 = v2;
      v2 = v3;
    }
    else
    {
      ObfDereferenceObject(v3[1]);
      ExFreePoolWithTag((unsigned int)v3);
    }
  }
  do
  {
    v4 = 0;
    v5 = 0;
    v6 = 0;
    while ( 1 )
    {
      v7 = v2;
      if ( !v2 )
        break;
      v8 = v2[1];
      v2 = (_DWORD *)*v2;
      if ( (*(_DWORD *)(v8 + 8) & 1) != 0 )
      {
        ObfDereferenceObject(v8);
        ExFreePoolWithTag((unsigned int)v7);
        v5 = 1;
      }
      else
      {
        *v7 = v6;
        v6 = v7;
      }
    }
    if ( v5 )
    {
      ZwDelayExecution();
      v4 = 1;
    }
    v2 = v6;
  }
  while ( v4 == 1 && v6 );
  while ( 1 )
  {
    v9 = (unsigned int)v2;
    if ( !v2 )
      break;
    v10 = v2[1];
    v2 = (_DWORD *)*v2;
    ObfDereferenceObject(v10);
    ExFreePoolWithTag(v9);
  }
  return v0;
}
