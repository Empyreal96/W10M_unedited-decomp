// sub_8113EC 
 
void sub_8113EC()
{
  EtwUnregisterCounters();
  if ( PcwpSynchCounterSet )
  {
    PcwUnregister();
    PcwpSynchCounterSet = 0;
  }
  if ( PcwpSynchNumaCounterSet )
  {
    PcwUnregister();
    PcwpSynchNumaCounterSet = 0;
  }
  if ( PcwpProcessorCounterSet )
  {
    PcwUnregister();
    PcwpProcessorCounterSet = 0;
  }
  if ( PcwpFileSystemDiskIOCounterSet )
  {
    PcwUnregister();
    PcwpFileSystemDiskIOCounterSet = 0;
  }
  if ( PcwpThermalCounterSet )
  {
    PcwUnregister();
    PcwpThermalCounterSet = 0;
  }
  JUMPOUT(0x79F578);
}
