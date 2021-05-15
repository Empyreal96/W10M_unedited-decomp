// CmpCopyCell 
 
int __fastcall CmpCopyCell(int a1, int a2, int a3)
{
  int (__fastcall *v4)(int, int, _DWORD *); // r4
  int v5; // r7
  int v7; // r0
  int v8; // r8
  int v9; // r9
  int v11; // [sp+Ch] [bp-24h]
  _DWORD v12[8]; // [sp+10h] [bp-20h] BYREF

  v4 = *(int (__fastcall **)(int, int, _DWORD *))(a1 + 4);
  v11 = -1;
  v12[0] = -1;
  v5 = -1;
  v7 = v4(a1, a2, v12);
  v8 = v7;
  if ( v7 )
  {
    v9 = *(_DWORD *)(v7 - 4);
    v5 = HvAllocateCell(a3, -4 - v9);
    if ( v5 != -1 )
      memmove(0, v8, -4 - v9);
    (*(void (__fastcall **)(int, _DWORD *))(a1 + 8))(a1, v12);
  }
  return v5;
}
