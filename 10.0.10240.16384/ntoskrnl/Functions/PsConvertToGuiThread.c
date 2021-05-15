// PsConvertToGuiThread 
 
int PsConvertToGuiThread()
{
  unsigned int v0; // r5
  int v2; // r4
  unsigned __int8 *v3; // r6
  unsigned int v4; // r3
  unsigned int v5; // r3
  int v6; // [sp+8h] [bp-20h] BYREF
  int v7; // [sp+Ch] [bp-1Ch]
  _DWORD v8[6]; // [sp+10h] [bp-18h] BYREF

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( !*(_BYTE *)(v0 + 0x15A) )
    return -1073741811;
  if ( (*(_DWORD *)(v0 + 80) & 0x40) != 0 )
    return sub_7D52C0();
  if ( *(int *)(*(_DWORD *)(v0 + 116) + 188) < 0 )
    return -1073741790;
  v6 = *(_DWORD *)(v0 + 116);
  v7 = 1;
  if ( PsQuerySectionSignatureInformation() >= 0 )
    v7 ^= ((unsigned __int8)v7 ^ (unsigned __int8)(2 * SeCompareSigningLevels())) & 2;
  v2 = PsInvokeWin32Callout(0, &v6, 0, 0);
  if ( v2 >= 0 )
  {
    __dmb(0xBu);
    v3 = (unsigned __int8 *)(v0 + 80);
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 | 0x40, v3) );
    __dmb(0xBu);
    v8[0] = v0;
    v8[1] = 0;
    v2 = PsInvokeWin32Callout(1, v8, 0, 0);
    if ( v2 < 0 )
    {
      __dmb(0xBu);
      do
        v5 = __ldrex(v3);
      while ( __strex(v5 & 0xBF, v3) );
      __dmb(0xBu);
    }
    SeCaptureAtomTableCallout();
  }
  return v2;
}
