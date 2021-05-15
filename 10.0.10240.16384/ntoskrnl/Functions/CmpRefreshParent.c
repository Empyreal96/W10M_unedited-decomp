// CmpRefreshParent 
 
int __fastcall CmpRefreshParent(int a1, int a2, __int64 *a3)
{
  __int64 v3; // kr00_8

  v3 = *a3;
  if ( *(_DWORD *)(a1 + 40) == *(_DWORD *)a3 )
  {
    *(_DWORD *)(a1 + 40) = HIDWORD(v3);
    if ( *(_DWORD *)v3 )
    {
      CmpReferenceKeyControlBlock((unsigned int *)HIDWORD(v3));
      CmpDereferenceKeyControlBlockWithLock(v3, 0);
    }
  }
  return 0;
}
