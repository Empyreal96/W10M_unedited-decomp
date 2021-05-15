// sub_7D67DC 
 
void __fastcall sub_7D67DC(unsigned __int8 *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  unsigned int v10; // r1
  int v11; // r3
  int v12; // r5
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3
  int v16; // r4
  int v17; // r5
  unsigned int v18; // r7
  int v19; // r2
  int v20; // r3

  do
  {
    v19 = 37 * (37 * (37 * (37 * (37 * (37 * a1[1] + a1[2]) + a1[3]) + a1[4]) + a1[5]) + a1[6])
        + 442596621 * *a1
        - 803794207 * v18;
    v20 = a1[7];
    a1 += 8;
    v18 = v19 + v20;
    --v17;
  }
  while ( v17 );
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(__int16 *)(v10 + 0x134) - 1;
  *(_WORD *)(v10 + 308) = v11;
  ExAcquireResourceExclusiveLite((int)&unk_6373CC, 1, v19, v11);
  v12 = dword_6373C4 - 8;
  if ( !memcmp(dword_6373C4 + 8, v16 + 4, 64)
    || (v12 = PfSnPrefetchCacheEntryGet(&dword_6373B0[1], v16 + 4, v18, 0)) != 0 )
  {
    *(_DWORD *)(v12 + 96) = *(_DWORD *)(v16 + 68);
    *(_DWORD *)(v12 + 100) = *(_DWORD *)(v16 + 72);
  }
  v13 = ExReleaseResourceLite((int)&unk_6373CC);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_WORD *)(v14 + 0x134) + 1;
  *(_WORD *)(v14 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
    KiCheckForKernelApcDelivery(v13);
  __asm { POP.W           {R4-R7,R11,PC} }
}
