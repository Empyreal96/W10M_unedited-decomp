// CmpMergeKeyValues 
 
int __fastcall CmpMergeKeyValues(int a1, int a2, _DWORD *a3, int a4, unsigned int a5, unsigned int *a6)
{
  int v6; // r5
  unsigned int v7; // r1
  unsigned int v9; // r2
  unsigned int v11; // r2
  unsigned int v12; // r1
  unsigned int v13; // r8
  _WORD *v14; // r10
  int *v15; // r7
  unsigned int v16; // r9
  _WORD *v17; // r0
  BOOL v18; // r0
  void (__fastcall *v19)(int, int *); // r3
  int v20; // r0
  int v23; // [sp+14h] [bp-3Ch] BYREF
  _DWORD v24[4]; // [sp+18h] [bp-38h] BYREF
  __int16 v25; // [sp+28h] [bp-28h] BYREF
  int v26; // [sp+2Ah] [bp-26h]
  __int16 v27; // [sp+2Eh] [bp-22h]

  v6 = 0;
  v7 = a6[15];
  v9 = a3[15];
  v23 = -1;
  v24[0] = -1;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  if ( v7 < v9 )
    a6[15] = v9;
  v11 = a3[16];
  v12 = a6[16];
  if ( v12 < v11 )
    a6[16] = v11;
  if ( !a6[9] )
    return CmpSyncKeyValues(a1, v12, a3, a4, a5);
  v13 = a3[9];
  if ( !v13 )
    return 1;
  v14 = (_WORD *)ExAllocatePoolWithTag(1, 0x7FFF, 538987843);
  if ( !v14 )
    return 0;
  v15 = (int *)(*(int (__fastcall **)(int, _DWORD, _DWORD *))(a1 + 4))(a1, a3[10], v24);
  if ( v15 )
  {
    v16 = 0;
    while ( 1 )
    {
      v17 = (_WORD *)(*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, *v15, &v23);
      if ( !v17 )
        break;
      CmpInitializeValueNameString(v17, (int)&v25, v14);
      v18 = CmpFindNameInList();
      v19 = *(void (__fastcall **)(int, int *))(a1 + 8);
      if ( !v18 )
      {
        v19(a1, &v23);
        break;
      }
      v19(a1, &v23);
      if ( v24[1] == -1 )
      {
        v20 = CmpCopyValue(a1, *v15, a4, a5 >> 31);
        if ( v20 == -1 || CmpAddValueToListEx(a4, v20, v24[2], a5 >> 31, a6 + 9, 1) < 0 )
          break;
      }
      ++v16;
      ++v15;
      if ( v16 >= v13 )
      {
        v6 = 1;
        break;
      }
    }
    (*(void (__fastcall **)(int, _DWORD *))(a1 + 8))(a1, v24);
  }
  ExFreePoolWithTag((unsigned int)v14);
  return v6;
}
