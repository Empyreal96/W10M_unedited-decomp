// sub_812330 
 
void __fastcall sub_812330(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, unsigned int a20, int a21, int a22, unsigned __int16 a23)
{
  int v23; // r9
  int *v24; // r10
  unsigned int v25; // r4
  int *v26; // r6
  int *v27; // r0
  unsigned int v28; // r5
  _DWORD *v29; // r7
  int v30; // r0
  unsigned int v31; // r7
  _DWORD *v32; // r8
  int v33; // r3
  _WORD *v34; // r3
  unsigned int v35; // r4
  _DWORD *v36; // r5
  int v37; // r4
  __int16 v38; // r5
  int **v39; // r1
  _WORD *v40; // [sp+0h] [bp+0h]
  int v41; // [sp+4h] [bp+4h]
  unsigned int v42; // [sp+8h] [bp+8h]

  v25 = a20;
  if ( !a20 )
    PopFxBugCheck(1798, 36, 1396928373, 0);
  if ( a20 > 0x3E8 )
    PopFxBugCheck(1798, 36, 1396928373, a20);
  v26 = (int *)PopFxLookupSocSubsystemsByPlatformIdleState();
  if ( v26 )
    goto LABEL_6;
  v27 = (int *)ExAllocatePoolWithTag(1, 320 * v25 + 16, 1297630800);
  v26 = v27;
  if ( !v27 )
LABEL_37:
    JUMPOUT(0x7A2E7C);
  memset(v27, 0, 320 * v25 + 16);
  v28 = 0;
  v26[2] = v23;
  v26[3] = v25;
  if ( v25 )
  {
    v29 = v26 + 4;
    do
    {
      v29[3] = v29 + 48;
      v29[4] = v28;
      v29[1] = v29 + 16;
      *(_WORD *)v29 = 0;
      *((_WORD *)v29 + 1) = 128;
      *((_WORD *)v29 + 4) = 0;
      *((_WORD *)v29 + 5) = 128;
      a11 = 0;
      a9 = v23;
      v30 = *v24;
      a10 = v29[4];
      a12 = *v29;
      a13 = v29[1];
      a14 = v29[2];
      a15 = v29[3];
      a16 = 0;
      a17 = 0;
      PopPluginInitializeSocSubsystemStaticInfo(v30, &a9);
      *((_WORD *)v29 + 4) = a14;
      *(_WORD *)v29 = a12;
      v29[6] = a11;
      v29[15] = a16;
      if ( RtlHashUnicodeString((unsigned __int16 *)v29 + 4, 0, 0, v29 + 5) < 0 )
        goto LABEL_6;
      ++v28;
      v29 += 80;
    }
    while ( v28 < v26[3] );
  }
  v41 = 0;
  v31 = 0;
  if ( v26[3] )
  {
    v32 = v26 + 4;
    do
    {
      v33 = v32[4];
      v32[7] = -1430541637;
      v32[8] = 0;
      v32[9] = 0;
      v32[10] = 0;
      *((_WORD *)v32 + 16) = v23;
      *((_WORD *)v32 + 17) = v33 + 1;
      v34 = (_WORD *)v32[1];
      v35 = 0;
      v40 = v34;
      v42 = v26[3];
      if ( v42 )
      {
        v36 = v26 + 4;
        while ( 1 )
        {
          if ( v35 != v31 )
          {
            if ( !wcsncmp((_WORD *)v32[3], (unsigned __int16 *)v36[3], 64) )
              PopFxBugCheck(1798, 37, 1315007845, v35);
            v34 = v40;
          }
          if ( !wcsncmp(v34, (unsigned __int16 *)v36[3], 64) )
            break;
          ++v35;
          v36 += 80;
          v34 = v40;
          if ( v35 >= v42 )
            goto LABEL_21;
        }
        v38 = v36[4] + 1;
        v32[11] = -1430541637;
        v32[12] = 0;
        v32[13] = 0;
        v32[14] = 0;
        *((_WORD *)v32 + 25) = v38;
        *((_WORD *)v32 + 24) = v23;
      }
      else
      {
LABEL_21:
        if ( v41 )
        {
          if ( wcsncmp(v34, &a23, 64) )
            PopFxBugCheck(1798, 37, 1348563557, v31);
        }
        else
        {
          RtlStringCchCopyW(&a23, 0x40u, (int)v34);
          v41 = 1;
        }
        v32[11] = -1430541637;
        v32[12] = 0;
        v32[13] = 0;
        v32[14] = 0;
        *((_WORD *)v32 + 24) = 0;
        *((_WORD *)v32 + 25) = 0;
      }
      ++v31;
      v32 += 80;
    }
    while ( v31 < v26[3] );
  }
  if ( PopDiagSleepStudyHandleRegistered )
  {
    v37 = -1073740008;
  }
  else
  {
    v37 = EtwRegister((int)SLEEPSTUDY_ETW_PROVIDER, 0, 0);
    if ( v37 < 0 )
      goto LABEL_6;
    PopDiagSleepStudyHandleRegistered = 1;
  }
  if ( !v37 )
  {
    v39 = (int **)dword_61F58C;
    *v26 = (int)&SocSubsystemsList;
    v26[1] = (int)v39;
    if ( *v39 != &SocSubsystemsList )
      __fastfail(3u);
    *v39 = v26;
    dword_61F58C = (int)v26;
    goto LABEL_37;
  }
LABEL_6:
  ExFreePoolWithTag((unsigned int)v26);
  goto LABEL_37;
}
