// ViLookasideTrackListEx 
 
int __fastcall ViLookasideTrackListEx(int a1, int a2, int (__fastcall *a3)(int a1), void *a4)
{
  if ( a2 )
  {
    a3 = *(int (__fastcall **)(int))(a1 + 40);
    a4 = ExAllocatePoolEx;
    if ( (char *)a3 == (char *)ExAllocatePoolEx )
    {
      a3 = *(int (__fastcall **)(int))(a1 + 44);
      a4 = ST_STORE<SM_TRAITS>::StDmSparseBitmapFree;
      if ( a3 == ST_STORE<SM_TRAITS>::StDmSparseBitmapFree )
      {
        *(_DWORD *)(a1 + 40) = VerifierExAllocatePoolWithTag;
        a4 = VerifierExFreePoolEx;
        *(_DWORD *)(a1 + 44) = VerifierExFreePoolEx;
      }
    }
  }
  return ViLookasideAdd(a1, a2, (int)a3, (int)a4);
}
