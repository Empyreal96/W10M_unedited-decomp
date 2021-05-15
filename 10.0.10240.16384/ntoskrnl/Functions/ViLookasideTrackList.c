// ViLookasideTrackList 
 
int __fastcall ViLookasideTrackList(int a1, int a2, int (__fastcall *a3)(int a1, int a2, int a3), void *a4)
{
  int (__fastcall *v4)(int, int, int); // r3

  if ( a2 )
  {
    a3 = *(int (__fastcall **)(int, int, int))(a1 + 44);
    a4 = ExFreePool;
    if ( (char *)a3 == (char *)ExFreePool )
    {
      a3 = *(int (__fastcall **)(int, int, int))(a1 + 40);
      if ( a3 == ExAllocatePoolWithTag )
      {
        v4 = VerifierExAllocatePoolWithTag;
LABEL_7:
        *(_DWORD *)(a1 + 40) = v4;
        a4 = VerifierExFreePool;
        *(_DWORD *)(a1 + 44) = VerifierExFreePool;
        return ViLookasideAdd(a1, a2, (int)a3, (int)a4);
      }
      a4 = ExAllocatePoolWithQuotaTag;
      if ( (char *)a3 == (char *)ExAllocatePoolWithQuotaTag )
      {
        v4 = VerifierExAllocatePoolWithQuotaTag;
        goto LABEL_7;
      }
    }
  }
  return ViLookasideAdd(a1, a2, (int)a3, (int)a4);
}
