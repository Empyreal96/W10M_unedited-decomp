// VfAvlReserveNode 
 
_DWORD *__fastcall VfAvlReserveNode(int *a1, int a2, int a3)
{
  int v5; // r1
  _DWORD *result; // r0
  int v8; // r0

  v5 = a1[4];
  if ( v5 == 1 )
    return (_DWORD *)sub_518C10();
  v8 = ExAllocatePoolWithTag(512, v5, 1413572182);
  if ( !v8 )
    return 0;
  result = (_DWORD *)(v8 + 16);
  *result = a2;
  if ( !a3 )
    a3 = *a1;
  result[1] = a3;
  return result;
}
