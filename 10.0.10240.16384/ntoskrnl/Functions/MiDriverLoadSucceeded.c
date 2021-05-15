// MiDriverLoadSucceeded 
 
int __fastcall MiDriverLoadSucceeded(int *a1, int a2, char *a3, unsigned __int16 *a4, int a5, char a6, char a7)
{
  int v9; // r3
  unsigned int v10; // r10
  unsigned int v11; // r6
  int *v12; // r5
  int v13; // r1
  int v14; // r4
  unsigned __int16 *v15; // r4
  int result; // r0
  int v17; // r2
  int v18; // r3
  unsigned int v19; // r1
  char *v21[2]; // [sp+10h] [bp-40h] BYREF
  char v22[4]; // [sp+18h] [bp-38h] BYREF
  int v23; // [sp+1Ch] [bp-34h]
  int v24; // [sp+20h] [bp-30h]
  int v25; // [sp+24h] [bp-2Ch]
  int v26; // [sp+28h] [bp-28h]
  int v27; // [sp+2Ch] [bp-24h]

  v9 = a2;
  v10 = (unsigned int)a1[8] >> 12;
  v21[0] = a3;
  if ( a6 == 1 )
  {
    a1[13] |= 0x41004000u;
    if ( (a7 & 1) == 0 )
    {
      MiFinalizeDriverImage((int)a1);
      do
        v11 = __ldrex((unsigned int *)algn_634DB0);
      while ( __strex(v11 + v10, (unsigned int *)algn_634DB0) );
      v9 = a2;
    }
    v12 = (int *)MiSectionControlArea(v9);
    v13 = *v12;
    v23 = 3;
    v23 = ((*(_BYTE *)(v13 + 11) & 0xF0) << 8) | 3;
    v23 = (v23 ^ (*(unsigned __int8 *)(v13 + 11) << 15)) & 0x70000 ^ v23 | 0x100;
    v26 = a1[8];
    v24 = a1[6];
    v25 = 0;
    v27 = 0;
    v14 = MI_REFERENCE_CONTROL_AREA_FILE((int)v12);
    PsCallImageNotifyRoutines(v21[0], 0, (int)v22, v14);
    MI_DEREFERENCE_CONTROL_AREA_FILE((int)v12, v14);
    if ( MiCacheImageSymbols(a1[6]) )
    {
      v15 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 256, 1850502477);
      if ( v15 )
      {
        if ( *a4 <= 0x16u || wcsnicmp(*((_DWORD *)a4 + 1), L"\\SystemRoot", 11) )
          return sub_7CDA74();
        v21[0] = *(char **)a4;
        v21[1] = (char *)(*((_DWORD *)a4 + 1) + 22);
        LOWORD(v21[0]) -= 22;
        if ( RtlStringCbPrintfW(v15, 0x100u, (int)L"%ws%wZ", -28620) >= 0 )
        {
          RtlInitUnicodeString((unsigned int)v21, v15);
          if ( DbgLoadImageSymbolsUnicode((int)v21, a1[6], v17, v18) == 1 )
            a1[13] |= 0x100000u;
        }
        ExFreePoolWithTag((unsigned int)v15);
      }
    }
  }
  result = MiSectionControlArea(a1[15]);
  if ( !*(_DWORD *)(result + 88) )
    result = MiProtectSystemImage(a1);
  if ( a1[6] >= (unsigned int)dword_63389C )
  {
    if ( *((_BYTE *)&MiState[2423] + MiGetSystemRegionIndex(a1[6])) == 1
      || (result = MiGetSystemRegionIndex(v19), *((_BYTE *)&MiState[2423] + result) == 11) )
    {
      result = MiSessionUpdateImageCharges((int)a1);
    }
  }
  return result;
}
