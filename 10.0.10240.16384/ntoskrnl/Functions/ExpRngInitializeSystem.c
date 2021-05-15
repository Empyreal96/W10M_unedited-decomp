// ExpRngInitializeSystem 
 
// local variable allocation has failed, the output may be wrong!
int ExpRngInitializeSystem()
{
  int *v0; // r6
  int v1; // r8
  int v2; // r9 OVERLAPPED
  int v3; // r10 OVERLAPPED
  int v4; // r3
  int v5; // r4
  int v6; // r7
  int v7; // r0
  _BYTE v9[256]; // [sp-4h] [bp-100h] BYREF

  v0 = ExpLFGRngState;
  ExpLFGRngLock = 0;
  v1 = 2;
  v2 = 1;
  v3 = 32;
  v4 = *((_DWORD *)KeLoaderBlock_0 + 33);
  v5 = v4 + 144;
  v6 = v4 + 364;
  do
  {
    memmove((int)v9, v6 + 888, 0xDCu);
    memmove((int)v0, (int)v9, 0xDCu);
    v6 += 220;
    --v1;
    *v0 |= 1u;
    v0 += 57;
    *((_QWORD *)v0 - 1) = *(_QWORD *)&v2;
  }
  while ( v1 );
  ExpRemainingLeftoverBootRngData = 91;
  v7 = memmove((int)ExpLeftoverBootRngData, v5 + 1548, 0x16Cu);
  return sub_96C528(v7, 0, 1024, v5 + 888);
}
