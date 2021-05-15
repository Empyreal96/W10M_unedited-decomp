// PfSnGetPrefetchInstructions 
 
int __fastcall PfSnGetPrefetchInstructions(int a1, int a2, unsigned int *a3)
{
  unsigned int v3; // r6
  int *v4; // r9
  unsigned int v5; // r4
  int v6; // r0
  unsigned int v7; // r2
  unsigned int v9; // r4
  unsigned __int16 *v10; // r0
  unsigned __int16 *v11; // r8
  unsigned int v12; // r1
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3
  int v16; // r4
  unsigned int v17; // r5
  int v18; // r0
  unsigned int v19; // r1
  int v20; // r0
  unsigned int v21; // r1
  int v22; // r3
  int v23; // [sp+18h] [bp-80h] BYREF
  unsigned int v24; // [sp+1Ch] [bp-7Ch] BYREF
  unsigned int v25; // [sp+20h] [bp-78h] BYREF
  unsigned int *v26; // [sp+24h] [bp-74h]
  int v27; // [sp+28h] [bp-70h]
  unsigned int v28; // [sp+2Ch] [bp-6Ch] BYREF
  int v29[2]; // [sp+30h] [bp-68h] BYREF
  int v30[2]; // [sp+38h] [bp-60h] BYREF
  int v31[6]; // [sp+40h] [bp-58h] BYREF
  char v32[8]; // [sp+58h] [bp-40h] BYREF
  int v33; // [sp+60h] [bp-38h] BYREF
  unsigned int v34; // [sp+68h] [bp-30h]
  int v35; // [sp+6Ch] [bp-2Ch]

  v3 = 0;
  v23 = 0;
  v24 = 0;
  v4 = 0;
  v26 = a3;
  v27 = a2;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = KeAbPreAcquire((unsigned int)dword_637278, 0, 0);
  do
    v7 = __ldrex(dword_637278);
  while ( !v7 && __strex(0x11u, dword_637278) );
  __dmb(0xBu);
  if ( v7 )
    return sub_807A0C(v6, 17);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  v9 = wcslen(word_637110) + 51;
  v10 = (unsigned __int16 *)ExAllocatePoolWithTag(257, 2 * v9, 1179673411);
  v11 = v10;
  if ( !v10 )
  {
    v16 = -1073741670;
    __dmb(0xBu);
    do
      v19 = __ldrex(dword_637278);
    while ( v19 == 17 && __strex(0, dword_637278) );
    if ( v19 != 17 )
      ExfReleasePushLockShared(dword_637278);
    v20 = KeAbPostRelease((unsigned int)dword_637278);
    v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v22 = (__int16)(*(_WORD *)(v21 + 0x134) + 1);
    *(_WORD *)(v21 + 308) = v22;
    if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
      KiCheckForKernelApcDelivery(v20);
    goto LABEL_27;
  }
  RtlStringCbPrintfW(v10, 2 * v9, (int)L"%s\\%ws-%08X.%ws", (int)word_637110);
  __dmb(0xBu);
  do
    v12 = __ldrex(dword_637278);
  while ( v12 == 17 && __strex(0, dword_637278) );
  if ( v12 != 17 )
    ExfReleasePushLockShared(dword_637278);
  v13 = KeAbPostRelease((unsigned int)dword_637278);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_WORD *)(v14 + 0x134) + 1;
  *(_WORD *)(v14 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
    KiCheckForKernelApcDelivery(v13);
  RtlInitUnicodeString((unsigned int)v32, v11);
  v31[0] = 24;
  v31[1] = 0;
  v31[3] = 576;
  v31[2] = (int)v32;
  v31[4] = 0;
  v31[5] = 0;
  v16 = NtOpenFile((int)&v23, -2146435072, (int)v31, (int)v30, 0, 32);
  if ( v16 >= 0 )
  {
    v16 = NtQueryInformationFile(v23, v30, &v33, 0x18u, 5u);
    if ( v16 >= 0 )
    {
      v17 = v34;
      v25 = 0x10000000;
      if ( v34 > 0x10000000 || !v34 || v35 )
        goto LABEL_40;
      v18 = ExAllocatePoolWithTag(1, v34, 1884316483);
      v4 = (int *)v18;
      if ( !v18 )
      {
        v16 = -1073741670;
        goto LABEL_27;
      }
      v16 = NtReadFile(v23, 0, 0, 0, v30, v18, v17, 0, 0);
      if ( v16 < 0 )
        goto LABEL_27;
      v29[0] = (int)PfSnScenarioAlloc;
      v29[1] = (int)RtlpSysVolFree;
      v16 = SmDecompressBuffer(v4, v17, (int *)&v24, &v28, &v25, (int)v29);
      v3 = v24;
      if ( v16 < 0 )
        goto LABEL_27;
      if ( !PfVerifyScenarioBuffer(v24, v28, &v25) )
      {
        v16 = -1073741701;
        goto LABEL_27;
      }
      if ( *(_DWORD *)(v3 + 80) != v27 )
      {
LABEL_40:
        v16 = -1073741823;
        goto LABEL_27;
      }
      *v26 = v3;
      v3 = 0;
      v16 = 0;
    }
  }
LABEL_27:
  if ( v23 )
    NtClose();
  if ( v11 )
    ExFreePoolWithTag((unsigned int)v11);
  if ( v4 )
    ExFreePoolWithTag((unsigned int)v4);
  if ( v3 )
    RtlpSysVolFree(v3);
  return v16;
}
