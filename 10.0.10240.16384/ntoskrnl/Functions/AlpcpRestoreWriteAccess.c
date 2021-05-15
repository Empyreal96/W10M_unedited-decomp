// AlpcpRestoreWriteAccess 
 
unsigned int __fastcall AlpcpRestoreWriteAccess(_DWORD *a1)
{
  int v2; // r6
  int v3; // r0
  int v4; // r5
  unsigned int result; // r0
  int v6; // r3
  _BYTE v7[40]; // [sp-4h] [bp-28h] BYREF

  v2 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v3 = a1[4];
  v4 = a1[2];
  if ( v3 != v2 )
    KiStackAttachProcess(v3, 0, (int)v7);
  result = MmUnsecureVirtualMemory(a1[8]);
  if ( a1[4] != v2 )
    result = KiUnstackDetachProcess((unsigned int)v7, 0);
  v6 = a1[9];
  a1[8] = 0;
  a1[9] = v6 | 1;
  *(_DWORD *)(v4 + 40) = 0;
  *(_DWORD *)(v4 + 44) = a1;
  return result;
}
