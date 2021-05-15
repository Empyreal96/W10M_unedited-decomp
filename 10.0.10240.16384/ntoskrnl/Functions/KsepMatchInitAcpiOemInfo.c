// KsepMatchInitAcpiOemInfo 
 
int KsepMatchInitAcpiOemInfo()
{
  int v0; // r5
  int v1; // r0
  int v2; // r4
  int v3; // r3

  v0 = -1073741275;
  memset(dword_647518, 0, 36);
  dword_647534 = -1;
  dword_647538 = -1;
  memset(dword_6474F4, 0, 36);
  dword_647510 = -1;
  v1 = HalAcpiGetTableEx_0();
  v2 = v1;
  if ( v1 )
  {
    v0 = KsepStringAnsiToUnicode((int)&unk_6474C0, 0xEu, v1 + 10, 6);
    if ( v0 >= 0 )
    {
      v0 = KsepStringAnsiToUnicode((int)&unk_6474A0, 0x12u, v2 + 16, 8);
      if ( v0 >= 0 )
      {
        v0 = KsepStringAnsiToUnicode((int)&unk_6474B4, 0xAu, v2 + 28, 4);
        if ( v0 >= 0 )
        {
          dword_647518[0] = &unk_6474C0;
          dword_647518[1] = &unk_6474B4;
          dword_647534 = *(unsigned __int8 *)(v2 + 8);
          v3 = *(_DWORD *)(v2 + 32);
          dword_6474F4[0] = &unk_6474C0;
          dword_6474F4[1] = &unk_6474A0;
          dword_647538 = v3;
          dword_647510 = *(_DWORD *)(v2 + 24);
        }
      }
    }
  }
  return v0;
}
