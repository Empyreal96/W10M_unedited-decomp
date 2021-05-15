// MmStoreAllocateVirtualMemory 
 
unsigned int __fastcall MmStoreAllocateVirtualMemory(int a1, int a2)
{
  int v2; // r7
  unsigned int v3; // r5
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r6
  char v8[4]; // [sp+18h] [bp-38h] BYREF
  unsigned int v9; // [sp+1Ch] [bp-34h] BYREF
  int v10; // [sp+20h] [bp-30h] BYREF
  _DWORD var28[11]; // [sp+28h] [bp-28h] BYREF
  int vars8[2]; // [sp+58h] [bp+8h] BYREF

  vars8[0] = a1;
  vars8[1] = a2;
  var28[0] = 0;
  var28[1] = 0;
  var28[2] = 0;
  var28[3] = 0;
  v2 = __mrc(15, 0, 13, 0, 3);
  v9 = 0;
  v10 = 0;
  v3 = 0;
  v4 = MiAllocateVirtualMemory(-1, &v9, 0, vars8, 12288, 4u, 0, 1, &v10);
  v5 = v10;
  if ( v4 >= 0 )
  {
    v6 = (*(_DWORD *)(v10 + 16) << 12) | 0xFFF;
    if ( MiAddSecureEntry(v10, v9, v6, -2147483647, 1) )
    {
      MiDecommitPages(v9, ((v6 >> 10) & 0x3FFFFC) - 0x40000000, *(_DWORD *)((v2 & 0xFFFFFFC0) + 0x74), v5, 1, var28);
      if ( MiLockPageTableRange(v9, v6) >= 0 )
      {
        MiUnlockAndDereferenceVad(v5);
        v3 = v9;
        v5 = 0;
      }
    }
  }
  if ( v5 )
  {
    v8[0] = 0;
    __mrc(15, 0, 13, 0, 3);
    MiFreeVadRange(v5, (int)v8, *(_DWORD *)(v5 + 12), *(_DWORD *)(v5 + 16));
  }
  return v3;
}
