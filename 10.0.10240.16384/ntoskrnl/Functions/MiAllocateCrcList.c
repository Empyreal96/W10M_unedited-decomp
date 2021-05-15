// MiAllocateCrcList 
 
int __fastcall MiAllocateCrcList(int *a1, int *a2)
{
  _DWORD *v3; // r5
  unsigned int v4; // r6
  int v5; // r4
  unsigned int v6; // r0
  unsigned int v7; // r3
  unsigned int v8; // r4
  unsigned int v9; // r3
  unsigned int v10; // r2
  unsigned int v11; // r3
  unsigned int v12; // r0
  unsigned int v13; // r4
  int result; // r0

  v3 = (_DWORD *)*a1;
  v4 = (2863311531u * (unsigned __int64)(unsigned int)*a2) >> 32;
  v5 = *(_DWORD *)(*a1 + 3072);
  v6 = MiGetPrivatePageCount(*a1, (int)a2, *a2, -1431655765 * *a2);
  v7 = v6 + v5;
  if ( v6 + v5 < v6 )
    v7 = -1;
  if ( v7 > v4 >> 4 )
    v7 = v4 >> 4;
  v8 = ((24 * v7 + 4095) & 0xFFFFF000) >> 12;
  if ( v3[960] - 1024 <= 0 )
    return 0;
  if ( v8 > v3[960] - 1024 )
    v8 = v3[960] - 1024;
  v9 = v3[1029];
  v10 = v3[961];
  if ( v10 >= v9 )
    return 0;
  v11 = v9 - v10;
  if ( v8 > v11 )
    v8 = v11;
  v12 = MiGetAvailablePagesBelowPriority(v3, 2);
  if ( v8 > v12 )
    v8 = v12;
  v13 = v8 << 12;
  if ( v13 < 0x400000 )
    v13 = 0x400000;
  result = ExAllocatePoolWithTag(512, v13, 1836405581);
  if ( !result )
    return sub_80FDCC();
  *a2 = v13;
  return result;
}
