// PspReadUserQuotaLimits 
 
int __fastcall PspReadUserQuotaLimits(_BYTE *a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // r10
  unsigned int v4; // r4
  int v6; // r4
  _DWORD *v8; // r5
  char *v9; // r10
  unsigned int v10; // r6
  int v11; // r7
  int *v12; // r9
  int v13; // r0
  int v14; // r3
  unsigned int v15; // [sp+10h] [bp-70h]
  _DWORD v18[18]; // [sp+38h] [bp-48h] BYREF

  v3 = a3;
  *a2 = 1;
  v4 = PspQuotaDatabaseKey;
  v15 = PspQuotaDatabaseKey;
  if ( PspQuotaDatabaseKey )
  {
LABEL_2:
    if ( v4 == 1 )
      goto LABEL_6;
    v6 = RtlConvertSidToUnicodeString((unsigned __int16 *)v18, a1, 1);
    if ( v6 >= 0 )
    {
      v6 = ZwOpenKey();
      RtlFreeAnsiString(v18);
      if ( v6 >= 0 )
      {
        v8 = v3;
        v9 = (char *)(&PspDefaultResourceLimits - (_UNKNOWN *)v3);
        v10 = 0;
        v11 = 0;
        v12 = &PspDefaultResourceNames;
        do
        {
          v13 = ZwQueryValueKey();
          v6 = v13;
          if ( v13 < 0 && v13 != -1073741772 )
          {
            ZwClose();
            return v6;
          }
          if ( v13 != -1073741772 && v18[6] == 4 && v18[5] == 4 )
          {
            v14 = v18[7];
          }
          else
          {
            v14 = *(_DWORD *)((char *)v8 + (_DWORD)v9);
            ++v10;
          }
          *v8 = v14;
          ++v11;
          ++v8;
          v12 += 2;
        }
        while ( v11 < 4 );
        ZwClose();
        if ( v10 < 4 )
        {
          v6 = PspSanitizeResourceLimits(a3, 0);
          if ( v6 < 0 )
            return v6;
          *a2 = 0;
        }
        goto LABEL_6;
      }
      if ( v6 == -1073741772 )
LABEL_6:
        v6 = 0;
    }
    return v6;
  }
  if ( ZwCreateKey() >= 0 )
  {
    __dmb(0xBu);
    do
      v4 = __ldrex((unsigned int *)&PspQuotaDatabaseKey);
    while ( !v4 && __strex(v15, (unsigned int *)&PspQuotaDatabaseKey) );
    __dmb(0xBu);
    if ( v4 )
    {
      if ( v15 != 1 )
        ZwClose();
    }
    else
    {
      v4 = v15;
    }
    goto LABEL_2;
  }
  return sub_7E8564();
}
