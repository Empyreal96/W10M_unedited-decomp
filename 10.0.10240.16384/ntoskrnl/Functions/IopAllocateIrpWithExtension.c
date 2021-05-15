// IopAllocateIrpWithExtension 
 
int __fastcall IopAllocateIrpWithExtension(int a1, char a2, int a3)
{
  int result; // r0
  int v4; // r3

  result = IopAllocateIrpPrivate(0, a2 + 1, a3);
  if ( result )
  {
    --*(_BYTE *)(result + 35);
    --*(_BYTE *)(result + 34);
    v4 = *(_DWORD *)(result + 96) - 40;
    *(_DWORD *)(result + 96) = v4;
    *(_DWORD *)(result + 104) = v4;
    if ( (IopFunctionPointerMask & 4) != 0 )
      result = sub_50F318();
  }
  return result;
}
