// SepAdtStagingEvent 
 
int __fastcall SepAdtStagingEvent(int a1, int a2, int *a3, unsigned __int16 *a4, unsigned __int16 *a5, int a6, int a7, int a8, int a9, unsigned __int8 a10, int a11, int a12)
{
  int v13; // r6
  int v14; // r7
  int v15; // r3
  int v16; // r5
  int v18; // r9
  int v19; // r4
  __int16 v20; // r3
  int v21; // r3
  int v22; // r3
  int v23; // r3
  int v24; // r3
  int v25; // r3
  int v26; // r0
  int v27; // r5
  int v28; // r3
  int v29; // r0
  int v30; // r3
  unsigned int v31; // r10
  unsigned int v32; // r8
  int v33; // r9
  _BYTE *v34; // r0
  unsigned int v35; // r5
  __int64 v36; // r2
  unsigned __int8 v39; // [sp+0h] [bp-2F8h] BYREF
  char v40[3]; // [sp+1h] [bp-2F7h] BYREF
  int v41; // [sp+4h] [bp-2F4h] BYREF
  int v42; // [sp+8h] [bp-2F0h] BYREF
  unsigned __int16 *v43; // [sp+Ch] [bp-2ECh]
  int v44; // [sp+10h] [bp-2E8h]
  int v45; // [sp+14h] [bp-2E4h]
  int v46; // [sp+18h] [bp-2E0h]
  unsigned int v47; // [sp+1Ch] [bp-2DCh] BYREF
  int v48; // [sp+20h] [bp-2D8h]
  int v49; // [sp+28h] [bp-2D0h]
  int v50; // [sp+2Ch] [bp-2CCh]
  unsigned int v51; // [sp+30h] [bp-2C8h] BYREF
  int v52; // [sp+34h] [bp-2C4h]
  int *v53; // [sp+38h] [bp-2C0h]
  int v54[174]; // [sp+40h] [bp-2B8h] BYREF

  v49 = 0;
  v50 = 0;
  v43 = 0;
  v47 = 0;
  v51 = 0;
  v13 = 0;
  v14 = 0;
  v15 = *(_DWORD *)(a12 + 48);
  v16 = 0;
  v53 = a3;
  v45 = v15;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v18 = 0;
  v40[0] = 0;
  if ( !v15
    || !*(_BYTE *)(v15 + 192)
    || a1 != 116 && a1 != 128 && RtlCompareUnicodeString(a4, (unsigned __int16 *)&SepFileTypeName, 0) )
  {
    return 1;
  }
  v19 = SeLocateProcessImageName(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  if ( v19 >= 0 )
  {
    if ( a6 )
    {
      v48 = **(_DWORD **)(a6 + 148);
      v46 = *(_DWORD *)(a6 + 24);
      v44 = *(_DWORD *)(a6 + 28);
    }
    else
    {
      v48 = **(_DWORD **)(a7 + 148);
      v44 = v50;
      v46 = v49;
    }
    v52 = *(_DWORD *)(a7 + 24);
    v49 = *(_DWORD *)(a7 + 28);
    memset(v54, 0, 664);
    v54[0] = 3;
    v54[1] = 4818;
    LOWORD(v54[4]) = 129;
    if ( (a8 & 0x2000000) != 0 || !a10 )
      v20 = 16;
    else
      v20 = 8;
    HIWORD(v54[4]) = v20;
    v54[6] = 4;
    v21 = *(unsigned __int8 *)(v48 + 1);
    v54[10] = v48;
    v54[7] = 4 * (v21 + 2);
    v54[11] = 1;
    v54[12] = 24;
    v54[15] = (int)&SeSubsystemName;
    v54[16] = 5;
    v54[17] = 8;
    if ( a6 )
    {
      v54[18] = v46;
      v22 = v44;
    }
    else
    {
      v54[18] = v52;
      v22 = v49;
    }
    v54[19] = v22;
    v54[21] = 1;
    v54[22] = 24;
    v54[2] = 4;
    v54[25] = (int)&SeSubsystemName;
    if ( a4 )
    {
      v54[26] = 1;
      v23 = *a4;
      v54[30] = (int)a4;
      v54[27] = v23 + 8;
      if ( a5 )
      {
        if ( a1 == 116 || a1 == 128 )
          v24 = 2;
        else
          v24 = 1;
        v54[31] = v24;
        v25 = *a5;
        v54[35] = (int)a5;
        v54[32] = v25 + 8;
      }
      if ( v53 )
      {
        v26 = *v53;
        v54[36] = 11;
        v54[37] = 4;
        v54[38] = ObNormalizeHandleValue(v26);
      }
      else
      {
        v54[36] = 11;
        v54[37] = 4;
        v54[38] = 0;
      }
      v54[41] = 11;
      v54[42] = 4;
      v27 = v45;
      v54[43] = a11;
      v54[46] = 2;
      v28 = *v43;
      v29 = *(_DWORD *)(v45 + 48);
      v54[50] = (int)v43;
      v54[47] = v28 + 8;
      v54[2] = 9;
      v19 = SepCheckAndCopySelfRelativeSD(v29, &v41, &v47, &v39);
      if ( v19 < 0 )
      {
        v13 = v41;
      }
      else
      {
        v19 = SepCheckAndCopySelfRelativeSD(*(_DWORD *)(v27 + 52), &v42, &v51, v40);
        v13 = v41;
        v14 = v42;
        if ( v19 >= 0 )
        {
          if ( v41 || v42 )
            v30 = 4;
          else
            v30 = 0;
          v31 = v51;
          v32 = v47;
          v33 = v51 - v30 + v47 + 144;
          v34 = (_BYTE *)ExAllocatePoolWithTag(1, v33, 1883333971);
          v35 = (unsigned int)v34;
          if ( v34 )
          {
            memset(v34, 0, v33);
            HIDWORD(v36) = a10;
            LODWORD(v36) = 4;
            *(_QWORD *)(v35 + 132) = v36;
            if ( !a10 )
              a9 = a8;
            *(_DWORD *)v35 = a9 & 0xFDFFFFFF;
            memmove(v35 + 4, v45 + 64, 0x80u);
            if ( v13 )
              memmove(v35 + 140, v13, v32);
            if ( v14 )
              memmove(v32 + v35 + 140, v14, v31);
            v54[51] = 29;
            v54[52] = v33;
            v54[55] = v35;
            v54[56] = 30;
            v54[58] = 0;
            v54[59] = 0;
            v54[2] = 11;
            v54[57] = v33;
            v54[60] = v35;
            SepAdtLogAuditRecord((int)v54);
            ExFreePoolWithTag(v35);
          }
          else
          {
            v19 = -1073741670;
          }
        }
        v18 = (unsigned __int8)v40[0];
      }
      v16 = v39;
    }
    else
    {
      v19 = -1073741811;
    }
  }
  if ( v43 )
    ExFreePoolWithTag((unsigned int)v43);
  if ( v16 && v13 )
    ExFreePoolWithTag(v13);
  if ( v18 )
  {
    if ( v14 )
      ExFreePoolWithTag(v14);
  }
  if ( v19 >= 0 )
    return 1;
  SepAuditFailed();
  return 0;
}
