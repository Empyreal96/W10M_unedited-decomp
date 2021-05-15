// sub_7E8FEC 
 
void __fastcall sub_7E8FEC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  int v11; // r4
  int v12; // r0

  if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x4C) & 0x400) != 0
    || *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
  {
    v12 = 0;
  }
  else
  {
    v12 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x9C);
  }
  if ( !v12 || v11 != *(_DWORD *)(a3 + 336) || !DbgkpSuppressDbgMsg(v12) )
  {
    a5 = 2359308;
    a6 = 8;
    a11 = 6;
    DbgkpSendApiMessage(v11, 1, &a5);
  }
  JUMPOUT(0x700C1C);
}
