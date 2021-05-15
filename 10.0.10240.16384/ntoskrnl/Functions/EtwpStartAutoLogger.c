// EtwpStartAutoLogger 
 
int __fastcall EtwpStartAutoLogger(char *a1, unsigned __int16 *a2, _DWORD *a3, int a4)
{
  unsigned int v6; // r6
  unsigned int v7; // r4
  unsigned int v8; // r5
  int v9; // r0
  unsigned __int16 *v10; // r4
  int v12; // r3
  int v13; // r7
  _BYTE *v14; // r0
  __int16 *v15; // r4
  _WORD *v16; // r5
  _WORD *v17; // r10
  _WORD *v18; // r8
  int v19; // r9
  int v20; // r2
  int v21; // r0
  int v22; // r2
  int v23; // r5
  int v24; // r3
  int v25; // r3
  int v26; // r1
  int v27; // r2
  int v28; // r3
  int v29; // r0
  unsigned int v30; // r1
  int v31; // r1
  __int16 v32; // r2
  int v33; // r10
  int v34; // r0
  __int16 v35; // r2
  int v36; // r0
  __int16 v37; // r2
  int v38; // r3
  unsigned int v39; // r2
  int v40; // r1
  int v41; // [sp+0h] [bp-2D8h]
  int v42; // [sp+0h] [bp-2D8h]
  __int16 v43; // [sp+Ch] [bp-2CCh] BYREF
  int v44[2]; // [sp+10h] [bp-2C8h] BYREF
  __int64 v45; // [sp+18h] [bp-2C0h] BYREF
  __int64 v46; // [sp+20h] [bp-2B8h] BYREF
  int v47; // [sp+28h] [bp-2B0h] BYREF
  unsigned int v48; // [sp+2Ch] [bp-2ACh] BYREF
  int v49[2]; // [sp+30h] [bp-2A8h] BYREF
  int v50; // [sp+38h] [bp-2A0h] BYREF
  __int16 v51; // [sp+40h] [bp-298h] BYREF
  int v52; // [sp+42h] [bp-296h]
  __int16 v53; // [sp+46h] [bp-292h]
  int v54[2]; // [sp+48h] [bp-290h] BYREF
  char *v55; // [sp+50h] [bp-288h]
  int v56; // [sp+54h] [bp-284h] BYREF
  _DWORD *v57; // [sp+58h] [bp-280h]
  int v58; // [sp+5Ch] [bp-27Ch] BYREF
  int v59[2]; // [sp+60h] [bp-278h] BYREF
  int v60; // [sp+68h] [bp-270h]
  int v61; // [sp+6Ch] [bp-26Ch]
  int v62[8]; // [sp+70h] [bp-268h] BYREF
  int v63; // [sp+90h] [bp-248h] BYREF
  int v64; // [sp+94h] [bp-244h]
  int v65; // [sp+98h] [bp-240h]
  int v66; // [sp+9Ch] [bp-23Ch]
  int v67[142]; // [sp+A0h] [bp-238h] BYREF

  v61 = a4;
  v51 = 0;
  v52 = 0;
  v53 = 0;
  v49[1] = 0;
  v50 = 0;
  v46 = 0i64;
  v45 = 0i64;
  v48 = 0;
  v49[0] = 0;
  v47 = 0;
  v43 = 0;
  v55 = a1;
  v56 = 1;
  v62[0] = 0;
  v57 = a3;
  v58 = 100;
  v63 = 0;
  v64 = 0;
  v65 = 0;
  v66 = 0;
  *a3 = 0;
  v6 = 0;
  v7 = wcslen(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\");
  v8 = wcslen(a2) + v7 + 1;
  v9 = ExAllocatePoolWithTag(1, 2 * v8, 1350005829);
  v10 = (unsigned __int16 *)v9;
  if ( !v9 )
    return sub_810D74();
  RtlStringCbCopyW(v9, 2 * v8);
  RtlStringCbCatW(v10, 2 * v8, (int)a2, v12);
  RtlInitUnicodeString((unsigned int)&v51, v10);
  v62[2] = 24;
  v62[3] = 0;
  v62[5] = 576;
  v62[4] = (int)&v51;
  v62[6] = 0;
  v62[7] = 0;
  v13 = ZwOpenKey();
  if ( v13 >= 0 )
  {
    v14 = (_BYTE *)ExAllocatePoolWithTag(1, 1284, 1350005829);
    v6 = (unsigned int)v14;
    if ( !v14 )
      return sub_810D74();
    memset(v14, 0, 1284);
    *(_DWORD *)(v6 + 44) = 0x20000;
    *(_DWORD *)(v6 + 48) = 4;
    RtlInitUnicodeString(v6 + 144, (unsigned __int16 *)a1);
    *(_DWORD *)(v6 + 72) = 0x80000000;
    *(_BYTE *)(v6 + 74) = -1;
    v15 = (__int16 *)(v6 + 176);
    v16 = (_WORD *)(v6 + 180);
    *(_WORD *)(v6 + 72) = 176;
    *(_WORD *)(v6 + 178) = 0;
    v17 = (_WORD *)(v6 + 224);
    v18 = (_WORD *)(v6 + 1252);
    *(_WORD *)(v6 + 176) = 1;
    v19 = 180;
    memset(v67, 0, 532);
    v46 = 0i64;
    v45 = 0i64;
    v67[0] = (int)EtwpQueryRegistryCallback;
    v67[3] = (int)&v50;
    v67[2] = (int)L"Start";
    v67[4] = 4;
    v13 = RtlpQueryRegistryValues(0x40000000, 0, v67, 0, v41, 1u);
    if ( v13 >= 0 )
    {
      if ( v50 )
      {
        v67[0] = (int)EtwpQueryRegistryCallback;
        v67[3] = v6 + 76;
        v67[2] = (int)L"FlushThreshold";
        v67[4] = 4;
        v67[7] = (int)EtwpQueryRegistryCallback;
        v67[10] = v6 + 48;
        v67[9] = (int)L"BufferSize";
        v67[11] = 4;
        v67[14] = (int)EtwpQueryRegistryCallback;
        v67[17] = v6 + 52;
        v67[16] = (int)L"MinimumBuffers";
        v67[18] = 4;
        v67[21] = (int)EtwpQueryRegistryCallback;
        v67[24] = v6 + 68;
        v67[23] = (int)L"FlushTimer";
        v67[25] = 4;
        v67[28] = (int)EtwpQueryRegistryCallback;
        v67[31] = v6 + 56;
        v67[30] = (int)L"MaximumBuffers";
        v67[32] = 4;
        v67[35] = (int)EtwpQueryRegistryCallback;
        v67[38] = v6 + 128;
        v67[37] = (int)L"FileName";
        v67[39] = 1;
        v67[40] = (int)&v43;
        v59[0] = 40;
        v59[1] = v6 + 184;
        v67[42] = (int)EtwpQueryRegistryCallback;
        v67[45] = (int)v59;
        v67[44] = (int)L"EnableKernelFlags";
        v67[46] = 3;
        v44[0] = 1024;
        v44[1] = v6 + 228;
        v67[49] = (int)EtwpQueryRegistryCallback;
        v67[52] = (int)v44;
        v67[51] = (int)L"StackWalkingFilter";
        v67[53] = 3;
        v67[56] = (int)EtwpQueryRegistryCallback;
        v67[59] = v6 + 40;
        v67[58] = (int)L"ClockType";
        v67[60] = 4;
        v67[61] = (int)&v56;
        v67[62] = 4;
        v67[63] = (int)EtwpQueryRegistryCallback;
        v67[66] = v6 + 60;
        v67[65] = (int)L"MaxFileSize";
        v67[67] = 4;
        v67[68] = (int)&v58;
        v67[69] = 4;
        v67[70] = (int)EtwpQueryRegistryCallback;
        v67[73] = v6 + 64;
        v67[72] = (int)L"LogFileMode";
        v67[74] = 4;
        v67[75] = (int)v62;
        v67[76] = 4;
        v67[77] = (int)EtwpQueryRegistryCallback;
        v67[80] = (int)v49;
        v67[79] = (int)L"DisableRealtimePersistence";
        v67[81] = 4;
        v67[84] = (int)EtwpQueryRegistryCallback;
        v67[87] = (int)&v46;
        v67[86] = (int)L"Guid";
        v67[88] = 1;
        v67[89] = (int)&v43;
        v67[91] = (int)EtwpQueryRegistryCallback;
        v67[94] = v6 + 96;
        v67[93] = (int)L"FileCounter";
        v67[95] = 4;
        v67[98] = (int)EtwpQueryRegistryCallback;
        v67[101] = (int)&v48;
        v67[100] = (int)L"FileMax";
        v67[102] = 4;
        v67[105] = (int)EtwpQueryRegistryCallback;
        v67[108] = (int)&v45;
        v67[107] = (int)L"PoolTagFilter";
        v67[109] = 1;
        v67[110] = (int)&v43;
        v54[0] = 8;
        v54[1] = v6 + 1276;
        v67[112] = (int)EtwpQueryRegistryCallback;
        v67[115] = (int)v54;
        v67[114] = (int)L"StackCaching";
        v67[116] = 3;
        v67[119] = (int)EtwpQueryRegistryCallback;
        v67[122] = (int)&v47;
        v67[121] = (int)L"EnableSecurityProvider";
        v67[123] = 4;
        v13 = RtlpQueryRegistryValues(0x40000000, 0, v67, 0, v42, 1u);
        if ( v13 >= 0 )
        {
          v20 = *(_DWORD *)(v6 + 112) | 2;
          *(_DWORD *)(v6 + 112) = v20;
          if ( !v49[0] )
            *(_DWORD *)(v6 + 112) = v20 | 1;
          v21 = (unsigned __int16)((unsigned int)v59[0] >> 2);
          v60 = v21;
          if ( (unsigned __int16)((unsigned int)v59[0] >> 2) )
          {
            *v16 = v21 + 1;
            *(_WORD *)(v6 + 182) = 1;
            ++*(_WORD *)(v6 + 178);
            *v15 += *v16;
            v19 = 4 * ((unsigned __int16)*v16 + 45);
          }
          v22 = v44[0];
          if ( v44[0] )
          {
            v31 = (unsigned __int16)((unsigned int)v44[0] >> 2);
            if ( (v44[0] & 3) != 0 )
              v31 = (unsigned __int16)(v31 + 1);
            *v17 = v31 + 1;
            *(_WORD *)(v6 + 226) = 3;
            v32 = *v15;
            ++*(_WORD *)(v6 + 178);
            *v15 = *v17 + v32;
            v19 += 4 * (unsigned __int16)*v17;
            if ( v21 )
              v16 += 2 * (unsigned __int16)*v16;
            if ( v16 != v17 )
              memmove((int)v16, v6 + 224, 4 * (v31 + 1));
            v22 = v44[0];
          }
          if ( HIDWORD(v45) )
          {
            v33 = (int)&v15[2 * (unsigned __int16)*v15];
            v34 = EtwpParsePoolTagFilter(&v45, v6 + 1256, v22);
            v23 = v34;
            if ( v34 )
            {
              *(_WORD *)(v6 + 1254) = 4;
              *v18 = v34 + 1;
              v35 = *v15;
              ++*(_WORD *)(v6 + 178);
              *v15 = *v18 + v35;
              v19 += 4 * (unsigned __int16)*v18;
              if ( (_WORD *)v33 != v18 )
                memmove(v33, v6 + 1252, 4 * (v34 + 1));
            }
            v22 = v44[0];
          }
          else
          {
            v23 = 0;
          }
          v24 = v54[0];
          if ( v54[0] == 8 )
          {
            v36 = (int)&v15[2 * (unsigned __int16)*v15];
            *(_WORD *)(v6 + 1274) = 5;
            *(_WORD *)(v6 + 1272) = 3;
            v37 = *v15;
            ++*(_WORD *)(v6 + 178);
            *v15 = *(_WORD *)(v6 + 1272) + v37;
            v19 += 4 * *(unsigned __int16 *)(v6 + 1272);
            if ( v36 != v6 + 1272 )
              memmove(v36, v6 + 1272, 0xCu);
            v24 = v54[0];
            v22 = v44[0];
          }
          if ( !v60 && !v22 && !v24 && !v23 )
            *(_DWORD *)(v6 + 72) = 0;
          v25 = *(_DWORD *)(v6 + 64);
          if ( ((v25 & 0x100) != 0 || (v25 & 0x400) != 0) && (v25 & 0x200) == 0 || *(_DWORD *)(v6 + 132) )
          {
LABEL_24:
            if ( v47 )
            {
              v38 = *(_DWORD *)(v6 + 64);
              if ( (v38 & 0x80) != 0 && (v38 & 0x100) != 0 && !*(_DWORD *)(v6 + 132) )
                *(_DWORD *)(v6 + 112) |= 0x8004000u;
              else
                v13 = -1073741790;
            }
            if ( v13 >= 0 )
            {
              if ( v48 )
              {
                v30 = *(_DWORD *)(v6 + 96) + 1;
                *(_DWORD *)(v6 + 96) = v30;
                if ( v30 > v48 || v30 > 0x10 )
                  *(_DWORD *)(v6 + 96) = 1;
                RtlWriteRegistryValue(0x40000000, 0, L"FileCounter");
              }
              if ( !wcscmp(v55, (char *)L"GlobalLogger") )
              {
                v63 = -393180484;
                v64 = 299018884;
                v65 = -2147445862;
                v66 = -958954145;
              }
              else
              {
                v13 = HIDWORD(v46) ? RtlGUIDFromString((unsigned __int16 *)&v46, &v63) : -1073741811;
              }
              if ( v13 >= 0 )
              {
                v26 = v64;
                v27 = v65;
                v28 = v66;
                *(_DWORD *)(v6 + 24) = v63;
                *(_DWORD *)(v6 + 28) = v26;
                *(_DWORD *)(v6 + 32) = v27;
                *(_DWORD *)(v6 + 36) = v28;
                *(_DWORD *)v6 = v19;
                v13 = EtwpStartLogger(v6);
                v29 = *(unsigned __int16 *)(v6 + 8);
                *v57 = v29;
                if ( v13 >= 0 && v29 && v47 )
                {
                  v39 = 0;
                  v40 = v61;
                  while ( *(_WORD *)(v40 + 376) )
                  {
                    ++v39;
                    v40 += 2;
                    if ( v39 >= 8 )
                      goto LABEL_34;
                  }
                  *(_WORD *)(v61 + 2 * v39 + 376) = v29;
                }
              }
            }
            goto LABEL_34;
          }
          if ( RtlCreateUnicodeString(v6 + 128, L"%SystemRoot%") )
          {
            v13 = 0;
            goto LABEL_24;
          }
          v13 = -1073741801;
        }
      }
    }
  }
LABEL_34:
  if ( v6 )
  {
    RtlFreeAnsiString((_DWORD *)(v6 + 128));
    ExFreePoolWithTag(v6);
  }
  RtlFreeAnsiString(&v46);
  RtlFreeAnsiString(&v51);
  RtlFreeAnsiString(&v45);
  return v13;
}
