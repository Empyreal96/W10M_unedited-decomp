// EmRemoveBadS3PagesCallback 
 
int __fastcall EmRemoveBadS3PagesCallback(int a1, int a2, int a3, int a4, int *a5, int a6)
{
  if ( !a5 || a6 != 1 )
    return 1;
  EmpBadS3Page = *a5;
  dword_631EE8 = (int)EmpRemoveBadS3PageWorker;
  dword_631EEC = 0;
  PersistBadS3PageWorkItem = 0;
  ExQueueWorkItem(&PersistBadS3PageWorkItem, 1);
  return 2;
}
