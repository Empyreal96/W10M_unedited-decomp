// sub_96AE34 
 
void sub_96AE34()
{
  unsigned int v0; // r4
  unsigned int v1; // r5
  unsigned int v2; // r7
  unsigned int v3; // r8
  int v4; // r9
  int v5; // r10
  int v6; // r0

  if ( (v1 & 2) != 0 )
  {
    if ( v3 <= 1 )
    {
      if ( (v1 & 0x400) != 0 )
      {
        if ( v0 + v4 + 3145728 <= 0x3FFFFF )
        {
LABEL_7:
          __dmb(0xBu);
          *(_DWORD *)v0 = v5;
          if ( v0 + v4 <= v2 )
          {
            v6 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v6, (_DWORD *)(v6 + 4 * (v0 & 0xFFF)), 0);
          }
LABEL_13:
          JUMPOUT(0x95621A);
        }
LABEL_12:
        *(_DWORD *)v0 = v5;
        goto LABEL_13;
      }
    }
    else
    {
      MxZeroBootMappings(v0 << 10, (v0 << 10) + 4096);
    }
    MiFreeBootPageTable(v1 >> 12);
  }
  if ( v0 >= 0xC0000000 && v0 <= 0xC03FFFFF )
    goto LABEL_7;
  goto LABEL_12;
}
