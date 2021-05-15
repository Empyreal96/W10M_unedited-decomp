// CmpCommitDeleteValueKeyUoW 
 
int __fastcall CmpCommitDeleteValueKeyUoW(int a1, _DWORD *a2)
{
  int v3; // r3
  int v4; // r5
  _DWORD *v5; // r6
  int v6; // r4
  int v7; // r1
  int (__fastcall *v8)(int, int, int *); // r3
  _WORD *v9; // r8
  _WORD *v10; // r0
  unsigned int v11; // r10
  int v12; // r9
  int v13; // r2
  int v14; // r3
  int v15; // r3
  int v16; // r2
  int v17; // r3
  _DWORD *v18; // r1
  int v19; // r2
  int v21; // [sp+8h] [bp-40h] BYREF
  int v22; // [sp+Ch] [bp-3Ch]
  int v23[2]; // [sp+10h] [bp-38h] BYREF
  _DWORD *v24; // [sp+18h] [bp-30h]
  __int16 v25; // [sp+20h] [bp-28h] BYREF
  int v26; // [sp+22h] [bp-26h]
  __int16 v27; // [sp+26h] [bp-22h]

  v25 = 0;
  v26 = 0;
  v27 = 0;
  v3 = *(_DWORD *)(a1 + 24);
  v23[0] = -1;
  v21 = -1;
  v4 = *(_DWORD *)(v3 + 20);
  v24 = a2;
  v5 = (_DWORD *)(*(int (__fastcall **)(int, _DWORD, int *))(v4 + 4))(v4, *(_DWORD *)(v3 + 24), v23);
  if ( !v5 )
    return -1073741670;
  v7 = *(_DWORD *)(a1 + 48);
  v8 = *(int (__fastcall **)(int, int, int *))(v4 + 4);
  v22 = -1;
  v9 = (_WORD *)v8(v4, v7, &v21);
  if ( v9 )
  {
    v10 = (_WORD *)ExAllocatePoolWithTag(1, 0x8000, 1649626435);
    v11 = (unsigned int)v10;
    if ( v10 )
    {
      CmpInitializeValueNameString(v9, (int)&v25, v10);
      if ( CmpFindNameInList()
        && (v12 = v22, v22 != -1)
        && ((*(void (__fastcall **)(int, int *))(v4 + 8))(v4, &v21),
            (v9 = (_WORD *)(*(int (__fastcall **)(int, int, int *))(v4 + 4))(v4, v12, &v21)) != 0) )
      {
        if ( HvpMarkCellDirty(v4, *(_DWORD *)(*(_DWORD *)(a1 + 24) + 24), 0, 0)
          && HvpMarkCellDirty(v4, v5[10], 0, 0)
          && HvpMarkCellDirty(v4, v12, 0, 0)
          && CmpMarkValueDataDirty(v4, (int)v9, v13, v14) )
        {
          v6 = CmpRemoveValueFromList(v4, v23[1], v5 + 9, v15);
          if ( v6 >= 0 )
          {
            CmpFreeValue(v4, v12, v16, v17);
            v18 = v24;
            v5[1] = *v24;
            v5[2] = v18[1];
            v19 = *(_DWORD *)(a1 + 24);
            *(_DWORD *)(v19 + 88) = *v18;
            *(_DWORD *)(v19 + 92) = v18[1];
            if ( !v5[9] )
            {
              v5[15] = 0;
              v5[16] = 0;
              *(_WORD *)(*(_DWORD *)(a1 + 24) + 98) = 0;
              *(_DWORD *)(*(_DWORD *)(a1 + 24) + 100) = 0;
            }
            CmpCleanUpKcbValueCache(*(_DWORD *)(a1 + 24));
            *(_DWORD *)(*(_DWORD *)(a1 + 24) + 52) = v5[9];
            *(_DWORD *)(*(_DWORD *)(a1 + 24) + 56) = v5[10];
          }
        }
        else
        {
          v6 = -1073741443;
        }
      }
      else
      {
        v6 = -1073741670;
      }
      ExFreePoolWithTag(v11);
    }
    else
    {
      v6 = -1073741670;
    }
    if ( v9 )
      (*(void (__fastcall **)(int, int *))(v4 + 8))(v4, &v21);
  }
  else
  {
    v6 = -1073741670;
  }
  (*(void (__fastcall **)(int, int *))(v4 + 8))(v4, v23);
  return v6;
}
