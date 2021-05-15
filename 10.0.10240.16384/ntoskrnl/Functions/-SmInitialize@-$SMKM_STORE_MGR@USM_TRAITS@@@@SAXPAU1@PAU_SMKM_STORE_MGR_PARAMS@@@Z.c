// -SmInitialize@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAXPAU1@PAU_SMKM_STORE_MGR_PARAMS@@@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmInitialize(int a1, _DWORD *a2)
{
  unsigned int v4; // r0
  int v5; // r2
  int v6; // r4
  _DWORD *v7; // r1
  _BYTE *v8; // r0
  int v9; // r1

  memset((_BYTE *)a1, 0, 5904);
  *(_DWORD *)(a1 + 5888) = *a2;
  *(_DWORD *)(a1 + 5892) = a2[1];
  SmKmInitialize(a1);
  *(_DWORD *)(a1 + 3192) = 0;
  *(_DWORD *)(a1 + 3196) = 0;
  v4 = 0;
  *(_DWORD *)(a1 + 3200) = 0;
  v5 = a1;
  v6 = a1;
  v7 = (_DWORD *)(a1 + 4360);
  do
  {
    *(_DWORD *)(v6 + 3208) = 0;
    v6 += 4;
    *(_DWORD *)(v5 + 3336) = *(_DWORD *)(v5 + 3336) & 0xFFFFFFF8 | 4;
    *(_DWORD *)(v5 + 3340) &= 0xFFFFFFF8;
    v7[5] = v4++;
    v7[4] = a1;
    v7[2] = SMKM_STORE_MGR<SM_TRAITS>::SmEmptyWorker;
    v7[3] = v7;
    v5 += 32;
    *v7 = 0;
    v7 += 6;
  }
  while ( v4 < 0x20 );
  memset((_BYTE *)(a1 + 5656), 0, 64);
  *(_BYTE *)(a1 + 5660) = 1;
  *(_BYTE *)(a1 + 5662) = 4;
  *(_BYTE *)(a1 + 5661) = 0;
  *(_DWORD *)(a1 + 5664) = 0;
  *(_DWORD *)(a1 + 5668) = a1 + 5668;
  *(_DWORD *)(a1 + 5672) = a1 + 5668;
  memset((_BYTE *)(a1 + 5720), 0, 64);
  *(_BYTE *)(a1 + 5724) = 1;
  *(_BYTE *)(a1 + 5725) = 0;
  *(_BYTE *)(a1 + 5726) = 4;
  *(_DWORD *)(a1 + 5728) = 0;
  *(_DWORD *)(a1 + 5732) = a1 + 5732;
  *(_DWORD *)(a1 + 5736) = a1 + 5732;
  v8 = memset((_BYTE *)(a1 + 5128), 0, 516);
  return sub_50AEEC(v8, v9, 32, a1 + 5128);
}
