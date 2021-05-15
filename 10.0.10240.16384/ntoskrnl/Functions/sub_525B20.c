// sub_525B20 
 
void __fastcall sub_525B20(int a1, int a2, int a3, int a4, unsigned int a5, unsigned int a6, int a7, unsigned int a8, int a9, int a10, int a11, unsigned int a12, int a13, int a14, int a15, int a16)
{
  int v16; // r5
  unsigned int *v17; // r6
  int v18; // r3
  unsigned int v19; // r1
  int v20; // r8
  int v21; // r9
  unsigned int v22; // r1
  int v23; // r3
  int v24; // r0
  unsigned int v25; // r2
  unsigned int v26; // r4
  int v27; // r0

  STACK[0x804] = 0;
  if ( a3 )
  {
    a7 = 0;
    a8 = 0;
    a9 = 0;
    a10 = 0;
    v18 = *(_DWORD *)(v16 + 176);
    v19 = *(_DWORD *)(v16 + 200);
    a7 = v16;
    a9 = v18;
    v20 = 14;
    v21 = 16;
    a8 = (v19 >> 3) & 0x1C000000 ^ (*(_DWORD *)(v16 + 204) ^ v19 ^ v16) & 0x1FFFFFFF;
    a10 = *(_DWORD *)(v16 + 408);
  }
  else
  {
    if ( !v17 )
    {
      RtlInitUnicodeString((unsigned int)&a5, 0);
      v17 = &a5;
    }
    memset(&a7, 0, 40);
    v22 = *(_DWORD *)(v16 + 200);
    a11 = *(_DWORD *)(v16 + 176);
    v23 = *(_DWORD *)(v16 + 204);
    a14 = v16;
    a12 = (v22 >> 3) & 0x1C000000 ^ (v23 ^ v22 ^ v16) & 0x1FFFFFFF;
    a10 = *(_DWORD *)(v16 + 408);
    v24 = MmGetDirectoryFrameFromProcess(v16);
    v25 = *(unsigned __int16 *)v17;
    v26 = 2008;
    a13 = v24;
    if ( v25 <= 0x7D8 )
      v26 = v25;
    LOWORD(a16) = v26 >> 1;
    memmove((int)&a16 + 2, v25 - v26 + v17[1], v26);
    *((_WORD *)&a7 + (unsigned __int16)a16 + 19) = 0;
    v27 = MmGetSessionIdEx(v16);
    if ( v27 == -1 )
      v27 = 0;
    a7 = v27;
    a8 = MmGetSessionGlobalVA(v16);
    v20 = 1;
    v21 = v26 + 40;
    a9 = PsIdleProcess;
  }
  KeQueryTickCount((int *)&a5);
  PfLogEvent(
    v20,
    dword_63728C
  + ((__int64)(((a5 * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24) + ((a6 * (unsigned __int64)MEMORY[0xFFFF9004]) << 8)) >> 10),
    &a7,
    v21);
  JUMPOUT(0x4600FA);
}
