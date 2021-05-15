// CmpCommitDeleteKeyUoW 
 
int __fastcall CmpCommitDeleteKeyUoW(int a1, _DWORD *a2, int a3, int a4)
{
  int v4; // r3
  __int64 v5; // kr00_8
  _DWORD *v8; // r0
  _DWORD *v9; // r6
  int v10; // r5
  int v11; // r4
  int v12; // r1
  int v13; // r2
  _DWORD *v14; // r0
  int v15; // r2
  _DWORD *v16; // r4
  int v17; // r0
  int v19[8]; // [sp+0h] [bp-20h] BYREF

  v19[0] = a4;
  v4 = *(_DWORD *)(a1 + 24);
  v19[0] = -1;
  v5 = *(_QWORD *)(v4 + 20);
  v8 = (_DWORD *)(*(int (__fastcall **)(_DWORD, _DWORD, int *))(v5 + 4))(v5, HIDWORD(v5), v19);
  v9 = v8;
  if ( !v8 )
    return -1073741670;
  v11 = v8[4];
  if ( v8[5] + v8[6] )
  {
    v10 = -1073741535;
  }
  else
  {
    (*(void (__fastcall **)(_DWORD, int *))(v5 + 8))(v5, v19);
    v10 = CmpFreeKeyByCell(v5, HIDWORD(v5), 1);
    if ( v10 < 0 )
      return v10;
    CmpCleanUpSubKeyInfo(*(_DWORD **)(*(_DWORD *)(a1 + 24) + 40), v12, v13, *(_DWORD *)(a1 + 24));
    v14 = (_DWORD *)(*(int (__fastcall **)(_DWORD, int, int *))(v5 + 4))(v5, v11, v19);
    v9 = v14;
    if ( v14 )
    {
      *(_WORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 24) + 40) + 96) = v14[13];
      v14[1] = *a2;
      v14[2] = a2[1];
      v15 = *(_DWORD *)(*(_DWORD *)(a1 + 24) + 40);
      *(_DWORD *)(v15 + 88) = *a2;
      *(_DWORD *)(v15 + 92) = a2[1];
    }
    CmpFlushNotifiesOnKeyBodyList(*(_DWORD *)(a1 + 24));
    v16 = *(_DWORD **)(a1 + 24);
    v17 = v16[5];
    v16[1] |= 0x20000u;
    CmpRemoveKeyHash(v17, v16 + 3);
    v16[4] = -1;
    *(_DWORD *)(*(_DWORD *)(a1 + 24) + 24) = -1;
  }
  if ( v9 )
    (*(void (__fastcall **)(_DWORD, int *))(v5 + 8))(v5, v19);
  return v10;
}
