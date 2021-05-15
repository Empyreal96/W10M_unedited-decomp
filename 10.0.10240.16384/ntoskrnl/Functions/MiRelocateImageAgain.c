// MiRelocateImageAgain 
 
int __fastcall MiRelocateImageAgain(int *a1, int a2)
{
  int *v2; // r8
  int v5; // r7
  int v6; // r9
  int v7; // r6
  int v8; // r4
  _DWORD *v10; // r0
  int v11; // r9
  int v12; // r4
  int v13; // r0
  int v14; // [sp+8h] [bp-40h] BYREF
  int v15; // [sp+Ch] [bp-3Ch]
  int v16; // [sp+10h] [bp-38h]
  int v17[12]; // [sp+18h] [bp-30h] BYREF

  v2 = (int *)a1[14];
  v5 = *v2;
  if ( !*v2 )
    return 0;
  v17[0] = 0;
  v17[1] = 0;
  v17[2] = 0;
  v17[3] = 0;
  v6 = *a1;
  v17[0] = -1;
  v7 = 0;
  v8 = 0;
  v16 = __mrc(15, 0, 13, 0, 3);
  MI_LOCK_RELOCATIONS_EXCLUSIVE(v16 & 0xFFFFFFC0, v5);
  if ( a1[13] < 0
    || (v15 = *(_DWORD *)(v6 + 24), (v7 = MiReservePtes(&dword_634D58, 1u)) == 0)
    || (v8 = MiSelectImageBase(v5, (_DWORD **)v6, a2, 0, (unsigned int *)&v14), v8 < 0) )
  {
LABEL_3:
    MI_UNLOCK_RELOCATIONS_EXCLUSIVE(v16 & 0xFFFFFFC0, v5);
    if ( v7 )
      MiReleasePtes(&dword_634D58, v7, 1u);
    MiReturnImageBase((int)v17);
    return v8;
  }
  a1[13] |= 0x80000000;
  MiGetControlAreaCfg((int)a1);
  v10 = *(_DWORD **)v6;
  v11 = v14;
  v12 = MiUpdateCfgSystemWideBitmap(v10, v14);
  if ( v12 >= 0 )
  {
    if ( v11 != v15 )
    {
      if ( (MiFlags & 0x100000) != 0 && (a1[13] & 0xC000000) != 0 )
        v12 = SeSetImageBaseAddress(v2[1] & 0xFFFFFFF8, v11);
      if ( v12 < 0 )
        return sub_802DAC();
      if ( a2 )
        v13 = -1;
      else
        v13 = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
      MiSwitchBaseAddress(a1, v11, v7, v13);
    }
    v8 = 0;
    goto LABEL_3;
  }
  return sub_802DAC();
}
