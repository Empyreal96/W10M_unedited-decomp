// WmipProcessLegacyEtwCallback 
 
signed int __fastcall WmipProcessLegacyEtwCallback(signed int result, int a2)
{
  signed int v2; // r6
  int v4; // r7
  unsigned int v5; // r8
  signed int v6; // r9
  int v7; // r1
  __int64 v8; // r2
  __int64 v9; // kr00_8
  _DWORD *v10; // r4
  int v11; // [sp+8h] [bp-68h] BYREF
  __int64 v12[12]; // [sp+10h] [bp-60h] BYREF

  v2 = result;
  if ( *(_BYTE *)(result + 28) )
    v4 = 4;
  else
    v4 = 5;
  v5 = 0;
  if ( *(_DWORD *)(result + 24) )
  {
    v6 = result;
    do
    {
      memset(v12, 0, 64);
      v7 = *(_DWORD *)(a2 + 44);
      v8 = *(_QWORD *)(a2 + 48);
      LODWORD(v12[3]) = *(_DWORD *)(a2 + 40);
      HIDWORD(v12[3]) = v7;
      v12[4] = v8;
      LODWORD(v12[0]) = 64;
      v9 = *(_QWORD *)(v2 + 16);
      v10 = *(_DWORD **)(v6 + 32);
      HIDWORD(v12[5]) = 0x20000;
      v12[6] = v9;
      v12[1] = v9;
      WmipSendWmiIrp(v4, v10[7], (int)&v12[3], 64, (int)v12, &v11);
      result = WmipUnreferenceEntry((int *)&WmipDSChunkInfo, v10);
      ++v5;
      v6 += 4;
    }
    while ( v5 < *(_DWORD *)(v2 + 24) );
  }
  return result;
}
