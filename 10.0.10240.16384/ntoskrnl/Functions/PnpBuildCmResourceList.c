// PnpBuildCmResourceList 
 
int __fastcall PnpBuildCmResourceList(int a1, int a2)
{
  _DWORD *v2; // r8
  int *v3; // r5
  int v4; // r4
  int *v5; // r3
  int v6; // r10
  int v7; // r0
  int v8; // r2
  int v9; // r3
  int v10; // r7
  int v11; // r6
  int result; // r0
  int v13; // r7
  int *v14; // r9
  _DWORD *v15; // lr
  int v16; // r3
  int v17; // r2
  int v18; // r8
  int v19; // r4
  _DWORD *v20; // lr
  int *v21; // r9
  int v22; // r1
  int v23; // r2
  int v24; // r3
  _DWORD *v25; // r5
  int v26; // r3
  unsigned int v27; // r0
  int v28; // r2
  int v29; // r3
  int v30; // r4
  __int64 v31; // kr00_8
  unsigned int v32; // r3
  int v33; // r8
  char *v34; // r2
  int v35; // r4
  int v36; // r2
  int v37; // r1
  int v38; // r2
  int v39; // r3
  int v40; // r1
  int v41; // r2
  int v42; // r3
  int *v43; // [sp+8h] [bp-258h] BYREF
  _DWORD *v44; // [sp+Ch] [bp-254h]
  int v45; // [sp+10h] [bp-250h] BYREF
  char *v46; // [sp+14h] [bp-24Ch]
  int v47[2]; // [sp+18h] [bp-248h] BYREF
  int v48[2]; // [sp+20h] [bp-240h] BYREF
  int v49; // [sp+28h] [bp-238h]
  int v50; // [sp+2Ch] [bp-234h] BYREF
  unsigned int v51; // [sp+30h] [bp-230h]
  int *v52; // [sp+34h] [bp-22Ch]
  int *v53; // [sp+38h] [bp-228h] BYREF
  int v54; // [sp+3Ch] [bp-224h]
  int v55; // [sp+40h] [bp-220h] BYREF
  char *v56; // [sp+44h] [bp-21Ch]
  char v57[536]; // [sp+48h] [bp-218h] BYREF

  v2 = *(_DWORD **)(a1 + 24);
  v3 = (int *)a1;
  v4 = 0;
  v5 = (int *)v2[3];
  v50 = a2;
  v52 = (int *)a1;
  v6 = *v5;
  v7 = *(_DWORD *)(*v5 + 16);
  v45 = *v5;
  if ( !v7 )
    goto LABEL_31;
  v8 = v6;
  do
  {
    v9 = *(_DWORD *)(v8 + 20);
    v8 += 4;
    v4 += *(_DWORD *)(v9 + 168) + 1;
    --v7;
  }
  while ( v7 );
  if ( !v4 )
LABEL_31:
    JUMPOUT(0x80DE40);
  v10 = 16 * (v4 - 1) + 36;
  v54 = v10;
  v11 = ExAllocatePoolWithTag(1, v10, 538996816);
  v47[0] = v11;
  if ( !v11 )
    JUMPOUT(0x80DD90);
  result = ExAllocatePoolWithTag(1, v10, 538996816);
  v13 = result;
  v48[0] = result;
  if ( !result )
    return sub_80DD88();
  *(_DWORD *)v11 = 1;
  v14 = (int *)(v11 + 20);
  v15 = (_DWORD *)(result + 20);
  *(_DWORD *)(v11 + 4) = *v2;
  v16 = v2[1];
  v43 = (int *)(v11 + 20);
  v44 = (_DWORD *)(result + 20);
  *(_DWORD *)(v11 + 8) = v16;
  *(_WORD *)(v11 + 12) = 1;
  *(_WORD *)(v11 + 14) = 1;
  *(_DWORD *)(v11 + 16) = v4;
  *(_DWORD *)result = 1;
  *(_DWORD *)(result + 4) = *v2;
  *(_DWORD *)(result + 8) = v2[1];
  v51 = 0;
  *(_WORD *)(result + 12) = 1;
  *(_WORD *)(result + 14) = 1;
  *(_DWORD *)(result + 16) = v4;
  if ( *(_DWORD *)(v6 + 16) )
  {
    v17 = v6;
    v49 = v6;
    while ( 1 )
    {
      v18 = *(_DWORD *)(v17 + 20);
      if ( *(_BYTE *)(v18 + 8) )
      {
        v19 = *(_DWORD *)(v18 + 20);
        if ( *(_DWORD *)(v19 + 76) == 2 )
          JUMPOUT(0x80DD94);
        if ( IopParentToRawTranslation(*(_DWORD *)(v18 + 20)) < 0 )
          JUMPOUT(0x80DE08);
        v20 = *(_DWORD **)(v18 + 68);
        v21 = v43;
        v22 = v20[1];
        v23 = v20[2];
        v24 = v20[3];
        v25 = v44;
        *v44 = *v20;
        v25[1] = v22;
        v25[2] = v23;
        v25[3] = v24;
        v3 = v52;
        v44 += 4;
        if ( *(_DWORD *)(v19 + 76) == 2 )
          JUMPOUT(0x80DDA2);
        v26 = *(_DWORD *)(v18 + 40);
        if ( !v26 )
          JUMPOUT(0x80DD9C);
        if ( IopChildToRootTranslation(
               *(_DWORD *)(*(_DWORD *)(v26 + 176) + 20),
               *(_DWORD *)v18,
               *(_DWORD *)(v18 + 4),
               *(_DWORD *)(v18 + 44),
               v18 + 80,
               &v53) < 0 )
          JUMPOUT(0x80DE1E);
        v27 = (unsigned int)v53;
        v28 = v53[1];
        v29 = v53[2];
        v30 = v53[3];
        *v21 = *v53;
        v21[1] = v28;
        v21[2] = v29;
        v21[3] = v30;
        result = ExFreePoolWithTag(v27);
        v14 = v21 + 4;
      }
      else
      {
        v37 = *(_DWORD *)(v18 + 84);
        v38 = *(_DWORD *)(v18 + 88);
        v39 = *(_DWORD *)(v18 + 92);
        *v15 = *(_DWORD *)(v18 + 80);
        v15[1] = v37;
        v15[2] = v38;
        v15[3] = v39;
        result = *(_DWORD *)(v18 + 80);
        v40 = *(_DWORD *)(v18 + 84);
        v41 = *(_DWORD *)(v18 + 88);
        v42 = *(_DWORD *)(v18 + 92);
        *v14 = result;
        v14[1] = v40;
        v14[2] = v41;
        v14[3] = v42;
        v14 += 4;
        v44 = v15 + 4;
      }
      v31 = *(_QWORD *)(v18 + 168);
      v43 = v14;
      if ( (_DWORD)v31 )
        JUMPOUT(0x80DDAE);
      v32 = *(_DWORD *)(v6 + 16);
      v17 = v49 + 4;
      ++v51;
      v49 += 4;
      if ( v51 >= v32 )
        break;
      v15 = v44;
    }
  }
  if ( v50 )
  {
    v33 = *v3;
    result = IopCreateRegistryKeyEx(&v43, 0, (int)&CmRegistryMachineHardwareResourceMapName, 131103, 1, 0);
    if ( result >= 0 )
    {
      v47[0] = 1572886;
      v47[1] = (int)L"PnP Manager";
      v48[0] = 1441812;
      v48[1] = (int)L"PnpManager";
      if ( ObQueryNameStringMode(v33, (int)&v55, 512, &v50, 0) >= 0 )
      {
        HIWORD(v55) = 504;
        if ( (_WORD)v55 )
        {
          v34 = v56;
        }
        else
        {
          v34 = v57;
          v56 = v57;
        }
        v45 = v55;
        v46 = v34;
        RtlAppendUnicodeToString((unsigned __int16 *)&v45, (int)L".Raw", (int)v34, v55);
        v35 = v54;
        if ( IopWriteResourceList(v43, v47, v48, &v45, v13, v54) >= 0 )
        {
          v45 = v55;
          v46 = v56;
          RtlAppendUnicodeToString((unsigned __int16 *)&v45, (int)L".Translated", v36, (int)v56);
          IopWriteResourceList(v43, v47, v48, &v45, v11, v35);
        }
      }
      result = ZwClose();
    }
  }
  v3[7] = v13;
  v3[8] = v11;
  return result;
}
