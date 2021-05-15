// KdpSetContextEx 
 
int __fastcall KdpSetContextEx(int a1, int a2, int a3)
{
  unsigned int v4; // r3
  __int64 v5; // kr00_8
  unsigned int v6; // r2
  int v7; // r9
  unsigned __int16 v8; // r0
  int v9; // r2
  int v10; // r3
  int v13; // [sp+4h] [bp-2Ch]

  v4 = *(unsigned __int16 *)(a1 + 6);
  v5 = *(_QWORD *)(a1 + 20);
  v6 = *(_DWORD *)(a1 + 16);
  if ( v4 < 0x20 && *(&KiProcessorBlock + v4) && KdpContextSent )
  {
    if ( HIDWORD(v5) <= 0x1000
      && v6 < HIDWORD(v5)
      && (_DWORD)v5
      && (v7 = v5 + v6, (unsigned int)v5 + (unsigned __int64)v6 <= HIDWORD(v5)) )
    {
      KdpQuickMoveMemory((char *)&unk_6521E8 + v6, *(_DWORD *)(a2 + 4), v5);
      if ( v7 == HIDWORD(v5) )
      {
        v8 = KeGetCurrentProcessorNumberEx(0);
        v9 = *(unsigned __int16 *)(a1 + 6);
        if ( v9 != v8 )
          a3 = *((_DWORD *)*(&KiProcessorBlock + v9) + 326);
        KdpSanitizeContextFlags(&unk_6521E8);
        KdpCopyContext(a3, v13);
      }
      v10 = 0;
      *(_DWORD *)(a1 + 24) = v5;
    }
    else
    {
      v10 = -1073741811;
    }
  }
  else
  {
    v10 = -1073741823;
  }
  *(_DWORD *)(a1 + 8) = v10;
  return KdSendPacket_0();
}
