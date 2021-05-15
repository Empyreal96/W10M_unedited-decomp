// CmpFindValueByNameFromCache 
 
int __fastcall CmpFindValueByNameFromCache(_DWORD *a1, unsigned __int16 *a2, _DWORD *a3, _DWORD *a4)
{
  int v5; // r4
  int v6; // r5
  int *v9; // r8
  int v10; // r7
  int v11; // t1
  int v12; // r0
  unsigned int v13; // r0
  int v15; // [sp+0h] [bp-38h] BYREF
  int v16; // [sp+4h] [bp-34h] BYREF
  _DWORD *v17; // [sp+8h] [bp-30h]
  unsigned __int16 v18[2]; // [sp+10h] [bp-28h] BYREF
  int v19; // [sp+14h] [bp-24h]

  v5 = a1[13];
  v17 = a3;
  v6 = 0;
  v15 = -1;
  v16 = -1;
  if ( !v5 )
    return 0;
  v9 = (int *)(*(int (__fastcall **)(_DWORD, _DWORD, int *))(a1[5] + 4))(a1[5], a1[14], &v16);
  if ( v9 )
  {
    v10 = 0;
    if ( a1[13] )
    {
      while ( 1 )
      {
        v11 = *v9++;
        v12 = (*(int (__fastcall **)(_DWORD, int, int *))(a1[5] + 4))(a1[5], v11, &v15);
        v6 = v12;
        if ( !v12 )
          break;
        if ( (*(_WORD *)(v12 + 16) & 1) != 0 )
        {
          v13 = CmpCompareCompressedName(a2, (unsigned __int8 *)(v12 + 20), *(_WORD *)(v12 + 2), 0);
        }
        else
        {
          v18[0] = *(_WORD *)(v12 + 2);
          v18[1] = v18[0];
          v19 = v12 + 20;
          v13 = RtlCompareUnicodeString(a2, v18, 1);
        }
        if ( !v13 )
        {
          *v17 = v10;
          *a4 = v15;
          HvpGetCellContextReinitialize(&v15);
          break;
        }
        (*(void (__fastcall **)(_DWORD, int *))(a1[5] + 8))(a1[5], &v15);
        if ( (unsigned int)++v10 >= a1[13] )
        {
          (*(void (__fastcall **)(_DWORD, int *))(a1[5] + 8))(a1[5], &v16);
          return 0;
        }
      }
    }
    (*(void (__fastcall **)(_DWORD, int *))(a1[5] + 8))(a1[5], &v16);
  }
  return v6;
}
