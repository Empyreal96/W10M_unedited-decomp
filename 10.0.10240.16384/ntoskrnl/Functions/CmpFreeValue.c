// CmpFreeValue 
 
int __fastcall CmpFreeValue(int a1, unsigned int a2, int a3, int a4)
{
  int v6; // r0
  int v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[1] = a4;
  v8[0] = -1;
  v6 = (*(int (__fastcall **)(int, unsigned int, int *))(a1 + 4))(a1, a2, v8);
  if ( !v6 )
    JUMPOUT(0x805E74);
  if ( !CmpFreeValueData(a1, *(_DWORD *)(v6 + 8), *(_DWORD *)(v6 + 4)) )
    return sub_805E70(a1);
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v8);
  HvFreeCell(a1, a2);
  return 1;
}
