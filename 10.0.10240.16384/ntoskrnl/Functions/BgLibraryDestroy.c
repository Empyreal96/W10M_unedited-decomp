// BgLibraryDestroy 
 
int __fastcall BgLibraryDestroy(int a1)
{
  unsigned int v1; // r0
  int v2; // r5
  unsigned int v3; // r0
  int v5; // r4

  v1 = BgpFwGetCurrentIrql(a1);
  if ( v1 > 2 )
    return -1073741823;
  v2 = 0;
  v3 = BgpFwAcquireLock(v1);
  if ( (dword_619018 & 1) == 0 )
    return sub_8DEDEC(v3);
  if ( (dword_619018 & 0xC00) == 3072 )
    v2 = 1;
  v5 = BgpFwLibraryDestroy(v3);
  if ( !v2 )
    BgpFwReleaseLock();
  return v5;
}
