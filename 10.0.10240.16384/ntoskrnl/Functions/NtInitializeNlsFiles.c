// NtInitializeNlsFiles 
 
int __fastcall NtInitializeNlsFiles(unsigned int a1, unsigned int a2, unsigned int a3, int a4)
{
  _DWORD *v5; // r9
  _DWORD *v6; // r8
  int v7; // r4
  _DWORD *v8; // r2
  _DWORD *v9; // r2
  int v10; // r1
  int v12; // [sp+1Ch] [bp-34h] BYREF
  int v13; // [sp+20h] [bp-30h] BYREF
  _DWORD v14[3]; // [sp+24h] [bp-2Ch] BYREF
  _DWORD _30[14]; // [sp+30h] [bp-20h] BYREF

  _30[13] = a4;
  _30[12] = a3;
  v5 = (_DWORD *)a2;
  _30[11] = a2;
  v6 = (_DWORD *)a1;
  _30[10] = a1;
  if ( !*(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    return -1073741637;
  v8 = (_DWORD *)a1;
  if ( a1 >= MmUserProbeAddress )
    v8 = (_DWORD *)MmUserProbeAddress;
  *v8 = *v8;
  v9 = (_DWORD *)a2;
  if ( a2 >= MmUserProbeAddress )
    v9 = (_DWORD *)MmUserProbeAddress;
  *v9 = *v9;
  if ( (a3 & 7) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  if ( a3 >= MmUserProbeAddress )
    *(_BYTE *)MmUserProbeAddress = 0;
  *(_BYTE *)a3 = *(_BYTE *)a3;
  v7 = ZwQueryDefaultLocale();
  if ( v7 >= 0 )
  {
    v7 = ExpGetGlobalLocaleSection(&v12);
    if ( v7 >= 0 )
    {
      v13 = 0;
      _30[0] = 0;
      _30[1] = 0;
      v14[0] = 0;
      v10 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      v7 = MmMapViewOfSection(v12, v10, &v13, 0, 0, _30, v14, 1, 0x400000, 2);
      ObfDereferenceObject(v12);
      if ( v7 >= 0 )
      {
        *v6 = v13;
        *v5 = v14[1];
        *(_DWORD *)a3 = NlsDefaultCasingTableSize;
        *(_DWORD *)(a3 + 4) = dword_92037C;
      }
    }
  }
  return v7;
}
