// CmpFindNameInListWithStatus 
 
int __fastcall CmpFindNameInListWithStatus(int a1, _DWORD *a2, int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  int v6; // r7
  int v7; // r6
  bool v8; // zf
  int v12; // r0
  int v14; // r4
  int *i; // r3
  int v16; // r1
  int v17; // r0
  int v18; // r0
  int v19; // r4
  int v20; // r2
  int v21; // [sp+0h] [bp-38h] BYREF
  int v22; // [sp+4h] [bp-34h]
  int v23; // [sp+8h] [bp-30h] BYREF
  int *v24; // [sp+Ch] [bp-2Ch]
  unsigned __int16 v25[2]; // [sp+10h] [bp-28h] BYREF
  int v26; // [sp+14h] [bp-24h]

  v6 = 0;
  v7 = 0;
  v8 = *a2 == 0;
  v21 = -1;
  v22 = a4;
  v23 = -1;
  if ( v8 )
  {
    if ( a5 )
      *a5 = 0;
    *a6 = -1;
LABEL_15:
    v19 = -1073741772;
  }
  else
  {
    v12 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, a2[1], &v23);
    v6 = v12;
    if ( !v12 )
      return sub_8044E8();
    v14 = 0;
    for ( i = (int *)v12; ; i = v24 )
    {
      v16 = *i;
      v24 = i + 1;
      v17 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v16, &v21);
      v7 = v17;
      if ( !v17 )
      {
        v19 = -1073741670;
        *a6 = -1;
        goto LABEL_18;
      }
      if ( (*(_WORD *)(v17 + 16) & 1) != 0 )
      {
        v18 = (v22 & 0x10000) != 0 ? CmpCompareTwoCompressedNames(
                                       *(unsigned __int8 **)(a3 + 4),
                                       *(_WORD *)a3,
                                       (unsigned __int8 *)(v17 + 20),
                                       *(_WORD *)(v17 + 2)) : CmpCompareCompressedName(
                                                                (unsigned __int16 *)a3,
                                                                (unsigned __int8 *)(v17 + 20),
                                                                *(_WORD *)(v17 + 2),
                                                                0);
      }
      else
      {
        v25[0] = *(_WORD *)(v17 + 2);
        v25[1] = v25[0];
        v26 = v17 + 20;
        v18 = (v22 & 0x10000) != 0 ? -CmpCompareCompressedName(v25, *(unsigned __int8 **)(a3 + 4), *(_WORD *)a3, 0) : RtlCompareUnicodeString((unsigned __int16 *)a3, v25, 1);
      }
      if ( !v18 )
        break;
      if ( ++v14 == *a2 )
      {
        if ( a5 )
          *a5 = v14;
        *a6 = -1;
        goto LABEL_15;
      }
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v21);
    }
    if ( a5 )
      *a5 = v14;
    v20 = *(_DWORD *)(v6 + 4 * v14);
    v19 = 0;
    *a6 = v20;
  }
  if ( v7 )
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v21);
LABEL_18:
  if ( v6 )
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v23);
  return v19;
}
