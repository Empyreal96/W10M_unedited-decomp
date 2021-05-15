// sub_7C37E8 
 
void sub_7C37E8()
{
  int v0; // r5
  char v1; // r2
  int v2; // r4

  v1 = PerfGlobalGroupMask[0];
  if ( (PerfGlobalGroupMask[0] & 0xC004) != 0 )
  {
    v2 = IoSetThreadHardErrorMode(0);
    EtwpEnumerateAddressSpace(v0, 0, (int)PerfGlobalGroupMask);
    IoSetThreadHardErrorMode(v2);
    v1 = PerfGlobalGroupMask[0];
  }
  if ( (v1 & 8) != 0 )
    EtwpLogProcessPerfCtrs(v0);
  JUMPOUT(0x6B3CF6);
}
