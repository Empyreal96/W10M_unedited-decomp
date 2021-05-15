// ExpSvmServicePageFault 
 
int __fastcall ExpSvmServicePageFault(char a1, unsigned int a2, int a3)
{
  int v6; // r5
  int v7; // r4
  int v8; // r6
  int v9; // r0
  int v10; // r4
  _BYTE v12[16]; // [sp-4h] [bp-40h] BYREF
  char v13[48]; // [sp+Ch] [bp-30h] BYREF

  v6 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_619EF0, (unsigned int)v12);
  v7 = *(_DWORD *)(dword_619EEC + 8 * a3);
  KeReleaseInStackQueuedSpinLock((int)v12);
  v8 = 0;
  if ( v6 != v7 )
  {
    KiStackAttachProcess(v7, 0, (int)v13);
    v8 = 1;
  }
  v9 = 0;
  if ( (a1 & 8) != 0 )
  {
    v10 = -1073741819;
  }
  else
  {
    if ( (a1 & 2) != 0 )
      v9 = 1;
    if ( (a1 & 4) != 0 )
      v9 |= 8u;
    v10 = MmAccessFault(v9, a2, 1, 0);
  }
  if ( v8 )
    KiUnstackDetachProcess((unsigned int)v13, 0);
  return v10;
}
