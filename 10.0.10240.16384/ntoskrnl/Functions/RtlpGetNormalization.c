// RtlpGetNormalization 
 
int __fastcall RtlpGetNormalization(unsigned int a1, void ***a2, unsigned int a3, unsigned __int16 *a4)
{
  int v6; // r4
  void **v7; // r4
  void **v8; // r0
  int v9; // r0
  unsigned int v10; // r5

  if ( a2 )
  {
    NormalizationList__Lock();
    v7 = NormalizationList__Lookup((void *)a1);
    if ( !v7 )
    {
      v8 = NormalizationList__Lookup((void *)(a1 ^ 0x100));
      if ( v8 )
      {
        a4 = (unsigned __int16 *)v8[1];
        a3 = (unsigned int)v8[2];
      }
      else
      {
        v6 = ZwGetNlsSectionPtr();
        if ( v6 < 0 )
          goto LABEL_13;
      }
      v9 = NormalizationListEntry_Alloc();
      v10 = v9;
      if ( !v9 )
      {
        v6 = -1073741801;
LABEL_13:
        NormalizationList__Unlock();
        return v6;
      }
      v6 = Normalization__LoadTables(a1, a4, a3, v9 + 12);
      if ( v6 < 0 )
      {
        ExFreePoolWithTag(v10);
        goto LABEL_13;
      }
      *(_DWORD *)(v10 + 8) = a1;
      NormalizationList__InsertTail(v10);
      v7 = (void **)(v10 + 12);
    }
    NormalizationList__Unlock();
    *a2 = v7;
    return 0;
  }
  return -1073741584;
}
