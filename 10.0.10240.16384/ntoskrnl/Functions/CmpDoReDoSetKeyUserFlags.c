// CmpDoReDoSetKeyUserFlags 
 
int __fastcall CmpDoReDoSetKeyUserFlags(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v7; // [sp+0h] [bp-10h] BYREF
  int v8; // [sp+4h] [bp-Ch]

  v7 = a3;
  v8 = a4;
  v5 = CmpDoReOpenTransKey(a1, a2 + 32, 2, &v7);
  if ( v5 >= 0 )
  {
    v8 = *(_DWORD *)(a2 + 40);
    v5 = ZwSetInformationKey();
    ZwClose();
  }
  return v5;
}
