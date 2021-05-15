// PsReturnPoolQuota 
 
int __fastcall PsReturnPoolQuota(int result, int a2, int a3)
{
  int v4; // r1
  int v5; // r0

  v4 = result;
  if ( result != PsInitialSystemProcess )
  {
    v5 = *(_DWORD *)(result + 332);
    __dmb(0xBu);
    result = PspReturnQuota(v5, v4, a2 == 1, a3);
  }
  return result;
}
