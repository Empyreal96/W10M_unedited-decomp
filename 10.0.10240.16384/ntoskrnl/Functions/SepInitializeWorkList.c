// SepInitializeWorkList 
 
int SepInitializeWorkList()
{
  ExInitializeResourceLite((int)algn_641888);
  dword_6418C0[0] = 0;
  SepLsaAuditQueueInfo = (int)&SepLsaAuditQueueInfo;
  *(_DWORD *)algn_64187C = &SepLsaAuditQueueInfo;
  dword_641884 = (int)&dword_641880;
  dword_641880 = (int)&dword_641880;
  dword_6418EC = (int)ExFreePool;
  dword_6418E8 = (int)SepAdtDetermineInsertQueue;
  word_6418F0 = 3;
  ExInitializeResourceLite((int)&unk_6417E8);
  SepLsaDeletedLogonQueueInfo = (int)&SepLsaDeletedLogonQueueInfo;
  unk_6417DC = &SepLsaDeletedLogonQueueInfo;
  dword_64184C = (int)ExFreePool;
  word_641850 = 1;
  return 1;
}
