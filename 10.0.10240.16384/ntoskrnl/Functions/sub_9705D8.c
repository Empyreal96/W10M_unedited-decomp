// sub_9705D8 
 
void __fastcall sub_9705D8(int a1)
{
  _DWORD **v1; // r5
  _DWORD *v2; // r2
  int v3; // r3

  KiInitializeMutant(a1 + 4, 0, 1);
  v2 = *v1;
  v3 = (int)(*v1 + 12);
  v2[9] = 1;
  v2[10] = 0;
  v2[11] = 0;
  *(_BYTE *)v3 = 1;
  *(_BYTE *)(v3 + 2) = 4;
  *(_BYTE *)(v3 + 1) = 0;
  *(_DWORD *)(v3 + 4) = 0;
  v3 += 8;
  *(_DWORD *)v3 = v3;
  *(_DWORD *)(v3 + 4) = v3;
  v2[17] = v2 + 17;
  v2[18] = v2 + 17;
  *v2 = 259;
  PnpNotificationInProgressLock = 1;
  dword_62FB04 = 0;
  unk_62FB08 = 0;
  byte_62FB0C = 1;
  byte_62FB0D = 0;
  byte_62FB0E = 4;
  dword_62FB10 = 0;
  dword_62FB18 = (int)&dword_62FB14;
  dword_62FB14 = (int)&dword_62FB14;
  PnpEventQueueEmpty = 0;
  byte_62FB21 = 0;
  byte_62FB22 = 4;
  dword_62FB24 = 1;
  dword_62FB2C = (int)&dword_62FB28;
  dword_62FB28 = (int)&dword_62FB28;
  JUMPOUT(0x9645F6);
}
