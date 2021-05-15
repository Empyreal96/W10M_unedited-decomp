// HvDuplicateCell 
 
int __fastcall HvDuplicateCell(int a1, int a2, int a3, int a4)
{
  int (__fastcall *v5)(int, int, int *); // r4
  int v6; // r6
  int v8; // r0
  int v9; // r8
  int v10; // r7
  int v11; // r9
  _BYTE *v12; // r4
  int v14; // [sp+8h] [bp-28h] BYREF
  int v15; // [sp+Ch] [bp-24h] BYREF
  _BYTE *v16; // [sp+10h] [bp-20h]

  v5 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
  v6 = -1;
  v14 = -1;
  v15 = -1;
  v8 = v5(a1, a2, &v14);
  v9 = v8;
  if ( v8 )
  {
    v10 = *(_DWORD *)(v8 - 4);
    v11 = HvAllocateCell(a1, -4 - v10);
    v12 = v16;
    if ( v11 != -1 )
    {
      if ( a4 == 1 )
        memmove((int)v16, v9, -4 - v10);
      else
        memset(v16, 0, -4 - v10);
    }
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v14);
    if ( v12 )
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v15);
    v6 = v11;
  }
  return v6;
}
