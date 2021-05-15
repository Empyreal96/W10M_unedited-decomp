// KiEmulateLoadStoreDouble 
 
void __fastcall KiEmulateLoadStoreDouble(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  unsigned int v11; // r7
  void (*v16)(void); // r4
  int v17; // r0
  char *v18; // r6
  char *v19; // r0
  int v20; // r0
  int v21; // r0
  int v22; // r0
  int v23; // r0

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
  v19 = (char *)sub_4220E6 + 4 * (HIWORD(v11) & 0xF);
  if ( (v11 & 0x1000000) != 0 )
    v19 = v18;
  if ( (v11 & 0x100000) != 0 )
  {
    v23 = KiEmulatedLoadStoreStart(v19);
    KiEmulatedLoadStoreStart(v23 + 4);
    ((void (*)(void))((char *)sub_42216A + 4 * ((v11 >> 8) & 0xF)))();
    ((void (*)(void))((char *)sub_42216A + 4 * ((unsigned __int16)v11 >> 12)))();
  }
  else
  {
    v20 = ((int (__fastcall *)(char *))((char *)sub_4220E6 + 4 * ((unsigned __int16)v11 >> 12)))(v19);
    v21 = KiEmulateStoreWord(v20);
    v22 = ((int (__fastcall *)(int))((char *)sub_4220E6 + 4 * ((v11 >> 8) & 0xF)))(v21 + 4);
    KiEmulateStoreWord(v22);
  }
  if ( (v11 & 0x200000) != 0 )
  {
    ((void (*)(void))((char *)sub_4220E6 + 4 * (HIWORD(v11) & 0xF)))();
    ((void (*)(void))((char *)sub_42216A + 4 * (HIWORD(v11) & 0xF)))();
  }
  a5 += 4;
  __asm { RFEFD.W         SP }
}
