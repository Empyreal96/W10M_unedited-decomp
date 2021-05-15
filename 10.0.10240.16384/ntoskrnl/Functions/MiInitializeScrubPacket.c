// MiInitializeScrubPacket 
 
int __fastcall MiInitializeScrubPacket(int a1, int a2, _DWORD *a3)
{
  int v5; // r4
  int v6; // r0

  a3[5] = a2;
  v5 = 0;
  a3[7] = 0;
  a3[8] = a1;
  a3[4] = 0;
  a3[6] = 0;
  MiCreatePteCopyList(0x100u, 0x100u, (int)a3);
  if ( !a3[1] )
    return -1073741670;
  v6 = ExAllocatePoolWithTag(512, 4096, 1667450189);
  a3[4] = v6;
  if ( v6 )
  {
    if ( a1 != -1 )
      a3[7] = MiReferencePageRuns((int)MiSystemPartition, 1);
  }
  else
  {
    v5 = -1073741670;
    MiReleaseScrubPacket(a3);
  }
  return v5;
}
