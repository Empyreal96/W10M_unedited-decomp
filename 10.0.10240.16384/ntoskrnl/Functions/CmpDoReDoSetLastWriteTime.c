// CmpDoReDoSetLastWriteTime 
 
int __fastcall CmpDoReDoSetLastWriteTime(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v7[2]; // [sp+0h] [bp-18h] BYREF
  int v8; // [sp+8h] [bp-10h]
  int v9; // [sp+Ch] [bp-Ch]

  v7[0] = a1;
  v7[1] = a2;
  v8 = a3;
  v9 = a4;
  v5 = CmpDoReOpenTransKey(a1, a2 + 32, 2, v7);
  if ( v5 >= 0 )
  {
    v8 = *(_DWORD *)(a2 + 40);
    v9 = *(_DWORD *)(a2 + 44);
    v5 = ZwSetInformationKey();
    ZwClose();
  }
  return v5;
}
