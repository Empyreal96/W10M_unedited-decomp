// sub_9668B4 
 
// bad sp value at call has been detected, the output may be wrong!
int sub_9668B4()
{
  int (*v1)(void); // [sp+14h] [bp-4h]

  KiForceSymbolReferences();
  KeBugCheckCallbackListHead = (int)&KeBugCheckCallbackListHead;
  dword_624F84 = (int)&KeBugCheckCallbackListHead;
  KeBugCheckReasonCallbackListHead = (int)&KeBugCheckReasonCallbackListHead;
  dword_624D2C = (int)&KeBugCheckReasonCallbackListHead;
  KeBugCheckAddRemovePagesCallbackListHead = (int)&KeBugCheckAddRemovePagesCallbackListHead;
  *(_DWORD *)algn_624D24 = &KeBugCheckAddRemovePagesCallbackListHead;
  KeBugCheckCallbackLock = 0;
  KiProfileListHead = (int)&KiProfileListHead;
  dword_624F14 = (int)&KiProfileListHead;
  KiProfileSourceListHead = (int)&KiProfileSourceListHead;
  *(_DWORD *)algn_624F1C = &KiProfileSourceListHead;
  KiSwapEvent = 1;
  byte_624F21 = 0;
  byte_624F22 = 4;
  dword_624F24 = 0;
  dword_624F2C = (int)&dword_624F28;
  dword_624F28 = (int)&dword_624F28;
  KiProcessInSwapListHead = 0;
  KiProcessOutSwapListHead = 0;
  KiStackInSwapListHead = 0;
  KeServiceDescriptorTable = (int)&KiServiceTable;
  dword_682088 = 441;
  dword_68208C = (int)KiArgumentTable;
  dword_682098 = 0;
  KeServiceDescriptorTableShadow = (int)&KiServiceTable;
  *(_DWORD *)algn_682004 = *(_DWORD *)algn_682084;
  dword_682008 = 441;
  *(_DWORD *)algn_68200C = KiArgumentTable;
  dword_682010 = dword_682090;
  *(_DWORD *)algn_682014 = *(_DWORD *)algn_682094;
  dword_682018 = 0;
  *(_DWORD *)algn_68201C = *(_DWORD *)algn_68209C;
  KiBalanceSetManagerPeriodicDpc = 19;
  byte_624F61 = 1;
  word_624F62 = 0;
  unk_624F6C = KiBalanceSetManagerDeferredRoutine;
  unk_624F70 = &KiBalanceSetManagerPeriodicEvent;
  dword_624F7C = 0;
  dword_624F68 = 0;
  KiBalanceSetManagerPeriodicEvent = 1;
  byte_624F41 = 0;
  byte_624F42 = 4;
  dword_624F44 = 0;
  dword_624F4C = (int)&dword_624F48;
  dword_624F48 = (int)&dword_624F48;
  KiDynamicProcessorLock = 1;
  dword_624E44 = 0;
  unk_624E48 = 0;
  byte_624E4C = 1;
  byte_624E4D = 0;
  byte_624E4E = 4;
  dword_624E50 = 0;
  dword_624E58 = (int)&dword_624E54;
  dword_624E54 = (int)&dword_624E54;
  return v1();
}
