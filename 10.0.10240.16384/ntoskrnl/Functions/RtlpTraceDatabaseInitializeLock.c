// RtlpTraceDatabaseInitializeLock 
 
int __fastcall RtlpTraceDatabaseInitializeLock(int a1)
{
  if ( (*(_DWORD *)(a1 + 4) & 4) != 0 )
  {
    *(_DWORD *)(a1 + 32) = 0;
  }
  else
  {
    *(_DWORD *)(a1 + 32) = 1;
    *(_DWORD *)(a1 + 36) = 0;
    *(_DWORD *)(a1 + 40) = 0;
    *(_BYTE *)(a1 + 44) = 1;
    *(_BYTE *)(a1 + 45) = 0;
    *(_BYTE *)(a1 + 46) = 4;
    *(_DWORD *)(a1 + 48) = 0;
    *(_DWORD *)(a1 + 52) = a1 + 52;
    *(_DWORD *)(a1 + 56) = a1 + 52;
  }
  return 1;
}
