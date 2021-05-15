// MiReserveDriverPtes 
 
int __fastcall MiReserveDriverPtes(int a1, int a2)
{
  unsigned int v3; // r6
  int v4; // r5
  _DWORD *v5; // r4
  int v6; // r0
  int v7; // r4
  unsigned int v9; // r10
  int v10; // r0
  int v11; // r7
  int v12; // r4
  unsigned int v13; // r0
  unsigned int v14; // r0
  __int64 v15; // r3
  int v16; // [sp+4h] [bp-34h]
  int v17; // [sp+8h] [bp-30h]
  unsigned int v18; // [sp+Ch] [bp-2Ch]
  int *v19; // [sp+10h] [bp-28h]

  v3 = a2 + 15;
  v4 = __mrc(15, 0, 13, 0, 3);
  MiLockDriverMappings(v4 & 0xFFFFFFC0);
  v5 = (_DWORD *)MiState[a1 + 305];
  v19 = &MiState[a1];
  while ( v5 )
  {
    if ( v5[2] >= v3 >> 4 )
    {
      v6 = RtlFindClearBitsAndSet(v5 + 2, v3 >> 4, v5[4]);
      if ( v6 != -1 )
      {
        v5[4] = v6 + (v3 >> 4);
        v7 = v5[1] + 4 * ((16 * v6) & 0xFFFFF);
        MiUnlockDriverMappings(v4 & 0xFFFFFFC0);
        goto LABEL_6;
      }
    }
    v5 = (_DWORD *)*v5;
  }
  v16 = ExGenRandom(1) & 0x3F;
  v17 = v16 + (v3 >> 4);
  v9 = (16 * v17 + 1023) & 0xFFFFFC00;
  if ( InitializationPhase )
    v10 = 1;
  else
    v10 = 512;
  v11 = ExAllocatePoolWithTag(v10, (v9 >> 7) + 20, 1883532621);
  if ( !v11 )
    return sub_7CEEFC();
  if ( a1 )
    v12 = 11;
  else
    v12 = 12;
  v13 = MiObtainSystemVa(v9 >> 10, v12);
  if ( !v13 )
    JUMPOUT(0x7CEF14);
  v14 = ((v13 >> 10) & 0x3FFFFC) - 0x40000000;
  v18 = v14;
  if ( !a1 && !MiMakeZeroedPageTables(v14, v14 + 4 * v9 - 4, 1) )
    JUMPOUT(0x7CEF06);
  memset((_BYTE *)(v11 + 20), 0, v9 >> 7);
  LODWORD(v15) = v9 >> 4;
  HIDWORD(v15) = v11 + 20;
  *(_QWORD *)(v11 + 8) = v15;
  RtlSetBits((_BYTE *)(v11 + 8), v16, v3 >> 4);
  *(_DWORD *)(v11 + 16) = v17;
  *(_DWORD *)(v11 + 4) = v18;
  *(_DWORD *)v11 = v19[305];
  v19[305] = v11;
  MiUnlockDriverMappings(v4 & 0xFFFFFFC0);
  v7 = v18 + 4 * ((16 * v16) & 0xFFFFF);
LABEL_6:
  if ( (MiFlags & 0x30000) != 0 )
    JUMPOUT(0x7CEF26);
  return v7;
}
