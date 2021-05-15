// MiInitializeBootLoadedDriverPfns 
 
int __fastcall MiInitializeBootLoadedDriverPfns(int result)
{
  _DWORD *v1; // r6
  unsigned int v2; // r1
  unsigned int v3; // r2
  unsigned int v4; // r0
  int v5; // r3

  v1 = *(_DWORD **)(result + 16);
  if ( v1 == (_DWORD *)(result + 16) )
  {
LABEL_10:
    MiFlags |= 0x1000u;
  }
  else
  {
    v2 = 4095;
    while ( 1 )
    {
      v3 = v1[6];
      if ( (*(_DWORD *)((((((v3 >> 10) & 0x3FFFFC) - 0x40000000) >> 10) & 0x3FFFFC) - 0x40000000) & 0x400) == 0 )
        break;
      v1 = (_DWORD *)*v1;
      v2 = 4095;
      if ( v1 == (_DWORD *)(result + 16) )
        goto LABEL_10;
    }
    v4 = (unsigned int)(v1[8] + 4095) >> 12;
    if ( v3 != PsNtosImageBase && v3 != PsHalImageBase )
    {
      do
        v2 = __ldrex((unsigned int *)algn_634DB0);
      while ( __strex(v2 + v4, (unsigned int *)algn_634DB0) );
      v5 = dword_634D90 - v4;
      __dmb(0xBu);
      dword_634D90 = v5;
    }
    result = sub_969C5C(v4, v2);
  }
  return result;
}
