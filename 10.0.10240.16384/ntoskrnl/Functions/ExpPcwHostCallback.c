// ExpPcwHostCallback 
 
int __fastcall ExpPcwHostCallback(int result)
{
  __int16 v1; // [sp+0h] [bp-28h] BYREF
  __int16 v2; // [sp+2h] [bp-26h]
  const __int16 *v3; // [sp+4h] [bp-24h]
  int v4; // [sp+8h] [bp-20h] BYREF
  __int16 *v5; // [sp+Ch] [bp-1Ch]
  int v6; // [sp+10h] [bp-18h]
  int *v7; // [sp+14h] [bp-14h]
  int (__fastcall *v8)(int, __int64 *); // [sp+18h] [bp-10h]
  int v9; // [sp+1Ch] [bp-Ch]

  if ( result == 1 )
  {
    EtwRegisterCounters();
    v1 = 30;
    v2 = 32;
    v3 = L"Synchronization";
    v4 = 256;
    v7 = &`PcwpRegisterSynchCounterSet'::`2'::Descriptors;
    v6 = 42;
    v8 = (int (__fastcall *)(int, __int64 *))KiSynchCounterSetCallback;
    v9 = 0;
    v5 = &v1;
    PcwRegister(&PcwpSynchCounterSet, &v4);
    v1 = 38;
    v2 = 40;
    v3 = L"SynchronizationNuma";
    v4 = 256;
    v7 = &`PcwpRegisterSynchCounterSet'::`2'::Descriptors;
    v6 = 42;
    v8 = (int (__fastcall *)(int, __int64 *))KiSynchNumaCounterSetCallback;
    v9 = 0;
    v5 = &v1;
    PcwRegister(&PcwpSynchNumaCounterSet, &v4);
    v1 = 42;
    v2 = 44;
    v3 = L"Processor Information";
    v4 = 256;
    v7 = &`PcwpRegisterProcessorCounterSet'::`2'::Descriptors;
    v6 = 33;
    v8 = ExProcessorCounterSetCallback;
    v9 = 0;
    v5 = &v1;
    PcwRegister(&PcwpProcessorCounterSet, &v4);
    if ( PsIsDiskCountersEnabled() )
    {
      v1 = 48;
      v2 = 50;
      v3 = L"FileSystem Disk Activity";
      v4 = 256;
      v7 = &`PcwpRegisterFileSystemDiskIOCounterSet'::`2'::Descriptors;
      v6 = 2;
      v8 = (int (__fastcall *)(int, __int64 *))FsRtlDiskIOCounterSetCallback;
      v9 = 0;
      v5 = &v1;
      PcwRegister(&PcwpFileSystemDiskIOCounterSet, &v4);
    }
    v1 = 48;
    v2 = 50;
    v3 = L"Thermal Zone Information";
    v4 = 256;
    v7 = &`PcwpRegisterThermalCounterSet'::`2'::Descriptors;
    v6 = 3;
    v8 = (int (__fastcall *)(int, __int64 *))PoThermalCounterSetCallback;
    v9 = 0;
    v5 = &v1;
    result = PcwRegister(&PcwpThermalCounterSet, &v4);
  }
  else if ( result == 2 )
  {
    result = sub_8113EC();
  }
  return result;
}
