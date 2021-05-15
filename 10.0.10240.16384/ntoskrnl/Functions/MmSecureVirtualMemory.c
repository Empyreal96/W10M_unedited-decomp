// MmSecureVirtualMemory 
 
int __fastcall MmSecureVirtualMemory(unsigned int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r6
  int v8; // r0
  int v9; // r5
  int v10; // r3
  int v11; // r4
  int v13[6]; // [sp+8h] [bp-18h] BYREF

  v13[0] = a4;
  v4 = a1 + a2;
  if ( a1 + a2 <= MmHighestUserAddress && v4 > a1 )
  {
    v8 = MiObtainReferencedVad(a1 & 0xFFFFF000, v13);
    v9 = v8;
    if ( v8 )
    {
      v10 = *(_DWORD *)(v8 + 28) & 7;
      if ( v10 == 3 || v10 == 5 || (v4 - 1) >> 12 > *(_DWORD *)(v8 + 16) )
      {
        MiUnlockAndDereferenceVad(v8);
      }
      else
      {
        if ( a3 != 2 )
          a3 = 4;
        v11 = MiSecureVad(v8, a1, a2, a3, v13);
        MiUnlockAndDereferenceVad(v9);
        if ( v11 >= 0 )
          return v13[0];
      }
    }
  }
  return 0;
}
