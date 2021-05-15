// CmpQueryKeyDataFromCache 
 
int __fastcall CmpQueryKeyDataFromCache(int a1, int a2, int *a3, unsigned int a4, _DWORD *a5, int a6)
{
  int v9; // r2
  int v10; // r4
  int v11; // r3
  int v12; // r10
  int v13; // r2
  int v14; // r0
  _DWORD *v15; // r8
  int v16; // r1
  int v17; // r3
  int v18; // r0
  int v20; // [sp+8h] [bp-48h]
  int v21; // [sp+Ch] [bp-44h] BYREF
  int v22; // [sp+10h] [bp-40h]
  int v23; // [sp+14h] [bp-3Ch] BYREF
  int v24; // [sp+18h] [bp-38h]
  int v25; // [sp+1Ch] [bp-34h] BYREF
  int v26; // [sp+20h] [bp-30h] BYREF
  int v27; // [sp+24h] [bp-2Ch] BYREF
  int v28; // [sp+28h] [bp-28h]
  int v29; // [sp+2Ch] [bp-24h]

  v21 = -1;
  v9 = *(_DWORD *)(a1 + 44);
  if ( !v9 )
    return -1073741670;
  if ( (*(_DWORD *)v9 & 1) != 0 )
    v11 = (unsigned __int16)(2 * *(_WORD *)(v9 + 12));
  else
    v11 = *(unsigned __int16 *)(v9 + 12);
  v20 = v11;
  if ( a2 != 4 )
    return -1073741811;
  v10 = CmGetVisibleMaxNameLenAndClassLen(a1, 0, a6, &v25, 0);
  if ( v10 >= 0 )
  {
    v10 = CmGetVisibleMaxValueNameLenAndDataLen(a1, 0, a6, &v26, &v27);
    if ( v10 >= 0 )
    {
      *a5 = 40;
      if ( a4 >= 0x28 )
      {
        v23 = 0;
        v12 = *(_DWORD *)(a1 + 88);
        v28 = v12;
        v13 = *(_DWORD *)(a1 + 92);
        v24 = v13;
        v29 = v13;
        if ( a6 )
        {
          while ( 1 )
          {
            v14 = CmListGetPrevElement(a1 + 108, &v23);
            v15 = (_DWORD *)v14;
            if ( !v14 )
              break;
            if ( CmEqualTrans(*(_DWORD *)(v14 + 28), a6) && v15[9] == 8 )
            {
              v12 = v15[12];
              v28 = v12;
              v13 = v15[13];
              v29 = v13;
              goto LABEL_19;
            }
          }
          v13 = v24;
        }
LABEL_19:
        *a3 = v12;
        a3[1] = v13;
        a3[2] = 0;
        a3[8] = v20;
        a3[5] = CmGetVisibleValueCount(a1, 0, a6);
        a3[4] = v25;
        a3[6] = v26;
        a3[7] = v27;
        v16 = *(_DWORD *)(a1 + 4);
        if ( (v16 & 0x40) != 0 || *(_DWORD *)(a1 + 108) != a1 + 108 )
        {
          v18 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(*(_DWORD *)(a1 + 20) + 4))(
                  *(_DWORD *)(a1 + 20),
                  *(_DWORD *)(a1 + 24),
                  &v21);
          if ( v18 )
          {
            a3[3] = CmGetVisibleSubkeyCount(a1, v18, a6);
            (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(a1 + 20) + 8))(*(_DWORD *)(a1 + 20), &v21);
          }
          else
          {
            v10 = -1073741670;
            v22 = -1073741670;
          }
        }
        else
        {
          v17 = 1;
          if ( (v16 & 1) != 0 )
          {
            a3[3] = 0;
          }
          else
          {
            if ( (v16 & 2) == 0 )
            {
              if ( (v16 & 4) != 0 )
                v17 = **(_DWORD **)(a1 + 60);
              else
                v17 = *(_DWORD *)(a1 + 60);
            }
            a3[3] = v17;
          }
        }
      }
      else
      {
        v10 = -1073741789;
        v22 = -1073741789;
      }
    }
  }
  return v10;
}
