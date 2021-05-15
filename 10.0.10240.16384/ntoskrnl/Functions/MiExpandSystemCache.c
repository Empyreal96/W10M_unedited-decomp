// MiExpandSystemCache 
 
int MiExpandSystemCache()
{
  int v0; // r0
  int v1; // r5
  int v2; // r2
  int v3; // r3
  unsigned int v4; // r0
  unsigned int v5; // r6
  int v6; // r3
  int *v7; // r4
  int v9; // r5

  if ( (unsigned int)dword_635310 <= 0x4000000 || (v0 = ExAllocatePoolWithTag(512, 384), (v1 = v0) == 0) )
LABEL_12:
    JUMPOUT(0x552F56);
  v2 = 16;
  v3 = v0;
  do
  {
    *(_DWORD *)(v3 + 8) = 0;
    v3 += 24;
    --v2;
  }
  while ( v2 );
  v4 = MiObtainSystemVa(1, 8);
  v5 = v4;
  if ( !v4 )
  {
    ExFreePoolWithTag(v1, 0);
    goto LABEL_12;
  }
  v6 = (v4 >> 10) & 0x3FFFFC;
  v7 = (int *)(v6 - 0x40000000);
  if ( !MiMakeZeroedPageTables(v6 - 0x40000000, v6 - 1073737732, 0) )
    return sub_552F40();
  MiState[((int)(((v5 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2) + 1032] = v1;
  v9 = 16;
  do
  {
    InsertTailListPte((unsigned int)&dword_6342C4, v7);
    v7 += 64;
    --v9;
  }
  while ( v9 );
  return (int)v7;
}
