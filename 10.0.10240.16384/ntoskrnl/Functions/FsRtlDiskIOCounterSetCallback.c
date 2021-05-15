// FsRtlDiskIOCounterSetCallback 
 
int __fastcall FsRtlDiskIOCounterSetCallback(int a1, int a2)
{
  int result; // r0
  char v4[16]; // [sp+10h] [bp-10h] BYREF

  if ( a1 == 2 )
  {
    RtlInitUnicodeString((unsigned int)v4, L"default");
    result = PcwAddInstance(*(_DWORD *)(a2 + 20), (int)v4, 0, 1);
    if ( result < 0 )
      return result;
  }
  else if ( a1 == 3 )
  {
    return FsRtlAddDiskIOCounterInstance(*(_DWORD *)(a2 + 20));
  }
  return 0;
}
