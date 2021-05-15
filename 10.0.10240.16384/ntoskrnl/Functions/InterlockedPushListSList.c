// InterlockedPushListSList 
 
int __fastcall InterlockedPushListSList(unsigned __int64 *a1, unsigned int a2, _DWORD *a3, int a4)
{
  unsigned __int64 v4; // r4
  unsigned __int64 v5; // r6

  do
  {
    do
    {
      v4 = *a1;
      *a3 = *(_DWORD *)a1;
      __dmb(0xBu);
      v5 = __ldrexd(a1);
    }
    while ( v4 != v5 );
  }
  while ( __strexd(__PAIR64__(HIDWORD(v4) + a4, a2), a1) == 1 );
  return v4;
}
