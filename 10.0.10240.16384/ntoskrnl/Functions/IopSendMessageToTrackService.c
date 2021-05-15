// IopSendMessageToTrackService 
 
int __fastcall IopSendMessageToTrackService(_DWORD *a1, int a2, _DWORD *a3)
{
  char v4; // r5
  int v5; // r0
  int v6; // r4
  int v7; // r0
  int v8; // r0
  int v9; // r3
  unsigned int v10; // r5
  _DWORD *v11; // r6
  int v12; // r1
  int v13; // r2
  int v14; // r3
  unsigned int v15; // r3
  unsigned int v16; // r2
  int v17; // r0
  int v19; // [sp+8h] [bp-130h]
  char v21; // [sp+10h] [bp-128h]
  char v23[24]; // [sp+18h] [bp-120h] BYREF
  int v24; // [sp+30h] [bp-108h]

  v19 = 0;
  v4 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v21 = v4;
  while ( 1 )
  {
    if ( !IopLinkTrackingServiceObject )
    {
      if ( !*((_DWORD *)IopLinkTrackingServiceEvent + 1) )
        return -1073741153;
      v5 = KeWaitForSingleObject((unsigned int)&IopLinkTrackingPortObject, 0, v4, 0, 0);
      v6 = v5;
      if ( v5 == 192 || v5 == 257 )
        return v6;
      if ( IopLinkTrackingServiceObject )
      {
        KeSetEvent((int)&IopLinkTrackingPortObject, 0, 0);
      }
      else
      {
        *(_DWORD *)&algn_631AC4[4] = IopConnectLinkTrackingPort;
        *(_DWORD *)&algn_631AC4[8] = &IopLinkTrackingPacket;
        IopLinkTrackingPacket = 0;
        KeResetEvent((int)&algn_631AC4[12]);
        ExQueueWorkItem(&IopLinkTrackingPacket, 1);
        v7 = KeWaitForSingleObject((unsigned int)&algn_631AC4[12], 0, v4, 0, 0);
        v6 = v7;
        if ( v7 != 192 && v7 != 257 && dword_631AE0 < 0 )
          v6 = dword_631AE0;
        KeSetEvent((int)&IopLinkTrackingPortObject, 0, 0);
        if ( v6 )
          return v6;
      }
    }
    if ( ViVerifierDriverAddedThunkListHead )
    {
      v9 = (MmVerifierData & 0x10) != 0 ? 40 : 32;
      v8 = ExAllocatePoolWithTagPriority(1, 0xA8u, 538996553, v9);
    }
    else
    {
      v8 = ExAllocatePoolWithTag(1, 168, 538996553);
    }
    v10 = v8;
    if ( !v8 )
      break;
    v11 = (_DWORD *)(v8 + 24);
    memset((_BYTE *)(v8 + 24), 0, 144);
    *v11 = 0;
    v11[1] = 0;
    v12 = a1[1];
    v13 = a1[2];
    v14 = a1[3];
    v11[2] = *a1;
    v11[3] = v12;
    v11[4] = v13;
    v11[5] = v14;
    v11[6] = a1[4];
    memmove((int)(v11 + 7), a2, 0x40u);
    if ( a3[1] < 0x24u )
    {
      ExFreePoolWithTag(v10);
      return -2147483643;
    }
    v11[23] = a3[2];
    v11[24] = a3[3];
    v11[25] = a3[4];
    v11[26] = a3[5];
    v11[27] = a3[6];
    v11[28] = a3[7];
    v11[29] = a3[8];
    v11[30] = a3[9];
    v11[31] = a3[10];
    v15 = a3[1];
    if ( v15 > 0x24 )
    {
      v16 = v15 - 36;
      if ( v15 - 36 > 0x10 )
        v16 = 16;
      memmove((int)(v11 + 32), (int)(a3 + 11), v16);
    }
    *(_WORD *)(v10 + 2) = 168;
    *(_WORD *)v10 = 144;
    *(_DWORD *)(v10 + 4) = 0;
    v17 = LpcRequestWaitReplyPort(IopLinkTrackingServiceObject, v10, (unsigned int)v23);
    v6 = v17;
    if ( v17 >= 0 )
      return v24;
    if ( v17 != -1073741769
      || (v4 = v21,
          v6 = KeWaitForSingleObject((unsigned int)&IopLinkTrackingPortObject, 0, v21, 0, 0),
          ObfDereferenceObject(IopLinkTrackingServiceObject),
          IopLinkTrackingServiceObject = 0,
          KeSetEvent((int)&IopLinkTrackingPortObject, 0, 0),
          v19) )
    {
      if ( v6 < 0 )
        return v6;
      return v24;
    }
    v19 = 1;
  }
  return -1073741670;
}
