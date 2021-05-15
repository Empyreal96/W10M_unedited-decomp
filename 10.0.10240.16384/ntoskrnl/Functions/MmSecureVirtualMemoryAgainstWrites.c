// MmSecureVirtualMemoryAgainstWrites 
 
int __fastcall MmSecureVirtualMemoryAgainstWrites(int a1, int a2, int a3)
{
  unsigned int v3; // r5
  unsigned int v7; // r9
  int v8; // r6
  int v9; // r0
  int v10; // r4
  int v11; // r2
  int v12; // r2
  int v13; // r7
  int v14; // r3
  int v15; // [sp+8h] [bp-48h]
  int v17; // [sp+10h] [bp-40h] BYREF
  char v18[56]; // [sp+18h] [bp-38h] BYREF

  v3 = a2 & 0xFFFFF000;
  if ( (a2 & 0xFFFFF000) != a2 || (a3 & 0xFFF) != 0 )
    return sub_7F6424();
  v7 = (a3 + a2 - 1) | 0xFFF;
  v8 = 0;
  v15 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( v15 == a1 )
    v15 = 0;
  else
    KiStackAttachProcess(a1, 0, (int)v18);
  v9 = MiObtainReferencedVad(v3, &v17);
  v10 = v9;
  if ( v9 )
  {
    if ( v7 >> 12 <= *(_DWORD *)(v9 + 16) )
    {
      v11 = *(_DWORD *)(v9 + 28);
      if ( ((1 << (v11 & 7)) & 0x55) != 0 && ((v11 & 0x4000) == 0 || MiCheckSecuredVad(v9, a2, a3, 1) >= 0) )
      {
        v12 = *(_DWORD *)(v10 + 28);
        if ( (v12 & 0x8000) == 0 && (*(_DWORD *)(v10 + 40) & 0x4000000) == 0 )
        {
          v13 = **(_DWORD **)(v10 + 44);
          if ( (*(_DWORD *)(v13 + 28) & 0x20) != 0 || MiIsPteProtectionCompatible((unsigned __int8)v12 >> 3, 2) )
          {
            if ( (v14 = *(_DWORD *)(v13 + 28), (v14 & 0x80) != 0) && (v14 & 0x20) == 0
              || !MiVadMapsLargeImage(v10) && MiIsRangeFullyCommitted(v10, v3, v7) )
            {
              if ( MiSetReadOnlyOnSectionView(a1, v10, v3, v7) >= 0 )
              {
                v8 = MiAddSecureEntry(v10, v3, v7, -1073741823, 0);
                if ( !v8 )
                  MiUnsecureVirtualMemoryAgainstWrites((_DWORD *)v10, v3, v7);
              }
            }
          }
        }
      }
    }
    MiUnlockAndDereferenceVad(v10);
  }
  if ( v15 )
    KiUnstackDetachProcess((unsigned int)v18, 0);
  return v8;
}
