// CmpGetBootValueData 
 
int __fastcall CmpGetBootValueData(int a1, int a2, int a3, unsigned int a4)
{
  unsigned int v5; // r3
  int v9; // r0
  int v10[11]; // [sp+Ch] [bp-2Ch] BYREF

  v5 = *(_DWORD *)(a2 + 4);
  v10[0] = -1;
  if ( v5 >= 0x80000000 )
  {
    memmove(a3, a2 + 8, a4);
    return 1;
  }
  if ( (unsigned int)dword_98240C < 4 || v5 - 16345 > 0x7FFFC026 )
  {
    v9 = off_98237C(&CmControlHive, *(_DWORD *)(a2 + 8), v10);
    if ( !v9 )
      return 0;
    memmove(a3, v9, a4);
    off_982380(&CmControlHive, v10);
    return 1;
  }
  return sub_9683E8();
}
