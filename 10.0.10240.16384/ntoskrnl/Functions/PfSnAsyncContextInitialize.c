// PfSnAsyncContextInitialize 
 
int __fastcall PfSnAsyncContextInitialize(int a1, int a2, int a3, int a4)
{
  int v8; // r0
  int v9; // r0
  _DWORD *v10; // r2
  unsigned int v11; // r2
  __int64 v13; // r3

  memset((_BYTE *)a1, 0, 152);
  *(_DWORD *)(a1 + 128) = a2;
  *(_DWORD *)(a1 + 16) = a3;
  v8 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  *(_DWORD *)(a1 + 132) = v8;
  ObfReferenceObject(v8);
  v9 = PfSnReferenceProcessTrace(*(_DWORD *)(a1 + 132));
  v10 = *(_DWORD **)(a1 + 16);
  *(_DWORD *)(a1 + 136) = v9;
  *v10 = 0;
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (*(_DWORD *)(*(_DWORD *)(v11 + 336) + 192) & 0x100000) != 0 )
    return sub_8093C0();
  *(_DWORD *)(a1 + 144) = (*(_DWORD *)(v11 + 960) >> 12) & 7;
  *(_DWORD *)(a1 + 8) = PfSnAsyncPrefetchWorker;
  *(_DWORD *)(a1 + 12) = a1;
  *(_DWORD *)a1 = 0;
  if ( a4 )
    *(_DWORD *)(a1 + 148) |= 1u;
  LODWORD(v13) = PfSnPowerBoostWorker;
  HIDWORD(v13) = a1 + 24;
  *(_DWORD *)(a1 + 24) = 0;
  *(_QWORD *)(HIDWORD(v13) + 96) = v13;
  *(_DWORD *)(a1 + 112) = 0;
  KeInitializeTimerEx((_DWORD *)(a1 + 32), 0);
  return KeInitializeDpc(a1 + 80, (int)PfSnPowerBoostDpc, a1 + 24);
}
