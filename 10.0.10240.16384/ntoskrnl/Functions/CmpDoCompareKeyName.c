// CmpDoCompareKeyName 
 
int __fastcall CmpDoCompareKeyName(int a1, unsigned __int16 *a2, int a3)
{
  int v4; // r5
  int (__fastcall *v5)(int, int, int *); // r3
  int v6; // r6
  int v7; // r0
  unsigned __int16 *v8; // r6
  int v9; // r5
  int v10; // r8
  unsigned __int8 *v11; // r7
  unsigned int v12; // r0
  unsigned int v13; // t1
  unsigned int v14; // r4
  unsigned int v15; // t1
  signed int v16; // r4
  int v17; // r10
  int v19[2]; // [sp+0h] [bp-30h] BYREF
  int v20[10]; // [sp+8h] [bp-28h] BYREF

  v4 = a1;
  v5 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
  v6 = -1;
  v20[0] = a1;
  v19[0] = -1;
  v7 = v5(a1, a3, v19);
  if ( !v7 )
    return 2;
  if ( (*(_WORD *)(v7 + 2) & 0x20) != 0 )
  {
    v8 = (unsigned __int16 *)*((_DWORD *)a2 + 1);
    v9 = *(unsigned __int16 *)(v7 + 72);
    v10 = *a2 >> 1;
    v11 = (unsigned __int8 *)(v7 + 76);
    if ( v10 )
    {
      while ( v9 )
      {
        v13 = *v8++;
        v12 = v13;
        v15 = *v11++;
        v14 = v15;
        if ( v12 != v15 )
        {
          if ( v12 >= 0x61 )
          {
            if ( v12 > 0x7A )
              LOWORD(v12) = RtlUpcaseUnicodeChar(v12);
            else
              LOWORD(v12) = v12 - 32;
          }
          v17 = (unsigned __int16)v12;
          if ( v14 >= 0x61 )
          {
            if ( v14 > 0x7A )
              LOWORD(v14) = RtlUpcaseUnicodeChar(v14);
            else
              LOWORD(v14) = v14 - 32;
          }
          v16 = v17 - (unsigned __int16)v14;
          if ( v16 )
            goto LABEL_11;
        }
        v10 = (unsigned __int16)(v10 - 1);
        v9 = (unsigned __int16)(v9 - 1);
        if ( !v10 )
          break;
      }
    }
    v16 = v10 - v9;
LABEL_11:
    v4 = v20[0];
    v6 = -1;
  }
  else
  {
    v20[1] = v7 + 76;
    LOWORD(v20[0]) = *(_WORD *)(v7 + 72);
    HIWORD(v20[0]) = v20[0];
    v16 = RtlCompareUnicodeString(a2, (unsigned __int16 *)v20, 1);
  }
  (*(void (__fastcall **)(int, int *))(v4 + 8))(v4, v19);
  if ( !v16 )
    return 0;
  if ( v16 >= 0 )
    v6 = 1;
  return v6;
}
