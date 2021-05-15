// IopSymlinkSetFoExtension 
 
int __fastcall IopSymlinkSetFoExtension(int a1, unsigned int a2)
{
  int result; // r0
  int *v4[2]; // [sp+0h] [bp-8h] BYREF

  v4[0] = 0;
  if ( *(_DWORD *)(a1 + 124) )
  {
    IopGetFileObjectExtension(a1, 5, v4);
  }
  else
  {
    result = IopAllocateFileObjectExtension(a1, v4);
    if ( result < 0 )
      return result;
  }
  return IopSetTypeSpecificFoExtension((int)v4[0], 5u, a2);
}
