// CmpCheckLexicographicalOrder 
 
int __fastcall CmpCheckLexicographicalOrder(int a1, int a2, int a3)
{
  int (__fastcall *v5)(int, int, int *); // r3
  int v6; // r6
  int v7; // r0
  int v8; // r4
  __int16 v9; // r3
  int v11; // r7
  int v12; // r2
  int v13; // [sp+0h] [bp-28h] BYREF
  int v14; // [sp+4h] [bp-24h] BYREF
  unsigned __int16 v15; // [sp+8h] [bp-20h] BYREF
  unsigned __int16 v16; // [sp+Ah] [bp-1Eh]
  int v17; // [sp+Ch] [bp-1Ch]
  unsigned __int16 v18[2]; // [sp+10h] [bp-18h] BYREF
  int v19; // [sp+14h] [bp-14h]

  v5 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
  v13 = -1;
  v14 = -1;
  v6 = v5(a1, a3, &v13);
  v7 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, a2, &v14);
  v8 = v7;
  if ( !v6 || !v7 )
    goto LABEL_13;
  v9 = *(_WORD *)(v7 + 2);
  if ( (*(_WORD *)(v6 + 2) & 0x20) != 0 )
  {
    if ( (v9 & 0x20) == 0 )
      return sub_7FC148();
    if ( CmpCompareTwoCompressedNames(v7 + 76, *(unsigned __int16 *)(v7 + 72), v6 + 76, *(unsigned __int16 *)(v6 + 72)) < 0 )
      goto LABEL_7;
LABEL_13:
    v11 = 0;
    goto LABEL_8;
  }
  if ( (v9 & 0x20) != 0 )
  {
    v17 = v6 + 76;
    v12 = *(unsigned __int16 *)(v7 + 72);
    v15 = *(_WORD *)(v6 + 72);
    v16 = v15;
    if ( CmpCompareCompressedName(&v15, v7 + 76, v12, 0) <= 0 )
      goto LABEL_13;
  }
  else
  {
    v19 = v7 + 76;
    v18[0] = *(_WORD *)(v7 + 72);
    v18[1] = v18[0];
    v17 = v6 + 76;
    v15 = *(_WORD *)(v6 + 72);
    v16 = v15;
    if ( (RtlCompareUnicodeString(v18, &v15, 1) & 0x80000000) == 0 )
      goto LABEL_13;
  }
LABEL_7:
  v11 = 1;
LABEL_8:
  if ( v6 )
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v13);
  if ( v8 )
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v14);
  return v11;
}
