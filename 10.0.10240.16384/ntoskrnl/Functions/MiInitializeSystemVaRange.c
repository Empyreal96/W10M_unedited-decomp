// MiInitializeSystemVaRange 
 
int __fastcall MiInitializeSystemVaRange(unsigned int a1, int a2, int a3)
{
  int v4; // r7
  char *v5; // r6
  unsigned int v6; // r7
  char v8[40]; // [sp+8h] [bp-28h] BYREF

  if ( a1 < dword_63389C )
    sub_50B500();
  v4 = a2 - a1;
  v5 = &byte_63505C[(int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2];
  KeAcquireInStackQueuedSpinLock(&dword_6342BC, v8);
  if ( v4 )
  {
    v6 = ((unsigned int)(v4 - 1) >> 22) + 1;
    do
    {
      if ( *v5 )
      {
        --MiState[(unsigned __int8)*v5 + 2408];
      }
      else
      {
        dword_635310 -= 0x400000;
        if ( v5 >= &byte_63505C[(int)(3072 - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2] )
          dword_633890 -= 0x400000;
      }
      *v5++ = a3;
      ++MiState[a3 + 2408];
      --v6;
    }
    while ( v6 );
  }
  if ( dword_635310 < (unsigned int)dword_633888 )
    dword_633888 = dword_635310;
  return KeReleaseInStackQueuedSpinLock(v8);
}
