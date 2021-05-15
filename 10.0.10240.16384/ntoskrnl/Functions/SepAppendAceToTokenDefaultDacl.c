// SepAppendAceToTokenDefaultDacl 
 
int __fastcall SepAppendAceToTokenDefaultDacl(int a1, int a2)
{
  int v2; // r6
  int v6; // r5
  int v7; // r4
  unsigned int v8; // r9
  int v9; // r0
  int v10; // r5
  int v11; // [sp+8h] [bp-30h] BYREF
  int v12; // [sp+Ch] [bp-2Ch] BYREF
  char v13[4]; // [sp+10h] [bp-28h] BYREF
  int v14; // [sp+14h] [bp-24h]

  v2 = *(_DWORD *)(a1 + 164);
  v12 = 0;
  if ( !v2 )
    return sub_5154A0();
  if ( RtlFindAceBySid(v2, a2, 0) )
    return 0;
  v6 = *(unsigned __int16 *)(v2 + 2);
  v7 = RtlQueryInformationAcl(v2, &v11, 4, 1);
  if ( v7 >= 0 )
  {
    v7 = RtlQueryInformationAcl(v2, v13, 12, 2);
    if ( v7 >= 0 )
    {
      v8 = (v6 + 4 * *(unsigned __int8 *)(a2 + 1) + 19) & 0xFFFFFFFC;
      v9 = ExAllocatePoolWithTag(1, v8, 1665230163);
      v10 = v9;
      if ( v9 )
      {
        v7 = RtlCreateAcl(v9, v8, v11);
        if ( v7 >= 0 )
        {
          v7 = RtlGetAce(v2, 0, &v12);
          if ( v7 >= 0 )
          {
            v7 = RtlAddAce(v10, v11, 0, v12, v14 - 8);
            if ( v7 >= 0 )
            {
              v7 = RtlAddAccessAllowedAce(v10, v11, 0x10000000, a2);
              if ( v7 >= 0 )
              {
                v7 = SepExpandDynamic(a1, (v8 + 4 * *(unsigned __int8 *)(*(_DWORD *)(a1 + 156) + 1) + 11) & 0xFFFFFFFC);
                if ( v7 >= 0 )
                {
                  SepFreeDefaultDacl(a1);
                  SepAppendDefaultDacl(a1, v10);
                }
              }
            }
          }
        }
        if ( v10 )
          ExFreePoolWithTag(v10, 0);
      }
      else
      {
        v7 = -1073741670;
      }
    }
  }
  return v7;
}
