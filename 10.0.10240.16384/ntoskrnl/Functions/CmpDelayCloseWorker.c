// CmpDelayCloseWorker 
 
int __fastcall CmpDelayCloseWorker(int a1)
{
  BOOL v1; // r7
  unsigned int v3; // r2

  v1 = a1 != 0;
  CmpLockRegistry();
  if ( !v1 )
  {
    __dmb(0xBu);
    do
      v3 = __ldrex(&CmpDelayCloseWorkItemActive);
    while ( __strex(2u, &CmpDelayCloseWorkItemActive) );
    __dmb(0xBu);
  }
  return sub_804D5C(2, &CmpDelayCloseWorkItemActive);
}
