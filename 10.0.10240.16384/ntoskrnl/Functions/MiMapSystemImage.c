// MiMapSystemImage 
 
int __fastcall MiMapSystemImage(int a1, unsigned int a2)
{
  int v2; // r5
  _DWORD *v4; // r4
  unsigned int v5; // r10
  char v6; // r2
  int v8; // r5
  unsigned int v9; // r0
  int v10; // r0
  int v11; // r1
  int v12; // r0
  int v13; // r1
  unsigned __int64 v15; // [sp+10h] [bp-28h] BYREF

  v2 = a1;
  v15 = 0i64;
  v4 = (_DWORD *)MiSectionControlArea(a1);
  v5 = *(_DWORD *)(*v4 + 4);
  if ( (v6 & 1) != 0 )
    return sub_7CDDBC();
  v8 = MiChargeSystemImageCommitment(v2, 1);
  if ( v8 >= 0 )
  {
    v8 = MiAddMappedPtes((unsigned int *)(((a2 >> 10) & 0x3FFFFC) - 0x40000000), v5, v4, &v15, -1);
    if ( v8 < 0 )
    {
      MiChargeSystemImageCommitment(a1, 0);
      if ( a2 >= dword_63389C )
      {
        v10 = MiGetSystemRegionIndex(a2);
        if ( *(_BYTE *)(v10 + v11 + 9692) == 1 || (v12 = MiGetSystemRegionIndex(a2), *(_BYTE *)(v12 + v13 + 9692) == 11) )
        {
          if ( a2 != *(_DWORD *)(*v4 + 24) )
            MiDeleteSessionDriverProtos(v4);
        }
      }
    }
    else
    {
      do
        v9 = __ldrex((unsigned int *)&algn_632F58[4]);
      while ( __strex(v9 + v5, (unsigned int *)&algn_632F58[4]) );
      v8 = 0;
    }
  }
  return v8;
}
