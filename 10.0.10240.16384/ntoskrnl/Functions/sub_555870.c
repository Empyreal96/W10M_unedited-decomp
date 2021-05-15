// sub_555870 
 
void sub_555870(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, ...)
{
  int v10; // r4
  int v11; // r7
  unsigned int v12; // r8
  int v13; // r1
  int v14; // r0
  unsigned int v15; // r9
  _DWORD *v16; // r5
  unsigned int v17; // r7
  int v18; // r0
  int v19; // [sp+Ch] [bp+Ch]
  unsigned int v20; // [sp+10h] [bp+10h]
  va_list va; // [sp+18h] [bp+18h] BYREF

  va_start(va, a10);
  v13 = ((v12 >> 10) & 0x3FFFFC) - 0x40000000;
  v14 = v11 << 10;
  v15 = v13 + (v11 << 12);
  v19 = v11 << 10;
  v20 = v13 + 4 * (((v12 & 0xFFF) + v10 + 4095) >> 12);
  v16 = (_DWORD *)v15;
  if ( v15 < v20 )
  {
    v17 = v15 + 1070596096;
    do
    {
      if ( !*v16 )
        break;
      if ( v17 + 3145728 > 0x3FFFFF )
      {
        *v16 = 0;
      }
      else
      {
        __dmb(0xBu);
        *v16 = 0;
        if ( v17 <= 0xFFF )
        {
          v18 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v18, (_DWORD *)(v18 + 4 * ((unsigned __int16)v16 & 0xFFF)), 0);
        }
      }
      ++v16;
      v17 += 4;
    }
    while ( (unsigned int)v16 < v20 );
    v13 = ((v12 >> 10) & 0x3FFFFC) - 0x40000000;
    v14 = v19;
  }
  if ( v16 != (_DWORD *)v15 )
    MiInsertTbFlushEntry((int)va, v15 << 10, ((int)v16 - v13 + -4 * v14) >> 2, 0);
  JUMPOUT(0x4F88B8);
}
