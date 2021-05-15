// CmpFindControlSet 
 
int __fastcall CmpFindControlSet(int a1, int a2, int a3, _BYTE *a4)
{
  int (__fastcall *v5)(int, int, int *); // r4
  int v7; // r5
  int v10; // r4
  int v11; // r8
  int v12; // r4
  int v13; // r3
  int v14; // r4
  int v15; // r0
  int v17; // r0
  int v18; // r3
  int v19; // r4
  int v20; // r0
  _DWORD *v21; // r9
  unsigned __int16 v22; // r0
  bool v23; // nf
  int v24; // r0
  int v25; // r0
  int v26; // r7
  int v27; // r4
  int v28; // r3
  int v29; // r4
  int v30; // r0
  _DWORD *v31; // r0
  int *v32; // r1
  int v33; // [sp+8h] [bp-1D0h] BYREF
  int v34; // [sp+Ch] [bp-1CCh] BYREF
  _DWORD v35[2]; // [sp+10h] [bp-1C8h] BYREF
  unsigned __int16 v36[2]; // [sp+18h] [bp-1C0h] BYREF
  char *v37; // [sp+1Ch] [bp-1BCh]
  int v38[2]; // [sp+20h] [bp-1B8h] BYREF
  _DWORD v39[2]; // [sp+28h] [bp-1B0h] BYREF
  int v40[2]; // [sp+30h] [bp-1A8h] BYREF
  char v41[128]; // [sp+38h] [bp-1A0h] BYREF
  char v42; // [sp+B8h] [bp-120h] BYREF

  v5 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
  v7 = -1;
  v34 = -1;
  v35[0] = -1;
  v38[1] = -1;
  v39[0] = -1;
  v33 = -1;
  v10 = v5(a1, a2, &v33);
  if ( v10 )
  {
    RtlInitUnicodeString((unsigned int)v36, L"select");
    CmpFindSubKeyByNameWithStatus(a1, v10, (int)v36, v38);
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v33);
    v11 = v38[0];
    if ( v38[0] != -1 )
    {
      v12 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v38[0], &v33);
      if ( v12 )
      {
        RtlInitUnicodeString((unsigned int)v36, L"AutoSelect");
        v14 = CmpFindValueByName(a1, v12, (int)v36, v13);
        v15 = (*(int (__fastcall **)(int, int *))(a1 + 8))(a1, &v33);
        if ( v14 != -1 )
          return sub_80C00C(v15);
        *a4 = 1;
        v17 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v11, &v33);
        if ( v17 )
        {
          v19 = CmpFindValueByName(a1, v17, a3, v18);
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v33);
          if ( v19 != -1 )
          {
            v20 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v19, &v34);
            if ( v20 )
            {
              if ( *(_DWORD *)(v20 + 12) != 4 )
              {
                v32 = &v34;
                goto LABEL_23;
              }
              v21 = (_DWORD *)CmpValueToData(a1, v19, v20, v38, v35);
              (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v34);
              if ( v21 )
              {
                sprintf_s((int)v41, 128, (int)"ControlSet%03d", *v21);
                v22 = (unsigned __int16)strlen((unsigned int)v41);
                v40[1] = (int)v41;
                v36[1] = 256;
                v37 = &v42;
                HIWORD(v40[0]) = v22;
                LOWORD(v40[0]) = v22;
                v36[0] = 0;
                v23 = RtlAnsiStringToUnicodeString(v36, (unsigned __int16 *)v40, 0, 0) < 0;
                v24 = a1;
                if ( !v23 )
                {
                  v25 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, a2, &v33);
                  if ( !v25 )
                    goto LABEL_22;
                  CmpFindSubKeyByNameWithStatus(a1, v25, (int)v36, v40);
                  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v33);
                  v26 = v40[0];
                  v24 = a1;
                  if ( v40[0] != -1 )
                  {
                    v27 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v11, &v33);
                    if ( v27 )
                    {
                      RtlInitUnicodeString((unsigned int)v36, L"Current");
                      v29 = CmpFindValueByName(a1, v27, (int)v36, v28);
                      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v33);
                      if ( v29 == -1 )
                      {
LABEL_21:
                        v7 = v26;
                        goto LABEL_22;
                      }
                      v30 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v29, &v34);
                      if ( v30 )
                      {
                        if ( *(_DWORD *)(v30 + 12) != 4 )
                        {
LABEL_20:
                          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v34);
                          goto LABEL_21;
                        }
                        v31 = (_DWORD *)CmpValueToData(a1, v29, v30, v38, v39);
                        if ( v31 )
                        {
                          *v31 = *v21;
                          (*(void (__fastcall **)(int, _DWORD *))(a1 + 8))(a1, v39);
                          goto LABEL_20;
                        }
                      }
                    }
LABEL_22:
                    v32 = v35;
LABEL_23:
                    v24 = a1;
LABEL_24:
                    (*(void (__fastcall **)(int, int *))(a1 + 8))(v24, v32);
                    return v7;
                  }
                }
                v32 = v35;
                goto LABEL_24;
              }
            }
          }
        }
      }
    }
  }
  return v7;
}
