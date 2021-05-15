// VfAvlLookupTreeNode 
 
int __fastcall VfAvlLookupTreeNode(int *a1, int a2, int a3, int a4)
{
  int v4; // r7
  int v5; // r4
  unsigned int v8; // r5
  unsigned int v9; // r10
  int v10; // r3
  unsigned int i; // r7
  unsigned int v13; // r8
  int v14; // r5
  char v15; // r0
  char v16; // r3
  unsigned int v17; // [sp+0h] [bp-38h]
  int v18; // [sp+4h] [bp-34h] BYREF
  int v19; // [sp+8h] [bp-30h] BYREF
  _DWORD v20[10]; // [sp+10h] [bp-28h] BYREF

  v4 = a4;
  v5 = 0;
  if ( !a4 )
    v4 = *a1;
  v8 = a3 & 0xFFFFF000;
  v9 = ((a3 & 0xFFFu) + v4 + 4095) >> 12;
  v10 = 4096;
  if ( (a3 & 0xFFFFF000) != a3 )
    return sub_51933C();
  v17 = 0;
  for ( i = v4 + a3; v17 < v9; ++v17 )
  {
    v13 = v8 + 4096;
    if ( v8 + 4096 > i )
      v10 = i - v8;
    v20[0] = v8;
    v20[1] = v10;
    v14 = ViAvlTableIndex((int)a1);
    if ( (*(_BYTE *)(a2 + 5) & 1) == 0 )
    {
      v15 = KfRaiseIrql(2);
      v16 = *(_BYTE *)(a2 + 5);
      *(_BYTE *)(a2 + 4) = v15;
      *(_BYTE *)(a2 + 5) = v16 | 1;
    }
    ViAvlAcquireTableLockAtDpcLevelSafe(a1[2] + (v14 << 8), a2);
    v5 = RtlLookupElementGenericTableFullAvl(a1[2] + (v14 << 8), (int)v20, &v18, &v19);
    if ( v5 )
      break;
    ViAvlReleaseTableLockFromDpcLevel((unsigned int *)(a1[2] + (v14 << 8)), a2);
    v8 = v13;
    v10 = 4096;
  }
  return v5;
}
