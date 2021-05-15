// WmipInsertMofResource 
 
int __fastcall WmipInsertMofResource(int a1, int a2, int a3, unsigned int a4)
{
  int v5; // r5
  int *v7; // r1
  _DWORD *v8; // r1
  int v9; // r3
  int v10; // t1
  int result; // r0
  BOOL v12; // r8
  int *v13; // r0
  int *v14; // r7
  int v15; // [sp+0h] [bp-20h] BYREF
  unsigned int v16[7]; // [sp+4h] [bp-1Ch] BYREF

  v15 = a3;
  v16[0] = a4;
  v5 = *(_DWORD *)(a1 + 36);
  if ( v5 )
  {
    v7 = *(int **)(a1 + 40);
    v10 = *v7;
    v8 = v7 + 1;
    v9 = v10;
    if ( v10 == a2 )
      return 0;
    if ( v9 )
      return sub_80C4F4(a1, v8, 0);
    **(_DWORD **)(a1 + 40) = a2;
  }
  if ( v5 )
  {
LABEL_7:
    WmipReferenceEntry(a2);
    return 0;
  }
  v12 = *(_DWORD *)(a1 + 40) != a1 + 44;
  RtlULongLongToULong(0, 0, v16);
  result = RtlULongLongToULong(16, 0, &v15);
  if ( result >= 0 )
  {
    v13 = (int *)ExAllocatePoolWithTag(1, v15, 1885957463);
    v14 = v13;
    if ( !v13 )
      return -1073741670;
    memset(v13, 0, v15);
    memmove((int)v14, *(_DWORD *)(a1 + 40), v16[0]);
    if ( v12 )
      ExFreePoolWithTag(*(_DWORD *)(a1 + 40));
    *(_DWORD *)(a1 + 40) = v14;
    *v14 = a2;
    *(_DWORD *)(a1 + 36) = 4;
    goto LABEL_7;
  }
  return result;
}
