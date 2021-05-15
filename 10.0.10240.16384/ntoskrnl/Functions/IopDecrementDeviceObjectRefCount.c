// IopDecrementDeviceObjectRefCount 
 
int __fastcall IopDecrementDeviceObjectRefCount(int a1, int a2)
{
  int result; // r0
  int v4; // r0

  if ( a2 )
    return sub_554854();
  result = *(_DWORD *)(a1 + 4) - 1;
  *(_DWORD *)(a1 + 4) = result;
  if ( result < 0 )
  {
    v4 = *(_DWORD *)(a1 + 8);
    if ( v4 )
    {
      IoAddTriageDumpDataBlock(v4, 168);
      IoAddTriageDumpDataBlock(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 32), *(unsigned __int16 *)(*(_DWORD *)(a1 + 8) + 28));
    }
    KeBugCheckEx(24, 0, a1);
  }
  return result;
}
