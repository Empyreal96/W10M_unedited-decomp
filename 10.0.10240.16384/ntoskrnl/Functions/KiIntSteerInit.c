// KiIntSteerInit 
 
int __fastcall KiIntSteerInit(int a1, int a2, int a3, int a4)
{
  int v5; // [sp+0h] [bp-8h] BYREF

  v5 = a4;
  KiIntTrackRootCount = 0;
  KiIntTrackRootList = (int)&KiIntTrackRootList;
  dword_6217DC = (int)&KiIntTrackRootList;
  KiIntTrackSpinlock = 0;
  KiIntSteerMask[0] = 1;
  word_6217F2 = 1;
  dword_6217F4 = 0;
  dword_6217F8 = 1;
  KiIntSteerAffinitizedInterrupts = 1;
  word_621812 = 1;
  *(_DWORD *)algn_621814 = 0;
  dword_621818 = 0;
  off_617B54(39, 4, &KiInterruptControllerInfo, &v5);
  return 0;
}
