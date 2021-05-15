// sub_965AFC 
 
void sub_965AFC()
{
  PiUEventClientRegistrationListLock = 1;
  dword_6308E4 = 0;
  unk_6308E8 = 0;
  byte_6308EC = 1;
  byte_6308ED = 0;
  byte_6308EE = 4;
  dword_6308F0 = 0;
  dword_6308F8 = (int)&dword_6308F4;
  dword_6308F4 = (int)&dword_6308F4;
  PiUEventUsermodeEventQueueLock = 1;
  dword_630B04 = 0;
  unk_630B08 = 0;
  byte_630B0C = 1;
  byte_630B0D = 0;
  byte_630B0E = 4;
  dword_630B10 = 0;
  dword_630B18 = (int)&dword_630B14;
  dword_630B14 = (int)&dword_630B14;
  PiUEventBroadcastEventQueueLock = 1;
  dword_630B44 = 0;
  unk_630B48 = 0;
  byte_630B4C = 1;
  byte_630B4D = 0;
  byte_630B4E = 4;
  dword_630B50 = 0;
  dword_630B58 = (int)&dword_630B54;
  dword_630B54 = (int)&dword_630B54;
  JUMPOUT(0x948E1A);
}
