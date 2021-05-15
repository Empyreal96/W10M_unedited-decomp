// MiReturnVadQuota 
 
int __fastcall MiReturnVadQuota(int result, int a2, int a3)
{
  int v3; // r5

  v3 = result;
  if ( (*(_DWORD *)(result + 32) & 0x7FFFFFFFu) < 0x7FFFE )
  {
    result = PsReturnProcessNonPagedPoolQuota(a2, 0x4Cu);
    if ( a3 == 1 )
    {
      result = MiVadPureReserve(v3);
      if ( !result )
        result = PsReturnProcessPagedPoolQuota(a2, 4 * (*(_DWORD *)(v3 + 16) - *(_DWORD *)(v3 + 12) + 1));
    }
  }
  return result;
}
