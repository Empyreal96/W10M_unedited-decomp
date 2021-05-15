// PfSnInitializePrefetcher 
 
int PfSnInitializePrefetcher()
{
  int result; // r0
  char v1[16]; // [sp+10h] [bp-10h] BYREF

  PfSnGlobals = &PfSnGlobals;
  dword_637374 = (int)&PfSnGlobals;
  dword_637378 = 0;
  dword_637380 = (int)&dword_63737C;
  dword_63737C = (int)&dword_63737C;
  dword_637384 = 1;
  dword_637388 = 0;
  *(_DWORD *)algn_63738C = 0;
  byte_637390 = 1;
  byte_637391 = 0;
  byte_637392 = 4;
  dword_637394 = 0;
  dword_63739C = (int)&dword_637398;
  dword_637398 = (int)&dword_637398;
  dword_6373A8 = 0;
  RtlInitUnicodeString((unsigned int)v1, L"\\KernelObjects\\PrefetchTracesReady");
  PfpCreateEvent((int)v1, 1, &dword_6373AC);
  PfSnPrefetchCacheCtxInitialize((int)&dword_6373B0[1]);
  qword_637408 = 0i64;
  if ( ExAllocatePoolWithTag(512, 96, 1716544323) )
    result = sub_96E4B4();
  else
    result = 0;
  return result;
}
