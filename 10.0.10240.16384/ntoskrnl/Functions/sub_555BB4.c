// sub_555BB4 
 
void __fastcall sub_555BB4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, char a10)
{
  char *v10; // r2
  int v11; // r0
  unsigned int v12; // r1
  char v13; // r3

  KiExternalCacheGlobalSyncRequired = a10;
  KiExternalCacheDescriptor = a7;
  unk_6810D8 = a8;
  unk_6810DC = a9;
  v10 = KiExternalCacheQuiesceDpc;
  v11 = KiExternalCacheQuiesceHighImportanceEnable;
  v12 = 0;
  while ( 1 )
  {
    *v10 = 19;
    v10[1] = 1;
    *((_DWORD *)v10 + 3) = KiExternalCacheFlushQuiesce;
    *((_DWORD *)v10 + 4) = 0;
    *((_WORD *)v10 + 1) = v12 + 32;
    *((_DWORD *)v10 + 7) = 0;
    *((_DWORD *)v10 + 2) = 0;
    if ( v11 )
      v13 = 2;
    else
      v13 = 3;
    v10[1] = v13;
    ++v12;
    v10 += 32;
    if ( v12 >= 0x20 )
    {
      KiExternalCachePresent = 1;
      MEMORY[0xFFFF928E] = 1;
      KiExternalCacheAddDescriptor();
      JUMPOUT(0x4F8DE2);
    }
  }
}
