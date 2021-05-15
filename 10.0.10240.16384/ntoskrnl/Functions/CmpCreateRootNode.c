// CmpCreateRootNode 
 
int __fastcall CmpCreateRootNode(int a1, int a2, int *a3)
{
  unsigned int v5; // r0
  int v6; // r0
  int v7; // r4
  unsigned int v8; // r0
  unsigned int v9; // r3
  int v11; // [sp+8h] [bp-28h] BYREF
  int v12[2]; // [sp+10h] [bp-20h] BYREF
  unsigned __int16 v13[12]; // [sp+18h] [bp-18h] BYREF

  v11 = -1;
  RtlInitUnicodeString((unsigned int)v13, L"REGISTRY");
  v5 = CmpNameSize(v13);
  v6 = HvAllocateCell(a1, v5 + 76);
  *a3 = v6;
  if ( v6 == -1 )
    return 0;
  v7 = v12[0];
  *(_DWORD *)(*(_DWORD *)(a1 + 32) + 36) = v6;
  *(_WORD *)v7 = 27502;
  *(_WORD *)(v7 + 2) = 12;
  KeQuerySystemTime(v12);
  *(_DWORD *)(v7 + 4) = v12[0];
  *(_DWORD *)(v7 + 8) = v12[1];
  *(_DWORD *)(v7 + 16) = -1;
  *(_DWORD *)(v7 + 20) = 0;
  *(_DWORD *)(v7 + 24) = 0;
  *(_DWORD *)(v7 + 28) = -1;
  *(_DWORD *)(v7 + 32) = -1;
  *(_DWORD *)(v7 + 36) = 0;
  *(_DWORD *)(v7 + 40) = -1;
  *(_DWORD *)(v7 + 44) = -1;
  *(_DWORD *)(v7 + 48) = -1;
  *(_WORD *)(v7 + 74) = 0;
  *(_DWORD *)(v7 + 64) = 0;
  *(_WORD *)(v7 + 52) = 0;
  *(_DWORD *)(v7 + 52) &= 0xFF00FFFF;
  *(_BYTE *)(v7 + 55) = 0;
  *(_DWORD *)(v7 + 56) = 0;
  *(_DWORD *)(v7 + 60) = 0;
  v8 = CmpCopyName(v7 + 76, v13);
  v9 = v13[0];
  *(_WORD *)(v7 + 72) = v8;
  if ( v8 < v9 )
    *(_WORD *)(v7 + 2) |= 0x20u;
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v11);
  return 1;
}
