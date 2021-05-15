// AdtpBuildStagingReasonAuditStringInternal 
 
int __fastcall AdtpBuildStagingReasonAuditStringInternal(int a1, int a2, int a3, int a4, int a5, int a6, int a7, _WORD *a8)
{
  int v10; // r9
  int v11; // r7
  int v12; // r4
  int v13; // r5
  int v14; // r2
  unsigned int v15; // r3
  unsigned int v16; // r10
  int v17; // r4
  unsigned int v18; // r8
  bool v19; // zf
  int v20; // r6
  int v21; // r2
  unsigned int v22; // r3
  int *v23; // r2
  int v24; // r2
  int v25; // r3
  int v26; // r0
  unsigned int v27; // r6
  int v28; // r8
  int v29; // r0
  int v30; // r4
  _WORD *v31; // r2
  char v33[8]; // [sp+18h] [bp-B0h] BYREF
  unsigned __int16 v34; // [sp+20h] [bp-A8h]
  _BYTE v35[6]; // [sp+22h] [bp-A6h]
  int v36; // [sp+28h] [bp-A0h] BYREF
  const __int16 *v37; // [sp+2Ch] [bp-9Ch]
  unsigned __int16 v38; // [sp+30h] [bp-98h] BYREF
  __int16 v39; // [sp+32h] [bp-96h]
  int v40; // [sp+34h] [bp-94h]
  int v41; // [sp+38h] [bp-90h] BYREF
  unsigned __int16 v42[2]; // [sp+40h] [bp-88h] BYREF
  char *v43; // [sp+44h] [bp-84h]
  _WORD *v44; // [sp+48h] [bp-80h]
  int v45; // [sp+4Ch] [bp-7Ch]
  char v46[16]; // [sp+50h] [bp-78h] BYREF
  char v47[40]; // [sp+60h] [bp-68h] BYREF
  char v48; // [sp+88h] [bp-40h] BYREF

  v45 = a4;
  v43 = &v48;
  v34 = 0;
  *(_DWORD *)v35 = 0;
  *(_WORD *)&v35[4] = 0;
  v38 = 0;
  v39 = 0;
  v33[0] = 0;
  v42[0] = 0;
  v42[1] = 30;
  v41 = a3;
  v10 = 2;
  v11 = 0;
  v36 = 131074;
  v44 = a8;
  qmemcpy(v46, "# %d", 8);
  v37 = L"-";
  v12 = AdtpPermissionBitPosition(a5);
  v13 = AdtpBuildAccessesString(a1, a2, a5);
  v14 = *(_DWORD *)&v35[2];
  if ( v13 >= 0 )
  {
    v15 = *(_DWORD *)(a7 + 4 * v12);
    v16 = v34;
    v17 = v15 & 0xFF0000;
    v18 = HIBYTE(v15) & 0x7F;
    if ( (v15 & 0xFF0000) > 0x200000 )
    {
      if ( v17 == 3145728 )
        goto LABEL_22;
      if ( v17 != 0x400000 )
      {
        if ( v17 == 5242880 )
          goto LABEL_22;
        if ( v17 != 6291456 && v17 != 7340032 )
        {
          v19 = v17 == 0x800000;
LABEL_19:
          if ( !v19 )
          {
            v20 = 1809;
            goto LABEL_23;
          }
          goto LABEL_22;
        }
      }
    }
    else if ( (v15 & 0xFF0000) != 0x200000 && v17 != 0x10000 )
    {
      if ( v17 != 0x20000 )
      {
        if ( v17 == 196608 )
        {
          v20 = 1816;
          goto LABEL_23;
        }
        if ( v17 != 327680 )
        {
          if ( v17 == 393216 )
          {
            v20 = 1815;
            goto LABEL_23;
          }
          if ( v17 != 458752 )
          {
            v19 = v17 == 0x100000;
            goto LABEL_19;
          }
        }
      }
LABEL_22:
      v20 = 1813;
LABEL_23:
      v13 = AdtpFormatPrefix(v42, v20, 0);
      if ( v13 >= 0 )
      {
        if ( v17 == 196608 || v17 == 393216 )
          v21 = v45;
        else
          v21 = v41;
        v22 = *(_DWORD *)(v21 + 4);
        if ( !v22 )
          goto LABEL_32;
        if ( v18 >= v22 )
        {
          v13 = -1073741811;
          goto LABEL_43;
        }
        v23 = (int *)(*(_DWORD *)(v21 + 8) + 8 * v18);
        v36 = *v23;
        v10 = (unsigned __int16)v36;
        v37 = (const __int16 *)v23[1];
        if ( (unsigned __int16)v36 <= 2u )
        {
LABEL_32:
          v41 = 0;
          if ( StringCchPrintfExW(v47, 20, 0, &v41, 0, v46, v18, 0, v33) >= 0 )
          {
            HIWORD(v36) = 40;
            v10 = (unsigned __int16)(2 * (20 - v41));
            v37 = (const __int16 *)v47;
            LOWORD(v36) = 2 * (20 - v41);
          }
        }
        v11 = ExAllocatePoolWithTag(1, v10 + 54);
        v40 = v11;
        if ( v11 )
        {
          v38 = 0;
          v39 = 2 * (v10 + 54);
          RtlAppendUnicodeStringToString(&v38, v42);
          v25 = 1809;
          if ( v20 != 1809 )
            RtlAppendUnicodeStringToString(&v38, (unsigned __int16 *)&v36);
          v26 = RtlAppendUnicodeToString(&v38, (int)L"\r\n\t\t\t\t", v24, v25);
          v27 = v38;
          v13 = v26;
          v28 = (v38 >> 1) + (v16 >> 1) + 1;
          v29 = ExAllocatePoolWithTag(1, 2 * v28);
          v30 = v29;
          if ( v29 )
          {
            v11 = v40;
            if ( v27 )
              memmove(v16 + v29, v40, v27);
            *(_WORD *)(v30 + 2 * v28 - 2) = 0;
            v31 = v44;
            *v44 = 2 * (v28 - 1);
            v31[1] = 2 * (v28 - 1) + 2;
            *((_DWORD *)v31 + 1) = v30;
          }
          else
          {
            v13 = -1073741801;
            v11 = v40;
          }
        }
        else
        {
          v13 = -1073741801;
        }
      }
LABEL_43:
      v14 = *(_DWORD *)&v35[2];
      goto LABEL_44;
    }
    v20 = 1814;
    goto LABEL_23;
  }
LABEL_44:
  if ( v33[0] && v14 )
    ExFreePoolWithTag(v14);
  if ( v11 )
    ExFreePoolWithTag(v11);
  return v13;
}
