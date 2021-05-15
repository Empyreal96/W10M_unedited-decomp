// IoSetFileObjectIgnoreSharing 
 
int __fastcall IoSetFileObjectIgnoreSharing(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5[2]; // [sp+0h] [bp-8h] BYREF

  v5[0] = a3;
  v5[1] = a4;
  result = IopAllocateFileObjectExtension(a1, v5);
  if ( result >= 0 )
  {
    result = 0;
    *(_DWORD *)v5[0] |= 1u;
  }
  return result;
}
