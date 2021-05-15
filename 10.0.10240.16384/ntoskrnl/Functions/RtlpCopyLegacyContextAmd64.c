// RtlpCopyLegacyContextAmd64 
 
int __fastcall RtlpCopyLegacyContextAmd64(int result, int a2, int a3, int a4)
{
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r1
  int v17; // r2
  int v18; // r3

  result = (char)result;
  *(_DWORD *)(a2 + 48) = a3 & 0x67FFFFFF;
  if ( (_BYTE)result )
  {
    if ( (a3 & 0x40000000) != 0 )
      *(_DWORD *)(a2 + 48) = *(_DWORD *)(a4 + 48) & 0x98000000 | a3 & 0x67FFFFFF;
    result = a3 & 0x100001;
    if ( (a3 & 0x100001) == 1048577 )
    {
      *(_DWORD *)(a2 + 248) = *(_DWORD *)(a4 + 248);
      *(_DWORD *)(a2 + 252) = *(_DWORD *)(a4 + 252);
      *(_WORD *)(a2 + 56) = *(_WORD *)(a4 + 56);
      *(_WORD *)(a2 + 66) = *(_WORD *)(a4 + 66);
      *(_DWORD *)(a2 + 152) = *(_DWORD *)(a4 + 152);
      *(_DWORD *)(a2 + 156) = *(_DWORD *)(a4 + 156);
      *(_DWORD *)(a2 + 68) = *(_DWORD *)(a4 + 68);
    }
    if ( (a3 & 0x100002) == 1048578 )
    {
      v7 = *(_DWORD *)(a4 + 124);
      v8 = *(_DWORD *)(a4 + 128);
      v9 = *(_DWORD *)(a4 + 132);
      *(_DWORD *)(a2 + 120) = *(_DWORD *)(a4 + 120);
      *(_DWORD *)(a2 + 124) = v7;
      *(_DWORD *)(a2 + 128) = v8;
      *(_DWORD *)(a2 + 132) = v9;
      v10 = *(_DWORD *)(a4 + 140);
      v11 = *(_DWORD *)(a4 + 144);
      v12 = *(_DWORD *)(a4 + 148);
      *(_DWORD *)(a2 + 136) = *(_DWORD *)(a4 + 136);
      *(_DWORD *)(a2 + 140) = v10;
      *(_DWORD *)(a2 + 144) = v11;
      *(_DWORD *)(a2 + 148) = v12;
      result = memmove(a2 + 160, a4 + 160, 0x58u);
    }
    if ( (a3 & 0x100004) == 1048580 )
    {
      *(_WORD *)(a2 + 64) = *(_WORD *)(a4 + 64);
      *(_WORD *)(a2 + 62) = *(_WORD *)(a4 + 62);
      *(_WORD *)(a2 + 60) = *(_WORD *)(a4 + 60);
      *(_WORD *)(a2 + 58) = *(_WORD *)(a4 + 58);
    }
    if ( (a3 & 0x100008) == 1048584 )
    {
      *(_DWORD *)(a2 + 52) = *(_DWORD *)(a4 + 52);
      result = memmove(a2 + 256, a4 + 256, 0x200u);
    }
    if ( (a3 & 0x100010) == 1048592 )
    {
      memmove(a2 + 72, a4 + 72, 0x30u);
      v13 = *(_DWORD *)(a4 + 1204);
      v14 = *(_DWORD *)(a4 + 1208);
      v15 = *(_DWORD *)(a4 + 1212);
      *(_DWORD *)(a2 + 1200) = *(_DWORD *)(a4 + 1200);
      *(_DWORD *)(a2 + 1204) = v13;
      *(_DWORD *)(a2 + 1208) = v14;
      *(_DWORD *)(a2 + 1212) = v15;
      result = *(_DWORD *)(a4 + 1216);
      v16 = *(_DWORD *)(a4 + 1220);
      v17 = *(_DWORD *)(a4 + 1224);
      v18 = *(_DWORD *)(a4 + 1228);
      *(_DWORD *)(a2 + 1216) = result;
      *(_DWORD *)(a2 + 1220) = v16;
      *(_DWORD *)(a2 + 1224) = v17;
      *(_DWORD *)(a2 + 1228) = v18;
    }
  }
  return result;
}
