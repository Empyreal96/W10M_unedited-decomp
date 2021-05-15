// CMFReadCompressedSegment 
 
int __fastcall CMFReadCompressedSegment(int a1, int a2, int a3, int a4)
{
  int v4; // r8
  int v5; // r4

  v4 = 0;
  if ( a1 && a4 && a2 )
  {
    if ( *(_DWORD *)(a4 + 84) > 0x400u )
      return -1073741811;
    v4 = XpressDecodeCreate();
    if ( v4 )
    {
      v5 = ZwCreateSection();
      if ( v5 >= 0 )
      {
        v5 = ZwMapViewOfSection();
        if ( v5 >= 0 )
          v5 = -1073741306;
      }
    }
    else
    {
      v5 = -1073741801;
    }
  }
  else
  {
    v5 = -1073741811;
  }
  if ( v4 )
    XpressDecodeClose(v4);
  return v5;
}
