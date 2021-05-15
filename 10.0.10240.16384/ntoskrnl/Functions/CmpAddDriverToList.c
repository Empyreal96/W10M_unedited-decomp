// CmpAddDriverToList 
 
int __fastcall CmpAddDriverToList(int a1, int a2, int a3)
{
  int v4; // r0
  unsigned __int16 *v5; // r8
  _BYTE *v6; // r0
  _BYTE *v7; // r5
  __int16 v8; // r2
  int v9; // r8
  int v10; // r0
  int v11; // r6
  int v12; // r0
  int v13; // r9
  unsigned int v14; // r8
  int v15; // r0
  int v16; // r6
  void (__fastcall *v17)(int, int *); // r3
  int (*v18)(void); // r3
  int v19; // r3
  __int16 v20; // r0
  int (*v21)(void); // r3
  int v22; // r2
  int v23; // r3
  int v25; // r2
  int v26; // r3
  __int16 v27; // [sp+8h] [bp-68h] BYREF
  int v28; // [sp+Ch] [bp-64h] BYREF
  unsigned int v29; // [sp+10h] [bp-60h] BYREF
  int v30; // [sp+14h] [bp-5Ch]
  int v31[4]; // [sp+18h] [bp-58h] BYREF
  int v32; // [sp+28h] [bp-48h] BYREF
  int v33; // [sp+2Ch] [bp-44h]
  int v34; // [sp+30h] [bp-40h]
  int v35; // [sp+38h] [bp-38h] BYREF
  int v36; // [sp+40h] [bp-30h] BYREF
  int v37; // [sp+44h] [bp-2Ch]
  unsigned __int16 v38; // [sp+48h] [bp-28h] BYREF
  __int16 v39; // [sp+4Ah] [bp-26h]

  v31[3] = -1;
  v32 = -1;
  v31[1] = -1;
  v31[2] = -1;
  v31[0] = -1;
  v28 = -1;
  v27 = 0;
  HIWORD(v36) = 0;
  v39 = 0;
  v33 = 0;
  v34 = a3;
  v4 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, a2, &v32);
  v30 = v4;
  if ( !v4 )
    return v33;
  v5 = (unsigned __int16 *)CmpGetNodeName(a1, v4, &v27);
  if ( !v5 )
  {
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v32);
    return v33;
  }
  if ( RtlInitUnicodeStringEx((int)&v35, v5) < 0
    || (v6 = (_BYTE *)(*(int (__fastcall **)(int, _DWORD, int))(a1 + 12))(68, 0, 540101955), (v7 = v6) == 0) )
  {
    JUMPOUT(0x9681AE);
  }
  memset(v6, 0, 68);
  v8 = v27;
  *((_DWORD *)v7 + 5) = 0;
  *((_DWORD *)v7 + 3) = 0;
  *((_DWORD *)v7 + 14) = v5;
  *((_WORD *)v7 + 26) = v8 - 2;
  v9 = v30;
  v35 = 0;
  *((_WORD *)v7 + 27) = v8;
  v10 = CmpFindValueByName(a1, v9, (int)&CmpImagePathString, (int)&CmpTagString);
  v11 = v10;
  if ( v10 != -1 )
  {
    v12 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v10, &v28);
    if ( v12 )
    {
      v13 = CmpValueToData(a1, v11, v12, &v29, (int)v31);
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v28);
      if ( v13 )
      {
        v14 = v29;
        v15 = (*(int (__fastcall **)(unsigned int, _DWORD, int))(a1 + 12))(v29, 0, 540233027);
        v16 = v15;
        if ( !v15 )
          JUMPOUT(0x968164);
        memmove(v15, v13, v14);
        v17 = *(void (__fastcall **)(int, int *))(a1 + 8);
        LOWORD(v36) = v14;
        HIWORD(v36) = v14;
        v17(a1, v31);
LABEL_10:
        v38 = 0;
        v18 = *(int (**)(void))(a1 + 12);
        v39 = *((_WORD *)v7 + 26) + 104;
        if ( v18() )
        {
          if ( RtlAppendUnicodeStringToString(&v38, (unsigned __int16 *)&CmpServicesKeyName) >= 0
            && RtlAppendUnicodeStringToString(&v38, (unsigned __int16 *)v7 + 26) >= 0 )
          {
            if ( !*((_DWORD *)v7 + 3) )
            {
              v19 = v36;
              *((_DWORD *)v7 + 3) = v16;
              *((_DWORD *)v7 + 2) = v19;
              if ( !*((_DWORD *)v7 + 5) )
                JUMPOUT(0x96817C);
              JUMPOUT(0x968176);
            }
            JUMPOUT(0x96816C);
          }
          JUMPOUT(0x9681A4);
        }
        JUMPOUT(0x9681B6);
      }
    }
LABEL_25:
    JUMPOUT(0x9681D2);
  }
  v20 = *((_WORD *)v7 + 26) + 46;
  LOWORD(v36) = 0;
  v21 = *(int (**)(void))(a1 + 12);
  HIWORD(v36) = v20;
  v37 = v21();
  if ( !v37 )
    goto LABEL_25;
  if ( RtlAppendUnicodeToString((unsigned __int16 *)&v36, (int)L"System32\\Drivers\\", v22, v23) >= 0
    && RtlAppendUnicodeStringToString((unsigned __int16 *)&v36, (unsigned __int16 *)v7 + 26) >= 0
    && RtlAppendUnicodeToString((unsigned __int16 *)&v36, (int)L".sys", v25, v26) >= 0 )
  {
    v16 = v37;
    goto LABEL_10;
  }
  return sub_96815C();
}
