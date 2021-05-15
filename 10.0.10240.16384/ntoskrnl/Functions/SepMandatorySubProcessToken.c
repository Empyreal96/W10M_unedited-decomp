// SepMandatorySubProcessToken 
 
int __fastcall SepMandatorySubProcessToken(int a1, _DWORD *a2, int a3, unsigned __int16 **a4)
{
  int v5; // r4
  int v6; // r6
  char *v7; // r7
  int v9; // r0
  char *v11; // r0
  int v12; // r0
  unsigned __int16 **v13; // r8
  int v14; // r0
  int v15; // r4
  unsigned __int16 **v16; // r0
  unsigned __int16 **v17; // r8
  int v18; // r2
  unsigned __int16 *v19; // r3
  unsigned int v20; // r3
  int v21; // r1
  int v22; // r0
  unsigned __int16 *v23; // r2
  _DWORD *v24; // r0
  unsigned __int16 **v25; // r1
  _DWORD *v26; // r8
  unsigned __int16 *v27; // lr
  unsigned int v28; // r4
  int v29; // r0
  int v30; // r2
  unsigned int v31; // r3
  int v32; // r3
  unsigned __int16 **v33; // r2
  unsigned int v34; // r3
  int v35; // [sp+8h] [bp-B8h]
  char v36[4]; // [sp+Ch] [bp-B4h] BYREF
  unsigned __int16 **v37; // [sp+10h] [bp-B0h]
  int v38; // [sp+14h] [bp-ACh] BYREF
  int v39; // [sp+18h] [bp-A8h] BYREF
  char v40[2]; // [sp+20h] [bp-A0h] BYREF
  __int16 v41; // [sp+22h] [bp-9Eh]
  char *v42; // [sp+2Ch] [bp-94h]

  *a4 = 0;
  v5 = *(_DWORD *)(a3 + 736);
  v6 = 0;
  v7 = 0;
  v37 = a4;
  v35 = 0;
  v39 = 0;
  v36[0] = 0;
  if ( (v5 & 1) != 0 || (a2[47] & 2) == 0 )
    goto LABEL_14;
  v6 = PsReferenceProcessFilePointer(a3, &v39);
  if ( v6 < 0 || (v38 = 128, v7 = v40, v6 = RtlCreateSecurityDescriptor(v40, 1), v6 < 0) )
  {
    v14 = v39;
    goto LABEL_18;
  }
  v35 = v39;
  v9 = ObQuerySecurityObject(v39, 16, v40, 128, &v38);
  v6 = v9;
  if ( v9 == -1073741789 )
    return sub_52AA10();
  if ( v9 < 0 || !v40 )
  {
    v6 = 0;
    goto LABEL_14;
  }
  if ( (v41 & 0x10) == 0 )
    goto LABEL_24;
  if ( (v41 & 0x8000) == 0 )
  {
    v11 = v42;
    goto LABEL_13;
  }
  if ( v42 )
    v11 = &v40[(_DWORD)v42];
  else
LABEL_24:
    v11 = 0;
LABEL_13:
  v12 = RtlFindAceByType(v11, 17, 0);
  if ( !v12 )
    goto LABEL_14;
  v15 = v12 + 8;
  v16 = (unsigned __int16 **)SepLocateTokenIntegrity((int)a2);
  v17 = v16;
  if ( !v16 )
    goto LABEL_14;
  v6 = RtlSidDominates(*v16, (unsigned __int16 *)v15, v36);
  if ( v6 >= 0 )
  {
    if ( v36[0] )
    {
      if ( *(_BYTE *)(v15 + 1) )
        v18 = *(_DWORD *)(v15 + 4 * *(unsigned __int8 *)(v15 + 1) + 4);
      else
        v18 = 0;
      *((_DWORD *)*v17 + 2) = v18;
      v19 = *v17;
      v13 = v37;
      *v37 = v19;
      if ( *(_BYTE *)(v15 + 1) && *(_DWORD *)(v15 + 4 * *(unsigned __int8 *)(v15 + 1) + 4) >= 0x2000u )
        v20 = a2[44] | 0x2000;
      else
        v20 = a2[44] & 0xFFFFDFFF;
      a2[44] = v20;
LABEL_15:
      if ( a1 )
      {
        if ( (*(_DWORD *)(a1 + 176) & 0x1000) != 0 && !SeTokenIsAdmin(a1) )
        {
          a2[44] &= 0xFFFFEFFF;
          v21 = SepLocateTokenIntegrity((int)a2);
          if ( v21 )
          {
            v22 = *(_DWORD *)(a2[48] + 32);
            if ( v22 )
            {
              v24 = (_DWORD *)SepLocateTokenIntegrity(v22);
              v26 = v24;
              if ( v24 )
              {
                v27 = *v25;
                v28 = *((_BYTE *)*v25 + 1) ? *(_DWORD *)&v27[2 * *((unsigned __int8 *)*v25 + 1) + 2] : 0;
                v29 = *v24;
                v30 = *(unsigned __int8 *)(*v26 + 1);
                v31 = *(_BYTE *)(*v26 + 1) ? *(_DWORD *)(v29 + 4 * v30 + 4) : 0;
                if ( v28 > v31 )
                {
                  if ( *(_BYTE *)(*v26 + 1) )
                    v32 = *(_DWORD *)(v29 + 4 * v30 + 4);
                  else
                    v32 = 0;
                  v33 = v37;
                  *((_DWORD *)v27 + 2) = v32;
                  *v33 = *v25;
                  if ( *(_BYTE *)(*v26 + 1) && *(_DWORD *)(*v26 + 4 * *(unsigned __int8 *)(*v26 + 1) + 4) >= 0x2000u )
                    v34 = a2[44] | 0x2000;
                  else
                    v34 = a2[44] & 0xFFFFDFFF;
                  a2[44] = v34;
                }
              }
            }
            else
            {
              v23 = *(unsigned __int16 **)v21;
              if ( *(_BYTE *)(*(_DWORD *)v21 + 1) )
              {
                v14 = v35;
                if ( *(_DWORD *)&v23[2 * *(unsigned __int8 *)(*(_DWORD *)v21 + 1) + 2] > 0x2000u )
                {
                  *((_DWORD *)v23 + 2) = 0x2000;
                  *v13 = *(unsigned __int16 **)v21;
                }
                goto LABEL_18;
              }
            }
          }
        }
      }
      goto LABEL_17;
    }
LABEL_14:
    v13 = v37;
    goto LABEL_15;
  }
LABEL_17:
  v14 = v35;
LABEL_18:
  if ( v14 )
    ObfDereferenceObjectWithTag(v14);
  if ( v7 )
  {
    if ( v7 != v40 )
      ExFreePoolWithTag(v7, 0);
  }
  return v6;
}
