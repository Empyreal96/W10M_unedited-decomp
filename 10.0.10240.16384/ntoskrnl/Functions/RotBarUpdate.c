// RotBarUpdate 
 
int RotBarUpdate()
{
  int v0; // r3
  int v1; // r4
  char *v2; // r3
  int result; // r0

  if ( PltRotBarStatus )
  {
    if ( PltRotBarStatus == 1 )
    {
      v1 = PaletteNum;
      FadePalette((unsigned __int8)PaletteNum);
      ++v1;
      v2 = PalettePtr;
      PaletteNum = v1;
      PalettePtr[4] = 0;
      v2[5] = 0;
      v2[6] = 0;
      v2[7] = 0;
      if ( v1 >= 20 )
      {
        PltRotBarStatus = 2;
        FadingIn = 1;
        PaletteNum = 1;
      }
      goto LABEL_24;
    }
    if ( PltRotBarStatus != 2 )
    {
      if ( PltRotBarStatus == 3 )
        return result;
      goto LABEL_24;
    }
    if ( !AnimBarPos )
      goto LABEL_18;
    if ( AnimBarPos != 1 )
    {
      if ( AnimBarPos != 2 )
      {
        if ( AnimBarPos == 16 )
        {
          VidBufferToScreenBlt_0();
        }
        else if ( AnimBarPos != 17 )
        {
          VidBufferToScreenBlt_0();
          VidBufferToScreenBlt_0();
          VidBufferToScreenBlt_0();
          v0 = AnimBarPos;
          if ( AnimBarPos <= 3 )
            goto LABEL_20;
          goto LABEL_18;
        }
        VidBufferToScreenBlt_0();
LABEL_18:
        VidSolidColorFill_0();
        goto LABEL_19;
      }
      VidBufferToScreenBlt_0();
    }
    VidBufferToScreenBlt_0();
LABEL_19:
    v0 = AnimBarPos;
LABEL_20:
    AnimBarPos = v0 + 1;
    if ( v0 + 1 > 17 )
      AnimBarPos = 0;
LABEL_24:
    result = InbvGetDisplayState();
    if ( !result )
      result = VidBitBlt_0();
  }
  return result;
}
