// CmpCommitSetValueKeyUoW 
 
int __fastcall CmpCommitSetValueKeyUoW(int *a1, _DWORD *a2)
{
  int v3; // r3
  int v4; // r5
  int v5; // r1
  int (__fastcall *v6)(int, int, int *); // r3
  int v7; // r9
  _DWORD *v8; // r8
  int v9; // r0
  int v10; // r10
  int v11; // r4
  unsigned int v12; // r6
  int v13; // r3
  int v14; // r0
  int v15; // r3
  _WORD *v16; // r0
  int v17; // r4
  _DWORD *v18; // r0
  __int16 v19; // r2
  _DWORD *v20; // r1
  int v21; // r2
  char v23[4]; // [sp+10h] [bp-50h] BYREF
  int v24; // [sp+14h] [bp-4Ch]
  int v25; // [sp+18h] [bp-48h] BYREF
  unsigned int v26; // [sp+1Ch] [bp-44h] BYREF
  int v27; // [sp+20h] [bp-40h]
  int v28; // [sp+24h] [bp-3Ch] BYREF
  _WORD *v29; // [sp+28h] [bp-38h]
  int v30; // [sp+2Ch] [bp-34h] BYREF
  int v31; // [sp+30h] [bp-30h] BYREF
  _DWORD *v32; // [sp+34h] [bp-2Ch]
  __int16 v33[20]; // [sp+38h] [bp-28h] BYREF

  v27 = 0;
  v29 = 0;
  v3 = a1[6];
  v30 = -1;
  v31 = -1;
  v28 = -1;
  v4 = *(_DWORD *)(v3 + 20);
  v32 = a2;
  v5 = a1[13];
  v6 = *(int (__fastcall **)(int, int, int *))(v4 + 4);
  v7 = 0;
  v24 = 0;
  v25 = 0;
  v23[0] = 0;
  v8 = 0;
  v9 = v6(v4, v5, &v31);
  v10 = v9;
  if ( !v9 )
    return -1073741670;
  v12 = *(_DWORD *)(v9 + 4);
  if ( v12 < 0x80000000 )
  {
    v13 = 0;
  }
  else
  {
    v12 += 0x80000000;
    v13 = 1;
  }
  v26 = v12;
  if ( v12 )
  {
    if ( v13 == 1 )
    {
      v7 = v9 + 8;
    }
    else
    {
      v14 = CmpGetValueData(v4, a1[13], v9, &v26, &v25, v23, (int)&v28);
      v7 = v25;
      if ( !v14 )
      {
        v11 = -1073741670;
        v15 = (unsigned __int8)v23[0];
        goto LABEL_30;
      }
      v27 = 1;
      v12 = v26;
      v24 = (unsigned __int8)v23[0];
    }
  }
  v8 = (_DWORD *)(*(int (__fastcall **)(int, _DWORD, int *))(v4 + 4))(v4, *(_DWORD *)(a1[6] + 24), &v30);
  if ( v8 )
  {
    if ( !HvpMarkCellDirty(v4, *(_DWORD *)(a1[6] + 24), 0, 0) )
    {
      v11 = -1073741443;
      goto LABEL_29;
    }
    a1[10] = *(_DWORD *)(a1[6] + 24) >> 31;
    v16 = (_WORD *)ExAllocatePoolWithTag(1, 0x8000, 1649626435);
    v29 = v16;
    if ( v16 )
    {
      CmpInitializeValueNameString((_WORD *)v10, (int)v33, v16);
      if ( CmpFindNameInList() )
      {
        if ( a1[9] != 5 || (v17 = v26, v26 == -1) )
        {
          v11 = CmpSetValueKeyNew(v4, (int)v8, (int)v33, v25, *(_DWORD *)(v10 + 12), v7, v12, a1[10]);
LABEL_23:
          if ( v11 >= 0 )
          {
            HvpMarkCellDirty(v4, a1[13], 0, 0);
            v19 = v33[0];
            if ( v8[15] < (unsigned int)(unsigned __int16)v33[0] )
            {
              v8[15] = (unsigned __int16)v33[0];
              *(_WORD *)(a1[6] + 98) = v19;
            }
            if ( v8[16] < v12 )
            {
              v8[16] = v12;
              *(_DWORD *)(a1[6] + 100) = v12;
            }
            v20 = v32;
            v8[1] = *v32;
            v8[2] = v20[1];
            v21 = a1[6];
            *(_DWORD *)(v21 + 88) = *v20;
            *(_DWORD *)(v21 + 92) = v20[1];
            CmpCleanUpKcbValueCache(a1[6]);
            *(_DWORD *)(a1[6] + 52) = v8[9];
            *(_DWORD *)(a1[6] + 56) = v8[10];
          }
          goto LABEL_29;
        }
        v26 = -1;
        v18 = (_DWORD *)(*(int (__fastcall **)(int, int, unsigned int *))(v4 + 4))(v4, v17, &v26);
        if ( v18 )
        {
          v11 = CmpSetValueKeyExisting(v4, v17, v18, *(_DWORD *)(v10 + 12), v7, v12, a1[10]);
          (*(void (__fastcall **)(int, unsigned int *))(v4 + 8))(v4, &v26);
          goto LABEL_23;
        }
      }
    }
  }
  v11 = -1073741670;
LABEL_29:
  v15 = v24;
LABEL_30:
  if ( v7 && v27 )
  {
    if ( v15 )
      ExFreePoolWithTag(v7);
    else
      (*(void (__fastcall **)(int, int *))(v4 + 8))(v4, &v28);
  }
  if ( v29 )
    ExFreePoolWithTag((unsigned int)v29);
  if ( v8 )
    (*(void (__fastcall **)(int, int *))(v4 + 8))(v4, &v30);
  (*(void (__fastcall **)(int, int *))(v4 + 8))(v4, &v31);
  return v11;
}
