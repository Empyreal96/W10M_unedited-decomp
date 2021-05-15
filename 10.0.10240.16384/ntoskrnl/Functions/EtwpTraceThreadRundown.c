// EtwpTraceThreadRundown 
 
int __fastcall EtwpTraceThreadRundown(int a1, int a2)
{
  int v3; // r6
  int v4; // r3
  int v5; // r9
  int v6; // r1
  int v7; // r0
  int v8; // r3
  _DWORD *v9; // r5
  unsigned int v10; // lr
  unsigned int v11; // r2
  int v12; // r8
  int v13; // r2
  char v14; // r3
  _DWORD v16[4]; // [sp+18h] [bp-60h] BYREF
  int v17; // [sp+28h] [bp-50h]
  int v18; // [sp+2Ch] [bp-4Ch]
  int v19; // [sp+30h] [bp-48h]
  int v20; // [sp+34h] [bp-44h]
  _DWORD *v21; // [sp+38h] [bp-40h]
  int v22; // [sp+3Ch] [bp-3Ch]
  char v23; // [sp+40h] [bp-38h]
  char v24; // [sp+41h] [bp-37h]
  char v25; // [sp+42h] [bp-36h]
  char v26; // [sp+43h] [bp-35h]
  _DWORD v27[12]; // [sp+48h] [bp-30h] BYREF

  v3 = *(_DWORD *)(a2 + 16);
  v4 = *(unsigned __int8 *)(a2 + 36);
  v5 = *(unsigned __int8 *)(a2 + 37);
  v6 = *(_DWORD *)(a2 + 20);
  if ( v4 )
    v7 = 1283;
  else
    v7 = 1284;
  if ( a1 != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
    v6 &= 0xFFFFE7FF;
  v16[0] = *(_DWORD *)(a1 + 876);
  v16[1] = *(_DWORD *)(a1 + 880);
  v16[2] = *(_DWORD *)(a1 + 40);
  v8 = *(_DWORD *)(a1 + 36);
  __dmb(0xBu);
  v16[3] = v8;
  v19 = *(_DWORD *)(a1 + 356);
  v20 = *(_DWORD *)(a1 + 924);
  v9 = *(_DWORD **)(a1 + 156);
  v17 = 0;
  v18 = 0;
  v21 = v9;
  v22 = 0;
  v23 = *(_BYTE *)(a1 + 347);
  v10 = *(_DWORD *)(a1 + 960);
  v11 = (v10 >> 12) & 7;
  v12 = *(_DWORD *)(a1 + 336);
  if ( (*(_DWORD *)(v12 + 192) & 0x100000) != 0 && v11 >= 2 )
    LOBYTE(v11) = 2;
  v24 = v11;
  v13 = (v10 >> 9) & 7;
  if ( (*(_DWORD *)(v12 + 192) & 0x100000) != 0 )
    v13 = 0;
  if ( v13 < 2 && a1 == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && *(_DWORD *)(a1 + 1000) )
    LOBYTE(v13) = 2;
  v25 = v13;
  v26 = 0;
  v14 = *(_BYTE *)(a1 + 968);
  __dmb(0xBu);
  if ( (v14 & 8) != 0 && *(_DWORD *)(a1 + 852) != a1 + 852 )
    v26 |= 1u;
  if ( v9 && v5 )
  {
    v22 = v9[984];
    v17 = v9[1];
    v18 = v9[2];
  }
  v27[0] = v16;
  v27[1] = 0;
  v27[2] = 44;
  v27[3] = 0;
  return EtwpLogSystemEventUnsafe(v27, a1, v3, 1, v7, v6);
}
