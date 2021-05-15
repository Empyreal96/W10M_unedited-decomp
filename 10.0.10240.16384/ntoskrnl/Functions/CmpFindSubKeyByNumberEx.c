// CmpFindSubKeyByNumberEx 
 
int __fastcall CmpFindSubKeyByNumberEx(int a1, int a2, unsigned int a3, int *a4, int a5, int a6, int a7, int a8)
{
  int (__fastcall *v9)(int, int, int *); // r4
  int v10; // r7
  unsigned int *v12; // r9
  _DWORD *v13; // r0
  _DWORD *v14; // r6
  int v16; // r1
  unsigned int v17; // r2
  unsigned int v18; // r3
  int v19; // r2
  int v20; // r1
  int v21; // r3
  void (__fastcall *v22)(int, int *); // r3
  unsigned int v23; // r2
  int v24; // r7
  bool v25; // cf
  int (__fastcall *v26)(int, _DWORD *, int *); // r3
  unsigned __int16 *v27; // r0
  int v28; // r3
  int v29; // r0
  int *v30; // r1
  unsigned __int16 *v31; // r0
  int v32; // r3
  void (__fastcall *v33)(int, int *); // r3
  bool v34; // zf
  int v35; // r0
  int v36; // r2
  int v37; // [sp+Ch] [bp-4Ch]
  int v38; // [sp+10h] [bp-48h]
  int v39; // [sp+14h] [bp-44h] BYREF
  int v40; // [sp+18h] [bp-40h]
  unsigned int v41; // [sp+1Ch] [bp-3Ch]
  unsigned int v42; // [sp+20h] [bp-38h]
  int v43; // [sp+24h] [bp-34h]
  int v44; // [sp+28h] [bp-30h] BYREF
  _DWORD *v45; // [sp+2Ch] [bp-2Ch]
  int v46; // [sp+30h] [bp-28h] BYREF
  int v47[9]; // [sp+34h] [bp-24h] BYREF

  v9 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
  v10 = 0;
  v42 = a3;
  v39 = -1;
  v12 = 0;
  v13 = (_DWORD *)v9(a1, a2, &v39);
  v14 = v13;
  if ( v13 )
  {
    *a4 = -1;
    if ( a8 )
      return sub_804968();
    if ( !a5 || *(_DWORD *)(a5 + 108) == a5 + 108 )
    {
      v10 = CmpFindSubKeyByNumber(a1, v13, v42, a4);
LABEL_6:
      if ( v12 )
        CmpDelayDerefKeyControlBlock(v12, v16, v17, v18);
      if ( v14 )
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v39);
      return v10;
    }
    v19 = v13[5];
    v20 = -1;
    v44 = -1;
    v46 = -1;
    v47[0] = v19;
    v37 = 0;
    if ( v19 )
    {
      v43 = v13[7];
      v20 = -1;
    }
    else
    {
      v43 = -1;
    }
    v21 = v13[6];
    if ( v21 )
      v20 = v13[8];
    v41 = v21 + v19;
    v22 = *(void (__fastcall **)(int, int *))(a1 + 8);
    v45 = (_DWORD *)v20;
    v22(a1, &v39);
    v17 = v41;
    v18 = 0;
    v14 = 0;
    v38 = 0;
    if ( v41 )
    {
      v23 = v47[0];
      v24 = -v47[0];
      v40 = -v47[0];
      while ( 1 )
      {
        v25 = v18 >= v23;
        v26 = *(int (__fastcall **)(int, _DWORD *, int *))(a1 + 4);
        if ( v25 )
        {
          v31 = (unsigned __int16 *)v26(a1, v45, &v46);
          if ( !v31 )
            return -1073741670;
          v29 = CmpDoFindSubKeyByNumber(a1, v31, v24, v32);
          v30 = &v46;
        }
        else
        {
          v27 = (unsigned __int16 *)v26(a1, (_DWORD *)v43, &v44);
          if ( !v27 )
            return -1073741670;
          v29 = CmpDoFindSubKeyByNumber(a1, v27, v38, v28);
          v30 = &v44;
        }
        v33 = *(void (__fastcall **)(int, int *))(a1 + 8);
        *a4 = v29;
        v33(a1, v30);
        if ( *a4 == -1 )
          return -1073741670;
        v10 = CmpFindSubkeyInHashByChildCell(a5, a6, a1);
        if ( v10 < 0 )
          return v10;
        v12 = 0;
        if ( ++v37 == v42 + 1 )
          break;
        v17 = v41;
        v18 = v38 + 1;
        v16 = v40 + 1;
        v38 = v18;
        ++v40;
        v34 = v18 == v41;
        if ( v18 >= v41 )
          goto LABEL_32;
        v23 = v47[0];
        v24 = v16;
      }
      v18 = v38;
      v17 = v41;
    }
    v34 = v18 == v17;
LABEL_32:
    if ( !v34 )
      goto LABEL_6;
    v47[0] = 0;
    *a4 = -1;
    while ( 1 )
    {
      v35 = CmListGetNextElement(a5 + 108, v47, 16);
      v18 = v35;
      v45 = (_DWORD *)v35;
      if ( !v35 )
        goto LABEL_6;
      if ( CmEqualTrans(*(_DWORD *)(v35 + 28), a7) )
      {
        v36 = v45[9];
        if ( v36 == 1 )
        {
          v12 = (unsigned int *)v45[12];
        }
        else
        {
          if ( v36 != 10 )
            goto LABEL_45;
          v12 = (unsigned int *)v45[13];
        }
        if ( CmRmIsKCBVisible((int)v12, a7, v36) && !CmRmIsKCBDeleted((int)v12, a7) )
        {
          if ( v37 == v42 )
          {
            *a4 = v12[6];
            CmpReferenceKeyControlBlock(v12);
            goto LABEL_6;
          }
          ++v37;
        }
      }
LABEL_45:
      v12 = 0;
    }
  }
  return -1073741670;
}
