// sub_817FDC 
 
void sub_817FDC()
{
  int v0; // r5
  _DWORD *v1; // r6
  unsigned __int8 *v2; // r7
  _DWORD *v3; // r8
  int v4; // r0
  char *v5; // r2
  __int16 v6; // r2
  int v7; // r1
  int v8; // r2
  int v9; // r1
  int v10; // r2
  int v11; // r3
  _BYTE *v12; // r0

  if ( v3[1] == 7 && (unsigned int)(v3[4] + 24) <= 0x200 )
  {
    v4 = *((_DWORD *)v2 + 3);
    v5 = (char *)v3 + 2 * (v3[4] >> 1);
    *((_DWORD *)v2 + 4) = v5;
    *((_DWORD *)v2 + 7) = *((unsigned __int16 *)v5 + 10);
    *((_WORD *)v5 + 10) = 0;
    if ( RtlpMuiRegGetLanguageSpec(v4, v3 + 5, v2) >= 0 )
    {
      *((_DWORD *)v2 + 8) = 0;
      *((_DWORD *)v2 + 9) = 0;
      v6 = *((_WORD *)v2 + 17);
      *((_DWORD *)v2 + 10) = 0;
      v7 = *((_DWORD *)v2 + 3);
      *((_WORD *)v2 + 17) = v6 & 0x3FFF | (*v2 << 14);
      v8 = *((_DWORD *)v2 + 7);
      *((_WORD *)v2 + 16) = *((_WORD *)v2 + 4);
      *(_WORD *)(*((_DWORD *)v2 + 4) + 20) = v8;
      if ( RtlpMuiRegConfigNodePopulate(v2 + 32, v7, (char *)v3 + v3[2], v3[3]) >= 0
        && RtlpMuiRegValidateConfigNode(*((_DWORD *)v2 + 3), (__int16 *)v2 + 16) >= 0 )
      {
        if ( !v0 )
        {
          v12 = RtlpMuiRegCreateLanguageConfigList(-1, v9, v10, v11);
          *((_DWORD *)v2 + 1) = v12;
          if ( !v12 )
            JUMPOUT(0x7B138E);
          *v1 = v12;
        }
        if ( RtlpMuiRegConfigListAddLanguage(v2 + 4, v2 + 32) >= 0 )
          *v1 = *((_DWORD *)v2 + 1);
      }
    }
    JUMPOUT(0x7B137C);
  }
  JUMPOUT(0x7B1380);
}
