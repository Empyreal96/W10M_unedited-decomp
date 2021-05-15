// IoSetIoPriorityHintIntoFileObject 
 
int __fastcall IoSetIoPriorityHintIntoFileObject(int a1, unsigned int a2, int a3, int a4)
{
  int result; // r0
  int v6; // [sp+0h] [bp-8h] BYREF

  v6 = a4;
  if ( a2 >= 5 )
    return -1073741811;
  result = IopAllocateFileObjectExtension(a1, &v6);
  if ( result >= 0 )
    *(_DWORD *)(v6 + 32) = a2 + 1;
  return result;
}
