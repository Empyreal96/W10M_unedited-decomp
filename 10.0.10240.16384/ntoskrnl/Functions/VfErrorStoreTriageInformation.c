// VfErrorStoreTriageInformation 
 
int __fastcall VfErrorStoreTriageInformation(int a1, int a2, int a3, int a4, int a5)
{
  int result; // r0
  unsigned int v7; // r5

  __dmb(0xBu);
  result = 1;
  do
    v7 = __ldrex(&VfErrorBugcheckDataReady);
  while ( __strex(1u, &VfErrorBugcheckDataReady) );
  __dmb(0xBu);
  if ( v7 )
    return 0;
  __dmb(0xBu);
  VfErrorBugcheckData = a1;
  __dmb(0xBu);
  dword_909004 = a2;
  __dmb(0xBu);
  dword_909008 = a3;
  __dmb(0xBu);
  dword_90900C = a4;
  __dmb(0xBu);
  dword_909010 = a5;
  return result;
}
