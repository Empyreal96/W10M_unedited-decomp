// VfThunkApplyMandatoryThunks 
 
int __fastcall VfThunkApplyMandatoryThunks(int a1, int a2)
{
  int v4; // r4
  int v5; // r2
  int v6; // r3
  int v7; // r0
  int v8; // r2
  int v9; // r3
  int v10; // r5
  _BYTE v12[48]; // [sp-4h] [bp-30h] BYREF

  if ( !a2 || !MmIsSessionAddress(*(_DWORD *)(a1 + 24)) )
    return ViThunkApplyMandatoryThunksCurrentSession(a1, a2);
  v4 = 1;
  while ( 1 )
  {
    v7 = MmGetNextSession();
    v10 = v7;
    if ( !v7 )
      break;
    if ( MmAttachSession(v7, (int)v12, v8, v9) >= 0 )
    {
      v4 = 1;
      if ( MmIsDriverLoadedCurrentSession(*(_DWORD *)(a1 + 24)) )
        v4 = ViThunkApplyMandatoryThunksCurrentSession(a1, a2);
      MmDetachSession(v10, (int)v12, v5, v6);
      if ( !v4 )
      {
        MmQuitNextSession(v10);
        return v4;
      }
    }
  }
  return v4;
}
