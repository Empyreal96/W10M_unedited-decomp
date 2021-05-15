// IopBootAllocation 
 
int __fastcall IopBootAllocation(int a1)
{
  int v1; // r7
  int v2; // r5
  int v3; // r4
  int v4; // r3
  int v5; // r0
  int v7[2]; // [sp+0h] [bp-30h] BYREF
  int v8[10]; // [sp+8h] [bp-28h] BYREF

  v7[1] = (int)v7;
  v7[0] = (int)v7;
  *(_DWORD *)(a1 + 12) = a1 + 24;
  v1 = 0;
  ((void (__fastcall *)(int, _DWORD, int *, int))IopAddRemoveReqDescs)(
    *(_DWORD *)(a1 + 24) + 20,
    *(_DWORD *)(*(_DWORD *)(a1 + 24) + 16),
    v7,
    1);
  v2 = v7[0];
  while ( (int *)v2 != v7 )
  {
    v3 = v2 - 44;
    v4 = *(unsigned __int8 *)(v2 + 9);
    v2 = *(_DWORD *)v2;
    if ( v4 )
    {
      v8[0] = v3 + 20;
      v5 = (*(int (__fastcall **)(_DWORD, int, int *))(*(_DWORD *)(v3 + 12) + 16))(
             *(_DWORD *)(*(_DWORD *)(v3 + 12) + 4),
             9,
             v8);
      if ( v5 < 0 )
        v1 = v5;
      *(_BYTE *)(v3 + 53) = 0;
      *(_BYTE *)(v3 + 52) = 0;
      *(_DWORD *)(v3 + 44) = v3 + 44;
      *(_DWORD *)(v3 + 48) = v3 + 44;
      *(_DWORD *)(v3 + 36) = v3 + 36;
      *(_DWORD *)(v3 + 40) = v3 + 36;
      *(_DWORD *)(v3 + 20) = v3 + 20;
      *(_DWORD *)(v3 + 24) = v3 + 20;
      *(_DWORD *)(v3 + 28) = v3 + 28;
      *(_DWORD *)(v3 + 32) = v3 + 28;
    }
  }
  return v1;
}
