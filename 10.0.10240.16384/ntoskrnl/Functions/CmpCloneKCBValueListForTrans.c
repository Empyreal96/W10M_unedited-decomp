// CmpCloneKCBValueListForTrans 
 
int __fastcall CmpCloneKCBValueListForTrans(int *a1, int a2, _BYTE *a3, int a4)
{
  int v4; // r3
  int v8; // r0
  int v9; // r5
  int v11; // r0
  int v12; // r3
  int v13[8]; // [sp+0h] [bp-20h] BYREF

  v13[0] = (int)a3;
  v13[1] = a4;
  v4 = a1[38];
  v13[0] = -1;
  *a3 = 0;
  if ( !v4 )
  {
    v8 = (*(int (__fastcall **)(int, int, int *))(a1[5] + 4))(a1[5], a1[6], v13);
    v9 = v8;
    if ( !v8 )
      return 0;
    if ( *(_DWORD *)(v8 + 36) )
    {
      v11 = HvDuplicateCell(a1[5], *(_DWORD *)(v8 + 40), 1, 1);
      a1[37] = v11;
      if ( v11 == -1 )
      {
        (*(void (__fastcall **)(int, int *))(a1[5] + 8))(a1[5], v13);
        return 0;
      }
      a1[36] = *(_DWORD *)(v9 + 36);
    }
    else
    {
      a1[36] = 0;
      a1[37] = -1;
    }
    *a3 = 1;
    v12 = a1[5];
    a1[38] = a2;
    (*(void (__fastcall **)(int, int *))(v12 + 8))(v12, v13);
  }
  return 1;
}
