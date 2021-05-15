// sub_7F1140 
 
void __fastcall sub_7F1140(int a1, int a2, _BYTE *a3)
{
  int v3; // r10
  int v4; // r9
  __int64 v5; // kr00_8

  *a3 = 0;
  if ( dword_61EEA4 )
  {
    if ( MmZeroPageFileAtShutdown(a1) )
      PopZeroHiberFile(PopHiberInfo, dword_61EEA4);
    ObfDereferenceObject(dword_61EEA4);
    ZwClose();
    ExFreePoolWithTag(dword_61EEB0);
    memset(&PopHiberInfo, 0, 128);
    v4 = dword_61EEBC;
    byte_61EA48 = 0;
    byte_61EA56 = 0;
    byte_61EA52 = 0;
    *(_DWORD *)&algn_61EEC4[4] = 0;
    *(_DWORD *)&algn_61EEC4[8] = 0;
    dword_61EEBC = 0;
    dword_61EEC0 = 0;
    v5 = *(_QWORD *)&dword_61EED8;
    PopResetCurrentPolicies();
    if ( v4 )
      MmReleaseDumpHibernateResources(v4, 53248);
    if ( HIDWORD(v5) )
    {
      MmReturnChargesToLockPagedPool(HIDWORD(v5), dword_61EEE0);
      ExFreePoolWithTag(HIDWORD(v5));
      memset(algn_61EEDC, 0, 60);
    }
    if ( (_DWORD)v5 )
    {
      ExFreePoolWithTag(v5);
      dword_61EED8 = 0;
    }
  }
  if ( v3 )
    PopSaveHibernateEnabled();
  JUMPOUT(0x78BF20);
}
