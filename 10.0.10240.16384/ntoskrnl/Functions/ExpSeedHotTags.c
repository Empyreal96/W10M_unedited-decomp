// ExpSeedHotTags 
 
int ExpSeedHotTags()
{
  int *v0; // r1
  int v1; // r4
  int v2; // r5
  int v3; // r7
  int result; // r0
  int v5; // t1
  int v6; // r2
  int v7; // r6
  int v8[72]; // [sp+8h] [bp-120h] BYREF

  qmemcpy(
    v8,
    "Io  Hal MdlPPooLObStIrp NDdbIrpLIoOpMdl FileCMVaSeSdNtFCPoolTCPrCMNbSeTdNtFsTCPTTCPCKey ObSqIoNmIoEaTCPcNtFaNtf0Sect"
    "IrpSTokeSe  ObClCcScNtFLSeAcFSfmCcWkFSimAfdCAfdEFSroNtfnUIRPNpFrNpFRSePaSeUsAcpFAcpMSeScObNmNpFsSeLuScPDEvenRqrvVadl"
    "Pp  VadSVad VadLVadFMmdiBIG ",
    260);
  v0 = v8;
  v1 = 65;
  v2 = PoolTrackTable;
  v3 = PoolTrackTableMask;
  do
  {
    v5 = *v0++;
    result = v5;
    v6 = v3 & ((40543 * (HIBYTE(v5) ^ (4 * (BYTE2(v5) ^ (4 * (BYTE1(v5) ^ (4 * (unsigned __int8)v5))))))) >> 2);
    v7 = v6;
    while ( *(_DWORD *)(v2 + 28 * v6) || v6 == PoolTrackTableSize - 1 )
    {
      v6 = (v6 + 1) & v3;
      if ( v6 == v7 )
        goto LABEL_6;
    }
    *(_DWORD *)(v2 + 28 * v6) = result;
LABEL_6:
    --v1;
  }
  while ( v1 );
  return result;
}
