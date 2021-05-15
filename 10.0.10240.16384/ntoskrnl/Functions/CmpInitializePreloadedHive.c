// CmpInitializePreloadedHive 
 
int __fastcall CmpInitializePreloadedHive(int a1, int a2)
{
  int v4; // r5
  int v5; // r0
  int v6; // r2
  unsigned int v7; // r9
  int v8; // r3
  int v9; // r3
  int v10; // r2
  int v11; // r3
  unsigned int v12; // r4
  __int16 v13; // r8
  int v14; // r0
  unsigned __int16 *v15; // r7
  int v16; // r3
  int v17; // r2
  int v18; // r0
  _DWORD *v19; // r4
  int v20; // r2
  int v21; // r3
  int v22; // r3
  char *v23; // r2
  int v24; // r2
  int v25; // r3
  int v26; // r2
  int v27; // r3
  int v28; // r2
  int v29; // r3
  int v30; // r0
  int **v31; // r0
  char v33[8]; // [sp+20h] [bp-1E0h] BYREF
  unsigned __int16 v34; // [sp+28h] [bp-1D8h] BYREF
  __int16 v35; // [sp+2Ah] [bp-1D6h]
  unsigned __int16 *v36; // [sp+2Ch] [bp-1D4h]
  unsigned __int16 v37[2]; // [sp+30h] [bp-1D0h] BYREF
  char *v38; // [sp+34h] [bp-1CCh]
  _DWORD *v39; // [sp+38h] [bp-1C8h] BYREF
  int v40; // [sp+40h] [bp-1C0h] BYREF
  char v41[284]; // [sp+44h] [bp-1BCh] BYREF
  char v42[160]; // [sp+160h] [bp-A0h] BYREF

  v40 = 0;
  memset(v41, 0, sizeof(v41));
  v4 = 4096;
  v39 = 0;
  v33[0] = 0;
  v5 = ExAllocatePoolWithTag(1, 4096, 538987843);
  v7 = v5;
  if ( !v5 )
    KeBugCheckEx(116, 3, 4, 0, -1073741670);
  v34 = 0;
  v8 = *(_DWORD *)(a1 + 12);
  v35 = 4096;
  v36 = (unsigned __int16 *)v5;
  if ( (v8 & 0x16) != 0 )
  {
    RtlAppendUnicodeToString(&v34, *(_DWORD *)(a1 + 8), v6, v8);
    v9 = *(_DWORD *)(a1 + 12);
    if ( (v9 & 2) == 0 )
    {
      if ( (v9 & 4) != 0 )
        v4 = 0x2000;
      else
        v4 = 1;
    }
  }
  else
  {
    RtlAppendUnicodeToString(&v34, (int)L"\\SystemRoot\\System32\\Config\\", v6, v8);
    RtlAppendUnicodeToString(&v34, *(_DWORD *)(a1 + 8), v10, v11);
    v4 = 0x4000;
  }
  v12 = v34;
  v13 = v34 + 2;
  v14 = ExAllocatePoolWithTag(1, v34 + 2, 538987843);
  v15 = (unsigned __int16 *)v14;
  if ( !v14 )
    KeBugCheckEx(116, 3, 4, 0, -1073741670);
  memmove(v14, (int)v36, v12);
  ExFreePoolWithTag(v7);
  v15[v12 >> 1] = 0;
  v16 = *(_DWORD *)(a1 + 12);
  v17 = 18;
  v35 = v13;
  v36 = v15;
  if ( (v16 & 8) != 0 )
    v17 = 274;
  v18 = CmpInitializeHive((int)&v39, 1u, v17, 2u, *(_DWORD **)(a1 + 16), 0, (int)&v34, 65544, 0, 0, v33, &v40);
  if ( v18 < 0 )
    KeBugCheckEx(116, 3, 5, (int)&v40, v18);
  v19 = v39;
  RtlInitUnicodeString((unsigned int)(v39 + 492), v15);
  v20 = v19[23] | v4 | 0x400;
  v21 = (unsigned __int8)v33[0];
  v19[23] = v20;
  if ( v21 == 1 )
    v19[23] = v20 | 0x800;
  if ( CmpShareSystemHives )
    v19[23] = v19[23] & 0xFFFDFFFF | 1;
  v22 = *(_DWORD *)(v19[8] + 4088);
  CmpBootType = v22;
  v23 = (char *)CmSelfHeal;
  if ( !CmSelfHeal )
  {
    v23 = &CmpSelfHeal;
    CmpSelfHeal = 0;
    if ( (v22 & 4) != 0 )
      KeBugCheckEx(116, 3, 6, (int)v19, 0);
  }
  v37[0] = 0;
  v37[1] = 128;
  v38 = v42;
  RtlAppendUnicodeToString(v37, (int)L"\\REGISTRY\\", (int)v23, (int)v42);
  RtlAppendUnicodeToString(v37, *(_DWORD *)(a1 + 28), v24, v25);
  RtlAppendUnicodeToString(v37, (int)L"\\", v26, v27);
  RtlAppendUnicodeToString(v37, *(_DWORD *)(a1 + 24), v28, v29);
  v30 = CmpLinkHiveToMaster(v37, 0, (int)v19, 0, 512, 0, 0, a2, 1);
  if ( v30 < 0 )
    KeBugCheck2(116, 3, 7u, (unsigned int)v19, v30, 0);
  v31 = (int **)dword_632524;
  v19[454] = &CmpPreloadedHivesList;
  v19[455] = v31;
  if ( *v31 != &CmpPreloadedHivesList )
    __fastfail(3u);
  *v31 = v19 + 454;
  dword_632524 = (int)(v19 + 454);
  return 1;
}
