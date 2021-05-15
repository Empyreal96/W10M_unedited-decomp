// KiEmulateLoadStoreVfp 
 
void __fastcall KiEmulateLoadStoreVfp(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  unsigned int v11; // r7
  void (*v16)(void); // r4
  int v17; // r0
  char *v18; // r0
  int v19; // r5
  int v20; // r4
  int v21; // r0
  int v22; // r0
  int v23; // r0
  int v24; // r0

  __asm
  {
    SRS.W           SP, #0x1B
    CPS.W           #0x1B
  }
  a11 = a1;
  v16 = (void (*)(void))((char *)sub_4220E6 + 4 * (HIWORD(v11) & 0xF));
  v16();
  v17 = (unsigned __int8)v11;
  if ( (v11 & 0x800000) == 0 )
    v17 = -(unsigned __int8)v11;
  v18 = (char *)v16 + 4 * v17;
  v19 = (unsigned __int16)v11 >> 12;
  v20 = (v11 >> 22) & 1;
  if ( (v11 & 0x100000) != 0 )
  {
    if ( (v11 & 0x100) != 0 )
    {
      v24 = KiEmulatedLoadStoreStart(v18);
      KiEmulatedLoadStoreStart(v24 + 4);
      ((int (*)())((char *)sub_42240C + 4 * (v19 | (16 * v20)) + 2 * (v19 | (16 * v20))))();
    }
    else
    {
      KiEmulatedLoadStoreStart(v18);
      ((int (*)())((char *)sub_42234C + 4 * (v20 | (2 * v19)) + 2 * (v20 | (2 * v19))))();
    }
  }
  else if ( (v11 & 0x100) != 0 )
  {
    v22 = ((int (__fastcall *)(char *))((char *)sub_42228C + 4 * (v19 | (16 * v20)) + 2 * (v19 | (16 * v20))))(v18);
    v23 = KiEmulateStoreWord(v22);
    KiEmulateStoreWord(v23 + 4);
  }
  else
  {
    v21 = ((int (__fastcall *)(char *))((char *)sub_4221CC + 4 * (v20 | (2 * v19)) + 2 * (v20 | (2 * v19))))(v18);
    KiEmulateStoreWord(v21);
  }
  a5 += 4;
  __asm { RFEFD.W         SP }
}
