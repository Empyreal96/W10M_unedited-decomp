// CmpFreeKeyByCell 
 
int __fastcall CmpFreeKeyByCell(int a1, unsigned int a2, int a3)
{
  int v6; // r0
  int v7; // r2
  int v8; // r6
  int v9; // r0
  __int16 v10; // r3
  int v11; // r3
  int *v12; // r7
  unsigned int i; // r5
  int v14; // t1
  int v15; // r5
  int v17; // [sp+0h] [bp-20h] BYREF
  int v18; // [sp+4h] [bp-1Ch] BYREF
  int v19[6]; // [sp+8h] [bp-18h] BYREF

  v17 = -1;
  v18 = -1;
  v19[0] = -1;
  CmLockHiveSecurityExclusive(a1);
  if ( !CmpMarkKeyDirty(a1, a2, a3) )
  {
    v15 = -1073741443;
    goto LABEL_21;
  }
  v6 = (*(int (__fastcall **)(int, unsigned int, int *))(a1 + 4))(a1, a2, &v17);
  v8 = v6;
  if ( !v6 )
    goto LABEL_23;
  if ( a3 == 1 )
  {
    if ( !CmpRemoveSubKey(a1, *(_DWORD *)(v6 + 16), a2) )
      goto LABEL_24;
    v9 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(v8 + 16), &v18);
    if ( !v9 )
      goto LABEL_24;
    if ( !(*(_DWORD *)(v9 + 20) + *(_DWORD *)(v9 + 24)) )
    {
      *(_WORD *)(v9 + 52) = 0;
      *(_DWORD *)(v9 + 56) = 0;
    }
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v18);
  }
  v10 = *(_WORD *)(v8 + 2);
  if ( (v10 & 2) != 0 || (v10 & 0x40) != 0 )
  {
LABEL_17:
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v17);
    v8 = 0;
    if ( CmpFreeKeyBody(a1, a2) )
    {
      v15 = 0;
      goto LABEL_19;
    }
LABEL_23:
    v15 = -1073741670;
    goto LABEL_21;
  }
  v11 = *(_DWORD *)(v8 + 36);
  if ( !v11 )
  {
LABEL_16:
    CmpFreeSecurityDescriptor(a1, a2, v7, v11);
    goto LABEL_17;
  }
  v12 = (int *)(*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(v8 + 40), v19);
  if ( v12 )
  {
    for ( i = 0; i < *(_DWORD *)(v8 + 36); ++i )
    {
      v14 = *v12++;
      CmpFreeValue(a1, v14);
    }
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v19);
    HvFreeCell(a1, *(_DWORD *)(v8 + 40));
    goto LABEL_16;
  }
LABEL_24:
  v15 = -1073741670;
LABEL_19:
  if ( v8 )
    return sub_805E64();
LABEL_21:
  CmUnlockHiveSecurity(a1);
  return v15;
}
