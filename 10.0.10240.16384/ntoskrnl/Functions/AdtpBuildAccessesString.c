// AdtpBuildAccessesString 
 
int __fastcall AdtpBuildAccessesString(int a1, int a2, int a3, int a4, unsigned int a5, _DWORD *a6, int a7, unsigned int *a8, _BYTE *a9)
{
  int v9; // r1
  int v10; // r6
  int v11; // r10
  const __int16 *v12; // r2
  int v13; // r5
  unsigned int v14; // r2
  int v15; // r0
  unsigned __int16 *v16; // r5
  int v17; // r8
  int *v18; // r7
  int v19; // r6
  int v20; // r3
  int v21; // t1
  int v22; // r2
  int v23; // r3
  int v24; // r0
  int v25; // r4
  unsigned __int16 *v26; // r5
  int *v27; // r7
  int v28; // r6
  int v29; // r3
  int v30; // t1
  int v31; // r2
  int v32; // r3
  int v33; // r0
  _DWORD *v34; // r4
  int v35; // r2
  int v36; // r3
  int v37; // r7
  int *v38; // r6
  unsigned __int16 *v39; // r9
  int *v40; // r5
  int v41; // r3
  _DWORD *v42; // r6
  int v43; // r0
  unsigned __int16 *v44; // r9
  _WORD *v45; // r2
  BOOL v46; // r8
  int v47; // r4
  _DWORD *v48; // r5
  int v49; // r3
  int v50; // r0
  unsigned int v51; // r1
  __int16 v52; // r3
  int v53; // r7
  int v54; // r4
  int v55; // r8
  int v56; // r6
  unsigned int i; // r5
  int v58; // r2
  int v59; // r3
  int v60; // r2
  int v61; // r3
  int v62; // r3
  _DWORD *v63; // r2
  int v65; // [sp+0h] [bp-68h] BYREF
  int v66; // [sp+4h] [bp-64h]
  const __int16 *v67; // [sp+8h] [bp-60h]
  int v68; // [sp+Ch] [bp-5Ch]
  int v69[2]; // [sp+10h] [bp-58h] BYREF
  int *v70; // [sp+18h] [bp-50h]
  _DWORD *v71; // [sp+1Ch] [bp-4Ch]
  _DWORD *v72; // [sp+20h] [bp-48h]
  int v73; // [sp+24h] [bp-44h]
  int v74; // [sp+28h] [bp-40h]
  _DWORD *v75; // [sp+2Ch] [bp-3Ch]
  char v76; // [sp+30h] [bp-38h] BYREF

  v68 = a3;
  v69[0] = a1;
  v74 = a2;
  v75 = (_DWORD *)a5;
  v9 = a3;
  v10 = 0;
  v70 = 0;
  v71 = a6;
  v11 = 0;
  v72 = 0;
  if ( a3 )
  {
    do
    {
      a3 &= a3 - 1;
      ++v10;
    }
    while ( a3 );
    if ( a4 )
    {
      if ( a4 == 1 )
      {
        v12 = L"\r\n";
      }
      else if ( a4 == 2 )
      {
        v12 = L":\t";
      }
      else
      {
        v12 = L"\r\n\t\t\t\t";
      }
      v67 = v12;
    }
    else
    {
      v67 = L"\r\n\t\t\t\t";
    }
    v13 = 24 * v10 + 1;
    if ( a7 && a8 && (v14 = *a8 + v13, v14 < 0x400) )
    {
      v15 = a7 + 2 * *a8;
      v73 = v15;
      *a8 = v14;
    }
    else
    {
      v15 = ExAllocatePoolWithTag(1, 2 * v13, 1799447891);
      v73 = v15;
      if ( !v15 )
        return -1073741801;
      v9 = v68;
      *a9 = 1;
    }
    LOWORD(v65) = 0;
    HIWORD(v65) = 2 * v13;
    v66 = v15;
    if ( (v9 & 0x1F0000) != 0 )
    {
      v16 = (unsigned __int16 *)&AdtpEventIdStringStandard;
      v17 = (int)v67;
      v18 = &AdtpStandardAccessTypes;
      v19 = 5;
      do
      {
        v21 = *v18++;
        v20 = v21;
        if ( (v21 & v9) != 0 )
        {
          RtlAppendUnicodeToString((unsigned __int16 *)&v65, (int)L"%%", v14, v20);
          RtlAppendUnicodeStringToString((unsigned __int16 *)&v65, v16);
          v24 = RtlAppendUnicodeToString((unsigned __int16 *)&v65, v17, v22, v23);
          v9 = v68;
          v11 = v24;
        }
        v16 += 4;
        --v19;
      }
      while ( v19 );
    }
    v25 = (int)v67;
    v26 = (unsigned __int16 *)&algn_6193C8[32];
    v27 = &dword_41DEC0;
    v28 = 2;
    do
    {
      v30 = *v27++;
      v29 = v30;
      if ( (v30 & v9) != 0 )
      {
        RtlAppendUnicodeToString((unsigned __int16 *)&v65, (int)L"%%", v14, v29);
        RtlAppendUnicodeStringToString((unsigned __int16 *)&v65, v26);
        v33 = RtlAppendUnicodeToString((unsigned __int16 *)&v65, v25, v31, v32);
        v9 = v68;
        v11 = v33;
      }
      v26 += 4;
      --v28;
    }
    while ( v28 );
    v34 = v71;
    if ( (_WORD)v9 )
    {
      v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v36 = *(__int16 *)(v35 + 0x134) - 1;
      *(_WORD *)(v35 + 308) = v36;
      ExAcquireResourceExclusiveLite((int)&AdtpSourceModuleLock, 1, v35, v36);
      v37 = 0;
      v38 = &AdtpSourceModules;
      if ( AdtpSourceModules )
      {
        v39 = (unsigned __int16 *)v69[0];
        do
        {
          if ( v37 )
            break;
          v40 = (int *)*v38;
          if ( RtlEqualUnicodeString((unsigned __int16 *)(*v38 + 4), v39, 1) )
          {
            v41 = *v40;
            v37 = 1;
            v70 = v40;
            *v38 = v41;
            *v40 = AdtpSourceModules;
            AdtpSourceModules = (int)v40;
          }
          else
          {
            v38 = v40;
          }
        }
        while ( *v38 );
        if ( v37 == 1 )
        {
          v42 = v70 + 3;
          v37 = 0;
          RtlInitUnicodeString((unsigned int)v69, L"DS");
          v43 = RtlEqualUnicodeString(v39, (unsigned __int16 *)v69, 1);
          v44 = (unsigned __int16 *)v74;
          v46 = 0;
          if ( v43 )
          {
            if ( *(_WORD *)v74 == 78 )
            {
              v45 = *(_WORD **)(v74 + 4);
              if ( *v45 == 37 && v45[1] == 123 && v45[38] == 125 )
                v46 = 1;
            }
          }
          RtlInitUnicodeString((unsigned int)v69, L"Directory Service Object");
          if ( *v42 )
          {
            v47 = (int)v70;
            do
            {
              if ( v37 )
                break;
              if ( v46
                && (v48 = (_DWORD *)*v42,
                    RtlEqualUnicodeString((unsigned __int16 *)(*v42 + 4), (unsigned __int16 *)v69, 1))
                || (v48 = (_DWORD *)*v42, RtlEqualUnicodeString((unsigned __int16 *)(*v42 + 4), v44, 1)) )
              {
                v49 = *v48;
                v37 = 1;
                v72 = v48;
                *v42 = v49;
                *v48 = *(_DWORD *)(v47 + 12);
                *(_DWORD *)(v47 + 12) = v48;
              }
              else
              {
                v42 = v48;
              }
            }
            while ( *v42 );
          }
        }
      }
      v50 = ExReleaseResourceLite((int)&AdtpSourceModuleLock);
      v51 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v52 = *(_WORD *)(v51 + 0x134) + 1;
      *(_WORD *)(v51 + 308) = v52;
      if ( !v52 && *(_DWORD *)(v51 + 100) != v51 + 100 && !*(_WORD *)(v51 + 310) )
        KiCheckForKernelApcDelivery(v50);
      if ( v37 )
        v53 = v72[3];
      else
        v53 = 1552;
      v69[1] = (int)&v76;
      v54 = (int)v67;
      v55 = v68;
      v56 = 1;
      v69[0] = 1310720;
      for ( i = 0; i < 0x10; ++i )
      {
        if ( (v56 & v55) != 0 )
        {
          v11 = RtlIntegerToUnicodeString(v53 + i, 10, (unsigned __int16 *)v69);
          if ( v11 >= 0 )
          {
            RtlAppendUnicodeToString((unsigned __int16 *)&v65, (int)L"%%", v58, v59);
            RtlAppendUnicodeStringToString((unsigned __int16 *)&v65, (unsigned __int16 *)v69);
            v11 = RtlAppendUnicodeToString((unsigned __int16 *)&v65, v54, v60, v61);
          }
        }
        v56 *= 2;
      }
      v34 = v71;
    }
    if ( v11 >= 0 )
    {
      if ( v34 )
      {
        *v34 = v73;
        v34[1] = 0;
        v62 = (unsigned __int16)v65;
        v34[3] = 0;
        v34[2] = v62 + 2;
      }
      else
      {
        v63 = v75;
        *v75 = v65;
        v63[1] = v66;
      }
    }
  }
  else
  {
    if ( a6 )
    {
      *a6 = dword_406F40;
      a6[1] = 0;
      a6[2] = 4;
      a6[3] = 0;
    }
    else if ( a5 )
    {
      RtlInitUnicodeString(a5, L"-");
    }
    v11 = 0;
  }
  return v11;
}
