// sub_5537F8 
 
void sub_5537F8()
{
  int v0; // r5
  __int16 *v1; // r7
  int v2; // r8
  int v3; // r9
  int v4; // r10
  int i; // r4
  int v6; // r6
  int v7; // r3
  int v8; // r0

  for ( i = 0; ; ++i )
  {
    v6 = ZwEnumerateKey();
    if ( v6 >= 0 && (unsigned int)(*(_DWORD *)(v0 + 12) + 24) < 0x1FE )
    {
      *(_WORD *)(v0 + 2 * (*(_DWORD *)(v0 + 12) >> 1) + 16) = 0;
      if ( RtlpMuiRegGetInstalledLanguageIndexByName(v2, v0 + 16) >= 0 )
      {
        v7 = *v1;
        if ( v7 != v4 && v7 != v3 )
        {
          *(_WORD *)(*(_DWORD *)(*(_DWORD *)(v2 + 20) + 12) + 28 * v7) &= 0xFFDFu;
          *(_WORD *)(*(_DWORD *)(*(_DWORD *)(v2 + 20) + 12) + 28 * *v1) |= 0x8000u;
        }
      }
    }
    if ( v6 == -2147483622 )
    {
      v8 = *((_DWORD *)v1 + 1);
      if ( v8 )
        NtClose(v8);
      JUMPOUT(0x4F41EC);
    }
  }
}
