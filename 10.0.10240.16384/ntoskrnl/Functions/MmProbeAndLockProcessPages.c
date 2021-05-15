// MmProbeAndLockProcessPages 
 
unsigned int __fastcall MmProbeAndLockProcessPages(int a1, int a2)
{
  unsigned int result; // r0
  int v4; // [sp+0h] [bp-40h]
  _BYTE v5[56]; // [sp+8h] [bp-38h] BYREF

  v4 = 0;
  if ( a2 != *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) )
  {
    v4 = 1;
    KiStackAttachProcess(a2, 0, (int)v5);
  }
  result = MmProbeAndLockPages(a1);
  if ( v4 )
    result = KiUnstackDetachProcess((unsigned int)v5, 0);
  return result;
}
