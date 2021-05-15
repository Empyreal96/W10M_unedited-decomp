// CmpInitializeTransactions 
 
int __fastcall CmpInitializeTransactions(int a1, int a2)
{
  CmpRmListHead = &CmpRmListHead;
  dword_631F94 = (int)&CmpRmListHead;
  CmpRmListLock = 1;
  dword_631FA4 = 0;
  unk_631FA8 = 0;
  byte_631FAC = 1;
  byte_631FAD = 0;
  byte_631FAE = 4;
  dword_631FB0 = 0;
  dword_631FB8 = (int)&dword_631FB4;
  dword_631FB4 = (int)&dword_631FB4;
  CmpTransactionListLock = 1;
  dword_632184 = 0;
  unk_632188 = 0;
  byte_63218C = 1;
  byte_63218D = 0;
  byte_63218E = 4;
  dword_632190 = 0;
  dword_632198 = (int)&dword_632194;
  dword_632194 = (int)&dword_632194;
  CmpTransactionInitializingEvent = 0;
  dword_6321B8 = (int)CmpLazyCommitWorker;
  dword_6321BC = 0;
  CmpLazyCommitWorkItem = 0;
  CmpLazyCommitListHead = (int)&CmpLazyCommitListHead;
  dword_6321C4 = (int)&CmpLazyCommitListHead;
  if ( qword_641CF0 )
    JUMPOUT(0x97041A);
  return sub_970284(a1, a2, qword_641CF0, HIDWORD(qword_641CF0) | qword_641CF0);
}
