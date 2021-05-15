// CmpDuplicateKey 
 
int __fastcall CmpDuplicateKey(int a1, int a2, unsigned int *a3)
{
  int (__fastcall *v4)(int, int, int *); // r3
  _DWORD *v7; // r6
  int v8; // r0
  _DWORD *v9; // r5
  int v10; // r5
  int v11; // r0
  int v12; // r0
  int v13; // r1
  int v14; // r0
  int v15; // r3
  int v17; // [sp+10h] [bp-20h] BYREF
  _DWORD v18[7]; // [sp+14h] [bp-1Ch] BYREF

  v4 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
  v17 = -1;
  v18[0] = -1;
  v7 = 0;
  v8 = v4(a1, a2, &v17);
  v9 = (_DWORD *)v8;
  if ( !v8 )
    return -1073741670;
  v11 = CmpCopyKeyPartial(a1, a2, a1, *(_DWORD *)(v8 + 16), 6);
  *a3 = v11;
  if ( v11 == -1 )
    goto LABEL_4;
  v12 = (*(int (__fastcall **)(int, int, _DWORD *))(a1 + 4))(a1, v11, v18);
  v7 = (_DWORD *)v12;
  if ( !v12 )
  {
LABEL_6:
    CmpFreeKeyByCell(a1, *a3, 0);
LABEL_4:
    v10 = -1073741670;
    goto LABEL_12;
  }
  v13 = v9[7];
  if ( v13 == -1 )
  {
    *(_DWORD *)(v12 + 28) = -1;
  }
  else
  {
    v14 = CmpDuplicateIndex(a1, v13, 0);
    v7[7] = v14;
    if ( v14 == -1 )
      goto LABEL_6;
  }
  v7[5] = v9[5];
  v7[8] = v9[8];
  v15 = v9[6];
  v10 = 0;
  v7[6] = v15;
LABEL_12:
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v17);
  if ( v7 )
    (*(void (__fastcall **)(int, _DWORD *))(a1 + 8))(a1, v18);
  return v10;
}
