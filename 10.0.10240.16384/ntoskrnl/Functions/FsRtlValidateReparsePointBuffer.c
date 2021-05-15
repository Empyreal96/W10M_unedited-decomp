// FsRtlValidateReparsePointBuffer 
 
int __fastcall FsRtlValidateReparsePointBuffer(unsigned int a1, int a2)
{
  unsigned int v3; // r5
  int v4; // r2
  int v6; // r1
  int v7; // r1
  int v8; // r6
  int v9; // r5
  int v10; // r2
  int v11; // r0

  if ( a1 < 8 || a1 > 0x4000 )
    return -1073741192;
  v3 = *(unsigned __int16 *)(a2 + 4);
  v4 = *(_DWORD *)a2;
  if ( v3 + 8 != a1 )
    return sub_51F1D0();
  if ( v4 >= 0 || v3 + 24 == a1 && (v4 == -1610612733 || v4 == -1610612724) )
    return -1073741192;
  if ( (v4 & 0xFFF0000) == 0 )
  {
    if ( v4 == -1610612733 )
    {
      if ( v3 >= 8 && !*(_WORD *)(a2 + 8) )
      {
        v6 = *(unsigned __int16 *)(a2 + 10);
        if ( *(unsigned __int16 *)(a2 + 12) == v6 + 2 && v3 == *(unsigned __int16 *)(a2 + 14) + v6 + 12 )
          return 0;
      }
    }
    else
    {
      if ( v4 != -1610612724 )
        return 0;
      if ( v3 >= 0xC )
      {
        v7 = *(unsigned __int16 *)(a2 + 10);
        v8 = *(unsigned __int16 *)(a2 + 8);
        v9 = v3 + 8;
        if ( v9 >= v8 + v7 + 20 )
        {
          v10 = *(unsigned __int16 *)(a2 + 14);
          v11 = *(unsigned __int16 *)(a2 + 12);
          if ( v9 >= v11 + v10 + 20
            && *(_WORD *)(a2 + 10)
            && *(_WORD *)(a2 + 14)
            && v7 - 2 * (v7 >> 1) != 1
            && v10 - 2 * (v10 >> 1) != 1
            && v8 - 2 * (v8 >> 1) != 1
            && v11 - 2 * (v11 >> 1) != 1 )
          {
            return 0;
          }
        }
      }
    }
    return -1073741192;
  }
  return -1073741194;
}
