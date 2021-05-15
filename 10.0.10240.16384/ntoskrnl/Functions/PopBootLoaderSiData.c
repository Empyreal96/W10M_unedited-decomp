// PopBootLoaderSiData 
 
_DWORD *__fastcall PopBootLoaderSiData(int a1, int a2)
{
  int v2; // r5
  _DWORD *result; // r0
  _DWORD v5[12]; // [sp+0h] [bp-30h] BYREF

  v2 = *(_DWORD *)(a1 + 16);
  result = (_DWORD *)memmove((int)v5, v2, 0x28u);
  if ( v5[7] == 1 )
  {
    if ( a2 )
      result = BapdRegisterSiData((_DWORD *)(v2 + a2), v5[4] - a2, 1);
  }
  return result;
}
