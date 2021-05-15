// IopGraftName 
 
int __fastcall IopGraftName(_DWORD *a1, int a2, int *a3)
{
  int v6; // r4
  int v7; // r0
  int v8; // lr
  int result; // r0
  int v10; // r3
  int v11; // r2
  int v12; // r3
  int v13; // r9
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int i; // r3
  unsigned int v18; // r3
  int v19; // r2
  unsigned int v20; // r6
  unsigned int v21; // r6
  int v22; // r4
  unsigned int v23; // r4
  unsigned int v24; // r3
  unsigned __int16 *v25; // r4
  unsigned int v26; // r8
  unsigned int *v27; // r9
  int v28; // r4
  _WORD *v29; // r2
  int v30; // r9
  int v31; // r8
  int v32; // r3
  int v33; // r4
  int j; // r0
  int v35; // r3
  int v36; // [sp+18h] [bp-58h] BYREF
  _DWORD *v37; // [sp+1Ch] [bp-54h]
  unsigned int v38; // [sp+20h] [bp-50h]
  unsigned int v39; // [sp+24h] [bp-4Ch]
  unsigned __int16 *v40; // [sp+28h] [bp-48h]
  int v41; // [sp+2Ch] [bp-44h]
  _DWORD *v42; // [sp+30h] [bp-40h]
  int v43; // [sp+34h] [bp-3Ch] BYREF
  unsigned __int16 *v44; // [sp+38h] [bp-38h]
  unsigned int v45; // [sp+3Ch] [bp-34h] BYREF
  int v46; // [sp+40h] [bp-30h] BYREF
  unsigned int *v47; // [sp+44h] [bp-2Ch]
  int v48; // [sp+48h] [bp-28h]
  int v49; // [sp+4Ch] [bp-24h]

  v38 = 0;
  v39 = 0;
  v42 = *(_DWORD **)(a2 + 32);
  v40 = 0;
  v41 = 0;
  v36 = 0;
  v37 = 0;
  v43 = 0;
  v44 = 0;
  v47 = 0;
  v6 = IoGetIrpExtraCreateParameter((int)a1, &v43);
  v7 = IopSymlinkGetECP(v43, (int)&v36);
  v8 = v36;
  *(_WORD *)(v36 + 2) |= 2u;
  if ( a1[6] != 260 )
    return sub_7F9D28(v7);
  v10 = a1[7];
  result = -1610612724;
  if ( v10 != -1610612733 && v10 != -1610612724 && v10 != -2147483623 )
    v6 = -1073741192;
  if ( !a1[21] )
    v6 = -1073741192;
  if ( !a3 )
    v6 = -1073741192;
  if ( *((unsigned __int16 *)a3 + 3) >= 0x4000u )
    v6 = -1073741192;
  if ( *((unsigned __int16 *)a3 + 2) >= 0x4000u )
    v6 = -1073741192;
  v11 = *a3;
  if ( *a3 != -1610612733 && v11 != -1610612724 && v11 != -2147483623 )
    v6 = -1073741192;
  if ( !*(_WORD *)(a2 + 48) )
  {
    v6 = -1073741192;
    goto LABEL_36;
  }
  if ( v6 >= 0 )
  {
    v12 = *((unsigned __int16 *)a3 + 4);
    v13 = *((unsigned __int16 *)a3 + 5);
    if ( v11 == -1610612733 )
    {
      v48 = (int)a3 + v12 + 16;
    }
    else
    {
      v48 = (int)a3 + v12 + 20;
      if ( (a3[4] & 1) != 0 )
      {
        v41 = 1;
        v49 = 256;
        if ( v42 )
        {
          result = IopGetFileObjectExtension((int)v42, 5, 0);
          if ( !result )
          {
            v22 = v49;
            v46 = -2147483643;
            while ( 1 )
            {
              result = ExAllocatePoolWithTag(1, v22, 1665560393);
              v40 = (unsigned __int16 *)result;
              v44 = (unsigned __int16 *)result;
              if ( !result )
              {
                v6 = -1073741670;
                goto LABEL_36;
              }
              memset((_BYTE *)result, 0, v22);
              result = ObQueryNameStringMode(*(_DWORD *)(a2 + 4), (int)v40, v22, &v45, 0);
              v6 = result;
              if ( result >= 0 )
                break;
              if ( result != v46 )
                goto LABEL_67;
              v22 = v45;
              if ( v45 >= 0xFFFF )
              {
                v6 = -1073741562;
                result = 0;
                goto LABEL_74;
              }
              ExFreePoolWithTag((unsigned int)v40);
            }
            v23 = 256;
            v38 = *(unsigned __int16 *)(a2 + 48) + *v40 - *((unsigned __int16 *)a3 + 3);
            while ( 1 )
            {
              result = ExAllocatePoolWithTag(1, v23, 1665560393);
              v37 = (_DWORD *)result;
              if ( !result )
              {
                v6 = -1073741670;
                goto LABEL_74;
              }
              v47 = (unsigned int *)result;
              memset((_BYTE *)result, 0, v23);
              result = IopGetFileInformation(v42, v23, 9, (int)v37, &v45);
              v6 = result;
              if ( result >= 0 )
                break;
              if ( result != v46 )
                goto LABEL_67;
              result = (int)v37;
              v23 = *v37 + 8;
              if ( v23 >= 0xFFFF )
              {
                v6 = -1073741562;
                goto LABEL_74;
              }
              ExFreePoolWithTag((unsigned int)v37);
            }
            result = v38;
            v24 = *v37 + v38;
            if ( v24 < v38 )
            {
              v6 = -1073741675;
            }
            else
            {
              v38 += *v37;
              if ( v24 < 0xFFFF )
                goto LABEL_67;
              v6 = -1073741562;
            }
LABEL_73:
            result = (int)v37;
LABEL_74:
            if ( v40 )
            {
              ExFreePoolWithTag((unsigned int)v40);
              result = (int)v37;
            }
            if ( result )
              result = ExFreePoolWithTag(result);
LABEL_30:
            if ( v6 >= 0 )
            {
              a1[6] = 260;
              return result;
            }
            goto LABEL_36;
          }
LABEL_67:
          v8 = v36;
        }
      }
    }
    if ( v6 >= 0 )
    {
      v14 = IopSymlinkGetRelatedMountPoint(v8, *((unsigned __int16 *)a3 + 3));
      if ( v14 )
      {
        v18 = *(unsigned __int16 *)(v14 + 12);
      }
      else
      {
        v16 = v36;
        for ( i = *(_DWORD *)(v36 + 8); i; i = *(_DWORD *)(i + 8) )
          v16 = i;
        v18 = *(unsigned __int16 *)(v16 + 12);
      }
      v19 = v41;
      if ( v41 )
      {
        if ( v38 > v18 )
          v18 = v38;
        v38 = v18 + 2;
      }
      result = v38;
      v20 = v15 + v13 + v38 + 4;
      if ( v20 >= 0xFFFF )
      {
        v6 = -1073741562;
      }
      else
      {
        result = ExAllocatePoolWithTag(1, v15 + v13 + v38 + 4, 1665560393);
        v39 = result;
        if ( !result )
        {
          v6 = -1073741670;
          goto LABEL_72;
        }
        result = (int)memset((_BYTE *)result, 0, v20);
        v19 = v41;
      }
      v21 = v20 - 2;
      if ( v6 < 0 )
        goto LABEL_72;
      if ( !v19 )
      {
        IopCopyOverNewPath(v39, v48, v13, a2, *((unsigned __int16 *)a3 + 3));
        if ( *a3 == -1610612733 )
          result = IopSymlinkRememberJunction(*((unsigned __int16 *)a3 + 3), a2, a1, v36);
        else
          result = IopSymlinkUpdateECP((int)a1, v36, 0, (unsigned __int16 *)(a2 + 48), 0, *(_WORD *)(v36 + 2) & 0xFFFE);
        v6 = result;
        goto LABEL_30;
      }
      v46 = 0;
      if ( !v42 || IopGetFileObjectExtension((int)v42, 5, 0) )
      {
        v33 = v36;
      }
      else
      {
        v25 = v44;
        v26 = v39;
        memmove(v39, *((_DWORD *)v44 + 1), *v44);
        v27 = v47;
        v28 = v26 + 2 * (*v25 >> 1);
        memmove(v28, (int)(v47 + 1), *v47);
        v29 = (_WORD *)(v28 + 2 * (*v27 >> 1));
        if ( **(_WORD **)(a2 + 52) != 92 && *(v29 - 1) != 92 )
        {
          *v29 = 92;
          LOWORD(v29) = (_WORD)v29 + 2;
        }
        v30 = (unsigned __int16)((_WORD)v29 - v26);
        IopSymlinkRemoveECP(v43, (int)&v36);
        v31 = v36;
        v32 = *(unsigned __int16 *)(v36 + 12) + v30 + 2;
        v6 = IopSymlinkAllocateAndAddECP((int)a1, &v46, (unsigned __int16)v32, v32);
        if ( v6 < 0 )
        {
          result = ExFreePoolWithTag(v39);
          goto LABEL_72;
        }
        v33 = v46;
        IopSymlinkInitializeSymlinkInfo(
          v46,
          *(_WORD *)(v31 + 12) + v30 + 22,
          *(_DWORD *)(v31 + 16),
          *(unsigned __int16 *)(v31 + 12),
          *(_WORD *)v31,
          v39,
          v30,
          *v44,
          *(_WORD *)(v31 + 2),
          *(_DWORD *)(v31 + 8));
        FsRtlFreeExtraCreateParameter(v31);
      }
      j = IopSymlinkGetRelatedMountPoint(v33, *((unsigned __int16 *)a3 + 3));
      if ( !j )
      {
        v35 = *(_DWORD *)(v33 + 8);
        for ( j = v33; v35; v35 = *(_DWORD *)(v35 + 8) )
          j = v35;
      }
      result = IopSymlinkApplyToOpenedName(a2, j, a3, a1, v39, v21);
      v6 = result;
    }
LABEL_72:
    if ( !v41 )
      goto LABEL_30;
    goto LABEL_73;
  }
LABEL_36:
  a1[6] = v6;
  return result;
}
