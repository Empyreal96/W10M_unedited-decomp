// RtlpGetRegistryHandle 
 
int __fastcall RtlpGetRegistryHandle(int a1, int a2, int a3, int *a4)
{
  unsigned int v6; // r4
  int v7; // r4
  _DWORD *v9; // r5
  int v10; // r7
  _DWORD *v11; // r0
  int v12; // r2
  int v13; // r3
  int v14; // r2
  int v15; // r3
  int v16; // r0
  _DWORD *v17; // r0
  unsigned int v18; // r1
  int v19; // r5
  unsigned int v20; // r2
  unsigned int v21; // r2
  int v22; // r7
  int v23; // r1
  int v24; // r2
  int v25; // r0
  unsigned __int16 v26[2]; // [sp+10h] [bp-48h] BYREF
  _DWORD *v27; // [sp+14h] [bp-44h]
  _DWORD v28[16]; // [sp+18h] [bp-40h] BYREF

  v6 = a1;
  if ( (a1 & 0x40000000) != 0 )
  {
    *a4 = a2;
    return 0;
  }
  if ( a1 < 0 )
    v6 = a1 & 0x7FFFFFFF;
  if ( v6 < 6 )
  {
    v9 = (_DWORD *)((unsigned int)KeGetPcr() & 0xFFFFF000);
    v10 = v9[720];
    ++*(_DWORD *)(v10 + 12);
    v11 = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)v10);
    if ( v11 )
      goto LABEL_9;
    ++*(_DWORD *)(v10 + 16);
    v22 = v9[721];
    ++*(_DWORD *)(v22 + 12);
    v11 = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)v22);
    if ( v11
      || (v23 = *(_DWORD *)(v22 + 36),
          v24 = *(_DWORD *)(v22 + 32),
          v25 = *(_DWORD *)(v22 + 28),
          ++*(_DWORD *)(v22 + 16),
          (v11 = (_DWORD *)(*(int (__fastcall **)(int, int, int))(v22 + 40))(v25, v23, v24)) != 0) )
    {
LABEL_9:
      *v11 = v9[357];
    }
    v27 = v11;
    if ( !v11 )
      return -1073741801;
    v26[0] = 0;
    v13 = 524;
    v26[1] = 524;
    if ( !v6
      || (v6 != 5 || RtlFormatCurrentUserKeyPath((unsigned __int16 *)v28) < 0 ? (v7 = RtlAppendUnicodeToString(
                                                                                        v26,
                                                                                        RtlpRegistryPaths[v6],
                                                                                        v12,
                                                                                        (int)RtlpRegistryPaths)) : (v7 = RtlAppendUnicodeStringToString(v26, (unsigned __int16 *)v28), RtlFreeAnsiString(v28)),
          v7 >= 0 && (v7 = RtlAppendUnicodeToString(v26, (int)L"\\", v14, v15), v7 >= 0)) )
    {
      v7 = RtlAppendUnicodeToString(v26, a2, v12, v13);
      if ( v7 >= 0 )
      {
        v28[2] = 24;
        v28[3] = 0;
        v28[5] = 576;
        v28[4] = v26;
        v28[6] = 0;
        v28[7] = 0;
        if ( a3 )
          v16 = ZwCreateKey();
        else
          v16 = ZwOpenKey();
        v7 = v16;
      }
    }
    v17 = v27;
    v18 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v19 = *(_DWORD *)(v18 + 2880);
    v20 = *(unsigned __int16 *)(v19 + 8);
    ++*(_DWORD *)(v19 + 20);
    if ( *(unsigned __int16 *)(v19 + 4) < v20
      || (++*(_DWORD *)(v19 + 24),
          v19 = *(_DWORD *)(v18 + 2884),
          v21 = *(unsigned __int16 *)(v19 + 8),
          ++*(_DWORD *)(v19 + 20),
          *(unsigned __int16 *)(v19 + 4) < v21) )
    {
      RtlpInterlockedPushEntrySList((unsigned __int64 *)v19, v17);
    }
    else
    {
      ++*(_DWORD *)(v19 + 24);
      (*(void (__fastcall **)(_DWORD *))(v19 + 44))(v17);
    }
    return v7;
  }
  return sub_80A914();
}
