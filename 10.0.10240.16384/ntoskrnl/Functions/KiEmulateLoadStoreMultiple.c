// KiEmulateLoadStoreMultiple 
 
void __fastcall KiEmulateLoadStoreMultiple(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  unsigned int v11; // r7
  void (*v16)(void); // r4
  unsigned int v17; // r6
  int v18; // r0
  int v19; // r0
  unsigned int v20; // r5
  int v21; // r0
  int v22; // r0
  unsigned int v23; // r6
  int v24; // r0

  __asm
  {
    SRS.W           SP, #0x1B
    CPS.W           #0x1B
  }
  a11 = a1;
  v16 = (void (*)(void))((char *)sub_4220E6 + 4 * (HIWORD(v11) & 0xF));
  v16();
  if ( (v11 & 0x1000000) != 0 )
  {
    v17 = (unsigned __int16)v11;
    v18 = 0;
    do
    {
      _CF = v17 & 1;
      v17 >>= 1;
      v18 += _CF;
    }
    while ( v17 );
    v16 = (void (*)(void))((char *)v16 - 4 * v18);
  }
  v19 = (int)v16;
  v20 = 0;
  if ( (v11 & 0x100000) != 0 )
  {
    do
    {
      if ( ((v11 >> v20) & 1) != 0 )
      {
        v22 = KiEmulatedLoadStoreStart(v19);
        v19 = ((int (__fastcall *)(int))((char *)sub_42216A + 4 * v20))(v22 + 4);
      }
      ++v20;
    }
    while ( v20 < 0x10 );
  }
  else
  {
    do
    {
      if ( ((v11 >> v20) & 1) != 0 )
      {
        v21 = ((int (__fastcall *)(int))((char *)sub_4220E6 + 4 * v20))(v19);
        v19 = KiEmulateStoreWord(v21) + 4;
      }
      ++v20;
    }
    while ( v20 < 0x10 );
  }
  if ( (v11 & 0x200000) != 0 )
  {
    if ( (v11 & 0x1000000) != 0 )
    {
      v23 = (unsigned __int16)v11;
      v24 = 0;
      do
      {
        _CF = v23 & 1;
        v23 >>= 1;
        v24 += _CF;
      }
      while ( v23 );
    }
    ((void (*)(void))((char *)sub_42216A + 4 * (HIWORD(v11) & 0xF)))();
  }
  if ( (v11 & 0x80000000) != 0 )
  {
    a5 += 4;
    __asm { RFEFD.W         SP }
  }
  a5 += 2;
  __asm { RFEFD.W         SP }
}
