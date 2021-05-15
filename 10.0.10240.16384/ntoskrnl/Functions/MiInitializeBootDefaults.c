// MiInitializeBootDefaults 
 
_BYTE *__fastcall MiInitializeBootDefaults(int a1)
{
  _BYTE *result; // r0
  int v3; // r4
  unsigned int i; // r1
  _DWORD *v5; // r3
  int v6; // r1
  int v7; // r2
  int v8; // r7
  int *v9; // r3
  int v10; // r2
  int *v11; // r3
  unsigned int v12; // r3
  unsigned int v13; // r2
  unsigned int v14; // r2
  int v15; // [sp+0h] [bp-30h] BYREF
  __int64 v16; // [sp+8h] [bp-28h] BYREF

  MmSystemRangeStart = 0x80000000;
  MmUserProbeAddress = 2147418112;
  dword_63388C = *(_DWORD *)(a1 + 136);
  MmHighestUserAddress = 2147418111;
  if ( !strstr(*(_BYTE **)(a1 + 120), "SAFEBOOT:") )
    return (_BYTE *)sub_96E798();
  MmLargePageDriverBufferLength = -1;
  MmSpecialPoolTag = 0;
  MmProtectFreedNonPagedPool = 0;
  byte_634C8D = 1;
  dword_681258 = 0;
  MEMORY[0xFFFF92EC] = 1;
  v3 = MiFlags;
  MiFlags |= 8u;
  if ( (NtGlobalFlag & 0x80000) == 0 )
    MiFlags = v3 | 0x48;
  byte_6346A4 = 19;
  algn_6346A5 = 1;
  word_6346A6 = 0;
  unk_6346B0 = MiAllocatePfnRepurposeLogDispatch;
  dword_6346B4 = 0;
  dword_6346C0 = 0;
  dword_6346AC = 0;
  KiInitializeMutant((int)&unk_632F0C, 0, 0);
  dword_632F60 = 0;
  for ( i = 0; i < 2; ++i )
  {
    v5 = (_DWORD *)((char *)&unk_6348C8 + 8 * i);
    *v5 = 0;
    v5[1] = 0;
    if ( i )
      *((_BYTE *)&MiState[1942] + i) = 2 * *((_BYTE *)&MiState[1941] + i + 3);
    else
      byte_6348D8 = 8;
  }
  dword_634498 = 5;
  dword_634500 = 0;
  dword_634980 = 0;
  qword_6337C8 = -10000000i64 * dword_681278;
  dword_632E10 = 0;
  dword_6337D4 = (int)&dword_6337D0;
  dword_6337D0 = (int)&dword_6337D0;
  dword_632E20 = MmHighestUserAddress;
  result = (_BYTE *)ExGenRandom(1);
  dword_632E20 -= ((unsigned __int8)result + 384) << 16;
  if ( dword_63388C )
  {
    result = strstr(*(_BYTE **)(a1 + 120), "USERVA");
    if ( !result )
      goto LABEL_29;
    result = strstr(result, "=");
    if ( !result )
      goto LABEL_29;
    result = (_BYTE *)atol((int)(result + 1));
    v12 = (unsigned int)(result + 3) & 0xFFFFFFFC;
    if ( v12 >= 0x800 )
    {
      if ( v12 > 0xC00 )
        v12 = 3072;
    }
    else
    {
      v12 = 2048;
    }
    v13 = (v12 - 2048) << 20;
    if ( !v13 )
LABEL_29:
      v13 = 0x40000000;
    v6 = MmSystemRangeStart + v13;
    MmSystemRangeStart += v13;
    MmUserProbeAddress += v13;
    MmHighestUserAddress += v13;
    MiMaximumWorkingSet += v13 >> 12;
  }
  else
  {
    v6 = MmSystemRangeStart;
  }
  dword_63389C = v6;
  if ( MmDynamicMemorySupported )
  {
    v7 = 0;
    v8 = MmDynamicPfn << 18;
    if ( !(MmDynamicPfn << 18) )
    {
      v16 = 0i64;
      v15 = 8;
      result = (_BYTE *)off_617B54(17, 8, &v16, &v15);
      if ( (int)result < 0 )
      {
LABEL_15:
        MmDynamicPfn = v8;
        goto LABEL_16;
      }
      v14 = v16;
      LODWORD(v16) = v16 >> 11;
      v8 = __SPAIR64__(HIDWORD(v16), v14) / 4096;
      v7 = (unsigned __int64)(__SPAIR64__(HIDWORD(v16), v14) / 4096) >> 32;
    }
    if ( v7 )
    {
      HIDWORD(v16) = 0;
      v8 = -1;
    }
    goto LABEL_15;
  }
  MmDynamicPfn = 0;
LABEL_16:
  unk_634700 = 0;
  *(_DWORD *)&word_634704 = 0;
  dword_634708[0] = 0;
  v9 = dword_634F90;
  v10 = 16;
  do
  {
    *v9 = (int)v9;
    v9[1] = (int)v9;
    v9 += 2;
    --v10;
  }
  while ( v10 );
  dword_634880 = 0;
  v11 = dword_634884;
  do
    *v11++ = 0;
  while ( v11 != &dword_634890 );
  dword_634894 = (int)&dword_634890;
  dword_634890 = (int)&dword_634890;
  return result;
}
