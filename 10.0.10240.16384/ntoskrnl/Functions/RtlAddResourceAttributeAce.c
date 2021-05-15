// RtlAddResourceAttributeAce 
 
int __fastcall RtlAddResourceAttributeAce(unsigned __int8 *a1, unsigned int a2, int a3, int a4, int a5, int a6, unsigned int *a7)
{
  char *v10; // r5
  int v11; // r4
  unsigned int v12; // r3
  unsigned int v13; // r10
  unsigned int v14; // r2
  unsigned int v15; // lr
  unsigned __int8 *v16; // r1
  unsigned int i; // r0
  int v18; // r8
  unsigned int v19; // r0
  char v20; // r3
  unsigned int v22; // [sp+0h] [bp-138h] BYREF
  int v23; // [sp+4h] [bp-134h]
  int v24; // [sp+8h] [bp-130h] BYREF
  int v25; // [sp+10h] [bp-128h] BYREF
  char v26; // [sp+14h] [bp-124h]
  char v27; // [sp+15h] [bp-123h]
  char v28; // [sp+18h] [bp-120h] BYREF
  char v29[255]; // [sp+19h] [bp-11Fh] BYREF

  v23 = a3;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 1;
  v28 = 0;
  v10 = 0;
  memset(v29, 0, sizeof(v29));
  v22 = 256;
  if ( !a7 )
    return -1073741811;
  *a7 = 0;
  if ( !a1 )
    return -1073741705;
  if ( !RtlValidSid((_BYTE *)a5) )
    return -1073741704;
  if ( memcmp(a5 + 2, (unsigned int)&v25, 6) )
    return -1073741811;
  if ( *(_BYTE *)(a5 + 1) == 1 && !*(_DWORD *)(a5 + 8) )
  {
    v12 = *a1;
    if ( v12 > 4 || a2 > 4 )
      return -1073741735;
    if ( v12 <= (unsigned __int8)a2 )
      v25 = (unsigned __int8)a2;
    else
      v25 = *a1;
    if ( (v23 & 0xFFFFFFE0) == 0 && !a4 && RtlpValidAttributeInfo(a6) && *(_DWORD *)(a6 + 4) == 1 )
    {
      v10 = &v28;
      v11 = RtlpConvertAbsoluteToRelativeSecurityAttribute(*(_DWORD *)(a6 + 8), &v28, &v22);
      if ( v11 == -1073741789 )
      {
        v10 = (char *)ExAllocatePoolWithQuotaTag(0x208u, v22, 1649439826);
        if ( !v10 )
          return -1073741801;
        v11 = RtlpConvertAbsoluteToRelativeSecurityAttribute(*(_DWORD *)(a6 + 8), v10, &v22);
      }
      if ( v11 >= 0 )
      {
        if ( RtlValidAcl(a1) && RtlFirstFreeAce((int)a1, &v24) )
        {
          v13 = v22;
          if ( v22 > 0xFFFF
            || (v14 = 4 * (*(unsigned __int8 *)(a5 + 1) + 4), v15 = (unsigned __int16)(v22 + v14), v15 < v14) )
          {
            v11 = -1073741675;
          }
          else
          {
            *a7 = 8;
            v16 = a1 + 8;
            for ( i = 0; i < *((unsigned __int16 *)a1 + 2); v16 += *((unsigned __int16 *)v16 + 1) )
            {
              ++i;
              *a7 += *((unsigned __int16 *)v16 + 1);
            }
            v18 = v24;
            v19 = v15 + *a7;
            *a7 = v19;
            if ( v18 && v15 + v18 <= (unsigned int)&a1[*((unsigned __int16 *)a1 + 1)] )
            {
              v20 = v23;
              *(_WORD *)(v18 + 2) = v15;
              *(_BYTE *)(v18 + 1) = v20;
              *(_BYTE *)v18 = 18;
              *(_DWORD *)(v18 + 4) = 0;
              RtlCopySid(4 * (*(unsigned __int8 *)(a5 + 1) + 2), v18 + 8, a5);
              memmove(v18 + 4 * (*(unsigned __int8 *)(a5 + 1) + 4), (int)v10, v13);
              ++*((_WORD *)a1 + 2);
              *a1 = v25;
            }
            else
            {
              v11 = -1073741671;
              *a7 = (v19 + 3) & 0xFFFFFFFC;
            }
          }
        }
        else
        {
          v11 = -1073741705;
        }
      }
      goto LABEL_38;
    }
    return -1073741811;
  }
  v11 = -1073741811;
LABEL_38:
  if ( v10 && v10 != &v28 )
    ExFreePoolWithTag((unsigned int)v10);
  return v11;
}
