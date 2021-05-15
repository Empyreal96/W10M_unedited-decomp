// MiInitializeWorkingSetManagerParameters 
 
int __fastcall MiInitializeWorkingSetManagerParameters(int a1)
{
  _BYTE *v1; // r5
  _BYTE *v3; // r0
  int v5; // r7
  int v6; // r8
  unsigned int v7; // r6
  unsigned int v8; // r3
  int v9; // r3
  int v10; // r3
  int v11; // r3
  int v12; // r2
  unsigned int v13; // r2

  v1 = *(_BYTE **)(a1 + 3512);
  if ( v1 )
  {
    v5 = 0;
  }
  else
  {
    v3 = (_BYTE *)ExAllocatePoolWithTag(512, 1392);
    v1 = v3;
    if ( !v3 )
      return sub_54E27C();
    memset(v3, 0, 1392);
    *v1 = 0;
    v1[1] = 0;
    v1[2] = 4;
    *((_DWORD *)v1 + 1) = 1;
    *((_DWORD *)v1 + 2) = v1 + 8;
    *((_DWORD *)v1 + 3) = v1 + 8;
    *((_DWORD *)v1 + 7) = 256;
    *((_DWORD *)v1 + 26) = 256;
    v5 = 1;
  }
  v6 = __mrc(15, 0, 13, 0, 3);
  MiLockDynamicMemoryExclusive(a1, v6 & 0xFFFFFFC0);
  v7 = *(_DWORD *)(a1 + 3592);
  if ( v7 < 0x20000 )
    v7 = 0x20000;
  *((_DWORD *)v1 + 310) = v7 >> 5;
  if ( v7 > 0x200000 )
    *((_DWORD *)v1 + 310) = ((v7 - 0x200000) >> 7) + 0x10000;
  *((_DWORD *)v1 + 311) = v7 >> 5;
  if ( v7 > 0x80000 )
    *((_DWORD *)v1 + 311) = ((v7 - 0x80000) >> 8) + 0x4000;
  *((_DWORD *)v1 + 312) = *((_DWORD *)v1 + 311);
  *((_DWORD *)v1 + 309) = *((_DWORD *)v1 + 310) >> 2;
  if ( v5 == 1 )
    *(_DWORD *)(a1 + 3512) = v1;
  MiSetTrimWhileAgingState(a1, 3);
  v8 = v7 / 0x3E8;
  if ( v7 / 0x3E8 <= 0x64 )
    v8 = 100;
  *((_DWORD *)v1 + 13) = v8;
  if ( v5 != 1 )
    goto LABEL_18;
  v1[72] = 1;
  v1[73] = 0;
  v1[74] = 4;
  *((_DWORD *)v1 + 19) = 0;
  *((_DWORD *)v1 + 20) = v1 + 80;
  *((_DWORD *)v1 + 21) = v1 + 80;
  if ( (__int16 *)a1 == MiSystemPartition )
  {
    byte_634988 = 0;
    algn_634989 = 0;
    byte_63498A = 4;
    *(_DWORD *)&algn_63498B[1] = 1;
    *(_DWORD *)algn_634994 = &dword_634990;
    dword_634990 = (int)&dword_634990;
LABEL_18:
    if ( (__int16 *)a1 == MiSystemPartition )
    {
      *(_DWORD *)(a1 + 2988) = dword_681294;
      *(_DWORD *)(a1 + 2992) = dword_681298;
    }
  }
  v9 = *(_DWORD *)(a1 + 2988);
  if ( v9 )
    v10 = v9 << 8;
  else
    v10 = 2 * *((_DWORD *)v1 + 310);
  *(_DWORD *)(a1 + 2988) = v10;
  v11 = *(_DWORD *)(a1 + 2992);
  if ( v11 )
  {
    *(_DWORD *)(a1 + 2992) = v11 << 8;
  }
  else
  {
    v12 = *(_DWORD *)(a1 + 2988);
    *(_DWORD *)(a1 + 2992) = 2 * v12;
    if ( 2 * v12 == v12 )
      *(_DWORD *)(a1 + 2992) = 1;
  }
  v13 = *(_DWORD *)(a1 + 2988);
  if ( *(_DWORD *)(a1 + 2992) < v13 )
    *(_DWORD *)(a1 + 2992) = v13;
  MiUnlockDynamicMemoryExclusive(a1, v6 & 0xFFFFFFC0);
  return 1;
}
