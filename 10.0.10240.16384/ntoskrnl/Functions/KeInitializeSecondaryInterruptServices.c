// KeInitializeSecondaryInterruptServices 
 
int KeInitializeSecondaryInterruptServices()
{
  _BYTE *v0; // r0
  _DWORD *v1; // r4
  int v2; // r5
  int result; // r0

  v0 = (_BYTE *)ExAllocatePoolWithTag(512, 7168, 1767073099);
  v1 = v0;
  KiGlobalSecondaryIDT = (int)v0;
  if ( !v0 )
    return -1073741670;
  memset(v0, 0, 7168);
  v2 = 256;
  do
  {
    *v1 = 0;
    v1 += 7;
    KeInitializeEvent((int)(v1 - 6), 1, 1);
    --v2;
  }
  while ( v2 );
  KiSecondarySignalList = (int)&KiSecondarySignalList;
  dword_6218C4 = (int)&KiSecondarySignalList;
  KeInitializeDpc((int)&KiSecondarySignalDpc, (int)KiProcessSecondarySignalList, 0);
  KiSecondarySignalListLock = 0;
  KiSecondarySignalDpcRunning = 0;
  result = 0;
  KiSecondaryInterruptServicesEnabled = 1;
  return result;
}
