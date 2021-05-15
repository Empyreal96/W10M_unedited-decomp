// RtlIsUntrustedObject 
 
int __fastcall RtlIsUntrustedObject(int a1, int a2, _BYTE *a3)
{
  char *v4; // r5
  int v7; // r9
  int v8; // r0
  int v9; // r4
  int v10; // r3
  char *v11; // r6
  int v12; // r0
  int v13; // r0
  unsigned int v14; // [sp+8h] [bp-90h] BYREF
  int v15; // [sp+Ch] [bp-8Ch] BYREF
  char v16[136]; // [sp+10h] [bp-88h] BYREF

  v4 = v16;
  *a3 = 1;
  if ( !a2 )
    return sub_51AA64();
  if ( a1 )
    return -1073741811;
  v7 = 0;
  v8 = ObQuerySecurityObject(a2, 16, v16, 104, &v14);
  v9 = v8;
  if ( v8 >= 0 )
    goto LABEL_5;
  if ( v8 == -1073741789 )
  {
    v13 = ExAllocatePoolWithQuotaTag(0x208u, v14, 1649439826);
    v4 = (char *)v13;
    if ( v13 )
    {
      v7 = 1;
      v9 = ObQuerySecurityObject(a2, 16, v13, 104, &v14);
      if ( v9 < 0 )
      {
LABEL_25:
        ExFreePoolWithTag(v4, 0);
        return v9;
      }
LABEL_5:
      if ( (*((_WORD *)v4 + 1) & 0x10) != 0 )
      {
        if ( (*((_WORD *)v4 + 1) & 0x8000) != 0 )
        {
          v10 = *((_DWORD *)v4 + 3);
          if ( !v10 )
            goto LABEL_12;
          v11 = &v4[v10];
        }
        else
        {
          v11 = (char *)*((_DWORD *)v4 + 3);
        }
        if ( v11 )
        {
          v15 = 0;
          while ( 1 )
          {
            v12 = RtlFindAceByType(v11, 17, &v15);
            if ( !v12 )
              break;
            if ( (*(_BYTE *)(v12 + 1) & 8) == 0 )
            {
              if ( !*(_BYTE *)(v12 + 9) || *(_DWORD *)(v12 + 4 * *(unsigned __int8 *)(v12 + 9) + 12) < 0x2000u )
                goto LABEL_13;
              break;
            }
          }
        }
      }
LABEL_12:
      *a3 = 0;
LABEL_13:
      if ( !v7 )
        return v9;
      goto LABEL_25;
    }
    v9 = -1073741801;
  }
  return v9;
}
