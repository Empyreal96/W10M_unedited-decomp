// FsFilterInit 
 
int FsFilterInit()
{
  int v0; // r4
  int result; // r0

  v0 = 0;
  AcquireOpsReservePool = ExAllocatePoolWithTag(512, 484, 1735217990);
  if ( !AcquireOpsReservePool )
    v0 = -1073741670;
  ReleaseOpsReservePool = ExAllocatePoolWithTag(512, 484, 1735217990);
  if ( !ReleaseOpsReservePool )
    return sub_50B7E0();
  result = v0;
  AcquireOpsEvent = 1;
  byte_631E41 = 0;
  byte_631E42 = 4;
  dword_631E44 = 1;
  dword_631E4C = (int)&dword_631E48;
  dword_631E48 = (int)&dword_631E48;
  ReleaseOpsEvent = 1;
  byte_631E61 = 0;
  byte_631E62 = 4;
  dword_631E64 = 1;
  dword_631E6C = (int)&dword_631E68;
  dword_631E68 = (int)&dword_631E68;
  return result;
}
