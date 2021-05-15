// PsReturnProcessQuota 
 
int __fastcall PsReturnProcessQuota(int result, int a2, int a3)
{
  int v3; // r1
  int v4; // r0

  v3 = result;
  if ( result != PsInitialSystemProcess )
  {
    v4 = *(_DWORD *)(result + 332);
    __dmb(0xBu);
    result = PspReturnQuota(v4, v3, 3, a3);
  }
  return result;
}
