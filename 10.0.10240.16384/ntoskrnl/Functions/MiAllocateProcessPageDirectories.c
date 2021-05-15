// MiAllocateProcessPageDirectories 
 
int __fastcall MiAllocateProcessPageDirectories(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r2
  int v6; // r3
  _DWORD *v7; // r4
  int v8; // r2
  int v9; // r3
  int v11[4]; // [sp+0h] [bp-10h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  do
  {
    v7 = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)&MiArmPageDirectorySlist);
    if ( v7 )
    {
      MmGetPhysicalAddress((int)v11, (int)v7, v5, v6);
      v8 = KiTbrConfiguration;
      v9 = v11[0];
      a1[8] = v7;
      a1[7] = v9 | v8;
      a1[9] = 255;
      KeZeroPages(v7, 0x4000u);
      return 1;
    }
  }
  while ( MiAllocateHardwarePageDirectories() == 1 );
  return 0;
}
