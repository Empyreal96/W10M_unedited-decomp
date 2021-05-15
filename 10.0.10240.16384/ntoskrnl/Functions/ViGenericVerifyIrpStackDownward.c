// ViGenericVerifyIrpStackDownward 
 
int __fastcall ViGenericVerifyIrpStackDownward(int *a1, int a2, int a3, unsigned __int8 *a4, _DWORD *a5, int a6, int a7)
{
  int v7; // r7
  int v9; // r5
  BOOL v10; // r8
  BOOL v11; // r10
  int v12; // r3
  int v13; // r9
  int result; // r0
  int v15; // r2
  int v16; // r3
  int v17; // r0
  int v19; // [sp+4h] [bp-2Ch]
  int v21; // [sp+Ch] [bp-24h]

  v9 = *a1;
  v21 = *(_DWORD *)(*a1 + 24);
  v10 = v21 != a5[16];
  v11 = *(_DWORD *)(*a1 + 28) != a5[17];
  v12 = a5[1];
  v13 = a1[35];
  if ( (v12 & 0x8000000) != 0 )
    v7 = 1;
  if ( (v12 & 0x8000000) == 0 )
    v7 = 0;
  result = VfMajorIsNewRequest(a3, a4);
  v15 = result;
  v19 = result;
  if ( (*a4 < 3u || *a4 > 4u && (*a4 <= 0xDu || *a4 > 0xFu && *a4 != 22))
    && *(_DWORD *)(v13 + 28) == 2
    && *((unsigned __int8 *)a1 + 40) >= 2u )
  {
    if ( (a1[9] & 0x2000000) == 0 )
    {
      result = VfErrorReport11(769, a7, v9);
      a1[9] |= 0x2000000u;
    }
    v15 = v19;
  }
  if ( a3 )
  {
    if ( (a1[9] & 0x20) != 0 )
    {
      v16 = a5[1];
      if ( (v16 & 0x1000000) == 0 )
      {
        if ( v15 && !v7 )
        {
          a5[1] = v16 | 0x1000000;
          VfErrorReport1(530, a7, v9);
        }
        if ( v10 )
        {
          a5[1] |= 0x1000000u;
          if ( a4[1] == 255 )
            v17 = 571;
          else
            v17 = 531;
          VfErrorReport1(v17, a7, v9);
        }
        if ( v11 )
        {
          a5[1] |= 0x1000000u;
          VfErrorReport1(532, a7, v9);
        }
      }
    }
    result = VfMajorIsValidIrpStatus(a4, v21);
    if ( !result )
      result = VfErrorReport6(768, a7, v9, v21);
  }
  return result;
}
