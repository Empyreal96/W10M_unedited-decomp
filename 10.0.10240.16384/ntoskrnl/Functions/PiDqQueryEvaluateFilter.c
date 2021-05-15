// PiDqQueryEvaluateFilter 
 
int __fastcall PiDqQueryEvaluateFilter(int a1, int a2, bool *a3)
{
  int v6; // r3
  int v7; // r4
  _BYTE *v8; // r0
  unsigned int v9; // r6
  int v10; // r1
  int v11; // r2
  int v12; // r5
  int v14; // [sp+8h] [bp-38h] BYREF
  int v15; // [sp+Ch] [bp-34h] BYREF
  int v16; // [sp+10h] [bp-30h] BYREF
  int v17; // [sp+14h] [bp-2Ch]
  unsigned int v18; // [sp+18h] [bp-28h]
  int v19; // [sp+1Ch] [bp-24h]
  int v20; // [sp+20h] [bp-20h]
  int v21; // [sp+24h] [bp-1Ch]

  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  *a3 = 0;
  v6 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 52);
  v7 = 0;
  v14 = 0;
  v8 = (_BYTE *)ExAllocatePoolWithTag(1, 40 * v6, 1483763280);
  v9 = (unsigned int)v8;
  if ( v8 )
  {
    memset(v8, 0, 40 * *(_DWORD *)(*(_DWORD *)(a1 + 12) + 52));
    v17 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 52);
    v18 = v9;
    v20 = a2;
    v21 = a1;
    PiPnpRtlBeginOperation(&v14, v10, v11, v17);
    v12 = FilterEval(
            PiDqPropertyCallback,
            &v16,
            *(_DWORD *)(*(_DWORD *)(a1 + 12) + 52),
            *(_DWORD *)(*(_DWORD *)(a1 + 12) + 56),
            &v15);
    if ( v12 >= 0 )
      *a3 = v15 != 0;
    PnpFreeDevPropertyArray(v19, v9);
    v7 = v14;
  }
  else
  {
    v12 = -1073741670;
  }
  if ( v16 )
    return sub_7EBFD8();
  if ( v7 )
    PiPnpRtlEndOperation(v7);
  return v12;
}
