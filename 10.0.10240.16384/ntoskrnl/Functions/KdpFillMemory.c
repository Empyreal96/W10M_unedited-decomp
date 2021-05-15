// KdpFillMemory 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KdpFillMemory(int a1, int a2)
{
  int v2; // r4
  int v3; // r3
  int v4; // r10
  int v5; // r9
  int v6; // r0
  __int16 v7; // r3
  int v8; // r5
  int v9; // r6
  unsigned int v10; // r7 OVERLAPPED
  unsigned int v11; // r8 OVERLAPPED
  char v12; // r4
  int v14; // [sp+10h] [bp-38h] BYREF
  int v15; // [sp+14h] [bp-34h]
  int v16; // [sp+18h] [bp-30h]
  __int16 v17; // [sp+20h] [bp-28h]
  int v18; // [sp+24h] [bp-24h]

  v2 = a1;
  v3 = *(unsigned __int16 *)(a1 + 30);
  v4 = *(_DWORD *)(a2 + 4);
  v5 = *(_DWORD *)(a1 + 24);
  v6 = 0;
  v15 = v3 + v4;
  v16 = v2;
  v14 = 5;
  v7 = *(_WORD *)(v2 + 28);
  v8 = 0;
  v9 = v4;
  if ( (v7 & 2) != 0 )
  {
    v14 = 7;
  }
  else if ( (v7 & 1) == 0 )
  {
    v6 = -1073741811;
    goto LABEL_11;
  }
  *(_QWORD *)&v10 = *(_QWORD *)(v2 + 16);
  if ( v5 )
  {
    v12 = v14;
    do
    {
      --v5;
      v6 = KdpCopyMemoryChunks(v10, v11, v9, 1u, 0, v12, &v14);
      if ( v6 < 0 )
        break;
      v11 = (__PAIR64__(v11, v10++) + 1) >> 32;
      if ( ++v9 == v15 )
        v9 = v4;
      ++v8;
    }
    while ( v5 );
    v2 = v16;
    if ( v8 )
      v6 = 0;
  }
LABEL_11:
  v17 = 56;
  *(_DWORD *)(v2 + 8) = v6;
  *(_DWORD *)(v2 + 24) = v8;
  v18 = v2;
  return KdSendPacket_0();
}
