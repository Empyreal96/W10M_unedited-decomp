// IopInitializeInMemoryDumpData 
 
void IopInitializeInMemoryDumpData()
{
  unsigned int v0; // r2
  int v1; // r7
  int v2; // r0
  unsigned int v3; // r6
  unsigned int *v4; // r5
  _BYTE *v5; // r0
  unsigned int v6; // r2
  unsigned int *v7; // r5
  int v8; // r6
  unsigned int v9; // r0
  char v10[24]; // [sp+18h] [bp-60h] BYREF
  int v11; // [sp+30h] [bp-48h] BYREF
  __int16 v12; // [sp+34h] [bp-44h]
  __int16 v13; // [sp+36h] [bp-42h]
  char v14; // [sp+38h] [bp-40h]
  char v15; // [sp+39h] [bp-3Fh]
  char v16; // [sp+3Ah] [bp-3Eh]
  char v17; // [sp+3Bh] [bp-3Dh]
  char v18; // [sp+3Ch] [bp-3Ch]
  char v19; // [sp+3Dh] [bp-3Bh]
  char v20; // [sp+3Eh] [bp-3Ah]
  char v21; // [sp+3Fh] [bp-39h]
  char v22[56]; // [sp+40h] [bp-38h] BYREF

  v11 = 2012912317;
  v12 = 857;
  v13 = 19762;
  v14 = -67;
  v15 = 96;
  v16 = 40;
  v17 = -12;
  v18 = -25;
  v19 = -113;
  v20 = 120;
  v21 = 75;
  v10[0] = -77;
  v10[1] = -108;
  v10[2] = 53;
  v10[3] = 53;
  v10[4] = -108;
  v10[5] = 69;
  v10[6] = 46;
  v10[7] = 48;
  v10[8] = -44;
  v10[9] = -53;
  v10[10] = -38;
  v10[11] = -105;
  v10[12] = -15;
  v10[13] = 17;
  v10[14] = 2;
  v10[15] = -75;
  v10[16] = -24;
  v10[17] = 54;
  v10[18] = 8;
  v10[19] = 97;
  v10[20] = -120;
  v10[21] = 112;
  v10[22] = -101;
  v10[23] = 25;
  __dmb(0xBu);
  do
    v0 = __ldrex(&InMemData);
  while ( __strex(1u, &InMemData) );
  __dmb(0xBu);
  if ( v0 != 1 )
  {
    dword_632A24 = 0;
    dword_632A14 = 0;
    v1 = 0;
    memset(v22, 0, 24);
    if ( ZwQuerySystemInformation() >= 0 && !memcmp((unsigned int)v22, (unsigned int)SecBootPolicyPublisherDebug, 16) )
      v1 = 1;
    v2 = 4984;
    dword_632A10 = 4984;
    v3 = 0;
    v4 = &InMemData;
    while ( 1 )
    {
      v5 = (_BYTE *)MmAllocateContiguousNodeMemory(v2, 0i64, -1i64, 0, 0, 4);
      v4[2] = (unsigned int)v5;
      if ( !v5 )
      {
        v7 = &InMemData;
        v8 = 2;
        dword_632A24 = -1073741801;
        do
        {
          v9 = v7[2];
          if ( v9 )
          {
            MmFreeContiguousMemory(v9);
            v7[2] = 0;
          }
          ++v7;
          --v8;
        }
        while ( v8 );
        goto LABEL_16;
      }
      memset(v5, 0, dword_632A10);
      memmove(v4[2], (int)v10, 0x18u);
      if ( v1 )
        KdCopyDataBlock(v4[2] + 4120);
      ++v3;
      ++v4;
      if ( v3 >= 2 )
        break;
      v2 = dword_632A10;
    }
    dword_632A18 = ReadTimeStampCounter();
    dword_632A1C = ReadTimeStampCounter();
    RtlRandomEx(&dword_632A1C);
    if ( IoSetEnvironmentVariableEx(L"DumpInstance", &v11, &dword_632A18, 8, 7) < 0 )
    {
      sub_552184();
      return;
    }
    dword_632A04 = 1;
LABEL_16:
    __dmb(0xBu);
    do
      v6 = __ldrex(&InMemData);
    while ( __strex(0, &InMemData) );
    __dmb(0xBu);
  }
}
