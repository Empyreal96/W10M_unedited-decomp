// KdpReportCommandStringStateChange 
 
int __fastcall KdpReportCommandStringStateChange(unsigned __int16 *a1, unsigned __int16 *a2, int a3)
{
  unsigned int v6; // r3
  unsigned int v7; // r3
  int v8; // r0
  int result; // r0
  unsigned __int16 v10; // [sp+10h] [bp-128h] BYREF
  char *v11; // [sp+14h] [bp-124h]
  int v12[2]; // [sp+18h] [bp-120h] BYREF
  __int16 v13; // [sp+20h] [bp-118h] BYREF
  char *v14; // [sp+24h] [bp-114h]
  char v15[32]; // [sp+28h] [bp-110h] BYREF
  char v16[64]; // [sp+48h] [bp-F0h] BYREF
  int v17; // [sp+E8h] [bp-50h]

  do
  {
    KdpSetCommonState(12338, a3, (int)v15);
    v17 = *(_DWORD *)(a3 + 68);
    memset(v16, 0, sizeof(v16));
    v6 = *a1;
    v11 = (char *)&KdpMessageBuffer;
    if ( v6 > 0x7F )
      v6 = 127;
    KdpCopyMemoryChunks(*((_DWORD *)a1 + 1), 0, (int)&KdpMessageBuffer, v6, 0, 4, v12);
    v10 = LOWORD(v12[0]) + 1;
    v11[(unsigned __int16)(LOWORD(v12[0]) + 1) - 1] = 0;
    v7 = KdTransportMaxPacketSize - v10 - 240;
    if ( *a2 < v7 )
      v7 = *a2;
    v8 = KdpCopyMemoryChunks(*((_DWORD *)a2 + 1), 0, (int)&v11[v10], v7, 0, 4, v12);
    v10 += LOWORD(v12[0]) + 1;
    v11[v10 - 1] = 0;
    v13 = 240;
    v14 = v15;
    result = KdpSendWaitContinue(v8, (int)&v13, (int)&v10, a3);
  }
  while ( result == 2 );
  return result;
}
