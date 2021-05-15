// CcZeroDataOnDisk 
 
int __fastcall CcZeroDataOnDisk(int a1, _DWORD *a2, __int64 *a3)
{
  __int64 v3; // r4
  unsigned int v4; // r2
  __int64 v5; // kr00_8
  int result; // r0
  __int64 v7; // [sp+0h] [bp-20h] BYREF
  int v8[6]; // [sp+8h] [bp-18h] BYREF

  v3 = *a3;
  v4 = a2[1];
  v8[0] = *a2;
  v8[1] = a2[1];
  v5 = v3 - __PAIR64__(v4, *a2);
  v7 = v3 - __PAIR64__(v4, *a2);
  if ( v5 >= (unsigned int)CcMaxZeroTransferSize )
    return sub_527534(a1);
  result = ((int (__fastcall *)(int, int *, __int64 *, _DWORD))MmZeroPageWrite)(a1, v8, &v7, 0);
  if ( result < 0 )
    RtlRaiseStatus(result);
  return result;
}
