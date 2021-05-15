// SepAppendAceToTokenObjectAcl 
 
int __fastcall SepAppendAceToTokenObjectAcl(int a1, int a2, unsigned __int16 *a3, int a4, int a5, int a6)
{
  int v7; // r5
  unsigned int v8; // r4
  int v9; // r3
  unsigned __int8 *v10; // r6
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  unsigned int v15; // r7
  int v16; // r0
  int v17; // r10
  int v18; // r5
  int v19; // r0
  unsigned int v20; // r8
  char v22[4]; // [sp+8h] [bp-60h] BYREF
  unsigned int v23; // [sp+Ch] [bp-5Ch] BYREF
  int v24; // [sp+10h] [bp-58h] BYREF
  int v25; // [sp+14h] [bp-54h]
  int v26; // [sp+18h] [bp-50h]
  char v27[24]; // [sp+20h] [bp-48h] BYREF
  char v28[4]; // [sp+38h] [bp-30h] BYREF
  int v29; // [sp+3Ch] [bp-2Ch]

  v25 = a1;
  v26 = a2;
  v23 = 0;
  v24 = 0;
  v22[0] = 0;
  v7 = ObpGetObjectSecurity(a1, &v23, v22, 0);
  v8 = v23;
  if ( v7 >= 0 )
  {
    if ( !v23 )
      return v7;
    if ( (*(_WORD *)(v23 + 2) & 4) != 0 )
    {
      if ( (*(_WORD *)(v23 + 2) & 0x8000) != 0 )
      {
        v9 = *(_DWORD *)(v23 + 16);
        if ( !v9 )
          goto LABEL_20;
        v10 = (unsigned __int8 *)(v9 + v23);
      }
      else
      {
        v10 = *(unsigned __int8 **)(v23 + 16);
      }
      if ( v10 )
      {
        if ( !RtlFindAceBySid((int)v10, a3, 0) )
        {
          v11 = RtlQueryInformationAcl(v10, v28, 12, 2);
          v7 = v11;
          if ( v11 >= 0 )
          {
            v15 = *v10;
            if ( v15 < 2 || v15 > 4 )
              return sub_7C5244(v11, v12, v13, v14, a5, a6);
            v16 = RtlLengthSid((int)a3);
            v17 = v29;
            v18 = v16 + v29 + 11;
            v19 = ExAllocatePoolWithTag(1, v18 & 0xFFFFFFFC, 1665230163);
            v20 = v19;
            if ( v19 )
            {
              v7 = RtlCreateAcl(v19, v18 & 0xFFFFFFFC, v15);
              if ( v7 >= 0 )
              {
                v7 = RtlGetAce(v10, 0, (int)&v24);
                if ( v7 >= 0 )
                {
                  v7 = RtlAddAce(v20, v15, 0, v24, v17 - 8);
                  if ( v7 >= 0 )
                  {
                    v7 = RtlpAddKnownAce(v20, v15, 0, v26, a3, 0);
                    if ( v7 >= 0 )
                    {
                      memset(v27, 0, 20);
                      v27[0] = 1;
                      v7 = RtlSetDaclSecurityDescriptor(v27, 1, v20, 0);
                      if ( v7 >= 0 )
                        v7 = ObSetSecurityObjectByPointer(v25, 4, v27);
                    }
                  }
                }
              }
              ExFreePoolWithTag(v20);
            }
            else
            {
              v7 = -1073741670;
            }
          }
        }
      }
    }
  }
LABEL_20:
  if ( !v8 )
    return v7;
  if ( v22[0] )
  {
    ExFreePoolWithTag(v8);
    return v7;
  }
  ObDereferenceSecurityDescriptor(v8, 1);
  return v7;
}
